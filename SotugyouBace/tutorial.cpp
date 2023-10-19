//==============================================================================================
//
// �`���[�g���A���@�@�@tutorial.cpp
// tutida ryousei
//
//==============================================================================================
#include"tutorial.h"
#include"camera.h"
#include"application.h"
#include"player_manager.h"
#include"halfsphere.h"
#include"meshfield.h"
#include"energy_gauge.h"
#include"input.h"
#include"fade.h"
#include"fontString.h"

CMeshField *CTutorial::pMeshField = nullptr;			// ���b�V���t�B�[���h
CEnergy_Gauge *CTutorial::m_pEnergy_Gauge = nullptr;	// �G�l���M�[�Q�[�W

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CTutorial::CTutorial()
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CTutorial::~CTutorial()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CTutorial::Init()
{
	CFontString::Create({ 390.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "�`���[�g���A��");

	// �J�����̃|�C���^
	CCamera* pCamera = CApplication::GetCamera();

	// ���_�A�����_�̐ݒ�
	pCamera->SetPosV({ 0.0f, 500.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 250.0f, 1000.0f });

	// �v���C���[�̐���(�e�X�g)
	CApplication::GetPlayerManager()->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0);

	// �n�[�t�X�t�B�A�̐���
	CHalfSphere *pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(20000.0f, 20000.0f, 20000.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	// ���b�V���t�B�[���h�̐���
	pMeshField = CMeshField::Create({ 0.0f, 0.0f, 0.0f }, 10, 10, 4000.0f);

	// �G�l���M�[�Q�[�W
	m_pEnergy_Gauge = CEnergy_Gauge::Create({ 1280.0f / 2, 650.0f, 0.0f }, { 800.0f, 10.0f });

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CTutorial::Uninit()
{
}

//==============================================================================================
// �X�V����
//==============================================================================================
void CTutorial::Update()
{
	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			CFade::SetFade(CApplication::MODE_GAME, 0.05f);
		}
	}
}

//==============================================================================================
// ��������
//==============================================================================================
CTutorial *CTutorial::Create()
{
	CTutorial* pTutorial = new CTutorial;

	if (FAILED(pTutorial->Init()))
	{
		return nullptr;
	}

	return pTutorial;
}