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
#include "connect.h"

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
	m_fMoveX = 175.0f;
	m_bMaxSize = false;
	m_bSlideFlag = false;
	m_bFontFlag = false;
	m_bLeftRight = false;
	m_bStopFlag = true;
	m_bPosDest = false;
	m_bExplanationUninit = false;
	m_bScale = false;
	m_bDicision = false;
	m_bUninitFlag = false;
	m_bScaleReduce = false;
	m_bSpawnWindow = true;
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
	{// �E�B���h�E�̊g�又��
		CharDecisionMenuScale();
	}

	// �Q�[����ʂւ̑J��
	if (pInput->Trigger(DIK_RETURN)
		&& m_bMaxSize == true
		&& m_bScaleReduce == false
		&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		UninitExplanation();				// �t�H���g�̍폜
		m_bScaleReduce = true;

		////�T�[�o�[�̐ڑ�
		//CApplication::GetClient()->Init("127.0.0.1", 15678);

		//// ��ʑJ��
		//CFade::SetFade(CApplication::MODE_GAME, 0.1f);

		// �v���C���[�̃W���u�ԍ��̐ݒ�
		CApplication::SetPlayerJobIndex(CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice());
	}
	if (m_bScaleReduce == true)
	{
		CharDecisionMenuScaleReduce();
	}

	if (m_pWindow != nullptr)
	{
		// �L�����̕ύX����
		CharSelectChoice();
	}

	// �E�B���h�E��߂�����
	if (m_bMaxSize == true)
	{
		BackWindow();
	}
}

//============================================================================
// �E�B���h�E�̊g�又��
//============================================================================
void CCharDecision_Window::CharDecisionMenuScale()
{
	if (m_pObject2D != nullptr)
	{// null�`�F�b�N

		// �T�C�Y�̊g��
		m_size.x += SizeXScaleSpeed;
		m_size.y += SizeYScaleSpeed;

		if (m_size.x >= m_MaxSize.x)
		{// X�T�C�Y�̍ő�
			m_size.x = m_MaxSize.x;
		}
		if (m_size.y >= m_MaxSize.y)
		{// Y�T�C�Y�̍ő�
			m_size.y = m_MaxSize.y;
		}

		// �E�B���h�E���ő�l�܂ōs������
		if (m_size.x >= m_MaxSize.x && m_size.y >= m_MaxSize.y && m_bMaxSize == false)
		{
			m_bMaxSize = true;		// �ő�T�C�Y�ɓ��B
			m_bScale = true;		// �g�傳�ꂽ
			return;
		}

		// �T�C�Y�̐ݒ�
		m_pWindow->SetSize(D3DXVECTOR2(m_size.x, m_size.y));
	}
}

//=============================================================================
// ���j���[�̃T�C�Y�k������
//=============================================================================
bool CCharDecision_Window::CharDecisionMenuScaleReduce()
{
	if (m_pObject2D != nullptr)
	{// null�`�F�b�N

		// �T�C�Y�̏k��
		m_size.x -= SizeXScaleSpeed;
		m_size.y -= SizeYScaleSpeed;

		if (m_size.x <= 0.0f)
		{// X�T�C�Y�̍ŏ�
			m_size.x = 0.0f;
		}
		if (m_size.y <= 0.0f)
		{// Y�T�C�Y�̍ŏ�
			m_size.y = 0.0f;
		}
		m_bExplanationUninit = true;		// �e�N�X�`���ƃt�H���g�̍폜

		// �t�H���g�ƃe�N�X�`���̍폜
		UninitExplanation();

		// �E�B���h�E���ŏ��l�܂ōs������
		if (m_size.x <= 0.0f && m_size.y <= 0.0f)
		{
			m_bSpawnWindow = false;		// �E�B���h�E�𐶐�����Ă��Ȃ���Ԃɂ���
			m_bUninitFlag = true;		// �폜�t���O��true

			// �I������
			Uninit();					

			return true;
		}

		// �T�C�Y�̐ݒ�
		m_pWindow->SetSize(D3DXVECTOR2(m_size.x, m_size.y));
	}
	return false;
}

//=============================================================================
// �I�����̏���
//=============================================================================
void CCharDecision_Window::CharSelectChoice()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	// �t�F�[�h���ł͖����ꍇ && �\�����̏ꍇ
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
	{
		// ���Ɉړ�����
		if (pInput->Trigger(DIK_A) && m_bStopFlag == true || (pInput->Trigger(JOYPAD_UP)) && m_bStopFlag == false)
		{
			// �I�������ԍ��̎擾
			m_nSelectIndex = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			m_nSelectIndex--;		// �ԍ���1�߂�
			m_bSlideFlag = true;	// �X���C�h������
			m_bLeftRight = false;	// ���Ɉړ�
			m_bPosDest = false;		// �ړI�̈ʒu�ɓ��B���Ă��Ȃ�
			m_bStopFlag = false;	// �����Ă�����
			// �I��SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

		}
		// ���Ɉړ�����
		else if (pInput->Trigger(DIK_D) && m_bStopFlag == true || (pInput->Trigger(JOYPAD_DOWN)) && m_bStopFlag == false)
		{
			// �I�������ԍ��̎擾
			m_nSelectIndex = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			m_nSelectIndex++;		// �ԍ���1�i�߂�
			m_bSlideFlag = true;	// �X���C�h������
			m_bLeftRight = true;	// �E�Ɉړ�
			m_bPosDest = false;		// �ړI�̈ʒu�ɓ��B���Ă��Ȃ�
			m_bStopFlag = false;	// �����Ă�����
			// �I��SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);
		}
	}
	
	// �E�B���h�E�X���C�h����
	SlideWindow();
}

//============================================================================
// �E�B���h�E��߂�����
//============================================================================
void CCharDecision_Window::BackWindow()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();
	
	// �O�̃E�B���h�E�ɖ߂�
	if (pInput->Trigger(DIK_BACK))
	{
		m_bDicision = true;
		m_bScale = true;
	}
	if (m_bScale == true && m_bDicision == true)
	{
		CharDecisionMenuScaleReduce();
	}
}

//============================================================================
// �E�B���h�E���X���C�h�����鏈��
//============================================================================
void CCharDecision_Window::SlideWindow()
{
	// �ʒu�̎擾
	D3DXVECTOR3 pos = m_pWindow->GetPos();

	if (m_bSlideFlag == true)
	{// �X���C�h����Ă��鎞

	 // ���ړ�
		if (m_bLeftRight == false)
		{
			m_bExplanationUninit = true;		// �e�N�X�`���ƃt�H���g�̍폜
			UninitExplanation();				// �t�H���g�̍폜
			pos.x -= m_fMoveX;					// �ړ��ʂ̌��Z
			if (pos.x <= -SCREEN_WIDTH / 2 && m_bPosDest == false)
			{// �ʒu��-640�ȉ� && �ړI�̈ʒu�܂œ��B���Ă��Ȃ�������

				pos.x = 1920.0f;				// �ʒu�̐ݒ�
				m_bPosDest = true;				// �ړI�̈ʒu�܂œ��B����
			}
			if (pos.x <= SCREEN_WIDTH / 2 && m_bPosDest == true)
			{// �ʒu��640�ȉ� && �ړI�̈ʒu�܂œ��B������

				pos.x = SCREEN_WIDTH / 2;		// �ʒu�̐ݒ�
				m_bFontFlag = false;			// �t�H���g���g�p���Ă��Ȃ���Ԃɂ���
				m_bStopFlag = true;				// �X���C�h���~������
				m_bExplanationUninit = false;   // �e�N�X�`���ƃt�H���g�̕\��

				// �I�������ԍ��̕ۑ�
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(m_nSelectIndex);
			}
		}
		// �E�ړ�
		else
		{
			m_bExplanationUninit = true;		// �e�N�X�`���ƃt�H���g�̍폜
			UninitExplanation();				// �t�H���g�̍폜
			pos.x += m_fMoveX;					// �ړ��ʂ̉��Z
			if (pos.x >= 1920.0f && m_bPosDest == false)
			{// �ʒu��1920.0f�ȏ� && �ړI�̈ʒu�܂œ��B���Ă��Ȃ�������

				pos.x = -SCREEN_WIDTH / 2;		// �ʒu�̐ݒ�
				m_bPosDest = true;				// �ړI�̈ʒu�܂œ��B����
			}
			if (pos.x >= SCREEN_WIDTH / 2 && m_bPosDest == true)
			{// �ʒu��640�ȉ� && �ړI�̈ʒu�܂œ��B������

				pos.x = SCREEN_WIDTH / 2;		// �ʒu�̐ݒ�
				m_bFontFlag = false;			// �t�H���g���g�p���Ă��Ȃ���Ԃɂ���
				m_bStopFlag = true;				// �X���C�h���~������
				m_bExplanationUninit = false;	// �e�N�X�`���ƃt�H���g�̕\��

				// �I�������ԍ��̕ۑ�
				CChar_Select::GetConfimationWindow()->GetCharSelect()->SetSelectChoice(m_nSelectIndex);
			}
		}
		// �ʒu�̐ݒ�
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
	// �t�H���g�̔j��
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (m_pFont[nCnt] != nullptr)
		{
			m_pFont[nCnt]->Uninit();
			m_pFont[nCnt] = nullptr;
		}
	}

	// �e�N�X�`���̔j��
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
		// �ݒ菈��
		pCharDecision->m_pos = pos;
		pCharDecision->m_Color = col;
		pCharDecision->m_MaxSize.x = xsize;
		pCharDecision->m_MaxSize.y = ysize;
		// ����������
		pCharDecision->Init();         
	}
	else
	{
		assert(false);
	}

	return pCharDecision;
}