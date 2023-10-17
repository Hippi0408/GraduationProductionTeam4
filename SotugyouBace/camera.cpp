//==============================================
//
// �J�����̏���[camera.cpp]
// Author�Ftutida ryousei
// Author�Ftanimoto kosuke
// Author�Fsaito shian
//
//==============================================
#include "camera.h"
#include "input.h"
#include "application.h"
#include "player_manager.h"
#include "application.h"
#include "mode.h"
#include "fade.h"

//==============================================
//�R���X�g���N�^
//==============================================
CCamera::CCamera()
{

}

//==============================================
//�f�X�g���N�^
//==============================================
CCamera::~CCamera()
{

}

//==============================================
//�J�����̏���������
//==============================================
void CCamera::Init(void)
{
	//���_�E�����_�E�������ݒ肷��
	m_posV = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// ���_(�I�t�Z�b�g)
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// �����_(�I�t�Z�b�g)
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// �p�x
	m_fRotSpeed = 0.03f;							// ��]���x
	m_CPos = { 0.0f,0.0f,0.0f };
	m_posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posRDest = D3DXVECTOR3(600.0f, 150.0f, 0.0f);
}

//==============================================
//�J�����̏I������
//==============================================
void CCamera::Uninit(void)
{

}

//==============================================
//�J�����̍X�V����
//==============================================
void CCamera::Update(void)
{
	if (CApplication::GetPlayerManager()->GetPlayer(0) != nullptr)
	{
		// ���_�ړ�
		Perspective();
	}

#ifdef _DEBUG
	// �J�����̈ړ�
	Move();
#endif
}

//==============================================
// �J�����̃Z�b�g����
//==============================================
void CCamera::SetCamera(void)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// �r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	// �r���[�}�g���b�N�X�̐���
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_worldCameraPosV,
		&m_worldCameraPosR,
		&m_vecU);

	// �r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

	// �v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	// �v���W�F�N�V�����}�g���b�N�X�̐���
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)1280.0f / (float)720.0f,
		10.0f,
		10000.0f);

	// �v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
}

//==============================================
// �s����g�����J��������
//==============================================
void CCamera::Matrix(D3DXVECTOR3 rot,D3DXVECTOR3 pos)
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�̃}�g���b�N�X

	// ���[���h�}�g���b�N�X
	D3DXMatrixIdentity(&m_mtxWorld);

	// �s�����]�ɔ��f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �s��Ɉړ��𔽉f(�v���C���[�̈ʒu)
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	D3DXVec3TransformCoord(&m_worldCameraPosV, &m_posV, &m_mtxWorld);
	D3DXVec3TransformCoord(&m_worldCameraPosR, &m_posR, &m_mtxWorld);
}

#ifdef _DEBUG
//==============================================
// �J�����̈ړ�
//==============================================
void CCamera::Move()
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();

	// �J�����̈ړ�
	if (pInput->Press(DIK_RIGHT))
	{
		//m_rot.y += m_fRotSpeed;
		m_posV.x += 10.0f;
		m_posR.x += 10.0f;
	}
	if (pInput->Press(DIK_LEFT))
	{
		//m_rot.y -= m_fRotSpeed;
		m_posV.x -= 10.0f;
		m_posR.x -= 10.0f;
	}
	if (pInput->Press(DIK_UP))
	{
		//m_rot.x -= m_fRotSpeed;
		m_posV.z += 10.0f;
		m_posR.z += 10.0f;
	}
	if (pInput->Press(DIK_DOWN))
	{
		//m_rot.x += m_fRotSpeed;
		m_posV.z -= 10.0f;
		m_posR.z -= 10.0f;
	}

	if (pInput->Press(DIK_RSHIFT))
	{
		//m_rot.x -= m_fRotSpeed;
		m_posV.y += 10.0f;
		m_posR.y += 10.0f;
	}
	if (pInput->Press(DIK_RCONTROL))
	{
		//m_rot.x += m_fRotSpeed;
		m_posV.y -= 10.0f;
		m_posR.y -= 10.0f;
	}
	if (pInput->Press(DIK_Q))
	{
		m_rot.y -= m_fRotSpeed;
	}
	if (pInput->Press(DIK_E))
	{
		m_rot.y += m_fRotSpeed;
	}

	// �p�x�̐��K��
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y -= D3DX_PI * 2;
	}
	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}
}

//==============================================
// �J�����̎��_
//==============================================
void CCamera::Perspective()
{
	if (CApplication::GetPlayerManager()->GetPlayer(0) != nullptr)
	{	// �v���C���[���g���Ă�������s

		//�擾����
		D3DXVECTOR3 PlayerPos = CApplication::GetPlayerManager()->GetPlayer(0)->GetPos();

		// �s����g�����J��������
		Matrix(m_rot, PlayerPos);
	}
}

//============================================
// �����̐ݒ�
//============================================
void CCamera::SetOffset(D3DXVECTOR3 posV, D3DXVECTOR3 posR)
{
	m_OffsetV = posV;
	m_OffsetR = posR;
}
#endif