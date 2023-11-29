//=============================================================================
//
// drop_weapon.h
// Author : tutida ryousei
//
//=============================================================================
#ifndef _DORP_WAPON_H_
#define _DORP_WAPON_H_

#include "objectX.h"
#include "player.h"

class CObject3D;

class CDrop_Weapon : public CObjectX
{
	static const float PARTS_FLOTIONG_POS;			// 落ちてる武器の浮遊位置
public:
	static const int DRAW_DROP_DISTANCE = 7000;		// 武器、パーツを表示する距離
	static const float PARTS_COLLISION_RADIUS;		// 当たり判定の大きさ

	CDrop_Weapon(const PRIORITY priority = PRIORITY_MODEL);
	~CDrop_Weapon();

	// パーツの種類
	enum Drop_Parts_FileName
	{
		// [1]腕
		ARMS_SG01 = 0,			// SG01の腕
		ARMS_SG02,				// SG02の腕
		ARMS_SG03,			// SG03の腕
		ARMS_MAX,				// 腕の最大数

		// [2]脚
		LEG_SG01,				// SG01の脚
		LEG_SG02,				// SG02の脚
		LEG_SG03,				// SG03の脚
		LEG_MAX,				// 脚の最大数

		// 武器
		WEAPON_NONE,			// 素手
		WEAPON_KNIFE,			// ナイフ
		WEAPON_HAMMER,			// ハンマー
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

	void ItemPointerMove();		// アイテムポインターの移動処理
	void Pick_Up_Weapon();		// 武器を拾う
	void Parts_Type();			// パーツの部位の設定
	void FieldCollision();		// 床との当たり判定

	void SetPick_Up(const bool pick_Up) { m_bPick_Up = pick_Up; }

	const D3DXVECTOR3 GetCentePos() { return m_CenterPos; }
	const int GetWeaponType() { return m_nWeapon_Type; }
	CPlayer::PARTS GetPartsType() { return m_Parts; }

	static CDrop_Weapon *Create(D3DXVECTOR3 pos, int weapon);

	static void LoadAllFile();			// 全てのドロップパーツの読み込み

private:

	D3DXVECTOR3 m_CenterPos;	// 中心位置
	int m_nWeapon_Type;			// 武器のタイプ
	CObject3D *m_pPointer;		// アイテムポインターの表示
	CObject3D *m_pPick_Up;		// 拾う時の表示
	float m_fMove;				// 落下速度
	bool m_bPick_Up;			// 拾える範囲にいるか
	CPlayer::PARTS m_Parts;		// パーツ情報
};

#endif // !_DORP_WAPON_H_
