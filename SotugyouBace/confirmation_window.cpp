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
#include "fade.h"
#include "input.h"
#include "game.h"
#include "title.h"
#include "menu_window.h"
#include "title_menu.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
const float CConfirmation_Window::BLINK_SPEED = 0.02f;	// �I�����̓_�ő��x
const float CConfirmation_Window::MINI_ALPHA = 0.5f;	// �I�����̍Œᓧ���l

bool CConfirmation_Window::m_bSpawnWindow = false;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CConfirmation_Window::CConfirmation_Window() : m_bSelectChoice(1), m_fBlinkSpeed(BLINK_SPEED)
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
	m_bScale = false;
	m_bMaxSize = false;
	m_bUninitFlag = false;
	m_bSpawnWindow = false;
	m_bSelectChoice = false;
	m_bDecition = false;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

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
	if (m_bScale == false)
	{// �g�傳��Ă��Ȃ���

		// �E�B���h�E�̊g�又��
		ConfirmatiomnMenuScale();
	}
	if (m_bScale == true)
	{// �g�債����

		// �E�B���h�E�̏k������
		ConfirmatiomnMenuScaleReduce();
	}
	// �I��������
	Choice();
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
		if (SizeX >= SizeXScaleMax && SizeY >= SizeYScaleMax && m_bMaxSize == false)
		{
			if (m_pFont == nullptr)
			{
				m_pFont = CFontString::Create({ 420.0f, 350.0f, 0.0f }, { 30.0f, 30.0f }, m_Letter[0]);
			}

			// �I�����̐ݒ菈��
			SetChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 40.0f, 40.0f }, m_Letter[1]));
			SetChoice(CFontString::Create({ 700.0f, 450.0f, 0.0f }, { 40.0f, 40.0f }, m_Letter[2]));

			// �I�������g�p����Ă���ꍇ
			if (!m_vpListChoice.empty())
			{
				for (auto pChoice : GetChoiceAll())
				{
					pChoice->SetAlpha(MINI_ALPHA);
				}
				// �I������Ă���I����
				m_vpListChoice[m_bSelectChoice]->SetBlink(BLINK_SPEED);
				m_vpListChoice[m_bSelectChoice]->SetAlpha(1.0f);
			}
			SetDisplay(true);
			m_bMaxSize = true;
			return;
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

		// �t�H���g�̍폜
		if (m_pFont != nullptr)
		{
			m_pFont->Uninit();
			m_pFont = nullptr;
		}

		// �E�B���h�E���ŏ��l�܂ōs������
		if (SizeX <= 0.0f && SizeY <= 0.0f)
		{
			
			m_bSpawnWindow = true;
			
			CGame::SetGameWindow(true);

			Uninit();						// ���j���[�E�B���h�E�̍폜
			return true;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
	return false;
}

//============================================================================
// �I�����̏���
//============================================================================
void CConfirmation_Window::Choice()
{
	// �t�F�[�h���ł͖����ꍇ && �\�����̏ꍇ
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE && m_bDisplay == true)
	{
		// �I�������g�p����Ă���ꍇ
		if (!m_vpListChoice.empty())
		{
			// ���̓f�o�C�X�̏��
			CInput* pInput = CInput::GetKey();

			// �I������2�ȏ�g�p����Ă���ꍇ
			if (m_vpListChoice.size() >= 2)
			{
				// ��Ɉړ�����
				if (pInput->Trigger(DIK_Q) || (pInput->Trigger(JOYPAD_UP, m_nMenuInitiative)))
				{
					// �I��SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// ���݂̔ԍ���0�ȉ��ł���ꍇ
					ChangeChoice(false);
				}
				// ���Ɉړ�����
				else if (pInput->Trigger(DIK_E) || (pInput->Trigger(JOYPAD_DOWN, m_nMenuInitiative)))
				{
					// �I��SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// ���݂̔ԍ����ő吔�ȏ�̏ꍇ
					ChangeChoice(true);
				}
			}

			if (pInput->Trigger(DIK_RETURN) || (pInput->Trigger(JOYPAD_B, m_nMenuInitiative) || pInput->Trigger(JOYPAD_A, m_nMenuInitiative)))
			{
				// ����SE
				CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

				// �I�������肷��
				m_bDecition = true;
			}

			// ���肳�ꂽ�ꍇ
			if (m_bDecition == true)
			{
				// �͂��̏ꍇ
				if (m_bSelectChoice == false)
				{
					m_bScale = true;
					SetDisplay(false);
					m_bSelectChoice = true;
				}
				// �������̏ꍇ
				else
				{
					m_bScale = true;
					SetDisplay(false);
					m_bSelectChoice = false;
				}
			}
		}
	}
	if (m_bSpawnWindow == true && CTitle::GetMenuWindow() != nullptr)
	{
		CApplication::GetMenu()->SetDisplay(false);
		CTitle::GetMenuWindow()->MenuScaleReduce();
	}
}

//============================================================================
// �I������ύX�������̏���
//============================================================================
void CConfirmation_Window::ChangeChoice(const bool nextChoice)
{
	// ���݂̑I�����̏���
	m_vpListChoice[m_bSelectChoice]->BlinkFinish();
	m_vpListChoice[m_bSelectChoice]->SetAlpha(MINI_ALPHA);

	// �I�����̕ύX
	m_bSelectChoice = (int)nextChoice;

	// �ύX��̑I�����̏���
	m_vpListChoice[m_bSelectChoice]->SetBlink(m_fBlinkSpeed);
	m_vpListChoice[m_bSelectChoice]->SetAlpha(1.0f);
}

//============================================================================
// �I�����̕\�������ݒ肷��
//============================================================================
void CConfirmation_Window::SetDisplay(const bool decition)
{
	m_bDisplay = decition;
	for (auto pChoice : GetChoiceAll()) { pChoice->SetFontDraw(decition); }

	// �\���������ꍇ
	if (decition == false)
	{
		// �I�����̏�������������
		ChangeChoice(0);
	}
}

//=============================================================================
// ���j���[�̐���
//=============================================================================
CConfirmation_Window* CConfirmation_Window::Create(const std::string letter, const std::string letter2, const std::string letter3, D3DXCOLOR col)
{
	//�N���X�̐���
	CConfirmation_Window* pMenuWindow = new CConfirmation_Window;

	//null�`�F�b�N
	if (pMenuWindow != nullptr)
	{
		pMenuWindow->m_Color = col;
		//����������
		pMenuWindow->Init();
		pMenuWindow->m_Letter[0] = letter;
		pMenuWindow->m_Letter[1] = letter2;
		pMenuWindow->m_Letter[2] = letter3;
	}
	else
	{
		assert(false);
	}

	return pMenuWindow;
}