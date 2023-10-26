//=============================================================================
//
// モブ　　　mob.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "mob.h"
#include "application.h"
#include "game.h"
#include "particle_emitter.h"
#include "mob_life_gauge.h"

const float CMob::MOB_COLLISION_RADIUS = 100.0f;	// ボスの当たり判定の大きさ
//=====================================
// デフォルトコンストラクタ
//=====================================
CMob::CMob()
{
	// プレイヤーの初期値を設定
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(MOB_COLLISION_RADIUS);
}

//=====================================
// デストラクタ
//=====================================
CMob::~CMob()
{

}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CMob::Init()
{
	// プレイヤーのモデルを読み込む
	LoadFile("Data\\text\\Motion\\motion_mob.txt");

	// 体力ゲージ
	m_LifeGauge = CMob_Life_Gauge::Create({ GetPos().x,GetPos().y + 50.0f,GetPos().z }, { 200.0f,30.0f }, m_nMob_Index);

	CEnemy::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CMob::Uninit()
{
	CEnemy::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CMob::Update()
{
	// モーション変更
	ChangeMotion();

	// 体力ゲージ
	m_LifeGauge->SetMobLife_Pos({ GetPos().x,GetPos().y + 400.0f,GetPos().z });

	// キャラクターの更新
	CEnemy::Update();
}

//============================================================================
// 描画処理
//============================================================================
void CMob::Draw()
{
	CEnemy::Draw();
}

//============================================================================
// モーション変更処理
//============================================================================
void CMob::ChangeMotion()
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
// 破壊処理
//============================================================================
void CMob::Destroy()
{
	// ボス用撃破パーティクル
	std::move(CParticleEmitter::Create("MineOre", GetPos()));

	// 体力ゲージ
	if (m_LifeGauge != nullptr)
	{
		m_LifeGauge->GetBackGauge()->Uninit();
		m_LifeGauge->Uninit();
	}

	CEnemy::Destroy();
}

//============================================================================
// 生成処理
//============================================================================
CMob* CMob::Create(const D3DXVECTOR3 pos, const int index)
{
	CMob* pMob = new CMob;

	if (pMob != nullptr)
	{
		pMob->SetPos(pos);
		pMob->SetMobIndex(index);
		pMob->Init();
	}

	return pMob;
}