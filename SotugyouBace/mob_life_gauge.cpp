//==============================================================================================
//
// 雑魚敵の体力ゲージ	　　mob_life_gauge.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"mob_life_gauge.h"
#include"game.h"
#include"character.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CMob_Life_Gauge::CMob_Life_Gauge(const PRIORITY priority) : CObject3D(priority)
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CMob_Life_Gauge::~CMob_Life_Gauge()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CMob_Life_Gauge::Init()
{
	CObject3D::Init();

	// ゲージの元の長さ
	m_nBase_GaugeSize = (int)GetScale().x;

	m_BackGauge = CObject3D::Create(GetPos(), GetScale(), PRIORITY_CENTER);
	m_BackGauge->SetCol({ 0.0f,0.0f,0.0f,1.0f });
	m_BackGauge->Setbillboard(true);

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CMob_Life_Gauge::Uninit()
{
	CObject3D::Uninit();
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CMob_Life_Gauge::Update()
{
	SetPos(m_Pos);
	m_BackGauge->SetPos(m_Pos);

	// 雑魚敵の情報
	std::vector<CCharacter*> Mob = CGame::GetMob();

	if (Mob[m_nGauge_Index] != nullptr)
	{
		// 敵の元の体力
		if (m_nMob_Base_Life == 0)
			m_nMob_Base_Life = Mob[m_nGauge_Index]->GetLife();

		// 現在の体力の割合
		float Life_Percent = (float)Mob[m_nGauge_Index]->GetLife() / m_nMob_Base_Life * 100;

		// ゲージサイズを同じ割合にする
		float Gauge_Percent = GetScale().x * Life_Percent / 100;

		// ゲージの増減
		SetSubSize({ m_nBase_GaugeSize - Gauge_Percent, 0.0f });
	}

	CObject3D::Update();
}

//==============================================================================================
// 描画処理
//==============================================================================================
void CMob_Life_Gauge::Draw()
{
	//if (m_bDraw)
		CObject3D::Draw();
}

//==============================================================================================
// 生成処理
//==============================================================================================
CMob_Life_Gauge *CMob_Life_Gauge::Create(const D3DXVECTOR3 &pos, D3DXVECTOR2 size, int index)
{
	CMob_Life_Gauge *pMob_Life_Gauge = new CMob_Life_Gauge(PRIORITY_FRONT);

	if (pMob_Life_Gauge != nullptr)
	{
		pMob_Life_Gauge->SetPos(pos);
		pMob_Life_Gauge->SetSize(size);
		pMob_Life_Gauge->SetIndex(index);
		pMob_Life_Gauge->Setbillboard(true);
		pMob_Life_Gauge->Init();
	}

	return pMob_Life_Gauge;
}