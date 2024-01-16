//=============================================================================
//
// player.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "player.h"
#include "input.h"
#include "manager.h"
#include "game.h"
#include "tps_camera.h"
#include "3dobject.h"
#include "read.h"
#include "convenience_function.h"
#include "ballast_manager.h"
#include <assert.h>

const D3DXVECTOR3 CPlayer::INIT_POS = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
const float CPlayer::MOVE_MAGNIFICATION = 1.0f;
//*****************************************************************************
// �R���X�g���N�^
//*****************************************************************************
CPlayer::CPlayer()
{
	m_fSize = MOVE_MAGNIFICATION;
	m_nModelNum = 0;
	m_Pos = INIT_POS;
	m_Rot = INIT_POS;
	m_MoveMagnification = MOVE_MAGNIFICATION;
	m_pModelIndex = nullptr;
	m_p3DObject = nullptr;
	m_nModelIndexMax = 0;
	m_bCollision = true;
	m_bOpeningLost = true;
	m_bSwitch = false;
}

//*****************************************************************************
// �f�X�g���N�^
//*****************************************************************************
CPlayer::~CPlayer()
{
}

//*****************************************************************************
// ������
//*****************************************************************************
HRESULT CPlayer::Init()
{

	CRead CRead;

	CRead.ReadEditorText("data/EDITOR_TEXT/EditorText.txt");

	m_p3DObject = new C3DObject;
	if (FAILED(m_p3DObject->Init()))
	{
		return -1;
	}

	m_p3DObject->SetSize(m_fSize);
	m_p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], INIT_POS, INIT_POS);

	return S_OK;
}

//*****************************************************************************
// �I������
//*****************************************************************************
void CPlayer::Uninit()
{
	//���f���C���f�b�N�X
	if (m_pModelIndex != nullptr)
	{
		delete[] m_pModelIndex;
		m_pModelIndex = nullptr;
	}

	if (m_p3DObject != nullptr)
	{
		m_p3DObject->Uninit();
		delete m_p3DObject;
		m_p3DObject = nullptr;
	}

	//�C�e���[�^�[���[�v
	for (auto itr = m_BallastList.begin(); itr != m_BallastList.end();)
	{
		//�C�e���[�^�[���犢�I�̃|�C���^�̑��
		C3DObject* p3DObject = *itr;

		//���I�|�C���^�̉��
		if (p3DObject != nullptr)
		{
			//�I������
			p3DObject->Uninit();
			delete p3DObject;
			p3DObject = nullptr;
		}

		//���̃C�e���[�^�[�̑���A���݂̃C�e���[�^�[��j��
		itr = m_BallastList.erase(itr);
	}
	
}

//*****************************************************************************
// �X�V����
//*****************************************************************************
void CPlayer::Update()
{
	
	MovePos();

	MoveRot();

	m_Rot = CConvenience_Function::NormalizationRot(m_Rot);

	ChangeSize();

	ChangeMagnification();

	ChangeModel();

	m_p3DObject->SetModelPattnNum(m_nModelNum);

	m_p3DObject->SetParentPos(m_Pos);
	m_p3DObject->SetRot(m_Rot);

	//���̓f�o�C�X�̎擾
	CInput* pInput = CInput::GetKey();
	if (pInput->Trigger(DIK_SPACE))
	{
		SetBullast();
	}

	if (pInput->Trigger(DIK_Y))
	{
		m_bCollision = true;
	}
	else if (pInput->Trigger(DIK_U))
	{
		m_bCollision = false;
	}

	if (pInput->Trigger(DIK_H))
	{
		m_bOpeningLost = true;
	}
	else if (pInput->Trigger(DIK_J))
	{
		m_bOpeningLost = false;
	}

	if (pInput->Trigger(DIK_N))
	{
		m_bSwitch = true;
	}
	else if (pInput->Trigger(DIK_M))
	{
		m_bSwitch = false;
	}

	m_p3DObject->Update();

	//�C�e���[�^�[���[�v
	for (auto itr = m_BallastList.begin(); itr != m_BallastList.end();itr++)
	{
		//�C�e���[�^�[���犢�I�̃|�C���^�̑��
		C3DObject* p3DObject = *itr;

		//���I�̍X�V
		if (p3DObject != nullptr)
		{
			p3DObject->Update();
		}
	}


	//�O���t�@�C���ɏo��
	if (pInput->Trigger(DIK_F1))
	{
		CRead CRead;

		CRead.SaveEditorData(m_BallastList);
	}


	//�ݒu����߂�
	if (pInput->Trigger(DIK_BACK))
	{
		//�R���e�i�̒����Ȃ�������
		if(m_BallastList.empty())
		{
			return;
		}

		//���[�̎擾
		C3DObject* p3DObject = m_BallastList.back();

		//���I�|�C���^�̉��
		if (p3DObject != nullptr)
		{
			//�I������
			p3DObject->Uninit();
			delete p3DObject;
			p3DObject = nullptr;
		}

		//���[��j��
		m_BallastList.pop_back();
	}

}

//*****************************************************************************
// �`�揈��
//*****************************************************************************
void CPlayer::Draw()
{
	m_p3DObject->CalculationMatrix();
	m_p3DObject->Draw();
	//�C�e���[�^�[���[�v
	for (auto itr = m_BallastList.begin(); itr != m_BallastList.end(); itr++)
	{
		//�C�e���[�^�[���犢�I�̃|�C���^�̑��
		C3DObject* p3DObject = *itr;

		//���I�̕`��
		if (p3DObject != nullptr)
		{
			p3DObject->CalculationMatrix();
			p3DObject->Draw();
		}
	}
}

//Pos�̈ړ�
void CPlayer::MovePos()
{
	//���̓f�o�C�X�̎擾
	CInput* pInput = CInput::GetKey();
	//�}�l�[�W���[����Q�[���I�u�W�F�N�g�̎擾
	CManager *pManager = GetManager();
	CGame* pGame = (CGame*)pManager->GetGameObject();

	CTpsCamera* pTpsCamera = (CTpsCamera*)pGame->GetCamera();

	//�J�����̌����iY���̂݁j
	float rotY = pTpsCamera->GetRot();

	//���_�ړ�
	if (pInput->Press(DIK_W))
	{//��L�[�������ꂽ
		if (pInput->Press(DIK_A))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * 0.75f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * 0.75f) * m_MoveMagnification;
		}
		else if (pInput->Press(DIK_D))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * -0.75f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * -0.75f) * m_MoveMagnification;
		}
		else
		{
			m_Pos.x += sinf(rotY) * m_MoveMagnification;
			m_Pos.z += cosf(rotY) * m_MoveMagnification;
		}
	}
	else if (pInput->Press(DIK_S))
	{//���L�[�������ꂽ
		if (pInput->Press(DIK_A))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * 0.25f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * 0.25f) * m_MoveMagnification;
		}
		else if (pInput->Press(DIK_D))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * -0.25f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * -0.25f) * m_MoveMagnification;
		}
		else
		{
			m_Pos.x += sinf(rotY + D3DX_PI) * m_MoveMagnification;
			m_Pos.z += cosf(rotY + D3DX_PI) * m_MoveMagnification;
		}
	}
	else if (pInput->Press(DIK_A))
	{//���L�[�������ꂽ
		m_Pos.x += sinf(rotY + D3DX_PI * -0.5f) * m_MoveMagnification;
		m_Pos.z += cosf(rotY + D3DX_PI * -0.5f) * m_MoveMagnification;
	}
	else if (pInput->Press(DIK_D))
	{//�E�L�[�������ꂽ
		m_Pos.x += sinf(rotY + D3DX_PI * 0.5f) * m_MoveMagnification;
		m_Pos.z += cosf(rotY + D3DX_PI * 0.5f) * m_MoveMagnification;
	}

	if (pInput->Press(DIK_LSHIFT))
	{
		m_Pos.y += m_MoveMagnification;
	}
	else if (pInput->Press(DIK_LCONTROL))
	{
		m_Pos.y -= m_MoveMagnification;
	}

	//���Z�b�g
	if (!pInput->Press(DIK_0))
	{
		return;
	}

	if (pInput->Press(DIK_1))
	{
		m_Pos.x = 0.0f;
	}
	else if (pInput->Press(DIK_2))
	{
		m_Pos.y = 0.0f;
	}
	else if (pInput->Press(DIK_3))
	{
		m_Pos.z = 0.0f;
	}
	
}

//Rot�̒���
void CPlayer::MoveRot()
{
	//���̓f�o�C�X�̎擾
	CInput* pInput = CInput::GetKey();

	if (pInput->Press(DIK_R))
	{
		m_Rot.x += D3DXToRadian(1);
	}
	else if (pInput->Press(DIK_T))
	{
		m_Rot.x -= D3DXToRadian(1);
	}

	if (pInput->Press(DIK_F))
	{
		m_Rot.y += D3DXToRadian(1);
	}
	else if (pInput->Press(DIK_G))
	{
		m_Rot.y -= D3DXToRadian(1);
	}

	if (pInput->Press(DIK_V))
	{
		m_Rot.z += D3DXToRadian(1);
	}
	else if (pInput->Press(DIK_B))
	{
		m_Rot.z -= D3DXToRadian(1);
	}


	//���Z�b�g
	if (!pInput->Press(DIK_0))
	{
		return;
	}

	if (pInput->Press(DIK_4))
	{
		m_Rot.x = 0.0f;
	}
	else if (pInput->Press(DIK_5))
	{
		m_Rot.y = 0.0f;
	}
	else if (pInput->Press(DIK_6))
	{
		m_Rot.z = 0.0f;
	}
}

//�{���̕ύX
void CPlayer::ChangeMagnification()
{
	//���̓f�o�C�X�̎擾
	CInput* pInput = CInput::GetKey();

	if (pInput->Press(DIK_LEFT))
	{
		m_MoveMagnification += MOVE_MAGNIFICATION;
	}
	else if (pInput->Press(DIK_RIGHT))
	{
		m_MoveMagnification -= MOVE_MAGNIFICATION;
	}

	//���Z�b�g
	if (!pInput->Press(DIK_0))
	{
		return;
	}

	if (pInput->Press(DIK_7))
	{
		m_MoveMagnification = MOVE_MAGNIFICATION;
	}
}

//�\�����f���̕ύX
void CPlayer::ChangeModel()
{
	//���̓f�o�C�X�̎擾
	CInput* pInput = CInput::GetKey();
	bool bUes = false;

	if (pInput->Trigger(DIK_UP))
	{
		m_nModelNum++;
		bUes = true;
	}
	else if (pInput->Trigger(DIK_DOWN))
	{
		m_nModelNum--;
		bUes = true;
	}

	if (m_nModelNum >= m_nModelIndexMax)
	{
		m_nModelNum = 0;
	}
	else if (m_nModelNum < 0)
	{
		m_nModelNum = m_nModelIndexMax - 1;
	}

	if (bUes)
	{
		m_p3DObject->Uninit();
		m_p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], INIT_POS, INIT_POS);
	}
}

//�`�F���W�T�C�Y
void CPlayer::ChangeSize()
{
	//���̓f�o�C�X�̎擾
	CInput* pInput = CInput::GetKey();
	bool bUes = false;

	if (pInput->Trigger(DIK_K))
	{
		m_fSize += m_MoveMagnification;
		bUes = true;
	}
	else if (pInput->Trigger(DIK_L))
	{
		m_fSize -= m_MoveMagnification;
		bUes = true;
	}
	//���Z�b�g
	if (pInput->Press(DIK_0) && pInput->Press(DIK_8))
	{
		m_fSize = 1.0f;
		bUes = true;
	}

	if (bUes)
	{
		m_p3DObject->Uninit();
		m_p3DObject->SetSize(m_fSize);
		m_p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], INIT_POS, m_Rot);
	}
}

//���I�̐ݒu
void CPlayer::SetBullast()
{
	//���I�N���X�̐���
	C3DObject* p3DObject = new C3DObject;

	//������
	if (FAILED(p3DObject->Init()))
	{
		assert(false);
	}

	//�����蔻��
	p3DObject->SetCollision(m_bCollision);

	//�I�[�v�j���O���X�g
	p3DObject->SetOpeningLost(m_bOpeningLost);

	//�C��
	p3DObject->SetSwitch(m_bSwitch);

	//���f���ԍ��̃C���f�b�N�X
	p3DObject->SetModelNumIndex(m_nModelNum);

	//�g�p���郂�f���ԍ��A���I�̈ʒu�A���I�̌���
	p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], m_Pos, m_Rot);

	//�@���ݒ�
	p3DObject->SetNormal();

	//���X�g�Ɋ��I����ǉ�
	m_BallastList.push_back(p3DObject);
}
