//==============================================================================================
//
// プレイヤーの体力ゲージ	　　player_life_gauge.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _PLAYER_LIFE_GAUGE_H_
#define	_PLAYER_LIFE_GAUGE_H_

#include"gauge_manager.h"

class CPlayer_Life_Gauge : public CGauge_Manager
{
public:
	CPlayer_Life_Gauge(const PRIORITY priority);
	~CPlayer_Life_Gauge();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw()  override;

	static CPlayer_Life_Gauge *Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size);

	void Fluctuation() override;
	void Col();

private:
	float m_fLife_Percent;		// 体力の割合
	int m_nPlayer_Base_Life;	// プレイヤーの元の体力
};

#endif // !_PLAYER_LIFE_GAUGE_H_
