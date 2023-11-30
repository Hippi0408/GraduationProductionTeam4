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
#include "char_select.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
const float CCharDecision_Window::BLINK_SPEED = 0.02f;	// �I�����̓_�ő��x
const float CCharDecision_Window::MINI_ALPHA = 0.5f;	// �I�����̍Œᓧ���l

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
	m_nSelectIndex = 0;
	index = 0;
	m_SizeX = 0.0f;
	m_SizeY = 0.0f;
	m_fMoveX = 50.0f;
	m_bScale = false;
	m_bMaxSize = false;
	m_bUninitFlag = false;
	m_bFontFlag = false;
	m_bDecition = false;
	m_bDisplay = false;
	m_bStopFlag = false;
	m_bPosDest = false;
	m_bExplanationUninit = false;
	m_pWindow = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pWindow->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CCharDecision_Window::Uninit()
{
	//�����o�ϐ��̏�����
	if (m_pWindow != nullptr)
	{
		m_pWindow->Uninit();
		m_pWindow = nullptr;
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

	if (pInput->Trigger(DIK_RETURN)
		&& m_bMaxSize == true
		&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		UninitExplanation();				// �t�H���g�̍폜
		// ��ʑJ��
		CFade::SetFade(CApplication::MODE_GAME, 0.1f);
	}

	// �L�����̕ύX����
	CharSelectChoice();
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

		//// �g��X�L�b�v
		//if (pInput->Trigger(DIK_RETURN) && m_bMaxSize == false)
		//{
		//	m_SizeX = m_MaxSizeX;
		//	m_SizeY = m_MaxSizeY;
		//	// �T�C�Y�̐ݒ�
		//	m_pWindow->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
		//}

		// �E�B���h�E���ő�l�܂ōs������
		if (m_SizeX >= m_MaxSizeX && m_SizeY >= m_MaxSizeY && m_bMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_GAME)
			{
				pInput->SetKeyLock(100);
			}

			if (m_bUninitFlag == false && m_bScale == true)
			{
				m_bMaxSize = true;
				m_bFontFlag = false;
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(m_nSelectIndex);
			}

			m_bMaxSize = true;
			m_bScale = true;
			return;
		}

		// �T�C�Y�̐ݒ�
		m_pWindow->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
}

//=============================================================================
// �I�����̏���
//=============================================================================
void CCharDecision_Window::CharSelectChoice()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	D3DXVECTOR3 pos = m_pWindow->GetPos();

	// �t�F�[�h���ł͖����ꍇ && �\�����̏ꍇ
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		// ���Ɉړ�����
		if (pInput->Trigger(DIK_A) && m_bStopFlag == false || (pInput->Trigger(JOYPAD_UP, m_nMenuInitiative)) && m_bStopFlag == false)
		{
			index = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			index--;
			m_bUninitFlag = true;
			m_bDecition = false;
			m_bPosDest = false;
			m_bStopFlag = true;
			// �I��SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

		}
		// ���Ɉړ�����
		else if (pInput->Trigger(DIK_D) && m_bStopFlag == false || (pInput->Trigger(JOYPAD_DOWN, m_nMenuInitiative)) && m_bStopFlag == false)
		{
			index = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			index++;
			m_bUninitFlag = true;
			m_bDecition = true;
			m_bPosDest = false;
			m_bStopFlag = true;
			// �I��SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);
		}
	}

	if (m_bUninitFlag == true)
	{
		// ���ړ�
		if (m_bDecition == false)
		{
			m_bExplanationUninit = true;
			UninitExplanation();				// �t�H���g�̍폜
			pos.x -= m_fMoveX;
			if (pos.x <= -SCREEN_WIDTH / 2 && m_bPosDest == false)
			{
				pos.x = 1920.0f;
				m_bPosDest = true;
			}
			if (pos.x <= SCREEN_WIDTH / 2 && m_bPosDest == true)
			{
				pos.x = SCREEN_WIDTH / 2;
				m_bFontFlag = false;
				m_bStopFlag = false;
				m_bExplanationUninit = false;
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(index);
			}
		}
		// �E�ړ�
		else
		{
			m_bExplanationUninit = true;
			UninitExplanation();				// �t�H���g�̍폜
			pos.x += m_fMoveX;
			if (pos.x >= 1920.0f && m_bPosDest == false)
			{
				pos.x = -SCREEN_WIDTH / 2;
				m_bPosDest = true;
			}
			if (pos.x >= SCREEN_WIDTH / 2 && m_bPosDest == true)
			{
				pos.x = SCREEN_WIDTH / 2;
				m_bFontFlag = false;
				m_bStopFlag = false;
				m_bExplanationUninit = false;
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(index);
			}
		}
		m_pWindow->SetPos(pos);
	}
}

//============================================================================
// �t�H���g�̐ݒ菈��
//============================================================================
void CCharDecision_Window::SetFont(const std::string lette[])
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_pFont[nCnt] == nullptr && m_bFontFlag == false)
		{
			m_pFont[0] = CFontString::Create(D3DXVECTOR3(750.0f, 200.0f, 0.0f), { 25.0f, 25.0f }, lette[0]);
			m_pFont[1] = CFontString::Create(D3DXVECTOR3(650.0f, 300.0f, 0.0f), { 35.0f, 35.0f }, lette[1]);
			m_bFontFlag = true;
		}
	}
}

//============================================================================
// �e�N�X�`���̐ݒ菈��
//============================================================================
void CCharDecision_Window::SetTextue(CTexture::TEXTURE texture, CTexture::TEXTURE texture1)
{
	if (m_pObject2D[0] == nullptr)
	{
		m_pObject2D[0] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 500.0f, 0.0f), D3DXVECTOR2(700.0f, 250.0f), CObject::PRIORITY_SCREEN);
		m_pObject2D[0]->SetTexture(texture1);
	}
	if (m_pObject2D[1] == nullptr)
	{
		m_pObject2D[1] = CObject2D::Create(D3DXVECTOR3(500.0f, 250.0f, 0.0f), D3DXVECTOR2(175.0f, 175.0f), CObject::PRIORITY_SCREEN);
		m_pObject2D[1]->SetTexture(texture);
	}
}

//============================================================================
// �����p�e�N�X�`���A�t�H���g�̔j������
//============================================================================
void CCharDecision_Window::UninitExplanation()
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_pFont[nCnt] != nullptr)
		{
			m_pFont[nCnt]->Uninit();
			m_pFont[nCnt] = nullptr;
		}
	}

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