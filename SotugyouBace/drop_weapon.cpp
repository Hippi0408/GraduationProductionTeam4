//=============================================================================
//
// drop_weapon.p
// Author : tutida ryousei
//
//=============================================================================
#include"drop_weapon.h"
#include"drop_manager.h"
#include"objectX.h"
#include"meshfield.h"
#include"tutorial.h"
#include"game.h"
#include"input.h"
#include"object3D.h"
#include"debugProc.h"
#include"application.h"
#include"player_manager.h"
#include"model.h"


const float CDrop_Weapon::PARTS_COLLISION_RADIUS = 150.0f;	// �����Ă镐��̓����蔻��̑傫��
const float CDrop_Weapon::PARTS_FLOTIONG_POS = 100.0f;		// �����Ă镐��̕��V�ʒu

//=============================================================================
// ��`
//=============================================================================
const char* CDrop_Weapon::s_Weapon_FileName[] =
{
	// �r
	"Data/model/DropParts/SG_01/SG_01_DropArm.x",
	"Data/model/DropParts/SG_02/SG_02_DropArm.x",
	"Data/model/DropParts/SG_03/SG_03_DropArm.x",
	nullptr,

	// �r
	"Data/model/DropParts/SG_01/SG_01_DropLeg.x",
	"Data/model/DropParts/SG_02/SG_02_DropLeg.x",
	"Data/model/DropParts/SG_03/SG_03_DropLeg.x",
	nullptr,

	// ����
	"Data/model/SG_01/DummyParent.x",
	"Data/model/Weapon/knife.x",
	"Data/model/Weapon/hammer.x",
	"Data/model/Weapon/scythe.x",
	nullptr,
};

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CDrop_Weapon::CDrop_Weapon(const PRIORITY priority) : CObjectX(priority)
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �������Ɏ��g�̃|�C���^��G�L�����}�l�[�W���[�ɐݒ�
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CTutorial::GetDropManager()->SetDrop(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CGame::GetDropManager()->SetDrop(this);
	}
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CDrop_Weapon::~CDrop_Weapon()
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �}�l�[�W���[���g�p���̏ꍇ�A������Ɏ��g�̃|�C���^��z�񂩂珜�O����
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CDropManager* pManager = CTutorial::GetDropManager();
		if (pManager != nullptr) pManager->DestroyDrop(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CDropManager* pManager = CGame::GetDropManager();
		if (pManager != nullptr) pManager->DestroyDrop(this);
	}
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CDrop_Weapon::Init()
{
	m_CenterPos = { 0.0f,PARTS_FLOTIONG_POS,0.0f };

	// �p�x�̐ݒ�
	SetRot({ 0.4f,0.0f,0.0f });

	// �����Ă镐��̐���
	//m_pDrop_Weapon->SetSize({ 3.0f,3.0f,3.0f });

	// �p�[�c�̕��ʂ̐ݒ�
	Parts_Type();

	m_bPick_Up = false;
	m_fMove = 0.0f;

	D3DXVECTOR3 ModelPos = GetPos() + m_CenterPos;

	// �s�b�N�A�b�vUI�̐���
	m_pPick_Up = CObject3D::Create({ ModelPos.x, ModelPos.y + 200.0f, ModelPos.z }, { 70.0f,70.0f }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,1.0f }, true);
	m_pPick_Up->SetDrawFlag(false);

	CObjectX::Init();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CDrop_Weapon::Uninit()
{
	if (m_pPick_Up != nullptr)
	{
		m_pPick_Up->Uninit();
		m_pPick_Up = nullptr;
	}

	CObjectX::Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void CDrop_Weapon::Update()
{
	CObjectX::Update();

	// ���Ƃ̓����蔻��
	FieldCollision();

	// �p�x�̉��Z
	AddRot({ 0.0f,0.03f,0.0f });

	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	CPlayer* pPlayer = nullptr;

	// ���[�h���Ƀv���C���[��ǂݍ���
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pPlayer = CTutorial::GetPlayerManager()->GetPlayer(0);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pPlayer = CGame::GetPlayerManager()->GetPlayer(0);
	}

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
		SetDrawFlag(false);
	else
		SetDrawFlag(true);

	// ������E��
	Pick_Up_Weapon();

	// �s�b�N�A�b�v��Ԃ����Z�b�g����
	m_bPick_Up = false;
}

//=============================================================================
// �`�揈��
//=============================================================================
void CDrop_Weapon::Draw()
{
	CObjectX::Draw();
}

//=============================================================================
// ������E��
//=============================================================================
void CDrop_Weapon::Pick_Up_Weapon()
{
	// �s�b�N�A�b�vUI�����݂���ꍇ
	if(m_pPick_Up != nullptr)
	{
		// �`�攻��
		m_pPick_Up->SetDrawFlag(m_bPick_Up);

		// �s�b�N�A�b�v����Ă���ꍇ
		if (m_bPick_Up)
		{
			D3DXVECTOR3 ModelPos = GetPos() + m_CenterPos;

			// �F�̐ݒ�
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,1.0f });

			m_pPick_Up->SetPos({ ModelPos.x, ModelPos.y + 200.0f, ModelPos.z });
		}
		else
		{
			// �F�̐ݒ�
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,0.0f });
		}
	}
}

//=============================================================================
// �p�[�c�̕��ʂ̐ݒ�
//=============================================================================
void CDrop_Weapon::Parts_Type()
{
	if (ARMS_MAX > m_nWeapon_Type)
	m_Parts = CPlayer::PARTS_ARMS;
	else if(LEG_MAX > m_nWeapon_Type)
	m_Parts = CPlayer::PARTS_LEG;
	else if (WEAPON_MAX > m_nWeapon_Type)
	m_Parts = CPlayer::PARTS_WEAPON;
}

//=============================================================================
// ���Ƃ̓����蔻��
//=============================================================================
void CDrop_Weapon::FieldCollision()
{
	CMeshField *pMesh = CGame::GetMeshField();

	if (pMesh != nullptr)
	{
		const D3DXVECTOR3 pos = GetPos();
		const D3DXVECTOR3 rot = GetRot();

		// ���b�V���t�B�[���h�Ƃ̓����蔻��
		float MeshY = pMesh->MeshCollision(pos);

		// ���b�V���t�B�[���h�ɏ���Ă�
		if (pMesh->GetHit())
		{
			m_fMove = 0.0f;
			// ���g�̈ʒu
			SetPos({ pos.x, MeshY, pos.z });
		}
		else
		{
			// ���f���̈ʒu
			D3DXVECTOR3 Weapon_Pos = pos;
			// �������x
			m_fMove += 0.5f;
			// Y���W�̈ړ�
			Weapon_Pos.y -= m_fMove;

			// �����蔻��̈ʒu
			SetPos({ Weapon_Pos.x, Weapon_Pos.y, Weapon_Pos.z });
		}
	}
}

//=============================================================================
// ��������
//=============================================================================
CDrop_Weapon *CDrop_Weapon::Create(D3DXVECTOR3 pos, int weapon)
{
	CDrop_Weapon *pDrop_Weapon = nullptr;

	pDrop_Weapon = new CDrop_Weapon(PRIORITY_MODEL);

	if (pDrop_Weapon != nullptr)
	{
		pDrop_Weapon->SetPos(pos);
		pDrop_Weapon->SetModel(CApplication::GetModel()->ReadObject(s_Weapon_FileName[pDrop_Weapon->m_nWeapon_Type = weapon]));
		pDrop_Weapon->Init();
	}

	return pDrop_Weapon;
}

//==============================================================================================
// �S�Ẵh���b�v�p�[�c�̓ǂݍ���
//==============================================================================================
void CDrop_Weapon::LoadAllFile()
{
	for (int nCnt = 0; nCnt < DROP_PARTS_MAX; nCnt++)
	{
		// ���O�����݂���ꍇ
		if (s_Weapon_FileName[nCnt] != nullptr)
		{
			CApplication::GetModel()->ReadObject(s_Weapon_FileName[nCnt]);
		}
	}
}