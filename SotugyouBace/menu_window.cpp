//=============================================================================
//
// menu_window.h (���j���[�E�B���h�E.h)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "menu_window.h"
#include "object2D.h"
#include "menu.h"
#include "title.h"
#include "title_menu.h"
#include "confirmation_window.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CMenuWindow::CMenuWindow()
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CMenuWindow::~CMenuWindow()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CMenuWindow::Init()
{
	//==================================================
	// �����o�ϐ��̏�����
	//==================================================  
	SizeX = 0.0f;
	SizeY = 0.0f;
	m_bScaleFlag = false;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 450.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f),CObject::PRIORITY_FRONT);
	m_pObject2D->SetCol(D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f));

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CMenuWindow::Uninit()
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
void CMenuWindow::Update()
{
	if (CTitle::GetUninitWindow() == false && m_bScaleFlag == false)
	{ // ���j���[�̃T�C�Y�g�又��
		MenuScale();
	}
}

//=============================================================================
// ���j���[�̃T�C�Y�g�又��
//=============================================================================
void CMenuWindow::MenuScale()
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
			CTitle::SetWindow(true);						// �E�B���h�E���g�p���Ă����Ԃɂ���
			m_bScaleFlag = true;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
}

//=============================================================================
// ���j���[�̃T�C�Y�k����������
//=============================================================================
bool CMenuWindow::MenuScaleReduce()
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
			CTitleMenu::GetComfirmationWindow()->SetSapawnWindow(false);
			if (CTitleMenu::GetComfirmationWindow()->GetSelectChoice() == true)
			{
				DestroyWindow(CApplication::GetWindow());
			}
		
			//Uninit();						// ���j���[�E�B���h�E�̍폜
			CTitle::UninitMenuWindow();
			CTitleMenu::UninitComfirmationWindow();
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
CMenuWindow* CMenuWindow::Create()
{
	//�N���X�̐���
	CMenuWindow* pMenuWindow = new CMenuWindow;

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