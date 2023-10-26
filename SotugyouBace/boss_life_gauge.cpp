//==============================================================================================
//
// ボスの体力ゲージ	　　boss_life_gauge.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"boss_life_gauge.h"
#include"game.h"
#include"character.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CBoss_Life_Gauge::CBoss_Life_Gauge()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CBoss_Life_Gauge::~CBoss_Life_Gauge()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CBoss_Life_Gauge::Init()
{
	SetCol({ 1.0f,0.0f,0.0f,1.0f });

	// 後ろのゲージの色
	SetBackCol({ 0.0f,0.0f,0.0f,1.0f });

	CGauge_Manager::Init();

	// ゲージの元の長さ
	SetBeaseSize((int)GetGaugeSize().x);

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CBoss_Life_Gauge::Uninit()
{
	CGauge_Manager::Uninit();
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CBoss_Life_Gauge::Update()
{
	CGauge_Manager::Update();
}

//==============================================================================================
// 描画処理
//==============================================================================================
void CBoss_Life_Gauge::Draw()
{
	CGauge_Manager::Draw();
}

//==============================================================================================
// ゲージの増減
//==============================================================================================
void CBoss_Life_Gauge::Fluctuation()
{
	CCharacter *pBoss = CGame::GetBoss();

	if (pBoss != nullptr)
	{
		// 現在の体力の割合
		float Life_Percent = (float)pBoss->GetLife() / GetBeaseLife() * 100;

		// ゲージサイズを同じ割合にする
		float Gauge_Percent = GetGaugeSize().x * Life_Percent / 100;

		// ゲージの増減
		SetSubSize({ GetBeaseSize() - Gauge_Percent, 0.0f });
	}
}

//==============================================================================================
// 生成処理
//==============================================================================================
CBoss_Life_Gauge *CBoss_Life_Gauge::Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size)
{
	CBoss_Life_Gauge *pBoss_Life_Gauge = new CBoss_Life_Gauge;
	
	if (pBoss_Life_Gauge != nullptr)
	{
		pBoss_Life_Gauge->SetGaugePos(pos);
		pBoss_Life_Gauge->SetGaugeSize(size);
		pBoss_Life_Gauge->Init();
	}

	return pBoss_Life_Gauge;
}