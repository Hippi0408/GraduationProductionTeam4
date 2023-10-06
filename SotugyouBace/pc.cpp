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
#include"game.h"
#include"meshfield.h"

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

	// ���[�V����
	Motion();

	// ���͏���
	Input();

	float a = CGame::GetMeshField()->MeshCollision(CCharacter::GetPos());

	CCharacter::SetPos({ CCharacter::GetPos().x,a,CCharacter::GetPos().z });

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
	D3DXVECTOR3 move = { 0.0f, 0.0f, 0.0f };

	// �ړI�̊p�x
	D3DXVECTOR3 rotDest = GetRotDest();

		// �v���C���[�̈ړ�
	if ((pInput->Press(DIK_W) && nIndex == 0) || pInput->Press(JOYPAD_UP, nIndex))
	{
		if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		{// ���O
			rotDest.y = rotCamera.y + D3DX_PI * 3 / 4;
			move.x = -sinf(rotCamera.y + D3DX_PI * 3 / 4);
			move.z = -cosf(rotCamera.y + D3DX_PI * 3 / 4);
		}
		else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		{// �E�O
			rotDest.y = rotCamera.y - D3DX_PI * 3 / 4;
			move.x = sinf(rotCamera.y + D3DX_PI / 4);
			move.z = cosf(rotCamera.y + D3DX_PI / 4);
		}
		else
		{// �O
			rotDest.y = rotCamera.y + D3DX_PI;
			move.x = sinf(rotCamera.y);
			move.z = cosf(rotCamera.y);
		}
	}
	else if ((pInput->Press(DIK_S) && nIndex == 0) || pInput->Press(JOYPAD_DOWN, nIndex))
	{
		if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
		{// ����
			rotDest.y = rotCamera.y + D3DX_PI / 4;
			move.x = -sinf(rotCamera.y + D3DX_PI / 4);
			move.z = -cosf(rotCamera.y + D3DX_PI / 4);
		}
		else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
		{// �E��
			rotDest.y = rotCamera.y - D3DX_PI / 4;
			move.x = sinf(rotCamera.y + D3DX_PI * 3 / 4);
			move.z = cosf(rotCamera.y + D3DX_PI * 3 / 4);
		}
		else
		{// ��
			rotDest.y = rotCamera.y;
			move.x = -sinf(rotCamera.y);
			move.z = -cosf(rotCamera.y);
		}
	}
	else if ((pInput->Press(DIK_A) && nIndex == 0) || pInput->Press(JOYPAD_LEFT, nIndex))
	{// ��
		rotDest.y = rotCamera.y + D3DX_PI / 2;
		move.x = -sinf(rotCamera.y + D3DX_PI / 2);
		move.z = -cosf(rotCamera.y + D3DX_PI / 2);
	}
	else if ((pInput->Press(DIK_D) && nIndex == 0) || pInput->Press(JOYPAD_RIGHT, nIndex))
	{// �E
		rotDest.y = rotCamera.y - D3DX_PI / 2;
		move.x = sinf(rotCamera.y + D3DX_PI / 2);
		move.z = cosf(rotCamera.y + D3DX_PI / 2);
	}

	if ((pInput->Press(DIK_W) && nIndex == 0)
		|| (pInput->Press(DIK_A) && nIndex == 0)
		|| (pInput->Press(DIK_S) && nIndex == 0)
		|| (pInput->Press(DIK_D) && nIndex == 0)
		|| pInput->Press(JOYPAD_RIGHT, nIndex)
		|| pInput->Press(JOYPAD_LEFT, nIndex)
		|| pInput->Press(JOYPAD_UP, nIndex)
		|| pInput->Press(JOYPAD_DOWN, nIndex))
	{
		// ��]������
		Rotation();

		// ����
		SetMotion(MOTION_WALK);
	}
	else
	{
		// �������I��������
		SetMotion(MOTION_NEUTRAL);
	}
	if (pInput->Trigger(DIK_F))
	{
		CGame::GetMeshField()->Ground_Broken(CCharacter::GetPos(), 50.0f, 5);
	}

	// �ړ��ʂ��X�V
	CCharacter::SetMove(move);

	// �ړI�̊p�x�̐ݒ�
	CCharacter::SetRotDest(rotDest);
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