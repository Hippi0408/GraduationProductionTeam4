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

	// p[cΜΚ
	enum MODEL
	{
		DROP_BODY = 0,			// [0]·
		DROP_HIP,				// [1]
		DROP_HEAD,				// [2]ͺ
		DROP_RIGHT_UPPER_ARM,	// [3]Eγr
		DROP_RIGHT_FOREARM,		// [4]EOr
		DROP_RIGHT_ARM,			// [5]Eθ
		DROP_LEFT_UPPER_ARM,	// [6]Άγr
		DROP_LEFT_FOREARM,		// [7]ΆOr
		DROP_LEFT_ARM,			// [8]Άθ
		DROP_RIGHT_THIGH,		// [9]EΪ
		DROP_RIGHT_SHIN,		// [10]Eγψ
		DROP_RIGHT_LEG,			// [11]E«
		DROP_LEFT_THIGH,		// [12]ΆΪ
		DROP_LEFT_SHIN,			// [13]Άγψ
		DROP_LEFT_LEG,			// [14]Ά«
		DROP_MAX,				// fΜΕε
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
	static const float PARTS_COLLISION_RADIUS;	// {XΜ½θ»θΜε«³

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
