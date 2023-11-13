//=============================================================================
//
// weapon.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _WEAPON_H_
#define _WEAPON_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "objectX.h"
#include "motion.h"
#include "parts_file.h"

//---------------------------
// クラス宣言
//---------------------------
class CWeapon : public CObjectX
{
public:

	CWeapon(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CWeapon() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CWeapon* Create(const D3DXVECTOR3 pos, const int partsIndex, CObjectX* parent = nullptr);

private:

};

#endif// _PARTS_H_