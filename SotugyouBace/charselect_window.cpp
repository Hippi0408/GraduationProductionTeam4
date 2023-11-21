//=============================================================================
//
// charselect_windpow.cpp (キャラ選択ウィンドウ.cpp)
// Author : Saitou Shian
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "charselect_window.h"
#include "application.h"
#include "renderer.h"
#include "object2D.h"
#include "menu.h"
#include "fade.h"
#include "input.h"
#include "game.h"
#include "title.h"
#include "menu_window.h"
#include "title_menu.h"
#include "chardecision_window.h"
#include "confirmation_window.h"
#include "char_select.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
const float CCharSelect_Window::BLINK_SPEED = 0.02f;	// 選択肢の点滅速度
const float CCharSelect_Window::MINI_ALPHA = 0.5f;	// 選択肢の最低透明値

//=============================================================================
// コンストラクタ
//=============================================================================
CCharSelect_Window::CCharSelect_Window()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CCharSelect_Window::~CCharSelect_Window()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CCharSelect_Window::Init()
{
	//==================================================
	// メンバ変数の初期化
	//==================================================  
	m_nSelectChoice = 0;
	m_SizeX = 0.0f;
	m_SizeY = 0.0f;
	m_bScale = false;
	m_bMaxSize = false;
	m_bUninitFlag = false;
	m_bSpawnWindow = false;
	m_bDecition = false;
	m_bDicisionCreateFlag = false;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CCharSelect_Window::Uninit()
{
	// メンバ変数の破棄
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}

	// キャラ決定ウィンドウの破棄
	if (m_pCharDecision != nullptr)
	{
		m_pCharDecision->Uninit();
		delete m_pCharDecision;
		m_pCharDecision = nullptr;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void CCharSelect_Window::Update()
{
	if (m_bScale == false)
	{// 拡大されていない時 

	 // ウィンドウの拡大処理
		CharSelectMenuScale();
	}
	else 
	{// 拡大した時

	 // ウィンドウの縮小処理
		CharSelectMenuScaleReduce();
	}

	// 選択肢処理
	CharSelectChoice();

	// キャラ決定ウィンドウの更新処理
	if (m_pCharDecision != nullptr)
	{
		m_pCharDecision->Update();
	}

	// キャラごと
	if (m_pCharDecision != nullptr && m_pCharDecision->GetMaxScale() == true)
	{
		std::string SkillName;

		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			std::string Name = "ストライダー";

			if (m_nSelectChoice == 0)
			{
				SkillName = "ラッシュ";
				CharName(Name, SkillName);
			}
			if (m_nSelectChoice == 1)
			{
				SkillName = "マーシャル";
				CharName(Name, SkillName);
			}
			if (m_nSelectChoice == 2)
			{
				SkillName = "イーグルアイ";
				CharName(Name, SkillName);
			}
			if (m_nSelectChoice == 3)
			{
				SkillName = "キャッスル";
				CharName(Name, SkillName);
			}
		}
		else
		{
			std::string Name = "コマンダー";

			if (m_nSelectChoice == 0)
			{
				SkillName = "メカニック";
				CharName(Name, SkillName);
			}
			if (m_nSelectChoice == 1)
			{
				SkillName = "レイダー";
				CharName(Name, SkillName);
			}
			if (m_nSelectChoice == 2)
			{
				SkillName = "アークフィリア";
				CharName(Name, SkillName);
			}
			if (m_nSelectChoice == 3)
			{
				SkillName = "コントロール";
				CharName(Name, SkillName);
			}
		}
	}

	// キャラ決定ウィンドウが閉じた場合 
	if (m_pCharDecision != nullptr && m_pCharDecision->GetSapawnWindow() == true)
	{
		// キャラ決定画面の破棄
		m_pCharDecision->Uninit();
		delete m_pCharDecision;
		m_pCharDecision = nullptr;
	}

	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();
	if (pInput->Trigger(DIK_SPACE))
	{
		CFade::SetFade(CApplication::MODE_CHAR_SELECT, 0.05f);
		/*m_bUninitFlag = true;*/
	}
	/*if (m_pCharDecision != nullptr && m_bUninitFlag == true)
	{
		m_pCharDecision->CharDecisionMenuScaleReduce();
	}*/
}

//=============================================================================
// 拡大処理
//=============================================================================
void CCharSelect_Window::CharSelectMenuScale()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	if (m_pObject2D != nullptr)
	{// nullチェック

	 // サイズの拡大
		m_SizeX += SizeXScaleSpeed;
		m_SizeY += SizeYScaleSpeed;

		if (m_SizeX >= m_MaxSizeX)
		{// Xサイズの最大
			m_SizeX = m_MaxSizeX;
		}
		if (m_SizeY >= m_MaxSizeY)
		{// Yサイズの最大
			m_SizeY = m_MaxSizeY;
		}

		// ウィンドウが最大値まで行ったら
		if (m_SizeX >= m_MaxSizeX && m_SizeY >= m_MaxSizeY && m_bMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_GAME)
			{
				pInput->SetKeyLock(100);
			}

			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
			{
   				if (m_pFont == nullptr)
				{
					m_pFont = CFontString::Create(D3DXVECTOR3(500.0f, 200.0f, 0.0f), { 30.0f, 30.0f }, "ストライカー");
				}

				SetCharSelectChoice(CFontString::Create({ 200.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "ラッシュ"));
				SetCharSelectChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "マーシャル"));
				SetCharSelectChoice(CFontString::Create({ 625.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "イーグルアイ"));
				SetCharSelectChoice(CFontString::Create({ 875.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "キャッスル"));
			}
			else
			{
				if (m_pFont == nullptr)
				{
					m_pFont = CFontString::Create(D3DXVECTOR3(500.0f, 200.0f, 0.0f), { 30.0f, 30.0f }, "コマンダー");
				}

				SetCharSelectChoice(CFontString::Create({ 200.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "メカニック"));
				SetCharSelectChoice(CFontString::Create({ 415.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "レイダー"));
				SetCharSelectChoice(CFontString::Create({ 580.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "アークフィリア"));
				SetCharSelectChoice(CFontString::Create({ 865.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "コントロール"));
			}

			// 選択肢が使用されている場合
			if (!m_vpListChoice.empty())
			{
				for (auto pChoice : GetChoiceAll())
				{
					pChoice->SetAlpha(MINI_ALPHA);
				}
				// 選択されている選択肢
				m_vpListChoice[m_nSelectChoice]->SetBlink(BLINK_SPEED);
				m_vpListChoice[m_nSelectChoice]->SetAlpha(1.0f);
			}

			SetCharSelectDisplay(true);
			m_bMaxSize = true;
			return;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
}

//=============================================================================
// 縮小処理
//=============================================================================
bool CCharSelect_Window::CharSelectMenuScaleReduce()
{
	if (m_pObject2D != nullptr)
	{// nullチェック

	 // 現在のモード
		CApplication::MODE Mode = CApplication::GetModeType();

		// サイズの縮小
		m_SizeX -= SizeXScaleSpeed;
		m_SizeY -= SizeYScaleSpeed;

		if (m_SizeX <= 0.0f)
		{// Xサイズの最小
			m_SizeX = 0.0f;
		}
		if (m_SizeY <= 0.0f)
		{// Yサイズの最小
			m_SizeY = 0.0f;
		}

		// フォントの削除
		if (m_pFont != nullptr)
		{
			m_pFont->Uninit();
			m_pFont = nullptr;
		}

		// ウィンドウが最小値まで行ったら
		if (m_SizeX <= 0.0f && m_SizeY <= 0.0f)
		{
			// キャラ決定ウィンドウの生成
			if (m_pCharDecision == nullptr && m_bDicisionCreateFlag == false)
			{
				m_pCharDecision = CCharDecision_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), 900.0f, 500.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
				m_bDicisionCreateFlag = true;
			}

			// キャラ選択画面以外の時
			if (!Mode == CApplication::MODE_CHAR_SELECT)
			{
				m_bScale = false;
				CGame::SetGameWindow(true);
				Uninit();						// メニューウィンドウの削除
			}

			return true;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
	return false;
}

//=============================================================================
// キャラクター説明処理
//=============================================================================
void CCharSelect_Window::CharName(const std::string name,const std::string skillname)
{
	m_nLetter[0] = name;
	m_nLetter[1] = skillname;

	m_pCharDecision->SetFont(&m_nLetter[0]);
	m_pCharDecision->SetFont(&m_nLetter[1]);
}

//=============================================================================
// 選択肢の処理
//=============================================================================
void CCharSelect_Window::CharSelectChoice()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	// フェード中では無い場合 && 表示中の場合
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE && m_bDisplay == true)
	{
		// 選択肢が使用されている場合
		if (!m_vpListChoice.empty())
		{

			// 選択肢が2つ以上使用されている場合
			if (m_vpListChoice.size() >= 2)
			{
				// 上に移動する
				if (pInput->Trigger(DIK_Q) || (pInput->Trigger(JOYPAD_UP, m_nMenuInitiative)))
				{
					// 選択SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// 現在の番号が0以下である場合
					CharSelectChangeChoice(m_nSelectChoice <= 0 ? m_vpListChoice.size() - 1 : m_nSelectChoice - 1);
				}
				// 下に移動する
				else if (pInput->Trigger(DIK_E) || (pInput->Trigger(JOYPAD_DOWN, m_nMenuInitiative)))
				{
					//m_bInputFlag = true;
					// 選択SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// 現在の番号が最大数以上の場合
					CharSelectChangeChoice(m_nSelectChoice >= ((int)m_vpListChoice.size() - 1) ? 0 : m_nSelectChoice + 1);
				}
			}

			if (pInput->Trigger(DIK_RETURN) || (pInput->Trigger(JOYPAD_B, m_nMenuInitiative) || pInput->Trigger(JOYPAD_A, m_nMenuInitiative)))
			{
				// 決定SE
				CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

				// 選択を決定する
				m_bDecition = true;
			}
			// 決定された場合
			if (m_bDecition == true)
			{
				for (int nCnt = 0; nCnt < 4; nCnt++)
				{
					if (m_nSelectChoice == nCnt)
					{
						m_bScale = true;
						SetCharSelectDisplay(false);
					}
				}
			}
		}
	}
}

//=============================================================================
// 選択肢を変更した時の処理
//=============================================================================
void CCharSelect_Window::CharSelectChangeChoice(const int nextChoice)
{
	// 現在の選択肢の処理
	m_vpListChoice[m_nSelectChoice]->BlinkFinish();
	m_vpListChoice[m_nSelectChoice]->SetAlpha(MINI_ALPHA);

	// 選択肢の変更
	m_nSelectChoice = (int)nextChoice;

	// 変更後の選択肢の処理
	m_vpListChoice[m_nSelectChoice]->SetBlink(m_fBlinkSpeed);
	m_vpListChoice[m_nSelectChoice]->SetAlpha(1.0f);
}

//============================================================================
// 選択肢の表示判定を設定する
//============================================================================
void CCharSelect_Window::SetCharSelectDisplay(const bool display)
{
	m_bDisplay = display;
	for (auto pChoice : GetChoiceAll()) { pChoice->SetFontDraw(display); }

	//// 表示を消す場合
	//if (display == false)
	//{
	//	// 選択肢の情報を初期化する
	//	CharSelectChangeChoice(0);
	//}
}

//============================================================================
// 生成処理
//============================================================================
CCharSelect_Window * CCharSelect_Window::Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col)
{
	//クラスの生成
	CCharSelect_Window* pCharSelect = new CCharSelect_Window;

	//nullチェック
	if (pCharSelect != nullptr)
	{
		pCharSelect->m_pos = pos;
		pCharSelect->m_Color = col;
		pCharSelect->m_MaxSizeX = xsize;
		pCharSelect->m_MaxSizeY = ysize;
		//初期化処理
		pCharSelect->Init();
	}
	else
	{
		assert(false);
	}

	return pCharSelect;
}
