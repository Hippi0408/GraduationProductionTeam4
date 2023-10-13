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
	// モーション番号の設定
	ChangeMotion();

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
	const int nIndex = GetCharaIndex();

	// カメラの角度
	const D3DXVECTOR3 rotCamera = CApplication::GetCamera()->GetRot();

	// 移動量
	D3DXVECTOR3 move = GetMove();

	D3DXVECTOR3 boostMove = { 1.0f,1.0f,1.0f };

	// ブースト中は移動速度が上がる
	if (GetBoost())
		boostMove *= 1.8f;

	SetBoost(false);

	// 目的の角度
	D3DXVECTOR3 rotDest = GetRotDest();

	// 歩き判定
	bool bWalk = false;

	if (pInput->StickPress(JOYKEY_CROSS_UP) || 
		pInput->StickPress(JOYKEY_CROSS_DOWN) || 
		pInput->StickPress(JOYKEY_CROSS_RIGHT) || 
		pInput->StickPress(JOYKEY_CROSS_LEFT))
	{
		// 回転させる
		Rotation();

		bWalk = true;
	}

	// 歩いている場合
	if (bWalk == true)
	{
		// プレイヤーの移動
		//if ((pInput->Press(DIK_W) && nIndex == 0) || pInput->Press(JOYPAD_UP, nIndex))
		//{
		//	if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		//	{// 左前
		//		rotDest.y = rotCamera.y + D3DX_PI * 3 / 4;
		//		move.x = -sinf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.x;
		//		move.z = -cosf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.z;
		//	}
		//	else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		//	{// 右前
		//		rotDest.y = rotCamera.y - D3DX_PI * 3 / 4;
		//		move.x = sinf(rotCamera.y + D3DX_PI / 4) * boostMove.x;
		//		move.z = cosf(rotCamera.y + D3DX_PI / 4) * boostMove.z;
		//	}
		//	else
		//	{// 前
		//		rotDest.y = rotCamera.y + D3DX_PI;
		//		move.x = sinf(rotCamera.y) * boostMove.x;
		//		move.z = cosf(rotCamera.y) * boostMove.z;
		//	}
		//}
		//else if ((pInput->Press(DIK_S) && nIndex == 0) || pInput->Press(JOYPAD_DOWN, nIndex))
		//{
		//	if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		//	{// 左下
		//		rotDest.y = rotCamera.y + D3DX_PI / 4;
		//		move.x = -sinf(rotCamera.y + D3DX_PI / 4) * boostMove.x;
		//		move.z = -cosf(rotCamera.y + D3DX_PI / 4) * boostMove.z;
		//	}
		//	else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		//	{// 右下
		//		rotDest.y = rotCamera.y - D3DX_PI / 4;
		//		move.x = sinf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.x;
		//		move.z = cosf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.z;
		//	}
		//	else
		//	{// 下
		//		rotDest.y = rotCamera.y;
		//		move.x = -sinf(rotCamera.y) * boostMove.x;
		//		move.z = -cosf(rotCamera.y) * boostMove.z;
		//	}
		//}
		//else if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		//{// 左
		//	rotDest.y = rotCamera.y + D3DX_PI / 2;
		//	move.x = -sinf(rotCamera.y + D3DX_PI / 2) * boostMove.x;
		//	move.z = -cosf(rotCamera.y + D3DX_PI / 2) * boostMove.z;
		//}
		//else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		//{// 右
		//	rotDest.y = rotCamera.y - D3DX_PI / 2;
		//	move.x = sinf(rotCamera.y + D3DX_PI / 2) * boostMove.x;
		//	move.z = cosf(rotCamera.y + D3DX_PI / 2) * boostMove.z;
		//}

		D3DXVECTOR3 VectorMove = pInput->VectorMove();
		move.x = VectorMove.x * boostMove.x;
		move.z = VectorMove.y * boostMove.z;

		// 接地している場合に歩きモーション
		if (GetGround() == true)
		{
			// 歩き
			SetMotion(MOTION_WALK);
		}

	}
	// 前回モーションが歩きモーションだった場合
	else if (GetCurrentMotion() == MOTION_WALK)
	{
		// 歩きを終了させる
		SetMotion(MOTION_NEUTRAL);
	}

	// 移動量を更新
	CCharacter::SetMove(move);

	// 目的の角度の設定
	CCharacter::SetRotDest(rotDest);

	if (pInput->Trigger(DIK_F))
	{
		CMeshField *pMeshField = nullptr;
		pMeshField = CGame::GetMeshField();

		if (pMeshField != nullptr)
			pMeshField->Ground_Broken(CCharacter::GetPos(), 30.0f, 10);
	}

	// ジャンプ処理
	if ((pInput->Press(DIK_SPACE)) || pInput->Press(JOYPAD_A, nIndex))
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
	if ((pInput->Trigger(DIK_B)) || pInput->Press(JOYPAD_B, nIndex))
	{
		// プレイヤーの攻撃処理
		PlayerAttack();
	}

	// エネルギーゲージの取得
	CEnergy_Gauge* pGauge = CGame::GetEnergy_Gauge();

	if (pGauge != nullptr)
	{
		// 地上にいる場合
		if (GetGround())
		{
			pGauge->SetConsumption_Speed(3.0f);
			pGauge->SetRecovery_Speed(10.0f);
		}
		// 空中にいる場合
		else
		{
			pGauge->SetConsumption_Speed(7.0f);
			pGauge->SetRecovery_Speed(0.3f);
		}

		if (!pGauge->GetConsumption())
		{
			if (GetJump_Boost())
				// ジャンプブースト開始
				JumpBoost();

			if ((pInput->Press(DIK_LSHIFT)) && bWalk)
			{
				// ブーストする
				SetBoost(true);

				// エネルギーを消費する
				pGauge->Consumption_Gauge();
			}

			// 回避
			if (pInput->Trigger(DIK_C))
			{
				pGauge->Avoidance();			// エネルギー消費
				pGauge->Recovery_Pause(30);		// クールタイム
			}
		}
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