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

//---------------------------
// クラス宣言
//---------------------------
class CWeapon : public CObjectX
{
public:

	enum WEAPON_TYPE
	{
		WEAPON_NONE = 0,	// 素手
		WEAPON_KNIFE,		// ナイフ
		WEAPON_HAMMER,		// ハンマー
		WEAPON_SCYTHE,		// 鎌
		WEAPON_MAX			// 最大値
	};

	CWeapon(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CWeapon() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ChangeWeapon(const int type);

	static CWeapon* Create(const D3DXVECTOR3 pos, const int type, CObjectX* parent = nullptr);

	void SetType(const int type) { m_nWeaponType = type; }

private:
	static const char* m_cWeaponFileName[WEAPON_MAX];	// ファイル名

	int m_nWeaponType;	// 武器の種類
};

#endif// _PARTS_H_