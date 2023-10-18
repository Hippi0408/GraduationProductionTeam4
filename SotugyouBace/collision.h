//=============================================================================
//
// collision.h
// Author : Tutida Ryousei
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _COLLISION_H_
#define	_COLLISION_H_

#include"object.h"

// �O���錾
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
	bool Sphere_Collision(const D3DXVECTOR3 pos, const float radius, const D3DXVECTOR3 otherPos, const float otherRadius);	// �~�̓����蔻��

	void SetParent(CMove_Object* parent) { m_pParent = parent; }

	CMove_Object* GetParent() { return m_pParent; }

	static CCollision* Create(CMove_Object* pParent);

private:

	CMove_Object* m_pParent;	// �e�I�u�W�F�N�g
};

#endif // !_COLLISION_H_
