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
	static const float PARTS_FLOTIONG_POS;			// �����Ă镐��̕��V�ʒu
public:
	static const int DRAW_DROP_DISTANCE = 7000;		// ����A�p�[�c��\�����鋗��
	static const float PARTS_COLLISION_RADIUS;		// �����蔻��̑傫��

	CDrop_Weapon(const PRIORITY priority = PRIORITY_MODEL);
	~CDrop_Weapon();

	// �p�[�c�̎��
	enum Drop_Parts_FileName
	{
		// [1]�r
		ARMS_SG01 = 0,			// SG01�̘r
		ARMS_SG02,				// SG02�̘r
		ARMS_SG03,			// SG03�̘r
		ARMS_MAX,				// �r�̍ő吔

		// [2]�r
		LEG_SG01,				// SG01�̋r
		LEG_SG02,				// SG02�̋r
		LEG_SG03,				// SG03�̋r
		LEG_MAX,				// �r�̍ő吔

		// ����
		WEAPON_NONE,			// �f��
		WEAPON_KNIFE,			// �i�C�t
		WEAPON_HAMMER,			// �n���}�[
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

	void ItemPointerMove();		// �A�C�e���|�C���^�[�̈ړ�����
	void Pick_Up_Weapon();		// ������E��
	void Parts_Type();			// �p�[�c�̕��ʂ̐ݒ�
	void FieldCollision();		// ���Ƃ̓����蔻��

	void SetPick_Up(const bool pick_Up) { m_bPick_Up = pick_Up; }

	const D3DXVECTOR3 GetCentePos() { return m_CenterPos; }
	const int GetWeaponType() { return m_nWeapon_Type; }
	CPlayer::PARTS GetPartsType() { return m_Parts; }

	static CDrop_Weapon *Create(D3DXVECTOR3 pos, int weapon);

	static void LoadAllFile();			// �S�Ẵh���b�v�p�[�c�̓ǂݍ���

private:

	D3DXVECTOR3 m_CenterPos;	// ���S�ʒu
	int m_nWeapon_Type;			// ����̃^�C�v
	CObject3D *m_pPointer;		// �A�C�e���|�C���^�[�̕\��
	CObject3D *m_pPick_Up;		// �E�����̕\��
	float m_fMove;				// �������x
	bool m_bPick_Up;			// �E����͈͂ɂ��邩
	CPlayer::PARTS m_Parts;		// �p�[�c���
};

#endif // !_DORP_WAPON_H_
