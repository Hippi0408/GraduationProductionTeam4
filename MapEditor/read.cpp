
//=============================================================================
//
// read.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "read.h"
#include <stdio.h>
#include "manager.h"
#include <assert.h>
#include "texture.h"
#include "meshfield.h"
#include "game.h"
#include "ballast_manager.h"
#include "player.h"

//*****************************************************************************
// �R���X�g���N�^
//*****************************************************************************
CRead::CRead()
{
}

//*****************************************************************************
// �f�X�g���N�^
//*****************************************************************************
CRead::~CRead()
{
}

//*****************************************************************************
// �}�b�vTet�̓ǂݍ���
//*****************************************************************************
CMeshfield *CRead::ReadMap(char * sFilePath)
{
	//�}�l�[�W���[�̎擾
	CManager* pManager = GetManager();

	//�Q�[���̎擾
	CGame* pGame = (CGame*)pManager->GetGameObject();

	//���b�V���t�B�[���h�p�̃|�C���^�錾
	CMeshfield *pMeshfield = nullptr;

	//���f���C���f�b�N�X
	int *pModelIndex = nullptr;

	FILE *pFile = NULL;			//�t�@�C���|�C���^�[�錾

	char cBff[LINE_MAX_READING_LENGTH];		//��s���ǂݎ�邽�߂̕ϐ�
	char cBffHead[LINE_MAX_READING_LENGTH];	//���̕�����ǂݎ�邽�߂̕ϐ�

	//���b�V���t�B�[���h
	pMeshfield = new CMeshfield;

	//������
	if (FAILED(pMeshfield->Init()))
	{
		assert(false);
	}

	//���b�V�����̈ꎞ�ۑ�
	MeshfieldStructure MeshData;
	ZeroMemory(&MeshData, sizeof(MeshData));

	//�ǂݍ��݉\���f����
	int nModelNumber = 0;

	//���f���̓ǂݍ��ސ��̕ۑ�
	int nModelNumberMax = 0;

	//�t�@�C�����J��
	pFile = fopen(sFilePath, "r");

	if (pFile == nullptr)
	{//�J���Ȃ��������p
		assert(false);
	}

	//������̓ǂݎ�胋�[�v����
	while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
	{
		//������̕���
		sscanf(cBff, "%s", &cBffHead);

		if (strcmp(&cBffHead[0], "TEXTURE_FILENAME") == 0)
		{//�e�N�X�`���̓ǂݍ���

			//�e�N�X�`���p�X��ǂݎ�邽�߂̕ϐ�
			char cBffPath[LINE_MAX_READING_LENGTH];	
			//������̕���
			sscanf(cBff, "%s = %s", &cBffHead, &cBffPath);
			//�e�N�X�`���̓ǂݍ���
			MeshData.nTextIndex = CTexture::LoadTexture(cBffPath);
		}
		else if (strcmp(&cBffHead[0], "NUM_MODEL") == 0)
		{//���f���̓ǂݍ��ݐ�

			//���f���ԍ��̔z��|�C���^��NULL�`�F�b�N
			if (pModelIndex != nullptr)
			{
				assert(false);
			}

			//������̕���
			sscanf(cBff, "%s = %d", &cBffHead, &nModelNumberMax);
			//���f���ԍ��̔z��ŊǗ�
			pModelIndex = new int[nModelNumberMax];
		}
		else if (strcmp(&cBffHead[0], "MODEL_FILENAME") == 0)
		{//���f���t�@�C���̓ǂݍ���

			//���f���ԍ��̔z��|�C���^��NULL�`�F�b�N
			if (pModelIndex == nullptr)
			{
				assert(false);
			}

			//�o�^�\��̐���葽�������ꍇ
			if (nModelNumber >= nModelNumberMax)
			{
				assert(false);
			}

			//���f���p�X��ǂݎ�邽�߂̕ϐ�
			char cBffPath[LINE_MAX_READING_LENGTH];
			//������̕���
			sscanf(cBff, "%s = %s", &cBffHead, &cBffPath);

			//���f���̃��[�h�ƃC���f�b�N�X�̕ۑ�
			pModelIndex[nModelNumber] = ReadXFile(cBffPath);

			//���f���ԍ��z��̕ۑ����ύX
			nModelNumber++;

		}
		else if (strcmp(&cBffHead[0], "FIELDSET") == 0)
		{//�n�ʂ̐ݒ�

			//������̓ǂݎ�胋�[�v����
			while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
			{
				//������̕���
				sscanf(cBff, "%s", &cBffHead);

				if (strcmp(&cBffHead[0], "POS") == 0)
				{//Pos�̐ݒ�

					//Pos�̈ꎞ�ۑ�
					D3DXVECTOR3 pos;

					//������̕���
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &pos.x, &pos.y, &pos.z);

					//���b�V���t�B�[���h��Pos�̐ݒ�
					MeshData.pos = pos;
				}
				else if (strcmp(&cBffHead[0], "ROT") == 0)
				{//Rot�̐ݒ�

					//Rot�̈ꎞ�ۑ�
					D3DXVECTOR3 rot;

					//������̕���
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &rot.x, &rot.y, &rot.z);

					//���b�V���t�B�[���h��Rot�̐ݒ�
					MeshData.rot = rot;
				}
				else if (strcmp(&cBffHead[0], "COLOR") == 0)
				{//Color�̐ݒ�

					//Color�̈ꎞ�ۑ�
					D3DXCOLOR Color;

					//������̕���
					sscanf(cBff, "%s = %f %f %f %f", &cBffHead, &Color.r, &Color.g, &Color.b, &Color.a);

					//���b�V���t�B�[���h��Color�̐ݒ�
					MeshData.col = Color;
				}
				else if (strcmp(&cBffHead[0], "SIZE") == 0)
				{//SIZE�̐ݒ�

					//SIZE�̈ꎞ�ۑ�
					float fSizeX ,fSizeZ;

					//������̕���
					sscanf(cBff, "%s = %f %f", &cBffHead, &fSizeX, &fSizeZ);

					//���b�V���t�B�[���h��Size�̐ݒ�
					MeshData.fRadiusX = fSizeX / 2.0f;
					MeshData.fRadiusZ = fSizeZ / 2.0f;
				}
				else if (strcmp(&cBffHead[0], "DIVISION") == 0)
				{//DIVISION�̐ݒ�

					//DIVISION�̈ꎞ�ۑ�
					int nMeshX, nMeshZ;

					//������̕���
					sscanf(cBff, "%s = %d %d", &cBffHead, &nMeshX, &nMeshZ);

					//���b�V���t�B�[���h��DIVISION�̐ݒ�
					MeshData.nMeshX = nMeshX;
					MeshData.nMeshZ = nMeshZ;
				}
				else if (strcmp(&cBffHead[0], "END_FIELDSET") == 0)
				{//���b�V�����̏I���̐ݒ�

					MeshData.pos = D3DXVECTOR3(-MeshData.fRadiusX, 0.0f,MeshData.fRadiusZ);

					//���b�V�����̐ݒ�
					pMeshfield->SetMeshfield(MeshData);

					//���I�}�l�[�W���[�̐���
					pGame->CreateBallastManager(pMeshfield);

					break;
				}

				//�ۑ����̕�����̏�����
				ZeroMemory(&cBff, sizeof(cBff));
				ZeroMemory(&cBffHead, sizeof(cBffHead));
			}

		}
		else if (strcmp(&cBffHead[0], "MODELSET") == 0)
		{//���f���̐ݒ�

			//�RDOBJ���̈ꎞ�ۊǏꏊ
			Object_Data Data;
			ZeroMemory(&Data, sizeof(Data));

			//���I�}�l�[�W���[�̎擾
			CBallast_Manager* pBallast_Manager = pGame->GetBallast_Manager();

			//������̓ǂݎ�胋�[�v����
			while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
			{
				

				//������̕���
				sscanf(cBff, "%s", &cBffHead);

				if (strcmp(&cBffHead[0], "TYPE") == 0)
				{//TYPE�̐ݒ�

					int nPattn = 0;

					//������̕���
					sscanf(cBff, "%s = %d", &cBffHead,&nPattn);

					Data.nPattn = pModelIndex[nPattn];

				}
				else if (strcmp(&cBffHead[0], "POS") == 0)
				{//POS�̐ݒ�

					//Pos�ꎞ�ۊǏꏊ
					D3DXVECTOR3 pos;

					//������̕���
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &pos.x, &pos.y, &pos.z);

					//Pos�̕ۑ�
					Data.pos = pos;
				}
				else if (strcmp(&cBffHead[0], "ROT") == 0)
				{//ROT�̐ݒ�

					//Rot�ꎞ�ۊǏꏊ
					D3DXVECTOR3 rot;

					//������̕���
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &rot.x, &rot.y, &rot.z);

					//Rot�̕ۑ�
					Data.rot = rot;
				}
				else if (strcmp(&cBffHead[0], "END_MODELSET") == 0)
				{//���f���̐ݒ�̏I���

					//���̃I�u�W�F�N�g�����b�V���̂ǂ��ɋ��邩�𒲂ׂ�p
					int nPosLocationm = 0;

					////��������Pos���ǂ̃}�X�ɋ��邩��Ԃ�
					//nPosLocationm = pMeshfield->CheckPosLocation(Data.pos);

					////�G���[���m�p
					//if (nPosLocationm < 0)
					//{
					//	assert(false);
					//}

					//���I�}�l�[�W���[��NULL��������
					if (pBallast_Manager == nullptr)
					{
						assert(false);
					}

					//���I�̐ݒu
					pBallast_Manager->SetBallast(nPosLocationm, Data);

					break;
				}

				//�ۑ����̕�����̏�����
				ZeroMemory(&cBff, sizeof(cBff));
				ZeroMemory(&cBffHead, sizeof(cBffHead));
			}
		}
		else if (strcmp(&cBffHead[0], "END_SCRIPT") == 0)
		{//�X�N���v�g�̏I���
			break;
		}

		//�ۑ����̕�����̏�����
		ZeroMemory(&cBff, sizeof(cBff));
		ZeroMemory(&cBffHead, sizeof(cBffHead));
	}

	//���f���C���f�b�N�X
	if (pModelIndex != nullptr)
	{
		delete[] pModelIndex;
		pModelIndex = nullptr;
	}

	//�t�@�C�������
	fclose(pFile);

	//���b�V���|�C���^�錾�̃��^�[��
	return pMeshfield;
}

//*****************************************************************************
// X�t�@�C���̓ǂݍ���
//*****************************************************************************
int CRead::ReadXFile(char * sXFilePath)
{
	C3DObject::ModelPattern Model;

	CManager *pManager = GetManager();

	LPDIRECT3DDEVICE9 pD3DDevice = nullptr;

	pD3DDevice = pManager->GetDeviceManager();

	//X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX(sXFilePath,
		D3DXMESH_SYSTEMMEM,
		pD3DDevice,
		nullptr,
		&Model.pBuffMatModel,
		nullptr,
		&Model.nNumMatModel,
		&Model.pMeshModel);

	Model.bUse = true;

	// �o�b�t�@�̐擪�|�C���^��D3DXMATERIAL�ɃL���X�g���Ď擾
	D3DXMATERIAL *pMat = (D3DXMATERIAL*)Model.pBuffMatModel->GetBufferPointer();

	// �e���b�V���̃}�e���A�������擾����
	for (int i = 0; i < (int)Model.nNumMatModel; i++)
	{
		Model.pTexture[i] = nullptr;

		if (pMat[i].pTextureFilename != nullptr)
		{// �}�e���A���Őݒ肳��Ă���e�N�X�`���ǂݍ���
			D3DXCreateTextureFromFileA(pD3DDevice,
				pMat[i].pTextureFilename,
				&Model.pTexture[i]);
		}
		else
		{
			Model.pTexture[i] = nullptr;
		}
	}

	//���f���̓o�^
	return C3DObject::SetModel(&Model);
}

//*****************************************************************************
// �G�f�B�^�p�e�L�X�g�̓ǂݍ���
//*****************************************************************************
void CRead::ReadEditorText(char * sFilePath)
{
	//�}�l�[�W���[�̎擾
	CManager* pManager = GetManager();

	//�Q�[���̎擾
	CGame* pGame = (CGame*)pManager->GetGameObject();

	//�v���C���[�̎擾
	CPlayer* pPlayer = pGame->GetPlayer();

	//���f���C���f�b�N�X
	int *pModelIndex = nullptr;

	FILE *pFile = NULL;			//�t�@�C���|�C���^�[�錾

	char cBff[LINE_MAX_READING_LENGTH];		//��s���ǂݎ�邽�߂̕ϐ�
	char cBffHead[LINE_MAX_READING_LENGTH];	//���̕�����ǂݎ�邽�߂̕ϐ�

	//�ǂݍ��݉\���f����
	int nModelNumber = 0;

	//���f���̓ǂݍ��ސ��̕ۑ�
	int nModelNumberMax = 0;

	//�t�@�C�����J��
	pFile = fopen(sFilePath, "r");

	if (pFile == nullptr)
	{//�J���Ȃ��������p
		assert(false);
	}

	//������̓ǂݎ�胋�[�v����
	while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
	{
		//������̕���
		sscanf(cBff, "%s", &cBffHead);

		if (strcmp(&cBffHead[0], "NUM_MODEL") == 0)
		{//���f���̓ǂݍ��ݐ�

		 //���f���ԍ��̔z��|�C���^��NULL�`�F�b�N
			if (pModelIndex != nullptr)
			{
				assert(false);
			}

			//������̕���
			sscanf(cBff, "%s = %d", &cBffHead, &nModelNumberMax);
			//���f���ԍ��̔z��ŊǗ�
			pModelIndex = new int[nModelNumberMax];
		}
		else if (strcmp(&cBffHead[0], "MODEL_FILENAME") == 0)
		{//���f���t�@�C���̓ǂݍ���

			//���f���ԍ��̔z��|�C���^��NULL�`�F�b�N
			if (pModelIndex == nullptr)
			{
				assert(false);
			}

			//�o�^�\��̐���葽�������ꍇ
			if (nModelNumber >= nModelNumberMax)
			{
				assert(false);
			}

			//���f���p�X��ǂݎ�邽�߂̕ϐ�
			char cBffPath[LINE_MAX_READING_LENGTH];
			//������̕���
			sscanf(cBff, "%s = %s", &cBffHead, &cBffPath);

			//���f���̃��[�h�ƃC���f�b�N�X�̕ۑ�
			pModelIndex[nModelNumber] = ReadXFile(cBffPath);

			//���f���ԍ��z��̕ۑ����ύX
			nModelNumber++;

		}
		else if (strcmp(&cBffHead[0], "END_SCRIPT") == 0)
		{//�X�N���v�g�̏I���
			break;
		}

		//�ۑ����̕�����̏�����
		ZeroMemory(&cBff, sizeof(cBff));
		ZeroMemory(&cBffHead, sizeof(cBffHead));
	}

	//���f���C���f�b�N�X
	pPlayer->SetModelIndex(pModelIndex);

	//�o�^���f����
	pPlayer->SetModelIndexMax(nModelNumberMax);

	//�t�@�C�������
	fclose(pFile);
}

//*****************************************************************************
// �G�f�B�^�f�[�^�̕ۑ�
//*****************************************************************************
void CRead::SaveEditorData(std::list<C3DObject*> data)
{
	FILE *pFile = NULL;			//�t�@�C���|�C���^�[�錾

	//�t�@�C�����J��
	pFile = fopen("Data/EDITOR_TEXT/EditorData.txt", "w");

	if (pFile == nullptr)
	{//�J���Ȃ��������p
		assert(false);
	}

	//�C�e���[�^�[���[�v
	for (auto itr = data.begin(); itr != data.end(); itr++)
	{
		//�C�e���[�^�[���犢�I�̃|�C���^�̑��
		C3DObject* p3DObject = *itr;

		//���I���̕ۑ�
		if (p3DObject != nullptr)
		{
			//�o�͏��̈ꎞ�ۊ�
			int nMudelNum;
			D3DXVECTOR3 pos, rot;
			
			//���f���ԍ�
			nMudelNum = p3DObject->GetModelNumIndex();

			//�ʒu
			pos = p3DObject->GetPos();

			//����
			rot = p3DObject->GetRot();

			//�e�L�X�g�ɏo�͂̎n�܂�
			fprintf(pFile, "MODELSET\n");

			//���f���ԍ�
			fprintf(pFile, "	TYPE = %d\n",nMudelNum);

			//�ʒu
			fprintf(pFile, "	POS = %.1f %.1f %.1f\n", pos.x, pos.y, pos.z);

			//����
			fprintf(pFile, "	ROT = %.1f %.1f %.1f\n", rot.x, rot.y, rot.z);

			//�����蔻��
			if (p3DObject->GetCollision())
			{
				fprintf(pFile, "	COLLISION_OFF = 1\n");
			}
			else
			{
				fprintf(pFile, "	COLLISION_OFF = 0\n");
			}

			//�I�[�v�j���O���X�g
			if (p3DObject->GetOpeningLost())
			{
				fprintf(pFile, "	OPENING_LOST = 1\n");
			}
			else
			{
				fprintf(pFile, "	OPENING_LOST = 0\n");
			}

			//�C��
			if (p3DObject->GetSwitch())
			{
				fprintf(pFile, "	SWITCH = 1\n");
			}
			else
			{
				fprintf(pFile, "	SWITCH = 0\n");
			}

			//�e�L�X�g�ɏo�͂̏I���
			fprintf(pFile, "END_MODELSET\n\n");
		}
	}

	//�t�@�C�������
	fclose(pFile);
}
