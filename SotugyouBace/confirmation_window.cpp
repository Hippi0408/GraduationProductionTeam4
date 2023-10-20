//=============================================================================
//
// confirmation_window.h (���j���[�E�B���h�E.h)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "confirmation_window.h"
#include "object2D.h"
#include "menu.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CConfirmation_Window::CConfirmation_Window()
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CConfirmation_Window::~CConfirmation_Window()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CConfirmation_Window::Init()
{
	//==================================================
	// �����o�ϐ��̏�����
	//==================================================  
	SizeX = 0.0f;
	SizeY = 0.0f;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_FRONT);
	m_pObject2D->SetCol(D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f));

	//// �I�����̐ݒ菈��
	//CApplication::GetMenu()->SetChoice(CFontString::Create({ 400.0f, 300.0f, 0.0f }, { 40.0f, 40.0f }, "�͂�"));
	//CApplication::GetMenu()->SetChoice(CFontString::Create({ 800.0f / 2, 400.0f ,0.0f }, { 40.0f, 40.0f }, "������"));

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CConfirmation_Window::Uninit()
{
	//�����o�ϐ��̏�����
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CConfirmation_Window::Update()
{
	// ���j���[�̃T�C�Y�g�又��
	ConfirmatiomnMenuScale();
}

//=============================================================================
// ���j���[�̃T�C�Y�g�又��
//=============================================================================
void CConfirmation_Window::ConfirmatiomnMenuScale()
{
	if (m_pObject2D != nullptr)
	{// null�`�F�b�N
	 // �T�C�Y�̊g��
		SizeX += SizeXScaleSpeed;
		SizeY += SizeYScaleSpeed;

		if (SizeX >= SizeXScaleMax)
		{// X�T�C�Y�̍ő�
			SizeX = SizeXScaleMax;
		}
		if (SizeY >= SizeYScaleMax)
		{// Y�T�C�Y�̍ő�
			SizeY = SizeYScaleMax;
		}

		// �E�B���h�E���ő�l�܂ōs������
		if (SizeX >= SizeXScaleMax && SizeY >= SizeYScaleMax)
		{
			CApplication::GetMenu()->SetDisplay(true);		// ���j���[��ʂ̕\��
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
}

//=============================================================================
// ���j���[�̃T�C�Y�k����������
//=============================================================================
bool CConfirmation_Window::ConfirmatiomnMenuScaleReduce()
{
	if (m_pObject2D != nullptr)
	{// null�`�F�b�N
	 // �T�C�Y�̏k��
		SizeX -= SizeXScaleSpeed;
		SizeY -= SizeYScaleSpeed;

		if (SizeX <= 0.0f)
		{// X�T�C�Y�̍ŏ�
			SizeX = 0.0f;
		}
		if (SizeY <= 0.0f)
		{// Y�T�C�Y�̍ŏ�
			SizeY = 0.0f;
		}

		// �E�B���h�E���ŏ��l�܂ōs������
		if (SizeX <= 0.0f && SizeY <= 0.0f)
		{
			Uninit();						// ���j���[�E�B���h�E�̍폜
			return true;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
	return false;
}

//=============================================================================
// �^�C���̐���
//=============================================================================
CConfirmation_Window* CConfirmation_Window::Create()
{
	//�N���X�̐���
	CConfirmation_Window* pMenuWindow = new CConfirmation_Window;

	//null�`�F�b�N
	if (pMenuWindow != nullptr)
	{
		//����������
		pMenuWindow->Init();
	}
	else
	{
		assert(false);
	}

	return pMenuWindow;
}