//=============================================================================
//
// PlayerData.cpp (�v���C���[�f�[�^.cpp)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "application.h"
#include "playerdata.h"
#include "char_select.h"
#include "confirmation_window.h"
#include "charselect_window.h"
#include "chardecision_window.h"
#include "player_manager.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayerData::CPlayerData()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayerData::~CPlayerData()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayerData::Init()
{
	//==================================================
	// �����o�ϐ��̏�����
	//================================================== 
	PlayerIndex = 0;
	m_pPlayerManager = CPlayerManager::Create();				// �v���C���[�}�l�[�W���[�̐���

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CPlayerData::Uninit()
{
	// �v���C���[�}�l�[�W���[�̔j��
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CPlayerData::Update()
{
	if (CChar_Select::GetConfimationWindow() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetScaleReduce() == true)
	{// �S�E�B���h�E��null�`�F�b�N && �L��������E�B���h�E��������

	 // �v���C���[�̃W���u�ԍ�
		int nJob_Index = CApplication::GetPlayerJobIndex() % 3;
		m_pPlayerManager->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0, nJob_Index);
	}
}
