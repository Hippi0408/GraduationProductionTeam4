//==============================================================================================
//
// �L�����N�^�[�Z���N�g�@�@�@char_select.cpp
// tutida ryousei
//
//==============================================================================================
#include"char_select.h"
#include"input.h"
#include"application.h"
#include"fade.h"
#include"fontString.h"
#include"confirmation_window.h"
#include "camera.h"
#include "halfsphere.h"

//==============================================================================================
// �ÓI�����o�ϐ��錾
//==============================================================================================
CConfirmation_Window* CChar_Select::m_pConfirmation = nullptr;

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CChar_Select::CChar_Select()
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CChar_Select::~CChar_Select()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CChar_Select::Init()
{
	m_pFont = CFontString::Create({ 280.0f, 200.0f, 0.0f }, { 50.0f, 50.0f }, "�L�����N�^�[�Z���N�g");

	// �J�����̃|�C���^
	CCamera* pCamera = CApplication::GetCamera();

	pCamera->SetPosV({ 0.0f, 2000.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 2000.0f, 1000.0f });

	// �n�[�t�X�t�B�A�̐���
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f),  D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CChar_Select::Uninit()
{
	// ���j���[�E�B���h�E�̏I������
	if (m_pConfirmation != nullptr)
	{
		m_pConfirmation->Uninit();
		delete m_pConfirmation;
		m_pConfirmation = nullptr;
	}
}

//==============================================================================================
// �X�V����
//==============================================================================================
void CChar_Select::Update()
{
	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			if (m_pConfirmation == nullptr)
			{
				m_pConfirmation = CConfirmation_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 450.0f, 0.0f), 500.0f, 120.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
			}
		}

		//// �L�����Z���N�g��ʂɖ߂�
		//if (pInput->Trigger(DIK_BACK, nCnt)
		//	&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		//{
		//	// ��ʑJ��
		//	CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
		//}
	}

	if (m_pConfirmation != nullptr)
	{
		m_pConfirmation->Update();

		/*if (m_pConfirmation->GetSelectChoice() == true)
		{
			CFade::SetFade(CApplication::MODE_STAGE_SELECT, 0.05f);
		}*/
	}

	// �E�B���h�E�������ꍇ 
	if (m_pConfirmation != nullptr && m_pConfirmation->GetSapawnWindow() == true)
	{
		m_pConfirmation->SetSapawnWindow(false);
		delete m_pConfirmation;
		m_pConfirmation = nullptr;
	}
}

//==============================================================================================
// ��������
//==============================================================================================
CChar_Select* CChar_Select::Create()
{
	CChar_Select* pChar_Select = new CChar_Select;

	if (FAILED(pChar_Select->Init()))
	{
		return nullptr;
	}

	return pChar_Select;
}
