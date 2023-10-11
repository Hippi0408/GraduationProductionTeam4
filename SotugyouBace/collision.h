//=============================================================================
//
// collision.h
// Author : Tutida Ryousei
//
//=============================================================================
#ifndef _COLLISION_H_
#define	_COLLISION_H_

#include"object.h"

// ëOï˚êÈåæ
class CMove_Object;

class CCollision : public CObject
{
public:
	CCollision();
	~CCollision();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Collision();
	CMove_Object* GetParent() { return m_pMove_Object; }

	void SetCollision_Death(const bool death) { m_bCollision_Death = death; }

	static CCollision *Create(CMove_Object* pParent);

private:
	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3	m_OtherPos;
	float m_fRadius;
	float m_fOtherRadius;

	CMove_Object* m_pMove_Object;
	bool m_bCollision_Death;
};

#endif // !_COLLISION_H_
