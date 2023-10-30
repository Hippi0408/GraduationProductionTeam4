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
#include "tutorial.h"

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
	//LoadFile("Data\\text\\Motion\\motion_player.txt");
	SetParts(PARTS_BODY, "Data\\text\\Motion\\parts\\motion_Body.txt");
	SetParts(PARTS_LEG, "Data\\text\\Motion\\parts\\motion_Leg.txt");
	SetParts(PARTS_ARMS, "Data\\text\\Motion\\parts\\motion_Arms.txt");

	//for (int nCnt = 1; nCnt < (int)GetAllParts().size(); nCnt++)
	//{
	//	GetParts(nCnt)->SetModelParent(GetParts(PARTS_BODY)->GetModelSet(0).pModel);
	//}

	// タグの設定
	SetTag(TAG_CHARACTER);

	// プレイヤー側に設定
	SetPlayerSide(true);

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
	// モーション番号の設定
	ChangeMotion();

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
	// 着地モーションを設定
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// パーツ
		CParts* pParts = GetParts(nCnt);

		// 着地モーションが終了した場合
		if (pParts->GetCurrentMotion() == MOTION_LANDING && pParts->GetMotionStop() == true)
		{
			pParts->SetMotion(MOTION_NEUTRAL);
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
	CBullet::Create({pos_vec.x, pos_vec.y, pos_vec.z}, D3DXVECTOR2(60.0f, 60.0f), D3DXVECTOR3(-sinf(rot.y), sinf(rot.x), -cosf(rot.y)), true);
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
		GetParts(PARTS_LEG)->SetMotion(MOTION_JUMP);

		// 離着状態にする
		SetGround(false);

		// 上に上昇する
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// プレイヤーのジャンプブースト処理
//============================================================================
void CPlayer::JumpBoost()
{
	// エネルギーゲージの取得
	CEnergy_Gauge* pGauge = nullptr;

	if (CApplication::GetModeType() == CApplication::MODE_GAME)
		pGauge = CGame::GetEnergy_Gauge();
	else if (CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
		pGauge = CTutorial::GetEnergy_Gauge();

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
	// 着地モーションを設定
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		GetParts(nCnt)->SetMotion(MOTION_LANDING);
	}

	// キャラクターの着地処理
	CCharacter::Landing(pos);
}

//============================================================================
// 被弾処理
//============================================================================
void CPlayer::Hit(CMove_Object* pHit)
{
	// 自身ではない 且つ プレイヤー側ではない場合
	if (pHit != nullptr && GetPlayerSide() != pHit->GetPlayerSide())
	{
		TAG tag = pHit->GetTag();

		switch (tag)
		{
		case TAG_CHARACTER:
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