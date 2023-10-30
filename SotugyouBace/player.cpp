//=============================================================================
//
// player.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "player.h"
#include "application.h"
#include "input.h"
#include "bullet.h"
#include "player_manager.h"
#include "game.h"
#include "energy_gauge.h"
#include "tutorial.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// �v���C���[�̓����蔻��̑傫��
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// �v���C���[�̃W�����v��
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CPlayer::CPlayer()
{
	// �v���C���[�̏����l��ݒ�
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(PLAYER_COLLISION_RADIUS);
}

//=====================================
// �f�X�g���N�^
//=====================================
CPlayer::~CPlayer()
{
	// �v���C���[�}�l�[�W���[�̎��g���폜
	CApplication::GetPlayerManager()->PlayerRelease(m_nCharaIndex);
}

//============================================================================
// ����������
//============================================================================
HRESULT CPlayer::Init()
{
	// �v���C���[�̃��f����ǂݍ���
	//LoadFile("Data\\text\\Motion\\motion_player.txt");
	SetParts(PARTS_BODY, "Data\\text\\Motion\\parts\\motion_Body.txt");
	SetParts(PARTS_LEG, "Data\\text\\Motion\\parts\\motion_Leg.txt");
	SetParts(PARTS_ARMS, "Data\\text\\Motion\\parts\\motion_Arms.txt");

	//for (int nCnt = 1; nCnt < (int)GetAllParts().size(); nCnt++)
	//{
	//	GetParts(nCnt)->SetModelParent(GetParts(PARTS_BODY)->GetModelSet(0).pModel);
	//}

	// �^�O�̐ݒ�
	SetTag(TAG_CHARACTER);

	// �v���C���[���ɐݒ�
	SetPlayerSide(true);

	// �����蔻��̐���
	SetCollision();

	CCharacter::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();

	CObject::Release();
}

//============================================================================
// �X�V����
//============================================================================
void CPlayer::Update()
{
	// ���[�V�����ԍ��̐ݒ�
	ChangeMotion();

	// �L�����N�^�[�̍X�V
	CCharacter::Update();
}

//============================================================================
// �`�揈��
//============================================================================
void CPlayer::Draw()
{
	CCharacter::Draw();
}

//============================================================================
// ���[�V�����ύX����
//============================================================================
void CPlayer::ChangeMotion()
{
	// ���n���[�V������ݒ�
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// �p�[�c
		CParts* pParts = GetParts(nCnt);

		// ���n���[�V�������I�������ꍇ
		if (pParts->GetCurrentMotion() == MOTION_LANDING && pParts->GetMotionStop() == true)
		{
			pParts->SetMotion(MOTION_NEUTRAL);
		}
	}
}

//============================================================================
// �v���C���[�̍U������
//============================================================================
void CPlayer::PlayerAttack()
{
	// ���̎擾
	D3DXVECTOR3 pos = GetCenterPos();
	D3DXVECTOR3 rot = GetRot();

	D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };
	pos_vec *= 100.f;
	pos_vec += pos;

	// �e�̐���
	CBullet::Create({pos_vec.x, pos_vec.y, pos_vec.z}, D3DXVECTOR2(60.0f, 60.0f), D3DXVECTOR3(-sinf(rot.y), sinf(rot.x), -cosf(rot.y)), true);
}

//============================================================================
// �v���C���[�̃W�����v����
//============================================================================
void CPlayer::JumpStart()
{
	// �ڒn���Ă���ꍇ�̂�
	if (GetGround() == true)
	{
		// �W�����v���[�V������ݒ�
		GetParts(PARTS_LEG)->SetMotion(MOTION_JUMP);

		// ������Ԃɂ���
		SetGround(false);

		// ��ɏ㏸����
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// �v���C���[�̃W�����v�u�[�X�g����
//============================================================================
void CPlayer::JumpBoost()
{
	// �G�l���M�[�Q�[�W�̎擾
	CEnergy_Gauge* pGauge = nullptr;

	if (CApplication::GetModeType() == CApplication::MODE_GAME)
		pGauge = CGame::GetEnergy_Gauge();
	else if (CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
		pGauge = CTutorial::GetEnergy_Gauge();

	if (pGauge != nullptr)
	{
		// �󒆂ɂ���ꍇ�A�G�l���M�[���c���Ă���ꍇ
		if (!GetGround() && !pGauge->GetConsumption())
		{
			// �㏸����
			AddMove({ 0.0f, 0.5f, 0.0f });

			// �G�l���M�[�������
			pGauge->Consumption_Gauge();
		}
	}
}

//============================================================================
// �v���C���[�̒��n����
//============================================================================
void CPlayer::Landing(const D3DXVECTOR3 pos)
{
	// ���n���[�V������ݒ�
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		GetParts(nCnt)->SetMotion(MOTION_LANDING);
	}

	// �L�����N�^�[�̒��n����
	CCharacter::Landing(pos);
}

//============================================================================
// ��e����
//============================================================================
void CPlayer::Hit(CMove_Object* pHit)
{
	// ���g�ł͂Ȃ� ���� �v���C���[���ł͂Ȃ��ꍇ
	if (pHit != nullptr && GetPlayerSide() != pHit->GetPlayerSide())
	{
		TAG tag = pHit->GetTag();

		switch (tag)
		{
		case TAG_CHARACTER:
			break;
		case TAG_BULLET:
			// �e�̃_���[�W��Ԃ�
			Damage(pHit->GetPower());
			break;
		default:
			break;
		}
	}
}