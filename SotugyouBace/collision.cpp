//=============================================================================
//
// collision.cpp
// Author : Tutida Ryousei
//
//=============================================================================
#include"collision.h"
#include"game.h"
#include"character.h"
#include"bullet.h"
#include"application.h"
#include"player_manager.h"
#include"meshfield.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CCollision::CCollision()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CCollision::~CCollision()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CCollision::Init()
{
	m_Pos = { 0.0f,0.0f,0.0f };
	m_OtherPos = { 0.0f,0.0f,0.0f };
	m_fRadius = 0.0f;
	m_fOtherRadius = 0.0f;

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CCollision::Uninit()
{

}

//=============================================================================
// 更新処理
//=============================================================================
void CCollision::Update()
{
	// 情報の取得
	m_pPlayerManager = CApplication::GetPlayerManager();	// プレイヤーマネージャー
	m_pCharacter = m_pPlayerManager->GetPlayer(0);			// プレイヤー
	m_pBullet = m_pCharacter->GetBullet();					// 弾
	m_pBoss = CGame::GetBoss();								// ボス

	// 弾の当たり判定
	Bullet_Collision();
}

//=============================================================================
// 描画処理
//=============================================================================
void CCollision::Draw()
{

}

//=============================================================================
// 生成処理
//=============================================================================
CCollision *CCollision::Create()
{
	CCollision *pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();
	}

	return pCollision;
}

//=============================================================================
// 弾の当たり判定
//=============================================================================
void CCollision::Bullet_Collision()
{
	// 位置と半径の取得
	if (m_pBullet != nullptr)
	{
		// 弾の情報
		m_Pos = m_pBullet->GetPos();
		m_fRadius = m_pBullet->GetScale().x;

		if (m_pBoss != nullptr)
		{
			// ボスの情報
			m_OtherPos = m_pBoss->GetPos();
			m_fOtherRadius = m_pBoss->GetRadius();
		}

		// 円の当たり判定
		bool Collision = Sphere_Collision(m_Pos, m_fRadius, { m_OtherPos.x,m_OtherPos.y + 200,m_OtherPos.z }, 100);

		// 弾が当たった場合
		if (Collision)
		{
			m_pBullet->SetLife(0);
		}

		// メッシュと弾の当たり判定
		CMeshField *pMeshField = nullptr;
		pMeshField = CGame::GetMeshField();
		bool hit = false;

		if (pMeshField != nullptr)
		{
			pMeshField->MeshCollision(m_Pos);
			hit = pMeshField->GetHit();
		}
		if (hit)
		{
			pMeshField->Ground_Broken(m_Pos, 10.0f, 1);
			m_pBullet->SetLife(0);
		}
	}
}