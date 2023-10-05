//==============================================================================================
//
// �Q�[���@�@�@game.cpp
// tutida ryousei
//
//==============================================================================================
#include "game.h"
#include "application.h"
#include "camera.h"
#include "fade.h"
#include "input.h"
#include "fontString.h"
#include "player_manager.h"
#include "score.h"
#include "time.h"

//==============================================================================================
// �ÓI�����o�ϐ��錾
//==============================================================================================

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CGame::CGame()
{
	
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CGame::~CGame()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CGame::Init()
{
	// �J�����̃|�C���^
	CCamera* pCamera = CApplication::GetCamera();

	// ���_�A�����_�̐ݒ�
	pCamera->SetPosV({ 0.0f, 500.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 1000.0f });

	CFontString::Create({ 515.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "�Q�[��");

	// �v���C���[�̐���(�e�X�g)
	CApplication::GetPlayerManager()->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0);

	// �X�R�A�̐���
	m_pScore = CScore::Create();

	// �^�C���̐���
	m_pTime = CTime::Create();

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CGame::Uninit()
{
	// �^�C�}�[�̏I������
	if (m_pTime != nullptr)
	{
		m_pTime->Uninit();
		delete m_pTime;
		m_pTime = nullptr;
	}
}

//==============================================================================================
//�X�V����
//==============================================================================================
void CGame::Update()
{
	// �^�C�}�[�̍X�V
	m_pTime->Update();

	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Trigger(DIK_SPACE) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			CFade::SetFade(CApplication::MODE_RESULT, 0.05f);
		}
	}
	// �f�o�b�O��p�R�}���h
#ifdef _DEBUG
	// ��Shift�L�[���������܂܂̏ꍇ
	if (pInput->Press(DIK_LSHIFT))
	{
		int nKey = -1;
		if (pInput->Trigger(DIK_1))
		{
			nKey = 0;
		}
		if (pInput->Trigger(DIK_2))
		{
			nKey = 1;
		}
		if (pInput->Trigger(DIK_3))
		{
			nKey = 2;
		}
		if (pInput->Trigger(DIK_4))
		{
			nKey = 3;
		}

		if (nKey >= 0)
		{
			CPlayerManager* pPlayerManager = CApplication::GetPlayerManager();
			CPlayer* pPlayer = pPlayerManager->GetPlayer(nKey);

			if (pPlayer == nullptr)
			{
				// �v���C���[�̐���
				pPlayerManager->SetPlayer({ -300.0f + (200.0f * nKey), 0.0f, 0.0f }, CPlayerManager::TYPE_PC, nKey);
			}
			else
			{
				pPlayerManager->PlayerRelease(nKey);
			}
		}
	}

	// �X�R�A�̉��Z
	if (pInput->Press(DIK_L))
	{
		m_pScore->AddScore(10);
	}

#endif
}

//==============================================================================================
// ��������
//==============================================================================================
CGame* CGame::Create()
{
	CGame* pGame = new CGame;

	if (FAILED(pGame->Init()))
	{
		return nullptr;
	}

	return pGame;
}