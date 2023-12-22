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

		WEAPON_SLASH_KNIFE,		// �i�C�t
		WEAPON_SLASH_HAMMER,	// �n���}�[
		WEAPON_SLASH_SCYTHE,	// ��

		WEAPON_MAX				// �ő�l
	};

	// �p�����[�^�[
	struct PARAMETERS
	{
		int m_nPower;					// �З�
		int m_nGravity;					// �d��
		float m_fInterval;				// �U���Ԋu

										//Skill m_skill;					// �X�L���^�C�v
	};


	CWeapon(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CWeapon() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ChangeWeapon(const int type);

	static CWeapon* Create(const D3DXVECTOR3 pos, const int type, CObjectX* parent = nullptr);

private:
	static const char* m_cWeaponFileName[WEAPON_MAX];		// ����̃t�@�C����
	static const PARAMETERS m_WeaponPaeameters[WEAPON_MAX];	// ����̃p�����[�^�[���
};

#endif// _WEAPON_H_