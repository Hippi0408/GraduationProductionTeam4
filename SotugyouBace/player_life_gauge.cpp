//==============================================================================================
//
// �v���C���[�̗̑̓Q�[�W	�@�@player_life_gauge.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"player_life_gauge.h"
#include"player_manager.h"
#include"application.h"

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CPlayer_Life_Gauge::CPlayer_Life_Gauge(const PRIORITY priority) : CGauge_Manager(priority)
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CPlayer_Life_Gauge::~CPlayer_Life_Gauge()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CPlayer_Life_Gauge::Init()
{
	CGauge_Manager::Init();

	// ���̃Q�[�W�̐F
	SetBackCol({ 0.0f,0.0f,0.0f,1.0f });

	// �Q�[�W�̌��̒���
	SetBeaseSize((int)GetGaugeSize().y);

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CPlayer_Life_Gauge::Uninit()
{
	CGauge_Manager::Uninit();
}

//==============================================================================================
// �X�V����
//==============================================================================================
void CPlayer_Life_Gauge::Update()
{
	CGauge_Manager::Update();
}

//==============================================================================================
// �`�揈��
//==============================================================================================
void CPlayer_Life_Gauge::Draw()
{
	CGauge_Manager::Draw();
}

//==============================================================================================
// ��������
//==============================================================================================
CPlayer_Life_Gauge *CPlayer_Life_Gauge::Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size)
{
	CPlayer_Life_Gauge *pPlayer_Life_Gauge = new CPlayer_Life_Gauge(PRIORITY_SCREEN);

	if (pPlayer_Life_Gauge != nullptr)
	{
		pPlayer_Life_Gauge->SetGaugePos(pos);
		pPlayer_Life_Gauge->SetGaugeSize(size);
		pPlayer_Life_Gauge->Init();
	}

	return pPlayer_Life_Gauge;
}

//==============================================================================================
// �Q�[�W�̑���
//==============================================================================================
void CPlayer_Life_Gauge::Fluctuation()
{
	CPlayerManager *pPlayerManager = CApplication::GetPlayerManager();
	CPlayer *pPlayer = nullptr;

	if (pPlayerManager != nullptr)
	{
		pPlayer = pPlayerManager->GetPlayer(0);
	}

	if (pPlayer != nullptr)
	{
		// ���݂̗̑͂̊���
		m_fLife_Percent = (float)pPlayer->GetLife() / GetBeaseLife() * 100;

		// �Q�[�W�T�C�Y�𓯂������ɂ���
		float Gauge_Percent = GetGaugeSize().y * m_fLife_Percent / 100;

		// �Q�[�W�̑���
		SetSubSize({ 0.0f, -GetBeaseSize() + Gauge_Percent });
	}

	// �F�̐ݒ�
	Col();
}

//==============================================================================================
// �F�̐ݒ�
//==============================================================================================
void CPlayer_Life_Gauge::Col()
{
	// ���݂̗̑͂̊���
	if (m_fLife_Percent <= 25.0f)
		SetCol({ 1.0f,0.0f,0.0f,1.0f });
	else
		SetCol({ 1.0f,1.0f,1.0f,1.0f });
}