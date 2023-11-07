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

	// �p�[�c�̎��
	enum Weapon_FileName
	{
		WEAPON_HAMMER = 0,		// �n���}�[
		WEAPON_KNIFE,			// �i�C�t
		WEAPON_SCYTHE,			// ��
		WEAPON_MAX,
		WEAPON_NONE
	};
	static const char* s_Weapon_FileName[];	// �t�@�C���p�X

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Hit(CMove_Object* pHit) override;
	void Pick_Up_Weapon();		// ������E��

	void SetWeapon_Type(int weapon) { m_nWeapon_Type = weapon; }

	static CDrop_Weapon *Creat(D3DXVECTOR3 pos, int weapon);

private:
	static const float PARTS_COLLISION_RADIUS;	// �����蔻��̑傫��

	int m_nWeapon_Type;			// ����̃^�C�v
	CObjectX *m_pDrop_Weapon;	// �����Ă镐��̏��
	D3DXVECTOR3 m_Pos;			// �ʒu
	CObject3D *m_pPick_Up;		// �E�����̕\��
	float m_fRot;				// �p�x
	float m_fMove;				// �������x
	bool m_bPick_Up;			// �E����͈͂ɂ��邩
};

#endif // !_DORP_WAPON_H_
