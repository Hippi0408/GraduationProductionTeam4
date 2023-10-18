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
#include "boss.h"
#include "score.h"
#include "time.h"
#include "halfsphere.h"
#include"meshfield.h"
#include"collision.h"
#include"energy_gauge.h"
#include "object2D.h"

CMeshField *CGame::pMeshField = nullptr;
CEnergy_Gauge *CGame::m_pEnergy_Gauge = nullptr;
bool CGame::m_bGameEnd = false;
CFontString* CGame::m_pFinishRogo = nullptr;

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

	// �v���C���[�̐���(�e�X�g)
	CApplication::GetPlayerManager()->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0);

	// �{�X�L�����̐���
	CBoss::Create({ 0.0f, 0.0f, 10000.0f });

	// �^�C���̐���
	m_pTime = CTime::Create();

	// �n�[�t�X�t�B�A�̐���
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(20000.0f, 20000.0f, 20000.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	// ���b�V���t�B�[���h�̐���
	pMeshField = CMeshField::Create({ 0.0f, 0.0f, 0.0f }, 10, 10, 4000.0f);

	// �G�l���M�[�Q�[�W
	m_pEnergy_Gauge = CEnergy_Gauge::Create({ SCREEN_WIDTH / 2, 650.0f, 0.0f }, { 800.0f, 10.0f });

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

	// �G�l���M�[�Q�[�W�̏I������
	if (m_pTime != nullptr)
	{
		m_pEnergy_Gauge = nullptr;
	}

	// �I�����S�̏I��
	if (m_pFinishRogo != nullptr)
	{
		m_pFinishRogo->Uninit();
		m_pFinishRogo = nullptr;
	}

	m_bGameEnd = false;	// �Q�[���I��������U�ɂ���
}

//==============================================================================================
//�X�V����
//==============================================================================================
void CGame::Update()
{
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

		CInput* pInput = CInput::GetKey();

		// �f�o�b�O��p�R�}���h
#ifdef _DEBUG
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
					pPlayer->Damage(50);
				}
			}
		}
		// LShift�L�[�����̏ꍇ
		else
		{
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