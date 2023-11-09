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
	CFontString::Create({ 280.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "�L�����N�^�[�Z���N�g");

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
				m_pConfirmation = CConfirmation_Window::Create("", "�X�g���C�J�[", "�R�}���_�[",D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
			}
		}

		// �L�����Z���N�g��ʂɖ߂�
		if (pInput->Trigger(DIK_BACK, nCnt)
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			// ��ʑJ��
			CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
		}
	}

	if (m_pConfirmation != nullptr)
	{
		m_pConfirmation->Update();
		if (m_pConfirmation->GetSelectChoice() == true && m_pConfirmation->GetDecition() == true)
		{
			CFade::SetFade(CApplication::MODE_STAGE_SELECT, 0.05f);
		}
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
