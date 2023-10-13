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
	const int nIndex = GetCharaIndex();

	// �J�����̊p�x
	const D3DXVECTOR3 rotCamera = CApplication::GetCamera()->GetRot();

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

	if (pInput->StickPress(JOYKEY_CROSS_UP) || 
		pInput->StickPress(JOYKEY_CROSS_DOWN) || 
		pInput->StickPress(JOYKEY_CROSS_RIGHT) || 
		pInput->StickPress(JOYKEY_CROSS_LEFT))
	{
		// ��]������
		Rotation();

		bWalk = true;
	}

	// �����Ă���ꍇ
	if (bWalk == true)
	{
		// �v���C���[�̈ړ�
		//if ((pInput->Press(DIK_W) && nIndex == 0) || pInput->Press(JOYPAD_UP, nIndex))
		//{
		//	if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		//	{// ���O
		//		rotDest.y = rotCamera.y + D3DX_PI * 3 / 4;
		//		move.x = -sinf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.x;
		//		move.z = -cosf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.z;
		//	}
		//	else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		//	{// �E�O
		//		rotDest.y = rotCamera.y - D3DX_PI * 3 / 4;
		//		move.x = sinf(rotCamera.y + D3DX_PI / 4) * boostMove.x;
		//		move.z = cosf(rotCamera.y + D3DX_PI / 4) * boostMove.z;
		//	}
		//	else
		//	{// �O
		//		rotDest.y = rotCamera.y + D3DX_PI;
		//		move.x = sinf(rotCamera.y) * boostMove.x;
		//		move.z = cosf(rotCamera.y) * boostMove.z;
		//	}
		//}
		//else if ((pInput->Press(DIK_S) && nIndex == 0) || pInput->Press(JOYPAD_DOWN, nIndex))
		//{
		//	if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		//	{// ����
		//		rotDest.y = rotCamera.y + D3DX_PI / 4;
		//		move.x = -sinf(rotCamera.y + D3DX_PI / 4) * boostMove.x;
		//		move.z = -cosf(rotCamera.y + D3DX_PI / 4) * boostMove.z;
		//	}
		//	else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		//	{// �E��
		//		rotDest.y = rotCamera.y - D3DX_PI / 4;
		//		move.x = sinf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.x;
		//		move.z = cosf(rotCamera.y + D3DX_PI * 3 / 4) * boostMove.z;
		//	}
		//	else
		//	{// ��
		//		rotDest.y = rotCamera.y;
		//		move.x = -sinf(rotCamera.y) * boostMove.x;
		//		move.z = -cosf(rotCamera.y) * boostMove.z;
		//	}
		//}
		//else if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		//{// ��
		//	rotDest.y = rotCamera.y + D3DX_PI / 2;
		//	move.x = -sinf(rotCamera.y + D3DX_PI / 2) * boostMove.x;
		//	move.z = -cosf(rotCamera.y + D3DX_PI / 2) * boostMove.z;
		//}
		//else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		//{// �E
		//	rotDest.y = rotCamera.y - D3DX_PI / 2;
		//	move.x = sinf(rotCamera.y + D3DX_PI / 2) * boostMove.x;
		//	move.z = cosf(rotCamera.y + D3DX_PI / 2) * boostMove.z;
		//}

		D3DXVECTOR3 VectorMove = pInput->VectorMove();
		move.x = VectorMove.x * boostMove.x;
		move.z = VectorMove.y * boostMove.z;

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
	if ((pInput->Press(DIK_SPACE)) || pInput->Press(JOYPAD_A, nIndex))
	{
		// �W�����v���͎��Ԃ̉��Z
		AddJump_PressCount(1);

		if (GetJump_PressCount() < 20)
			// �v���C���[�̃W�����v����
			JumpStart();
		else
			SetJump_Boost(true);
	}
	else
		SetJump_Boost(false);

	if (GetGround())
		// �W�����v���͎��Ԃ̃��Z�b�g
		SetJump_PressCount(0);

	// �U������
	if ((pInput->Trigger(DIK_B)) || pInput->Press(JOYPAD_B, nIndex))
	{
		// �v���C���[�̍U������
		PlayerAttack();
	}

	// �G�l���M�[�Q�[�W�̎擾
	CEnergy_Gauge* pGauge = CGame::GetEnergy_Gauge();

	if (pGauge != nullptr)
	{
		// �n��ɂ���ꍇ
		if (GetGround())
		{
			pGauge->SetConsumption_Speed(3.0f);
			pGauge->SetRecovery_Speed(10.0f);
		}
		// �󒆂ɂ���ꍇ
		else
		{
			pGauge->SetConsumption_Speed(7.0f);
			pGauge->SetRecovery_Speed(0.3f);
		}

		if (!pGauge->GetConsumption())
		{
			if (GetJump_Boost())
				// �W�����v�u�[�X�g�J�n
				JumpBoost();

			if ((pInput->Press(DIK_LSHIFT)) && bWalk)
			{
				// �u�[�X�g����
				SetBoost(true);

				// �G�l���M�[�������
				pGauge->Consumption_Gauge();
			}

			// ���
			if (pInput->Trigger(DIK_C))
			{
				pGauge->Avoidance();			// �G�l���M�[����
				pGauge->Recovery_Pause(30);		// �N�[���^�C��
			}
		}
	}
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