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

	// �p�[�c�̎��
	enum Drop_Parts_FileName
	{
		// ����
		WEAPON_HAMMER = 0,		// �n���}�[
		WEAPON_KNIFE,			// �i�C�t
		WEAPON_SCYTHE,			// ��
		WEAPON_MAX,				// ����̍ő吔

		// [0]��
		BODY_SG01,
		BODY_MAX,				// ���̍ő吔

		// [1]��
		HIP_SG01,
		HIP_MAX,				// ���̍ő吔

		// [2]��
		HEAD_SG01,
		HEAD_MAX,				// ���̍ő吔

		// [3]�E��r
		RIGHT_UPPER_ARM_SG01,
		RIGHT_UPPER_ARM_MAX,	// �E��r�̍ő吔

		// [4]�E�O�r
		RIGHT_FOREARM_SG01,
		RIGHT_FOREARM_MAX,		// �E�O�r�̍ő吔

		// [5]�E��
		RIGHT_ARM_SG01,
		RIGHT_ARM_MAX,			// �E��̍ő吔

		// [6]����r
		LEFT_UPPER_ARM_SG01,
		LEFT_UPPER_ARM_MAX,		// ����r�̍ő吔

		// [7]���O�r
		LEFT_FOREARM_SG01,
		LEFT_FOREARM_MAX,		// ���O�r�̍ő吔

		// [8]����
		LEFT_ARM_SG01,
		LEFT_ARM_MAX,			// ����̍ő吔

		// [9]�E��
		RIGHT_THIGH_SG01,
		RIGHT_THIGH_MAX,		// �E�ڂ̍ő吔

		// [10]�E��
		RIGHT_SHIN_SG01,
		RIGHT_SHIN_MAX,			// �E���̍ő吔

		// [11]�E��
		RIGHT_LEG_SG01,
		RIGHT_LEG_MAX,			// �E���̍ő吔

		// [12]����
		LEFT_THIGH_SG01,
		LEFT_THIGH_MAX,			// ���ڂ̍ő吔

		// [13]����
		LEFT_SHIN_SG01,
		LEFT_SHIN_MAX,			// �����̍ő吔

		// [14]����
		LEFT_LEG_SG01,
		LEFT_LEG_MAX,			// �����̍ő吔

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
	CPlayer::MODEL m_Model;
};

#endif // !_DORP_WAPON_H_
