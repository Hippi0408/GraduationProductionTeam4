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
	static const float PARTS_COLLISION_RADIUS;		// �����蔻��̑傫��
	static const float PARTS_FLOTIONG_POS;			// �����Ă镐��̕��V�ʒu
public:
	static const int DRAW_DROP_DISTANCE = 7000;		// �G��\�����鋗��

	CDrop_Weapon(const PRIORITY priority = PRIORITY_MODEL);
	~CDrop_Weapon();

	// �p�[�c�̎��
	enum Drop_Parts_FileName
	{
		// [1]�r
		ARMS_SG01 = 0,				// SG01�̘r
		ARMS_SG02,				// SG02�̘r
		ARMS_SG03,				// SG03�̘r
		ARMS_MAX,				// �r�̍ő吔

		// [2]�r
		LEG_SG01,				// SG01�̋r
		LEG_SG02,				// SG02�̋r
		LEG_SG03,				// SG03�̋r
		LEG_MAX,				// �r�̍ő吔

		// ����
		WEAPON_HAMMER,		// �n���}�[
		WEAPON_KNIFE,			// �i�C�t
		WEAPON_SCYTHE,			// ��
		WEAPON_MAX,				// ����̍ő吔

		DROP_PARTS_MAX,
		DROP_PARTS_NONE
	};

	static const char* s_Weapon_FileName[];	// �t�@�C���p�X

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Hit(CMove_Object* pHit) override;
	void Pick_Up_Weapon();		// ������E��
	void Parts_Type();			// �p�[�c�̕��ʂ̐ݒ�

	void SetWeapon_Type(int weapon) { m_nWeapon_Type = weapon; }

	static CDrop_Weapon *Create(D3DXVECTOR3 pos, int weapon);

private:

	int m_nWeapon_Type;			// ����̃^�C�v
	CObjectX *m_pDrop_Weapon;	// �����Ă镐��̏��
	D3DXVECTOR3 m_Pos;			// �ʒu
	CObject3D *m_pPick_Up;		// �E�����̕\��
	float m_fRot;				// �p�x
	float m_fMove;				// �������x
	bool m_bPick_Up;			// �E����͈͂ɂ��邩
	CPlayer::PARTS m_Parts;		// �p�[�c���
};

#endif // !_DORP_WAPON_H_
