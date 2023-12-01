//=============================================================================
//
// collision.cpp
// Author : Tutida Ryousei
//
//=============================================================================
#include "collision.h"
#include "collision_manager.h"
#include "application.h"
#include "tutorial.h"
#include "game.h"
#include "move_object.h"
#include "object3D.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CCollision::CCollision()
{
	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	// 生成時に自身のポインタを当たり判定マネージャーに設定
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CTutorial::GetCollision_Manager()->SetCollision(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CGame::GetCollision_Manager()->SetCollision(this);
	}
	m_bDeath = false;
	m_bNoneHit = false;
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
	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CCollision::Uninit()
{
	// 親の当たり判定ポインタを消す処理
	m_pParent->CollisionDestroy();

#ifdef _DEBUG
	// デバッグオブジェクトが使用中の場合
	if (m_pDebugObj != nullptr)
	{
		m_pDebugObj->Uninit();
		m_pDebugObj = nullptr;
	}
#endif // _DEBUG

	Releace();
}

//=============================================================================
// 更新処理
//=============================================================================
void CCollision::Update()
{
#ifdef _DEBUG
	DebugObj();
#endif // _DEBUG

	// 当たり判定
	Collision();
}

//=============================================================================
// 当たり判定
//=============================================================================
void CCollision::Collision()
{
	// ヒット処理を読み込む場合
	if (m_bNoneHit == false)
	{
		// 自分の位置
		D3DXVECTOR3 pos = m_pParent->GetCenterPos();
		// 半径
		float fRadius = m_pParent->GetRadius();
		// サイズ
		D3DXVECTOR3 Size = m_pParent->GetSize();

		// 現在のモード
		CApplication::MODE Mode = CApplication::GetModeType();

		CCollision_Manager* pCollision_Manager = nullptr;

		// モード毎にプレイヤーを読み込む
		if (Mode == CApplication::MODE_TUTORIAL)
		{
			pCollision_Manager = CTutorial::GetCollision_Manager();
		}
		else if (Mode == CApplication::MODE_GAME)
		{
			pCollision_Manager = CGame::GetCollision_Manager();
		}

		// 全ての当たり判定を個別に判定
		for (auto pCollision : pCollision_Manager->GetAllCollision())
		{
			// 当たり判定が存在する場合 && 当たり判定が自身ではない場合
			if (!pCollision->GetParent()->GetDeathFlag() && !pCollision->GetDeath() && pCollision != this)
			{
				// 相手のmoveobjectの情報
				CMove_Object* pMove_Object = pCollision->GetParent();

				// 相手の位置
				D3DXVECTOR3 OtherPos = pMove_Object->GetCenterPos();
				bool bHit = false;

				if (pMove_Object->GetCollision_Type() == CMove_Object::COLLISION_TYPE_SHERER)
				{
					// 半径
					float fOtherRadius = pMove_Object->GetRadius();

					// 円同士の当たり判定の計算
					bHit = Sphere_Collision(pos, fRadius, OtherPos, fOtherRadius);
				}
				else
				{
					// 前回の位置
					D3DXVECTOR3 PosOld = m_pParent->GetPosOld();

					// サイズ
					D3DXVECTOR3 OtherSize = pMove_Object->GetSize();

					// 円同士の当たり判定の計算
					bHit = Block_Collision(pos, PosOld, Size, OtherPos, OtherSize);
				}

				// ヒットした場合
				if (bHit)
				{
					// 二回ヒットしてしまう
					m_pParent->Hit(pMove_Object);
					pMove_Object->Hit(m_pParent);
				}
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
// 矩形の当たり判定
//=============================================================================
bool CCollision::Block_Collision(const D3DXVECTOR3 pos, const D3DXVECTOR3 posold, const D3DXVECTOR3 size, const D3DXVECTOR3 otherpos, const D3DXVECTOR3 othersize)
{
	if (otherpos.x + othersize.x > pos.x - size.x
		&& otherpos.x - othersize.x < pos.x + size.x)
	{
		// 奥から手前
		if (otherpos.z + othersize.z > pos.z - size.z
			&& otherpos.z + othersize.z <= posold.z - size.z)
		{
			// 押し出し

			return true;
		}

		// 手前から奥
		else if (otherpos.z - othersize.z < pos.z + size.z
			&& otherpos.z - othersize.z >= posold.z + size.z)
		{
			return true;
		}
	}
	else if (otherpos.z + othersize.z > pos.z - size.z
		&& otherpos.z - othersize.z < pos.z + size.z)
	{
		// 右から左
		if (otherpos.x + othersize.x > pos.x - size.x
			&& otherpos.x + othersize.x <= posold.x - size.x)
		{
			return true;
		}

		// 左から右
		else if (otherpos.x - othersize.x < pos.x + size.x
			&& otherpos.x - othersize.x >= posold.x + size.x)
		{
			return true;
		}
	}

	return false;
}

// デバッグ用関数の処理
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

//=============================================================================
// デバッグオブジェクトの処理
//=============================================================================
void CCollision::SetDebugObj()
{
	const float fRadius = m_pParent->GetRadius() * 2.0f;

	// デバッグオブジェクトの生成
	m_pDebugObj = CObject3D::Create(m_pParent->GetCenterPos(), D3DXVECTOR2(fRadius, fRadius));

	// 色の設定(プレイヤー側かどうか ? 水色 : 赤色)
	m_pDebugObj->SetCol(m_pParent->GetPlayerSide() ? D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f) : D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
	m_pDebugObj->SetTexture(CTexture::TEXTURE_CIRCLE);
	m_pDebugObj->Setbillboard(true);
}
#endif // _DEBUG

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
			// デバッグオブジェクトの設定
			pCollision->SetDebugObj();
#endif // _DEBUG

		}
	}

	return pCollision;
}