#include <stdlib.h>
#include "application.h"
#include "input.h"
#include "keyboard.h"
#include "camera.h"
#include "utility.h"
#include "pointer.h"
#include "model.h"
#include "texture.h"

#include "particle_manager.h"
#include "particle_emitter.h"
#include "myimgui.h"
#include "particle.h"

//��������������������������������������������������������������
// �|�C���^�[�̃R���X�g���N�^
//��������������������������������������������������������������
CPointer::CPointer() : m_fSpeed(1.0f)
{
	SetObjType(OBJTYPE_PLAYER);
	SetObjState(CObject::OBJSTATE_3D);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_bVisible = true;
}

//��������������������������������������������������������������
// �|�C���^�[�̃f�X�g���N�^
//��������������������������������������������������������������
CPointer::~CPointer()
{
}

//��������������������������������������������������������������
// �|�C���^�[�̐���
//��������������������������������������������������������������
CPointer * CPointer::Create(D3DXVECTOR3 pos)
{
	CPointer *pObj = nullptr;
	pObj = new CPointer;

	//�k���`�F�b�N
	if (pObj != nullptr)
	{
		// �|���S���̏���������
		pObj->SetPos(pos);
		pObj->Init();
	}

	return pObj;
}

//��������������������������������������������������������������
// �|�C���^�[�̏�����
//��������������������������������������������������������������
HRESULT CPointer::Init()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	LoadModel("SPHERE");

	m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	return S_OK;
}

//��������������������������������������������������������������
// �|�C���^�[�̏I��
//��������������������������������������������������������������
void CPointer::Uninit()
{
	Destroy();
}

//��������������������������������������������������������������
// �|�C���^�[�̍X�V
//��������������������������������������������������������������
void CPointer::Update()
{
	m_posOld = m_objpos;
	m_objpos += m_move;

	//----------------------------------------------------------
	// �v���C���[�s������
	Movement();

	static int time = 0;

	std::string tag = CApplication::GetInstance()->GetMyImgui()->GetNowTag();
	int popTime = CApplication::GetInstance()->GetMyImgui()->GetEmissionInterval();

	time++;
	// �p�[�e�B�N��
	if ((time % popTime) == 0)
	{
		m_pParticleEmitter = CParticleEmitter::Create(tag);
		m_pParticleEmitter->SetPos(m_objpos);
	}

	//----------------------------------------------------------
	// ���K��
	//----------------------------------------------------------
	// �ړI�̌����̐��K��
	if (m_rotDest.x - m_rot.x > D3DX_PI)
	{
		m_rotDest.x -= D3DX_PI * 2;
	}

	else if (m_rotDest.x - m_rot.x < -D3DX_PI)
	{
		m_rotDest.x += D3DX_PI * 2;
	}

	if (m_rotDest.y - m_rot.y > D3DX_PI)
	{
		m_rotDest.y -= D3DX_PI * 2;
	}

	else if (m_rotDest.y - m_rot.y < -D3DX_PI)
	{
		m_rotDest.y += D3DX_PI * 2;
	}

	//���f���̉�]�̊���
	m_rot.x += (m_rotDest.x - m_rot.x) * 0.1f;
	m_rot.y += (m_rotDest.y - m_rot.y) * 0.1f;

	// �����̐��K��
	utility::AngleNormalize(m_rot.y);
}

//��������������������������������������������������������������
// �|�C���^�[�̕`��
//��������������������������������������������������������������
void CPointer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	D3DXMATRIX mtxTrans, mtxScale;		// �v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;						// ���݂̃}�e���A����ۑ�
	D3DXMATERIAL *pMat;							// �}�e���A���f�[�^�ւ̃|�C���^

	//�e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, NULL);

	//���[���h�}�g���b�N�X��������
	D3DXMatrixIdentity(&m_mtxWorld);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_objpos.x, m_objpos.y, m_objpos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// �s��g�k�֐�
	D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	//Z�e�X�g
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	for (auto &p : m_modelData)
	{
		if (!m_bVisible)
		{	// ������
			break;
		}

		//���݂̃}�e���A����ۑ�
		pDevice->GetMaterial(&matDef);

		//�}�e���A���f�[�^�ւ̃|�C���^���擾
		pMat = (D3DXMATERIAL*)p.buffMat->GetBufferPointer();
		pMat->MatD3D.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		for (int j = 0; j < (int)p.dwNum; j++)
		{
			//�}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat->MatD3D);

			//���f���p�[�c�̕`��
			p.mesh->DrawSubset(j);
		}
	}

	//�ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

	//�e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, NULL);
}

//��������������������������������������������������������������
// �|�C���^�[�̓��͏��ɂ��s��
//��������������������������������������������������������������
void CPointer::Movement()
{
	CCamera *pCamera = CApplication::GetInstance()->GetCamera();
	CCamera::CAMERA *camera = pCamera->GetCamera();

	D3DXVECTOR3 vec(0.0f, 0.0f, 0.0f);

	// ��
	if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_W))
	{
		vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed));
		m_rotDest.y = camera->rot.y + D3DX_PI * 0.0f;				//�ړI�̊p�x

																	// �E��
		if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_D))
			vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y + D3DX_PI * 0.25f;

		// ����
		else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_A))
			vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y - D3DX_PI * 0.25f;
	}

	// ��
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_S))
	{
		vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed));
		m_rotDest.y = camera->rot.y - D3DX_PI * 1.0f;

		// �E��
		if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_D))
			vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y + D3DX_PI * 0.75f;

		// ����
		else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_A))
			vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y - D3DX_PI * 0.75f;
	}

	// �E
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_D))
	{
		vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed));
		m_rotDest.y = camera->rot.y + D3DX_PI * 0.5f;
	}

	// ��
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_A))
	{
		vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed));
		m_rotDest.y = camera->rot.y - D3DX_PI * 0.5f;
	}

	// ��
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_R))
	{
		m_objpos.y += 1.5f;
	}

	// ��
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_F))
	{
		m_objpos.y -= 1.5f;
	}

	m_objpos.x += vec.x;
	m_objpos.z += vec.z;
	m_vec = vec;
}

//��������������������������������������������������������������
// �|�C���^�[�̃��f���f�[�^���擾
//��������������������������������������������������������������
void CPointer::LoadModel(std::string path)
{
	// ���f���f�[�^�̃|�C���^���擾
	CModel *pModel = CApplication::GetInstance()->GetModel();

	SModelData data = {};

	data.mesh = pModel->GetMesh(path);
	data.buffMat = pModel->GetBuffMat(path);
	data.dwNum = pModel->GetModelNum(path);
	data.maxModel = pModel->GetMaxModel(path);
	data.minModel = pModel->GetMinModel(path);

	m_modelData.push_back(data);
}

//��������������������������������������������������������������
// �|�C���^�[�̃e�N�X�`�����o�C���h
//��������������������������������������������������������������
void CPointer::BindTexture(std::string inPath)
{
	m_pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//�e�N�X�`���̃|�C���^
}