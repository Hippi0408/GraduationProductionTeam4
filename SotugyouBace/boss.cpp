//=============================================================================
//
// �{�X�L�����@�@�@boss.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "boss.h"
#include "application.h"

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CBoss::CBoss()
{
	// �v���C���[�̏����l��ݒ�
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
}

//=====================================
// �f�X�g���N�^
//=====================================
CBoss::~CBoss()
{

}

//============================================================================
// ����������
//============================================================================
HRESULT CBoss::Init()
{
	// �v���C���[�̃��f����ǂݍ���
	LoadFile("Data\\text\\Motion\\motion_player.txt");

	CEnemy::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CBoss::Uninit()
{
	CEnemy::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CBoss::Update()
{
	// ���[�V�����ύX
	ChangeMotion();

	// �L�����N�^�[�̍X�V
	CEnemy::Update();
}

//============================================================================
// �`�揈��
//============================================================================
void CBoss::Draw()
{
	CEnemy::Draw();
}

//============================================================================
// ���[�V�����ύX����
//============================================================================
void CBoss::ChangeMotion()
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
// ��������
//============================================================================
CBoss* CBoss::Create(const D3DXVECTOR3 pos)
{
	CBoss* pBoss = new CBoss;

	if (FAILED(pBoss->Init()))
	{
		return nullptr;
	}

	pBoss->SetPos(pos);

	return pBoss;
}