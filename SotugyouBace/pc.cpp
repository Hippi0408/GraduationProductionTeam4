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

	if (pInput->MovePress(GAME_MOVE_ALL))
	{
		// ��]������
		Rotation();

		bWalk = true;
	}

	// �����Ă���ꍇ
	if (bWalk == true)
	{
		//�J�����̌����iY���̂݁j
		float rotY = rotCamera.y;

		//���_�ړ�
		if (pInput->MovePress(GAME_MOVE_UP))
		{//��L�[�������ꂽ
			if (pInput->MovePress(GAME_MOVE_LEFT))
			{
				move.x = -sinf(rotY + D3DX_PI * 0.75f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * 0.75f) * boostMove.z;
			}
			else if (pInput->MovePress(GAME_MOVE_RIGHT))
			{
				move.x = -sinf(rotY + D3DX_PI * -0.75f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * -0.75f) * boostMove.z;
			}
			else
			{
				move.x = sinf(rotY) * boostMove.x;
				move.z = cosf(rotY) * boostMove.z;
			}
		}
		else if (pInput->MovePress(GAME_MOVE_DOWN))
		{//���L�[�������ꂽ
			if (pInput->MovePress(GAME_MOVE_LEFT))
			{
				move.x = -sinf(rotY + D3DX_PI * 0.25f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * 0.25f) * boostMove.z;
			}
			else if (pInput->MovePress(GAME_MOVE_RIGHT))
			{
				move.x = -sinf(rotY + D3DX_PI * -0.25f) * boostMove.x;
				move.z = -cosf(rotY + D3DX_PI * -0.25f) * boostMove.z;
			}
			else
			{
				move.x = sinf(rotY + D3DX_PI) * boostMove.x;
				move.z = cosf(rotY + D3DX_PI) * boostMove.z;
			}
		}
		else if (pInput->MovePress(GAME_MOVE_LEFT))
		{//���L�[�������ꂽ
			move.x = sinf(rotY + D3DX_PI * -0.5f) * boostMove.x;
			move.z = cosf(rotY + D3DX_PI * -0.5f) * boostMove.z;
		}
		else if (pInput->MovePress(GAME_MOVE_RIGHT))
		{//�E�L�[�������ꂽ
			move.x = sinf(rotY + D3DX_PI * 0.5f) * boostMove.x;
			move.z = cosf(rotY + D3DX_PI * 0.5f) * boostMove.z;
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
	if ((pInput->Press(DIK_SPACE)) || pInput->Press(JOYPAD_A))
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
	if ((pInput->Trigger(DIK_B)) || pInput->Press(JOYPAD_R2))
	{
		// �v���C���[�̍U������
		PlayerAttack();
	}

	// ���_����
	Perspective();

	// �G�l���M�[�Q�[�W�̎擾
	CEnergy_Gauge* pGauge = CGame::GetEnergy_Gauge();

	if (pGauge != nullptr)
	{
		// �n��ɂ���ꍇ
		if (GetGround())
		{
			// ����x
			pGauge->SetConsumption_Speed(3.0f);
			// �񕜑��x
			pGauge->SetRecovery_Speed(10.0f);
		}
		// �󒆂ɂ���ꍇ
		else
		{
			// ����x
			pGauge->SetConsumption_Speed(6.0f);
			// �񕜑��x
			pGauge->SetRecovery_Speed(0.3f);
		}

		// �G�l���M�[���c���Ă�����
		if (!pGauge->GetConsumption())
		{
			if (GetJump_Boost())
				// �W�����v�u�[�X�g
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