#include "myimgui.h"
#include "application.h"
#include "pointer.h"
#include "particle.h"
#include "utility.h"
#include "particle_manager.h"
#include "model.h"
#include "mouse.h"
#include "physics.h"
#include "sound.h"
#include "file.h"
#include <algorithm>

//imgui
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include "imgui_internal.h"

#ifndef IMPLOT_DISABLE_OBSOLETE_FUNCTIONS
#define IMPLOT_DISABLE_OBSOLETE_FUNCTIONS
#endif
#include "implot.h"
#include "implot_internal.h"

namespace ImPlot
{
	template <typename T>
	inline T RandomRange(T min, T max) 
	{
		T scale = rand() / (T)RAND_MAX;
		return min + scale * (max - min);
	}

	ImVec4 RandomColor() 
	{
		ImVec4 col;
		col.x = RandomRange(0.0f, 1.0f);
		col.y = RandomRange(0.0f, 1.0f);
		col.z = RandomRange(0.0f, 1.0f);
		col.w = 1.0f;
		return col;
	}

	ImPlotPoint FindCentroid(const ImVector<ImPlotPoint>& data, ImPlotRect& bounds, int& cnt) {
		cnt = 0;
		ImPlotPoint avg;
		for (int i = 0; i < data.size(); ++i) {
			if (bounds.Contains(data[i].x, data[i].y)) {
				avg.x += data[i].x;
				avg.y += data[i].y;
				cnt++;
			}
		}
		if (cnt > 0) {
			avg.x = avg.x / cnt;
			avg.y = avg.y / cnt;
		}
		return avg;
	}

	double RandomGauss() 
	{
		static double V1, V2, S;
		static int phase = 0;
		double X;
		if (phase == 0) 
		{
			do {
				double U1 = (double)rand() / RAND_MAX;
				double U2 = (double)rand() / RAND_MAX;
				V1 = 2 * U1 - 1;
				V2 = 2 * U2 - 1;
				S = V1 * V1 + V2 * V2;
			} while (S >= 1 || S == 0);

			X = V1 * sqrt(-2 * log(S) / S);
		}
		else
			X = V2 * sqrt(-2 * log(S) / S);
		phase = 1 - phase;
		return X;
	}

	// utility structure for realtime plot
	struct ScrollingBuffer
	{
		int MaxSize;
		int Offset;
		ImVector<ImVec2> Data;

		ScrollingBuffer(int max_size = 2000) 
		{
			MaxSize = max_size;
			Offset = 0;
			Data.reserve(MaxSize);
		}

		void AddPoint(float x, float y)
		{
			if (Data.size() < MaxSize)
				Data.push_back(ImVec2(x, y));
			else 
			{
				Data[Offset] = ImVec2(x, y);
				Offset = (Offset + 1) % MaxSize;
			}
		}

		void Erase() 
		{
			if (Data.size() > 0) 
			{
				Data.shrink(0);
				Offset = 0;
			}
		}
	};

	// utility structure for realtime plot
	struct RollingBuffer
	{
		float Span;
		ImVector<ImVec2> Data;
		RollingBuffer() 
		{
			Span = 10.0f;
			Data.reserve(2000);
		}

		void AddPoint(float x, float y) 
		{
			float xmod = fmodf(x, Span);
			if (!Data.empty() && xmod < Data.back().x)
				Data.shrink(0);
			Data.push_back(ImVec2(xmod, y));
		}
	};
}

namespace PointPlot
{
	enum EElement
	{
		Element_Vector2,
		Element_Vector3,
		Element_Color,
		Element_Max
	};

	void PlotMarkerColor(ImPlotCol colFlags, std::string markerLabel, ImVec4 col, ImPlotPoint& ptData, size_t size, int index)
	{
		ImPlot::PushStyleColor(colFlags, col);
		ImPlot::PlotScatter(markerLabel.c_str(), &ptData.x, &ptData.y, size, index, 2 * sizeof(double));
		ImPlot::PopStyleColor();
	}

	void PlotLineColor(ImPlotCol colFlags, std::string lineLabel, ImVec4 col, ImPlotPoint& ptData, size_t size, int index)
	{
		ImPlot::PushStyleColor(colFlags, col);
		ImPlot::PlotLine(lineLabel.c_str(), &ptData.x, &ptData.y, size, index + 1, 2 * sizeof(double));
		ImPlot::PopStyleColor();
	}

	void DragPoints(ImVector<ImPlotPoint>& ptData, int index, ImPlotDragToolFlags flags)
	{
		for (int i = 0; i < ptData.size(); i++)
		{
			ImVec4 color(1, 1, 1, 1);
			float pointSize = 8.0f;
			ImPlot::DragPoint(index + i, &ptData[i].x, &ptData[i].y, color, pointSize, flags);
		}
	}

	void RemovePoints(ImVector<ImPlotPoint>& ptData, CParticle::SInfo& data, ImPlotRect select, int& index)
	{
		//点の番号を取る
		for (int i = 0; i < ptData.size(); i++)
		{
			if (select.Contains(ptData[i].x, ptData[i].y))
			{
				//点を削除
				if (ImGui::IsMouseClicked(0) && ImGui::GetIO().KeysDown[ImGuiKey_Delete])
				{//Deleteを押下したまま、クリックした場合
					if (index <= 0)
					{
						continue;
					}

					//選択した１点のみを削除
					for (int j = i; j < index; j++)
					{
						ptData[j] = ptData[j + 1];
						data.colorProp[j] = data.colorProp[j + 1];
					}

					ptData.pop_back();
					data.colorProp.pop_back();
					index--;
				}
			}
		}
	}

	// 点の数、現在時間、合計時間に応じて数値を変化させる処理
	inline float CalcPoint(std::vector<float>& pt, int time, int total)
	{
		float interval = total / (float)(pt.size() - 1);
		int currentIndex = static_cast<int>(time / interval);
		float t = (time - currentIndex * interval) / interval;

		return utility::Lerp(pt[currentIndex], pt[currentIndex + 1], t);
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// MyImguiのコンストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CMyImgui::CMyImgui() :
	show_demo_window(true),
	show_another_window(false),
	m_showParticles(false)
{
	m_particleIndex = 0;
	m_textureIndex = 0;
	m_tagIndex = 0;
	m_emissionInterval = 150;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// MyImguiのデストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CMyImgui::~CMyImgui()
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// MyImguiの初期化
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
HRESULT CMyImgui::Init()
{
	std::vector<CParticleManager::SBundleData> data(1);

	data[0].info.pos = D3DXVECTOR3(0.0f, 10.0f, 0.0f);
	data[0].info.posOffset = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	data[0].info.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	data[0].info.scale = D3DXVECTOR3(10.0f, 10.0f, 0.0f);
	data[0].info.scalingValue = D3DXVECTOR3(0.0f,0.0f,0.0f);
	data[0].info.col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	data[0].info.destCol = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	data[0].info.trailInfo.beginCol = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	data[0].info.trailInfo.endCol = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	data[0].emitterData.popParticleNum = 5;
	data[0].info.popTime = 50;
	data[0].info.moveAttenuation = 0.005f;
	data[0].info.colAttenuation = 0.5f;
	data[0].info.rotate.angle = 0.0f;
	data[0].info.random.distortion = D3DXVECTOR2(1.0f, 1.0f);
	data[0].emitterData.radius = 360.0f;
	data[0].info.useRandom = false;
	data[0].meshInfo.scale = D3DXVECTOR3(1.0f,1.0f,1.0f);
	data[0].meshInfo.color.col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
	data[0].meshInfo.color.destCol = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	data[0].meshInfo.color.colAttenuation = 0.5f;
	data[0].meshInfo.popTime = 100;
	data[0].emitterData.objType = CParticleEmitter::OBJECT_BILLBOARD;
	data[0].emitterData.particleTag = "Begin";
	data[0].emitterData.modelTag = "CUBE";
	data[0].emitterData.texTag = "FLARE";

	//CApplication::GetInstance()->GetParticleManager()->LoadInitializeData(data[0]);

	CApplication::GetInstance()->GetParticleManager()->SetParticleData(data[0].emitterData.particleTag, data);
	m_pParticle[data[0].emitterData.particleTag].push_back(data[0]);
	m_nowTag = data[0].emitterData.particleTag;
	m_tagList.push_back(data[0].emitterData.particleTag);

	return S_OK;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// MyImguiの終了処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::Uninit()
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImPlot::DestroyContext();
	ImGui::DestroyContext();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// MyImguiの更新
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::Update()
{
	show_another_window = ImGuiText(show_demo_window, show_another_window);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// MyImguiの描画
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::Draw()
{
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// Imguiのウィンドウ処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CMyImgui::ImGuiText(bool show_demo_window, bool show_another_window)
{
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// ウインドウの起動時の場所
	ImGui::SetNextWindowPos(ImVec2(0, 20), ImGuiCond_Once);
	ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Once);

	static float math[2];
	static bool visible = CApplication::GetInstance()->GetPointer()->GetVisible();

	CApplication::GetInstance()->GetParticleManager()->SetParticleData(m_tagList[m_tagIndex], m_pParticle[m_tagList[m_tagIndex]]);

	ImGuiIO& io = ImGui::GetIO();
	//io.MouseDrawCursor = true;

	// ウィンドウを作成
	if (!show_demo_window)
	{
		return false;
	}

	ImGui::Begin("Hello, world!", nullptr, ImGuiWindowFlags_MenuBar);                          // Create a window called "Hello, world!" and append into it.
	MenuBar();
	m_isHover = CheckHoverWindow();

	//FPS表示
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

	// ポインターの表示の切り替え
	CMyImgui::SwitchButton("Pointer", "Hide ", "Show ", visible);
	if (visible)
		CApplication::GetInstance()->GetPointer()->Invisible();
	else if (!visible)
		CApplication::GetInstance()->GetPointer()->Visible();

	ImGui::SetNextWindowSize(ImVec2(500, 600), ImGuiCond_Once);

	// タグの変更
	static int copyIndex = 0;
	static char changeTag[256] = {};
	static char buf[256] = {};
	static bool isTagMenuOpen = false;
	static bool isCopyMenuOpen = false;
	static bool isEditTag = false;
	static bool isCopy = false;

	ImGui::InputText("##ParticleTag", buf, IM_ARRAYSIZE(buf));
	ImGui::SameLine();
	if (ImGui::Button("SetTag"))
	{
		m_tagList.push_back(buf);
		m_pParticle[m_tagList[m_tagList.size() - 1]].push_back(m_pParticle[m_tagList[0]][0]);
		CApplication::GetInstance()->GetParticleManager()->SetParticleData(m_tagList[m_tagList.size() - 1], m_pParticle[m_tagList[0]]);
	}

	if (!m_tagList.empty())
	{
		RenderComboBox("EmitterTagList", m_tagIndex, m_tagList, [&]() {m_nowTag = m_tagList[m_tagIndex], m_particleIndex = 0; });
	}

	// 右クリックでホバーメニューを表示
	std::vector<std::string> clickedList = { "Change", "Copy" };
	if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Right))
	{
		isTagMenuOpen = true;
	}
	if (isTagMenuOpen && ImGui::BeginPopupContextItem())
	{
		for (size_t i = 0; i < clickedList.size(); i++)
		{
			if (ImGui::Selectable(clickedList[i].c_str()))
			{
				if (clickedList[i] == "Change")
				{
					isEditTag = true;
					break;
				}
				if (clickedList[i] == "Copy")
				{
					isCopyMenuOpen = true;
					break;
				}
			}
		}
		ImGui::EndPopup();
	}

	// Enterを押すと元のタグを変更
	if (isEditTag)
	{
		ImGui::InputText("ChangeTag", changeTag, IM_ARRAYSIZE(changeTag));
		if (ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeyPadEnter))
		{
			if (strlen(changeTag) != 0)
			{	// 変更先の文字列が空ではない場合
				if (m_pParticle.count(m_tagList[m_tagIndex]) > 0)
				{
					m_pParticle[changeTag] = m_pParticle[m_tagList[m_tagIndex]];
					m_pParticle.erase(m_tagList[m_tagIndex]);
				}
				m_tagList[m_tagIndex] = changeTag;
				isEditTag = false;
			}
		}
	}

	// 現在のパーティクルのタグのデータを別のタグのデータにコピーする
	ImGui::Separator();
	if (isCopyMenuOpen)
	{
		// コピー元
		RenderComboBox("CopySource", m_tagIndex, m_tagList, [&]() {m_nowTag = m_tagList[m_tagIndex], m_particleIndex = 0; });

		// コピー先
		RenderComboBox("CopyTarget", copyIndex, m_tagList, [&]() {; });

		if (ImGui::Button("OK"))
		{
			if (m_pParticle.count(m_tagList[m_tagIndex]) > 0)
			{
				m_pParticle[m_tagList[copyIndex]] = m_pParticle[m_tagList[m_tagIndex]];
			}
			copyIndex = 0;
			isCopyMenuOpen = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("NO"))
		{
			copyIndex = 0;
			isCopyMenuOpen = false;
		}
	}

	ImGui::Separator();

	// リストボックス
	std::vector<std::string> itemLabels;
	for (size_t i = 0; i < m_pParticle[m_tagList[m_tagIndex]].size(); i++)
	{
		std::string str = "Item : " + std::to_string(i);
		itemLabels.push_back(str.c_str());
	}

	// アイテムラベルの要素をstringからconst charに変換し、データを保持
	std::vector<const char*> itemLabelsPtr;
	itemLabelsPtr.reserve(itemLabels.size());
	for (const auto &p : itemLabels)
	{
		itemLabelsPtr.push_back(p.c_str());
	}

	ImGui::ListBox("Index", &m_particleIndex, itemLabelsPtr.data(), static_cast<int>(itemLabels.size()));
	ImGui::SameLine();
	if (ImGui::Button("+"))
	{
		m_pParticle[m_tagList[m_tagIndex]].push_back(m_pParticle[m_tagList[0]][0]);
	}
	ImGui::SameLine();
	if (ImGui::Button("-"))
	{
		if (itemLabels.size() > 1)
		{
			m_pParticle[m_tagList[m_tagIndex]].pop_back();
			m_particleIndex--;
		}
	}

	// 現在選択しているデータをDELキーで削除
	if (m_pParticle[m_tagList[m_tagIndex]].size() - 1 > 0 && ImGui::IsKeyPressed(ImGuiKey_Delete))
	{
		m_pParticle[m_tagList[m_tagIndex]].erase(m_pParticle[m_tagList[m_tagIndex]].begin() + m_particleIndex);
		if (m_particleIndex >= m_pParticle[m_tagList[m_tagIndex]].size() - 1)
		{
			m_particleIndex = m_pParticle[m_tagList[m_tagIndex]].size() - 1;
		}
	}

	if (ImGui::IsKeyPressed(ImGuiKey_LeftCtrl) || ImGui::IsKeyPressed(ImGuiKey_RightCtrl))
	{
		if (ImGui::IsKeyDown(ImGuiKey_C))
		{	// コピー
			m_copyData = m_pParticle[m_tagList[m_tagIndex]][m_particleIndex];
		}
		if (ImGui::IsKeyDown(ImGuiKey_V))
		{	// ペースト
			m_pParticle[m_tagList[m_tagIndex]].push_back(m_copyData);
		}
		if (m_pParticle[m_tagList[m_tagIndex]].size() - 1 > 0 && ImGui::IsKeyDown(ImGuiKey_X))
		{	// カット
			m_copyData = m_pParticle[m_tagList[m_tagIndex]][m_particleIndex];
			m_pParticle[m_tagList[m_tagIndex]].erase(m_pParticle[m_tagList[m_tagIndex]].begin() + m_particleIndex);
			if (m_particleIndex >= m_pParticle[m_tagList[m_tagIndex]].size() - 1)
			{
				m_particleIndex = m_pParticle[m_tagList[m_tagIndex]].size() - 1;
			}
		}
	}

	ImGui::Separator();

	ImGui::DragInt("Emission Interval", &m_emissionInterval, 1, 15, 1000);			// 全体の生成間隔
	ImGui::Separator();

	if (IconButton("ICON_PARTICLE", ImVec2(100.0f, 100.0f)))
	{
		m_showParticles = !m_showParticles;
	}
	ImGui::SameLine();
	if (IconButton("ICON_SOUND", ImVec2(100.0f, 100.0f)))
	{
		m_showSounds = !m_showSounds;
	}

	if (m_showParticles)
	{
		ImGui::Begin("Particles");
		m_isHover = CheckHoverWindow();

		// パーティクルの情報を操作する処理
		ProcessParticle(m_pParticle[m_tagList[m_tagIndex]][m_particleIndex]);

		ImGui::End();
	}

	if (m_showSounds)
	{
		ImGui::Begin("Sounds");
		m_isHover = CheckHoverWindow();
		EditSound(m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData);

		ImGui::End();
	}

	//別ウィンドウを生成
	ImGui::Checkbox("Another Window", &show_another_window);
	ImGui::End();

	// ウィンドウを作成
	if (show_another_window)
	{
		ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		ImGui::End();
	}

	// 背景描画
	return show_another_window;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの種類選択処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::ProcessParticle(CParticleManager::SBundleData& data)
{
	std::vector<std::string> ObjectList = { "Object_Billboard", "Object_Mesh" };
	std::map<std::string, std::vector<std::string>, std::less<>> ObjectTagList;
	ObjectTagList[m_tagList[m_tagIndex]] = ObjectList;

	int objIndex = utility::EnumToInt(data.emitterData.objType);
	RenderComboBox("ObjectType", objIndex, ObjectTagList[m_tagList[m_tagIndex]], [&]() {data.emitterData.objType = static_cast<CParticleEmitter::EObjectType>(objIndex); });

	switch (data.emitterData.objType)
	{
	case CParticleEmitter::EObjectType::OBJECT_BILLBOARD:
		EditParticle(data.info, data.emitterData);
		break;

	case CParticleEmitter::EObjectType::OBJECT_MESH:
		EditMesh(data.meshInfo, data.emitterData);
		break;

	default:
		break;
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ビルボードパーティクルの編集
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::EditParticle(CParticle::SInfo& data, CParticleEmitter::SEmitterInfo& emitterData)
{
	static int maxQuantity = 400;
	static int maxPopTime = 500;
	static bool usePhysics = false;
	static bool invalidLimit = false;

	// テクスチャの設定
	SettingTexture(Texture_Main);

	std::vector<std::string> blendList = { "Additive", "Subtractive", "None" };
	std::map<std::string, std::vector<std::string>, std::less<>> blendTagList;
	blendTagList[m_tagList[m_tagIndex]] = std::move(blendList);

	int blendIndex = utility::EnumToInt(data.blendState);
	RenderComboBox("BlendType", blendIndex, blendTagList[m_tagList[m_tagIndex]], [&]() { data.blendState = static_cast<CBillboard::EBlend>(blendIndex); });

	// 生成関係
	if (ImGui::CollapsingHeader("Create"))
	{
		ImGui::DragInt("DelayStartTime", &data.beginDelay, 1, 0, 3000);
		ImGui::DragInt("AddSeparateDelay", &emitterData.popDelay, 1, 0, 20);

		float posOffset[3] = { data.posOffset.x, data.posOffset.y, data.posOffset.z };
		ImGui::DragFloat3("PosOffset", posOffset, 0.1f, -500.0f, 500.0f);

		data.posOffset.x = posOffset[0];
		data.posOffset.y = posOffset[1];
		data.posOffset.z = posOffset[2];

		// ランダムな位置の設定
		{
			std::vector<std::string> randomList = { "Default", "Random_Circle" };
			std::map<std::string, std::vector<std::string>, std::less<>> randPosTagList;
			randPosTagList[m_tagList[m_tagIndex]] = std::move(randomList);

			int randomSetIndex = utility::EnumToInt(data.random.randomBehavior);
			RenderComboBox("RandomBehavior", randomSetIndex, randPosTagList[m_tagList[m_tagIndex]], [&]() {data.random.randomBehavior = static_cast<CParticle::ERandomBehavior>(randomSetIndex); });

			if (randomSetIndex == CParticle::ERandomBehavior::RandomBehavior_Circle)
			{
				ImGui::DragFloat("CreateRange", &data.circleDistance, 0.01f, 0.0f, 100.0f);		// 円の範囲

			// 位置設定のロック
				std::vector<std::string> lockList = { "Lock_None", "Lock_X", "Lock_Y", "Lock_Z",
					"Lock_XY", "Lock_XZ", "Lock_YZ" };
				std::map<std::string, std::vector<std::string>, std::less<>> lockTagList;
				lockTagList[m_tagList[m_tagIndex]] = std::move(lockList);

				int lockIndex = utility::EnumToInt(data.random.randomLockVector);
				RenderComboBox("LockPos", lockIndex, lockTagList[m_tagList[m_tagIndex]], [&]() {data.random.randomLockVector = static_cast<CParticle::ELockVector>(lockIndex); });
			}
		}
	}

	// 移動関係
	if (ImGui::CollapsingHeader("Movement"))
	{
		std::vector<std::string> behaviorList = { "Behavior_None", "Behavior_Circle", "Behavior_Sphere", "Behavior_Rotate" };
		std::map<std::string, std::vector<std::string>, std::less<>> behaviorTagList;
		behaviorTagList[m_tagList[m_tagIndex]] = std::move(behaviorList);

		int behaviorIndex = utility::EnumToInt(emitterData.behavior);
		RenderComboBox("ParticleBehavior", behaviorIndex, behaviorTagList[m_tagList[m_tagIndex]], [&]() {emitterData.behavior = static_cast<CParticleEmitter::EBehavior>(behaviorIndex); });

		float move[2] = { data.move.x, data.move.z };
		ImGui::DragFloat2("Velocity", move, 0.001f, -300.0f, 300.0f);
		ImGui::DragFloat("UpVector", &data.move.y, 0.01f, 0.0f, 100.0f);							// 移動量

		data.move.x = move[0];
		data.move.z = move[1];

		data.velocity.x = move[0];
		data.velocity.z = move[1];

		switch (behaviorIndex)
		{
		case CParticleEmitter::Behavior_Rotate:
			ImGui::DragFloat("RotateAngle", &data.rotate.angle, 0.01f, -100.0f, 100.0f);			// 角度
			ImGui::DragFloat("RotateRadius", &data.rotate.radius, 0.001f, -5.0f, 5.0f);				// 半径
			ImGui::DragFloat2("RandomRotate", &(data.rotate.randomMax, data.rotate.randomMin), 0.01f, -100.0f, 100.0f);
			break;
		case CParticleEmitter::Behavior_Sphere:
			ImGui::DragFloat2("Distortion", data.random.distortion, 0.01f, 0.0f, 10.0f);
			break;
		}

		ImGui::DragFloat("MoveAttenuation", &data.moveAttenuation, 0.001f, 0.0f, 10.0f);		// 移動減衰量
		ImGui::DragInt("FallDelay", &data.fallDelayTime, 1, 0, 60);								// 落ちるようになる時間
		ImGui::DragFloat("Weight", &data.weight, 0.001f, -100.0f, 100.0f);						// 重さ
		ImGui::DragFloat("Radius", &emitterData.radius, 0.01f, -360.0f, 360.0f);				// 半径

		// 重さのランダム
		ImGui::Checkbox("Random", &data.useRandom);
		if (data.useRandom)
		{
			ImGui::Text("Min / Max");
			ImGui::DragFloat2("RandomWeight", &(data.random.randomWeight.y, data.random.randomWeight.x), 0.001f, -0.5f, 0.5f);
			ImGui::DragFloat3("RandomVelocityMin", data.random.randomVelocityMin, 0.001f, -10.0f, 10.0f);
			ImGui::DragFloat3("RandomVelocityMax", data.random.randomVelocityMax, 0.001f, -10.0f, 10.0f);
		}	

		ImGui::Checkbox("Use Physics", &emitterData.usePhysics);

		if (emitterData.usePhysics)
		{
			SwitchButton("##Limit", "Invalid Limit", "Valid Limit", invalidLimit);
			EditPhysics(emitterData);
		}

		if (!invalidLimit)
		{
			maxQuantity = 150;
			maxPopTime = 125;
		}
		else
		{
			maxQuantity = 400;
			maxPopTime = 500;
		}
	}

	ImGui::Separator();
	ImGui::DragFloat3("Scale", data.scale, 0.1f, 0.0f, 100.0f);							// 大きさ
	ImGui::DragFloat3("ScalingValue", data.scalingValue, 0.01f, -5.0f, 5.0f);			// 拡縮量
	ImGui::DragFloat("RotateValue", &data.rotateValue, 0.01f, -10.0f, 10.0f);			// 回転量
	
	ImGui::DragFloat2("RandomRotateValue", data.random.randomRotate, 0.01f, -10.0f, 10.0f);			// 回転量

	// 色関係
	ColorPalette4("Color", data.col);													// 色
	ColorPalette4("DestColor", data.destCol);											// 目的の色
	ImGui::DragFloat("ColorAttenuation", &data.colAttenuation, 0.01f, 0.0f, 10.0f);		// 目的の色への減衰量

	if (ImGui::CollapsingHeader("Plot"))
	{
		ParticlePlot(data, emitterData);
	}

	ImGui::InputInt("Quantity", &emitterData.popParticleNum);							// 量
	if (emitterData.popParticleNum <= 0)
	{
		emitterData.popParticleNum = 1;
	}
	if (emitterData.popParticleNum >= maxQuantity)
	{
		emitterData.popParticleNum = maxQuantity;
	}

	ImGui::DragInt("PopTime", &data.popTime, 1, 1, maxPopTime);							// 生成間隔
	if (data.popTime >= maxPopTime)
	{
		data.popTime = maxPopTime;
	}

	ImGui::Separator();
	ImGui::Checkbox("Use Trail", &data.useTrail);

	if (data.useTrail)
	{
		ImGui::DragFloat("TrailWidth", &data.trailInfo.trailWidth, 0.01f);

		ImGui::Checkbox("UseTrailTexture", &data.trailInfo.useTexture);
		if (data.trailInfo.useTexture)
		{
			// テクスチャのポインタ
			CTexture *pTexture = CApplication::GetInstance()->GetTexture();

			static int trailTextureIndex = 0;
			std::vector<std::string> texPath;
			for (auto &p : pTexture->GetTexturePath())
			{
				if (p.first.find("ICON") != std::string::npos)
				{
					continue;
				}
				texPath.push_back(p.first);
			}

			// コンボボックスの表示名を現在使用しているテクスチャに変更
			for (size_t i = 0; i < texPath.size(); i++)
			{
				if (data.trailInfo.texPath == texPath[i])
				{
					trailTextureIndex = i;
				}
			}
			RenderComboBox("TrailTexture", trailTextureIndex, texPath, [&]() {data.trailInfo.texPath = texPath[trailTextureIndex]; });
		}

		ImGui::Checkbox("SeparateTrailColors", &data.separateTrail);
	}
	if (data.separateTrail)
	{
		ColorPalette4("BeginTrailColor", data.trailInfo.beginCol);		// 色
		ColorPalette4("EndTrailColor", data.trailInfo.endCol);			// 目的の色
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// メッシュの編集処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::EditMesh(CMeshParticle::SInfo& data, CParticleEmitter::SEmitterInfo& emitterData)
{
	// モデルのポインタ
	CModel *pModel = CApplication::GetInstance()->GetModel();

	CMyImgui::SwitchButton("Shader", emitterData.enableShader);

	std::vector<std::string> modelPath;
	for (auto &p : pModel->GetModelData())
	{
		modelPath.push_back(p.first);
	}

	// コンボボックスの表示名を現在使用しているテクスチャに変更
	for (size_t i = 0; i < modelPath.size(); i++)
	{
		if (m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.texTag == modelPath[i])
		{
			m_modelIndex = i;
		}
	}

	RenderComboBox("Model", m_modelIndex, modelPath, [&]() {m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.modelTag = modelPath[m_modelIndex]; });
	
	if (m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.modelTag.empty())
	{	// モデルタグが""だった場合パス0番目
		m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.modelTag = modelPath[0];
	}

	// テクスチャの設定
	ImGui::Checkbox("Use Texture", &data.useTexture);
	if (data.useTexture)
	{
		SettingTexture(Texture_Main);
		ImGui::DragFloat2("UVMovement", data.moveUV, 0.001f, -2.0f, 2.0f);

		ImGui::Checkbox("Use MaskTexture", &data.useMaskTexture);
		if (data.useMaskTexture)
		{
			SettingTexture(Texture_Mask);
		}
		else
		{
			emitterData.maskTexTag = "";
		}
	}
	else
	{
		emitterData.texTag = "";
	}

	// 生成関係
	if (ImGui::CollapsingHeader("Create"))
	{
		ImGui::DragInt("DelayStartTime", &data.beginDelay, 1, 0, 3000);

		float posOffset[3] = { data.posOffset.x, data.posOffset.y, data.posOffset.z };
		ImGui::DragFloat3("PosOffset", posOffset, 0.1f, -500.0f, 500.0f);

		data.posOffset.x = posOffset[0];
		data.posOffset.y = posOffset[1];
		data.posOffset.z = posOffset[2];

		ImGui::Checkbox("RandomPos", &data.randomPos);
		if (data.randomPos)
		{
			ImGui::DragFloat("CreateRange", &data.circleDistance, 0.01f, 0.0f, 100.0f);		// 円の範囲
		}
	}

	// 移動関係
	if (ImGui::CollapsingHeader("Movement"))
	{
		std::vector<std::string> behaviorList = { "Behavior_None", "Behavior_Circle", "Behavior_Sphere", "Behavior_Rotate" };
		std::map<std::string, std::vector<std::string>, std::less<>> behaviorTagList;
		behaviorTagList[m_tagList[m_tagIndex]] = std::move(behaviorList);

		int behaviorIndex = utility::EnumToInt(emitterData.behavior);
		RenderComboBox("ParticleBehavior", behaviorIndex, behaviorTagList[m_tagList[m_tagIndex]], [&]() {emitterData.behavior = static_cast<CParticleEmitter::EBehavior>(behaviorIndex); });

		float move[2] = { data.move.x, data.move.z };
		ImGui::DragFloat2("Velocity", move, 0.001f, -300.0f, 300.0f);
		ImGui::DragFloat("UpVector", &data.move.y, 0.01f, 0.0f, 100.0f);							// 移動量

		data.move.x = move[0];
		data.move.z = move[1];

		if (behaviorIndex != CParticleEmitter::Behavior_Rotate)
		{
			ImGui::DragFloat("MoveAttenuation", &data.moveAttenuation, 0.001f, 0.0f, 10.0f);		// 移動減衰量
			ImGui::DragInt("FallDelay", &data.fallDelayTime, 1, 0, 60);								// 落ちるようになる時間
			ImGui::DragFloat("Weight", &data.weight, 0.001f, -100.0f, 100.0f);						// 重さ
			ImGui::DragFloat("Radius", &emitterData.radius, 0.01f, -360.0f, 360.0f);				// 半径
		}
		if (behaviorIndex == CParticleEmitter::Behavior_Rotate)
		{
			ImGui::DragFloat("RotateAngle", &data.rotate.angle, 0.01f, -100.0f, 100.0f);			// 角度
			ImGui::DragFloat("RotateRadius", &data.rotate.radius, 0.001f, -5.0f, 5.0f);				// 半径
			ImGui::DragFloat2("RandomRotate", &(data.rotate.randomMax, data.rotate.randomMin), 0.01f, -100.0f, 100.0f);
		}

		// 重さのランダム
		ImGui::Checkbox("Random", &data.randomWeight);
		if (data.randomWeight)
		{
			ImGui::DragFloat2("RandomValue", &(data.randomWeightMax, data.randomWeightMin), 0.001f, -0.5f, 0.5f);
		}
	}

	ImGui::Separator();
	ImGui::DragFloat3("Scale", data.scale, 0.1f, 0.0f, 100.0f);								// 大きさ
	ImGui::DragFloat3("ScalingValue", data.scalingValue, 0.01f, -5.0f, 5.0f);				// 拡縮量

	ImGui::DragFloat("Rotate", &data.rotationVolume, 0.01f, 0.0f, 10.0f);					// 回転量	

	// 色関係
	ColorPalette4("Color", data.color.col);													// 色
	ColorPalette4("DestColor", data.color.destCol);											// 目的の色
	ImGui::DragFloat("ColorAttenuation", &data.color.colAttenuation, 0.01f, 0.0f, 10.0f);	// 目的の色への減衰量
	ImGui::DragFloat("Emissive", &data.color.emissive, 0.01f, 0.0f, 2.0f);					// 発光度

	ImGui::Checkbox("RandomColor", &data.color.randomColor);								// 色にランダムを適用するかどうか
	if (data.color.randomColor)
	{
		ImGui::DragFloat("RandomColorMin", &data.color.randomMin, 0.01f, 0.0f, 1.0f);
		ImGui::DragFloat("RandomColorMax", &data.color.randomMax, 0.01f, 0.0f, 1.0f);
	}

	ImGui::InputInt("Quantity", &emitterData.popParticleNum);					// 量
	if (emitterData.popParticleNum <= 0)
	{
		emitterData.popParticleNum = 1;
	}

	ImGui::DragInt("PopTime", &data.popTime, 1, 1, 600);						// 生成間隔
	ImGui::Checkbox("Use Trail", &data.useTrail);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// メニューバー
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::MenuBar()
{
	if (!ImGui::BeginMenuBar())
	{	// タスクバー
		return;
	}

	if (ImGui::BeginMenu("File"))
	{
		if (ImGui::MenuItem("SaveText"))
		{
			CApplication::GetInstance()->GetParticleManager()->BackUpFile("particle.txt");
			CApplication::GetInstance()->GetParticleManager()->SaveText(m_pParticle);
		}
		else if (ImGui::MenuItem("LoadText"))
		{
			CParticle::SInfo info = {};

			CApplication::GetInstance()->GetParticleManager()->LoadText("particle.txt", m_pParticle);

			// 既存のタグと一致しなかった場合、追加
			for (auto &p : m_pParticle)
			{
				bool find = false;
				for (const std::string& element : m_tagList)
				{
					if (element == p.first)
					{
						find = true;
						break;
					}
				}

				if (!find)
				{
					m_tagList.push_back(p.first);
				}
			}
			
			m_tagIndex = m_tagList.size() - 1;
			m_nowTag = m_tagList[m_tagIndex];
			m_particleIndex = 0;
		}
		else if (ImGui::MenuItem("SaveJson"))
		{
			CApplication::GetInstance()->GetParticleManager()->SaveJson("particle.json", m_pParticle);
		}
		else if (ImGui::MenuItem("LoadJson"))
		{
			CApplication::GetInstance()->GetParticleManager()->LoadAll();
			m_pParticle = CApplication::GetInstance()->GetParticleManager()->GetData();

			// 既存のタグと一致しなかった場合、追加
			for (auto &p : m_pParticle)
			{
				bool find = false;
				for (const std::string& element : m_tagList)
				{
					if (element == p.first)
					{
						find = true;
						break;
					}
				}

				if (!find)
				{
					m_tagList.push_back(p.first);
				}
			}

			m_tagIndex = m_tagList.size() - 1;
			m_nowTag = m_tagList[m_tagIndex];
			m_particleIndex = 0;
		}
		ImGui::EndMenu();
	}
	ImGui::EndMenuBar();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// サウンドの編集処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::EditSound(CParticleEmitter::SEmitterInfo& emitterData)
{
	// サウンドのポインタ
	CSound *pSound = CApplication::GetInstance()->GetSound();
	static std::map<std::string, std::vector<CSound::STrack>, std::less<>> tracks;
	static std::vector<int> tracksSoundIndex(256);
	static CSound::STrack trackData = {};
	static int soundIndex = 0;
	static int numTracks = 0;

	std::vector<std::string> soundPath;
	for (auto &p : pSound->GetSoundPath())
	{
		soundPath.push_back(p.first);
	}
	RenderComboBox("Sound", soundIndex, soundPath, [&]() { ; });

	int currentTracks = numTracks;
	if (ImGui::InputInt("Tracks", &numTracks))
	{
		if (numTracks < 0)
		{
			numTracks = 0;
		}
		if (numTracks > currentTracks)
		{
			trackData.startTime = 0;
			trackData.soundLabel = soundPath[soundIndex];
			tracks[m_tagList[m_tagIndex]].push_back(trackData);
		}
		if (numTracks < currentTracks && numTracks >= 0)
		{
			tracks[m_tagList[m_tagIndex]].pop_back();
		}
	}

	for (size_t i = 0; i < tracks[m_tagList[m_tagIndex]].size(); i++)
	{
		std::string nodeName = "Track" + std::to_string(i + 1);
		if (ImGui::TreeNode(nodeName.c_str()))
		{
			RenderComboBox("TrackSound", tracksSoundIndex[i], soundPath, [&]() {tracks[m_tagList[m_tagIndex]][i].soundLabel = soundPath[tracksSoundIndex[i]]; });
			ImGui::DragInt("Volume", &tracks[m_tagList[m_tagIndex]][i].volume, 1, 0, 10);
			ImGui::DragInt("Start", &tracks[m_tagList[m_tagIndex]][i].startTime);
			ImGui::TreePop();
		}
	}

	if (ImGui::Button("Play"))
	{
		pSound->Play(soundPath[soundIndex]);
	}
	pSound->loopMp3(soundPath[soundIndex]);

	if (tracks[m_tagList[m_tagIndex]].empty())
	{
		return;
	}

	emitterData.tracks = tracks[m_tagList[m_tagIndex]];
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テクスチャの設定
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::SettingTexture(ETextureMode mode)
{
	// テクスチャのポインタ
	CTexture *pTexture = CApplication::GetInstance()->GetTexture();

	std::vector<std::string> texPath;
	for (auto &p : pTexture->GetTexturePath())
	{
		if (p.first.find("ICON") != std::string::npos)
		{
			continue;
		}
		texPath.push_back(p.first);
	}

	// コンボボックスの表示名を現在使用しているテクスチャに変更
	switch (mode)
	{
	case Texture_Main:
		for (size_t i = 0; i < texPath.size(); i++)
		{
			if (m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.texTag == texPath[i])
			{
				m_textureIndex = i;
			}
		}
		RenderComboBox("Texture", m_textureIndex, texPath, [&]() {m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.texTag = texPath[m_textureIndex]; });
		break;

	case Texture_Mask:
		for (size_t i = 0; i < texPath.size(); i++)
		{
			if (m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.maskTexTag == texPath[i])
			{
				m_maskTextureIndex = i;
			}
		}
		RenderComboBox("MaskTexture", m_maskTextureIndex, texPath, [&]() {m_pParticle[m_tagList[m_tagIndex]][m_particleIndex].emitterData.maskTexTag = texPath[m_maskTextureIndex]; });
		break;
	}
	
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 物理の編集処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::EditPhysics(CParticleEmitter::SEmitterInfo& emitterData)
{
	std::vector<std::string> physicsList = { "PHYSICS_NONE", "PHYSICS_BOUNCE", "PHYSICS_AIR" };
	std::map<std::string, std::vector<std::string>, std::less<>> physicsTagList;
	physicsTagList[m_tagList[m_tagIndex]] = std::move(physicsList);

	int physicIndex = utility::EnumToInt(emitterData.physicsType);
	RenderComboBox("PhysicsType", physicIndex, physicsTagList[m_tagList[m_tagIndex]], [&]() {emitterData.physicsType = static_cast<CPhysics::EPhysicsType>(physicIndex); });

	switch (emitterData.physicsType)
	{
	case CPhysics::EPhysicsType::PHYSICS_BOUNCE:
		ImGui::DragFloat("BounceFactor", &emitterData.physics.bounce.bounceFactor, 0.01f, 0.0f, 1.0f);
		ImGui::DragFloat("ElasticityCoefficient", &emitterData.physics.bounce.elasticityCoefficient, 0.01f, 0.0f, 2.0f);
		break;

	case CPhysics::EPhysicsType::PHYSICS_AIR:
		ImGui::DragFloat("VectorFactor", &emitterData.physics.air.vecFactor, 0.01f, 0.0f, 10.0f);
		ImGui::DragFloat("DragCoefficient", &emitterData.physics.air.dragCoefficient, 0.01f, 0.0f, 2.0f);
		break;

	default:
		break;
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの数値変更用プロット
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::ParticlePlot(CParticle::SInfo& data, CParticleEmitter::SEmitterInfo& emitterData)
{
	static std::vector<ImVector<ImPlotPoint>> ptData(4);
	static std::vector<int> index(4);
	static int plotListIndex = 0;
	static int plotElementIndex = 0;
	static bool init = true;

	if (init)
	{
		init = false;
	}

	for (size_t i = 0; i < ptData.size(); i++)
	{
		if (!ptData[i].empty())
		{
			continue;
		}

		if (data.colorProp.empty())
		{
			data.colorProp.resize(2);
			data.colorProp[0].colorPtTime = 0;
			data.colorProp[1].colorPtTime = 1;
		}

		for (size_t j = 0; j < data.colorProp.size(); j++)
		{
			double time = data.colorProp[j].colorPtTime;
			double r = static_cast<double>(data.colorProp[j].color.r);
			double g = static_cast<double>(data.colorProp[j].color.g);
			double b = static_cast<double>(data.colorProp[j].color.b);
			double a = static_cast<double>(data.colorProp[j].color.a);

			for (size_t k = 0; k < 4; k++)
			{
				ptData[k].push_back(ImPlotPoint(time, k == 0 ? r : k == 1 ? g : k == 2 ? b : a));
				index[k] = j;
			}
		}
	}

	std::vector<std::string> elementList = { "Vector2", "Vector3", "Color" };
	std::map<std::string, std::vector<std::string>, std::less<>> elementTagList;
	elementTagList[m_tagList[m_tagIndex]] = std::move(elementList);
	RenderComboBox("ElementType", plotElementIndex, elementTagList[m_tagList[m_tagIndex]], [&]() {; });

	std::vector<std::string> plotList;
	switch (plotElementIndex)
	{
	case PointPlot::EElement::Element_Vector2:
		plotList = { "x", "y" };
		break;

	case PointPlot::EElement::Element_Vector3:
		plotList = {"x", "y", "z"};
		break;

	case PointPlot::EElement::Element_Color:
		plotList = { "r", "g", "b", "a" };
		break;
	}

	std::map<std::string, std::vector<std::string>, std::less<>> plotTagList;
	plotTagList[m_tagList[m_tagIndex]] = std::move(plotList);
	RenderComboBox("PlotType", plotListIndex, plotTagList[m_tagList[m_tagIndex]], [&]() { ; });

	switch (plotListIndex)
	{
	case 0:
		m_markerLineColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
		break;

	case 1:
		m_markerLineColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
		break;

	case 2:
		m_markerLineColor = ImVec4(0.0f, 0.0f, 1.0f, 1.0f);
		break;

	case 3:
		m_markerLineColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		break;
	}

	// プロットの開始
	if (ImPlot::BeginPlot("PlotData"))
	{
		EditPlot(data, ptData[plotListIndex], index[plotListIndex]);
		ImPlot::EndPlot();
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// プロットのメイン処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::EditPlot(CParticle::SInfo& data, ImVector<ImPlotPoint>& plotPt, int& index)
{
	static ImVector<ImPlotRect> rects;
	static ImPlotRect limits, select;
	static ImPlotDragToolFlags flags = ImPlotDragToolFlags_None | ImPlotAxisFlags_LockMin;
	ImPlotPoint pt;

	ImPlot::SetupAxes(0, 0, flags, flags);
	ImPlot::SetupAxesLimits(0, data.popTime, 0, 1, ImPlotCond_Always);

	// ポイントの設置
	if (ImPlot::IsPlotHovered() && ImGui::IsMouseClicked(0) && ImGui::GetIO().KeyCtrl)
	{
		pt = ImPlot::GetPlotMousePos();
		plotPt.push_back(pt);
		index++;
	}

	for (int i = 0; i < plotPt.size(); i++)
	{
		plotPt[i].x = roundf((float)plotPt[i].x);
	}

	// 点の位置のソート
	std::sort(plotPt.begin(), plotPt.end(), [](const ImPlotPoint& ptA, const ImPlotPoint& ptB) { return ptA.x < ptB.x; });

	for (int i = 0; i < plotPt.size(); i++)
	{
		if (plotPt.size() > static_cast<int>(data.colorProp.size()))
		{
			data.colorProp.resize(plotPt.size());
		}

		data.colorProp[i].color.r = static_cast<float>(plotPt[i].y);
		data.colorProp[i].colorPtTime = static_cast<int>(plotPt[i].x);
	}

	// 点動かす用
	PointPlot::DragPoints(plotPt, index, flags);

	// 線
	PointPlot::PlotLineColor(ImPlotCol_Line, "##Line", m_markerLineColor, plotPt[0], plotPt.size(), index);

	// 点
	PointPlot::PlotMarkerColor(ImPlotCol_MarkerFill, "Points", m_markerLineColor, plotPt[0], plotPt.size(), index);

	// 右クリックの範囲選択
	if (ImPlot::IsPlotSelected())
	{
		select = ImPlot::GetPlotSelection();

		int cnt;
		pt = ImPlot::FindCentroid(plotPt, select, cnt);

		// 点の削除処理
		PointPlot::RemovePoints(plotPt, data, select, index);

		// 選択範囲の中の点をとる
		if (cnt > 0)
		{
			ImPlot::SetNextMarkerStyle(ImPlotMarker_Square, 6);
			ImPlot::PlotScatter("Centroid", &pt.x, &pt.y, 1);
		}
	}

	for (int i = 0; i < rects.size(); i++)
	{
		int cnt;
		ImPlotPoint centroid = ImPlot::FindCentroid(plotPt, rects[i], cnt);

		if (cnt > 0)
		{
			ImPlot::SetNextMarkerStyle(ImPlotMarker_Square, 6);
			ImPlot::PlotScatter("Centroid", &centroid.x, &centroid.y, 1);
		}

		ImPlot::DragRect(i, &rects[i].X.Min, &rects[i].Y.Min, &rects[i].X.Max, &rects[i].Y.Max, ImVec4(1, 0, 1, 1));
	}

	limits = ImPlot::GetPlotLimits();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// コンボボックスの描画処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::RenderComboBox(std::string label, int& index, std::vector<std::string>& list, std::function<void()> func)
{
	if (ImGui::BeginCombo(label.c_str(), list[index].c_str(), 0))
	{
		for (size_t i = 0; i < list.size(); i++)
		{
			const bool is_selected = (i == index);
			if (ImGui::Selectable(list[i].c_str(), is_selected))
			{
				index = i;
				func();
			}

			if (is_selected)
			{
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// スイッチボタン
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMyImgui::SwitchButton(std::string label, bool& target)
{
	if (!target)
	{
		label = "Enable " + label;
	}
	else
	{
		label = "Disable " + label;
	}

	if (ImGui::Button(label.c_str()))
	{
		target = !target;
	}
}
void CMyImgui::SwitchButton(std::string label, std::string enable, std::string disable, bool& target, int index)
{
	if (!target)
	{
		switch (index)
		{
		case 0:	// 末尾の位置
			label = label + enable;
			break;

		case 1:	// 開始の位置
			label = enable + label;
			break;

		default:
			break;
		}
	}
	else
	{
		switch (index)
		{
		case 0:	// 末尾の位置
			label = label + disable;
			break;

		case 1:	// 開始の位置
			label = disable + label;
			break;

		default:
			break;
		}
	}

	if (ImGui::Button(label.c_str()))
	{
		target = !target;
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// アイコンボタン
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CMyImgui::IconButton(std::string icon, const ImVec2& size)
{
	LPDIRECT3DTEXTURE9 pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(icon, 1);
	ImGuiIO& io = ImGui::GetIO();
	ImDrawList* drawList = ImGui::GetWindowDrawList();
	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImVec2 rectMin = pos;
	ImVec2 rectMax = ImVec2(pos.x + size.x, pos.y + size.y);

	ImGui::InvisibleButton("##iconButton", ImVec2(size.x, size.y));
	bool hovered = ImGui::IsItemHovered();
	bool clicked = ImGui::IsItemClicked();

	// 背景の描画
	drawList->AddRectFilled(rectMin, rectMax, IM_COL32(0, 0, 0, 0));

	ImTextureID textureID = reinterpret_cast<ImTextureID>(pTexture);

	// アイコン回転用
	const float RotationSpeed = 2.5f;
	const float RotationRange = 20.0f;

	if (hovered)
	{
		static float rotation = 0.0f;
		rotation += RotationSpeed;

		// サインカーブで回転
		float angle = sinf(rotation * D3DX_PI / 180.0f) * RotationRange;

		ImVec2 center = ImVec2(pos.x + size.x * 0.5f, pos.y + size.y * 0.5f);
		ImVec2 vtx[4];
		vtx[0] = ImVec2(pos.x, pos.y);
		vtx[1] = ImVec2(pos.x + size.x, pos.y);
		vtx[2] = ImVec2(pos.x + size.x, pos.y + size.y);
		vtx[3] = ImVec2(pos.x, pos.y + size.y);

		for (int i = 0; i < 4; i++)
		{
			float x = (vtx[i].x - center.x) * cosf(angle * D3DX_PI / 180.0f) - (vtx[i].y - center.y) * sinf(angle * D3DX_PI / 180.0f);
			float y = (vtx[i].x - center.x) * sinf(angle * D3DX_PI / 180.0f) + (vtx[i].y - center.y) * cosf(angle * D3DX_PI / 180.0f);
			vtx[i] = ImVec2(x + center.x, y + center.y);
		}
		drawList->AddImageQuad(textureID, vtx[0], vtx[1], vtx[2], vtx[3]);
	}
	else
	{
		ImVec2 uvMin = ImVec2(0.0f, 0.0f);
		ImVec2 uvMax = ImVec2(1.0f, 1.0f);
		drawList->AddImage(textureID, rectMin, rectMax, uvMin, uvMax);
	}
	return clicked;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// カーソルがウィンドウをホバーしているか判別する処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CMyImgui::CheckHoverWindow()
{
	ImVec2 windowPos = ImGui::GetWindowPos();
	ImVec2 windowSize = ImGui::GetWindowSize();
	return ImGui::IsMouseHoveringRect(windowPos, windowPos + windowSize);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// カラーパレット4
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CMyImgui::ColorPalette4(const char * label, float col[4])
{
	//カラーパレット
	ImGuiColorEditFlags misc_flags = ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions;

	static const char* ids[4] = { "##X", "##Y", "##Z", "##W" };
	static const char* fmt_table_float[4] = { "R:%0.3f", "G:%0.3f", "B:%0.3f", "A:%0.3f" };
	const float square_sz = ImGui::GetFrameHeight();
	const float w_full = ImGui::CalcItemWidth();
	const float w_button = square_sz + ImGui::GetStyle().ItemInnerSpacing.x;
	const float w_inputs = w_full - w_button;
	const float w_item_one = ImMax(1.0f, IM_FLOOR((w_inputs - (ImGui::GetStyle().ItemInnerSpacing.x) * (4 - 1)) / 4.0f));
	const float w_item_last = ImMax(1.0f, IM_FLOOR(w_inputs - (w_item_one + ImGui::GetStyle().ItemInnerSpacing.x) * (4 - 1)));

	bool dragChange = false;
	// ドラッグで色を変更する
	for (int i = 0; i < 4; i++)
	{
		if (i > 0)
		{
			// 横並びにする
			ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
		}

		// ボタンの大きさをウィンドウサイズに合わせる。
		ImGui::SetNextItemWidth((i + 1 < 4) ? w_item_one : w_item_last);

		// データの変更
		dragChange = (ImGui::DragFloat(ids[i], &col[i], 1.0f / 255.0f, 0.0f, 1.0f, fmt_table_float[i]) || dragChange);
	}

	if (dragChange)
	{
		int a = 0;
	}

	ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);

	ImVec4 color_vec = ImVec4(col[0], col[1], col[2], col[3]);
	bool open_popup = ImGui::ColorButton(label, color_vec, misc_flags);
	ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
	open_popup |= ImGui::Button("!");
	ImGui::SameLine();
	ImGui::Text(label);

	static D3DXCOLOR backup_color;

	if (open_popup)
	{
		ImGui::OpenPopup(label);
		backup_color = D3DXCOLOR(col[0], col[1], col[2], col[3]);
	}

	bool plaetteChange = false;
	if (ImGui::BeginPopup(label))
	{
		ImGuiColorEditFlags flags = ImGuiColorEditFlags_AlphaBar;
		flags |= ImGuiColorEditFlags_AlphaPreview;
		flags |= ImGuiColorEditFlags_Float;

		plaetteChange = ColorPalette(col, (float*)&backup_color, flags);
		ImGui::EndPopup();
	}

	return plaetteChange || dragChange;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// カラーパレット
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CMyImgui::ColorPalette(float color[4], float backup_color[4], ImGuiColorEditFlags flags)
{
	float colorOld[4] = { color[0],color[1],color[2],color[3] };

	bool pickerChange = ImGui::ColorPicker4("##picker", color, flags | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
	ImGui::SameLine();

	ImGui::BeginGroup();

	// 現在の色と元の色を表示、元の色がクリックされた場合、現在の色を元の色に戻す
	ImGui::Text("Current");
	ImGui::ColorButton("##current", ImVec4(color[0], color[1], color[2], color[3]), ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreview, ImVec2(60, 40));
	ImGui::Text("Original");
	if (ImGui::ColorButton("##original", ImVec4(backup_color[0], backup_color[1], backup_color[2], backup_color[3]), ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreview, ImVec2(60, 40)))
	{
		color[0] = backup_color[0];
		color[1] = backup_color[1];
		color[2] = backup_color[2];
		color[3] = backup_color[3];
	}

	ImGui::Separator();
	ImGui::Text("Palette");

	static bool saved_palette_init = true;
	static ImVec4 saved_palette[32] = {};
	if (saved_palette_init)
	{
		for (int n = 0; n < IM_ARRAYSIZE(saved_palette); n++)
		{
			ImGui::ColorConvertHSVtoRGB(n / 31.0f, 0.8f, 0.8f,
			saved_palette[n].x, saved_palette[n].y, saved_palette[n].z);
			saved_palette[n].w = 1.0f; // Alpha
		}
		saved_palette_init = false;
	}

	for (int n = 0; n < IM_ARRAYSIZE(saved_palette); n++)
	{
		ImGui::PushID(n);
		if ((n % 8) != 0)
			ImGui::SameLine(0.0f, ImGui::GetStyle().ItemSpacing.y);

		ImGuiColorEditFlags palette_button_flags = ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_NoTooltip;
		if (ImGui::ColorButton("##palette", saved_palette[n], palette_button_flags, ImVec2(20, 20)))
		{
			color[0] = saved_palette[n].x;
			color[1] = saved_palette[n].y;
			color[2] = saved_palette[n].z;
		}

		/* 各パレットに色をドロップ。ColorButton()はドラッグソース
		   ImGuiColorEditFlags_NoDragDropを指定しない限りデフォルトでドラッグソース */
		if (ImGui::BeginDragDropTarget())
		{
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(IMGUI_PAYLOAD_TYPE_COLOR_3F))
			{
				memcpy((float*)&saved_palette[n], payload->Data, sizeof(float) * 3);
			}
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload(IMGUI_PAYLOAD_TYPE_COLOR_4F))
			{
				memcpy((float*)&saved_palette[n], payload->Data, sizeof(float) * 4);
			}
			ImGui::EndDragDropTarget();
		}

		ImGui::PopID();
	}
	ImGui::EndGroup();

	bool red = color[0] != colorOld[0];
	bool grean = color[1] != colorOld[1];
	bool blue = color[2] != colorOld[2];
	bool alpha = color[3] != colorOld[3];
	return pickerChange || red || grean || blue || alpha;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// カラーからベクトルに変換
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
ImVec4 CMyImgui::ColorToImVec4(const D3DXCOLOR & color)
{
	ImVec4 vec;

	vec.x = color.r;
	vec.y = color.g;
	vec.z = color.b;
	vec.w = color.a;

	return vec;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ベクトルからカラーに変換
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
D3DXCOLOR CMyImgui::ImVec4ToColor(const ImVec4 & vec)
{
	D3DXCOLOR color;

	color.r = vec.x;
	color.g = vec.y;
	color.b = vec.z;
	color.a = vec.w;

	return color;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 抽出したデータを返す処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
std::vector<CParticleManager::SBundleData> CMyImgui::GetParticleData(std::string str)
{
	if (m_pParticle.count(str) == 0)
	{	//モデルデータが入ってなかった場合
		assert(false);
	}

	return m_pParticle[str];
}