//==============================================================================================
//
// タイトル　　　title.cpp
// tutida ryousei
// tanimoto kosuke
// saito shian
//
//==============================================================================================
#include "title.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include "camera.h"
#include "fontString.h"
#include "halfsphere.h"
#include "title_menu.h"
#include "menu_window.h"

bool CTitle::m_bWindow = false;
bool CTitle::m_bWindowUninit = false;
CMenuWindow* CTitle::m_pMenuWindow = nullptr;

//==============================================================================================
// コンストラクタ
//==============================================================================================
CTitle::CTitle()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CTitle::~CTitle()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CTitle::Init()
{
	// カメラのポインタ
	CCamera* pCamera = CApplication::GetCamera();

	pCamera->SetPosV({ 0.0f, 500.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 1000.0f });

	// ハーフスフィアの生成
	m_pHalf = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalf->LoadTexture("Data/texture/sky000.jpg");

	m_pFomntString[0] = CFontString::Create({ 490.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "タイトル");
	m_pFomntString[1] = CFontString::Create({ 500.0f, 600.0f, 0.0f }, { 30.0f, 30.0f }, "ENTER");

	m_bWindowUninit = GetUninitWindow();

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CTitle::Uninit()
{
	// メニューウィンドウの終了処理
	if (m_pMenuWindow != nullptr)
	{
		m_pMenuWindow->Uninit();
		delete m_pMenuWindow;
		m_pMenuWindow = nullptr;
	}
}

//==============================================================================================
//更新処理
//==============================================================================================
void CTitle::Update()
{
	CInput* pInput = CInput::GetKey();

	// ウィンドウが表示されていない場合
	if(m_pMenuWindow == nullptr)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Trigger(JOYPAD_B) || pInput->Trigger(JOYPAD_A)
			|| pInput->Trigger(JOYPAD_START))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			// メニューウィンドウの生成
			m_pMenuWindow = CMenuWindow::Create();

			// 決定SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

			return;
		}
	}
	else
	{
		// メニューウィンドウの更新
		m_pMenuWindow->Update();
	}

	// ウインドウが閉じた場合
	if (m_pMenuWindow != nullptr && m_bWindow == true)
	{
		if (pInput->Trigger(DIK_RETURN))
		{
			CApplication::GetMenu()->SetDisplay(false);
			m_bWindowUninit = true;
		}
	}

	if (m_pMenuWindow != nullptr && m_bWindowUninit == true)
	{
		m_pMenuWindow->MenuScaleReduce();
	}
}

//==============================================================================================
// 生成処理
//==============================================================================================
CTitle* CTitle::Create()
{
	CTitle* pTitle =  new CTitle;

	if (FAILED(pTitle->Init()))
	{
		return nullptr;
	}

	return pTitle;
}