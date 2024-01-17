//=============================================================================
//
// game.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "manager.h"
#include "game.h"
#include "input.h"
#include "texture.h"
#include "camera.h"
#include "light.h"
#include "meshfield.h"
#include "player.h"
#include "billboard.h"
#include "tps_camera.h"
#include "read.h"
#include "ballast_manager.h"
#include <assert.h>

//*****************************************************************************
// �R���X�g���N�^
//*****************************************************************************
CGame::CGame()
{
}

//*****************************************************************************
// �f�X�g���N�^
//*****************************************************************************
CGame::~CGame()
{
}

//*****************************************************************************
// ������
//*****************************************************************************
HRESULT CGame::Init()
{
	//�J����
	m_pCamera = new CTpsCamera;
	if (FAILED(m_pCamera->Init()))
	{
		return -1;
	}

	//���C�g
	m_pLight = new CLight;
	if (FAILED(m_pLight->Init()))
	{
		return -1;
	}

	
	CRead cRead;

	m_pPlayer = new CPlayer;
	if (FAILED(m_pPlayer->Init()))
	{
		return -1;
	}
	
	//BG3D
	m_pMeshfieldBG = cRead.ReadMap("Data/MAPTXT/map.txt");
	return S_OK;
}

//*****************************************************************************
// �I������
//*****************************************************************************
void CGame::Uninit()
{
	//�J����
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}
	//���C�g
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	//���I�}�l�[�W���[
	if (m_pBallastManager != nullptr)
	{
		m_pBallastManager->Uninit();
		delete m_pBallastManager;
		m_pBallastManager = nullptr;
	}

	//���b�V���t�B�[���h
	if (m_pMeshfieldBG != nullptr)
	{
		m_pMeshfieldBG->Uninit();
		delete m_pMeshfieldBG;
		m_pMeshfieldBG = nullptr;
	}

	//Player
	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Uninit();
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}

	C3DObject::UninitAllModel();
}

//*****************************************************************************
// �X�V����
//*****************************************************************************
void CGame::Update()
{
	m_pCamera->Update();
	m_pPlayer->Update();
	m_pBallastManager->Update();
	CInput *pInput = CInput::GetKey();
}

//*****************************************************************************
// �`�揈��
//*****************************************************************************
void CGame::Draw()
{
	//�J����
	m_pCamera->SetCamera();

	m_pMeshfieldBG->Draw();

	m_pBallastManager->Draw();

	m_pPlayer->Draw();

}

//*****************************************************************************
// ���I�}�l�[�W���[�̐�������
//*****************************************************************************
void CGame::CreateBallastManager(CMeshfield * pMeshfield)
{
	//���I�}�l�[�W���[�̐�������
	m_pBallastManager = new CBallast_Manager;

	//������
	if (FAILED(m_pBallastManager->Init()))
	{
		assert(false);
	}

	//���b�V���t�B�[���h�̏�񂩂�K�v�Ȑ��l�̎擾
	m_pBallastManager->MeshfieldSet(pMeshfield);

}
