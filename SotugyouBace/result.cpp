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
#include "menu.h"
#include "title_menu.h"
#include "player_manager.h"
#include "player_parameter.h"
#include "weapon_parameter.h"
#include "score.h"
#include "pause.h"
#include "parts.h"
#include "time.h"

//==============================================================================================
// 静的メンバ変数宣言
//==============================================================================================
CPlayer_Parameter* CResult::m_pPlayerParameter = nullptr;
CPlayerManager* CResult::m_pPlayerManager = nullptr;

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

	//=======================================================
	// メンバ変数の初期化
	//=======================================================
	m_move = D3DXVECTOR3(4.25, 0.1f, 6.25f);
	m_pos = D3DXVECTOR3(-200.0f, 250.0f, 525.0f);
	m_bGetFlag = false;
	m_bCreateFlag = false;
	m_MoveCount = 120;
	m_PlayerIndex = 0;

	// カメラのポインタ
	CCamera* pCamera = CApplication::GetCamera();
	pCamera->SetPosV({ 0.0f, 4.0f,-3.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 3.0f });

	// プレイヤー番号の取得
	m_Index = CApplication::GetPlayerJobIndex();

	// 全てのモデルパーツの読み込み
	CApplication::GetPartsFile()->LoadAllFile();

	// 全てのモデルパーツの読み込み
	CApplication::GetMotion()->LoadAllFile();

	// プレイヤーパラメーターの生成
	m_pPlayerParameter = new CPlayer_Parameter;
	m_pPlayerParameter->Init();

	// 武器パラメーターの生成
	m_pWeaponParameter = new CWeapon_Parameter;
	m_pWeaponParameter->Init();

	// プレイヤーマネージャーの生成
	m_pPlayerManager = CPlayerManager::Create();	

	// プレイヤーの生成(テスト)
	m_pPlayerManager->SetPlayer({ m_pos.x, m_pos.y, m_pos.z }, CPlayerManager::TYPE_PC, m_PlayerIndex, 0);

	// ハーフスフィアの生成
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, -1000.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CResult::Uninit()
{
	// プレイヤーパラメーターの破棄
	if (m_pPlayerParameter != nullptr)
	{
		m_pPlayerParameter->Uninit();
		delete m_pPlayerParameter;
		m_pPlayerParameter = nullptr;
	}

	// 武器パラメーターの破棄
	if (m_pWeaponParameter != nullptr)
	{
		m_pWeaponParameter->Uninit();
		delete m_pWeaponParameter;
		m_pWeaponParameter = nullptr;
	}

	// プレイヤーマネージャーの破棄
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}

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
void CResult::Update()
{
	// インプットの取得処理
	CInput* pInput = CInput::GetKey();

	// スキルの種類
	//SkillType();

	if (m_PlayerIndex <= 0)// ココの値を変えれば人数を増やしたり減らしたりできる
	{
		// プレイヤー情報の取得
		if (m_pPlayerManager != nullptr && m_bGetFlag == false)
		{
			// 位置の取得
			m_pos = m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetPos();

			for (int nCnt = 0; nCnt < 3; nCnt++)
			{
				// パーツの取得と向きの設定
				m_pParts[nCnt] = m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetParts(nCnt);
				m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetParts(nCnt)->SetRot(D3DXVECTOR3(0.0f, -D3DX_PI / 3.75f, 0.0f));
			}

			// 取得完了
			m_bGetFlag = true;
		}

		// 移動時間の減算
		m_MoveCount--;
		if (m_MoveCount >= 0)
		{
			// 移動
			m_pos.x += m_move.x;
			m_pos.z -= m_move.z;

			// 歩きモーション
			for (int nCnt = 0; nCnt < 3; nCnt++)
			{
				m_pParts[nCnt]->SetMotion(CPlayer::MOTION_WALK);
			}

		}
		else if (m_MoveCount <= 0 && m_pObject2D == nullptr && m_pPlayerManager != nullptr)
		{
			m_pObject2D = CObject2D::Create(D3DXVECTOR3(400.0f, 360.0f, 0.0f), D3DXVECTOR2(m_size.x, m_size.y), CObject::PRIORITY_BACK_GROUND);
			m_pObject2D->SetCol(D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));

			// 歩きを終了させる
			for (int nCnt = 0; nCnt < 3; nCnt++)
			{
				m_pParts[nCnt]->SetMotion(CPlayer::MOTION_NEUTRAL);
				m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetParts(nCnt)->SetRot(D3DXVECTOR3(0.0f, 0.25f, 0.0f));
			}
		}

		ScaleExpansion();
		if (m_pPlayerManager != nullptr)
		{
			m_pPlayerManager->GetPlayer(m_PlayerIndex)->SetPos(m_pos);
		}

		if (pInput->Trigger(DIK_RETURN) && m_bCreateFlag == true)
		{
			m_PlayerIndex++;
			// プレイヤー情報の削除
			if (m_PlayerIndex <= 3)
			{
				InformationUninit();
			}

			if (m_pPlayerManager == nullptr && m_PlayerIndex <= 0)// ココの値を変えれば人数を増やしたり減らしたりできる)
			{
				// プレイヤーマネージャーの生成
				m_pPlayerManager = CPlayerManager::Create();
				m_pPlayerManager->SetPlayer({ -200.0f, 250.0f, 525.0f }, CPlayerManager::TYPE_PC, m_PlayerIndex, 0);
			}
		}
	}
	if (m_PlayerIndex >= 1)// ココの値を変えれば人数を増やしたり減らしたりできる
	{
		// タイトル画面に遷移
		for (int nCnt = 0; nCnt < 4; nCnt++)
		{
			if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
				|| pInput->Trigger(JOYPAD_START, nCnt))
				&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
			{
				CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
			}
		}
	}
}

//=============================================================================
// サイズ拡大処理
//=============================================================================
void CResult::ScaleExpansion()
{
	if (m_pObject2D != nullptr)
	{ // nullチェック

	  // サイズの拡大
		m_size.x += SizeXScaleSpeed;
		m_size.y += SizeYScaleSpeed;

		if (m_size.x >= 700.0f)
		{ // Xサイズの最大
			m_size.x = 700.0f;
		}
		if (m_size.y >= 500.0f)
		{ // Yサイズの最大
			m_size.y = 500.0f;
		}

		if (m_size.x >= 700.0f && m_size.y >= 500.0f && m_bCreateFlag == false)
		{

			// タイムの生成
			m_pTime = CTime::Create(D3DXVECTOR3(540.0f, 150.0f, 0.0f));

			// タイマーの更新
			if (m_pTime != nullptr)
			{
				m_pTime->SetTime(CApplication::GetDestroyTime());
			}

			m_pScore = CScore::Create(D3DXVECTOR3(100.0f, 500.0f, 0.0f));
			m_pFont[0] = CFontString::Create({ 100.0f, 150.0f, 0.0f }, { 35.0f, 35.0f }, "さいたんげきは");
			m_pFont[1] = CFontString::Create({ 100.0f, 250.0f, 0.0f }, { 35.0f, 35.0f }, "ひだめりつ");
			m_pFont[2] = CFontString::Create({ 100.0f, 350.0f, 0.0f }, { 35.0f, 35.0f }, "たおしたてきのかず");
			m_bCreateFlag = true;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(m_size.x, m_size.y));
	}
}

//==============================================================================================
// 情報の破棄処理
//==============================================================================================
void CResult::InformationUninit()
{
	// プレイヤーマネージャーの破棄
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}

	// オブジェクト2Dの破棄
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}

	// フォントの破棄
	for (int nCnt = 0; nCnt < 3; nCnt++)
	{
		if (m_pFont[nCnt] != nullptr)
		{
			m_pFont[nCnt]->Uninit();
			m_pFont[nCnt] = nullptr;
		}
	}

	// スコアの破棄
	if (m_pScore != nullptr)
	{
		m_pScore->Uninit();
		m_pScore = nullptr;
	}

	m_bGetFlag = false;
	m_bCreateFlag = false;
	m_MoveCount = 120;
}

//==============================================================================================
// スキルの種類処理
//==============================================================================================
void CResult::SkillType()
{
	/*if (m_pObjectX == nullptr)
	{
		if (CApplication::GetSkillType() == true)
		{
			if (m_Index == 0)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
			}
			if (m_Index == 1)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_01.x");
			}
			if (m_Index == 2)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_02.x");
			}
			if (m_Index == 3)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_03.x");
			}
		}
		else
		{
			if (m_Index == 0)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_04.x");
			}
			if (m_Index == 1)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_05.x");
			}
			if (m_Index == 2)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_06.x");
			}
			if (m_Index == 3)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_07.x");
			}
		}
	}*/
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
