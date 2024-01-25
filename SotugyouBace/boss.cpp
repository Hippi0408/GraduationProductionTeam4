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
#include "boss_life_gauge.h"
#include "camera.h"
#include "particle_emitter.h"

const float CBoss::BOSS_COLLISION_RADIUS = 1000.0f;	// ボスの当たり判定の大きさ
//=====================================
// デフォルトコンストラクタ
//=====================================
CBoss::CBoss()
{
	// ボスキャラ
	SetEnemyType(ENEMY_TYPE_BOSS);

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
	// ボスのモデルパーツを設定
	SetParts(PARTS_BODY, CParts_File::PARTS_BOSS, CMotion::MOTION_BOSS);
	GetParts(PARTS_BODY)->GetModel(0)->SetSize({ 5.0f, 5.0f, 5.0f });

	SetGaugeManager(CBoss_Life_Gauge::Create({ 1280 / 2, 100.0f,0.0f }, { 800.0f,15.0f }));

	CEnemy::Init();

	CParts* pBody = GetParts(PARTS_BODY);
	pBody->SetMotion(MOTION_NEUTRAL);

	m_bOpening = true;

	//SetCenterPos({ 0.0f,500.0f,0.0f });

	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetOpening(m_bOpening);

	pCamera->SetPosV({ 0.0f,200.0f,-1000.0f });
	pCamera->SetPosR({ 0.0f, 3000.0f, -500.0f });
	pCamera->SetRot({ 0.0f,0.0f,0.0f });

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
	// キャラクターの更新
	CEnemy::Update();

	ChangeMotion();

	// カメラのポインタ
	bool bOpening = CApplication::GetCamera()->GetOpening();

	if (m_bOpening != bOpening)
	{
		// オープニング終了時に着地する
		D3DXVECTOR3 pos = GetPos();
		SetPos({ pos.x,0.0f,pos.z });

		CParts* pBody = GetParts(PARTS_BODY);
		pBody->SetMotion(MOTION_NEUTRAL);
	}

	m_bOpening = bOpening;
}

//============================================================================
// 描画処理
//============================================================================
void CBoss::Draw()
{
	CEnemy::Draw();
}

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

		// 撃破時パーティクル
		std::move(CParticleEmitter::Create("Destroy", pos));
	}



	// ゲーム終了を設定する
	CGame::SetGameEnd();

	CEnemy::Destroy();

}

//============================================================================
// モーション変更処理
//============================================================================
void CBoss::ChangeMotion()
{
	// ニュートラルモーションモーションを設定
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// パーツ
		CParts* pParts = GetParts(nCnt);

		if (pParts->GetMotion() == MOTION_ATTACK1 && pParts->GetMotionStop() == true)
		{
			pParts->SetMotion(MOTION_ATTACK2);
		}
		// モーションがループしない場合
		else if (pParts->GetMotionLoop() == false && pParts->GetMotionStop() == true)
		{
			// ニュートラルモーションにする
			pParts->SetMotion(MOTION_NEUTRAL);
		}
	}
}

//============================================================================
// 着地処理
//============================================================================
void CBoss::Landing(const D3DXVECTOR3 pos)
{
	// カメラのポインタ
	bool bOpening = CApplication::GetCamera()->GetOpening();

	if (bOpening)
	{
		// 着地モーションを設定
		for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
		{
			GetParts(nCnt)->SetMotion(MOTION_NEUTRAL);
			// 着地時パーティクル
			std::move(CParticleEmitter::Create("Shock", pos));
			std::move(CParticleEmitter::Create("Dust", pos));
		}
	}

	// キャラクターの着地処理
	CCharacter::Landing(pos);
}

//============================================================================
// 移動処理
//============================================================================
void CBoss::Move()
{
	CEnemy::Move();

	// 常に追跡状態
	SetTracking(true);
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