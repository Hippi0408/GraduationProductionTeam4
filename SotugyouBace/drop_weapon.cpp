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
#include"debugProc.h"
#include"application.h"
#include"player_manager.h"

const float CDrop_Weapon::PARTS_COLLISION_RADIUS = 150.0f;	// �����Ă镐��̓����蔻��̑傫��

//=============================================================================
// ��`
//=============================================================================
const char* CDrop_Weapon::s_Weapon_FileName[] =
{
	// ����
	"Data/model/Weapon/hammer.x",
	"Data/model/Weapon/knife.x",
	"Data/model/Weapon/scythe.x",
	nullptr,

	// [0]��
	"Data/model/SG_01/SG01_Body.x",
	nullptr,

	// [1]��
	"Data/model/SG_01/SG01_Hip.x",
	nullptr,

	// [2]��
	"Data/model/SG_01/SG01_Head.x",
	nullptr,

	// [3]�E��r
	"Data/model/SG_01/SG01_Shoulder.x",
	nullptr,

	// [4]�E�O�r
	"Data/model/SG_01/SG01_Arm.x",
	nullptr,

	// [5]�E��
	"Data/model/SG_01/SG01_RightHand.x",
	nullptr,

	// [6]����r
	"Data/model/SG_01/SG01_Shoulder.x",
	nullptr,

	// [7]���O�r
	"Data/model/SG_01/SG01_Arm.x",
	nullptr,

	// [8]����
	"Data/model/SG_01/SG01_LiftHand.x",
	nullptr,

	// [9]�E��
	"Data/model/SG_01/SG01_Thighs.x",
	nullptr,

	// [10]�E��
	"Data/model/SG_01/SG01_Leg.x",
	nullptr,

	// [11]�E��
	"Data/model/SG_01/SG01_Foot.x",
	nullptr,

	// [12]����
	"Data/model/SG_01/SG01_Thighs.x",
	nullptr,

	// [13]����
	"Data/model/SG_01/SG01_Leg.x",
	nullptr,

	// [14]����
	"Data/model/SG_01/SG01_Foot.x",
	nullptr,
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
	SetCollision({ 1.0f, 1.0f, 1.0f, 1.0f });

	// �����Ă镐��̐���
	m_pDrop_Weapon = CObjectX::Create(GetPos(), { 0.0f,0.0f,0.0f }, nullptr, s_Weapon_FileName[m_nWeapon_Type]);
	m_pDrop_Weapon->SetSize({ 3.0f,3.0f,3.0f });

	// �p�[�c�̕��ʂ̐ݒ�
	Parts_Type();

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
	if (m_pDrop_Weapon != nullptr)
	{
		m_pDrop_Weapon->Uninit();
		m_pDrop_Weapon = nullptr;
	}

	if (m_pPick_Up != nullptr)
	{
		m_pPick_Up->Uninit();
		m_pPick_Up = nullptr;
	}

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
			m_fMove = 0.0f;
			// �����蔻��̈ʒu
			SetPos({ GetPos().x, MeshY, GetPos().z });
			// ���f���̈ʒu
			m_pDrop_Weapon->SetPos({ GetPos().x, MeshY + 100, GetPos().z });
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
			SetPos({ Weapon_Pos.x, Weapon_Pos.y - 100, Weapon_Pos.z });
			// ���f���̈ʒu
			m_pDrop_Weapon->SetPos({ Weapon_Pos.x, Weapon_Pos.y, Weapon_Pos.z });
		}
	}

	// ��]���x
	m_fRot += 0.03f;
	// �p�x�̐ݒ�
	m_pDrop_Weapon->SetRot({ 0.4f,m_fRot,0.0f });

	CPlayerManager *pPlayerManager = CApplication::GetPlayerManager();
	CPlayer *pPlayer = nullptr;

	if (pPlayerManager != nullptr)
		pPlayer = pPlayerManager->GetPlayer(0);

	D3DXVECTOR3 Player_Pos = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 Mob_Pos = { 0.0f,0.0f,0.0f };

	if (pPlayer != nullptr)
	{
		// �ʒu�̎擾
		Player_Pos = pPlayer->GetPos();
		Mob_Pos = GetPos();
	}

	// �v���C���[���痎���Ă�p�[�c�̋���
	D3DXVECTOR3 Vec = Player_Pos - Mob_Pos;

	// �����̎Z�o
	float fDistance = sqrtf(Vec.x * Vec.x + Vec.z * Vec.z);

	// ����7000�ȏ�
	if (fDistance > DRAW_DROP_DISTANCE)
		m_pDrop_Weapon->SetDrawFlag(false);
	else
		m_pDrop_Weapon->SetDrawFlag(true);

	// ������E��
	Pick_Up_Weapon();

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
			}
		}
		else
			// �F�̐ݒ�
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,0.0f });
	}
}

//=============================================================================
// �p�[�c�̕��ʂ̐ݒ�
//=============================================================================
void CDrop_Weapon::Parts_Type()
{
	if (WEAPON_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_BODY;
	else if(BODY_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_BODY;
	else if (HIP_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_HIP;
	else if (HEAD_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_HEAD;
	else if (RIGHT_UPPER_ARM_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_RIGHT_UPPER_ARM;
	else if (RIGHT_FOREARM_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_RIGHT_FOREARM;
	else if (RIGHT_ARM_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_RIGHT_ARM;
	else if (LEFT_UPPER_ARM_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_LEFT_UPPER_ARM;
	else if (LEFT_FOREARM_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_LEFT_FOREARM;
	else if (LEFT_ARM_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_LEFT_ARM;
	else if (RIGHT_THIGH_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_RIGHT_THIGH;
	else if (RIGHT_SHIN_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_RIGHT_SHIN;
	else if (RIGHT_LEG_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_RIGHT_LEG;
	else if (LEFT_THIGH_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_LEFT_THIGH;
	else if (LEFT_SHIN_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_LEFT_SHIN;
	else if (LEFT_LEG_MAX > m_nWeapon_Type)
	m_Model = CPlayer::MODEL_LEFT_LEG;
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

