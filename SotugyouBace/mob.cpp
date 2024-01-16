//=============================================================================
//
// ���u�@�@�@mob.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "mob.h"
#include "application.h"
#include "tutorial.h"
#include "game.h"
#include "particle_emitter.h"
#include "mob_life_gauge.h"
#include "player.h"
#include "player_manager.h"

const float CMob::MOB_COLLISION_RADIUS = 200.0f;	// ���u�L�����̓����蔻��̑傫��
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CMob::CMob()
{
	// ���u�L����
	SetEnemyType(ENEMY_TYPE_MOB);

	// �v���C���[�̏����l��ݒ�
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(MOB_COLLISION_RADIUS);
}

//=====================================
// �f�X�g���N�^
//=====================================
CMob::~CMob()
{

}

//============================================================================
// ����������
//============================================================================
HRESULT CMob::Init()
{
	// ���u�̃��f���p�[�c��ݒ�
	SetParts(PARTS_BODY, CParts_File::PARTS_MOB, CMotion::MOTION_MOB);

	CEnemy::Init();

	// �̗̓Q�[�W
	SetGaugeManager(CMob_Life_Gauge::Create({0.0f, 0.0f, 0.0f}, { 200.0f,30.0f }));

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CMob::Uninit()
{
	CEnemy::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CMob::Update()
{
	D3DXVECTOR3 Life_Gauge_Pos = GetPos();
	Life_Gauge_Pos.y += 400.0f;

	/*D3DXVECTOR3 Move_Vec = { 0.0f,-0.1f,-0.01f };
	D3DXVec3Normalize(&Move_Vec, &Move_Vec);
	SetSpeed(20);

	SetMove(Move_Vec);*/

	CGauge_Manager *GaugeManager = GetGaugeManager();

	if (GaugeManager != nullptr)
	{
		// �̗̓Q�[�W
		GaugeManager->SetGaugePos(Life_Gauge_Pos);

		// �̗̓Q�[�W�̕\��
		DrawLifeGauge();
	}

	// �S�Ẵp�[�c�̏���
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// �p�[�c�̏��
		CParts* pParts = GetParts(nCnt);

		// �p�[�c�����S�Ẵ��f��
		for (auto pModel : pParts->GetModelAll())
		{
			// ����7000�ȏ�œG��\��
			if (m_fDistance > DRAW_DISTANCE)
			{
				pModel->SetDrawFlag(false);
			}
			else
			{
				pModel->SetDrawFlag(true);
			}
		}
	}

	// �L�����N�^�[�̍X�V
	CEnemy::Update();
}

//============================================================================
// �`�揈��
//============================================================================
void CMob::Draw()
{
	CEnemy::Draw();
}

//============================================================================
// �j�󏈗�
//============================================================================
void CMob::Destroy()
{
	// ���j�p�[�e�B�N��
	//std::move(CParticleEmitter::Create("Destroy", GetPos()));
	std::move(CParticleEmitter::Create("Dust", GetPos()));			//test

	CEnemy::Destroy();

	// ����A�p�[�c�̃h���b�v
	CGame::SetDrop_Parts(1, GetPos());
}

//============================================================================
// �̗̓Q�[�W�̕\��
//============================================================================
void CMob::DrawLifeGauge()
{
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

	// �v���C���[����G�̋���
	D3DXVECTOR3 Vec = Player_Pos - Mob_Pos;

	// �����̎Z�o
	m_fDistance = sqrtf(Vec.x * Vec.x + Vec.z * Vec.z);

	// ����3000�ȏ�
	if (m_fDistance > DRAW_HP_DISTANCE || GetLife() == FIRST_MAX_LIFE)
	{
		GetGaugeManager()->SetDrawGauge(false);
	}
	else
	{
		GetGaugeManager()->SetDrawGauge(true);
	}
}

//============================================================================
// ��������
//============================================================================
CMob* CMob::Create(const D3DXVECTOR3 pos)
{
	CMob* pMob = new CMob;

	if (FAILED(pMob->Init()))
	{
		return nullptr;
	}
	pMob->SetPos(pos);

	return pMob;
}