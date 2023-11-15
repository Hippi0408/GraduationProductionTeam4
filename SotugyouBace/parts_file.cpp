//=============================================================================
//
// parts_file.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "parts_file.h"
#include "application.h"
#include "model.h"

const char* CParts_File::m_cFileName[] =
{
	"Data\\text\\Motion\\parts\\motion_Body.txt",
	"Data\\text\\Motion\\parts\\motion_Arms.txt",
	"Data\\text\\Motion\\parts\\motion_Leg.txt",
	"Data\\text\\Motion\\parts\\motion_Body_02.txt",
	"Data\\text\\Motion\\parts\\motion_Arms_02.txt",
	"Data\\text\\Motion\\parts\\motion_Leg_02.txt",

	"Data\\text\\Motion\\motion_mob.txt",

	"Data\\text\\Motion\\motion_boss.txt",
};

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CParts_File::CParts_File()
{

}

//=====================================
// �f�X�g���N�^
//=====================================
CParts_File::~CParts_File()
{
}

//============================================================================
// ����������
//============================================================================
HRESULT CParts_File::Init()
{
	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CParts_File::Uninit()
{
	// �S�Ẵ��f���Z�b�g�̏I��
	ReleaseAllFile();
}

//============================================================================
// �I������
//============================================================================
void CParts_File::ReleaseAllFile()
{
	// �S�Ẵ��f���Z�b�g�̏I��
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++) { m_PartsSet[nCnt] = {}; }
}

//==============================================================================================
// ���f���p�[�c�̐ݒ�(�p�[�c.���f��.���)
//==============================================================================================
void CParts_File::SetModel(const int partsIndex, const int modelIndex, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename)
{
	// �p�[�c�̃��f���Z�b�g�̈�𐶐�����
	m_PartsSet[partsIndex].ModelSet.emplace_back();

	m_PartsSet[partsIndex].ModelSet[modelIndex].nParentIndex = parent;
	m_PartsSet[partsIndex].ModelSet[modelIndex].InitPos = pos;
	m_PartsSet[partsIndex].ModelSet[modelIndex].InitRot = rot;
	m_PartsSet[partsIndex].ModelSet[modelIndex].nModelIndex = CApplication::GetModel()->ReadObject(Xfilename);
}

//==============================================================================================
// ���f���p�[�c�̐ݒ�
//==============================================================================================
void CParts_File::LoadFile(const char* Xfilename, const int partsIndex)
{
	// ���[�V�������̃|�C���^���擾
	CMotion* pMotion = CApplication::GetMotion();

	// �t�@�C����
	FILE* pFile = fopen(Xfilename, "r");

	// �L�����N�^�[�Z�b�g�p
	D3DXVECTOR3 Rot;				// �p�x
	int nIndex = 0;					// �ԍ�
	int nParentIndex = 0;				// �e�̔ԍ�
	int nPartsIndex = 0;			// �p�[�c�̔ԍ�
	D3DXVECTOR3 PartsStartPos;		// �����ʒu
	D3DXVECTOR3 PartsStartRot;		// �����p�x
	char XFileName[0x20][0xff] = {};	// X�t�@�C����

	int nNumMotion = 0;		// ���݂̃��[�V����

	char m_aString[0xff];
	memset(m_aString, 0, sizeof(m_aString));

	// �t�@�C�����J�����ꍇ
	if (pFile != NULL)
	{
		// ���O��ݒ肷��
		m_PartsSet[partsIndex].Name = Xfilename;

		while (strcmp(&m_aString[0], "END_SCRIPT") != 0)
		{
			fscanf(pFile, "%s", &m_aString[0]);

			// SCRIPT����v
			if (strcmp(&m_aString[0], "SCRIPT") == 0)
			{
				while (strcmp(&m_aString[0], "END_SCRIPT") != 0)
				{
					fscanf(pFile, "%s", &m_aString[0]);

					// �t�@�C����
					if (strcmp(&m_aString[0], "MODEL_FILENAME") == 0)
					{
						// ����ǂݔ�΂�
						fscanf(pFile, "%s", &m_aString[0]);
						fscanf(pFile, "%s", &XFileName[nIndex][0]);
						nIndex++;
					}

					if (strcmp(&m_aString[0], "ALL_PARTSET") == 0)
					{
						while (strcmp(&m_aString[0], "END_ALL_PARTSET") != 0)
						{
							fscanf(pFile, "%s", &m_aString[0]);

							if (strcmp(&m_aString[0], "PARTSSET") == 0)
							{
								while (strcmp(&m_aString[0], "END_PARTSSET") != 0)
								{
									fscanf(pFile, "%s", &m_aString[0]);

									// �e�̔ԍ�
									if (strcmp(&m_aString[0], "PARENT") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%d", &nParentIndex);
									}

									// �p�[�c�̈ʒu
									if (strcmp(&m_aString[0], "POS") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%f", &PartsStartPos.x);
										fscanf(pFile, "%f", &PartsStartPos.y);
										fscanf(pFile, "%f", &PartsStartPos.z);
									}

									// �p�[�c�̌���
									if (strcmp(&m_aString[0], "ROT") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%f", &PartsStartRot.x);
										fscanf(pFile, "%f", &PartsStartRot.y);
										fscanf(pFile, "%f", &PartsStartRot.z);
									}
								}
								// ���f���p�[�c�̐ݒ�
								SetModel(partsIndex, nPartsIndex, nParentIndex, PartsStartPos, PartsStartRot, &XFileName[nPartsIndex][0]);
								nPartsIndex++;
							}
						}
					}

					if (strcmp(&m_aString[0], "MOTIONSET") == 0)
					{
						int nKey = 0;			// ���݂̃L�[�̐�

												// ���[�V�������
						CMotion::MotionPattern vMotionPattern = {};	// �L�[�Z�b�g�̏��

						while (strcmp(&m_aString[0], "END_MOTIONSET") != 0)
						{
							fscanf(pFile, "%s", &m_aString[0]);

							// ���[�v���邩
							if (strcmp(&m_aString[0], "LOOP") == 0)
							{
								int nLoop;
								fscanf(pFile, "%s", &m_aString[0]);
								fscanf(pFile, "%d", &nLoop);

								// ���[�v����̑��(true = 1, false = 0)
								vMotionPattern.bLoop = nLoop == 1;
							}

							// �L�[�̐�
							if (strcmp(&m_aString[0], "NUM_KEY") == 0)
							{
								fscanf(pFile, "%s", &m_aString[0]);
								//fscanf(pFile, "%d", &vMotionPattern.nMaxKey);
							}

							if (strcmp(&m_aString[0], "KEYSET") == 0)
							{
								// �L�[�Z�b�g�̃������̈���m��
								vMotionPattern.aKeySet.emplace_back();

								int nParts = 0;			// ���݂̃p�[�c

								while (strcmp(&m_aString[0], "END_KEYSET") != 0)
								{
									fscanf(pFile, "%s", &m_aString[0]);

									// �L�[�t���[��
									if (strcmp(&m_aString[0], "FRAME") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%d", &vMotionPattern.aKeySet[nKey].nFrame);
									}

									if (strcmp(&m_aString[0], "KEY") == 0)
									{
										// �L�[�̃������̈���m��
										vMotionPattern.aKeySet[nKey].aKey.emplace_back();

										while (strcmp(&m_aString[0], "END_KEY") != 0)
										{
											fscanf(pFile, "%s", &m_aString[0]);

											// �ʒu
											if (strcmp(&m_aString[0], "POS") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyPos.x);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyPos.y);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyPos.z);
											}

											// �p�x
											if (strcmp(&m_aString[0], "ROT") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyRot.x);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyRot.y);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyRot.z);
											}

											if (strcmp(&m_aString[0], "END_KEY") == 0)
											{
												// ���̃p�[�c
												nParts++;
											}
										}
									}
								}
								nKey++;
							}
						}
						vMotionPattern.nMaxKey = nKey;

						// ���[�V�����ɐݒ�
						pMotion->SetMotionData(vMotionPattern, Xfilename);

						nNumMotion++;
					}
				}
			}
		}
		//�t�@�C�������
		fclose(pFile);

		// ���[�V�����ɖ��O��ݒ肷��
		pMotion->SetUseFileName(Xfilename);
	}
}

//==============================================================================================
// �S�Ẵ��f���p�[�c�̓ǂݍ���
//==============================================================================================
void CParts_File::LoadAllFile()
{
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{ 
		LoadFile(m_cFileName[nCnt], nCnt);
	}
}