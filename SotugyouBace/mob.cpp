//=============================================================================
//
// モブ　　　mob.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "mob.h"
#include "application.h"
#include "tutorial.h"
#include "game.h"
#include "particle_emitter.h"
#include "mob_life_gauge.h"
#include "player.h"
#include "player_manager.h"

const float CMob::MOB_COLLISION_RADIUS = 200.0f;	// モブキャラの当たり判定の大きさ
//=====================================
// デフォルトコンストラクタ
//=====================================
CMob::CMob()
{
	// モブキャラ
	SetEnemyType(ENEMY_TYPE_MOB);

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
	// モブのモデルパーツを設定
	SetParts(PARTS_BODY, CParts_File::PARTS_MOB, CMotion::MOTION_MOB);

	CEnemy::Init();

	// 体力ゲージ
	SetGaugeManager(CMob_Life_Gauge::Create({0.0f, 0.0f, 0.0f}, { 200.0f,30.0f }));

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
	D3DXVECTOR3 Life_Gauge_Pos = GetPos();
	Life_Gauge_Pos.y += 400.0f;

	/*D3DXVECTOR3 Move_Vec = { 0.0f,-0.1f,-0.01f };
	D3DXVec3Normalize(&Move_Vec, &Move_Vec);
	SetSpeed(20);

	SetMove(Move_Vec);*/

	CGauge_Manager *GaugeManager = GetGaugeManager();

	if (GaugeManager != nullptr)
	{
		// 体力ゲージ
		GaugeManager->SetGaugePos(Life_Gauge_Pos);

		// 体力ゲージの表示
		DrawLifeGauge();
	}

	// 全てのパーツの処理
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// パーツの情報
		CParts* pParts = GetParts(nCnt);

		// パーツが持つ全てのモデル
		for (auto pModel : pParts->GetModelAll())
		{
			// 距離7000以上で敵を表示
			if (m_fDistance > DRAW_DISTANCE)
			{
				pModel->SetDrawFlag(false);
			}
			else
			{
				pModel->SetDrawFlag(true);
			}
		}
	}

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
// 破壊処理
//============================================================================
void CMob::Destroy()
{
	// 撃破パーティクル
	//std::move(CParticleEmitter::Create("Destroy", GetPos()));
	std::move(CParticleEmitter::Create("Dust", GetPos()));			//test

	CEnemy::Destroy();

	// 武器、パーツのドロップ
	CGame::SetDrop_Parts(1, GetPos());
}

//============================================================================
// 体力ゲージの表示
//============================================================================
void CMob::DrawLifeGauge()
{
	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	CPlayer* pPlayer = nullptr;

	// モード毎にプレイヤーを読み込む
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pPlayer = CTutorial::GetPlayerManager()->GetPlayer(0);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pPlayer = CGame::GetPlayerManager()->GetPlayer(0);
	}
	D3DXVECTOR3 Player_Pos = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 Mob_Pos = { 0.0f,0.0f,0.0f };

	if (pPlayer != nullptr)
	{
		// 位置の取得
		Player_Pos = pPlayer->GetPos();
		Mob_Pos = GetPos();
	}

	// プレイヤーから敵の距離
	D3DXVECTOR3 Vec = Player_Pos - Mob_Pos;

	// 距離の算出
	m_fDistance = sqrtf(Vec.x * Vec.x + Vec.z * Vec.z);

	// 距離3000以上
	if (m_fDistance > DRAW_HP_DISTANCE || GetLife() == FIRST_MAX_LIFE)
	{
		GetGaugeManager()->SetDrawGauge(false);
	}
	else
	{
		GetGaugeManager()->SetDrawGauge(true);
	}
}

//============================================================================
// 生成処理
//============================================================================
CMob* CMob::Create(const D3DXVECTOR3 pos)
{
	CMob* pMob = new CMob;

	if (FAILED(pMob->Init()))
	{
		return nullptr;
	}
	pMob->SetPos(pos);

	return pMob;
}