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
	"Data/model/Weapon/knife.x",
	"Data/model/Weapon/hammer.x",
	"Data/model/Weapon/scythe.x",
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
	SetModel(CApplication::GetModel()->ReadObject(m_cWeaponFileName[m_nWeaponType = type]));
}

//============================================================================
// ��������
//============================================================================
CWeapon* CWeapon::Create(const D3DXVECTOR3 pos, int type, CObjectX* parent)
{
	CWeapon* pParts = new CWeapon;

	if (FAILED(pParts->Init()))
	{
		return nullptr;
	}

	pParts->SetPos(pos);
	pParts->SetType(type);
	pParts->SetParent(parent);

	return pParts;
}
