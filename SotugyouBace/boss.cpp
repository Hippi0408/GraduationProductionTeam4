//=============================================================================
//
// ボスキャラ　　　boss.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "boss.h"
#include "application.h"
#include "game.h"
#include "particle_emitter.h"

const float CBoss::BOSS_COLLISION_RADIUS = 500.0f;	// ボスの当たり判定の大きさ
//=====================================
// デフォルトコンストラクタ
//=====================================
CBoss::CBoss()
{
	// ボスの初期値を設定
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(BOSS_COLLISION_RADIUS);
}

//=====================================
// デストラクタ
//=====================================
CBoss::~CBoss()
{

}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CBoss::Init()
{
	// プレイヤーのモデルを読み込む
	//LoadFile("Data\\text\\Motion\\motion_boss.txt");

	SetParts(0, "Data\\text\\Motion\\motion_boss.txt");
	GetParts(0)->GetModelSet(MODEL_BODY).pModel->SetSize({ 5.0f, 5.0f, 5.0f });

	// 体モデルのサイズを5倍
	//GetModelSet(MODEL_BODY).pModel->SetSize({ 5.0f, 5.0f, 5.0f });

	CEnemy::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CBoss::Uninit()
{
	CEnemy::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CBoss::Update()
{
	// モーション変更
	//ChangeMotion();

	// キャラクターの更新
	CEnemy::Update();
}

//============================================================================
// 描画処理
//============================================================================
void CBoss::Draw()
{
	CEnemy::Draw();
}
//
////============================================================================
//// モーション変更処理
////============================================================================
//void CBoss::ChangeMotion()
//{
//	// 現在のモーション
//	const int nCuttentMotion = GetCurrentMotion();
//	const int nMotion = GetMotion();
//
//	// 現在のモーションから変わった場合
//	if (nCuttentMotion != nMotion)
//	{
//		// 現在モーションの終了処理
//		switch (nCuttentMotion)
//		{
//		case MOTION_NEUTRAL:
//			break;
//		case MOTION_WALK:
//			break;
//		default:
//			break;
//		}
//
//		// 現在モーションの開始処理
//		switch (nMotion)
//		{
//		case MOTION_NEUTRAL:
//			break;
//		case MOTION_WALK:
//			break;
//		default:
//			break;
//		}
//
//		// キャラクターのモーション変更処理
//		CCharacter::ChangeMotion();
//	}
//}

//============================================================================
// 破壊処理
//============================================================================
void CBoss::Destroy()
{
	// ボス用撃破パーティクル
	for (int nCnt = 0; nCnt < 30; nCnt++)
	{
		D3DXVECTOR3 pos = GetPos();
		pos.y += 50.0f * nCnt;

		// 攻撃パーティクル
		std::move(CParticleEmitter::Create("MineOre", pos));
	}

	// ゲーム終了を設定する
	CGame::SetGameEnd();

	CEnemy::Destroy();
}

//============================================================================
// 生成処理
//============================================================================
CBoss* CBoss::Create(const D3DXVECTOR3 pos)
{
	CBoss* pBoss = new CBoss;

	if (FAILED(pBoss->Init()))
	{
		return nullptr;
	}

	pBoss->SetPos(pos);

	return pBoss;
}