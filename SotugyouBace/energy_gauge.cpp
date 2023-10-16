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
CEnergy_Gauge::CEnergy_Gauge(const PRIORITY priority) : CObject2D(priority)
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
	CObject2D::Init();

	m_fRecovery_Speed = 10.0f;		// �񕜑��x
	m_fConsumption_Speed = 3.0f;	// ����x
	m_fAvoidance = 300.0f;			// ������̏����
	m_fFluctuation = 0.0f;			// ��������Q�[�W�̗�
	m_fBaseSize = GetSize().x;		// ���̃Q�[�W�T�C�Y
	m_fRecovery_Interval = 300.0f;	// �񕜂��n�߂�܂ł̃C���^�[�o��
	m_fReuse_Percent = 30.0f;		// �S�����̉񕜎��ɍė��p�ł���^�C�~���O
	m_bConsumption = false;			// �����
	m_bAllRecovery = true;			// �񕜂��o�����Ԃ�
	m_bAllConsumption = false;		// �G�l���M�[��S�ď����
	m_bRecovery_Pause = false;		// �񕜂��ꎞ��~��

	// ���̃Q�[�W�̐ݒ�
	m_pBackGauge = CObject2D::Create(GetPos(), GetSize(), PRIORITY_FRONT);
	m_pBackGauge->SetCol({ 0.0f,0.0f,0.0f,1.0f });

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CEnergy_Gauge::Uninit()
{
	CObject2D::Uninit();
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

	// �Q�[�W�̐F�̐ݒ�
	GaugeColor();

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
		m_fFluctuation = m_fBaseSize;

	// �Q�[�W�̑���
	SetHalfSize({ m_fFluctuation,0.0f });

	CObject2D::Update();
}

//==============================================================================================
// �`�揈��
//==============================================================================================
void CEnergy_Gauge::Draw()
{
	CObject2D::Draw();
}

//==============================================================================================
// ��������
//==============================================================================================
CEnergy_Gauge* CEnergy_Gauge::Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size)
{
	CEnergy_Gauge *pEnergy_Gauge = new CEnergy_Gauge(PRIORITY_SCREEN);

	if (pEnergy_Gauge != nullptr)
	{
		pEnergy_Gauge->SetPos(pos);
		pEnergy_Gauge->SetSize(size);
		pEnergy_Gauge->Init();
	}

	return pEnergy_Gauge;
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
		float Gauge_Percent = (m_fBaseSize - m_fFluctuation) / m_fBaseSize * 100;

		// �񕜓r���G�l���M�[���g����悤�ɂ���^�C�~���O
		if (Gauge_Percent >= m_fReuse_Percent)
			m_bAllConsumption = false;

		// �S�񕜂���
		if (m_fFluctuation <= 0)
			m_fFluctuation = 0;
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
		if (m_fFluctuation <= m_fBaseSize)
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
void CEnergy_Gauge::Avoidance()
{
	if (!m_bAllConsumption)
	{
		// �����G�l���M�[��
		m_fFluctuation += m_fAvoidance;

		if (m_fFluctuation < m_fBaseSize)
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
	float Gauge_Percent = (m_fBaseSize - m_fFluctuation) / m_fBaseSize * 100;

	// �F�̐ݒ�
	if (Gauge_Percent <= 25.0f || m_bAllConsumption && !m_bRecovery_Pause)
		// �c��25%�ȉ�or�S�ď������A�S�񕜂���܂�(��)
		SetCol({ 1.0f,0.0f,0.0f,1.0f });
	else if (Gauge_Percent > 20.0f || !m_bAllConsumption)
		// �c��26%�ȏ�(��)
		SetCol({ 1.0f,1.0f,1.0f,1.0f });

	// ���̃Q�[�W�̐F
	m_BackGauge_Col = { 0.0f,0.0f,0.0f,1.0f };

	// �G�l���M�[��S�ď����
	if (!m_bAllRecovery && !m_bRecovery_Pause)
	{
		// �Ԃ��_�ł�����
		Col_Count++;
		m_BackGauge_Col.r = sinf(Col_Count * 0.07f);
	}
	else
	{
		// �_�ł̃��Z�b�g
		Col_Count = 0;

		// ��
		m_BackGauge_Col = { 0.0f,0.0f,0.0f,1.0f };
	}

	// ���̃Q�[�W�̐F�̐ݒ�
	m_pBackGauge->SetCol(m_BackGauge_Col);
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

		BasePause_Count = count;
	}
}