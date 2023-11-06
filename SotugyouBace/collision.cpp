//=============================================================================
//
// collision.cpp
// Author : Tutida Ryousei
//
//=============================================================================
#include "collision.h"
#include "application.h"
#include "collision_manager.h"
#include "move_object.h"

#ifdef _DEBUG
#include "object3D.h"
#endif

//=============================================================================
// コンストラクタ
//=============================================================================
CCollision::CCollision()
{
	CApplication::GetCollision_Manager()->SetCollision(this);
	m_bDeath = false;
}

//=============================================================================
// デストラクタ
//=============================================================================
CCollision::~CCollision()
{
	//CCollision_Manager* pManager = CApplication::GetCollision_Manager();

	//if (pManager != nullptr)
	//{
	//	// 当たり判定を消す
	//	pManager->DestroyCollision(this);
	//}
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CCollision::Init()
{
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CCollision::Uninit()
{
#ifdef _DEBUG
	// デバッグオブジェクトが使用中の場合
	if (m_pDebugObj != nullptr)
	{
		m_pDebugObj->Uninit();
		m_pDebugObj = nullptr;
	}
#endif

	Releace();
}

//=============================================================================
// 更新処理
//=============================================================================
void CCollision::Update()
{
#ifdef _DEBUG
	DebugObj();
#endif

	// 当たり判定
	Collision();
}

//=============================================================================
// 当たり判定
//=============================================================================
void CCollision::Collision()
{
	// 自分の位置
	D3DXVECTOR3 pos = m_pParent->GetCenterPos();
	// 半径
	float fRadius = m_pParent->GetRadius();
	
	// 全ての当たり判定を個別に判定
	for (auto pCollision : CApplication::GetCollision_Manager()->GetAllCollision())
	{
		// 当たり判定が存在する場合 && 当たり判定が自身ではない場合
		if (pCollision != nullptr && pCollision != this)
		{
			// 相手のmoveobjectの情報
			CMove_Object* pMove_Object = pCollision->GetParent();

			// 相手の位置
			D3DXVECTOR3 OtherPos = pMove_Object->GetCenterPos();
			// 半径
			float fOtherRadius = pMove_Object->GetRadius();

			// 円同士の当たり判定の計算
			bool bHit = Sphere_Collision(pos, fRadius, OtherPos, fOtherRadius);

			// ヒットした場合
			if (bHit)
			{
				m_pParent->Hit(pMove_Object);
				pMove_Object->Hit(m_pParent);
			}
		}
	}
}

//==============================================================================================
// オブジェクトを継承したものの当たり判定
//==============================================================================================
bool CCollision::Sphere_Collision(const D3DXVECTOR3 pos, const float radius, const D3DXVECTOR3 otherPos, const float otherRadius)
{
	// 位置同士の距離の計算用変数
	D3DXVECTOR3 Distance = otherPos - pos;

	float Dis = sqrtf((otherPos.x - pos.x) * (otherPos.x - pos.x)
		+ (otherPos.z - pos.z) * (otherPos.z - pos.z));

	float DisY = otherPos.y - pos.y;
	if (DisY < 0)
		DisY *= -1;

	if (Dis <= radius + otherRadius
		&& DisY <= radius + otherRadius)
		return true;

	return false;
}

#ifdef _DEBUG
//=============================================================================
// デバッグオブジェクトの処理
//=============================================================================
void CCollision::DebugObj()
{
	// デバッグオブジェクトが使用中の場合
	if (m_pDebugObj != nullptr)
	{
		// 位置を設定
		m_pDebugObj->SetPos(m_pParent->GetCenterPos());
	}
}
#endif

//=============================================================================
// 生成処理
//=============================================================================
CCollision* CCollision::Create(CMove_Object* pParent)
{
	CCollision* pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();

		// 親ポインタが使用中の場合
		if (pParent != nullptr)
		{
			pCollision->m_pParent = pParent;

#ifdef _DEBUG
			const float fRadius = pCollision->m_pParent->GetRadius() * 2.0f;

			pCollision->m_pDebugObj = CObject3D::Create(pCollision->m_pParent->GetCenterPos(), D3DXVECTOR2(fRadius, fRadius));
			pCollision->m_pDebugObj->SetTexture(CTexture::TEXTURE_CIRCLE);
			pCollision->m_pDebugObj->SetCol({1.0f, 0.0f, 0.0f, 1.0f});
#endif
		}
	}

	return pCollision;
}