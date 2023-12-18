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
#include "debugProc.h"

const D3DXVECTOR3 CTitle::TITLE_LOGO_POS = D3DXVECTOR3(SCREEN_WIDTH * 0.5f - 50.0f, SCREEN_HEIGHT * 0.5f - 100.0f, 0.0f);
const D3DXVECTOR3 CTitle::TITLE_LOGO_GEAR_POS = TITLE_LOGO_POS + D3DXVECTOR3(250.0f, 50.0f, 0.0f);
const float CTitle::TITLE_LOGO_GEAR_SIZE = 200.0f;
const float CTitle::GEAR_SPEED = 0.08f;

const D3DXVECTOR3 CTitle::TITLE_3D_MODEL_POS = D3DXVECTOR3(0.0f, 780.0f, 930.0f);
//const D3DXVECTOR3 CTitle::TITLE_3D_MODEL_POS = D3DXVECTOR3(-400.0f, 750.0f, -200.0f);


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

	

	m_pGearLogo[0] = CObject2D::Create(TITLE_LOGO_GEAR_POS + D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR2(TITLE_LOGO_GEAR_SIZE, TITLE_LOGO_GEAR_SIZE));
	m_pGearLogo[0]->SetTexture(CTexture::TEXTURE_TITLE_GEAR_00);

	m_pGearLogo[1] = CObject2D::Create(TITLE_LOGO_GEAR_POS + D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR2(TITLE_LOGO_GEAR_SIZE, TITLE_LOGO_GEAR_SIZE));
	m_pGearLogo[1]->SetTexture(CTexture::TEXTURE_TITLE_GEAR_01);

	m_pGearLogo[2] = CObject2D::Create(TITLE_LOGO_GEAR_POS + D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR2(TITLE_LOGO_GEAR_SIZE, TITLE_LOGO_GEAR_SIZE));
	m_pGearLogo[2]->SetTexture(CTexture::TEXTURE_TITLE_GEAR_02);

	m_pGearLogo[3] = CObject2D::Create(TITLE_LOGO_GEAR_POS + D3DXVECTOR3(-40.0f, 60.0f, 0.0f), D3DXVECTOR2(TITLE_LOGO_GEAR_SIZE, TITLE_LOGO_GEAR_SIZE));
	m_pGearLogo[3]->SetTexture(CTexture::TEXTURE_TITLE_GEAR_03);
	m_pGearLogo[3]->SetRot(D3DXVECTOR2(0.0f, D3DXToRadian(-10)));

	m_pGearLogo[4] = CObject2D::Create(TITLE_LOGO_GEAR_POS + D3DXVECTOR3(-40.0f, 60.0f, 0.0f), D3DXVECTOR2(TITLE_LOGO_GEAR_SIZE, TITLE_LOGO_GEAR_SIZE));
	m_pGearLogo[4]->SetTexture(CTexture::TEXTURE_TITLE_GEAR_04);
	m_pGearLogo[4]->SetRot(D3DXVECTOR2(0.0f, D3DXToRadian(-10)));

	m_pGearLogo[5] = CObject2D::Create(TITLE_LOGO_GEAR_POS + D3DXVECTOR3(10.0f, 15.0f, 0.0f), D3DXVECTOR2(TITLE_LOGO_GEAR_SIZE, TITLE_LOGO_GEAR_SIZE));
	m_pGearLogo[5]->SetTexture(CTexture::TEXTURE_TITLE_GEAR_05);
	m_pGearLogo[5]->SetRot(D3DXVECTOR2(0.0f, D3DXToRadian(22.5f)));

	m_pGearLogo[6] = CObject2D::Create(TITLE_LOGO_GEAR_POS + D3DXVECTOR3(85.0f, -60.0f, 0.0f), D3DXVECTOR2(TITLE_LOGO_GEAR_SIZE, TITLE_LOGO_GEAR_SIZE));
	m_pGearLogo[6]->SetTexture(CTexture::TEXTURE_TITLE_GEAR_06);
	m_pGearLogo[6]->SetRot(D3DXVECTOR2(0.0f, D3DXToRadian(0)));

	//タイトルロゴ
	m_pTitle[0] = CObject2D::Create(TITLE_LOGO_POS + D3DXVECTOR3(340.0f, 150.0f, 0.0f), D3DXVECTOR2(600.0f, 600.0f));
	m_pTitle[0]->SetTexture(CTexture::TEXTURE_TITLE_ROBOT);




	m_pTitle[1] = CObject2D::Create(TITLE_LOGO_POS + D3DXVECTOR3(-165.0f, 25.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[1]->SetTexture(CTexture::TEXTURE_TITLE_00);

	m_pTitle[2] = CObject2D::Create(TITLE_LOGO_POS + D3DXVECTOR3(-240.0f, 25.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[2]->SetTexture(CTexture::TEXTURE_TITLE_01);

	m_pTitle[3] = CObject2D::Create(TITLE_LOGO_POS + D3DXVECTOR3(-10.0f, 25.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[3]->SetTexture(CTexture::TEXTURE_TITLE_02);




	m_pTitle[4] = CObject2D::Create(TITLE_LOGO_POS + D3DXVECTOR3(-240.0f, 150.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[4]->SetTexture(CTexture::TEXTURE_TITLE_03);

	m_pTitle[5] = CObject2D::Create(TITLE_LOGO_POS + D3DXVECTOR3(0.0f, 150.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[5]->SetTexture(CTexture::TEXTURE_TITLE_04);

	m_pTitle[6] = CObject2D::Create(TITLE_LOGO_POS + D3DXVECTOR3(210.0f, 150.0f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[6]->SetTexture(CTexture::TEXTURE_TITLE_05);

	


	// ハーフスフィアの生成
	m_pHalf = CHalfSphere::Create(D3DXVECTOR3(-1580.0f, -1520.0f, -7280.0f), D3DXVECTOR3(5000.0f, 20000.0f, 5000.0f), D3DXVECTOR3(0.593413f, 2.338741f, -0.663226f), CHalfSphere::SPHERE_UP);
	m_pHalf->LoadTexture("Data/texture/Title/title_Bg_00.png");
	m_pHalf->SetAnimation(D3DXVECTOR2(-0.001111f, 0.000f));
	m_pHalf->SetRotMove(D3DXToRadian(0.4f));

	//歯車のモデルの読み込み
	m_nGearIndex[0] = CApplication::GetModel()->ReadObject("Data/model/Gear/Gear_00.x");
	m_nGearIndex[1] = CApplication::GetModel()->ReadObject("Data/model/Gear/Gear_01.x");
	m_nGearIndex[2] = CApplication::GetModel()->ReadObject("Data/model/Gear/Gear_02.x");

	//歯車
	m_pGear[0] = CObjectX::Create(TITLE_3D_MODEL_POS, D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, m_nGearIndex[0]);
	m_pGear[0]->SetWireFrame(true);
	m_pGear[1] = CObjectX::Create(TITLE_3D_MODEL_POS, D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, m_nGearIndex[1]);
	m_pGear[1]->SetWireFrame(true);
	m_pGear[2] = CObjectX::Create(TITLE_3D_MODEL_POS,D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, m_nGearIndex[2]);
	m_pGear[2]->SetWireFrame(true);
	
	m_pFlare = CObjectX::Create(TITLE_3D_MODEL_POS, D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(20)), nullptr, "Data/model/Title/flare.x");
	m_pEarth = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(0)), m_pFlare, "Data/model/Title/earth.x");
	//m_pEarth->SetWireFrame(true);

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
	m_pEarth->AddRot(D3DXVECTOR3(D3DXToRadian(0), D3DXToRadian(-0.02f), D3DXToRadian(0)));
	m_pGear[0]->AddRot(D3DXVECTOR3(D3DXToRadian(GEAR_SPEED), D3DXToRadian(GEAR_SPEED), D3DXToRadian(GEAR_SPEED)));
	m_pGear[1]->AddRot(D3DXVECTOR3(D3DXToRadian(GEAR_SPEED), D3DXToRadian(-GEAR_SPEED), D3DXToRadian(GEAR_SPEED)));
	m_pGear[2]->AddRot(D3DXVECTOR3(D3DXToRadian(-GEAR_SPEED), D3DXToRadian(-GEAR_SPEED), D3DXToRadian(-GEAR_SPEED)));
	
	m_pGearLogo[0]->AddRot(D3DXVECTOR2(0.0f, D3DXToRadian(1)));
	m_pGearLogo[1]->AddRot(D3DXVECTOR2(0.0f, D3DXToRadian(1)));
	m_pGearLogo[2]->AddRot(D3DXVECTOR2(0.0f, D3DXToRadian(1)));
	m_pGearLogo[3]->AddRot(D3DXVECTOR2(0.0f, D3DXToRadian(-1)));
	m_pGearLogo[4]->AddRot(D3DXVECTOR2(0.0f, D3DXToRadian(-1)));
	m_pGearLogo[5]->AddRot(D3DXVECTOR2(0.0f, D3DXToRadian(1)));
	m_pGearLogo[6]->AddRot(D3DXVECTOR2(0.0f, D3DXToRadian(-0.5f)));

	CInput* pInput = CInput::GetKey();

	/*if (pInput->Press(DIK_W))
	{
		m_pHalf->AddPos(D3DXVECTOR3(0.0f,0.0f,10.0f));
	}
	if (pInput->Press(DIK_S))
	{
		m_pHalf->AddPos(D3DXVECTOR3(0.0f, 0.0f, -10.0f));
	}

	if (pInput->Press(DIK_A))
	{
		m_pHalf->AddPos(D3DXVECTOR3(10.0f, 0.0f, 0.0f));
	}
	if (pInput->Press(DIK_D))
	{
		m_pHalf->AddPos(D3DXVECTOR3(-10.0f, 0.0f, 0.0f));
	}

	if (pInput->Press(DIK_LSHIFT))
	{
		m_pHalf->AddPos(D3DXVECTOR3(0.0f, 10.0f, 0.0f));
	}
	if (pInput->Press(DIK_LCONTROL))
	{
		m_pHalf->AddPos(D3DXVECTOR3(0.0f, -10.0f, 0.0f));
	}



	if (pInput->Press(DIK_UP))
	{
		m_pHalf->AddRot(D3DXVECTOR3(0.0f, 0.0f, D3DXToRadian(1)));
	}
	if (pInput->Press(DIK_DOWN))
	{
		m_pHalf->AddRot(D3DXVECTOR3(0.0f, 0.0f, -D3DXToRadian(1)));
	}

	if (pInput->Press(DIK_LEFT))
	{
		m_pHalf->AddRot(D3DXVECTOR3(D3DXToRadian(1), 0.0f, 0.0f));
	}
	if (pInput->Press(DIK_RIGHT))
	{
		m_pHalf->AddRot(D3DXVECTOR3(-D3DXToRadian(1), 0.0f, 0.0f));
	}

	if (pInput->Press(DIK_RSHIFT))
	{
		m_pHalf->AddRot(D3DXVECTOR3(0.0f, D3DXToRadian(1), 0.0f));
	}
	if (pInput->Press(DIK_RCONTROL))
	{
		m_pHalf->AddRot(D3DXVECTOR3(0.0f, -D3DXToRadian(1), 0.0f));
	}*/


	//CDebugProc::Print("POS：%f , %f , %f\n", m_pHalf->GetPos().x, m_pHalf->GetPos().y, m_pHalf->GetPos().z);
	//CDebugProc::Print("ROT：%f , %f , %f\n", m_pHalf->GetRot().x, m_pHalf->GetRot().y, m_pHalf->GetRot().z);

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