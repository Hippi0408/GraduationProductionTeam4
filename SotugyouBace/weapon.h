//=============================================================================
//
// weapon.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _WEAPON_H_
#define _WEAPON_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "objectX.h"

//---------------------------
// �N���X�錾
//---------------------------
class CWeapon : public CObjectX
{
public:

	enum WEAPON_TYPE
	{
		WEAPON_KNUCKLE = 0,		// �f��

		MELEE_WEAPON_FIST_KNUCKLE,			// �i�b�N��
		MELEE_WEAPON_FIST_BUNKER,			// �p�C���o���J�[
		MELEE_WEAPON_FIST_BRAND_MARKERS,	// �u�����h�}�[�J�[
		MELEE_WEAPON_FIST_STUN_BATON,		// �X�^���o�g��

		MELEE_WEAPON_SLASH_SAMURAI_SWORD,	// ����
		MELEE_WEAPON_SLASH_HAMMER,			// �n���}�[
		MELEE_WEAPON_SLASH_BEAM_SABER,		// �r�[���T�[�x��
		MELEE_WEAPON_SLASH_BASTARD_SWORD,	// �o�X�^�[�\�[�h

		MELEE_WEAPON_STABBING_LANCE,		// �����X
		MELEE_WEAPON_STABBING_RAPIER,		// ���C�s�A
		MELEE_WEAPON_STABBING_PARTISAN,		// �p���`�U��
		MELEE_WEAPON_STABBING_BEAM_JAVELIN,	// �r�[���W���x����

		WEAPON_MAX				// �ő�l
	};


	CWeapon(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CWeapon() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ChangeWeapon(const int type);

	static CWeapon* Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const int type, CObjectX* parent = nullptr);

private:
	static const char* m_cWeaponFileName[WEAPON_MAX];		// ����̃t�@�C����
};

#endif// _WEAPON_H_