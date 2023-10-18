//==============================================================================================
//
// �^�C�g���@�@�@title.cpp
// tutida ryousei
// tanimoto kosuke
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
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	//CFontString::Create({ 490.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "�^�C�g��");

	m_bWindow = false;

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CTitle::Uninit()
{
}

//==============================================================================================
//�X�V����
//==============================================================================================
void CTitle::Update()
{
	CInput* pInput = CInput::GetKey();

	CMenu* pMenu = CApplication::GetMenu();

	// �E�B���h�E���\������Ă��Ȃ��ꍇ
	if (m_bWindow == false)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Trigger(JOYPAD_B) || pInput->Trigger(JOYPAD_A)
			|| pInput->Trigger(JOYPAD_START))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			// ����SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

			// �E�B���h�E���J��
			m_bWindow = true;

			// ���j���[�̕\��
			pMenu->SetDisplay(true);
			//CFade::SetFade(CApplication::MODE_GAME, 0.05f);
		}
	}

	// �E�C���h�E�������ꍇ
	if (pMenu->GetDisplay() == false)
	{
		m_bWindow = false;
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