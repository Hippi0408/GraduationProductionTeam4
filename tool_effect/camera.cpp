//��������������������������
//camera.cpp
//��������������������������
#include "application.h"
#include "camera.h"
#include "input.h"
#include "keyboard.h"
#include "mouse.h"
#include "utility.h"
#include "pointer.h"
#include "myimgui.h"

//��������������������������������������������������������������
// �J�����̃R���X�g���N�^
//��������������������������������������������������������������
CCamera::CCamera() :
	m_quakeFrameCount(0),
	m_quakeMagnitude(0.0f),
	m_bTraction(false)
{
	memset(&m_camera, 0, sizeof(CCamera));
}

//��������������������������������������������������������������
// �J�����̃f�X�g���N�^
//��������������������������������������������������������������
CCamera::~CCamera()
{
}

//��������������������������������������������������������������
// �J�����̏�����
//��������������������������������������������������������������
HRESULT CCamera::Init()
{
	//���_�E�����_�E�������ݒ肷��
	m_camera.posV = D3DXVECTOR3(0.0f, 100.0f, 300.0f);	//���_
	m_camera.posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړI�̎��_
	m_camera.posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�����_
	m_camera.posRDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړI�̒����_
	m_camera.vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);		//������x�N�g��
	m_camera.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//����
	m_camera.rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړI�̌���

	float x = m_camera.posR.x - m_camera.posV.x;
	float z = m_camera.posR.z - m_camera.posV.z;
	m_camera.fDistance = sqrtf((x * x) + (z * z));		//���_���璍���_�̋���

	m_moveDirection = D3DXVECTOR3(0.0f,0.0f,0.0f);

	return S_OK;
}

//��������������������������������������������������������������
// �J�����̏I��
//��������������������������������������������������������������
void CCamera::Uninit()
{
}

//��������������������������������������������������������������
// �J�����̍X�V
//��������������������������������������������������������������
void CCamera::Update()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	D3DXMATRIX mtxTrans, mtxRot;

	CInputMouse *pMouse = CApplication::GetInstance()->GetInputMouse();

	const float cameraSpeed = 0.5f;			// �J�����̈ړ����x
	const float rotationSpeed = 0.005f;		// �J�����̉�]���x
	const float inertia = 0.85f;			// ��]���x�̌�����

	// �}�E�X�̈ړ��ʂɉ����ăJ��������]
	static D3DXVECTOR3 move(0.0f,0.0f,0.0f);

	if (pMouse->GetPress(CInputMouse::MOUSE_KEY_LEFT) && !CApplication::GetInstance()->GetMyImgui()->isHover())
	{	// �}�E�X�ŉ�]
		move = pMouse->GetMouseMove();
	}

	if (!CApplication::GetInstance()->GetMyImgui()->isHover())
	{
		m_camera.posV.y -= pMouse->GetMouseWheel() * 0.5f;
		m_camera.posV.z -= pMouse->GetMouseWheel() * 0.5f;
	}

	m_camera.rot.y += move.x * rotationSpeed;
	m_camera.rot.x += move.y * rotationSpeed;

	m_moveDirection.x = -sin(m_camera.rot.y);
	m_moveDirection.z = -cos(m_camera.rot.y);

	// �����ŉ�]���x������
	move.x *= inertia;
	move.y *= inertia;

	//----------------------------------------------------------
	// �J�����̒����_
	//----------------------------------------------------------
	//��
	if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_Q))
	{
		m_camera.rot.y -= rotationSpeed;
	}

	//�E
	if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_E))
	{
		m_camera.rot.y += rotationSpeed;
	}

	//----------------------------------------------------------
	// �J�����̎��_
	//----------------------------------------------------------
	if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_T))
	{
		m_camera.posV.y -= 0.5f * 8;
		m_camera.posV.z -= 1.5f * 8;
	}

	if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_G))
	{
		m_camera.posV.y += 0.5f * 8;
		m_camera.posV.z += 1.5f * 8;
	}

	CPointer *pPointer = CApplication::GetInstance()->GetPointer();
	D3DXVECTOR3 ptPos = pPointer->GetPos();

	//���[���h�}�g���b�N�X��������
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_camera.rot.y, m_camera.rot.x, m_camera.rot.z);
	D3DXVec3TransformNormal(&m_moveDirection, &m_moveDirection, &mtxRot);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, ptPos.x, ptPos.y, ptPos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	D3DXVec3TransformCoord(&m_worldposV, &m_camera.posV, &m_mtxWorld);
	D3DXVec3TransformCoord(&m_worldposR, &m_camera.posR, &m_mtxWorld);

	//----------------------------------------------------------
	// ���K��
	//----------------------------------------------------------
	utility::AngleNormalize(m_camera.rot.y);
}

//��������������������������������������������������������������
// �J�����̐ݒ�
//��������������������������������������������������������������
void CCamera::SetCamera()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_camera.mtxView);

	D3DXVECTOR3 adjustPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	if (m_quakeFrameCount > 0)
	{
		adjustPos = D3DXVECTOR3(rand() % 20 * m_quakeMagnitude, rand() % 20 * m_quakeMagnitude, rand() % 20 * m_quakeMagnitude);
	}

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_camera.mtxView,
		&(m_worldposV + adjustPos),
		&(m_worldposR + adjustPos),
		&m_camera.vecU);

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_camera.mtxView);

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_camera.mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X�̍쐬
	D3DXMatrixPerspectiveFovLH(&m_camera.mtxProjection,
		D3DXToRadian(45.0f),
		(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,
		5.0f,
		10000.0f);

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_camera.mtxProjection);
}