//=============================================================================
//
// drop_weapon.p
// Author : tutida ryousei
//
//=============================================================================
#include"drop_weapon.h"
#include"objectX.h"
#include"meshfield.h"
#include"game.h"
#include"input.h"
#include"object3D.h"

const float CDrop_Weapon::PARTS_COLLISION_RADIUS = 150.0f;	// �����Ă镐��̓����蔻��̑傫��

//=============================================================================
// ��`
//=============================================================================
const char* CDrop_Weapon::s_Weapon_FileName[] =
{// ���탂�f���̃p�X
	"Data/model/Weapon/hammer.x",
	"Data/model/Weapon/knife.x",
	"Data/model/Weapon/scythe.x"
};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CDrop_Weapon::CDrop_Weapon(const PRIORITY priority) : CMove_Object(priority)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CDrop_Weapon::~CDrop_Weapon()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CDrop_Weapon::Init()
{
	SetRadius(PARTS_COLLISION_RADIUS);
	SetCenterPos({ 0.0f,100.0f,0.0f });

	// �����蔻��̐���
	SetCollision();

	// �����Ă镐��̐���
	m_pDrop_Weapon = CObjectX::Create(GetCenterPos(), { 0.0f,0.0f,0.0f }, nullptr, s_Weapon_FileName[m_nWeapon_Type]);
	m_pDrop_Weapon->SetSize({ 3.0f,3.0f,3.0f });

	m_bPick_Up = false;
	m_fMove = 0.0f;

	CMove_Object::Init();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CDrop_Weapon::Uninit()
{
	CMove_Object::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CDrop_Weapon::Update()
{
	CMeshField *pMesh = CGame::GetMeshField();

	if (pMesh != nullptr)
	{
		// ���b�V���t�B�[���h�Ƃ̓����蔻��
		float MeshY = pMesh->MeshCollision(GetPos());

		// ���b�V���t�B�[���h�ɏ���Ă�
		if (pMesh->GetHit())
		{
			// �����蔻��̈ʒu
			SetPos({ GetCenterPos().x, MeshY, GetCenterPos().z });
			// ���f���̈ʒu
			m_pDrop_Weapon->SetPos({ GetCenterPos().x, GetCenterPos().y + MeshY, GetCenterPos().z });
		}
		else
		{
			// ���f���̈ʒu
			D3DXVECTOR3 Weapon_Pos = m_pDrop_Weapon->GetPos();
			// �������x
			m_fMove += 0.5f;
			// Y���W�̈ړ�
			Weapon_Pos.y -= m_fMove;
			
			// �����蔻��̈ʒu
			SetPos(Weapon_Pos);
			// ���f���̈ʒu
			m_pDrop_Weapon->SetPos(Weapon_Pos);
		}
	}

	// ������E��
	Pick_Up_Weapon();

	// ��]���x
	m_fRot += 0.03f;
	// �p�x�̐ݒ�
	m_pDrop_Weapon->SetRot({ 0.4f,m_fRot,0.0f });

	m_bPick_Up = false;
}

//=============================================================================
// �`�揈��
//=============================================================================
void CDrop_Weapon::Draw()
{
}

//=============================================================================
// �q�b�g
//=============================================================================
void CDrop_Weapon::Hit(CMove_Object* pHit)
{
	// �v���C���[���̏ꍇ
	if (pHit != nullptr && pHit->GetPlayerSide())
	{
		TAG tag = pHit->GetTag();

		switch (tag)
		{
		case TAG_CHARACTER:
			m_bPick_Up = true;
			break;
		case TAG_BULLET:
			break;
		default:
			break;
		}
	}
}

//=============================================================================
// ������E��
//=============================================================================
void CDrop_Weapon::Pick_Up_Weapon()
{
	//���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	if (m_pPick_Up == nullptr)
		m_pPick_Up = CObject3D::Create({ GetCenterPos().x,GetCenterPos().y + 200.0f,GetCenterPos().z }, { 70.0f,70.0f }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,1.0f }, true);

	if(m_pPick_Up != nullptr)
	{
		if (m_bPick_Up)
		{
			// �F�̐ݒ�
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,1.0f });

			m_pPick_Up->SetPos({ GetCenterPos().x,GetCenterPos().y + 200.0f,GetCenterPos().z });

			// �E��
			if (pInput->Trigger(DIK_E))
			{
				// �I������
				Uninit();
				m_pDrop_Weapon->Uninit();
				m_pPick_Up->Uninit();
			}
		}
		else
			// �F�̐ݒ�
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,0.0f });
	}
}

//=============================================================================
// ��������
//=============================================================================
CDrop_Weapon *CDrop_Weapon::Creat(D3DXVECTOR3 pos, int weapon)
{
	CDrop_Weapon *pDrop_Weapon = nullptr;

	pDrop_Weapon = new CDrop_Weapon(PRIORITY_MODEL);

	if (pDrop_Weapon != nullptr)
	{
		pDrop_Weapon->SetPos(pos);
		pDrop_Weapon->SetWeapon_Type(weapon);
		pDrop_Weapon->Init();
	}

	return pDrop_Weapon;
}