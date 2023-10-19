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
#include "game.h"
#include "energy_gauge.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// プレイヤーの当たり判定の大きさ
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// プレイヤーのジャンプ力
//=====================================
// デフォルトコンストラクタ
//=====================================
CPlayer::CPlayer()
{
	// プレイヤーの初期値を設定
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(PLAYER_COLLISION_RADIUS);
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

	// タグの設定
	SetTag(TAG_PLAYER);

	// 当たり判定の生成
	SetCollision();

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
	for (int nCnt = 0; nCnt < MODEL_MAX; nCnt++)
	{
		// 現在のモーション
		const int nCuttentMotion = GetCurrentMotion(nCnt);

		// 着地モーションが終了した場合
		if (nCuttentMotion == MOTION_LANDING && GetMotionStop(nCnt) == true)
		{
			SetMotion(MOTION_NEUTRAL, nCnt);
		}

		// 次のモーション
		int nMotion = GetMotion(nCnt);

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
			CCharacter::ChangeMotion(nCnt);
		}
	}
}

//============================================================================
// プレイヤーの攻撃処理
//============================================================================
void CPlayer::PlayerAttack()
{
	// 情報の取得
	D3DXVECTOR3 pos = GetCenterPos();
	D3DXVECTOR3 rot = GetRot();

	D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };
	pos_vec *= 100.f;
	pos_vec += pos;

	// 弾の生成
	CBullet::Create({pos_vec.x, pos_vec.y, pos_vec.z}, D3DXVECTOR2(60.0f, 60.0f), D3DXVECTOR3(-sinf(rot.y), sinf(rot.x), -cosf(rot.y)));
}

//============================================================================
// プレイヤーのジャンプ処理
//============================================================================
void CPlayer::JumpStart()
{
	// 接地している場合のみ
	if (GetGround())
	{
		for (int nCnt = 0; nCnt < MODEL_MAX; nCnt++)
		{
			// ジャンプモーションを設定
			SetMotion(MOTION_JUMP, nCnt);
			/*SetMotion(MOTION_WALK, 3);
			SetMotion(MOTION_WALK, 4);
			SetMotion(MOTION_WALK, 5);
			SetMotion(MOTION_WALK, 6);
			SetMotion(MOTION_WALK, 7);
			SetMotion(MOTION_WALK, 8);*/
		}

		// 離着状態にする
		SetGround(false);

		// 上昇する
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// プレイヤーのジャンプブースト処理
//============================================================================
void CPlayer::JumpBoost()
{
	// エネルギーゲージの取得
	CEnergy_Gauge* pGauge = CGame::GetEnergy_Gauge();

	if (pGauge != nullptr)
	{
		// 空中にいる場合、エネルギーが残っている場合
		if (!GetGround() && !pGauge->GetConsumption())
		{
			// 上昇する
			AddMove({ 0.0f, 0.5f, 0.0f });

			// エネルギーを消費する
			pGauge->Consumption_Gauge();
		}
	}
}

//============================================================================
// プレイヤーの着地処理
//============================================================================
void CPlayer::Landing(const D3DXVECTOR3 pos)
{
	for (int nCnt = 0; nCnt < MODEL_MAX; nCnt++)
	{
		// 着地モーションを設定
		SetMotion(MOTION_LANDING, nCnt);

		// キャラクターの着地処理
		CCharacter::Landing(pos);
	}
}

//============================================================================
// 被弾処理
//============================================================================
void CPlayer::Hit(CMove_Object* pHit)
{
	if (pHit != nullptr)
	{
		TAG tag = pHit->GetTag();

		switch (tag)
		{
		case TAG_PLAYER:
			break;
		case TAG_ENEMY:
			break;
		case TAG_BULLET:
			// 弾のダメージを返す
			Damage(pHit->GetPower());
			break;
		default:
			break;
		}
	}
}