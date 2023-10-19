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

	// �n�[�t�X�t�B�A�̐���
	m_pHalf = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalf->LoadTexture("Data/texture/sky000.jpg");

	m_pFomntString[0] = CFontString::Create({ 490.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "�^�C�g��");
	m_pFomntString[1] = CFontString::Create({ 500.0f, 600.0f, 0.0f }, { 30.0f, 30.0f }, "ENTER");

	m_bWindowUninit = GetUninitWindow();

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

	// �E�C���h�E�������ꍇ
	if (m_pMenuWindow != nullptr && m_bWindow == true)
	{
		if (pInput->Trigger(DIK_RETURN))
		{
			CApplication::GetMenu()->SetDisplay(false);
			m_bWindowUninit = true;
		}
	}

	if (m_pMenuWindow != nullptr && m_bWindowUninit == true)
	{
		m_pMenuWindow->MenuScaleReduce();
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