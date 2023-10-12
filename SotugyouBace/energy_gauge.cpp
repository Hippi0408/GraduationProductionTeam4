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
	m_fConsumption_Speed = 2.0f;	// ����x
	m_fAvoidance = 200.0f;			// ������̏����
	m_fFluctuation = 0.0f;			// ��������Q�[�W�̗�
	m_fBaseSize = GetSize().x;		// ���̃Q�[�W�T�C�Y
	m_fRecovery_Interval = 300.0f;	// �񕜂��n�߂�܂ł̃C���^�[�o��
	m_bConsumption = false;			// �����
	m_bAllRecovery = true;			// �񕜂��o�����Ԃ�
	m_bAllConsumption = false;		// �G�l���M�[��S�ď����

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

	if (m_bAllConsumption && !m_bAllRecovery)
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

		// �S�񕜂���
		if (m_fFluctuation <= 0)
			m_bAllConsumption = false;
	}
	else
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

		if (m_fFluctuation <= m_fBaseSize)
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
	if (Gauge_Percent <= 20.0f || m_bAllConsumption)
		// �c��20%�ȉ�or�S�ď������A�S�񕜂���܂�
		SetCol({ 1.0f,0.0f,0.0f,1.0f });
	else if (Gauge_Percent > 20.0f || !m_bAllConsumption)
		// �c��21%�ȏ�
		SetCol({ 1.0f,1.0f,1.0f,1.0f });

	// ���̃Q�[�W�̐F
	m_BackGauge_Col = { 0.0f,0.0f,0.0f,1.0f };

	// �G�l���M�[��S�ď����
	if (!m_bAllRecovery)
	{
		// �Ԃ��_�ł�����
		Col_Count++;
		m_BackGauge_Col.r = sinf(Col_Count * 0.07f);
	}
	else
		// ��
		m_BackGauge_Col = { 0.0f,0.0f,0.0f,1.0f };

	// ���̃Q�[�W�̐F�̐ݒ�
	m_pBackGauge->SetCol(m_BackGauge_Col);
}