//=============================================================================
//
// �{�X�L�����@�@�@boss.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "boss.h"
#include "application.h"
#include "game.h"
#include "particle_emitter.h"

const float CBoss::BOSS_COLLISION_RADIUS = 500.0f;	// �{�X�̓����蔻��̑傫��
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CBoss::CBoss()
{
	// �{�X�̏����l��ݒ�
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
	//LoadFile("Data\\text\\Motion\\motion_boss.txt");

	SetParts(0, "Data\\text\\Motion\\motion_boss.txt");
	GetParts(0)->GetModelSet(MODEL_BODY).pModel->SetSize({ 5.0f, 5.0f, 5.0f });

	// �̃��f���̃T�C�Y��5�{
	//GetModelSet(MODEL_BODY).pModel->SetSize({ 5.0f, 5.0f, 5.0f });

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
	//ChangeMotion();

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
//
////============================================================================
//// ���[�V�����ύX����
////============================================================================
//void CBoss::ChangeMotion()
//{
//	// ���݂̃��[�V����
//	const int nCuttentMotion = GetCurrentMotion();
//	const int nMotion = GetMotion();
//
//	// ���݂̃��[�V��������ς�����ꍇ
//	if (nCuttentMotion != nMotion)
//	{
//		// ���݃��[�V�����̏I������
//		switch (nCuttentMotion)
//		{
//		case MOTION_NEUTRAL:
//			break;
//		case MOTION_WALK:
//			break;
//		default:
//			break;
//		}
//
//		// ���݃��[�V�����̊J�n����
//		switch (nMotion)
//		{
//		case MOTION_NEUTRAL:
//			break;
//		case MOTION_WALK:
//			break;
//		default:
//			break;
//		}
//
//		// �L�����N�^�[�̃��[�V�����ύX����
//		CCharacter::ChangeMotion();
//	}
//}

//============================================================================
// �j�󏈗�
//============================================================================
void CBoss::Destroy()
{
	// �{�X�p���j�p�[�e�B�N��
	for (int nCnt = 0; nCnt < 30; nCnt++)
	{
		D3DXVECTOR3 pos = GetPos();
		pos.y += 50.0f * nCnt;

		// �U���p�[�e�B�N��
		std::move(CParticleEmitter::Create("MineOre", pos));
	}

	// �Q�[���I����ݒ肷��
	CGame::SetGameEnd();

	CEnemy::Destroy();
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