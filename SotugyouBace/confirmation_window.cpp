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
#include "charselect_window.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CCharSelect_Window* CConfirmation_Window::m_pCharSelectWindow = nullptr;
const float CConfirmation_Window::BLINK_SPEED = 0.02f;	// �I�����̓_�ő��x
const float CConfirmation_Window::MINI_ALPHA = 0.5f;	// �I�����̍Œᓧ���l

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
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CConfirmation_Window::Uninit()
{
	//�����o�ϐ��̔j��
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}

	// �L�����I����ʂ̔j��
	if (m_pCharSelectWindow != nullptr)
	{
		m_pCharSelectWindow->Uninit();
		delete m_pCharSelectWindow;
		m_pCharSelectWindow = nullptr;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CConfirmation_Window::Update()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	if (m_bScale == false)
	{// �g�傳��Ă��Ȃ���

		// �E�B���h�E�̊g�又��
		ConfirmatiomnMenuScale();
	}
	else
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
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	if (m_pObject2D != nullptr)
	{// null�`�F�b�N

		// �T�C�Y�̊g��
		SizeX += SizeXScaleSpeed;
		SizeY += SizeYScaleSpeed;

		if (SizeX >= MaxSizeX)
		{// X�T�C�Y�̍ő�
			SizeX = MaxSizeX;
		}
		if (SizeY >= MaxSizeY)
		{// Y�T�C�Y�̍ő�
			SizeY = MaxSizeY;
		}

		// �E�B���h�E���ő�l�܂ōs������
		if (SizeX >= MaxSizeX && SizeY >= MaxSizeY && m_bMaxSize == false)
		{
			// �Q�[�����[�h�̎擾
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_TITLE || Mode == CApplication::MODE_GAME)
			{ // �^�C�g�����Q�[����ʂ�������
				
				// �����̐���
				if (m_pFont == nullptr)
				{
					m_pFont = CFontString::Create({ 420.0f, 350.0f, 0.0f }, { 30.0f, 30.0f }, "��߂܂���?");
				}

				// �I�����̐���
				SetChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "�͂�"));
				SetChoice(CFontString::Create({ 700.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "������"));
			}
			else if(Mode == CApplication::MODE_CHAR_SELECT)
			{ // �L�����I����ʂ�������

				// �I�����̐���
				SetChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "�X�g���C�J�["));
				SetChoice(CFontString::Create({ 700.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "�R�}���_�["));
			}

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

			SetDisplay(true);		// �I�����̕\��������g�p
			m_bMaxSize = true;		// �ő�T�C�Y�ɓ��B
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

	 // ���݂̃��[�h
		CApplication::MODE Mode = CApplication::GetModeType();

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
			// �Q�[���I��
			if (m_bSelectChoice == true && Mode == CApplication::MODE_GAME)
			{
				m_bUninitFlag = true;							// �Q�[�����E�B���h�E�̔j��
				m_bSpawnWindow = true;							// ���j���[�E�B���h�E�̔j��
				DestroyWindow(CApplication::GetWindow());		// �E�B���h�E�̔j��
			}
			else if (m_bSelectChoice == false && Mode == CApplication::MODE_GAME)
			{
				m_bUninitFlag = true;							// �Q�[�����E�B���h�E�̔j��
				m_bSpawnWindow = true;							// ���j���[�E�B���h�E�̔j��
				m_bScale = false;								// �g��k���t���O��������			
				Uninit();										// ���j���[�E�B���h�E�̍폜			
			}
			if (Mode == CApplication::MODE_TITLE)
			{
				m_bScale = false;								// �g��k���t���O��������	
				m_bSpawnWindow = true;							// ���j���[�E�B���h�E�̔j��
				Uninit();										// ���j���[�E�B���h�E�̍폜
			}
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
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();
	
	// �t�F�[�h���ł͖����ꍇ && �\�����̏ꍇ
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE && m_bDisplay == true)
	{
		// �I�������g�p����Ă���ꍇ
		if (!m_vpListChoice.empty())
		{
			// �I������2�ȏ�g�p����Ă���ꍇ
			if (m_vpListChoice.size() >= 2)
			{
				// ��Ɉړ�����
				if (pInput->Trigger(DIK_A) || (pInput->Trigger(JOYPAD_UP, m_nMenuInitiative)))
				{
					// �I��SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// ���݂̔ԍ���0�ȉ��ł���ꍇ
					ChangeChoice(false);
				}
				// ���Ɉړ�����
				else if (pInput->Trigger(DIK_D) || (pInput->Trigger(JOYPAD_DOWN, m_nMenuInitiative)))
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
				// ���̑I�����̏ꍇ
				if (m_bSelectChoice == false)
				{
					CreateCharSelect();			// �L�����I����ʂ̐���
					m_bScale = true;			// �g��k���t���O���g���Ă���
					SetDisplay(false);			// �I�����̕\��������g�p���Ă��Ȃ���Ԃɂ���
					m_bSelectChoice = true;		// ���̑I������I��
				}
				// �E�̑I�����̏ꍇ
				else
				{
					CreateCharSelect();			// �L�����I����ʂ̐���
					m_bScale = true;            // �g��k���t���O���g���Ă���
					SetDisplay(false);			// �I�����̕\��������g�p���Ă��Ȃ���Ԃɂ���
					m_bSelectChoice = false;    // ���̑I������I��
				}
			}
		}
	}

	// null�`�F�b�N
	if (m_pCharSelectWindow != nullptr)
	{ 
		// �L�����I���E�B���h�E�̍X�V����
		m_pCharSelectWindow->Update();
	}

	// �L�����I���E�B���h�E�������ꍇ 
	if (m_pCharSelectWindow != nullptr && m_pCharSelectWindow->GetSapawnWindow() == true)
	{
		// �L�����I����ʂ̔j��
		m_pCharSelectWindow->SetSapawnWindow(false);	// �E�B���h�E�̐����t���O��������
		delete m_pCharSelectWindow;
		m_pCharSelectWindow = nullptr;
	}

	// ���j���[�E�B���h�E��������
	if (m_bSpawnWindow == true && CTitle::GetMenuWindow() != nullptr)
	{
		CApplication::GetMenu()->SetDisplay(false);		// ����������
		CTitle::GetMenuWindow()->MenuScaleReduce();		// �Q�[���J���̃E�B���h�E�̏k��
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
// �L�����I����ʂ̐���
//=============================================================================
void CConfirmation_Window::CreateCharSelect()
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();		

	if (Mode == CApplication::MODE_CHAR_SELECT)
	{ // �L�����I����ʂ�������

		// null�`�F�b�N
		if (m_pCharSelectWindow == nullptr)
		{
			// �L�����I���E�B���h�E�̐���
			m_pCharSelectWindow = CCharSelect_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), 900.0f, 500.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
		}
	}
}

//=============================================================================
// ���j���[�̐���
//=============================================================================
CConfirmation_Window* CConfirmation_Window::Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col)
{
	//�N���X�̐���
	CConfirmation_Window* pMenuWindow = new CConfirmation_Window;

	//null�`�F�b�N
	if (pMenuWindow != nullptr)
	{
		// �ݒ菈��
		pMenuWindow->m_pos = pos;
		pMenuWindow->m_Color = col;
		pMenuWindow->MaxSizeX = xsize;
		pMenuWindow->MaxSizeY = ysize;
		// ����������
		pMenuWindow->Init();
	}
	else
	{
		assert(false);
	}

	return pMenuWindow;
}