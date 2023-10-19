//=============================================================================
//
// �^�C�g�����j���[
// title_menu.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "title_menu.h"
#include "Application.h"
#include "input.h"
#include "fade.h"
#include "title.h"

//=====================================
// �R���X�g���N�^
//=====================================
CTitleMenu::CTitleMenu()
{
}

//=====================================
// �f�X�g���N�^
//=====================================
CTitleMenu::~CTitleMenu()
{

}

//============================================================================
// ����������
//============================================================================
HRESULT CTitleMenu::Init()
{
	// �I�����̐ݒ菈��
	SetChoice(CFontString::Create({ 400.0f, 300.0f, 0.0f}, { 40.0f, 40.0f }, "�Q�[�����͂��߂�"));
	SetChoice(CFontString::Create({ 800.0f / 2, 400.0f ,0.0f }, { 40.0f, 40.0f }, "�`���[�g���A��"));
	SetChoice(CFontString::Create({ 800.0f / 2, 500.0f ,0.0f }, { 40.0f, 40.0f }, "�Ƃ���"));

	//GetChoice(Choice_GameStart)->SetPos({ SCREEN_WIDTH / 2 - 200, 400.0f, 0.0f });

	// �S�Ă̑I������\������
	for (auto pChoice : GetChoiceAll())
	{
		pChoice->SetFontDraw(false);
	}

	// ���j���[�̏���������
	CMenu::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CTitleMenu::Uninit()
{
	// ���j���[�̏I������
	CMenu::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CTitleMenu::Update()
{
	// ���j���[�̍X�V����
	CMenu::Update();

	// �I�����̏���
	Choice();
}

//============================================================================
// �I�����̏���
//============================================================================
void CTitleMenu::Choice()
{
	// ���j���[�̑I�����̏���
	CMenu::Choice();

	// ���肳�ꂽ�ꍇ
	if (GetDecition() == true)
	{
		// ���ݑI������Ă���I�����̏�����ǂݍ���
		switch ((Choice_Type)GetSelectChoice())
		{
			// �Q�[���X�^�[�g
		case Choice_GameStart:
			// ����SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);
			// �Q�[���ɔ��
			CFade::SetFade(CApplication::MODE_GAME, 0.05f);
			CTitle::SetUninitWindow(false);
			break;

			// �`���[�g���A��
		case Choice_Tutorial:
			// ����SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);
			//// �`���[�g���A����ʂɔ��
			//CFade::SetFade(CApplication::MODE_ENTRY, 0.05f);
			break;

			// �E�B���h�E�����
		case Choice_Window_Exit:
			// ����SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

			// �\��������U�ɂ���
			SetDisplay(false);
			break;
		default:
			break;
		}
	}
	// �����j������
	SetDecition(false);
}

//============================================================================
// ��������
//============================================================================
CTitleMenu* CTitleMenu::Create()
{
	CTitleMenu* pTitleMenu = new CTitleMenu;

	if (FAILED(pTitleMenu->Init()))
	{
		return nullptr;
	}

	return pTitleMenu;
}
