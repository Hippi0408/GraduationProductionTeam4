//=============================================================================
//
// drop_weapon.h
// Author : tutida ryousei
//
//=============================================================================
#ifndef _DORP_WAPON_H_
#define _DORP_WAPON_H_

#include"move_object.h"
#include"player.h"

class CObjectX;
class CObject3D;

class CDrop_Weapon : public CMove_Object
{
	static const float PARTS_COLLISION_RADIUS;		// 当たり判定の大きさ
	static const float PARTS_FLOTIONG_POS;			// 落ちてる武器の浮遊位置
public:
	static const int DRAW_DROP_DISTANCE = 7000;		// 敵を表示する距離

	CDrop_Weapon(const PRIORITY priority = PRIORITY_MODEL);
	~CDrop_Weapon();

	// パーツの種類
	enum Drop_Parts_FileName
	{
		// [1]腕
		ARMS_SG01 = 0,				// SG01の腕
		ARMS_SG02,				// SG02の腕
		ARMS_SG03,				// SG03の腕
		ARMS_MAX,				// 腕の最大数

		// [2]脚
		LEG_SG01,				// SG01の脚
		LEG_SG02,				// SG02の脚
		LEG_SG03,				// SG03の脚
		LEG_MAX,				// 脚の最大数

		// 武器
		WEAPON_HAMMER,		// ハンマー
		WEAPON_KNIFE,			// ナイフ
		WEAPON_SCYTHE,			// 鎌
		WEAPON_MAX,				// 武器の最大数

		DROP_PARTS_MAX,
		DROP_PARTS_NONE
	};

	static const char* s_Weapon_FileName[];	// ファイルパス

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Hit(CMove_Object* pHit) override;
	void Pick_Up_Weapon();		// 武器を拾う
	void Parts_Type();			// パーツの部位の設定

	void SetWeapon_Type(int weapon) { m_nWeapon_Type = weapon; }

	static CDrop_Weapon *Create(D3DXVECTOR3 pos, int weapon);

private:

	int m_nWeapon_Type;			// 武器のタイプ
	CObjectX *m_pDrop_Weapon;	// 落ちてる武器の情報
	D3DXVECTOR3 m_Pos;			// 位置
	CObject3D *m_pPick_Up;		// 拾う時の表示
	float m_fRot;				// 角度
	float m_fMove;				// 落下速度
	bool m_bPick_Up;			// 拾える範囲にいるか
	CPlayer::PARTS m_Parts;		// パーツ情報
};

#endif // !_DORP_WAPON_H_
