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

// �O���錾
class CMove_Object;
class CObject3D;

class CCollision
{
public:

	CCollision();
	~CCollision();

	HRESULT Init();
	void Uninit();
	void Update();
	void Releace() { m_bDeath = true; }	// ���S�t���O��^�ɂ���

	void Collision();
	bool Sphere_Collision(const D3DXVECTOR3 pos, const float radius, const D3DXVECTOR3 otherPos, const float otherRadius);	// �~�̓����蔻��
	void DebugObj();			// �f�o�b�O�I�u�W�F�N�g�̏���

	static CCollision* Create(CMove_Object* pParent, const D3DXCOLOR col = { 1.0f, 1.0f, 1.0f, 1.0f });

	void SetParent(CMove_Object* parent) { m_pParent = parent; }

	const bool GetDeath() { return m_bDeath; }		// ���S�t���O�̎擾
	CMove_Object* GetParent() { return m_pParent; }

	CObject3D* GetDebugObj() { return m_pDebugObj; }		// �f�o�b�O�I�u�W�F�N�g�̃|�C���^

private:

	bool m_bDeath;				// ���S�t���O

	CMove_Object* m_pParent;	// �e�I�u�W�F�N�g
	CObject3D* m_pDebugObj;		// �f�o�b�O�I�u�W�F�N�g�̃|�C���^

};

#endif // !_COLLISION_H_
