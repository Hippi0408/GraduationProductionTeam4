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

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CPlayer::CPlayer()
{

}

//=====================================
// �f�X�g���N�^
//=====================================
CPlayer::~CPlayer()
{

}

//============================================================================
// ����������
//============================================================================
HRESULT CPlayer::Init()
{
	// �v���C���[�̃��f����ǂݍ���
	LoadFile("Data\\text\\Motion\\motion_player.txt");

	CCharacter::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CPlayer::Update()
{
	// �U������
	PlayerAttack();

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
	const int nMotion = GetMotion();

	// ���݂̃��[�V��������ς�����ꍇ
	if (nCuttentMotion != nMotion)
	{
		// ���݃��[�V�����̏I������
		switch (nCuttentMotion)
		{
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
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
	// �C���v�b�g
	CInput* pInput = CInput::GetKey();

	// ���̎擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();

	// �U������
	if ((pInput->Trigger(DIK_B)))
	{
		// �e�̐���
		CBullet::Create(D3DXVECTOR3(pos.x,200.0f,pos.z), 20.0f, 20.0f, D3DXVECTOR3(-sinf(rot.y) * 15.0f, sinf(rot.x) * 15.0f, -cosf(rot.y) * 15.0f), 50, CBullet::PRIORITY_BACK_GROUND);
	}
}
