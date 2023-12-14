//==============================================================================================
//
// キャラクターセレクト　　　char_select.cpp
// tutida ryousei
//
//==============================================================================================
#include"char_select.h"
#include"input.h"
#include"application.h"
#include"fade.h"
#include"fontString.h"
#include"confirmation_window.h"
#include "camera.h"
#include "halfsphere.h"

//==============================================================================================
// 静的メンバ変数宣言
//==============================================================================================
CConfirmation_Window* CChar_Select::m_pConfirmation = nullptr;

//==============================================================================================
// コンストラクタ
//==============================================================================================
CChar_Select::CChar_Select()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CChar_Select::~CChar_Select()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CChar_Select::Init()
{
	m_pFont = CFontString::Create({ 280.0f, 200.0f, 0.0f }, { 50.0f, 50.0f }, "キャラクターセレクト");

	// カメラのポインタ
	CCamera* pCamera = CApplication::GetCamera();

	pCamera->SetPosV({ 0.0f, 2000.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 2000.0f, 1000.0f });

	// ハーフスフィアの生成
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f),  D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CChar_Select::Uninit()
{
	// メニューウィンドウの終了処理
	if (m_pConfirmation != nullptr)
	{
		m_pConfirmation->Uninit();
		delete m_pConfirmation;
		m_pConfirmation = nullptr;
	}
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CChar_Select::Update()
{
	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			if (m_pConfirmation == nullptr)
			{
				m_pConfirmation = CConfirmation_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 450.0f, 0.0f), 500.0f, 120.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
			}
		}

		//// キャラセレクト画面に戻る
		//if (pInput->Trigger(DIK_BACK, nCnt)
		//	&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		//{
		//	// 画面遷移
		//	CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
		//}
	}

	if (m_pConfirmation != nullptr)
	{
		m_pConfirmation->Update();

		/*if (m_pConfirmation->GetSelectChoice() == true)
		{
			CFade::SetFade(CApplication::MODE_STAGE_SELECT, 0.05f);
		}*/
	}

	// ウィンドウが閉じた場合 
	if (m_pConfirmation != nullptr && m_pConfirmation->GetSapawnWindow() == true)
	{
		m_pConfirmation->SetSapawnWindow(false);
		delete m_pConfirmation;
		m_pConfirmation = nullptr;
	}
}

//==============================================================================================
// 生成処理
//==============================================================================================
CChar_Select* CChar_Select::Create()
{
	CChar_Select* pChar_Select = new CChar_Select;

	if (FAILED(pChar_Select->Init()))
	{
		return nullptr;
	}

	return pChar_Select;
}
