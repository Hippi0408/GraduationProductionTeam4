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
#include "confirmation_window.h"
#include "object2D.h"
#include "objectX.h"

const float CTitle::GEAR_SPEED = 0.7f;

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

	pCamera->SetPosV({ 0.0f, -200.0f, 1000.0f });
	pCamera->SetPosR({ 0.0f, 200.0f, 0.0f });

	m_pTitle[0] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f - 250.0f, SCREEN_HEIGHT * 0.5f + 100.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[0]->SetTexture(CTexture::TEXTURE_TITLE_00);

	m_pTitle[1] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f + 250.0f, SCREEN_HEIGHT * 0.5f + 100.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[1]->SetTexture(CTexture::TEXTURE_TITLE_01);

	m_pTitle[2] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f - 20.0f, SCREEN_HEIGHT * 0.5f - 30.0f + 100.0f, 0.0f), D3DXVECTOR2(70.0f, 70.0f));
	m_pTitle[2]->SetTexture(CTexture::TEXTURE_TITLE_02);

	m_pTitle[3] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f + 10.0f + 100.0f, 0.0f), D3DXVECTOR2(60.0f, 60.0f));
	m_pTitle[3]->SetTexture(CTexture::TEXTURE_TITLE_03);

	m_pTitle[4] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f - 235.0f, SCREEN_HEIGHT * 0.5f - 50.0f + 100.0f, 0.0f), D3DXVECTOR2(40.0f, 40.0f));
	m_pTitle[4]->SetTexture(CTexture::TEXTURE_TITLE_04);

	m_pTitle[5] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f + 330.0f, SCREEN_HEIGHT * 0.5f - 50.0f + 100.0f, 0.0f), D3DXVECTOR2(40.0f, 40.0f));
	m_pTitle[5]->SetTexture(CTexture::TEXTURE_TITLE_04);

	// ハーフスフィアの生成
	m_pHalf = CHalfSphere::Create(D3DXVECTOR3(800.0f, -2000.0f, -1000.0f), D3DXVECTOR3(3500.0f, 6000.0f, 3500.0f), D3DXVECTOR3(D3DXToRadian(-35), D3DXToRadian(0), D3DXToRadian(0)), CHalfSphere::SPHERE_UP);
	m_pHalf->LoadTexture("Data/texture/Title/title_Bg_00.png");
	m_pHalf->SetAnimation(D3DXVECTOR2(-0.001111f, 0.000f));
	m_pHalf->SetRotMove(D3DXToRadian(0.4f));

	//歯車のモデルの読み込み
	m_nGearIndex[0] = CApplication::GetModel()->ReadObject("Data/model/Gear/Gear_00.x");
	m_nGearIndex[1] = CApplication::GetModel()->ReadObject("Data/model/Gear/Gear_01.x");
	m_nGearIndex[2] = CApplication::GetModel()->ReadObject("Data/model/Gear/Gear_02.x");

	//歯車
	m_pGear[0] = CObjectX::Create(D3DXVECTOR3(-100.0f, 750.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, m_nGearIndex[0]);
	m_pGear[1] = CObjectX::Create(D3DXVECTOR3(-100.0f, 750.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, m_nGearIndex[1]);
	m_pGear[2] = CObjectX::Create(D3DXVECTOR3(-100.0f, 750.0f, 200.0f),D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, m_nGearIndex[2]);
	
	m_pFlare = CObjectX::Create(D3DXVECTOR3(-100.0f, 750.0f, 200.0f), D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(20)), nullptr, "Data/model/Title/flare.x");
	m_pEarth = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(0)), m_pFlare, "Data/model/Title/earth.x");

	m_pFomntString[0] = CFontString::Create({ 500.0f, 600.0f, 0.0f }, { 30.0f, 30.0f }, "ENTER");

	// 静的変数初期化
	m_bWindowUninit = false;
	m_bWindow = false;

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
	m_pEarth->AddRot(D3DXVECTOR3(D3DXToRadian(0), D3DXToRadian(-0.2f), D3DXToRadian(0)));
	m_pGear[0]->AddRot(D3DXVECTOR3(D3DXToRadian(GEAR_SPEED), D3DXToRadian(GEAR_SPEED), D3DXToRadian(GEAR_SPEED)));
	m_pGear[1]->AddRot(D3DXVECTOR3(D3DXToRadian(GEAR_SPEED), D3DXToRadian(-GEAR_SPEED), D3DXToRadian(GEAR_SPEED)));
	m_pGear[2]->AddRot(D3DXVECTOR3(D3DXToRadian(-GEAR_SPEED), D3DXToRadian(-GEAR_SPEED), D3DXToRadian(-GEAR_SPEED)));
	m_pTitle[2]->AddRot(D3DXVECTOR2(D3DXToRadian(0), D3DXToRadian(1)));
	m_pTitle[3]->AddRot(D3DXVECTOR2(D3DXToRadian(0), D3DXToRadian(-1)));
	m_pTitle[4]->AddRot(D3DXVECTOR2(D3DXToRadian(0), D3DXToRadian(-2)));
	m_pTitle[5]->AddRot(D3DXVECTOR2(D3DXToRadian(0), D3DXToRadian(1.5f)));

	CInput* pInput = CInput::GetKey();

	// ウィンドウが表示されていない場合
	if (m_pMenuWindow == nullptr)
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
}

//==============================================================================================
// メニューウィンドウを破棄する処理
//==============================================================================================
void CTitle::UninitMenuWindow()
{
	if (m_pMenuWindow != nullptr)
	{
		delete m_pMenuWindow;
		m_pMenuWindow = nullptr;
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