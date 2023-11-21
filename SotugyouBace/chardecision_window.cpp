//============================================================================
//
// chardecision_window.cpp (�L��������E�B���h�E.cpp)
// Author : Saito Shian
//
//============================================================================

//============================================================================
// �C���N���[�h
//============================================================================
#include "chardecision_window.h"
#include "application.h"
#include "renderer.h"
#include "object2D.h"
#include "menu.h"
#include "fade.h"
#include "input.h"
#include "game.h"
#include "title.h"
#include "menu_window.h"
#include "title_menu.h"
#include "texture.h"
#include "confirmation_window.h"
#include "charselect_window.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CObject2D* CCharDecision_Window::m_pObject2D[MAX_TEXTURE] = {};

//============================================================================
// �R���X�g���N�^
//============================================================================
CCharDecision_Window::CCharDecision_Window()
{
}

//============================================================================
// �f�X�g���N�^
//============================================================================
CCharDecision_Window::~CCharDecision_Window()
{
}

//============================================================================
// ����������
//============================================================================
HRESULT CCharDecision_Window::Init()
{
	//==================================================
	// �����o�ϐ��̏�����
	//==================================================  
	m_nSelectChoice = 0;
	m_SizeX = 0.0f;
	m_SizeY = 0.0f;
	m_bScale = false;
	m_bMaxSize = false;
	m_bUninitFlag = false;
	m_bSpawnWindow = false;
	m_bDecition = false;
	m_pObject2D[0] = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D[0]->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CCharDecision_Window::Uninit()
{
	//�����o�ϐ��̏�����
	for (int nCnt = 0; nCnt < MAX_TEXTURE; nCnt++)
	{
		if (m_pObject2D[nCnt] != nullptr)
		{
			m_pObject2D[nCnt]->Uninit();
			m_pObject2D[nCnt] = nullptr;
		}
	}
}

//============================================================================
// �X�V����
//============================================================================
void CCharDecision_Window::Update()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	if (m_bScale == false)
	{// �g�傳��Ă��Ȃ���

	 // �E�B���h�E�̊g�又��
		CharDecisionMenuScale();
	}

	if (pInput->Trigger(DIK_RETURN) && CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		CFade::SetFade(CApplication::MODE_GAME, 0.05f);
	}
}

//============================================================================
// �E�B���h�E�̊g�又��
//============================================================================
void CCharDecision_Window::CharDecisionMenuScale()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	if (m_pObject2D != nullptr)
	{// null�`�F�b�N

	 // �T�C�Y�̊g��
		m_SizeX += SizeXScaleSpeed;
		m_SizeY += SizeYScaleSpeed;

		if (m_SizeX >= m_MaxSizeX)
		{// X�T�C�Y�̍ő�
			m_SizeX = m_MaxSizeX;
		}
		if (m_SizeY >= m_MaxSizeY)
		{// Y�T�C�Y�̍ő�
			m_SizeY = m_MaxSizeY;
		}

		// �E�B���h�E���ő�l�܂ōs������
		if (m_SizeX >= m_MaxSizeX && m_SizeY >= m_MaxSizeY && m_bMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_GAME)
			{
				pInput->SetKeyLock(100);
			}

			if (m_pObject2D[1] == nullptr)
			{
				m_pObject2D[1] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 500.0f, 0.0f), D3DXVECTOR2(700.0f, 250.0f), CObject::PRIORITY_SCREEN);
				m_pObject2D[1]->SetTexture(CTexture::TEXTURE_FONT_JAPANESE);
			}
			if (m_pObject2D[2] == nullptr)
			{
				m_pObject2D[2] = CObject2D::Create(D3DXVECTOR3(500.0f, 250.0f, 0.0f), D3DXVECTOR2(175.0f, 175.0f), CObject::PRIORITY_SCREEN);
				m_pObject2D[2]->SetTexture(CTexture::TEXTURE_FLOOR);
			}

			m_bMaxSize = true;
			m_bScale = true;
			return;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D[0]->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
}

//============================================================================
// �E�B���h�E�̏k������
//============================================================================
bool CCharDecision_Window::CharDecisionMenuScaleReduce()
{
	if (m_pObject2D != nullptr)
	{// null�`�F�b�N

	 // �T�C�Y�̏k��
		m_SizeX -= SizeXScaleSpeed;
		m_SizeY -= SizeYScaleSpeed;

		if (m_SizeX <= 0.0f)
		{// X�T�C�Y�̍ŏ�
			m_SizeX = 0.0f;
		}
		if (m_SizeY <= 0.0f)
		{// Y�T�C�Y�̍ŏ�
			m_SizeY = 0.0f;
		}

		// �t�H���g�̍폜
		if (m_pFont != nullptr)
		{
			m_pFont->Uninit();
			m_pFont = nullptr;
		}

		// �E�B���h�E���ŏ��l�܂ōs������
		if (m_SizeX <= 0.0f && m_SizeY <= 0.0f)
		{
			SetUninit(false);
			SetSapawnWindow(true);
			CGame::SetGameWindow(true);
			Uninit();						// ���j���[�E�B���h�E�̍폜
			return true;
		}
		// �T�C�Y�̐ݒ�
		m_pObject2D[0]->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
	return false;
}

//============================================================================
// �t�H���g�̐ݒ菈��
//============================================================================
void CCharDecision_Window::SetFont(const std::string lette[])
{
	if (m_pFont == nullptr)
	{
		m_pFont = CFontString::Create(D3DXVECTOR3(750.0f, 200.0f, 0.0f), { 25.0f, 25.0f }, lette[0]);
		m_pFont = CFontString::Create(D3DXVECTOR3(650.0f, 300.0f, 0.0f), { 35.0f, 35.0f }, lette[1]);
	}
}

//============================================================================
// �t�H���g�̔j������
//============================================================================
void CCharDecision_Window::UninitFont()
{
	if (m_pFont != nullptr)
	{
		m_pFont->Uninit();
		delete m_pFont;
		m_pFont = nullptr;
	}
}

//============================================================================
// ��������
//============================================================================
CCharDecision_Window * CCharDecision_Window::Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col)
{
	//�N���X�̐���
	CCharDecision_Window* pCharDecision = new CCharDecision_Window;

	//null�`�F�b�N
	if (pCharDecision != nullptr)
	{
		pCharDecision->m_pos = pos;
		pCharDecision->m_Color = col;
		pCharDecision->m_MaxSizeX = xsize;
		pCharDecision->m_MaxSizeY = ysize;
		//����������
		pCharDecision->Init();
	}
	else
	{
		assert(false);
	}

	return pCharDecision;
}
