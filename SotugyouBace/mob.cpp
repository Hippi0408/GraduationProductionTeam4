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
#include "boss.h"
#include "utility.h"
#include "normal_bullet.h"

const float CMob::MOB_COLLISION_RADIUS = 200.0f;	// ���u�L�����̓����蔻��̑傫��
int CMob::m_DeathCount = 0;
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

	if (!CApplication::GetCamera()->GetOpening())
		// ���
		//Avoidance();

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
	std::move(CParticleEmitter::Create("burst", GetPos()));

	CEnemy::Destroy();

	// ����A�p�[�c�̃h���b�v
	CGame::SetDrop_Parts(1, GetPos());

	m_DeathCount++;

	// �{�X���o��܂ł̓`���[�g���A��
	if (pBoss == nullptr && m_DeathCount == 10)
	{
		// �{�X�L�����̐���
		pBoss = CBoss::Create({ 0.0f, 5000.0f, 6000.0f });
	}

	// ��̓|�������̕���
	if (m_DeathCount % 2 == 0)
		CMob::Create({ utility::Random<float>(5000.0f, -5000.0f), utility::Random<float>(600.0f, 200.0f), utility::Random<float>(5000.0f, -5000.0f) });
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
		pPlayer = CTutorial::GetPlayerManager()->GetPlayer(0);
	else if (Mode == CApplication::MODE_GAME)
		pPlayer = CGame::GetPlayerManager()->GetPlayer(0);

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
// �ړ�����
//============================================================================
void CMob::Move()
{
	CEnemy::Move();

	// ���u�G�ƃv���C���[�̋���
	float fDistance = GetDistance();

	// ������3000���߂��ꍇ�ɒǐՏ�Ԃɂ���
	if (fDistance <= 3000)
		SetTracking(true);
	else
		SetTracking(false);

		// �ǐՏ��
	if (GetTracking() && !CApplication::GetCamera()->GetOpening())
	{
		// �U��
		Attack();

		// �v���C���[�܂ł̊p�x
		float fAngle = GetAngle();

		// �G�̈ړ���
		D3DXVECTOR3 move = { 0.0f,GetMove().y,0.0f };

		// ���x�̐ݒ�
		SetSpeed(3.0f);

		if (fDistance >= 2000 && !m_bAvoidance)
		{
			move.x = sinf(fAngle) * GetSpeed();
			move.z = cosf(fAngle) * GetSpeed();
		}
		else if(fDistance < 2000 && !m_bAvoidance)
		{
			move.x = sinf(fAngle + D3DX_PI) * GetSpeed();
			move.z = cosf(fAngle + D3DX_PI) * GetSpeed();
		}
		
		// �ړ��ʂ̐ݒ�
		SetMove(move);

		// �p�x�̐ݒ�
		SetRot({ 0.0f,fAngle + D3DX_PI,0.0f });		

		// ����̃J�E���g
		m_fAvoidance_Count++;

		if (m_fAvoidance_Count >= 100)
		{
			// ��莞�Ԃ��ƂɊm���ŉ������
			int nRand = rand() % 100;

			if (nRand == 0)
			{
				// ���
				m_bAvoidance = true;
				m_fAvoidance_Speed = 20.0f;
				m_fAvoidance_Count = 0;
			}
		}
	}
}

//============================================================================
// �U������
//============================================================================
void CMob::Attack()
{
	// ���u�G�ƃv���C���[�̋���
	float fDistance = GetDistance();

	CPlayer* pPlayer = nullptr;

	// �v���C���[�̏��
	pPlayer = CGame::GetPlayerManager()->GetPlayer(0);
	
	// �e�����Ԋu
	m_nBullet_Interval++;

	if (m_nBullet_Interval >= 50)
	{
		// �e
		CNormal_Bullet::Create(GetPos(), { 60.0f,60.0f }, { 0.0f,0.0f,0.0f }, fDistance, pPlayer, 0.0f, true, false, PRIORITY_BACK);
		m_nBullet_Interval = 0;
	}
}

//============================================================================
// �������
//============================================================================
void CMob::Avoidance()
{
	if (m_bAvoidance)
	{
		// �v���C���[�܂ł̊p�x
		float fAngle = GetAngle();

		// �G�̈ړ���
		D3DXVECTOR3 move = { 0.0f,GetMove().y,0.0f };

		// �E�����ɉ��
		int nRand = rand() % 2;

		if (nRand == 0 && !m_bfAvo_Step)
		{
			m_fStep = fAngle + D3DX_PI / 2;
			m_bfAvo_Step = true;
		}
		else if(nRand == 1 && !m_bfAvo_Step)
		{
			m_fStep = fAngle - D3DX_PI / 2;
			m_bfAvo_Step = true;
		}

		// �ړ��ʂ̐ݒ�
		move.x = sinf(m_fStep) * m_fAvoidance_Speed;
		move.z = cosf(m_fStep) * m_fAvoidance_Speed;

		// �ړ��ʂ̌���
		m_fAvoidance_Speed -= 0.5f;

		if (m_fAvoidance_Speed <= 0)
		{
			m_bAvoidance = false;
			m_bfAvo_Step = false;
		}

		// �ړ��ʂ̐ݒ�
		SetMove(move);
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