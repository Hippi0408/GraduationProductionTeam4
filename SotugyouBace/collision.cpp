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
#include"collision_manager.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CCollision::CCollision()
{
	CApplication::GetCollision_Manager()->SetCollision(this);
}

//=============================================================================
// デストラクタ
//=============================================================================
CCollision::~CCollision()
{
	CCollision_Manager* pManager = CApplication::GetCollision_Manager();

	if (pManager != nullptr)
	{
		pManager->DestroyCollision(this);
	}
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

	m_bCollision_Death = false;

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CCollision::Uninit()
{
	Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CCollision::Update()
{
	// 情報の取得
	m_pMove_Object;

	// 当たり判定
	Collision();
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
CCollision *CCollision::Create(CMove_Object* pParent)
{
	CCollision *pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();
		pCollision->m_pMove_Object = pParent;
	}

	return pCollision;
}

//=============================================================================
// 当たり判定
//=============================================================================
void CCollision::Collision()
{
	// 自分の位置
	D3DXVECTOR3 pos = m_pMove_Object->GetPos();
	// 半径
	float fRadius = m_pMove_Object->GetRadius();
	
	for (auto pCollision : CApplication::GetCollision_Manager()->GetAllCollision())
	{
		if (pCollision != nullptr && pCollision != this)
		{
			// 相手のmoveobjectの情報
			CMove_Object* pMove_Object = pCollision->GetParent();

			// 相手の位置
			D3DXVECTOR3 OtherPos = pMove_Object->GetPos();
			// 半径
			float fOtherRadius = pMove_Object->GetRadius();

			bool Hit = Sphere_Collision(pos, 50, { OtherPos.x,OtherPos.y + 200,OtherPos.z }, 50);

			if (Hit)
			{
				m_pMove_Object->Hit();
				pMove_Object->Hit();
			}
			if (m_bCollision_Death)
			{
				return;
			}
		}
	}

	//	// メッシュと弾の当たり判定
	//	CMeshField *pMeshField = nullptr;
	//	pMeshField = CGame::GetMeshField();
	//	bool bHit = false;

	//	if (pMeshField != nullptr)
	//	{
	//		// 地面に当たったか
	//		pMeshField->MeshCollision(m_Pos);
	//		bHit = pMeshField->GetHit();
	//	}
	//	if (bHit)
	//	{
	//		// 地面をへこませる
	//		pMeshField->Ground_Broken(m_Pos, 10.0f, 1);
	//		m_pBullet->SetLife(0);
	//	}
	//}
}