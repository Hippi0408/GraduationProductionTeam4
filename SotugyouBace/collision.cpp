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
	m_pParent;

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
			bool Hit = Sphere_Collision(pos, fRadius, { OtherPos.x, OtherPos.y, OtherPos.z }, fOtherRadius);

			// ヒットした場合
			if (Hit)
			{
				m_pParent->Hit();
				pMove_Object->Hit();
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

//=============================================================================
// 生成処理
//=============================================================================
CCollision *CCollision::Create(CMove_Object* pParent)
{
	CCollision *pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();
		pCollision->m_pParent = pParent;
	}

	return pCollision;
}