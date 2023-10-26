//==============================================================================================
//
// �G�l���M�[�Q�[�W	�@�@energy_gauge.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _ENERGY_GAUGE_H_
#define _ENERGY_GAUGE_H_

#include"gauge_manager.h"

class CEnergy_Gauge : public CGauge_Manager
{
public:
	CEnergy_Gauge();
	~CEnergy_Gauge() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw()  override;

	static CEnergy_Gauge* Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size);

	void Fluctuation() override;
	void Consumption_Gauge();			// �G�l���M�[�̏���
	void Avoidance_Energy();			// ������̃G�l���M�[����
	void Recovery_Pause(int count);		// �Q�[�W�񕜂��ꎞ��~

	void SetRecovery_Speed(const float recovery) { m_fRecovery_Speed = recovery; }				// �񕜑��x�̐ݒ�
	void SetConsumption_Speed(const float consumption) { m_fConsumption_Speed = consumption; }	// ����x�̐ݒ�
	void SetAvoidance_amount(const float avoidance) { m_fAvoidance = avoidance; }				// ������̏����
	void SetReuse_Percent(const float reuse) { m_fReuse_Percent = reuse; }						// �S�����̉񕜎��ɍė��p�ł���^�C�~���O�̐ݒ�
	void SetRecovery_Interval(const float interval) { m_fRecovery_Interval = interval; }
	
	const bool GetConsumption() { return m_bAllConsumption; }		// �G�l���M�[��S�ď���Ă��邩

private:
	void Recovery_Gauge();		// �G�l���M�[�̉�
	void GaugeColor();			// �Q�[�W�̐F

	float m_fRecovery_Speed;		// �񕜑��x
	float m_fConsumption_Speed;		// ����x
	float m_fAvoidance;				// ������̏����
	float m_fBaseSize;				// ���̃Q�[�W�T�C�Y
	float m_fRecovery_Interval;		// �񕜂��n�߂�܂ł̃C���^�[�o��
	float m_fReuse_Percent;			// �S�����̉񕜎��ɍė��p�ł���^�C�~���O
	float m_fFluctuation;			// ��������Q�[�W�̗�
	int m_nInterval_Count;			// �C���^�[�o���̃J�E���g
	bool m_bConsumption;			// �����
	bool m_bAllRecovery;			// �񕜂��o�����Ԃ�
	bool m_bAllConsumption;			// �G�l���M�[��S�ď����
	bool m_bRecovery_Pause;			// �񕜂̈ꎞ��~
	int Col_Count;					// �_�ł̃J�E���g
	int Pause_Count;				// �񕜂̈ꎞ��~���̃J�E���g
	int BasePause_Count;			// �񕜂̈ꎞ��~���̃J�E���g�̃x�[�X
};

#endif // !_ENERGY_GAUGE_H_
