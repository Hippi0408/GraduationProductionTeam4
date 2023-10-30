//==============================================================================================
//
// 雑魚敵の体力ゲージ	　　mob_life_gauge.h
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
	D3DXVECTOR3 m_Pos;			// 位置
	int m_nMob_Base_Life;		// モブの元の体力
	int m_nBase_GaugeSize;		// ゲージの元の長さ
	int m_nGauge_Index;			// 番号
	CObject3D *m_BackGauge;		// ゲージの背景
	bool m_bDraw;				// 表示するか
};

#endif // !_MOB_LIFE_GAUGE
