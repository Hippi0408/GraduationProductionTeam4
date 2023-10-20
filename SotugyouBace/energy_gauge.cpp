//==============================================================================================
//
// エネルギーゲージ	　　energy_gauge.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"energy_gauge.h"
#include"debugProc.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CEnergy_Gauge::CEnergy_Gauge()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CEnergy_Gauge::~CEnergy_Gauge()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CEnergy_Gauge::Init()
{
	CGauge_Manager::Init();

	m_fRecovery_Speed = 10.0f;		// 回復速度
	m_fConsumption_Speed = 3.0f;	// 消費速度
	m_fAvoidance = 300.0f;			// 回避時の消費量
	m_fBaseSize = GetGaugeSize().x;		// 元のゲージサイズ
	m_fRecovery_Interval = 300.0f;	// 回復し始めるまでのインターバル
	m_fReuse_Percent = 30.0f;		// 全消費からの回復時に再利用できるタイミング
	m_bConsumption = false;			// 消費中か
	m_bAllRecovery = true;			// 回復が出来る状態か
	m_bAllConsumption = false;		// エネルギーを全て消費した
	m_bRecovery_Pause = false;		// 回復が一時停止中

	// 後ろのゲージの設定
	m_pBackGauge = CObject2D::Create(GetGaugePos(), GetGaugeSize(), PRIORITY_FRONT);
	m_pBackGauge->SetCol({ 0.0f,0.0f,0.0f,1.0f });

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CEnergy_Gauge::Uninit()
{
	CGauge_Manager::Uninit();
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CEnergy_Gauge::Update()
{
	// ゲージを回復する
	Recovery_Gauge();

	// 回復するか
	m_bConsumption = false;

	// ゲージの色の設定
	GaugeColor();

	if (m_bRecovery_Pause)
	{
		Pause_Count++;

		if (Pause_Count >= BasePause_Count)
		{
			m_bRecovery_Pause = false;
			m_bAllRecovery = true;		// 回復できない状態にする
			m_bAllConsumption = false;	// エネルギーを全て消費した
			Pause_Count = 0;
		}
	}
	else if (m_bAllConsumption && !m_bAllRecovery && !m_bRecovery_Pause)
		// 最後まで減らす
		SetFluctuation(m_fBaseSize);

	// ゲージの増減
	SetHalfSize({ GetFluctuation(),0.0f });

	CGauge_Manager::Update();
}

//==============================================================================================
// 描画処理
//==============================================================================================
void CEnergy_Gauge::Draw()
{
	CGauge_Manager::Draw();
}

//==============================================================================================
// 生成処理
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
// エネルギーの回復
//==============================================================================================
void CEnergy_Gauge::Recovery_Gauge()
{
	if (m_bAllRecovery)
	{
		if (!m_bConsumption && GetFluctuation() > 0.0f)
			// 回復するエネルギー量
			AddFluctuation(-m_fRecovery_Speed);

		// 現在のゲージ残量の割合
		float Gauge_Percent = (m_fBaseSize - GetFluctuation()) / m_fBaseSize * 100;

		// 回復途中エネルギーを使えるようにするタイミング
		if (Gauge_Percent >= m_fReuse_Percent)
			m_bAllConsumption = false;

		// 全回復した
		if (GetFluctuation() <= 0)
			SetFluctuation(0.0f);
	}
	else if (!m_bAllRecovery && !m_bRecovery_Pause)
	{
		// インターバルのカウント
		m_nInterval_Count++;

		if (m_nInterval_Count >= m_fRecovery_Interval)
		{
			// 回復できる状態にする
			m_bAllRecovery = true;
			m_nInterval_Count = 0;
		}
	}
}

//==============================================================================================
// エネルギーの消費
//==============================================================================================
void CEnergy_Gauge::Consumption_Gauge()
{
	if (!m_bAllConsumption)
	{
		// 消費するエネルギー量
		if (GetFluctuation() <= m_fBaseSize)
		{
			// 消費量の加算
			AddFluctuation(m_fConsumption_Speed);

			// エネルギー消費中
			m_bConsumption = true;
		}
		else
		{
			m_bAllRecovery = false;		// 回復できない状態にする
			m_bAllConsumption = true;	// エネルギーを全て消費した
		}
	}
}

//==============================================================================================
// 回避時のエネルギー消費
//==============================================================================================
void CEnergy_Gauge::Avoidance()
{
	if (!m_bAllConsumption)
	{
		// 消費するエネルギー量
		AddFluctuation(m_fAvoidance);

		if (GetFluctuation() < m_fBaseSize)
			// エネルギー消費中
			m_bConsumption = true;
		else
		{
			m_bAllRecovery = false;		// 回復できない状態にする
			m_bAllConsumption = true;	// エネルギーを全て消費した
		}
	}
}

//==============================================================================================
// ゲージの色
//==============================================================================================
void CEnergy_Gauge::GaugeColor()
{
	// 現在のゲージ残量の割合
	float Gauge_Percent = (m_fBaseSize - GetFluctuation()) / m_fBaseSize * 100;

	// 色の設定
	if (Gauge_Percent <= 25.0f || m_bAllConsumption && !m_bRecovery_Pause)
		// 残量25%以下or全て消費した後、全回復するまで(赤)
		SetCol({ 1.0f,0.0f,0.0f,1.0f });
	else if (Gauge_Percent > 20.0f || !m_bAllConsumption)
		// 残量26%以上(白)
		SetCol({ 1.0f,1.0f,1.0f,1.0f });

	// 後ろのゲージの色
	m_BackGauge_Col = { 0.0f,0.0f,0.0f,1.0f };

	// エネルギーを全て消費した
	if (!m_bAllRecovery && !m_bRecovery_Pause)
	{
		// 赤く点滅させる
		Col_Count++;
		m_BackGauge_Col.r = sinf(Col_Count * 0.07f);
	}
	else
	{
		// 点滅のリセット
		Col_Count = 0;

		// 黒
		m_BackGauge_Col = { 0.0f,0.0f,0.0f,1.0f };
	}

	// 後ろのゲージの色の設定
	m_pBackGauge->SetCol(m_BackGauge_Col);
}

//==============================================================================================
// ゲージ回復を一時停止
//==============================================================================================
void CEnergy_Gauge::Recovery_Pause(int count)
{
	if (m_bAllRecovery && !m_bAllConsumption)
	{
		m_bAllRecovery = false;		// 回復できない状態にする
		m_bAllConsumption = true;	// エネルギーを全て消費した
		m_bRecovery_Pause = true;	// 停止中

		BasePause_Count = count;
	}
}