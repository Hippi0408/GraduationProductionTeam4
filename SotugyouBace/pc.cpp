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

#include"player_manager.h"

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
	//const int nIndex = GetCharaIndex();

	// カメラの角度
	D3DXVECTOR3 rotCamera = CApplication::GetCamera()->GetRot();

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

	// 歩いている場合
	if (pInput->MovePress(GAME_MOVE_ALL))
	{
		// 回転させる
		Rotation();

		// 歩き判定を真にする
		bWalk = true;
	}

	for (int nCnt = 0; nCnt < MODEL_MAX; nCnt++)
	{
		// 歩いている場合
		if (bWalk == true)
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
				SetMotion(MOTION_WALK);
			}
			// 前回モーションが歩きモーションだった場合

		}
		else if (GetCurrentMotion() != MOTION_LANDING && GetGround())
		{
			// 歩きを終了させる
			SetMotion(MOTION_NEUTRAL);
		}
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

	// 視点処理
	Perspective();

	// エネルギーゲージの取得
	CEnergy_Gauge* pGauge = CGame::GetEnergy_Gauge();

	if (pGauge != nullptr)
	{
		// 地上にいる場合
		if (GetGround())
		{
			// 消費速度
			pGauge->SetConsumption_Speed(3.0f);
			// 回復速度
			pGauge->SetRecovery_Speed(10.0f);
		}
		// 空中にいる場合
		else
		{
			// 消費速度
			pGauge->SetConsumption_Speed(6.0f);
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
				SetMotion(MOTION_BOOST_RUN);
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

	//カメラの向きの設定
	CApplication::GetCamera()->SetRot(rotCamera);
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