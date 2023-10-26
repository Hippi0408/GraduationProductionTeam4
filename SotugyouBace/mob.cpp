//=============================================================================
//
// ���u�@�@�@mob.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "mob.h"
#include "application.h"
#include "game.h"
#include "particle_emitter.h"
#include "mob_life_gauge.h"

const float CMob::MOB_COLLISION_RADIUS = 100.0f;	// �{�X�̓����蔻��̑傫��
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CMob::CMob()
{
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
	// �v���C���[�̃��f����ǂݍ���
	LoadFile("Data\\text\\Motion\\motion_mob.txt");

	// �̗̓Q�[�W
	m_LifeGauge = CMob_Life_Gauge::Create({ GetPos().x,GetPos().y + 50.0f,GetPos().z }, { 200.0f,30.0f }, m_nMob_Index);

	CEnemy::Init();

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
	// ���[�V�����ύX
	ChangeMotion();

	// �̗̓Q�[�W
	m_LifeGauge->SetMobLife_Pos({ GetPos().x,GetPos().y + 400.0f,GetPos().z });

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
// ���[�V�����ύX����
//============================================================================
void CMob::ChangeMotion()
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
// �j�󏈗�
//============================================================================
void CMob::Destroy()
{
	// �{�X�p���j�p�[�e�B�N��
	std::move(CParticleEmitter::Create("MineOre", GetPos()));

	// �̗̓Q�[�W
	if (m_LifeGauge != nullptr)
	{
		m_LifeGauge->GetBackGauge()->Uninit();
		m_LifeGauge->Uninit();
	}

	CEnemy::Destroy();
}

//============================================================================
// ��������
//============================================================================
CMob* CMob::Create(const D3DXVECTOR3 pos, const int index)
{
	CMob* pMob = new CMob;

	if (pMob != nullptr)
	{
		pMob->SetPos(pos);
		pMob->SetMobIndex(index);
		pMob->Init();
	}

	return pMob;
}