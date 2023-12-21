//=============================================================================
//
// weapon_parameter.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _WEAPON_PARAMETER_H_
#define _WEAPON_PARAMETER_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "d3dx9.h"
#include "weapon.h"

//---------------------------
// �N���X�錾
//---------------------------
class CWeapon_Parameter
{

public:
	static const int WEAPON_RARITY = 3;				// �p�[�c�̃��A���e�B

	// �ߐڕ���̑���
	enum MELEE_WEAPON
	{
		MELEE_WEAPON_NONE = 0,		// �f��	(1���)
		MELEE_WEAPON_FIST = 1,		// ��	(4���)
		MELEE_WEAPON_SLASH = 5,		// �a��	(4���)
		MELEE_WEAPON_POKE = 9,		// �h��	(4���)
		MELEE_WEAPON_MAX = 13
	};

	// �ߐڕ���p�����[�^�[
	struct MELEE_WEAPON_PARAMETERS
	{
		int nPower;					// �З�
		int nAttack_Rate;			// �U�����x
		int nGravity;				// �d��
		int nLength;				// �˒�
	};


	CWeapon_Parameter();
	~CWeapon_Parameter();

	HRESULT Init();
	void Uninit();

	void LoadWeaponFile();	// ����̓ǂݍ���

	// �r�p�����[�^�[�̎擾
	MELEE_WEAPON_PARAMETERS GetParameterMeleeWeapon(const int type, const int rearity) { return m_Melee_Weapon[type][rearity]; }

private:

	MELEE_WEAPON_PARAMETERS m_Melee_Weapon[MELEE_WEAPON_MAX][WEAPON_RARITY];	// �ߐڕ���̃p�����[�^�[

};

#endif// _WEAPON_PARAMETER_H_