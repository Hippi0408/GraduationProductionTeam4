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

const float CBoss::BOSS_COLLISION_RADIUS = 500.0f;	// �{�X�̓����蔻��̑傫��
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
	SetParts(0, "Data\\text\\Motion\\motion_boss.txt");
	GetParts(0)->GetModelSet(MODEL_BODY).pModel->SetSize({ 5.0f, 5.0f, 5.0f });

	SetGaugeManager(CBoss_Life_Gauge::Create({ 1280 / 2, 100.0f,0.0f }, { 800.0f,15.0f }));

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