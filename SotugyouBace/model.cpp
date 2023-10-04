//==============================================================================================
//
// ���f���@�@�@madel.cpp
// tutida ryousei
//
//==============================================================================================
#include "model.h"
#include "application.h"
#include "renderer.h"

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CModel::CModel()
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CModel::~CModel()
{
}

//==============================================================================================
// �S�Ẵ��f���̏I������
//==============================================================================================
void CModel::ReleaseAll()
{
	// ���f����S�ďI��������
	while (!m_ModelPattern.empty())
	{
		// ���b�V���̔j��
		if (m_ModelPattern.back().pMesh != nullptr)
		{
			m_ModelPattern.back().pMesh->Release();
		}

		// �}�e���A���̔j��
		if (m_ModelPattern.back().pBuffMat != nullptr)
		{
			m_ModelPattern.back().pBuffMat->Release();
		}

		for (int nCntMat = 0; nCntMat < (int)m_ModelPattern.back().nNumMat; nCntMat++)
		{
			// �e�N�X�`���̔j��
			if (m_ModelPattern.back().pTexture[nCntMat] != nullptr)
			{
				m_ModelPattern.back().pTexture[nCntMat]->Release();
			}
		}	
		// ��Ԍ��̗v�f�����X�g����r������
		m_ModelPattern.pop_back();
	}
}

//==============================================================================================
// �t�@�C���̓ǂݍ���
//==============================================================================================
const int CModel::ReadObject(const char* name)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	int nIndex = 0;

	// �쐬���ꂽ�S�Ẵ��f����ǂݍ���
	for (auto model : m_ModelPattern)
	{
		if (model.fileName == name)
		{
			// �g�p���̃��f���ƈ�v����ꍇ�I��
			return nIndex;
		}
		nIndex++;
	}

	// ���f�����̌��̗v�f��ǉ�
	m_ModelPattern.emplace_back();

	m_ModelPattern.back().fileName = name;

	//X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX(m_ModelPattern.back().fileName,
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&m_ModelPattern.back().pBuffMat,
		NULL,
		&m_ModelPattern.back().nNumMat,
		&m_ModelPattern.back().pMesh);

	// �o�b�t�@�̐擪�|�C���^��D3DXMATERIAL�ɃL���X�g���Ď擾
	D3DXMATERIAL *pMat = (D3DXMATERIAL*)m_ModelPattern.back().pBuffMat->GetBufferPointer();

	// �e���b�V���̃}�e���A�������擾����
	for (int i = 0; i < (int)m_ModelPattern.back().nNumMat; i++)
	{
		// �e�N�X�`���̌��̗v�f��ǉ�
		m_ModelPattern.back().pTexture.emplace_back();

		if (pMat[i].pTextureFilename != nullptr)
		{// �}�e���A���Őݒ肳��Ă���e�N�X�`���ǂݍ���
			D3DXCreateTextureFromFileA(pDevice,
				pMat[i].pTextureFilename,
				&m_ModelPattern.back().pTexture.back());
		}
		else
		{
			m_ModelPattern.back().pTexture.back() = nullptr;
		}

		// �}�e���A���̌��̗v�f��ǉ�
		m_ModelPattern.back().MatColor.emplace_back();

		// �}�e���A���̐F����ۑ�
		m_ModelPattern.back().MatColor.back() = pMat[i].MatD3D.Diffuse;
	}

	return nIndex;
}
