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

class CDrop_Weapon : public CMove_Object
{
public:
	CDrop_Weapon(const PRIORITY priority = PRIORITY_MODEL);
	~CDrop_Weapon();

	// パーツの部位
	enum MODEL
	{
		DROP_BODY = 0,			// [0]胴
		DROP_HIP,				// [1]腰
		DROP_HEAD,				// [2]頭
		DROP_RIGHT_UPPER_ARM,	// [3]右上腕
		DROP_RIGHT_FOREARM,		// [4]右前腕
		DROP_RIGHT_ARM,			// [5]右手
		DROP_LEFT_UPPER_ARM,	// [6]左上腕
		DROP_LEFT_FOREARM,		// [7]左前腕
		DROP_LEFT_ARM,			// [8]左手
		DROP_RIGHT_THIGH,		// [9]右腿
		DROP_RIGHT_SHIN,		// [10]右脛
		DROP_RIGHT_LEG,			// [11]右足
		DROP_LEFT_THIGH,		// [12]左腿
		DROP_LEFT_SHIN,			// [13]左脛
		DROP_LEFT_LEG,			// [14]左足
		DROP_MAX,				// モデルの最大数
	};

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Hit(CMove_Object* pHit) override;

	//void SetPos(D3DXVECTOR3 pos) { m_Pos = pos; }
	void SetFileName(char *xfilename) { m_Weapon_Type.pXFileName = xfilename; }

	static CDrop_Weapon *Creat(D3DXVECTOR3 pos, char *xfilename);

private:
	static const float PARTS_COLLISION_RADIUS;	// ボスの当たり判定の大きさ

	struct Weapon_Type
	{
		MODEL type;
		char *pXFileName;
	};

	Weapon_Type m_Weapon_Type;
	CObjectX *m_pDrop_Weapon;
	D3DXVECTOR3 m_Pos;
};

#endif // !_DORP_WAPON_H_
