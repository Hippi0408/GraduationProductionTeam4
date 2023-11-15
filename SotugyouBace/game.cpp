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
#include "mob.h"
#include "boss.h"
#include "score.h"
#include "time.h"
#include "halfsphere.h"
#include"meshfield.h"
#include"collision.h"
#include "locus.h"
#include "object2D.h"
#include "confirmation_window.h"
#include "menu.h"
#include "utility.h"
#include "parts.h"
#include "drop_weapon.h"
#include "player_ui.h"
#include"debugProc.h"
#include"pause.h"
#include "parts_file.h"

CMeshField *CGame::m_pMeshField = nullptr;
bool CGame::m_bGameEnd = false;
bool CGame::m_bGameWindow = false;
CFontString* CGame::m_pFinishRogo = nullptr;
CPlayerManager* CGame::m_pPlayer_Manager = nullptr;
CPause *CGame::m_pPause = nullptr;

//==============================================================================================
// 静的メンバ変数宣言
//==============================================================================================
CConfirmation_Window* CGame::m_pConfirmationWindow = nullptr;

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
	pCamera->SetPosV({ 0.0f, 225.0f, -450.0f });
	pCamera->SetPosR({ 0.0f, 112.5f, 450.0f });

	// 全てのモデルパーツの読み込み
	CApplication::GetPartsFile()->LoadAllFile();

	// プレイヤーの生成(テスト)
	m_pPlayer_Manager = CApplication::GetPlayerManager();
	m_pPlayer_Manager->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0);

	for (int nCnt = 0; nCnt < 20; nCnt++)
	{
		// モブキャラの生成
		CMob::Create({ utility::Random<float>(5000.0f, -5000.0f), utility::Random<float>(600.0f, -200.0f), utility::Random<float>(15000.0f, -500.0f) });
	}

	// ボスキャラの生成
	CBoss::Create({ 0.0f, 0.0f, 10000.0f });

	// 武器、パーツのドロップ
	SetDrop_Parts(20, { 0.0f,0.0f,0.0f }, true);

	// タイムの生成
	m_pTime = CTime::Create();

	// ハーフスフィアの生成
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(20000.0f, 20000.0f, 20000.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	// メッシュフィールドの生成
	m_pMeshField = CMeshField::Create({ 0.0f, 0.0f, 0.0f }, 10, 10, 4000.0f);

	// プレイヤーUIの生成
	m_pPlayerUI = CPlayerUi::Create(D3DXVECTOR3(1200.0f, 50.0f, 0.0f), D3DXVECTOR2(100.0f, 75.0f),CPlayerUi::UITYPE_ONE,CObject::PRIORITY_CENTER);
	m_pPlayerUI = CPlayerUi::Create(D3DXVECTOR3(100.0f, 50.0f, 0.0f), D3DXVECTOR2(100.0f, 75.0f), CPlayerUi::UITYPE_TWO, CObject::PRIORITY_CENTER);
	m_pPlayerUI = CPlayerUi::Create(D3DXVECTOR3(1200.0f, 660.0f, 0.0f), D3DXVECTOR2(100.0f, 85.0f), CPlayerUi::UITYPE_THREE, CObject::PRIORITY_CENTER);

	// ポーズ画面
	m_pPause = CPause::Create();

	m_nEndCounter = 0;

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

	// 終了ロゴの終了
	if (m_pFinishRogo != nullptr)
	{
		m_pFinishRogo->Uninit();
		m_pFinishRogo = nullptr;
	}

	// メニューウィンドウの終了処理
	if (m_pConfirmationWindow != nullptr)
	{
		m_pConfirmationWindow->Uninit();
		delete m_pConfirmationWindow;
		m_pConfirmationWindow = nullptr;
	}

	m_bGameEnd = false;	// ゲーム終了判定を偽にする
}

//==============================================================================================
//更新処理
//==============================================================================================
void CGame::Update()
{
	// メニューウィンドウ処理
	MenuWindow();

	// ゲーム終了判定が真の場合
	if (m_bGameEnd == true)
	{
		GameEnd();	// ゲーム終了処理
	}
	else
	{
		// タイマーの更新
		if (m_pTime != nullptr)
			m_pTime->Update();

		// デバッグ専用コマンド
#ifdef _DEBUG
		CInput* pInput = CInput::GetKey();
		if (pInput->Trigger(DIK_F5))
		{
			CFade::SetFade(CApplication::MODE_RESULT, 0.05f);
		}
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
					pPlayer->Damage(10);
				}
			}
		}
		// LShiftキー無しの場合
		else
		{
			// パーツ変更処理
			if (pInput->Press(DIK_C))
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
				if (pInput->Trigger(DIK_5))
				{
					nKey = 4;
				}
				if (pInput->Trigger(DIK_6))
				{
					nKey = 5;
				}

				if (nKey >= 0)
				{
					CPlayer* pPlayer = CApplication::GetPlayerManager()->GetPlayer(0);
					pPlayer->GetParts(CPlayer::PARTS_BODY)->SetParts(CParts_File::PARTS_PLAYER_BODY_1 + nKey);
				}
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
}

//==============================================================================================
// ゲーム終了処理
//==============================================================================================
void CGame::GameEnd()
{
	// ゲームが終了するまでカウント
	if (m_nEndCounter < MAX_END_TIMER)
	{
		// 終了ロゴを生成する
		if ((m_nEndCounter == MAX_FINISH_ROGO) && (m_pFinishRogo == nullptr))
		{
			m_pFinishRogo = CFontString::Create({ SCREEN_WIDTH / 2 - 360, SCREEN_HEIGHT / 2, 0.0f }, { 100.0f, 100.0f }, "げきはァ!");
			m_pFinishRogo->SetColor({ 1.0f, 0.0f, 0.0f, 1.0f });
		}
		m_nEndCounter++;
	}
	// ゲームを終了させる
	else
	{
		// 終了ロゴの終了
		if (m_pFinishRogo != nullptr)
		{
			m_pFinishRogo->Uninit();
			m_pFinishRogo = nullptr;
		}

		// リザルトへ飛ぶ
		CFade::SetFade(CApplication::MODE_RESULT, 0.05f);
	}
}

//==============================================================================================
// メニューウィンドウ処理
//==============================================================================================
void CGame::MenuWindow()
{
	CInput* pInput = CInput::GetKey();
	if (m_pConfirmationWindow == nullptr)
	{
		if (pInput->Trigger(DIK_M))
		{
			m_pConfirmationWindow = CConfirmation_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f),500.0f, 320.0f, D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f));
			return;
		}
	}
	else
	{
		m_pConfirmationWindow->Update();
	}
	// ウィンドウが閉じた場合 
	if (m_pConfirmationWindow != nullptr && m_pConfirmationWindow->GetSapawnWindow() == true)
	{
		m_pConfirmationWindow->SetSapawnWindow(false);
		delete m_pConfirmationWindow;
		m_pConfirmationWindow = nullptr;
	}
}

//==============================================================================================
// 武器、パーツのドロップ
//==============================================================================================
void CGame::SetDrop_Parts(int num, D3DXVECTOR3 pos, bool rand)
{
	for (int nCnt = 0; nCnt < num; nCnt++)
	{
		D3DXVECTOR3 Pos = pos;
		if (rand)
			// ランダムな位置
			Pos = { utility::Random<float>(5000.0f, -5000.0f), utility::Random<float>(600.0f, -200.0f), utility::Random<float>(15000.0f, -500.0f) };

		// タイプの設定
		int nRandType = 0;

		// タイプ
		nRandType = utility::Random<int>(CDrop_Weapon::DROP_PARTS_MAX, 0);

		while (CDrop_Weapon::WEAPON_MAX == nRandType || CDrop_Weapon::BODY_MAX == nRandType
			|| CDrop_Weapon::HIP_MAX == nRandType || CDrop_Weapon::HEAD_MAX == nRandType
			|| CDrop_Weapon::RIGHT_UPPER_ARM_MAX == nRandType || CDrop_Weapon::RIGHT_FOREARM_MAX == nRandType
			|| CDrop_Weapon::RIGHT_ARM_MAX == nRandType || CDrop_Weapon::LEFT_UPPER_ARM_MAX == nRandType
			|| CDrop_Weapon::LEFT_FOREARM_MAX == nRandType || CDrop_Weapon::LEFT_ARM_MAX == nRandType
			|| CDrop_Weapon::RIGHT_THIGH_MAX == nRandType || CDrop_Weapon::RIGHT_SHIN_MAX == nRandType
			|| CDrop_Weapon::RIGHT_LEG_MAX == nRandType || CDrop_Weapon::LEFT_THIGH_MAX == nRandType
			|| CDrop_Weapon::LEFT_SHIN_MAX == nRandType || CDrop_Weapon::LEFT_LEG_MAX == nRandType)
		{
			// タイプ
			nRandType = utility::Random<int>(CDrop_Weapon::DROP_PARTS_MAX, 0);
		}

		// 生成
		CDrop_Weapon::Creat(Pos, nRandType);
	}
}

//==============================================================================================
// ゲーム終了処理
//==============================================================================================
void CGame::SetGameEnd()
{
	// ゲーム終了判定を真にする
	m_bGameEnd = true;
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