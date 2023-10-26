//==============================================================================================
//
// �G���G�̗̑̓Q�[�W	�@�@mob_life_gauge.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"mob_life_gauge.h"
#include"game.h"
#include"character.h"

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CMob_Life_Gauge::CMob_Life_Gauge(const PRIORITY priority) : CObject3D(priority)
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CMob_Life_Gauge::~CMob_Life_Gauge()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CMob_Life_Gauge::Init()
{
	CObject3D::Init();

	// �Q�[�W�̌��̒���
	m_nBase_GaugeSize = (int)GetScale().x;

	m_BackGauge = CObject3D::Create(GetPos(), GetScale(), PRIORITY_CENTER);
	m_BackGauge->SetCol({ 0.0f,0.0f,0.0f,1.0f });
	m_BackGauge->Setbillboard(true);

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CMob_Life_Gauge::Uninit()
{
	CObject3D::Uninit();
}

//==============================================================================================
// �X�V����
//==============================================================================================
void CMob_Life_Gauge::Update()
{
	SetPos(m_Pos);
	m_BackGauge->SetPos(m_Pos);

	// �G���G�̏��
	std::vector<CCharacter*> Mob = CGame::GetMob();

	if (Mob[m_nGauge_Index] != nullptr)
	{
		// �G�̌��̗̑�
		if (m_nMob_Base_Life == 0)
			m_nMob_Base_Life = Mob[m_nGauge_Index]->GetLife();

		// ���݂̗̑͂̊���
		float Life_Percent = (float)Mob[m_nGauge_Index]->GetLife() / m_nMob_Base_Life * 100;

		// �Q�[�W�T�C�Y�𓯂������ɂ���
		float Gauge_Percent = GetScale().x * Life_Percent / 100;

		// �Q�[�W�̑���
		SetSubSize({ m_nBase_GaugeSize - Gauge_Percent, 0.0f });
	}

	CObject3D::Update();
}

//==============================================================================================
// �`�揈��
//==============================================================================================
void CMob_Life_Gauge::Draw()
{
	//if (m_bDraw)
		CObject3D::Draw();
}

//==============================================================================================
// ��������
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