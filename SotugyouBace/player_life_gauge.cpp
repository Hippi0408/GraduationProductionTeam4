//==============================================================================================
//
// プレイヤーの体力ゲージ	　　player_life_gauge.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"player_life_gauge.h"
#include"player_manager.h"
#include"application.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CPlayer_Life_Gauge::CPlayer_Life_Gauge(const PRIORITY priority) : CGauge_Manager(priority)
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CPlayer_Life_Gauge::~CPlayer_Life_Gauge()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CPlayer_Life_Gauge::Init()
{
	CGauge_Manager::Init();

	// 後ろのゲージの色
	SetBackCol({ 0.0f,0.0f,0.0f,1.0f });

	// ゲージの元の長さ
	SetBeaseSize((int)GetGaugeSize().y);

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CPlayer_Life_Gauge::Uninit()
{
	CGauge_Manager::Uninit();
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CPlayer_Life_Gauge::Update()
{
	CGauge_Manager::Update();
}

//==============================================================================================
// 描画処理
//==============================================================================================
void CPlayer_Life_Gauge::Draw()
{
	CGauge_Manager::Draw();
}

//==============================================================================================
// 生成処理
//==============================================================================================
CPlayer_Life_Gauge *CPlayer_Life_Gauge::Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size)
{
	CPlayer_Life_Gauge *pPlayer_Life_Gauge = new CPlayer_Life_Gauge(PRIORITY_SCREEN);

	if (pPlayer_Life_Gauge != nullptr)
	{
		pPlayer_Life_Gauge->SetGaugePos(pos);
		pPlayer_Life_Gauge->SetGaugeSize(size);
		pPlayer_Life_Gauge->Init();
	}

	return pPlayer_Life_Gauge;
}

//==============================================================================================
// ゲージの増減
//==============================================================================================
void CPlayer_Life_Gauge::Fluctuation()
{
	CPlayerManager *pPlayerManager = CApplication::GetPlayerManager();
	CPlayer *pPlayer = nullptr;

	if (pPlayerManager != nullptr)
	{
		pPlayer = pPlayerManager->GetPlayer(0);
	}

	if (pPlayer != nullptr)
	{
		// 現在の体力の割合
		m_fLife_Percent = (float)pPlayer->GetLife() / GetBeaseLife() * 100;

		// ゲージサイズを同じ割合にする
		float Gauge_Percent = GetGaugeSize().y * m_fLife_Percent / 100;

		// ゲージの増減
		SetSubSize({ 0.0f, -GetBeaseSize() + Gauge_Percent });
	}

	// 色の設定
	Col();
}

//==============================================================================================
// 色の設定
//==============================================================================================
void CPlayer_Life_Gauge::Col()
{
	// 現在の体力の割合
	if (m_fLife_Percent <= 25.0f)
		SetCol({ 1.0f,0.0f,0.0f,1.0f });
	else
		SetCol({ 1.0f,1.0f,1.0f,1.0f });
}