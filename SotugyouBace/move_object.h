//==============================================================================================
//
// �����I�u�W�F�N�g�@�@�@move_object.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _MOVE_OBJECT_H_
#define	_MOVE_OBJECT_H_

#include"object.h"
#include"collision.h"

class CMove_Object : public CObject
{
public:
	enum OBJ_TYPE
	{
		OBJ_TYPE_NONE = 0,	// �^�C�v����
		OBJ_TYPE_PLAYER,	// �v���C���[
		OBJ_TYPE_ENEMY,		// �G�L����
		OBJ_TYPE_BULLET,	// �e
		OBJ_TYPE_MAX,		// �ő吔
	};

	CMove_Object(const PRIORITY priority);
	~CMove_Object();

	virtual HRESULT Init();
	virtual void Uninit();

	virtual void Hit() = 0;

	void AddPos(const D3DXVECTOR3 pos) { m_pos += pos; }				// �ʒu�̉��Z

	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }					// �ʒu�̐ݒ�
	void SetRadius(const float radius) { m_fRadius = radius; }			// ���a�̐ݒ�
	void SetType(const OBJ_TYPE type) { m_type = type; }				// ��ނ̐ݒ�
	void SetCollision() { m_pCollision = CCollision::Create(this); }	// �����蔻��̐���

	D3DXVECTOR3 GetPos() { return m_pos; }		// �ʒu�̎擾
	float GetRadius() { return m_fRadius; }		// ���a�̎擾
	OBJ_TYPE GetType() { return m_type; }		// ��ނ̎擾

private:
	D3DXVECTOR3 m_pos;			// �ʒu
	float m_fRadius;			// ���a
	CCollision* m_pCollision;	// �����蔻��̏��
	OBJ_TYPE m_type = OBJ_TYPE_NONE;	// �I�u�W�F�N�g�̎��
};

#endif // !_MOVE_OBJECT_H_
