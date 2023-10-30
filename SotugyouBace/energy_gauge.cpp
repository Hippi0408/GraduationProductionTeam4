//==============================================================================================
//
// �G�l���M�[�Q�[�W	�@�@energy_gauge.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"energy_gauge.h"
#include"debugProc.h"

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CEnergy_Gauge::CEnergy_Gauge()
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CEnergy_Gauge::~CEnergy_Gauge()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CEnergy_Gauge::Init()
{
	CGauge_Manager::Init();

	m_fRecovery_Interval = 300.0f;	// �񕜂��n�߂�܂ł̃C���^�[�o��
	m_fReuse_Percent = 30.0f;		// �S�����̉񕜎��ɍė��p�ł���^�C�~���O
	m_bConsumption = false;			// �����
	m_bAllRecovery = true;			// �񕜂��o�����Ԃ�
	m_bAllConsumption = false;		// �G�l���M�[��S�ď����
	m_bRecovery_Pause = false;		// �񕜂��ꎞ��~��

	// ���̃Q�[�W�̐F
	SetBackCol({ 0.0f,0.0f,0.0f,1.0f });

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CEnergy_Gauge::Uninit()
{
	CGauge_Manager::Uninit();
}

//==============================================================================================
// �X�V����
//==============================================================================================
void CEnergy_Gauge::Update()
{
	// �Q�[�W���񕜂���
	Recovery_Gauge();

	// �񕜂��邩
	m_bConsumption = false;

	// �Q�[�W�̑���
	Fluctuation();

	// �Q�[�W�̐F�̐ݒ�
	GaugeColor();

	CGauge_Manager::Update();
}

//==============================================================================================
// �`�揈��
//==============================================================================================
void CEnergy_Gauge::Draw()
{
	CGauge_Manager::Draw();
}

//==============================================================================================
// ��������
//==============================================================================================
CEnergy_Gauge* CEnergy_Gauge::Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size)
{
	CEnergy_Gauge *pEnergy_Gauge = new CEnergy_Gauge;

	if (pEnergy_Gauge != nullptr)
	{
		pEnergy_Gauge->SetGaugePos(pos);
		pEnergy_Gauge->SetGaugeSize(size);
		pEnergy_Gauge->Init();
	}

	return pEnergy_Gauge;
}

//==============================================================================================
// �Q�[�W�̑���
//==============================================================================================
void CEnergy_Gauge::Fluctuation()
{
	if (m_bRecovery_Pause)
	{
		Pause_Count++;

		if (Pause_Count >= BasePause_Count)
		{
			m_bRecovery_Pause = false;
			m_bAllRecovery = true;		// �񕜂ł��Ȃ���Ԃɂ���
			m_bAllConsumption = false;	// �G�l���M�[��S�ď����
			Pause_Count = 0;
		}
	}
	else if (m_bAllConsumption && !m_bAllRecovery && !m_bRecovery_Pause)
		// �Ō�܂Ō��炷
		m_fFluctuation = MAX_ENERGY;

	// ���݂̃G�l���M�[�c��
	float fEnergy = MAX_ENERGY - m_fFluctuation;

	// ���݂̃G�l���M�[�c�ʂ̊���
	float fEnergy_Percent = fEnergy / MAX_ENERGY * 100;

	// �Q�[�W�T�C�Y���G�l���M�[�̊����ɍ��킹��
	float fGeuge_Size = GetGaugeSize().x * fEnergy_Percent / 100.0f;

	// �Q�[�W�̑���
	SetSubSize({ GetGaugeSize().x - fGeuge_Size ,0.0f });
}

//==============================================================================================
// �G�l���M�[�̉�
//==============================================================================================
void CEnergy_Gauge::Recovery_Gauge()
{
	if (m_bAllRecovery)
	{
		if (!m_bConsumption && m_fFluctuation > 0.0f)
			// �񕜂���G�l���M�[��
			m_fFluctuation -= m_fRecovery_Speed;

		// ���݂̃Q�[�W�c�ʂ̊���
		float Gauge_Percent = (MAX_ENERGY - m_fFluctuation) / MAX_ENERGY * 100;

		// �񕜓r���G�l���M�[���g����悤�ɂ���^�C�~���O
		if (Gauge_Percent >= m_fReuse_Percent)
			m_bAllConsumption = false;

		// �S�񕜂���
		if (m_fFluctuation <= 0)
			m_fFluctuation = 0.0f;
	}
	else if (!m_bAllRecovery && !m_bRecovery_Pause)
	{
		// �C���^�[�o���̃J�E���g
		m_nInterval_Count++;

		if (m_nInterval_Count >= m_fRecovery_Interval)
		{
			// �񕜂ł����Ԃɂ���
			m_bAllRecovery = true;
			m_nInterval_Count = 0;
		}
	}
}

//==============================================================================================
// �G�l���M�[�̏���
//==============================================================================================
void CEnergy_Gauge::Consumption_Gauge()
{
	if (!m_bAllConsumption)
	{
		// �����G�l���M�[��
		if (m_fFluctuation <= MAX_ENERGY)
		{
			// ����ʂ̉��Z
			m_fFluctuation += m_fConsumption_Speed;

			// �G�l���M�[���
			m_bConsumption = true;
		}
		else
		{
			m_bAllRecovery = false;		// �񕜂ł��Ȃ���Ԃɂ���
			m_bAllConsumption = true;	// �G�l���M�[��S�ď����
		}
	}
}

//==============================================================================================
// ������̃G�l���M�[����
//==============================================================================================
void CEnergy_Gauge::Avoidance_Energy()
{
	if (!m_bAllConsumption)
	{
		// �����G�l���M�[��
		m_fFluctuation += m_fAvoidance;

		if (m_fFluctuation < MAX_ENERGY)
			// �G�l���M�[���
			m_bConsumption = true;
		else
		{
			m_bAllRecovery = false;		// �񕜂ł��Ȃ���Ԃɂ���
			m_bAllConsumption = true;	// �G�l���M�[��S�ď����
		}
	}
}

//==============================================================================================
// �Q�[�W�̐F
//==============================================================================================
void CEnergy_Gauge::GaugeColor()
{
	// ���݂̃Q�[�W�c�ʂ̊���
	float Gauge_Percent = (MAX_ENERGY - m_fFluctuation) / MAX_ENERGY * 100;

	// �F�̐ݒ�
	if (Gauge_Percent <= 25.0f || m_bAllConsumption && !m_bRecovery_Pause)
		// �c��25%�ȉ�or�S�ď������A�S�񕜂���܂�(��)
		SetCol({ 1.0f,0.0f,0.0f,1.0f });
	else if (Gauge_Percent > 20.0f || !m_bAllConsumption)
		// �c��26%�ȏ�(��)
		SetCol({ 1.0f,1.0f,1.0f,1.0f });

	// ���̃Q�[�W�̐F
	SetBackCol({ 0.0f,0.0f,0.0f,1.0f });

	// �G�l���M�[��S�ď����
	if (!m_bAllRecovery && !m_bRecovery_Pause)
	{
		// �Ԃ��_�ł�����
		Col_Count++;
		float fRed = sinf(Col_Count * 0.07f);
		SetBackCol({ fRed,0.0f,0.0f,1.0f });
	}
	else
		// �_�ł̃��Z�b�g
		Col_Count = 0;
}

//==============================================================================================
// �Q�[�W�񕜂��ꎞ��~
//==============================================================================================
void CEnergy_Gauge::Recovery_Pause(int count)
{
	if (m_bAllRecovery && !m_bAllConsumption)
	{
		m_bAllRecovery = false;		// �񕜂ł��Ȃ���Ԃɂ���
		m_bAllConsumption = true;	// �G�l���M�[��S�ď����
		m_bRecovery_Pause = true;	// ��~��

		// ��~���鎞��
		BasePause_Count = count;
	}
}