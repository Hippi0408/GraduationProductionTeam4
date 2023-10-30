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

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
const float CConfirmation_Window::BLINK_SPEED = 0.02f;	// �I�����̓_�ő��x
const float CConfirmation_Window::MINI_ALPHA = 0.5f;	// �I�����̍Œᓧ���l

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CConfirmation_Window::CConfirmation_Window() : m_bSelectChoice(0), m_fBlinkSpeed(BLINK_SPEED)
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
	m_bflag = false;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_FRONT);
	m_pObject2D->SetCol(D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f));

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
	{
		// ���j���[�̃T�C�Y�g�又��
		ConfirmatiomnMenuScale();
	}

	Choice();

	if (m_bScale == true)
	{
		ConfirmatiomnMenuScaleReduce();
	}
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
		if (SizeX >= SizeXScaleMax && SizeY >= SizeYScaleMax && m_bflag == false)
		{
			// �I�����̐ݒ菈��
			SetChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 40.0f, 40.0f }, "�͂�"));
			SetChoice(CFontString::Create({ 700.0f, 450.0f, 0.0f }, { 40.0f, 40.0f }, "������"));

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
			m_bflag = true;
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

		// �E�B���h�E���ŏ��l�܂ōs������
		if (SizeX <= 0.0f && SizeY <= 0.0f)
		{
			CGame::SetGameWindow(true);
			m_bScale = false;
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

			// ����̔���
			bool bDecition = false;

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
				bDecition = true;
			}

			// ���肳�ꂽ�ꍇ
			if (bDecition == true)
			{
				// �͂��̏ꍇ
				if (m_bSelectChoice == false)
				{

				}
				// �������̏ꍇ
				else
				{
					m_bScale = true;
					SetDisplay(false);
				}
			}
		}
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