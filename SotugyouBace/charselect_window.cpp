//=============================================================================
//
// charselect_windpow.cpp (�L�����I���E�B���h�E.cpp)
// Author : Saitou Shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "charselect_window.h"
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
#include "chardecision_window.h"
#include "confirmation_window.h"
#include "char_select.h"
#include "texture.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
const float CCharSelect_Window::BLINK_SPEED = 0.02f;	// �I�����̓_�ő��x
const float CCharSelect_Window::MINI_ALPHA = 0.5f;		// �I�����̍Œᓧ���l

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCharSelect_Window::CCharSelect_Window()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCharSelect_Window::~CCharSelect_Window()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCharSelect_Window::Init()
{
	//==================================================
	// �����o�ϐ��̏�����
	//==================================================  
	m_CharSelectWindowSize = D3DXVECTOR2(0.0f, 0.0f);
	m_nCharSelectWindowSelectChoice = 0;
	m_bCharSelectWindowScale = false;
	m_bCharSelectWindowMaxSize = false;
	m_bCharSelectWindowDecition = false;
	m_bDicisionCreateFlag = false;
	m_bCharSelectWindowWindowUse = false;
	m_bCharSelectWindowBackFlag = false;
	m_bCharSelectWindowUninitFlag = false;
	m_bPreviousWindowCreate = false;
	m_bDicisionUse = false;

	m_pObject2D = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCharSelect_Window::Uninit()
{
	// �����o�ϐ��̔j��
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}

	// �L��������E�B���h�E�̔j��
	if (m_pCharDecision != nullptr)
	{
		m_pCharDecision->Uninit();
		delete m_pCharDecision;
		m_pCharDecision = nullptr;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CCharSelect_Window::Update()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	if (m_bCharSelectWindowScale == false && m_bCharSelectWindowWindowUse == false)
	{// �g�傳��Ă��Ȃ��� 

	 // �E�B���h�E�̊g�又��
		CharSelectMenuScale();
	}
	else if (m_bCharSelectWindowScale == true && m_bCharSelectWindowWindowUse == false)
	{// �g�債����
		 
	 // �E�B���h�E�̏k������
		CharSelectMenuScaleReduce();
	}

	// �I��������
	CharSelectChoice();

	// �L��������E�B���h�E�̍X�V����
	if (m_pCharDecision != nullptr)
	{
		m_pCharDecision->Update();
	}

	// �I�������ԍ��ɂ���ďo���E�B���h�E��ς��鏈��
	SetSelectChoice(m_nCharSelectWindowSelectChoice);

	if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetUninit() == true
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetScaleReduce() == false
		&& m_bCharSelectWindowWindowUse == true)
	{
		// �E�B���h�E�̊g�又��
		CharSelectMenuScale();
		m_bCharSelectWindowBackFlag = true;
	}

	// �L��������E�B���h�E�������ꍇ 
	if (m_pCharDecision != nullptr && m_pCharDecision->GetSapawnWindow() == false)
	{
		m_bDicisionUse = false;
	}

	// �Q�[����ʂւ̑J��
	if (pInput->Trigger(DIK_BACK)
		&& m_bCharSelectWindowUninitFlag == false
		&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{ // �L�[�������ꂽ�� && �L�����I���E�B���h�E���폜����ĂȂ��� && �t�F�[�h���ĂȂ���

		// �t�H���g�̍폜����
		UninitFont();
		SetCharSelectDisplay(false);			// �\�������Ȃ�
		m_bCharSelectWindowUninitFlag = true;	// �E�B���h�E�폜�t���O��true
		m_bCharSelectWindowScale = true;		// �g��k���t���O��true
	}
	if (m_bCharSelectWindowUninitFlag == true && m_bCharSelectWindowBackFlag == false)
	{ // �L�����I���E�B���h�E���폜���ꂽ�� && �O�̃E�B���h�E����߂��Ă�����

		// �k������
		CharSelectMenuScaleReduce();
	}
}

//=============================================================================
// �g�又��
//=============================================================================
void CCharSelect_Window::CharSelectMenuScale()
{
	if (m_pObject2D != nullptr)
	{// null�`�F�b�N

		// �T�C�Y�̊g��
		m_CharSelectWindowSize.x += SizeXScaleSpeed;
		m_CharSelectWindowSize.y += SizeYScaleSpeed;

		if (m_CharSelectWindowSize.x >= m_CharSelectWindowMaxSize.x)
		{// X�T�C�Y�̍ő�
			m_CharSelectWindowSize.x = m_CharSelectWindowMaxSize.x;
		}
		if (m_CharSelectWindowSize.y >= m_CharSelectWindowMaxSize.y)
		{// Y�T�C�Y�̍ő�
			m_CharSelectWindowSize.y = m_CharSelectWindowMaxSize.y;
		}

		// �E�B���h�E���ő�l�܂ōs������
		if (m_CharSelectWindowSize.x >= m_CharSelectWindowMaxSize.x && m_CharSelectWindowSize.y >= m_CharSelectWindowMaxSize.y && m_bCharSelectWindowMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
			{
   				if (m_pFont == nullptr)
				{
					m_pFont = CFontString::Create(D3DXVECTOR3(500.0f, 200.0f, 0.0f), { 30.0f, 30.0f }, "�X�g���C�J�[");
				}

				SetCharSelectChoice(CFontString::Create({ 200.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "���b�V��"));
				SetCharSelectChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "���@���K�[�h"));
				SetCharSelectChoice(CFontString::Create({ 625.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "�C�[�O���A�C"));
				SetCharSelectChoice(CFontString::Create({ 875.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "�}�[�V����"));
			}
			else
			{
				if (m_pFont == nullptr)
				{
					m_pFont = CFontString::Create(D3DXVECTOR3(500.0f, 200.0f, 0.0f), { 30.0f, 30.0f }, "�R�}���_�[");
				}

				SetCharSelectChoice(CFontString::Create({ 200.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "���J�j�b�N"));
				SetCharSelectChoice(CFontString::Create({ 415.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "���C�_�["));
				SetCharSelectChoice(CFontString::Create({ 580.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "�A�[�N�t�B���A"));
				SetCharSelectChoice(CFontString::Create({ 865.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "�R���g���[��"));
			}

			// �I�������g�p����Ă���ꍇ
			if (!m_vpListChoice.empty())
			{
				for (auto pChoice : GetChoiceAll())
				{
					pChoice->SetAlpha(MINI_ALPHA);
				}
				// �I������Ă���I����
				m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetBlink(BLINK_SPEED);
				m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetAlpha(1.0f);
			}

			if (m_bCharSelectWindowBackFlag == true)
			{
				// �����o�ϐ�������
				m_bCharSelectWindowWindowUse = false;
				m_bCharSelectWindowScale = false;
				m_bCharSelectWindowDecition = false;
				m_bDicisionCreateFlag = false;
				m_bCharSelectWindowBackFlag = false;
				m_bCharSelectWindowUninitFlag = false;

				// �I�����̏�����
				InitSelect();
				
				if (m_pCharDecision != nullptr)
				{
					// �L���������ʂ̔j��
					m_pCharDecision->Uninit();
					delete m_pCharDecision;
					m_pCharDecision = nullptr;
				}
			}

			SetCharSelectDisplay(true);
			m_bCharSelectWindowMaxSize = true;

			return;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(m_CharSelectWindowSize.x, m_CharSelectWindowSize.y));
	}
}

//=============================================================================
// �k������
//=============================================================================
bool CCharSelect_Window::CharSelectMenuScaleReduce()
{
	if (m_pObject2D != nullptr)
	{// null�`�F�b�N

	 // ���݂̃��[�h
		CApplication::MODE Mode = CApplication::GetModeType();

		// �T�C�Y�̏k��
		m_CharSelectWindowSize.x -= SizeXScaleSpeed;
		m_CharSelectWindowSize.y -= SizeYScaleSpeed;

		if (m_CharSelectWindowSize.x <= 0.0f)
		{// X�T�C�Y�̍ŏ�
			m_CharSelectWindowSize.x = 0.0f;
		}
		if (m_CharSelectWindowSize.y <= 0.0f)
		{// Y�T�C�Y�̍ŏ�
			m_CharSelectWindowSize.y = 0.0f;
		}

		// �t�H���g�̍폜����
		UninitFont();

		// �E�B���h�E���ŏ��l�܂ōs������
		if (m_CharSelectWindowSize.x <= 0.0f && m_CharSelectWindowSize.y <= 0.0f)
		{
			// �L�����I����ʈȊO�̎�
			if (!Mode == CApplication::MODE_CHAR_SELECT)
			{
				m_bCharSelectWindowScale = false;
				CGame::SetGameWindow(true);
				Uninit();						// ���j���[�E�B���h�E�̍폜
			}
			else if (Mode == CApplication::MODE_CHAR_SELECT && m_bCharSelectWindowWindowUse == false)
			{
				m_bCharSelectWindowWindowUse = true;
				m_bCharSelectWindowMaxSize = false;
				m_bCharSelectWindowDecition = false;
				m_bDicisionCreateFlag = false;
			}
			
			// �L��������E�B���h�E�̐���
			if (m_pCharDecision == nullptr && m_bDicisionCreateFlag == false && m_bCharSelectWindowUninitFlag == false)
			{
				m_pCharDecision = CCharDecision_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), 900.0f, 500.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
				m_bDicisionUse = true;
			}
			if (m_bCharSelectWindowBackFlag == true && m_bDicisionUse == false)
			{
				m_bPreviousWindowCreate = true;
			}
			else if (m_bCharSelectWindowBackFlag == false && m_bDicisionUse == false)
			{
				m_bPreviousWindowCreate = true;
			}

			// �����l�ɖ߂�
			m_bDicisionCreateFlag = true;
			m_bCharSelectWindowUninitFlag = false; 
			return true;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(m_CharSelectWindowSize.x, m_CharSelectWindowSize.y));
	}
	return false;
}

//=============================================================================
// �L�����N�^�[��������
//=============================================================================
void CCharSelect_Window::SetSkillName(const std::string name, const std::string skillname)
{
	m_nLetter[0] = name;
	m_nLetter[1] = skillname;

	m_pCharDecision->SetFont(&m_nLetter[0]);
	m_pCharDecision->SetFont(&m_nLetter[1]);
}

//=============================================================================
// �I�������ԍ��ɂ���ăX�L����ς��鏈��
//=============================================================================
void CCharSelect_Window::SetSkillSelectChoice(const std::string type,const std::string name, const std::string name1, const std::string name2, const std::string name3)
{
	std::string SkillName;
	std::string Name = type;

	if (m_nCharSelectWindowSelectChoice == 0)
	{
		SkillName = name;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_RUSH, CTexture::TEXTURE_SKILLEXPLANATION_RUSH);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_MECHANIC, CTexture::TEXTURE_SKILLEXPLANATION_MECHANIC);
		}
	
	}
	if (m_nCharSelectWindowSelectChoice == 1)
	{
		SkillName = name1;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_VANGUARD, CTexture::TEXTURE_SKILLEXPLANATION_VANGUARD);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_RAIDER, CTexture::TEXTURE_SKILLEXPLANATION_RAIDER);
		}
		
	}
	if (m_nCharSelectWindowSelectChoice == 2)
	{
		SkillName = name2;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_EAGLEEYE, CTexture::TEXTURE_SKILLEXPLANATION_EAGLEEYE);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_ARCPHILIA, CTexture::TEXTURE_SKILLEXPLANATION_ARCPHILIA);
		}
	}
	if (m_nCharSelectWindowSelectChoice == 3 || m_nCharSelectWindowSelectChoice == -1)
	{
		SkillName = name3;
		SetSkillName(Name, SkillName);
		if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_MARSHALL, CTexture::TEXTURE_SKILLEXPLANATION_MARSHALL);
		}
		else
		{
			CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_CONTROL, CTexture::TEXTURE_SKILLEXPLANATION_CONTROL);
		}
	}
}

//=============================================================================
// �I�����̏���������
//=============================================================================
void CCharSelect_Window::InitSelect()
{
	// �I�����̏�������������
	CharSelectChangeChoice(0);
}

//=============================================================================
// �t�H���g�̍폜����
//=============================================================================
void CCharSelect_Window::UninitFont()
{
	// �t�H���g�̍폜
	if (m_pFont != nullptr)
	{
		m_pFont->Uninit();
		m_pFont = nullptr;
	}
}

//=============================================================================
// �I�����̏���
//=============================================================================
void CCharSelect_Window::CharSelectChoice()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	// �t�F�[�h���ł͖����ꍇ && �\�����̏ꍇ
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE && m_bCharSelectWindowDisplay == true)
	{
		// �I�������g�p����Ă���ꍇ
		if (!m_vpListChoice.empty())
		{

			// �I������2�ȏ�g�p����Ă���ꍇ
			if (m_vpListChoice.size() >= 2)
			{
				// ��Ɉړ�����
				if (pInput->Trigger(DIK_A) || (pInput->Trigger(JOYPAD_UP)))
				{
					// �I��SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// ���݂̔ԍ���0�ȉ��ł���ꍇ
					CharSelectChangeChoice(m_nCharSelectWindowSelectChoice <= 0 ? m_vpListChoice.size() - 1 : m_nCharSelectWindowSelectChoice - 1);
				}
				// ���Ɉړ�����
				else if (pInput->Trigger(DIK_D) || (pInput->Trigger(JOYPAD_DOWN)))
				{
					//m_bInputFlag = true;
					// �I��SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// ���݂̔ԍ����ő吔�ȏ�̏ꍇ
					CharSelectChangeChoice(m_nCharSelectWindowSelectChoice >= ((int)m_vpListChoice.size() - 1) ? 0 : m_nCharSelectWindowSelectChoice + 1);
				}
			}

			if (pInput->Trigger(DIK_RETURN) || (pInput->Trigger(JOYPAD_B) || pInput->Trigger(JOYPAD_A)))
			{
				// ����SE
				CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

				// �I�������肷��
				m_bCharSelectWindowDecition = true;
			}
			// ���肳�ꂽ�ꍇ
			if (m_bCharSelectWindowDecition == true)
			{
				for (int nCnt = 0; nCnt < 4; nCnt++)
				{
					if (m_nCharSelectWindowSelectChoice == nCnt)
					{
						m_bCharSelectWindowScale = true;
						SetCharSelectDisplay(false);
					}
				}
			}
		}
	}
}

//=============================================================================
// �I������ύX�������̏���
//=============================================================================
void CCharSelect_Window::CharSelectChangeChoice(const int nextChoice)
{
	// ���݂̑I�����̏���
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->BlinkFinish();
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetAlpha(MINI_ALPHA);

	// �I�����̕ύX
	m_nCharSelectWindowSelectChoice = (int)nextChoice;

	// �ύX��̑I�����̏���
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetBlink(m_fCharSelectWindowBlinkSpeed);
	m_vpListChoice[m_nCharSelectWindowSelectChoice]->SetAlpha(1.0f);
}

//============================================================================
// �I�������ԍ�
//============================================================================
void CCharSelect_Window::SetSelectChoice(int index)
{
	// �I�������ԍ���ۑ�����
	m_nCharSelectWindowSelectChoice = index;

	// �I�������ԍ���0�ȉ���������
	if (m_nCharSelectWindowSelectChoice == -1)
	{
		// �ԍ���3�ɂ���
		m_nCharSelectWindowSelectChoice = 3;
	}
	// �I�������ԍ���4�ȏゾ������
	if (m_nCharSelectWindowSelectChoice == 4)
	{
		// �ԍ���0�ɂ���
		m_nCharSelectWindowSelectChoice = 0;
	}

	// �L��������
	if (m_pCharDecision != nullptr && m_pCharDecision->GetMaxScale() == true)
	{
		if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetExplanationUninit() == false)
		{
			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
			{
				SetSkillSelectChoice("�X�g���C�J�[", "���b�V��", "���@���K�[�h", "�C�[�O���A�C", "�}�[�V����");
			}
		}
		if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetExplanationUninit() == false)
		{
			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == false)
			{
				SetSkillSelectChoice("�R�}���_�[", "���J�j�b�N", "���C�_�[", "�A�[�N�t�B���A", "�R���g���[��");
			}
		}
	}
}

//============================================================================
// �I�����̕\�������ݒ肷��
//============================================================================
void CCharSelect_Window::SetCharSelectDisplay(const bool display)
{
	m_bCharSelectWindowDisplay = display;
	for (auto pChoice : GetChoiceAll()) { pChoice->SetFontDraw(display); }
}

//============================================================================
// ��������
//============================================================================
CCharSelect_Window * CCharSelect_Window::Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col)
{
	//�N���X�̐���
	CCharSelect_Window* pCharSelect = new CCharSelect_Window; 

	//null�`�F�b�N
	if (pCharSelect != nullptr)
	{
		pCharSelect->m_pos = pos;
		pCharSelect->m_Color = col;
		pCharSelect->m_CharSelectWindowMaxSize.x = xsize;
		pCharSelect->m_CharSelectWindowMaxSize.y = ysize;
		//����������
		pCharSelect->Init();
	}
	else
	{
		assert(false);
	}

	return pCharSelect;
}
