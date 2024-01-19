//=============================================================================
//
// game.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "manager.h"
#include "game.h"
#include "input.h"
#include "texture.h"
#include "camera.h"
#include "light.h"
#include "meshfield.h"
#include "player.h"
#include "billboard.h"
#include "tps_camera.h"
#include "read.h"
#include "ballast_manager.h"
#include <assert.h>

//*****************************************************************************
// コンストラクタ
//*****************************************************************************
CGame::CGame()
{
}

//*****************************************************************************
// デストラクタ
//*****************************************************************************
CGame::~CGame()
{
}

//*****************************************************************************
// 初期化
//*****************************************************************************
HRESULT CGame::Init()
{
	//カメラ
	m_pCamera = new CTpsCamera;
	if (FAILED(m_pCamera->Init()))
	{
		return -1;
	}

	//ライト
	m_pLight = new CLight;
	if (FAILED(m_pLight->Init()))
	{
		return -1;
	}

	
	CRead cRead;

	m_pPlayer = new CPlayer;
	if (FAILED(m_pPlayer->Init()))
	{
		return -1;
	}
	
	//BG3D
	m_pMeshfieldBG = cRead.ReadMap("Data/MAPTXT/map.txt");
	return S_OK;
}

//*****************************************************************************
// 終了処理
//*****************************************************************************
void CGame::Uninit()
{
	//カメラ
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}
	//ライト
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	//瓦礫マネージャー
	if (m_pBallastManager != nullptr)
	{
		m_pBallastManager->Uninit();
		delete m_pBallastManager;
		m_pBallastManager = nullptr;
	}

	//メッシュフィールド
	if (m_pMeshfieldBG != nullptr)
	{
		m_pMeshfieldBG->Uninit();
		delete m_pMeshfieldBG;
		m_pMeshfieldBG = nullptr;
	}

	//Player
	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Uninit();
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}

	C3DObject::UninitAllModel();
}

//*****************************************************************************
// 更新処理
//*****************************************************************************
void CGame::Update()
{
	m_pCamera->Update();
	m_pPlayer->Update();
	m_pBallastManager->Update();
	CInput *pInput = CInput::GetKey();
}

//*****************************************************************************
// 描画処理
//*****************************************************************************
void CGame::Draw()
{
	//カメラ
	m_pCamera->SetCamera();

	m_pMeshfieldBG->Draw();

	m_pBallastManager->Draw();

	m_pPlayer->Draw();

}

//*****************************************************************************
// 瓦礫マネージャーの生成処理
//*****************************************************************************
void CGame::CreateBallastManager(CMeshfield * pMeshfield)
{
	//瓦礫マネージャーの生成処理
	m_pBallastManager = new CBallast_Manager;

	//初期化
	if (FAILED(m_pBallastManager->Init()))
	{
		assert(false);
	}

	//メッシュフィールドの情報から必要な数値の取得
	m_pBallastManager->MeshfieldSet(pMeshfield);

}
