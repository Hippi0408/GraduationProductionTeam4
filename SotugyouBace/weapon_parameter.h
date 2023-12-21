//=============================================================================
//
// weapon_parameter.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _WEAPON_PARAMETER_H_
#define _WEAPON_PARAMETER_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "d3dx9.h"
#include "weapon.h"

//---------------------------
// クラス宣言
//---------------------------
class CWeapon_Parameter
{

public:
	static const int WEAPON_RARITY = 3;				// パーツのレアリティ

	// 近接武器の属性
	enum MELEE_WEAPON
	{
		MELEE_WEAPON_NONE = 0,		// 素手	(1種類)
		MELEE_WEAPON_FIST = 1,		// 拳	(4種類)
		MELEE_WEAPON_SLASH = 5,		// 斬撃	(4種類)
		MELEE_WEAPON_POKE = 9,		// 刺突	(4種類)
		MELEE_WEAPON_MAX = 13
	};

	// 近接武器パラメーター
	struct MELEE_WEAPON_PARAMETERS
	{
		int nPower;					// 威力
		int nAttack_Rate;			// 攻撃速度
		int nGravity;				// 重量
		int nLength;				// 射程
	};


	CWeapon_Parameter();
	~CWeapon_Parameter();

	HRESULT Init();
	void Uninit();

	void LoadWeaponFile();	// 武器の読み込み

	// 腕パラメーターの取得
	MELEE_WEAPON_PARAMETERS GetParameterMeleeWeapon(const int type, const int rearity) { return m_Melee_Weapon[type][rearity]; }

private:

	MELEE_WEAPON_PARAMETERS m_Melee_Weapon[MELEE_WEAPON_MAX][WEAPON_RARITY];	// 近接武器のパラメーター

};

#endif// _WEAPON_PARAMETER_H_