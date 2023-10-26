//==============================================================================================
//
// ボスの体力ゲージ	　　boss_life_gauge.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _BOSS_LIFE_GAUGE_H_
#define _BOSS_LIFE_GAUGE_H_

#include"gauge_manager.h"

class CBoss_Life_Gauge : public CGauge_Manager
{
public:
	CBoss_Life_Gauge();
	~CBoss_Life_Gauge();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw()  override;

	void Fluctuation() override;

	static CBoss_Life_Gauge *Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size);

private:
	int m_nBoss_Base_Life;	// ボスの元の体力
};

#endif // !_BOSS_LIFE_GAUGE_H_

