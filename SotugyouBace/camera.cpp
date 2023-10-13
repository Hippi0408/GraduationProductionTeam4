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
	m_posV = D3DXVECTOR3(0.0f, 500.0f, -1000.0f);	// ���_(�I�t�Z�b�g)
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 1000.0f);		// �����_(�I�t�Z�b�g)
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// �p�x
	m_fRotSpeed = 0.03f;							// ��]���x
	m_CPos = { 0.0f,0.0f,0.0f };
	m_posVDest = D3DXVECTOR3(0.0f, 300.0f, -300.0f);
	m_posRDest = D3DXVECTOR3(0.0f, 0.0f, -300.0f);
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
	// �J�����̒Ǐ]
	Perspective();

	// �s����g�����J��������
	Matrix();

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
void CCamera::Matrix()
{
	// �f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//�v�Z�p�̃}�g���b�N�X

	// ���[���h�}�g���b�N�X
	D3DXMatrixIdentity(&m_mtxWorld);

	// �s�����]�ɔ��f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �s��Ɉړ��𔽉f(�v���C���[�̈ʒu)
	D3DXMatrixTranslation(&mtxTrans, m_CPos.x, m_CPos.y, m_CPos.z);
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

		//============================================
		// �J�����̒Ǐ]����
		//============================================
		//�ړI�̒����_�̐ݒ�
		m_posRDest.x = PlayerPos.x + sinf(m_rot.y) * 600.0f;
		m_posRDest.y = (PlayerPos.y + 150.0f) + sinf(m_rot.y);
		m_posRDest.z = PlayerPos.z + cosf(m_rot.y);

		//�ړI�̎��_�̐ݒ�												
		m_posVDest.x = PlayerPos.x - sinf(m_rot.y) * 600.0f;
		m_posVDest.y = (PlayerPos.y + 150.0f) - sinf(m_rot.y);
		m_posVDest.z = PlayerPos.z - cosf(m_rot.y) * 600.0f;

		//���_�̌�������
		m_posR.x += (m_posRDest.x - m_posR.x) * 1.0f;
		m_posR.y += (m_posRDest.y - m_posR.y) * 1.0f;
		m_posR.z += (m_posRDest.z - m_posR.z) * 1.0f;

		m_posV.x += (m_posVDest.x - m_posV.x) * 1.0f;
		m_posV.y += (m_posVDest.y - m_posV.y) * 1.0f;
		m_posV.z += (m_posVDest.z - m_posV.z) * 1.0f;
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