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
#include "boss_life_gauge.h"
#include "camera.h"
#include "particle_emitter.h"

const float CBoss::BOSS_COLLISION_RADIUS = 1000.0f;	// �{�X�̓����蔻��̑傫��
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CBoss::CBoss()
{
	// �{�X�L����
	SetEnemyType(ENEMY_TYPE_BOSS);

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
	// �{�X�̃��f���p�[�c��ݒ�
	SetParts(PARTS_BODY, CParts_File::PARTS_BOSS, CMotion::MOTION_BOSS);
	GetParts(PARTS_BODY)->GetModel(0)->SetSize({ 5.0f, 5.0f, 5.0f });

	SetGaugeManager(CBoss_Life_Gauge::Create({ 1280 / 2, 100.0f,0.0f }, { 800.0f,15.0f }));

	CEnemy::Init();

	CParts* pBody = GetParts(PARTS_BODY);
	pBody->SetMotion(MOTION_NEUTRAL);

	m_bOpening = true;

	//SetCenterPos({ 0.0f,500.0f,0.0f });

	CCamera *pCamera = CApplication::GetCamera();
	pCamera->SetOpening(m_bOpening);

	pCamera->SetPosV({ 0.0f,200.0f,-1000.0f });
	pCamera->SetPosR({ 0.0f, 3000.0f, -500.0f });
	pCamera->SetRot({ 0.0f,0.0f,0.0f });

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
	// �L�����N�^�[�̍X�V
	CEnemy::Update();

	ChangeMotion();

	// �J�����̃|�C���^
	bool bOpening = CApplication::GetCamera()->GetOpening();

	if (m_bOpening != bOpening)
	{
		// �I�[�v�j���O�I�����ɒ��n����
		D3DXVECTOR3 pos = GetPos();
		SetPos({ pos.x,0.0f,pos.z });

		CParts* pBody = GetParts(PARTS_BODY);
		pBody->SetMotion(MOTION_NEUTRAL);
	}

	m_bOpening = bOpening;
}

//============================================================================
// �`�揈��
//============================================================================
void CBoss::Draw()
{
	CEnemy::Draw();
}

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

		// ���j���p�[�e�B�N��
		std::move(CParticleEmitter::Create("Destroy", pos));
	}



	// �Q�[���I����ݒ肷��
	CGame::SetGameEnd();

	CEnemy::Destroy();

}

//============================================================================
// ���[�V�����ύX����
//============================================================================
void CBoss::ChangeMotion()
{
	// �j���[�g�������[�V�������[�V������ݒ�
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// �p�[�c
		CParts* pParts = GetParts(nCnt);

		if (pParts->GetMotion() == MOTION_ATTACK1 && pParts->GetMotionStop() == true)
		{
			pParts->SetMotion(MOTION_ATTACK2);
		}
		// ���[�V���������[�v���Ȃ��ꍇ
		else if (pParts->GetMotionLoop() == false && pParts->GetMotionStop() == true)
		{
			// �j���[�g�������[�V�����ɂ���
			pParts->SetMotion(MOTION_NEUTRAL);
		}
	}
}

//============================================================================
// ���n����
//============================================================================
void CBoss::Landing(const D3DXVECTOR3 pos)
{
	// �J�����̃|�C���^
	bool bOpening = CApplication::GetCamera()->GetOpening();

	if (bOpening)
	{
		// ���n���[�V������ݒ�
		for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
		{
			GetParts(nCnt)->SetMotion(MOTION_NEUTRAL);
			// ���n���p�[�e�B�N��
			std::move(CParticleEmitter::Create("Shock", pos));
			std::move(CParticleEmitter::Create("Dust", pos));
		}
	}

	// �L�����N�^�[�̒��n����
	CCharacter::Landing(pos);
}

//============================================================================
// �ړ�����
//============================================================================
void CBoss::Move()
{
	CEnemy::Move();

	// ��ɒǐՏ��
	SetTracking(true);
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