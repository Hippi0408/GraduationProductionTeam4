#include "objectx.h"
#include "application.h"
#include "light.h"
#include "object3d.h"
#include "model.h"

//��������������������������
//�I�u�W�F�N�gX�̃R���X�g���N�^
//��������������������������
CObjectX::CObjectX(int nPriority) :
	m_pTexture(nullptr)
{
	m_scale = D3DXVECTOR3(1.0f,1.0f,1.0f);
	m_col = D3DXCOLOR(1.0f,1.0f,1.0f,1.0f);
}

//��������������������������
//�I�u�W�F�N�gX�̃f�X�g���N�^
//��������������������������
CObjectX::~CObjectX()
{
}

CObjectX * CObjectX::Create(D3DXVECTOR3 pos, std::string str)
{
	CObjectX *pObj = nullptr;
	pObj = new CObjectX;

	//�k���`�F�b�N
	if (pObj != nullptr)
	{
		// �|���S���̏���������
		pObj->LoadModel(str);
		pObj->Init();
		pObj->SetPos(pos);
	}

	return pObj;
}

//��������������������������
//�I�u�W�F�N�gX�̏�����
//��������������������������
HRESULT CObjectX::Init()
{
	int nNumVtx;		//���_��
	DWORD sizeFVF;		//���_�t�H�[�}�b�g�̃T�C�Y
	BYTE *pVtxBuff;		//���_�o�b�t�@�ւ̃|�C���^

	//���_���̎擾
	nNumVtx = m_mesh->GetNumVertices();

	//���_�t�H�[�}�b�g�̃T�C�Y���擾
	sizeFVF = D3DXGetFVFVertexSize(m_mesh->GetFVF());

	//���_�o�b�t�@�̃��b�N
	m_mesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);

	//���_���W�̑��
	D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

	for (int i = 0; i < nNumVtx; i++)
	{
		//���_���W�̑��
		D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

		//X
		if (vtx.x > m_maxModel.x)
		{
			m_maxModel.x = floorf(vtx.x);
		}

		if (vtx.x < m_minModel.x)
		{
			m_minModel.x = floorf(vtx.x);
		}

		//Y
		if (vtx.y > m_maxModel.y)
		{
			m_maxModel.y = floorf(vtx.y);
		}

		if (vtx.y < m_minModel.y)
		{
			m_minModel.y = floorf(vtx.y);
		}

		//Z
		if (vtx.z > m_maxModel.z)
		{
			m_maxModel.z = floorf(vtx.z);
		}

		if (vtx.z < m_minModel.z)
		{
			m_minModel.z = floorf(vtx.z);
		}
		//���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
		pVtxBuff += sizeFVF;
	}

	//���f���T�C�Y
	m_scale.x = m_maxModel.x - m_minModel.x;
	m_scale.y = m_maxModel.y - m_minModel.y;
	m_scale.z = m_maxModel.z - m_minModel.z;

	//���_�o�b�t�@�̃A�����b�N
	m_mesh->UnlockVertexBuffer();

	return S_OK;
}

//��������������������������
//�I�u�W�F�N�gX�̏I��
//��������������������������
void CObjectX::Uninit()
{
	//���_�o�b�t�@�̔j��
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}

	//���b�V���̉��
	if (m_mesh = nullptr)
	{
		m_mesh->Release();
		m_mesh = nullptr;
	}

	//�}�e���A���̔j��
	if (m_buffMat != nullptr)
	{
		m_buffMat->Release();
		m_buffMat = nullptr;
	}

	Destroy();
}

//��������������������������
//�I�u�W�F�N�gX�̍X�V
//��������������������������
void CObjectX::Update()
{
	D3DXVECTOR3 pos = GetPos();
	pos += GetMove();
	SetPos(pos);
}

//��������������������������
//�I�u�W�F�N�gX�̕`��
//��������������������������
void CObjectX::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	D3DXMATRIX mtxRot, mtxTrans, mtxScale;			//�v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;						//���݂̃}�e���A����ۑ�
	D3DXMATERIAL *pMat;							//�}�e���A���f�[�^�ւ̃|�C���^

	//�e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, NULL);

	//���[���h�}�g���b�N�X��������
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_objpos.x, m_objpos.y, m_objpos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// �s��g�k�֐�
	D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	//Z�e�X�g
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//���f���̉e
	//Shadow();

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���݂̃}�e���A����ۑ�
	pDevice->GetMaterial(&matDef);

	//�}�e���A���f�[�^�ւ̃|�C���^���擾
	pMat = (D3DXMATERIAL*)m_buffMat->GetBufferPointer();

	pMat->MatD3D.Diffuse = m_col;

	for (int nCntMat = 0; nCntMat < (int)m_dwNum; nCntMat++)
	{
		//�}�e���A���̐ݒ�
		pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, m_pTexture);

		//���f���p�[�c�̕`��
		m_mesh->DrawSubset(nCntMat);
	}

	//�ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

	//�e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, NULL);
}

void CObjectX::LoadModel(std::string path)
{
	CModel *pModel = CApplication::GetInstance()->GetModel();

	m_mesh = pModel->GetMesh(path);
	m_buffMat = pModel->GetBuffMat(path);
	m_dwNum = pModel->GetModelNum(path);
}

void CObjectX::BindTexture(std::string inPath)
{
	m_pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//�e�N�X�`���̃|�C���^
}