//=============================================================================
//
// pc.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "pc.h"
#include "application.h"
#include "input.h"
#include "camera.h"
#include "game.h"
#include "meshfield.h"
#include "energy_gauge.h"

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CPC::CPC()
{

}

//=====================================
// �f�X�g���N�^
//=====================================
CPC::~CPC()
{

}

//============================================================================
// ����������
//============================================================================
HRESULT CPC::Init()
{
	CPlayer::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CPC::Uninit()
{
	CPlayer::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CPC::Update()
{
	// ���[�V�����ԍ��̐ݒ�
	ChangeMotion();

	// ���͏���
	Input();

	CPlayer::Update();
}

//============================================================================
// �`�揈��
//============================================================================
void CPC::Draw()
{
	CPlayer::Draw();
}

//==============================================================================================
// ���͏���
//==============================================================================================
void CPC::Input()
{
	//���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	// ���g�̔ԍ�
	//const int nIndex = GetCharaIndex();

	// �J�����̊p�x
	D3DXVECTOR3 rotCamera = CApplication::GetCamera()->GetRot();

	// �ړ���
	D3DXVECTOR3 move = GetMove();

	D3DXVECTOR3 boostMove = { 1.0f,1.0f,1.0f };

	// �u�[�X�g���͈ړ����x���オ��
	if (GetBoost())
		boostMove *= 1.8f;

	SetBoost(false);

	// �ړI�̊p�x
	D3DXVECTOR3 rotDest = GetRotDest();

	// ��������
	bool bWalk = false;

	if (pInput->Press(JOYPAD_UP) || pInput->Press(JOYPAD_DOWN)
		|| pInput->Press(JOYPAD_RIGHT)|| pInput->Press(JOYPAD_LEFT))
	{
		// ��]������
		Rotation();

		bWalk = true;
	}

	// �����Ă���ꍇ
	if (bWalk == true)
	{
		// �v���C���[�̈ړ�
		if ((pInput->Press(DIK_W)) || pInput->Press(JOYPAD_UP))
		{
			if ((pInput->Press(DIK_A)) || pInput->Press(JOYPAD_LEFT))
			{// ���O
				rotDest.y = rotCamera.y + D3DX_PI * 3 / 4;
				move.x = -sinf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.x;
				move.z = -cosf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.z;
			}
			else if ((pInput->Press(DIK_D)) || pInput->Press(JOYPAD_RIGHT))
			{// �E�O
				rotDest.y = rotCamera.y - D3DX_PI * 3 / 4;
				move.x = sinf(rotCamera.y + D3DX_PI / 4) * boostMove.x;
				move.z = cosf(rotCamera.y + D3DX_PI / 4) * boostMove.z;
			}
			else
			{// �O
				rotDest.y = rotCamera.y + D3DX_PI;
				move.x = sinf(rotCamera.y) * boostMove.x;
				move.z = cosf(rotCamera.y) * boostMove.z;
			}
		}
		else if ((pInput->Press(DIK_S)) || pInput->Press(JOYPAD_DOWN))
		{
			if ((pInput->Press(DIK_A)) || pInput->Press(JOYPAD_LEFT))
			{// ����
				rotDest.y = rotCamera.y + D3DX_PI / 4;
				move.x = -sinf(rotCamera.y + D3DX_PI / 4) * boostMove.x;
				move.z = -cosf(rotCamera.y + D3DX_PI / 4) * boostMove.z;
			}
			else if ((pInput->Press(DIK_D)) || pInput->Press(JOYPAD_RIGHT))
			{// �E��
				rotDest.y = rotCamera.y - D3DX_PI / 4;
				move.x = sinf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.x;
				move.z = cosf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.z;
			}
			else
			{// ��
				rotDest.y = rotCamera.y;
				move.x = -sinf(rotCamera.y) * boostMove.x;
				move.z = -cosf(rotCamera.y) * boostMove.z;
			}
		}
		else if ((pInput->Press(DIK_A)) || pInput->Press(JOYPAD_LEFT))
		{// ��
			rotDest.y = rotCamera.y + D3DX_PI / 2;
			move.x = -sinf(rotCamera.y + D3DX_PI / 2) * boostMove.x;
			move.z = -cosf(rotCamera.y + D3DX_PI / 2) * boostMove.z;
		}
		else if ((pInput->Press(DIK_D)) || pInput->Press(JOYPAD_RIGHT))
		{// �E
			rotDest.y = rotCamera.y - D3DX_PI / 2;
			move.x = sinf(rotCamera.y + D3DX_PI / 2) * boostMove.x;
			move.z = cosf(rotCamera.y + D3DX_PI / 2) * boostMove.z;
		}

		// �ڒn���Ă���ꍇ�ɕ������[�V����
		if (GetGround() == true)
		{
			// ����
			SetMotion(MOTION_WALK);
		}

	}
	// �O�񃂁[�V�������������[�V�����������ꍇ
	else if (GetCurrentMotion() == MOTION_WALK)
	{
		// �������I��������
		SetMotion(MOTION_NEUTRAL);
	}

	// �ړ��ʂ��X�V
	CCharacter::SetMove(move);

	// �ړI�̊p�x�̐ݒ�
	CCharacter::SetRotDest(rotDest);

	if (pInput->Trigger(DIK_F))
	{
		CMeshField *pMeshField = nullptr;
		pMeshField = CGame::GetMeshField();

		if (pMeshField != nullptr)
			pMeshField->Ground_Broken(CCharacter::GetPos(), 30.0f, 10);
	}
	// �W�����v����
	if ((pInput->Trigger(DIK_SPACE)) || pInput->Press(JOYPAD_A))
	{
		// �v���C���[�̃W�����v����
		JumpStart();
	}

	// �U������
	if ((pInput->Trigger(DIK_B)) || pInput->Press(JOYPAD_R2))
	{
		// �v���C���[�̍U������
		PlayerAttack();
	}

	// ���_����
	Perspective();

	// �G�l���M�[�Q�[�W�̎擾
	CEnergy_Gauge* pGauge = CGame::GetEnergy_Gauge();
	
	if ((pInput->Press(DIK_LSHIFT))
		&& bWalk && !pGauge->GetConsumption())
	{
		// �u�[�X�g����
		SetBoost(true);

		// �G�l���M�[�������
		pGauge->Consumption_Gauge();
	}

	if (pInput->Trigger(DIK_C) && !pGauge->GetConsumption())
	{
		pGauge->Avoidance();
		pGauge->Recovery_Pause(30);
	}

	//======================================
	//  �J�����̊p�x�̐��K��
	//======================================
	if (rotCamera.y > D3DX_PI)
	{
		rotCamera.y = rotCamera.y - D3DX_PI * 2;
	}
	else if (rotCamera.y < -D3DX_PI)
	{
		rotCamera.y = rotCamera.y + D3DX_PI * 2;
	}
}

//============================================================================
// ���_�̌����̏���
//============================================================================
void CPC::Perspective()
{
	//���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();
	// �J�����̊p�x
	D3DXVECTOR3 rotCamera = CApplication::GetCamera()->GetRot();

	if ((pInput->VectorMoveJoyStick(0,true).y < -0.5f))
	{	//UP�L�[�������Ă���Ƃ�
		rotCamera.x += 1.0f;		//�J�����̏�����̉��Z
	}
	//�J�����̌����̐ݒ�
	CApplication::GetCamera()->SetRot(rotCamera);
}

//============================================================================
// ��������
//============================================================================
CPC* CPC::Create(const D3DXVECTOR3 pos, const int index)
{
	CPC* pPC = new CPC;

	if (FAILED(pPC->Init()))
	{
		return nullptr;
	}

	pPC->SetPos(pos);
	pPC->SetCharaIndex(index);

	return pPC;
}