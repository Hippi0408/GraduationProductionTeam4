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
#include "enemy_manager.h"
#include "mob.h"
#include "boss.h"
#include "score.h"
#include "time.h"
#include "halfsphere.h"
#include"meshfield.h"
#include"collision.h"
#include "locus.h"
#include "object2D.h"
#include "confirmation_window.h"
#include "menu.h"
#include "utility.h"
#include "parts.h"
#include "parts_file.h"

CMeshField *CGame::m_pMeshField = nullptr;
bool CGame::m_bGameEnd = false;
bool CGame::m_bGameWindow = false;
CFontString* CGame::m_pFinishRogo = nullptr;
CPlayerManager* CGame::m_pPlayer_Manager = nullptr;

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
	pCamera->SetPosR({ 0.0f, 250.0f, 1000.0f });

	// �S�Ẵ��f���p�[�c�̓ǂݍ���
	CApplication::GetPartsFile()->LoadAllFile();

	// �v���C���[�̐���(�e�X�g)
	m_pPlayer_Manager = CApplication::GetPlayerManager();
	m_pPlayer_Manager->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0);

	for (int nCnt = 0; nCnt < 20; nCnt++)
	{
		// ���u�L�����̐���
		CMob::Create({ utility::Random<float>(1000.0f, -1000.0f), utility::Random<float>(600.0f, -200.0f), utility::Random<float>(9000.0f, 200.0f) });
	}

	// �{�X�L�����̐���
	CBoss::Create({ 0.0f, 0.0f, 10000.0f });

	// �^�C���̐���
	m_pTime = CTime::Create();

	// �n�[�t�X�t�B�A�̐���
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(20000.0f, 20000.0f, 20000.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	// ���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshField::Create({ 0.0f, 0.0f, 0.0f }, 10, 10, 4000.0f);

	m_nEndCounter = 0;

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

	// �I�����S�̏I��
	if (m_pFinishRogo != nullptr)
	{
		m_pFinishRogo->Uninit();
		m_pFinishRogo = nullptr;
	}

	// ���j���[�E�B���h�E�̏I������
	if (m_ponfirmationWindow != nullptr)
	{
		m_ponfirmationWindow->Uninit();
		delete m_ponfirmationWindow;
		m_ponfirmationWindow = nullptr;
	}

	m_bGameEnd = false;	// �Q�[���I��������U�ɂ���
}

//==============================================================================================
//�X�V����
//==============================================================================================
void CGame::Update()
{
	// ���j���[�E�B���h�E����
	//MenuWindow();

	// �Q�[���I�����肪�^�̏ꍇ
	if (m_bGameEnd == true)
	{
		GameEnd();	// �Q�[���I������
	}
	else
	{
		// �^�C�}�[�̍X�V
		if (m_pTime != nullptr)
			m_pTime->Update();


		// �f�o�b�O��p�R�}���h
#ifdef _DEBUG
		CInput* pInput = CInput::GetKey();
		if (pInput->Trigger(DIK_F5))
		{
			CFade::SetFade(CApplication::MODE_RESULT, 0.05f);
		}
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
					// 50�_���[�W
					pPlayer->Damage(10);
				}
			}
		}
		// LShift�L�[�����̏ꍇ
		else
		{
			// �p�[�c�ύX����
			if (pInput->Press(DIK_C))
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
				if (pInput->Trigger(DIK_5))
				{
					nKey = 4;
				}
				if (pInput->Trigger(DIK_6))
				{
					nKey = 5;
				}

				if (nKey >= 0)
				{
					CPlayer* pPlayer = CApplication::GetPlayerManager()->GetPlayer(0);
					pPlayer->GetParts(CPlayer::PARTS_BODY)->SetParts(CParts_File::PARTS_PLAYER_BODY_1 + nKey);
				}
			}

			// �X�R�A�̉��Z
			if (pInput->Trigger(DIK_0))
			{
				for (auto pEnemy : CApplication::GetEnemyManager()->GetAllEnemy())
				{
					// 50�_���[�W
					pEnemy->Damage(50);
				}
			}
		}
#endif
	}
}

//==============================================================================================
// �Q�[���I������
//==============================================================================================
void CGame::GameEnd()
{
	// �Q�[�����I������܂ŃJ�E���g
	if (m_nEndCounter < MAX_END_TIMER)
	{
		// �I�����S�𐶐�����
		if ((m_nEndCounter == MAX_FINISH_ROGO) && (m_pFinishRogo == nullptr))
		{
			m_pFinishRogo = CFontString::Create({ SCREEN_WIDTH / 2 - 360, SCREEN_HEIGHT / 2, 0.0f }, { 100.0f, 100.0f }, "�����̓@!");
			m_pFinishRogo->SetColor({ 1.0f, 0.0f, 0.0f, 1.0f });
		}
		m_nEndCounter++;
	}
	// �Q�[�����I��������
	else
	{
		// �I�����S�̏I��
		if (m_pFinishRogo != nullptr)
		{
			m_pFinishRogo->Uninit();
			m_pFinishRogo = nullptr;
		}

		// ���U���g�֔��
		CFade::SetFade(CApplication::MODE_RESULT, 0.05f);
	}
}

//==============================================================================================
// ���j���[�E�B���h�E����
//==============================================================================================
void CGame::MenuWindow()
{
	CInput* pInput = CInput::GetKey();
	if (m_ponfirmationWindow == nullptr)
	{
		if (pInput->Trigger(DIK_M))
		{
			m_ponfirmationWindow = CConfirmation_Window::Create();
			return;
		}
	}
	else
	{
		m_ponfirmationWindow->Update(); 
	}
	// �E�B���h�E�������ꍇ 
	if (m_ponfirmationWindow != nullptr && m_bGameWindow == true)
	{
		m_bGameWindow = false;
		delete m_ponfirmationWindow;
		m_ponfirmationWindow = nullptr;
	}
}

//==============================================================================================
// �Q�[���I������
//==============================================================================================
void CGame::SetGameEnd()
{
	// �Q�[���I�������^�ɂ���
	m_bGameEnd = true;
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