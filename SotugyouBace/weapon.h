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
		WEAPON_NONE = 0,	// �f��
		WEAPON_KNIFE,		// �i�C�t
		WEAPON_HAMMER,		// �n���}�[
		WEAPON_SCYTHE,		// ��
		WEAPON_MAX			// �ő�l
	};

	CWeapon(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CWeapon() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void ChangeWeapon(const int type);

	static CWeapon* Create(const D3DXVECTOR3 pos, const int type, CObjectX* parent = nullptr);

	void SetType(const int type) { m_nWeaponType = type; }

private:
	static const char* m_cWeaponFileName[WEAPON_MAX];	// �t�@�C����

	int m_nWeaponType;	// ����̎��
};

#endif// _PARTS_H_