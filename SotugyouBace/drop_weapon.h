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
public:
	CDrop_Weapon(const PRIORITY priority = PRIORITY_MODEL);
	~CDrop_Weapon();

	// パーツの種類
	enum Drop_Parts_FileName
	{
		// 武器
		WEAPON_HAMMER = 0,		// ハンマー
		WEAPON_KNIFE,			// ナイフ
		WEAPON_SCYTHE,			// 鎌
		WEAPON_MAX,				// 武器の最大数

		// [0]胴
		BODY_SG01,
		BODY_MAX,				// 胴の最大数

		// [1]腰
		HIP_SG01,
		HIP_MAX,				// 腰の最大数

		// [2]頭
		HEAD_SG01,
		HEAD_MAX,				// 頭の最大数

		// [3]右上腕
		RIGHT_UPPER_ARM_SG01,
		RIGHT_UPPER_ARM_MAX,	// 右上腕の最大数

		// [4]右前腕
		RIGHT_FOREARM_SG01,
		RIGHT_FOREARM_MAX,		// 右前腕の最大数

		// [5]右手
		RIGHT_ARM_SG01,
		RIGHT_ARM_MAX,			// 右手の最大数

		// [6]左上腕
		LEFT_UPPER_ARM_SG01,
		LEFT_UPPER_ARM_MAX,		// 左上腕の最大数

		// [7]左前腕
		LEFT_FOREARM_SG01,
		LEFT_FOREARM_MAX,		// 左前腕の最大数

		// [8]左手
		LEFT_ARM_SG01,
		LEFT_ARM_MAX,			// 左手の最大数

		// [9]右腿
		RIGHT_THIGH_SG01,
		RIGHT_THIGH_MAX,		// 右腿の最大数

		// [10]右脛
		RIGHT_SHIN_SG01,
		RIGHT_SHIN_MAX,			// 右脛の最大数

		// [11]右足
		RIGHT_LEG_SG01,
		RIGHT_LEG_MAX,			// 右足の最大数

		// [12]左腿
		LEFT_THIGH_SG01,
		LEFT_THIGH_MAX,			// 左腿の最大数

		// [13]左脛
		LEFT_SHIN_SG01,
		LEFT_SHIN_MAX,			// 左脛の最大数

		// [14]左足
		LEFT_LEG_SG01,
		LEFT_LEG_MAX,			// 左足の最大数

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
	CPlayer::MODEL m_Model;
};

#endif // !_DORP_WAPON_H_
