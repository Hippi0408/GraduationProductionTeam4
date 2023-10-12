//==============================================================================================
//
// エネルギーゲージ	　　energy_gauge.h
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

	void Consumption_Gauge();	// エネルギーの消費
	void Avoidance();			// 回避時のエネルギー消費

	void SetRecovery_Speed(const float recovery) { m_fRecovery_Speed = recovery; }				// 回復速度の設定
	void SetConsumption_Speed(const float consumption) { m_fConsumption_Speed = consumption; }	// 消費速度の設定
	void SetAvoidance_amount(const float avoidance) { m_fAvoidance = avoidance; }				// 消費速度の設定

	const bool GetConsumption() { return m_bAllConsumption; }

private:
	void Recovery_Gauge();		// エネルギーの回復
	void GaugeColor();			// ゲージの色

	float m_fRecovery_Speed;		// 回復速度
	float m_fConsumption_Speed;		// 消費速度
	float m_fAvoidance;				// 回避時の消費量
	float m_fFluctuation;			// 増減するゲージの量
	float m_fBaseSize;				// 元のゲージサイズ
	float m_fRecovery_Interval;		// 回復し始めるまでのインターバル
	int m_nInterval_Count;			// インターバルのカウント
	bool m_bConsumption;			// 消費中か
	bool m_bAllRecovery;			// 回復が出来る状態か
	bool m_bAllConsumption;			// エネルギーを全て消費した
	CObject2D* m_pBackGauge;		// 後ろのゲージ
	D3DXCOLOR m_BackGauge_Col;		// 後ろのゲージの色
	int Col_Count;
};

#endif // !_ENERGY_GAUGE_H_
