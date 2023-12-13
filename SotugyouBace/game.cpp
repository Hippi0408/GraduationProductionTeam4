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
#include "drop_manager.h"
#include "collision_manager.h"
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
#include "drop_weapon.h"
#include "player_ui.h"
#include"debugProc.h"
#include"pause.h"
#include "parts_file.h"
#include "motion.h"
#include "map.h"
#include "weapon.h"
#include "connect.h"
#include "player_parameter.h"
#include "map_object_manager.h"

//==============================================================================================
// �ÓI�����o�ϐ��錾
//==============================================================================================
CPlayerUi* CGame::m_pPlayer_UI[CPlayerUi::UITYPE_MAX] = {};
CConfirmation_Window* CGame::m_pConfirmationWindow = nullptr;
CPlayerManager* CGame::m_pPlayerManager = nullptr;
CEnemyManager* CGame::m_pEnemyManager = nullptr;
CDropManager* CGame::m_pDropManager = nullptr;
CCollision_Manager* CGame::m_pCollision_Manager = nullptr;
CMeshField *CGame::m_pMeshField = nullptr;
bool CGame::m_bGameEnd = false;
bool CGame::m_bGameWindow = false;
CFontString* CGame::m_pFinishRogo = nullptr;
CPause *CGame::m_pPause = nullptr;
CPlayer_Parameter *CGame::m_pPlayer_Parameter = nullptr;
CMap_Object_Manager *CGame::m_pMap_Object_Manager = nullptr;

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
	pCamera->SetPosV({ 0.0f, 225.0f, -450.0f });
	pCamera->SetPosR({ 0.0f, 112.5f, 450.0f });

	// �S�Ẵ��f���p�[�c�̓ǂݍ���
	CApplication::GetPartsFile()->LoadAllFile();

	// �S�Ẵ��f���p�[�c�̓ǂݍ���
	CApplication::GetMotion()->LoadAllFile();

	// �v���C���[�p�����[�^�[�̐���
	m_pPlayer_Parameter = new CPlayer_Parameter;
	m_pPlayer_Parameter->Init();

	// �v���C���[UI�̐���
	m_pPlayer_UI[CPlayerUi::UITYPE_SUPPORT] = CPlayerUi::Create(D3DXVECTOR3(1200.0f, 50.0f, 0.0f), D3DXVECTOR2(100.0f, 75.0f), CPlayerUi::UITYPE_SUPPORT, CObject::PRIORITY_CENTER);
	m_pPlayer_UI[CPlayerUi::UITYPE_ATTACK] = CPlayerUi::Create(D3DXVECTOR3(100.0f, 50.0f, 0.0f), D3DXVECTOR2(100.0f, 75.0f), CPlayerUi::UITYPE_ATTACK, CObject::PRIORITY_CENTER);
	m_pPlayer_UI[CPlayerUi::UITYPE_WEAPON] = CPlayerUi::Create(D3DXVECTOR3(1200.0f, 660.0f, 0.0f), D3DXVECTOR2(100.0f, 85.0f), CPlayerUi::UITYPE_WEAPON, CObject::PRIORITY_CENTER);

	m_pPlayerManager = CPlayerManager::Create();	// �v���C���[�}�l�[�W���[�̐���
	m_pEnemyManager = new CEnemyManager;			// �G�L�����}�l�[�W���[�̐���
	m_pDropManager = new CDropManager;				// ���Ƃ����}�l�[�W���[�̐���
	m_pCollision_Manager = new CCollision_Manager;	// �����蔻��}�l�[�W���[�̐���
	m_pMap_Object_Manager = new CMap_Object_Manager;

	// �S�Ẵ��f���p�[�c�̓ǂݍ���
	CDrop_Weapon* pWeaponDummer = new CDrop_Weapon;
	pWeaponDummer->LoadAllFile();
	pWeaponDummer->Uninit();

	// �v���C���[�̃W���u�ԍ�
	int nJob_Index = CApplication::GetPlayerJobIndex() % 3;

	// �v���C���[�̐���(�e�X�g)

	m_pPlayerManager->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0, nJob_Index);

	for (int nCnt = 0; nCnt < 20; nCnt++)
	{
		// ���u�L�����̐���
		CMob::Create({ utility::Random<float>(5000.0f, -5000.0f), utility::Random<float>(600.0f, -200.0f), utility::Random<float>(15000.0f, -500.0f) });
	}
	
	// �{�X�L�����̐���
	CBoss::Create({ 0.0f, 0.0f, 10000.0f });

	// ����A�p�[�c�̃h���b�v
	SetDrop_Parts(20, { 0.0f,0.0f,0.0f }, true);

	// �^�C���̐���
	m_pTime = CTime::Create();

	// �n�[�t�X�t�B�A�̐���
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(20000.0f, 20000.0f, 20000.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	// ���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshField::Create({ 0.0f, 0.0f, 0.0f }, 10, 10, 4000.0f);

	// �|�[�Y���
	m_pPause = CPause::Create();

	m_nEndCounter = 0;
	m_bInputFlag = false;

	// �}�b�v����
	CMap::ReadMap("Data/text/map.txt");

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CGame::Uninit()
{
	// �v���C���[�p�����[�^�[�̔j��
	if (m_pPlayer_Parameter != nullptr)
	{
		m_pPlayer_Parameter->Uninit();
		delete m_pPlayer_Parameter;
		m_pPlayer_Parameter = nullptr;
	}

	// �v���C���[�}�l�[�W���[�̔j��
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}

	// �G�L�����}�l�[�W���[�̔j��
	if (m_pEnemyManager != nullptr)
	{
		delete m_pEnemyManager;
		m_pEnemyManager = nullptr;
	}

	// ���Ƃ����}�l�[�W���[�̔j��
	if (m_pDropManager != nullptr)
	{
		delete m_pDropManager;
		m_pDropManager = nullptr;
	}

	// �R���W�����}�l�[�W���[�̔j��
	if (m_pCollision_Manager != nullptr)
	{
		// �S�Ă̓����蔻��̉������
		m_pCollision_Manager->ReleaseAllCollision();
		delete m_pCollision_Manager;
		m_pCollision_Manager = nullptr;
	}

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
	if (m_pConfirmationWindow != nullptr)
	{
		m_pConfirmationWindow->Uninit();
		delete m_pConfirmationWindow;
		m_pConfirmationWindow = nullptr;
	}

	// �v���C���[UI�̏I������
	for (int nCnt = 0; nCnt < CPlayerUi::UITYPE_MAX; nCnt++)
	{
		if (m_pPlayer_UI[nCnt] != nullptr)
		{
			m_pPlayer_UI[nCnt]->Uninit();
			m_pPlayer_UI[nCnt] = nullptr;
		}
	}

	//�}�b�v�I�u�W�F�N�g�̔j��
	if (m_pMap_Object_Manager != nullptr)
	{
		delete m_pMap_Object_Manager;
		m_pMap_Object_Manager = nullptr;
	}

	m_bGameEnd = false;	// �Q�[���I��������U�ɂ���
}

//==============================================================================================
//�X�V����
//==============================================================================================
void CGame::Update()
{
	// ���j���[�E�B���h�E����
	MenuWindow();

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
					CPlayer* pPlayer = m_pPlayerManager->GetPlayer(0);
					pPlayer->GetParts(CPlayer::PARTS_BODY)->SetParts(CParts_File::PARTS_PLAYER_BODY_1 + nKey);
				}
			}

			// �X�R�A�̉��Z
			if (pInput->Trigger(DIK_0))
			{
				for (auto pEnemy : m_pEnemyManager->GetAllEnemy())
				{
					// 50�_���[�W
					pEnemy->Damage(50);
				}
			}

			/*if (pInput->Trigger(DIK_O))
			{
				CLocus::Create(D3DXVECTOR3(0.0f,200.0f,0.0f),1000.0f,10);
			}*/
		}
#endif

		//�I�����C���̑��M
		if (CApplication::GetClient()->GetIsConnect())
		{
			CModelData::SSendEnemy sendData;
			sendData.m_pos = D3DXVECTOR3(50.0f, 0.0f, 50.0f);
			sendData.m_rot = D3DXVECTOR3(0.1f, 0.0f, 0.1f);
			for (int j = 0; j < 5; j++)
			{
				sendData.m_haveAbnormal.abnormalData[j] = 0;
				sendData.m_haveItem.itemData[j] = 0;
			}
			sendData.m_motion = 0;
			sendData.m_log = 2;
			sendData.m_pushBomComands = 0;

			CApplication::GetClient()->SendPlayerData(sendData);
		}
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
	//// ���݂̃��[�h
	//CApplication::MODE Mode = CApplication::GetModeType();

	//if (Mode == CApplication::MODE_GAME)
	//{
	//	if (this != nullptr && m_bInputFlag == true)
	//	{
	//		pInput->SetKeyLock(100);
	//	}
	//		else if (this != nullptr && m_bInputFlag == false)
	//	{
	//	pInput->UnlockKey(100);
	//	}
	//}
	if (m_pConfirmationWindow == nullptr)
	{
		if (pInput->Trigger(DIK_M))
		{
			m_pConfirmationWindow = CConfirmation_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f),500.0f, 320.0f, D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f));
			return;
		}
	}
	else
	{
		m_pConfirmationWindow->Update();
	}
	// �E�B���h�E�������ꍇ 
	if (m_pConfirmationWindow != nullptr && m_pConfirmationWindow->GetUninit() == true)
	{
		delete m_pConfirmationWindow;
		m_pConfirmationWindow = nullptr;
	}
}

//==============================================================================================
// �v���C���[UI�e�N�X�`���̐ݒ�
//==============================================================================================
void CGame::SetPlayerUI(const int index, const int type)
{
	// �e�N�X�`���ԍ�
	int nTexNumber = 0;

	if (index == CPlayerUi::UITYPE_SUPPORT)
	{
		// �T�|�[�g�X�L���̍Œ�l + ���g�̔ԍ���ݒ�
		nTexNumber = CTexture::TEXTURE_SKILL_RUSH + type;
	}
	else
	{
		// �ߐڕ���̍Œ�l���傫���ꍇ
		if (type >= CWeapon::WEAPON_SLASH_KNIFE)
		{
			// ����̍Œ�l�������l�ɐݒ�
			nTexNumber = CTexture::TEXTURE_ATTACK_SKILL_SLASH;
		}
		// �f��̍Œ�l���傫���ꍇ
		else
		{
			// ����̍Œ�l�������l�ɐݒ�
			nTexNumber = CTexture::TEXTURE_WEAPON_KNUCKLE;
		}
	}

	// �X�L���摜�̐ݒ�
	m_pPlayer_UI[index]->GetSkillUI()->SetTexture((CTexture::TEXTURE)nTexNumber);
}

//==============================================================================================
// ����A�p�[�c�̃h���b�v
//==============================================================================================
void CGame::SetDrop_Parts(int num, D3DXVECTOR3 pos, bool random)
{
	for (int nCnt = 0; nCnt < num; nCnt++)
	{
		D3DXVECTOR3 Pos = pos;
		if (random)
			// �����_���Ȉʒu
			Pos = { utility::Random<float>(5000.0f, -5000.0f), utility::Random<float>(600.0f, -200.0f), utility::Random<float>(15000.0f, -500.0f) };

		// �^�C�v�̐ݒ�
		int nRandType = 0;

		// �^�C�v
		nRandType = utility::Random<int>(CDrop_Weapon::DROP_PARTS_MAX, 0);

		// �ő吔 �܂��� �f�肪�ǂݍ��܂ꂽ�ꍇ��蒼������
		while (CDrop_Weapon::ARMS_MAX == nRandType || CDrop_Weapon::LEG_MAX == nRandType
			|| CDrop_Weapon::WEAPON_NONE == nRandType || CDrop_Weapon::WEAPON_MAX == nRandType)
		{
			// �^�C�v
			nRandType = utility::Random<int>(CDrop_Weapon::DROP_PARTS_MAX, 0);
		}

		// ����
		CDrop_Weapon::Create(Pos, nRandType);
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