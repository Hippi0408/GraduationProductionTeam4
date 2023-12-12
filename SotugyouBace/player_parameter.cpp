//=============================================================================
//
// player_parameter.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "player_parameter.h"
#include "application.h"

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CPlayer_Parameter::CPlayer_Parameter()
{

}

//=====================================
// �f�X�g���N�^
//=====================================
CPlayer_Parameter::~CPlayer_Parameter()
{
}

//============================================================================
// ����������
//============================================================================
HRESULT CPlayer_Parameter::Init()
{
	// �p�����[�^�[�t�@�C���̓ǂݍ���
	LoadFile();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CPlayer_Parameter::Uninit()
{

}

//==============================================================================================
// �p�����[�^�[�̐ݒ�
//==============================================================================================
void CPlayer_Parameter::LoadFile()
{
	// �t�@�C����
	FILE* pFile = fopen("Data\\text\\Parameter\\parameter_Player.txt", "r");

	int nJob_Index = 0;					// �W���u�̔ԍ�
	int nParameter_Index = 0;			// �p�����[�^�̔ԍ�
	char aString[0xff];
	memset(aString, 0, sizeof(aString));

	// �t�@�C�����J�����ꍇ
	if (pFile != NULL)
	{
		while (strcmp(&aString[0], "END_SCRIPT") != 0)
		{
			fscanf(pFile, "%s", &aString[0]);

			// SCRIPT����v
			if (strcmp(&aString[0], "SCRIPT") == 0)
			{
				while (strcmp(&aString[0], "END_SCRIPT") != 0)
				{
					fscanf(pFile, "%s", &aString[0]);

					// �S�Ẵp�����[�^�Z�b�g
					if (strcmp(&aString[0], "ALL_PARAM_SET") == 0)
					{
						while (strcmp(&aString[0], "END_ALL_PARAM_SET") != 0)
						{
							fscanf(pFile, "%s", &aString[0]);

							// �W���u���̃p�����[�^�[�Z�b�g
							if (strcmp(&aString[0], "JOB_PARAM_SET") == 0)
							{
								while (strcmp(&aString[0], "END_JOB_PARAM_SET") != 0)
								{
									fscanf(pFile, "%s", &aString[0]);

									// �p�����[�^�[�Z�b�g
									if (strcmp(&aString[0], "PARAM_SET") == 0)
									{
										while (strcmp(&aString[0], "END_PARAM_SET") != 0)
										{
											fscanf(pFile, "%s", &aString[0]);

											// �̗�
											if (strcmp(&aString[0], "LIFE") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nLife);
											}

											// �X�^�~�i
											if (strcmp(&aString[0], "STAMINA") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nStamina);
											}

											// �X�^�����e�l
											if (strcmp(&aString[0], "STAN_TOLERANCE") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nStan_Tolerance);
											}

											// �X�^�~�i
											if (strcmp(&aString[0], "GRAVITY") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nGravity);
											}
										}
										nParameter_Index++;	// �p�����[�^�[�̃J�E���g
									}
								}
								nParameter_Index = 0;		// �p�����[�^�[���̏�����
								nJob_Index++;				// �W���u�̃J�E���g
							}
						}
					}
				}
			}
		}
		//�t�@�C�������
		fclose(pFile);
	}
}