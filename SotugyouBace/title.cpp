//==============================================================================================
//
// タイトル　　　title.cpp
// tutida ryousei
// tanimoto kosuke
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
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	//CFontString::Create({ 490.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "タイトル");

	m_bWindow = false;

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CTitle::Uninit()
{
}

//==============================================================================================
//更新処理
//==============================================================================================
void CTitle::Update()
{
	CInput* pInput = CInput::GetKey();

	CMenu* pMenu = CApplication::GetMenu();

	// ウィンドウが表示されていない場合
	if (m_bWindow == false)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Trigger(JOYPAD_B) || pInput->Trigger(JOYPAD_A)
			|| pInput->Trigger(JOYPAD_START))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			// 決定SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

			// ウィンドウを開く
			m_bWindow = true;

			// メニューの表示
			pMenu->SetDisplay(true);
			//CFade::SetFade(CApplication::MODE_GAME, 0.05f);
		}
	}

	// ウインドウが閉じた場合
	if (pMenu->GetDisplay() == false)
	{
		m_bWindow = false;
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