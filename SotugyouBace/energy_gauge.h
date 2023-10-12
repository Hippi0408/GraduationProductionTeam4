//==============================================================================================
//
// �G�l���M�[�Q�[�W	�@�@energy_gauge.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _ENERGY_GAUGE_H_
#define _ENERGY_GAUGE_H_

#include"object2D.h"

class CEnergy_Gauge : public CObject2D
{
public:
	CEnergy_Gauge(const PRIORITY priority);
	~CEnergy_Gauge() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw()  override;

	static CEnergy_Gauge* Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size);

	void Consumption_Gauge();	// �G�l���M�[�̏���
	void Avoidance();			// ������̃G�l���M�[����

	void SetRecovery_Speed(const float recovery) { m_fRecovery_Speed = recovery; }				// �񕜑��x�̐ݒ�
	void SetConsumption_Speed(const float consumption) { m_fConsumption_Speed = consumption; }	// ����x�̐ݒ�
	void SetAvoidance_amount(const float avoidance) { m_fAvoidance = avoidance; }				// ����x�̐ݒ�

	const bool GetConsumption() { return m_bAllConsumption; }

private:
	void Recovery_Gauge();		// �G�l���M�[�̉�
	void GaugeColor();			// �Q�[�W�̐F

	float m_fRecovery_Speed;		// �񕜑��x
	float m_fConsumption_Speed;		// ����x
	float m_fAvoidance;				// ������̏����
	float m_fFluctuation;			// ��������Q�[�W�̗�
	float m_fBaseSize;				// ���̃Q�[�W�T�C�Y
	float m_fRecovery_Interval;		// �񕜂��n�߂�܂ł̃C���^�[�o��
	int m_nInterval_Count;			// �C���^�[�o���̃J�E���g
	bool m_bConsumption;			// �����
	bool m_bAllRecovery;			// �񕜂��o�����Ԃ�
	bool m_bAllConsumption;			// �G�l���M�[��S�ď����
	CObject2D* m_pBackGauge;		// ���̃Q�[�W
	D3DXCOLOR m_BackGauge_Col;		// ���̃Q�[�W�̐F
	int Col_Count;
};

#endif // !_ENERGY_GAUGE_H_
