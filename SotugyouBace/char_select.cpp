//==============================================================================================
//
// �L�����N�^�[�Z���N�g�@�@�@char_select.cpp
// tutida ryousei
//
//==============================================================================================
#include "char_select.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include "fontString.h"
#include "confirmation_window.h"
#include "charselect_window.h"
#include "camera.h"
#include "halfsphere.h"
#include "playerdata.h"
#include "model.h"
#include "objectX.h"

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
	//======================================
	// �����o�ϐ��̏���������
	//======================================
	m_nIndex = 0;
	m_nPlayerIndex = 0;

	m_pFont = CFontString::Create({ 280.0f, 200.0f, 0.0f }, { 50.0f, 50.0f }, "�L�����N�^�[�Z���N�g");

	// �J�����̃|�C���^
	CCamera* pCamera = CApplication::GetCamera();

	m_pPlayerData = new CPlayerData;

	pCamera->SetPosV({ 0.0f, 100.0f, -100.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 100.0f });

	m_pPlayerData->Init();

	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		m_pObjectX[nCnt] = CObjectX::Create(D3DXVECTOR3(-80.0f + 55.0f * nCnt, 600.0f, 0.0f), D3DXVECTOR3(0.0f, -0.3f + 0.5f * nCnt, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
	}
	//m_pObjectX[1] = CObjectX::Create(D3DXVECTOR3(-25.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
	//m_pObjectX[2] = CObjectX::Create(D3DXVECTOR3(30.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
	//m_pObjectX[3] = CObjectX::Create(D3DXVECTOR3(85.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");

	m_pWareHouse = CObjectX::Create(D3DXVECTOR3(0.0f, 300.0f, 1000.0f), D3DXVECTOR3(0.0f, 0.0, 0.0f), nullptr, "Data/model/CharacterSelect/Warehouse.x");

	// �n�[�t�X�t�B�A�̐���
	//m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f),  D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	//m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

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

	// �v���C���[�f�[�^
	if (m_pPlayerData != nullptr)
	{
		m_pPlayerData->Uninit();
		delete m_pPlayerData;
		m_pPlayerData = nullptr;
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

	// �v���C���[�f�[�^�̍X�V����
	if (m_pPlayerData != nullptr)
	{
		m_pPlayerData->Update();
	}

	// �L�����؂�ւ�����
	CharSwitching(2);
}

//==============================================================================================
//	�L�����؂�ւ�����
//==============================================================================================
void CChar_Select::CharSwitching(int PlayerIndex)
{
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		if (nCnt == PlayerIndex)
		{
			// ���݂̔ԍ��̎擾
			m_nIndex = m_pPlayerData->GetPlayerIndex();

			if (CChar_Select::GetConfimationWindow() != nullptr
				&& CChar_Select::GetConfimationWindow()->GetCharSelect() != nullptr)
			{
				m_nIndex = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			}

			if (m_nIndex <= -1)
			{
				m_nIndex = 3;
			}
			if (m_nIndex >= 4)
			{
				m_nIndex = 0;
			}

			// ���݂̔ԍ��ƑO�̔ԍ�����v���Ă��Ȃ�������
			if (m_nIndex != m_nIndexKeep)
			{
				// �I�u�W�F�N�gX�̍폜
				if (m_pObjectX[nCnt] != nullptr)
				{
					m_pObjectX[nCnt]->Uninit();
					m_pObjectX[nCnt] = nullptr;
				}
			}

			// �ԍ��̕ۑ�
			m_nIndexKeep = m_nIndex;

			// ���f���̐ݒ�
			if (CChar_Select::GetConfimationWindow() != nullptr)
			{
				if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
				{
					SetModel(0, "Data/model/SelectMode/view_Body_00.x");
					SetModel(1, "Data/model/SelectMode/view_Body_01.x");
					SetModel(2, "Data/model/SelectMode/view_Body_02.x");
					SetModel(3, "Data/model/SelectMode/view_Body_03.x");
				}
				else
				{
					SetModel(0, "Data/model/SelectMode/view_Body_04.x");
					SetModel(1, "Data/model/SelectMode/view_Body_05.x");
					SetModel(2, "Data/model/SelectMode/view_Body_06.x");
					SetModel(3, "Data/model/SelectMode/view_Body_07.x");
				}
			}
		}
	}
}

//==============================================================================================
// ���f���̐ݒ菈��
//==============================================================================================
void CChar_Select::SetModel(int index, const char * Xfilename)
{
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		if (m_pObjectX[nCnt] == nullptr)
		{
			if (m_nIndex == index)
			{
				m_pObjectX[nCnt] = CObjectX::Create(D3DXVECTOR3(-80.0f + 55.0f * nCnt, 600.0f, 0.0f), D3DXVECTOR3(0.0f, -0.3f, 0.0f), nullptr, Xfilename);
			}
		}
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
