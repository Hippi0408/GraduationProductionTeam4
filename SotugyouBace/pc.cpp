//=============================================================================
//
// pc.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "pc.h"
#include "application.h"
#include "input.h"
#include "camera.h"
#include "game.h"
#include "meshfield.h"
#include "energy_gauge.h"
#include "tutorial.h"
#include "locus.h"
#include "player_life_gauge.h"
#include "pause.h"

#include"player_manager.h"
#include"debugProc.h"

//=====================================
// デフォルトコンストラクタ
//=====================================
CPC::CPC()
{

}

//=====================================
// デストラクタ
//=====================================
CPC::~CPC()
{

}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CPC::Init()
{
	CPlayer::Init();
	m_bFlag = false;

	SetEnergyGauge(CEnergy_Gauge::Create({ 70,720.0f / 2,0.0f }, { 20.0f,500.0f }));
	SetGaugeManager(CPlayer_Life_Gauge::Create({ 1210.0f,720.0f / 2,0.0f }, { 20.0f,500.0f }));

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CPC::Uninit()
{
	CPlayer::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CPC::Update()
{
	// 入力処理
	Input();

	CPlayer::Update();
}

//============================================================================
// 描画処理
//============================================================================
void CPC::Draw()
{
	CPlayer::Draw();
}

//==============================================================================================
// 入力処理
//==============================================================================================
void CPC::Input()
{
	//入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	// 自身の番号
	//const int nIndex = GetCharaIndex();

	// カメラの角度
	D3DXVECTOR3 rotCamera = CApplication::GetCamera()->GetRot();

	// 移動量
	D3DXVECTOR3 move = GetMove();

	// エネルギーゲージの取得
	CEnergy_Gauge* pGauge = nullptr;
	pGauge = GetEnergy_Gauge();

	D3DXVECTOR3 boostMove = { 1.0f,1.0f,1.0f };

	// ブースト中は移動速度が上がる
	if (GetBoost())
		boostMove *= 3.0f;

	// 目的の角度
	D3DXVECTOR3 rotDest = GetRotDest();

	// 脚パーツ
	CParts* pLeg = GetParts(PARTS_LEG);

	// 歩き判定
	bool bWalk = false;

	// 歩いている場合
	if (pInput->MovePress(GAME_MOVE_ALL))
	{
		// 回転させる
		Rotation();

		// 歩き判定を真にする
		bWalk = true;
	}

		// 歩いている場合
	if (bWalk == true && !GetAvoidance())
	{
		//カメラの向き（Y軸のみ）
		float rotY = rotCamera.y;

		//視点移動
		if (pInput->MovePress(GAME_MOVE_UP))
		{//上キーが押された
			if (pInput->MovePress(GAME_MOVE_LEFT))
			{
				rotDest.y = rotCamera.y + D3DX_PI * 0.75f;
				move.x = -sinf(rotY + D3DX_PI * 0.75f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * 0.75f) * boostMove.z;
			}
			else if (pInput->MovePress(GAME_MOVE_RIGHT))
			{
				rotDest.y = rotCamera.y + D3DX_PI * -0.75f;
				move.x = -sinf(rotY + D3DX_PI * -0.75f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * -0.75f) * boostMove.z;
			}
			else
			{
				rotDest.y = rotCamera.y + D3DX_PI;
				move.x = sinf(rotY) * boostMove.x;
				move.z = cosf(rotY) * boostMove.z;
			}
		}

		else if (pInput->MovePress(GAME_MOVE_DOWN))
		{//下キーが押された
			if (pInput->MovePress(GAME_MOVE_LEFT))
			{
				rotDest.y = rotCamera.y + D3DX_PI * 0.25f;
				move.x = -sinf(rotY + D3DX_PI * 0.25f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * 0.25f) * boostMove.z;
			}
			else if (pInput->MovePress(GAME_MOVE_RIGHT))
			{
				rotDest.y = rotCamera.y + D3DX_PI * -0.25f;
				move.x = -sinf(rotY + D3DX_PI * -0.25f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * -0.25f) * boostMove.z;
			}
			else
			{
				rotDest.y = rotCamera.y;
				move.x = sinf(rotY + D3DX_PI) * boostMove.x;
				move.z = cosf(rotY + D3DX_PI) * boostMove.z;
			}
		}
		else if (pInput->MovePress(GAME_MOVE_LEFT))
		{//左キーが押された
			rotDest.y = rotCamera.y + D3DX_PI * 0.5f;
			move.x = sinf(rotY + D3DX_PI * -0.5f) * boostMove.x;
			move.z = cosf(rotY + D3DX_PI * -0.5f) * boostMove.z;
		}
		else if (pInput->MovePress(GAME_MOVE_RIGHT))
		{//右キーが押された
			rotDest.y = rotCamera.y + D3DX_PI * -0.5f;
			move.x = sinf(rotY + D3DX_PI * 0.5f) * boostMove.x;
			move.z = cosf(rotY + D3DX_PI * 0.5f) * boostMove.z;
		}

		// 接地している場合に歩きモーション
		if (GetGround())
		{
			// 歩き
			pLeg->SetMotion(MOTION_WALK);
		}
		// 回避
		if (pInput->Trigger(MOUSE_INPUT_RIGHT)
			&& !pGauge->GetConsumption())
		{
			// 歩き
			GetParts(PARTS_LEG)->SetMotion(MOTION_WALK);
			SetAvoidanceCount(20);				// 回避の硬直
			pGauge->SetAvoidance_amount(200.0f);// 回避時のエネルギー消費量
			pGauge->Avoidance_Energy();			// エネルギー消費
			pGauge->Recovery_Pause(50);			// クールタイム
			SetAvoidance(true);

			// ブーストした分の速度を減らす
			if (GetBoost())
				move /= boostMove.x;

			move *= 7.0f;		// 初速
			move.y = 0.0f;
		}
	}
	// 前回モーションが歩きモーションだった場合
	else if (pLeg->GetCurrentMotion() != MOTION_LANDING && GetGround())
	{
		// 歩きを終了させる
		pLeg->SetMotion(MOTION_NEUTRAL);
	}

	// ダッシュブーストの初期化
	SetBoost(false);

	// 移動量を更新
	CCharacter::SetMove(move);
	// 目的の角度の設定
	CCharacter::SetRotDest(rotDest);

	if (pInput->Trigger(DIK_F))
	{
		CMeshField *pMeshField = nullptr;

		if (CApplication::GetModeType() == CApplication::MODE_GAME)
			pMeshField = CGame::GetMeshField();
		else if (CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
			pMeshField = CTutorial::GetMeshField();

		if (pMeshField != nullptr)
			pMeshField->Ground_Broken(CCharacter::GetPos(), 30.0f, 10);
	}
	// ジャンプ処理
	if ((pInput->Press(DIK_SPACE)) || pInput->Press(JOYPAD_A))
	{
		// ジャンプ入力時間の加算
		AddJump_PressCount(1);

		if (GetJump_PressCount() < 20)
			// プレイヤーのジャンプ処理
			JumpStart();
		else
			SetJump_Boost(true);
	}
	else
		SetJump_Boost(false);

	if (GetGround())
		// ジャンプ入力時間のリセット
		SetJump_PressCount(0);

	// 攻撃処理
	if ((pInput->Trigger(DIK_B)) || pInput->Trigger(JOYPAD_R2) || pInput->Trigger(MOUSE_INPUT_LEFT))
	{
		// プレイヤーの攻撃処理
		PlayerAttack();
	}

	CPause *pPause = nullptr;

	// ポーズの取得
	if (CApplication::GetModeType() == CApplication::MODE_GAME)
		pPause = CGame::GetPause();
	else if (CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
		pPause = CTutorial::GetPause();

	// ポーズしてないとき
	if (!pPause->GetPause())
	{
		// 視点処理
		Perspective();
	}

	if (pGauge != nullptr)
	{
		// 地上にいる場合
		if (GetGround())
		{
			// 消費速度
			pGauge->SetConsumption_Speed(1.5f);
			// 回復速度
			pGauge->SetRecovery_Speed(10.0f);
		}
		// 空中にいる場合
		else
		{
			// 消費速度
			pGauge->SetConsumption_Speed(3.0f);
			// 回復速度
			pGauge->SetRecovery_Speed(0.3f);
		}

		// エネルギーが残っている状態
		if (!pGauge->GetConsumption())
		{
			if (GetJump_Boost())
				// ジャンプブースト
				JumpBoost();

			if ((pInput->Press(DIK_LSHIFT)) && bWalk)
			{
				// ブーストする
				SetBoost(true);

				// エネルギーを消費する
				pGauge->Consumption_Gauge();
				pLeg->SetMotion(MOTION_BOOST_RUN);
			}
		}
	}
}

//============================================================================
// 視点の向きの処理
//============================================================================
void CPC::Perspective()
{
	//入力デバイスの情報
	CInput* pInput = CInput::GetKey();
	// カメラの角度
	D3DXVECTOR3 rotCamera = CApplication::GetCamera()->GetRot();

	if (pInput->Press(DIK_UP) || pInput->StickPress(JOYKEY_CROSS_UP, 0, true))
	{	//UPキーを押しているとき
		rotCamera.x -= 0.015f;		//カメラの上方向の加算
		if (rotCamera.x <= -0.5f)
		{
			rotCamera.x = -0.5f;
		}

	}
	if (pInput->Press(DIK_DOWN) || pInput->StickPress(JOYKEY_CROSS_DOWN, 0, true))
	{	//DOWNキーを押しているとき
		rotCamera.x += 0.015f;		//カメラの上方向の加算
		if (rotCamera.x >= 0.5f)
		{
			rotCamera.x = 0.5f;
		}
	}

	if (pInput->Press(DIK_LEFT) || pInput->StickPress(JOYKEY_CROSS_LEFT, 0, true))
	{	//LEFTキーを押しているとき
		rotCamera.y -= 0.015f;		//カメラの上方向の加算
	}

	if (pInput->Press(DIK_RIGHT) || pInput->StickPress(JOYKEY_CROSS_RIGHT, 0, true))
	{	//LEFTキーを押しているとき
		rotCamera.y += 0.015f;		//カメラの上方向の加算
	}

	// 視点切り替え
	if (pInput->Trigger(DIK_P) && m_bFlag == false)
	{
		CApplication::GetCamera()->SetPerspective(true);
		m_bFlag = true;
	}
	else if(pInput->Trigger(DIK_P) && m_bFlag == true)
	{
		CApplication::GetCamera()->SetPerspective(false);
		m_bFlag = false;
	}

	D3DXVECTOR3 MouseMove;
	D3DXVECTOR3 rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	MouseMove = pInput->GetMouseMove();

	MouseMove = D3DXVECTOR3(MouseMove.y, MouseMove.x, 0.0f);

	if (D3DXVec3Length(&MouseMove) > 0.25f)
	{
		D3DXVec3Normalize(&MouseMove, &MouseMove);

		rot = MouseMove * (D3DX_PI / 180.0f);

		rot.x *= 3.0f;
		rot.y *= 2.0f;
	}

	rotCamera += rot;

	if (rotCamera.x  > D3DXToRadian(80))
	{
		rotCamera.x = D3DXToRadian(80);
	}
	else if (rotCamera.x  < D3DXToRadian(-50))
	{
		rotCamera.x = D3DXToRadian(-50);
	}

	rot = rotCamera;

	if (rot.x > D3DX_PI)
	{
		rot.x -= D3DX_PI * 2.0f;
	}
	else if (rot.x < -D3DX_PI)
	{
		rot.x += D3DX_PI * 2.0f;
	}

	if (rot.y > D3DX_PI)
	{
		rot.y -= D3DX_PI * 2.0f;
	}
	else if (rot.y < -D3DX_PI)
	{
		rot.y += D3DX_PI * 2.0f;
	}

	if (rot.z > D3DX_PI)
	{
		rot.z -= D3DX_PI * 2.0f;
	}
	else if (rot.z < -D3DX_PI)
	{
		rot.z += D3DX_PI * 2.0f;
	}

	rotCamera.y = rot.y;
	rotCamera.x = rot.x;

	//カメラの向きの設定
	CApplication::GetCamera()->SetRot(rotCamera);

	if (pInput->Trigger(DIK_0))
	{
		CLocus::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), 100.0f, 5, CObject::PRIORITY_CENTER, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}
}

//============================================================================
// 生成処理
//============================================================================
CPC* CPC::Create(const D3DXVECTOR3 pos, const int index)
{
	CPC* pPC = new CPC;

	if (FAILED(pPC->Init()))
	{
		return nullptr;
	}

	pPC->SetPos(pos);
	pPC->SetCharaIndex(index);

	return pPC;
}
