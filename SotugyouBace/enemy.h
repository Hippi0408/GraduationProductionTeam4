//=============================================================================
//
// enemy.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "character.h"

//---------------------------
// �N���X�錾
//---------------------------
class CEnemy : public CCharacter
{

public:
	// �G�L�����̎��
	enum ENEMY_TYPE
	{
		ENEMY_TYPE_MOB = 0,	// ���u�L����
		ENEMY_TYPE_BOSS		// �{�X�L����
	};

	CEnemy();
	virtual ~CEnemy() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Hit(CMove_Object* pHit) override;

	virtual void Destroy() override;			// �j�󏈗�

	void SetEnemyType(ENEMY_TYPE type) { m_type = type; }	// �G�L�����̎�ނ�ݒ�

	ENEMY_TYPE GetEnemyType() { return m_type; }			// �G�L�����̎�ނ��擾

private:

	ENEMY_TYPE m_type;						// �G�L�����̎��
};

#endif// _ENEMY_H_