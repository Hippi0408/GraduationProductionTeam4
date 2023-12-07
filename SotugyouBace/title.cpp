//==============================================================================================
//
// �^�C�g���@�@�@title.cpp
// tutida ryousei
// tanimoto kosuke
// saito shian
//
//==============================================================================================
#include "title.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include "camera.h"
#include "fontString.h"
#include "halfsphere.h"
#include "title_menu.h"
#include "menu_window.h"
#include "confirmation_window.h"
#include "object2D.h"

bool CTitle::m_bWindow = false;
bool CTitle::m_bWindowUninit = false;
CMenuWindow* CTitle::m_pMenuWindow = nullptr;

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CTitle::CTitle()
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CTitle::~CTitle()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CTitle::Init()
{
	// �J�����̃|�C���^
	CCamera* pCamera = CApplication::GetCamera();

	pCamera->SetPosV({ 0.0f, 500.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 1000.0f });

	m_pTitle[0] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[0]->SetTexture(CTexture::TEXTURE_TITLE_00);

	m_pTitle[0] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[0]->SetTexture(CTexture::TEXTURE_TITLE_01);

	m_pTitle[0] = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f), D3DXVECTOR2(500.0f, 500.0f));
	m_pTitle[0]->SetTexture(CTexture::TEXTURE_TITLE_02);

	// �n�[�t�X�t�B�A�̐���
	m_pHalf = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(D3DXToRadian(0), D3DXToRadian(90), D3DXToRadian(0)), CHalfSphere::SPHERE_UP);
	m_pHalf->LoadTexture("Data/texture/bg.png");

	

	//m_pFomntString[] = CFontString::Create({ 490.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "�^�C�g��",CObject::PRIORITY_FRONT);
	m_pFomntString[0] = CFontString::Create({ 500.0f, 600.0f, 0.0f }, { 30.0f, 30.0f }, "ENTER");

	// �ÓI�ϐ�������
	m_bWindowUninit = false;
	m_bWindow = false;

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CTitle::Uninit()
{
	// ���j���[�E�B���h�E�̏I������
	if (m_pMenuWindow != nullptr)
	{
		m_pMenuWindow->Uninit();
		delete m_pMenuWindow;
		m_pMenuWindow = nullptr;
	}
}

//==============================================================================================
//�X�V����
//==============================================================================================
void CTitle::Update()
{
	CInput* pInput = CInput::GetKey();

	// �E�B���h�E���\������Ă��Ȃ��ꍇ
	if(m_pMenuWindow == nullptr)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Trigger(JOYPAD_B) || pInput->Trigger(JOYPAD_A)
			|| pInput->Trigger(JOYPAD_START))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			// ���j���[�E�B���h�E�̐���
			m_pMenuWindow = CMenuWindow::Create();

			// ����SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

			return;
		}
	}
	else
	{
		// ���j���[�E�B���h�E�̍X�V
        m_pMenuWindow->Update();
	}
}

//==============================================================================================
// ���j���[�E�B���h�E��j�����鏈��
//==============================================================================================
void CTitle::UninitMenuWindow()
{
	if (m_pMenuWindow != nullptr)
	{
		delete m_pMenuWindow;
		m_pMenuWindow = nullptr;
	}
}

//==============================================================================================
// ��������
//==============================================================================================
CTitle* CTitle::Create()
{
	CTitle* pTitle =  new CTitle;

	if (FAILED(pTitle->Init()))
	{
		return nullptr;
	}

	return pTitle;
}