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

	CEnemy();
	virtual ~CEnemy() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Hit(CMove_Object* pHit) override;

	virtual void Destroy() override;			// �j�󏈗�

private:
};

#endif// _ENEMY_H_