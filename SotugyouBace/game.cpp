//==============================================================================================
//
// ゲーム　　　game.cpp
// tutida ryousei
//
//==============================================================================================
#include "game.h"
#include "application.h"
#include "camera.h"
#include "fade.h"
#include "input.h"
#include "fontString.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "boss.h"
#include "score.h"
#include "time.h"
#include "halfsphere.h"
#include"meshfield.h"
#include"collision.h"
#include"energy_gauge.h"

CMeshField *CGame::pMeshField = nullptr;
CCharacter *CGame::pBoss = nullptr;
CEnergy_Gauge *CGame::m_pEnergy_Gauge = nullptr;

//==============================================================================================
// 静的メンバ変数宣言
//==============================================================================================

//==============================================================================================
// コンストラクタ
//==============================================================================================
CGame::CGame()
{
	
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CGame::~CGame()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CGame::Init()
{
	// カメラのポインタ
	CCamera* pCamera = CApplication::GetCamera();

	// 視点、注視点の設定
	pCamera->SetPosV({ 0.0f, 500.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 1000.0f });

	//CFontString::Create({ 515.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "ゲーム");
	CFontString::Create({ SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT / 2 - 200.0f, 0.0f }, { 50.0f, 50.0f }, "ジャンプながおし");
	
	// プレイヤーの生成(テスト)
	CApplication::GetPlayerManager()->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0);

	// ボスキャラの生成
	pBoss = CBoss::Create({ 0.0f, 0.0f, 300.0f });

	// スコアの生成
	m_pScore = CScore::Create();

	// タイムの生成
	m_pTime = CTime::Create();

	// ハーフスフィアの生成
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	// メッシュフィールドの生成
	pMeshField = CMeshField::Create({ 0.0f, 0.0f,0.0f }, 20, 20, 300.0f);

	// エネルギーゲージ
	m_pEnergy_Gauge = CEnergy_Gauge::Create({ SCREEN_WIDTH / 2, 650.0f, 0.0f }, { 800.0f, 10.0f });

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CGame::Uninit()
{
	// タイマーの終了処理
	if (m_pTime != nullptr)
	{
		m_pTime->Uninit();
		delete m_pTime;
		m_pTime = nullptr;
	}
}

//==============================================================================================
//更新処理
//==============================================================================================
void CGame::Update()
{
	// タイマーの更新
	if (m_pTime != nullptr)
		m_pTime->Update();

	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			CFade::SetFade(CApplication::MODE_RESULT, 0.05f);
		}
	}
	// デバッグ専用コマンド
#ifdef _DEBUG
	// 左Shiftキーを押したままの場合
	if (pInput->Press(DIK_LSHIFT))
	{
		int nKey = -1;
		if (pInput->Trigger(DIK_1))
		{
			nKey = 0;
		}
		if (pInput->Trigger(DIK_2))
		{
			nKey = 1;
		}
		if (pInput->Trigger(DIK_3))
		{
			nKey = 2;
		}
		if (pInput->Trigger(DIK_4))
		{
			nKey = 3;
		}

		if (nKey >= 0)
		{
			CPlayerManager* pPlayerManager = CApplication::GetPlayerManager();
			CPlayer* pPlayer = pPlayerManager->GetPlayer(nKey);

			if (pPlayer == nullptr)
			{
				// プレイヤーの生成
				pPlayerManager->SetPlayer({ -300.0f + (200.0f * nKey), 0.0f, 0.0f }, CPlayerManager::TYPE_PC, nKey);
			}
			else
			{
				// 50ダメージ
				pPlayer->Damage(50);
			}
		}
	}
	// LShiftキー無しの場合
	else
	{
		// スコアの加算
		if (pInput->Press(DIK_L))
		{
			m_pScore->AddScore(10);
		}

		// スコアの加算
		if (pInput->Trigger(DIK_0))
		{
			for (auto pEnemy : CApplication::GetEnemyManager()->GetAllEnemy())
			{
				// 50ダメージ
				pEnemy->Damage(50);
			}
		}
	}

#endif
}

//==============================================================================================
// 生成処理
//==============================================================================================
CGame* CGame::Create()
{
	CGame* pGame = new CGame;

	if (FAILED(pGame->Init()))
	{
		return nullptr;
	}

	return pGame;
}