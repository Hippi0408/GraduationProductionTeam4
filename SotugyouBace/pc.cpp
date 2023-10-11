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

	// 目的の角度
	D3DXVECTOR3 rotDest = GetRotDest();

	// 歩き判定
	bool bWalk = false;

	if ((pInput->Press(DIK_W) && nIndex == 0)
		|| (pInput->Press(DIK_A) && nIndex == 0)
		|| (pInput->Press(DIK_S) && nIndex == 0)
		|| (pInput->Press(DIK_D) && nIndex == 0)
		|| pInput->Press(JOYPAD_RIGHT, nIndex)
		|| pInput->Press(JOYPAD_LEFT, nIndex)
		|| pInput->Press(JOYPAD_UP, nIndex)
		|| pInput->Press(JOYPAD_DOWN, nIndex))
	{
		// 回転させる
		Rotation();

		bWalk = true;
	}

	// 歩いている場合
	if (bWalk == true)
	{
		// プレイヤーの移動
		if ((pInput->Press(DIK_W) && nIndex == 0) || pInput->Press(JOYPAD_UP, nIndex))
		{
			if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
			{// 左前
				rotDest.y = rotCamera.y + D3DX_PI * 3 / 4;
				move.x = -sinf(rotCamera.y + D3DX_PI * 3 / 4);
				move.z = -cosf(rotCamera.y + D3DX_PI * 3 / 4);
			}
			else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
			{// 右前
				rotDest.y = rotCamera.y - D3DX_PI * 3 / 4;
				move.x = sinf(rotCamera.y + D3DX_PI / 4);
				move.z = cosf(rotCamera.y + D3DX_PI / 4);
			}
			else
			{// 前
				rotDest.y = rotCamera.y + D3DX_PI;
				move.x = sinf(rotCamera.y);
				move.z = cosf(rotCamera.y);
			}
		}
		else if ((pInput->Press(DIK_S) && nIndex == 0) || pInput->Press(JOYPAD_DOWN, nIndex))
		{
			if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
			{// 左下
				rotDest.y = rotCamera.y + D3DX_PI / 4;
				move.x = -sinf(rotCamera.y + D3DX_PI / 4);
				move.z = -cosf(rotCamera.y + D3DX_PI / 4);
			}
			else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
			{// 右下
				rotDest.y = rotCamera.y - D3DX_PI / 4;
				move.x = sinf(rotCamera.y + D3DX_PI * 3 / 4);
				move.z = cosf(rotCamera.y + D3DX_PI * 3 / 4);
			}
			else
			{// 下
				rotDest.y = rotCamera.y;
				move.x = -sinf(rotCamera.y);
				move.z = -cosf(rotCamera.y);
			}
		}
		else if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		{// 左
			rotDest.y = rotCamera.y + D3DX_PI / 2;
			move.x = -sinf(rotCamera.y + D3DX_PI / 2);
			move.z = -cosf(rotCamera.y + D3DX_PI / 2);
		}
		else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		{// 右
			rotDest.y = rotCamera.y - D3DX_PI / 2;
			move.x = sinf(rotCamera.y + D3DX_PI / 2);
			move.z = cosf(rotCamera.y + D3DX_PI / 2);
		}

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
		CGame::GetMeshField()->Ground_Broken(CCharacter::GetPos(), 50.0f, 5);
	}
	// ジャンプ処理
	if ((pInput->Trigger(DIK_SPACE)) || pInput->Press(JOYPAD_A, nIndex))
	{
		// プレイヤーのジャンプ処理
		PlayerJump();
	}

	// 攻撃処理
	if ((pInput->Trigger(DIK_B)) || pInput->Press(JOYPAD_B, nIndex))
	{
		// プレイヤーの攻撃処理
		PlayerAttack();
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