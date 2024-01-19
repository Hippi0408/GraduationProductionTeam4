//=============================================================================
//
// weapon.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "weapon.h"
#include "application.h"

const char* CWeapon::m_cWeaponFileName[] =
{
	"Data/model/SG_01/DummyParent.x",

	"Data/model/Weapon/Melee_Weapon/knuckle.x",			// �i�b�N��
	"Data/model/Weapon/Melee_Weapon/pilebunker.x",		// �p�C���o���J�[
	"Data/model/Weapon/Melee_Weapon/brandmarkers.x",	// �u�����h�}�[�J�[
	"Data/model/Weapon/Melee_Weapon/stunbaton.x",		// �X�^���o�g��

	"Data/model/Weapon/Melee_Weapon/samuraiSword.x",		// ����
	"Data/model/Weapon/Melee_Weapon/hammer.x",			// �n���}�[
	"Data/model/Weapon/Melee_Weapon/beamSword.x",		// �r�[���T�[�x��
	"Data/model/Weapon/Melee_Weapon/basterSword.x",		// �o�X�^�[�\�[�h

	"Data/model/Weapon/Melee_Weapon/lance.x",			// �����X
	"Data/model/Weapon/Melee_Weapon/rapier.x",			// ���C�s�A
	"Data/model/Weapon/Melee_Weapon/partisan.x",		// �p���`�U��
	"Data/model/Weapon/Melee_Weapon/beamjavelin.x",		// �r�[���W���x����
};
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CWeapon::CWeapon(const CObject::PRIORITY priority) : CObjectX(priority)
{

}

//=====================================
// �f�X�g���N�^
//=====================================
CWeapon::~CWeapon()
{
}

//============================================================================
// ����������
//============================================================================
HRESULT CWeapon::Init()
{
	CObjectX::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CWeapon::Uninit()
{
	CObjectX::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CWeapon::Update()
{
	CObjectX::Update();
}

//============================================================================
// �`�揈��
//============================================================================
void CWeapon::Draw()
{
	CObjectX::Draw();
}

//============================================================================
// ����̕ύX
//============================================================================
void CWeapon::ChangeWeapon(const int type)
{
	SetModel(CApplication::GetModel()->ReadObject(m_cWeaponFileName[type]));
}

//============================================================================
// ��������
//============================================================================
CWeapon* CWeapon::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, int type, CObjectX* parent)
{
	CWeapon* pParts = new CWeapon;

	if (FAILED(pParts->Init()))
	{
		return nullptr;
	}

	pParts->SetPos(pos);
	pParts->SetRot(rot);
	pParts->ChangeWeapon(type);
	pParts->SetParent(parent);

	return pParts;
}
