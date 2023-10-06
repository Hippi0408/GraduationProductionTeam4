//=============================================================================
//
// player.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "player.h"
#include "application.h"
#include "input.h"
#include "bullet.h"

//=====================================
// デフォルトコンストラクタ
//=====================================
CPlayer::CPlayer()
{

}

//=====================================
// デストラクタ
//=====================================
CPlayer::~CPlayer()
{

}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CPlayer::Init()
{
	// プレイヤーのモデルを読み込む
	LoadFile("Data\\text\\Motion\\motion_player.txt");

	CCharacter::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CPlayer::Update()
{
	// 攻撃処理
	PlayerAttack();

	// キャラクターの更新
	CCharacter::Update();
}

//============================================================================
// 描画処理
//============================================================================
void CPlayer::Draw()
{
	CCharacter::Draw();
}

//============================================================================
// モーション変更処理
//============================================================================
void CPlayer::ChangeMotion()
{
	// 現在のモーション
	const int nCuttentMotion = GetCurrentMotion();
	const int nMotion = GetMotion();

	// 現在のモーションから変わった場合
	if (nCuttentMotion != nMotion)
	{
		// 現在モーションの終了処理
		switch (nCuttentMotion)
		{
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
			break;
		default:
			break;
		}

		// 現在モーションの開始処理
		switch (nMotion)
		{
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
			break;
		default:
			break;
		}

		// キャラクターのモーション変更処理
		CCharacter::ChangeMotion();
	}
}

//============================================================================
// プレイヤーの攻撃処理
//============================================================================
void CPlayer::PlayerAttack()
{
	// インプット
	CInput* pInput = CInput::GetKey();

	// 情報の取得
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();

	// 攻撃処理
	if ((pInput->Trigger(DIK_B)))
	{
		// 弾の生成
		CBullet::Create(D3DXVECTOR3(pos.x,200.0f,pos.z), 20.0f, 20.0f, D3DXVECTOR3(-sinf(rot.y) * 15.0f, sinf(rot.x) * 15.0f, -cosf(rot.y) * 15.0f), 50, CBullet::PRIORITY_BACK_GROUND);
	}
}
