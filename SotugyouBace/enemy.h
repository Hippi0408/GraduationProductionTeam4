//=============================================================================
//
// enemy.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "character.h"

//---------------------------
// クラス宣言
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

	void Hit() override;

private:
};

#endif// _ENEMY_H_