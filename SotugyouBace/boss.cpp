//=============================================================================
//
// �{�X�L�����@�@�@boss.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "boss.h"
#include "application.h"

const float CBoss::BOSS_COLLISION_RADIUS = 100.0f;	// �{�X�̓����蔻��̑傫��
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CBoss::CBoss()
{
	// �v���C���[�̏����l��ݒ�
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(BOSS_COLLISION_RADIUS);
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
	LoadFile("Data\\text\\Motion\\motion_boss.txt");

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
void CBoss::ChangeMotion(const int index)
{
	for (int nCnt = 0; nCnt < MODEL_MAX; nCnt++)
	{
		// ���݂̃��[�V����
		const int nCuttentMotion = GetCurrentMotion(nCnt);
		const int nMotion = GetMotion(nCnt);

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
			CCharacter::ChangeMotion(nCnt);
		}
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