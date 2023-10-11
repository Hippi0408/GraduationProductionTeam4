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
#include "player_manager.h"
#include"game.h"

const float CPlayer::PLAYER_JUMP_POWER = 10.0f;
//=====================================
// デフォルトコンストラクタ
//=====================================
CPlayer::CPlayer()
{
	// プレイヤーの初期値を設定
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
}

//=====================================
// デストラクタ
//=====================================
CPlayer::~CPlayer()
{
	// プレイヤーマネージャーの自身を削除
	CApplication::GetPlayerManager()->PlayerRelease(m_nCharaIndex);
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

	CObject::Release();
}

//============================================================================
// 更新処理
//============================================================================
void CPlayer::Update()
{
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

	// 着地モーションが終了した場合
	if (nCuttentMotion == MOTION_LANDING && GetMotionStop() == true)
	{
		SetMotion(MOTION_NEUTRAL);
	}

	int nMotion = GetMotion();


	// 現在のモーションから変わった場合
	if (nCuttentMotion != nMotion)
	{
		// 現在モーションの終了処理
		switch (nCuttentMotion)
		{
			// ニュートラル
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
			break;
		case MOTION_JUMP:
			break;
		case MOTION_LANDING:
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
		case MOTION_JUMP:
			break;
		case MOTION_LANDING:
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
	// 情報の取得
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();

	D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };
	pos_vec *= 120.f;
	pos_vec += pos;

	// 弾の生成
	CBullet::Create({pos_vec.x, pos_vec.y + 200.0f, pos_vec.z}, D3DXVECTOR2(60.0f, 60.0f), D3DXVECTOR3(-sinf(rot.y), sinf(rot.x), -cosf(rot.y)));
}

//============================================================================
// プレイヤーのジャンプ処理
//============================================================================
void CPlayer::JumpStart()
{
	// 接地している場合のみ
	if (GetGround() == true)
	{
		// ジャンプモーションを設定
		SetMotion(MOTION_JUMP);

		// 離着状態にする
		SetGround(false);

		// 上に上昇する
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// プレイヤーの着地処理
//============================================================================
void CPlayer::Landing(const D3DXVECTOR3 pos)
{
	// 着地モーションを設定
	SetMotion(MOTION_LANDING);

	// キャラクターの着地処理
	CCharacter::Landing(pos);
}

//============================================================================
// 被弾処理
//============================================================================
void CPlayer::Hit()
{
	Damage(30);
}