//==============================================================================================
//
// �G���G�̗̑̓Q�[�W	�@�@mob_life_gauge.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _MOB_LIFE_GAUGE
#define	_MOB_LIFE_GAUGE

#include"object3D.h"

class CMob_Life_Gauge : public CObject3D
{
public:
	CMob_Life_Gauge(const PRIORITY priority);
	~CMob_Life_Gauge();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw()  override;

	static CMob_Life_Gauge *Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size, int index);

	void SetMobLife_Pos(D3DXVECTOR3 pos) { m_Pos = pos; }
	void SetIndex(int index) { m_nGauge_Index = index; }
	void SetDraw(bool draw) { m_bDraw = draw; }

	CObject3D *GetBackGauge() { return m_BackGauge; }

private:
	D3DXVECTOR3 m_Pos;			// �ʒu
	int m_nMob_Base_Life;		// ���u�̌��̗̑�
	int m_nBase_GaugeSize;		// �Q�[�W�̌��̒���
	int m_nGauge_Index;			// �ԍ�
	CObject3D *m_BackGauge;		// �Q�[�W�̔w�i
	bool m_bDraw;				// �\�����邩
};

#endif // !_MOB_LIFE_GAUGE
