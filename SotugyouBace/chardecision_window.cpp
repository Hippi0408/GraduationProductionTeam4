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

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
CObject2D* CCharDecision_Window::m_pObject2D[MAX_TEXTURE] = {};

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
	m_nSelectChoice = 0;
	m_SizeX = 0.0f;
	m_SizeY = 0.0f;
	m_bScale = false;
	m_bMaxSize = false;
	m_bUninitFlag = false;
	m_bSpawnWindow = false;
	m_bDecition = false;
	m_pObject2D[0] = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D[0]->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CCharDecision_Window::Uninit()
{
	//メンバ変数の初期化
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

	if (pInput->Trigger(DIK_RETURN) && CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		CFade::SetFade(CApplication::MODE_GAME, 0.05f);
	}
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

		// ウィンドウが最大値まで行ったら
		if (m_SizeX >= m_MaxSizeX && m_SizeY >= m_MaxSizeY && m_bMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_GAME)
			{
				pInput->SetKeyLock(100);
			}

			if (m_pObject2D[1] == nullptr)
			{
				m_pObject2D[1] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 500.0f, 0.0f), D3DXVECTOR2(700.0f, 250.0f), CObject::PRIORITY_SCREEN);
				m_pObject2D[1]->SetTexture(CTexture::TEXTURE_FONT_JAPANESE);
			}
			if (m_pObject2D[2] == nullptr)
			{
				m_pObject2D[2] = CObject2D::Create(D3DXVECTOR3(500.0f, 250.0f, 0.0f), D3DXVECTOR2(175.0f, 175.0f), CObject::PRIORITY_SCREEN);
				m_pObject2D[2]->SetTexture(CTexture::TEXTURE_FLOOR);
			}

			m_bMaxSize = true;
			m_bScale = true;
			return;
		}

		// サイズの設定
		m_pObject2D[0]->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
}

//============================================================================
// ウィンドウの縮小処理
//============================================================================
bool CCharDecision_Window::CharDecisionMenuScaleReduce()
{
	if (m_pObject2D != nullptr)
	{// nullチェック

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
			SetUninit(false);
			SetSapawnWindow(true);
			CGame::SetGameWindow(true);
			Uninit();						// メニューウィンドウの削除
			return true;
		}
		// サイズの設定
		m_pObject2D[0]->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
	return false;
}

//============================================================================
// フォントの設定処理
//============================================================================
void CCharDecision_Window::SetFont(const std::string lette[])
{
	if (m_pFont == nullptr)
	{
		m_pFont = CFontString::Create(D3DXVECTOR3(750.0f, 200.0f, 0.0f), { 25.0f, 25.0f }, lette[0]);
		m_pFont = CFontString::Create(D3DXVECTOR3(650.0f, 300.0f, 0.0f), { 35.0f, 35.0f }, lette[1]);
	}
}

//============================================================================
// フォントの破棄処理
//============================================================================
void CCharDecision_Window::UninitFont()
{
	if (m_pFont != nullptr)
	{
		m_pFont->Uninit();
		delete m_pFont;
		m_pFont = nullptr;
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
