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
	m_nSelectChoice = 0;
	m_SizeX = 0.0f;
	m_SizeY = 0.0f;
	m_bScale = false;
	m_bMaxSize = false; 
	m_bSpawnWindow = false;
	m_bDecition = false;
	m_bDicisionCreateFlag = false;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));
	m_bWindowUse = false;

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
	if (m_bScale == false)
	{// �g�傳��Ă��Ȃ��� 
	 // �E�B���h�E�̊g�又��
		CharSelectMenuScale();
	}
	else if (m_bScale == true && m_bWindowUse == false)
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
	SetSelectChoice(m_nSelectChoice);

	// �L��������E�B���h�E�������ꍇ 
	if (m_pCharDecision != nullptr && m_pCharDecision->GetSapawnWindow() == true)
	{
		m_bWindowUse = false;
		// �L���������ʂ̔j��
		m_pCharDecision->Uninit();
		delete m_pCharDecision;
		m_pCharDecision = nullptr;
	}
}

//=============================================================================
// �g�又��
//=============================================================================
void CCharSelect_Window::CharSelectMenuScale()
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
		//if (pInput->Trigger(DIK_RETURN) && m_bMaxSize == false)
		//{
		//	m_SizeX = m_MaxSizeX;
		//	m_SizeY = m_MaxSizeY;
		//	m_bMaxSize = true;
		//	// �T�C�Y�̐ݒ�
		//	m_pObject2D->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
		//}

		// �E�B���h�E���ő�l�܂ōs������
		if (m_SizeX >= m_MaxSizeX && m_SizeY >= m_MaxSizeY && m_bMaxSize == false)
		{
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_GAME)
			{
				pInput->SetKeyLock(100);
			}

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
				m_vpListChoice[m_nSelectChoice]->SetBlink(BLINK_SPEED);
				m_vpListChoice[m_nSelectChoice]->SetAlpha(1.0f);
			}

			SetCharSelectDisplay(true);
			m_bMaxSize = true;
			return;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
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
			// �L�����I����ʈȊO�̎�
			if (!Mode == CApplication::MODE_CHAR_SELECT)
			{
				m_bScale = false;
				CGame::SetGameWindow(true);
				Uninit();						// ���j���[�E�B���h�E�̍폜
			}
			else if (Mode == CApplication::MODE_CHAR_SELECT && m_bWindowUse == false)
			{
				m_bWindowUse = true;
				m_bMaxSize = false;
				m_bSpawnWindow = false;
				m_bDecition = false;
				m_bDicisionCreateFlag = false;
			}

			// �L��������E�B���h�E�̐���
			if (m_pCharDecision == nullptr && m_bDicisionCreateFlag == false)
			{
				m_pCharDecision = CCharDecision_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), 900.0f, 500.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
			}

			m_bDicisionCreateFlag = true;

			return true;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(m_SizeX, m_SizeY));
	}
	return false;
}

//=============================================================================
// �L�����N�^�[��������
//=============================================================================
void CCharSelect_Window::CharName(const std::string name, const std::string skillname)
{
	m_nLetter[0] = name;
	m_nLetter[1] = skillname;

	m_pCharDecision->SetFont(&m_nLetter[0]);
	m_pCharDecision->SetFont(&m_nLetter[1]);
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
// �I�����̏���
//=============================================================================
void CCharSelect_Window::CharSelectChoice()
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
					CharSelectChangeChoice(m_nSelectChoice <= 0 ? m_vpListChoice.size() - 1 : m_nSelectChoice - 1);
				}
				// ���Ɉړ�����
				else if (pInput->Trigger(DIK_D) || (pInput->Trigger(JOYPAD_DOWN, m_nMenuInitiative)))
				{
					//m_bInputFlag = true;
					// �I��SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// ���݂̔ԍ����ő吔�ȏ�̏ꍇ
					CharSelectChangeChoice(m_nSelectChoice >= ((int)m_vpListChoice.size() - 1) ? 0 : m_nSelectChoice + 1);
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
				for (int nCnt = 0; nCnt < 4; nCnt++)
				{
					if (m_nSelectChoice == nCnt)
					{
						m_bScale = true;
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
	m_vpListChoice[m_nSelectChoice]->BlinkFinish();
	m_vpListChoice[m_nSelectChoice]->SetAlpha(MINI_ALPHA);

	// �I�����̕ύX
	m_nSelectChoice = (int)nextChoice;

	// �ύX��̑I�����̏���
	m_vpListChoice[m_nSelectChoice]->SetBlink(m_fBlinkSpeed);
	m_vpListChoice[m_nSelectChoice]->SetAlpha(1.0f);
}

//============================================================================
// �I�������ԍ�
//============================================================================
void CCharSelect_Window::SetSelectChoice(int index)
{
	m_nSelectChoice = index;

	if (m_nSelectChoice == -1)
	{
		m_nSelectChoice = 3;
	}
	if (m_nSelectChoice == 4)
	{
		m_nSelectChoice = 0;
	}

	// �L��������
	if (m_pCharDecision != nullptr && m_pCharDecision->GetMaxScale() == true)
	{
		std::string SkillName;

		if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetExplanationUninit() == false)
		{
			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
			{
				std::string Name = "�X�g���C�J�[";

				if (m_nSelectChoice == 0)
				{
					SkillName = "���b�V��";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_RUSH, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
				if (m_nSelectChoice == 1)
				{
					SkillName = "���@���K�[�h";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_VANGUARD, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
				if (m_nSelectChoice == 2)
				{
					SkillName = "�C�[�O���A�C";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_EAGLEEYE, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
				if (m_nSelectChoice == 3 || m_nSelectChoice == -1)
				{
					SkillName = "�}�[�V����";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_MARSHALL, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
			}
		}
		if (CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetExplanationUninit() == false)
		{
			if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == false)
			{
				std::string Name = "�R�}���_�[";

				if (m_nSelectChoice == 0)
				{
					SkillName = "���J�j�b�N";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_MECHANIC, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
				if (m_nSelectChoice == 1)
				{
					SkillName = "���C�_�[";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_RAIDER, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
				if (m_nSelectChoice == 2)
				{
					SkillName = "�A�[�N�t�B���A";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_ARCPHILIA, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
				if (m_nSelectChoice == 3 || m_nSelectChoice == -1)
				{
					SkillName = "�R���g���[��";
					CharName(Name, SkillName);
					CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->SetTextue(CTexture::TEXTURE_SKILL_CONTROL, CTexture::TEXTURE_FONT_JAPANESE_VER2);
				}
			}
		}
	}
}

//============================================================================
// �I�����̕\�������ݒ肷��
//============================================================================
void CCharSelect_Window::SetCharSelectDisplay(const bool display)
{
	m_bDisplay = display;
	for (auto pChoice : GetChoiceAll()) { pChoice->SetFontDraw(display); }

	//// �\���������ꍇ
	//if (m_bDisplay == false)
	//{
	//	// �I�����̏�������������
	//	CharSelectChangeChoice(0);
	//}
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
		pCharSelect->m_MaxSizeX = xsize;
		pCharSelect->m_MaxSizeY = ysize;
		//����������
		pCharSelect->Init();
	}
	else
	{
		assert(false);
	}

	return pCharSelect;
}
