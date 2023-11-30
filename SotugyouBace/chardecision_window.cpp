//============================================================================
//
// chardecision_window.cpp (キャラ決定ウィンドウ.cpp)
// Author : Saito Shian
//
//============================================================================

//============================================================================
// インクルード
//============================================================================
#include "chardecision_window.h"
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
#include "texture.h"
#include "confirmation_window.h"
#include "charselect_window.h"
#include "char_select.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
const float CCharDecision_Window::BLINK_SPEED = 0.02f;	// 選択肢の点滅速度
const float CCharDecision_Window::MINI_ALPHA = 0.5f;	// 選択肢の最低透明値

//============================================================================
// コンストラクタ
//============================================================================
CCharDecision_Window::CCharDecision_Window()
{
}

//============================================================================
// デストラクタ
//============================================================================
CCharDecision_Window::~CCharDecision_Window()
{
}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CCharDecision_Window::Init()
{
	//==================================================
	// メンバ変数の初期化
	//==================================================  
	m_nSelectIndex = 0;
	index = 0;
	m_SizeX = 0.0f;
	m_SizeY = 0.0f;
	m_fMoveX = 50.0f;
	m_bScale = false;
	m_bMaxSize = false;
	m_bUninitFlag = false;
	m_bFontFlag = false;
	m_bDecition = false;
	m_bDisplay = false;
	m_bStopFlag = false;
	m_bPosDest = false;
	m_bExplanationUninit = false;
	m_pWindow = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pWindow->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CCharDecision_Window::Uninit()
{
	//メンバ変数の初期化
	if (m_pWindow != nullptr)
	{
		m_pWindow->Uninit();
		m_pWindow = nullptr;
	}
}

//============================================================================
// 更新処理
//============================================================================
void CCharDecision_Window::Update()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	if (m_bScale == false)
	{// 拡大されていない時

	 // ウィンドウの拡大処理
		CharDecisionMenuScale();
	}

	if (pInput->Trigger(DIK_RETURN)
		&& m_bMaxSize == true
		&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		UninitExplanation();				// フォントの削除
		// 画面遷移
		CFade::SetFade(CApplication::MODE_GAME, 0.1f);
	}

	// キャラの変更処理
	CharSelectChoice();
}

//============================================================================
// ウィンドウの拡大処理
//============================================================================
void CCharDecision_Window::CharDecisionMenuScale()
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

		//// 拡大スキップ
		//if (pInput->Trigger(DIK_RETURN) && m_bMaxSize == false)
		//{
		//	m_SizeX = m_MaxSizeX;
		//	m_SizeY = m_MaxSizeY;
		//	// サイズの設定
		//	m_pWindow->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
		//}

		// ウィンドウが最大値まで行ったら
		if (m_SizeX >= m_MaxSizeX && m_SizeY >= m_MaxSizeY && m_bMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_GAME)
			{
				pInput->SetKeyLock(100);
			}

			if (m_bUninitFlag == false && m_bScale == true)
			{
				m_bMaxSize = true;
				m_bFontFlag = false;
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(m_nSelectIndex);
			}

			m_bMaxSize = true;
			m_bScale = true;
			return;
		}

		// サイズの設定
		m_pWindow->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
}

//=============================================================================
// 選択肢の処理
//=============================================================================
void CCharDecision_Window::CharSelectChoice()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	D3DXVECTOR3 pos = m_pWindow->GetPos();

	// フェード中では無い場合 && 表示中の場合
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		// 左に移動する
		if (pInput->Trigger(DIK_A) && m_bStopFlag == false || (pInput->Trigger(JOYPAD_UP, m_nMenuInitiative)) && m_bStopFlag == false)
		{
			index = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			index--;
			m_bUninitFlag = true;
			m_bDecition = false;
			m_bPosDest = false;
			m_bStopFlag = true;
			// 選択SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

		}
		// 下に移動する
		else if (pInput->Trigger(DIK_D) && m_bStopFlag == false || (pInput->Trigger(JOYPAD_DOWN, m_nMenuInitiative)) && m_bStopFlag == false)
		{
			index = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			index++;
			m_bUninitFlag = true;
			m_bDecition = true;
			m_bPosDest = false;
			m_bStopFlag = true;
			// 選択SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);
		}
	}

	if (m_bUninitFlag == true)
	{
		// 左移動
		if (m_bDecition == false)
		{
			m_bExplanationUninit = true;
			UninitExplanation();				// フォントの削除
			pos.x -= m_fMoveX;
			if (pos.x <= -SCREEN_WIDTH / 2 && m_bPosDest == false)
			{
				pos.x = 1920.0f;
				m_bPosDest = true;
			}
			if (pos.x <= SCREEN_WIDTH / 2 && m_bPosDest == true)
			{
				pos.x = SCREEN_WIDTH / 2;
				m_bFontFlag = false;
				m_bStopFlag = false;
				m_bExplanationUninit = false;
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(index);
			}
		}
		// 右移動
		else
		{
			m_bExplanationUninit = true;
			UninitExplanation();				// フォントの削除
			pos.x += m_fMoveX;
			if (pos.x >= 1920.0f && m_bPosDest == false)
			{
				pos.x = -SCREEN_WIDTH / 2;
				m_bPosDest = true;
			}
			if (pos.x >= SCREEN_WIDTH / 2 && m_bPosDest == true)
			{
				pos.x = SCREEN_WIDTH / 2;
				m_bFontFlag = false;
				m_bStopFlag = false;
				m_bExplanationUninit = false;
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(index);
			}
		}
		m_pWindow->SetPos(pos);
	}
}

//============================================================================
// フォントの設定処理
//============================================================================
void CCharDecision_Window::SetFont(const std::string lette[])
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_pFont[nCnt] == nullptr && m_bFontFlag == false)
		{
			m_pFont[0] = CFontString::Create(D3DXVECTOR3(750.0f, 200.0f, 0.0f), { 25.0f, 25.0f }, lette[0]);
			m_pFont[1] = CFontString::Create(D3DXVECTOR3(650.0f, 300.0f, 0.0f), { 35.0f, 35.0f }, lette[1]);
			m_bFontFlag = true;
		}
	}
}

//============================================================================
// テクスチャの設定処理
//============================================================================
void CCharDecision_Window::SetTextue(CTexture::TEXTURE texture, CTexture::TEXTURE texture1)
{
	if (m_pObject2D[0] == nullptr)
	{
		m_pObject2D[0] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 500.0f, 0.0f), D3DXVECTOR2(700.0f, 250.0f), CObject::PRIORITY_SCREEN);
		m_pObject2D[0]->SetTexture(texture1);
	}
	if (m_pObject2D[1] == nullptr)
	{
		m_pObject2D[1] = CObject2D::Create(D3DXVECTOR3(500.0f, 250.0f, 0.0f), D3DXVECTOR2(175.0f, 175.0f), CObject::PRIORITY_SCREEN);
		m_pObject2D[1]->SetTexture(texture);
	}
}

//============================================================================
// 説明用テクスチャ、フォントの破棄処理
//============================================================================
void CCharDecision_Window::UninitExplanation()
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_pFont[nCnt] != nullptr)
		{
			m_pFont[nCnt]->Uninit();
			m_pFont[nCnt] = nullptr;
		}
	}

	for (int nCnt = 0; nCnt < MAX_TEXTURE; nCnt++)
	{
		if (m_pObject2D[nCnt] != nullptr)
		{
			m_pObject2D[nCnt]->Uninit();
			m_pObject2D[nCnt] = nullptr;
		}
	}
}

//============================================================================
// 生成処理
//============================================================================
CCharDecision_Window * CCharDecision_Window::Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col)
{
	//クラスの生成
	CCharDecision_Window* pCharDecision = new CCharDecision_Window;

	//nullチェック
	if (pCharDecision != nullptr)
	{
		pCharDecision->m_pos = pos;
		pCharDecision->m_Color = col;
		pCharDecision->m_MaxSizeX = xsize;
		pCharDecision->m_MaxSizeY = ysize;
		//初期化処理
		pCharDecision->Init();
	}
	else
	{
		assert(false);
	}

	return pCharDecision;
}