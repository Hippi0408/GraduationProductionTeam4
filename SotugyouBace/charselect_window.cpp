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
#include "texture.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
const float CCharSelect_Window::BLINK_SPEED = 0.02f;	// 選択肢の点滅速度
const float CCharSelect_Window::MINI_ALPHA = 0.5f;		// 選択肢の最低透明値

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
	m_CharSelectWindowSize = D3DXVECTOR2(0.0f, 0.0f);
	m_nCharSelectWindowSelectChoice = 0;
	m_bCharSelectWindowScale = false;
	m_bCharSelectWindowMaxSize = false;
	m_bCharSelectWindowDecition = false;
	m_bDicisionCreateFlag = false;
	m_bCharSelectWindowWindowUse = false;
	m_bCharSelectWindowBackFlag = false;
	m_bCharSelectWindowUninitFlag = false;
	m_bPreviousWindowCreate = false;
	m_bDicisionUse = false;

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
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	if (m_bCharSelectWindowScale == false && m_bCharSelectWindowWindowUse == false)
	{// 拡大されていない時 

	 // ウィンドウの拡大処理
		CharSelectMenuScale();
	}
	else if (m_bCharSelectWindowScale == true && m_bCharSelectWindowWindowUse == false)
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

	// 選択した番号によって出すウィンドウを変える処理
	SetSelectChoice(m_nCharSelectWindowSelectChoice);

	if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetUninit() == true
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetScaleReduce() == false
		&& m_bCharSelectWindowWindowUse == true)
	{
		// ウィンドウの拡大処理
		CharSelectMenuScale();
		m_bCharSelectWindowBackFlag = true;
	}

	// キャラ決定ウィンドウが閉じた場合 
	if (m_pCharDecision != nullptr && m_pCharDecision->GetSapawnWindow() == false)
	{
		m_bDicisionUse = false;
	}

	// ゲーム画面への遷移
	if (pInput->Trigger(DIK_BACK)
		&& m_bCharSelectWindowUninitFlag == false
		&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{ // キーが押された時 && キャラ選択ウィンドウが削除されてない時 && フェードしてない時

		// フォントの削除処理
		UninitFont();
		SetCharSelectDisplay(false);			// 表示させない
		m_bCharSelectWindowUninitFlag = true;	// ウィンドウ削除フラグをtrue
		m_bCharSelectWindowScale = true;		// 拡大縮小フラグをtrue
	}
	if (m_bCharSelectWindowUninitFlag == true && m_bCharSelectWindowBackFlag == false)
	{ // キャラ選択ウィンドウが削除された時 && 前のウィンドウから戻ってきた時

		// 縮小処理
		CharSelectMenuScaleReduce();
	}
}

//=============================================================================
// 拡大処理
//=============================================================================
void CCharSelect_Window::CharSelectMenuScale()
{
	if (m_pObject2D != nullptr)
	{// nullチェック

		// サイズの拡大
		m_CharSelectWindowSize.x += SizeXScaleSpeed;
		m_CharSelectWindowSize.y += SizeYScaleSpeed;

		if (m_CharSelectWindowSize.x >= m_CharSelectWindowMaxSize.x)
		{// Xサイズの最大
			m_CharSelectWindowSize.x = m_CharSelectWindowMaxSize.x;
		}
		if (m_CharSelectWindowSize.y >= m_CharSelectWindowMaxSize.y)
		{// Yサイズの最大
			m_CharSelectWindowSize.y = m_CharSelectWindowMaxSize.y;
		}

		// ウィンドウが最大値まで行ったら
		if (m_CharSelectWindowSize.x >= m_CharSelectWindowMaxSize.x && m_CharSelectWindowSize.y >= m_CharSelectWindowMaxSize.y && m_bCharSelectWindowMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
			{
   				if (m_pFont == nullptr)
				{
					m_pFont = CFontString::Create(D3DXVECTOR3(500.0f, 200.0f, 0.0f), { 30.0f, 30.0f }, "ストライカー");
				}

				SetCharSelectChoice(CFontString::Create({ 200.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "ラッシュ"));
				SetCharSelectChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "ヴァンガード"));
				SetCharSelectChoice(CFontString::Create({ 625.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "イーグルアイ"));
				SetCharSelectChoice(CFontString::Create({ 875.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "マーシャル"));
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
				m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetBlink(BLINK_SPEED);
				m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetAlpha(1.0f);
			}

			if (m_bCharSelectWindowBackFlag == true)
			{
				// メンバ変数初期化
				m_bCharSelectWindowWindowUse = false;
				m_bCharSelectWindowScale = false;
				m_bCharSelectWindowDecition = false;
				m_bDicisionCreateFlag = false;
				m_bCharSelectWindowBackFlag = false;
				m_bCharSelectWindowUninitFlag = false;

				// 選択肢の初期化
				InitSelect();
				
				if (m_pCharDecision != nullptr)
				{
					// キャラ決定画面の破棄
					m_pCharDecision->Uninit();
					delete m_pCharDecision;
					m_pCharDecision = nullptr;
				}
			}

			SetCharSelectDisplay(true);
			m_bCharSelectWindowMaxSize = true;

			return;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(m_CharSelectWindowSize.x, m_CharSelectWindowSize.y));
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
		m_CharSelectWindowSize.x -= SizeXScaleSpeed;
		m_CharSelectWindowSize.y -= SizeYScaleSpeed;

		if (m_CharSelectWindowSize.x <= 0.0f)
		{// Xサイズの最小
			m_CharSelectWindowSize.x = 0.0f;
		}
		if (m_CharSelectWindowSize.y <= 0.0f)
		{// Yサイズの最小
			m_CharSelectWindowSize.y = 0.0f;
		}

		// フォントの削除処理
		UninitFont();

		// ウィンドウが最小値まで行ったら
		if (m_CharSelectWindowSize.x <= 0.0f && m_CharSelectWindowSize.y <= 0.0f)
		{
			// キャラ選択画面以外の時
			if (!Mode == CApplication::MODE_CHAR_SELECT)
			{
				m_bCharSelectWindowScale = false;
				CGame::SetGameWindow(true);
				Uninit();						// メニューウィンドウの削除
			}
			else if (Mode == CApplication::MODE_CHAR_SELECT && m_bCharSelectWindowWindowUse == false)
			{
				m_bCharSelectWindowWindowUse = true;
				m_bCharSelectWindowMaxSize = false;
				m_bCharSelectWindowDecition = false;
				m_bDicisionCreateFlag = false;
			}
			
			// キャラ決定ウィンドウの生成
			if (m_pCharDecision == nullptr && m_bDicisionCreateFlag == false && m_bCharSelectWindowUninitFlag == false)
			{
				m_pCharDecision = CCharDecision_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), 900.0f, 500.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
				m_bDicisionUse = true;
			}
			if (m_bCharSelectWindowBackFlag == true && m_bDicisionUse == false)
			{
				m_bPreviousWindowCreate = true;
			}
			else if (m_bCharSelectWindowBackFlag == false && m_bDicisionUse == false)
			{
				m_bPreviousWindowCreate = true;
			}

			// 初期値に戻す
			m_bDicisionCreateFlag = true;
			m_bCharSelectWindowUninitFlag = false; 
			return true;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(m_CharSelectWindowSize.x, m_CharSelectWindowSize.y));
	}
	return false;
}

//=============================================================================
// キャラクター説明処理
//=============================================================================
void CCharSelect_Window::SetSkillName(const std::string name, const std::string skillname)
{
	m_nLetter[0] = name;
	m_nLetter[1] = skillname;

	m_pCharDecision->SetFont(&m_nLetter[0]);
	m_pCharDecision->SetFont(&m_nLetter[1]);
}

//=============================================================================
// 選択した番号によってスキルを変える処理
//=============================================================================
void CCharSelect_Window::SetSkillSelectChoice(const std::string type,const std::string name, const std::string name1, const std::string name2, const std::string name3)
{
	std::string SkillName;
	std::string Name = type;

	if (m_nCharSelectWindowSelectChoice == 0)
	{
		SkillName = name;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_RUSH, CTexture::TEXTURE_SKILLEXPLANATION_RUSH);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_MECHANIC, CTexture::TEXTURE_SKILLEXPLANATION_MECHANIC);
		}
	
	}
	if (m_nCharSelectWindowSelectChoice == 1)
	{
		SkillName = name1;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_VANGUARD, CTexture::TEXTURE_SKILLEXPLANATION_VANGUARD);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_RAIDER, CTexture::TEXTURE_SKILLEXPLANATION_RAIDER);
		}
		
	}
	if (m_nCharSelectWindowSelectChoice == 2)
	{
		SkillName = name2;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_EAGLEEYE, CTexture::TEXTURE_SKILLEXPLANATION_EAGLEEYE);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_ARCPHILIA, CTexture::TEXTURE_SKILLEXPLANATION_ARCPHILIA);
		}
	}
	if (m_nCharSelectWindowSelectChoice == 3 || m_nCharSelectWindowSelectChoice == -1)
	{
		SkillName = name3;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_MARSHALL, CTexture::TEXTURE_SKILLEXPLANATION_MARSHALL);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_CONTROL, CTexture::TEXTURE_SKILLEXPLANATION_CONTROL);
		}
	}
}

//=============================================================================
// 選択肢の初期化処理
//=============================================================================
void CCharSelect_Window::InitSelect()
{
	// 選択肢の情報を初期化する
	CharSelectChangeChoice(0);
}

//=============================================================================
// フォントの削除処理
//=============================================================================
void CCharSelect_Window::UninitFont()
{
	// フォントの削除
	if (m_pFont != nullptr)
	{
		m_pFont->Uninit();
		m_pFont = nullptr;
	}
}

//=============================================================================
// 選択肢の処理
//=============================================================================
void CCharSelect_Window::CharSelectChoice()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	// フェード中では無い場合 && 表示中の場合
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE && m_bCharSelectWindowDisplay == true)
	{
		// 選択肢が使用されている場合
		if (!m_vpListChoice.empty())
		{

			// 選択肢が2つ以上使用されている場合
			if (m_vpListChoice.size() >= 2)
			{
				// 上に移動する
				if (pInput->Trigger(DIK_A) || (pInput->Trigger(JOYPAD_UP)))
				{
					// 選択SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// 現在の番号が0以下である場合
					CharSelectChangeChoice(m_nCharSelectWindowSelectChoice <= 0 ? m_vpListChoice.size() - 1 : m_nCharSelectWindowSelectChoice - 1);
				}
				// 下に移動する
				else if (pInput->Trigger(DIK_D) || (pInput->Trigger(JOYPAD_DOWN)))
				{
					//m_bInputFlag = true;
					// 選択SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// 現在の番号が最大数以上の場合
					CharSelectChangeChoice(m_nCharSelectWindowSelectChoice >= ((int)m_vpListChoice.size() - 1) ? 0 : m_nCharSelectWindowSelectChoice + 1);
				}
			}

			if (pInput->Trigger(DIK_RETURN) || (pInput->Trigger(JOYPAD_B) || pInput->Trigger(JOYPAD_A)))
			{
				// 決定SE
				CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

				// 選択を決定する
				m_bCharSelectWindowDecition = true;
			}
			// 決定された場合
			if (m_bCharSelectWindowDecition == true)
			{
				for (int nCnt = 0; nCnt < 4; nCnt++)
				{
					if (m_nCharSelectWindowSelectChoice == nCnt)
					{
						m_bCharSelectWindowScale = true;
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
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->BlinkFinish();
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetAlpha(MINI_ALPHA);

	// 選択肢の変更
	m_nCharSelectWindowSelectChoice = (int)nextChoice;

	// 変更後の選択肢の処理
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetBlink(m_fCharSelectWindowBlinkSpeed);
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetAlpha(1.0f);
}

//============================================================================
// 選択した番号
//============================================================================
void CCharSelect_Window::SetSelectChoice(int index)
{
	// 選択した番号を保存する
	m_nCharSelectWindowSelectChoice = index;

	// 選択した番号が0以下だったら
	if (m_nCharSelectWindowSelectChoice == -1)
	{
		// 番号を3にする
		m_nCharSelectWindowSelectChoice = 3;
	}
	// 選択した番号が4以上だったら
	if (m_nCharSelectWindowSelectChoice == 4)
	{
		// 番号を0にする
		m_nCharSelectWindowSelectChoice = 0;
	}

	// キャラごと
	if (m_pCharDecision != nullptr && m_pCharDecision->GetMaxScale() == true)
	{
		if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetExplanationUninit() == false)
		{
			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
			{
				SetSkillSelectChoice("ストライカー", "ラッシュ", "ヴァンガード", "イーグルアイ", "マーシャル");
			}
		}
		if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetExplanationUninit() == false)
		{
			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == false)
			{
				SetSkillSelectChoice("コマンダー", "メカニック", "レイダー", "アークフィリア", "コントロール");
			}
		}
	}
}

//============================================================================
// 選択肢の表示判定を設定する
//============================================================================
void CCharSelect_Window::SetCharSelectDisplay(const bool display)
{
	m_bCharSelectWindowDisplay = display;
	for (auto pChoice : GetChoiceAll()) { pChoice->SetFontDraw(display); }
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
		pCharSelect->m_CharSelectWindowMaxSize.x = xsize;
		pCharSelect->m_CharSelectWindowMaxSize.y = ysize;
		//初期化処理
		pCharSelect->Init();
	}
	else
	{
		assert(false);
	}

	return pCharSelect;
}
