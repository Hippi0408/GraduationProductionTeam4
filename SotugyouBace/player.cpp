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
#include"game.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// �v���C���[�̓����蔻��̑傫��
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// �v���C���[�̃W�����v��
const float CPlayer::MAX_HOVER_POWER = 10.0f;			// �v���C���[�̍ő�z�o�[��
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
	LoadFile("Data\\text\\Motion\\motion_player.txt");

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
	// ���݂̃��[�V����
	const int nCuttentMotion = GetCurrentMotion();

	// ���n���[�V�������I�������ꍇ
	if (nCuttentMotion == MOTION_LANDING && GetMotionStop() == true)
	{
		SetMotion(MOTION_NEUTRAL);
	}

	int nMotion = GetMotion();


	// ���݂̃��[�V��������ς�����ꍇ
	if (nCuttentMotion != nMotion)
	{
		// ���݃��[�V�����̏I������
		switch (nCuttentMotion)
		{
			// �j���[�g����
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
			break;
		case MOTION_JUMP:
			break;
		case MOTION_LANDING:
			break;
		default:
			break;
		}

		// ���݃��[�V�����̊J�n����
		switch (nMotion)
		{
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
			break;
		case MOTION_JUMP:
			break;
		case MOTION_LANDING:
			break;
		default:
			break;
		}

		// �L�����N�^�[�̃��[�V�����ύX����
		CCharacter::ChangeMotion();
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
	CBullet::Create({pos_vec.x, pos_vec.y, pos_vec.z}, D3DXVECTOR2(60.0f, 60.0f), D3DXVECTOR3(-sinf(rot.y), sinf(rot.x), -cosf(rot.y)));
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
		SetMotion(MOTION_JUMP);

		// ������Ԃɂ���
		SetGround(false);

		// ��ɏ㏸����
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// �v���C���[�̒��n����
//============================================================================
void CPlayer::Landing(const D3DXVECTOR3 pos)
{
	// ���n���[�V������ݒ�
	SetMotion(MOTION_LANDING);

	// �L�����N�^�[�̒��n����
	CCharacter::Landing(pos);
}

//============================================================================
// ��e����
//============================================================================
void CPlayer::Hit()
{
	Damage(30);
}