//==============================================================================================
//
// リザルト　　　result.cpp
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#include "result.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include "camera.h"
#include "fontString.h"
#include "objectX.h"
#include "halfsphere.h"
#include "char_select.h"
#include "confirmation_window.h"
#include "game.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CResult::CResult()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CResult::~CResult()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CResult::Init()
{
	// カメラのポインタ
	CCamera* pCamera = CApplication::GetCamera();
	m_Index = CApplication::GetPlayerJobIndex();

	pCamera->SetPosV({ 0.0f, 100.0f, -100.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 100.0f });

	// ハーフスフィアの生成
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, -1000.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	//CFontString::Create({ 490.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "リザルト");

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CResult::Uninit()
{
}

//==============================================================================================
//更新処理
//==============================================================================================
void CResult::Update()
{
	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
		}
	}

		if (m_Index == 0)
		{
			CObjectX::Create(D3DXVECTOR3(0.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
		}
		if (m_Index == 1)
		{
			CObjectX::Create(D3DXVECTOR3(0.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_01.x");
		}
		if (m_Index == 2)
		{
			CObjectX::Create(D3DXVECTOR3(0.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_02.x");
		}
		if (m_Index == 3)
		{
			CObjectX::Create(D3DXVECTOR3(0.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_03.x");
		}
}

//==============================================================================================
// 生成処理
//==============================================================================================
CResult* CResult::Create()
{
	CResult* pResult = new CResult;

	if (FAILED(pResult->Init()))
	{
		return nullptr;
	}

	return pResult;
}
