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

		MELEE_WEAPON_FIST_KNUCKLE,			// ナックル
		MELEE_WEAPON_FIST_BUNKER,			// パイルバンカー
		MELEE_WEAPON_FIST_BRAND_MARKERS,	// ブランドマーカー
		MELEE_WEAPON_FIST_STUN_BATON,		// スタンバトン

		MELEE_WEAPON_SLASH_SAMURAI_SWORD,	// 太刀
		MELEE_WEAPON_SLASH_HAMMER,			// ハンマー
		MELEE_WEAPON_SLASH_BEAM_SABER,		// ビームサーベル
		MELEE_WEAPON_SLASH_BASTARD_SWORD,	// バスターソード

		MELEE_WEAPON_STABBING_LANCE,		// ランス
		MELEE_WEAPON_STABBING_RAPIER,		// レイピア
		MELEE_WEAPON_STABBING_PARTISAN,		// パルチザン
		MELEE_WEAPON_STABBING_BEAM_JAVELIN,	// ビームジャベリン

		WEAPON_MAX				// 最大値
	};


	CWeapon(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CWeapon() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ChangeWeapon(const int type);

	static CWeapon* Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const int type, CObjectX* parent = nullptr);

private:
	static const char* m_cWeaponFileName[WEAPON_MAX];		// 武器のファイル名
};

#endif// _WEAPON_H_