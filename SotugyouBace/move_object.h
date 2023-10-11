//==============================================================================================
//
// �����I�u�W�F�N�g�@�@�@move_object.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _MOVE_OBJECT_H_
#define	_MOVE_OBJECT_H_

#include"object.h"

class CCollision;

class CMove_Object : public CObject
{
public:
	CMove_Object(const PRIORITY priority);
	~CMove_Object();

	virtual HRESULT Init();
	virtual void Uninit();

	virtual void Hit() = 0;

	void AddPos(const D3DXVECTOR3 pos) { m_pos += pos; }			// �ʒu�̉��Z

	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }				// �ʒu�̐ݒ�
	void SetRadius(const float radius) { m_fRadius = radius; }		// ���a�̐ݒ�

	D3DXVECTOR3 GetPos() { return m_pos; }		// �ʒu�̎擾
	float GetRadius() { return m_fRadius; }		// ���a�̎擾

private:
	D3DXVECTOR3 m_pos;			// �ʒu
	float m_fRadius;			// ���a
	CCollision* m_pCollision;	// �����蔻��̏��
};

#endif // !_MOVE_OBJECT_H_
