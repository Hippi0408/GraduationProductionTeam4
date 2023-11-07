//=============================================================================
//
// drop_weapon.h
// Author : tutida ryousei
//
//=============================================================================
#ifndef _DORP_WAPON_H_
#define _DORP_WAPON_H_

#include"move_object.h"

class CObjectX;
class CObject3D;

class CDrop_Weapon : public CMove_Object
{
public:
	CDrop_Weapon(const PRIORITY priority = PRIORITY_MODEL);
	~CDrop_Weapon();

	// パーツの種類
	enum Weapon_FileName
	{
		WEAPON_HAMMER = 0,		// ハンマー
		WEAPON_KNIFE,			// ナイフ
		WEAPON_SCYTHE,			// 鎌
		WEAPON_MAX,
		WEAPON_NONE
	};
	static const char* s_Weapon_FileName[];	// ファイルパス

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Hit(CMove_Object* pHit) override;
	void Pick_Up_Weapon();		// 武器を拾う

	void SetWeapon_Type(int weapon) { m_nWeapon_Type = weapon; }

	static CDrop_Weapon *Creat(D3DXVECTOR3 pos, int weapon);

private:
	static const float PARTS_COLLISION_RADIUS;	// 当たり判定の大きさ

	int m_nWeapon_Type;			// 武器のタイプ
	CObjectX *m_pDrop_Weapon;	// 落ちてる武器の情報
	D3DXVECTOR3 m_Pos;			// 位置
	CObject3D *m_pPick_Up;		// 拾う時の表示
	float m_fRot;				// 角度
	float m_fMove;				// 落下速度
	bool m_bPick_Up;			// 拾える範囲にいるか
};

#endif // !_DORP_WAPON_H_
