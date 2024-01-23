//==============================================================================================
//
// ���U���g�@�@�@result.cpp
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#include "result.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include "camera.h"
#include "fontString.h"
#include "objectX.h"
#include "halfsphere.h"
#include "char_select.h"
#include "confirmation_window.h"
#include "game.h"
#include "menu.h"
#include "title_menu.h"
#include "player_manager.h"
#include "player_parameter.h"
#include "weapon_parameter.h"
#include "score.h"
#include "pause.h"
#include "parts.h"
#include "time.h"

//==============================================================================================
// �ÓI�����o�ϐ��錾
//==============================================================================================
CPlayer_Parameter* CResult::m_pPlayerParameter = nullptr;
CPlayerManager* CResult::m_pPlayerManager = nullptr;

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CResult::CResult()
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CResult::~CResult()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CResult::Init()
{

	//=======================================================
	// �����o�ϐ��̏�����
	//=======================================================
	m_move = D3DXVECTOR3(4.25, 0.1f, 6.25f);
	m_pos = D3DXVECTOR3(-200.0f, 250.0f, 525.0f);
	m_bGetFlag = false;
	m_bCreateFlag = false;
	m_MoveCount = 120;
	m_PlayerIndex = 0;

	// �J�����̃|�C���^
	CCamera* pCamera = CApplication::GetCamera();
	pCamera->SetPosV({ 0.0f, 4.0f,-3.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 3.0f });

	// �v���C���[�ԍ��̎擾
	m_Index = CApplication::GetPlayerJobIndex();

	// �S�Ẵ��f���p�[�c�̓ǂݍ���
	CApplication::GetPartsFile()->LoadAllFile();

	// �S�Ẵ��f���p�[�c�̓ǂݍ���
	CApplication::GetMotion()->LoadAllFile();

	// �v���C���[�p�����[�^�[�̐���
	m_pPlayerParameter = new CPlayer_Parameter;
	m_pPlayerParameter->Init();

	// ����p�����[�^�[�̐���
	m_pWeaponParameter = new CWeapon_Parameter;
	m_pWeaponParameter->Init();

	// �v���C���[�}�l�[�W���[�̐���
	m_pPlayerManager = CPlayerManager::Create();	

	// �v���C���[�̐���(�e�X�g)
	m_pPlayerManager->SetPlayer({ m_pos.x, m_pos.y, m_pos.z }, CPlayerManager::TYPE_PC, m_PlayerIndex, 0);

	// �n�[�t�X�t�B�A�̐���
	m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, -1000.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CResult::Uninit()
{
	// �v���C���[�p�����[�^�[�̔j��
	if (m_pPlayerParameter != nullptr)
	{
		m_pPlayerParameter->Uninit();
		delete m_pPlayerParameter;
		m_pPlayerParameter = nullptr;
	}

	// ����p�����[�^�[�̔j��
	if (m_pWeaponParameter != nullptr)
	{
		m_pWeaponParameter->Uninit();
		delete m_pWeaponParameter;
		m_pWeaponParameter = nullptr;
	}

	// �v���C���[�}�l�[�W���[�̔j��
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}

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
void CResult::Update()
{
	// �C���v�b�g�̎擾����
	CInput* pInput = CInput::GetKey();

	// �X�L���̎��
	//SkillType();

	if (m_PlayerIndex <= 0)// �R�R�̒l��ς���ΐl���𑝂₵���茸�炵����ł���
	{
		// �v���C���[���̎擾
		if (m_pPlayerManager != nullptr && m_bGetFlag == false)
		{
			// �ʒu�̎擾
			m_pos = m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetPos();

			for (int nCnt = 0; nCnt < 3; nCnt++)
			{
				// �p�[�c�̎擾�ƌ����̐ݒ�
				m_pParts[nCnt] = m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetParts(nCnt);
				m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetParts(nCnt)->SetRot(D3DXVECTOR3(0.0f, -D3DX_PI / 3.75f, 0.0f));
			}

			// �擾����
			m_bGetFlag = true;
		}

		// �ړ����Ԃ̌��Z
		m_MoveCount--;
		if (m_MoveCount >= 0)
		{
			// �ړ�
			m_pos.x += m_move.x;
			m_pos.z -= m_move.z;

			// �������[�V����
			for (int nCnt = 0; nCnt < 3; nCnt++)
			{
				m_pParts[nCnt]->SetMotion(CPlayer::MOTION_WALK);
			}

		}
		else if (m_MoveCount <= 0 && m_pObject2D == nullptr && m_pPlayerManager != nullptr)
		{
			m_pObject2D = CObject2D::Create(D3DXVECTOR3(400.0f, 360.0f, 0.0f), D3DXVECTOR2(m_size.x, m_size.y), CObject::PRIORITY_BACK_GROUND);
			m_pObject2D->SetCol(D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));

			// �������I��������
			for (int nCnt = 0; nCnt < 3; nCnt++)
			{
				m_pParts[nCnt]->SetMotion(CPlayer::MOTION_NEUTRAL);
				m_pPlayerManager->GetPlayer(m_PlayerIndex)->GetParts(nCnt)->SetRot(D3DXVECTOR3(0.0f, 0.25f, 0.0f));
			}
		}

		ScaleExpansion();
		if (m_pPlayerManager != nullptr)
		{
			m_pPlayerManager->GetPlayer(m_PlayerIndex)->SetPos(m_pos);
		}

		if (pInput->Trigger(DIK_RETURN) && m_bCreateFlag == true)
		{
			m_PlayerIndex++;
			// �v���C���[���̍폜
			if (m_PlayerIndex <= 3)
			{
				InformationUninit();
			}

			if (m_pPlayerManager == nullptr && m_PlayerIndex <= 0)// �R�R�̒l��ς���ΐl���𑝂₵���茸�炵����ł���)
			{
				// �v���C���[�}�l�[�W���[�̐���
				m_pPlayerManager = CPlayerManager::Create();
				m_pPlayerManager->SetPlayer({ -200.0f, 250.0f, 525.0f }, CPlayerManager::TYPE_PC, m_PlayerIndex, 0);
			}
		}
	}
	if (m_PlayerIndex >= 1)// �R�R�̒l��ς���ΐl���𑝂₵���茸�炵����ł���
	{
		// �^�C�g����ʂɑJ��
		for (int nCnt = 0; nCnt < 4; nCnt++)
		{
			if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
				|| pInput->Trigger(JOYPAD_START, nCnt))
				&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
			{
				CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
			}
		}
	}
}

//=============================================================================
// �T�C�Y�g�又��
//=============================================================================
void CResult::ScaleExpansion()
{
	if (m_pObject2D != nullptr)
	{ // null�`�F�b�N

	  // �T�C�Y�̊g��
		m_size.x += SizeXScaleSpeed;
		m_size.y += SizeYScaleSpeed;

		if (m_size.x >= 700.0f)
		{ // X�T�C�Y�̍ő�
			m_size.x = 700.0f;
		}
		if (m_size.y >= 500.0f)
		{ // Y�T�C�Y�̍ő�
			m_size.y = 500.0f;
		}

		if (m_size.x >= 700.0f && m_size.y >= 500.0f && m_bCreateFlag == false)
		{

			// �^�C���̐���
			m_pTime = CTime::Create(D3DXVECTOR3(540.0f, 150.0f, 0.0f));

			// �^�C�}�[�̍X�V
			if (m_pTime != nullptr)
			{
				m_pTime->SetTime(CApplication::GetDestroyTime());
			}

			m_pScore = CScore::Create(D3DXVECTOR3(100.0f, 500.0f, 0.0f));
			m_pFont[0] = CFontString::Create({ 100.0f, 150.0f, 0.0f }, { 35.0f, 35.0f }, "�������񂰂���");
			m_pFont[1] = CFontString::Create({ 100.0f, 250.0f, 0.0f }, { 35.0f, 35.0f }, "�Ђ��߂��");
			m_pFont[2] = CFontString::Create({ 100.0f, 350.0f, 0.0f }, { 35.0f, 35.0f }, "���������Ă��̂���");
			m_bCreateFlag = true;
		}

		// �T�C�Y�̐ݒ�
		m_pObject2D->SetSize(D3DXVECTOR2(m_size.x, m_size.y));
	}
}

//==============================================================================================
// ���̔j������
//==============================================================================================
void CResult::InformationUninit()
{
	// �v���C���[�}�l�[�W���[�̔j��
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}

	// �I�u�W�F�N�g2D�̔j��
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}

	// �t�H���g�̔j��
	for (int nCnt = 0; nCnt < 3; nCnt++)
	{
		if (m_pFont[nCnt] != nullptr)
		{
			m_pFont[nCnt]->Uninit();
			m_pFont[nCnt] = nullptr;
		}
	}

	// �X�R�A�̔j��
	if (m_pScore != nullptr)
	{
		m_pScore->Uninit();
		m_pScore = nullptr;
	}

	m_bGetFlag = false;
	m_bCreateFlag = false;
	m_MoveCount = 120;
}

//==============================================================================================
// �X�L���̎�ޏ���
//==============================================================================================
void CResult::SkillType()
{
	/*if (m_pObjectX == nullptr)
	{
		if (CApplication::GetSkillType() == true)
		{
			if (m_Index == 0)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
			}
			if (m_Index == 1)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_01.x");
			}
			if (m_Index == 2)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_02.x");
			}
			if (m_Index == 3)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_03.x");
			}
		}
		else
		{
			if (m_Index == 0)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_04.x");
			}
			if (m_Index == 1)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_05.x");
			}
			if (m_Index == 2)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_06.x");
			}
			if (m_Index == 3)
			{
				m_pObjectX = CObjectX::Create(D3DXVECTOR3(-100.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_07.x");
			}
		}
	}*/
}

//==============================================================================================
// ��������
//==============================================================================================
CResult* CResult::Create()
{
	CResult* pResult = new CResult;

	if (FAILED(pResult->Init()))
	{
		return nullptr;
	}

	return pResult;
}
