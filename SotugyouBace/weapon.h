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
		WEAPON_KNUCKLE = 0,		// 素手

		WEAPON_SLASH_KNIFE,		// ナイフ
		WEAPON_SLASH_HAMMER,	// ハンマー
		WEAPON_SLASH_SCYTHE,	// 鎌

		WEAPON_MAX				// 最大値
	};

	// パラメーター
	struct PARAMETERS
	{
		int m_nPower;					// 威力
		int m_nGravity;					// 重量
		float m_fInterval;				// 攻撃間隔

										//Skill m_skill;					// スキルタイプ
	};


	CWeapon(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CWeapon() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ChangeWeapon(const int type);

	static CWeapon* Create(const D3DXVECTOR3 pos, const int type, CObjectX* parent = nullptr);

private:
	static const char* m_cWeaponFileName[WEAPON_MAX];		// 武器のファイル名
	static const PARAMETERS m_WeaponPaeameters[WEAPON_MAX];	// 武器のパラメーター情報
};

#endif// _WEAPON_H_