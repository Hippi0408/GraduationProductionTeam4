//=============================================================================
//
// collision.h
// Author : Tutida Ryousei
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _COLLISION_H_
#define	_COLLISION_H_

#include"d3dx9.h"

// 前方宣言
class CMove_Object;

#ifdef _DEBUG
class CObject3D;
#endif

class CCollision
{
public:

	CCollision();
	~CCollision();

	HRESULT Init();
	void Uninit();
	void Update();
	void Releace() { m_bDeath = true; }	// 死亡フラグを真にする

	void Collision();
	bool Sphere_Collision(const D3DXVECTOR3 pos, const float radius, const D3DXVECTOR3 otherPos, const float otherRadius);	// 円の当たり判定

	void SetParent(CMove_Object* parent) { m_pParent = parent; }

	const bool GetDeath() { return m_bDeath; }		// 死亡フラグの取得
	CMove_Object* GetParent() { return m_pParent; }

	static CCollision* Create(CMove_Object* pParent);

private:

	bool m_bDeath;				// 死亡フラグ

	CMove_Object* m_pParent;	// 親オブジェクト

#ifdef _DEBUG
	void DebugObj();			// デバッグオブジェクトの処理
	CObject3D* m_pDebugObj;		// デバッグオブジェクトのポインタ
#endif

};

#endif // !_COLLISION_H_
