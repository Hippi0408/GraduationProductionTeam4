//＝＝＝＝＝＝＝＝＝＝＝＝＝
//MyImGui.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝
#ifndef _MYIMGUI_H_
#define _MYIMGUI_H_

#include "particle_manager.h"

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

class CParticleManager;

class CMyImgui
{
public:
	CMyImgui();
	~CMyImgui();

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	bool ImGuiText(bool show_demo_window, bool show_another_window);
	void ProcessParticle(CParticleManager::SBundleData& data);
	bool isHover() { return m_isHover; }

	std::vector<CParticleManager::SBundleData> GetParticleData(std::string str);
	std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>> GetData() { return m_pParticle; }
	std::string GetNowTag() { return m_nowTag; }
	int GetIndex() { return m_tagIndex; }
	int GetEmissionInterval() { return m_emissionInterval; }

private:
	enum ETextureMode
	{
		Texture_Main,
		Texture_Mask,
		Texture_Max
	};

	void EditParticle(CParticle::SInfo& data, CParticleEmitter::SEmitterInfo& emitterData);
	void EditMesh(CMeshParticle::SInfo& data, CParticleEmitter::SEmitterInfo& emitterData);
	void EditSound(CParticleEmitter::SEmitterInfo& emitterData);
	void EditPhysics(CParticleEmitter::SEmitterInfo& emitterData);
	void EditPlot(CParticle::SInfo& data, ImVector<ImPlotPoint>& plotPt, int& index);

	void SettingTexture(ETextureMode mode);
	void MenuBar();
	void ParticlePlot(CParticle::SInfo& data, CParticleEmitter::SEmitterInfo& emitterData);

	void RenderComboBox(std::string label, int& index, std::vector<std::string>& list, std::function<void()> func);
	void SwitchButton(std::string label, bool& target);
	void SwitchButton(std::string label, std::string enable, std::string disable, bool& target, int index = 1);
	bool IconButton(std::string icon, const ImVec2& size);
	bool CheckHoverWindow();
	
	// カラーパレット
	bool ColorPalette4(const char* label, float col[4]);
	bool ColorPalette(float color[4], float backup_color[4], ImGuiColorEditFlags flags);

	// 型の変換
	ImVec4 ColorToImVec4(const D3DXCOLOR& color);
	D3DXCOLOR ImVec4ToColor(const ImVec4& vec);

	std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>> m_pParticle;
	std::vector<std::string> m_tagList;
	std::string m_nowTag;
	CParticleManager::SBundleData m_copyData;
	ImVec4 m_markerLineColor;
	int m_cntMath;
	int m_tagIndex;
	int m_particleIndex;
	int m_textureIndex;
	int m_maskTextureIndex;
	int m_modelIndex;
	int m_emissionInterval;
	bool m_isHover;
	bool m_showParticles;
	bool m_showSounds;
	bool show_demo_window = true;
	bool show_another_window = false;
};

#endif