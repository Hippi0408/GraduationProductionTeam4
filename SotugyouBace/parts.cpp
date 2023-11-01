//=============================================================================
//
// parts.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "parts.h"
#include "application.h"
#include "character.h"

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CParts::CParts(const CObject::PRIORITY priority) : CObject(priority)
{

}

//=====================================
// �f�X�g���N�^
//=====================================
CParts::~CParts()
{
}

//============================================================================
// ����������
//============================================================================
HRESULT CParts::Init()
{
	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CParts::Uninit()
{
	// �S�Ẵ��f���Z�b�g�̏I��
	while (!m_ModelSet.empty())
	{
		m_ModelSet.back().pModel->Uninit();
		m_ModelSet.pop_back();
	}

	Release();
}

//============================================================================
// �X�V����
//============================================================================
void CParts::Update()
{
	// ���[�V������؂�ւ���ꍇ
	ChangeMotion();

	// ���[�V����
	Motion();

	// �p�x�̐��K��
	NormalizeRot();
}

//============================================================================
// �`�揈��
//============================================================================
void CParts::Draw()
{
	// �`�撆�̏ꍇ
	if (GetDrawFlag())
	{
		LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

		//�v�Z�p�̃}�g���b�N�X
		D3DXMATRIX mtxRot, mtxTrans, mtxParent;

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxWorld);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

		if (m_pParent != nullptr)
		{
			// �e�̃}�g���b�N�X�̎擾
			mtxParent = m_pParent->GetWorldMtx();

			// �e���f���̃}�g���b�N�X�Ƃ̊|���Z
			D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxParent);
		}

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	}
}

//==============================================================================================
// ���[�V�����̍Đ�
//==============================================================================================
void CParts::Motion()
{
	// ���[�V�������X�g�b�v���Ă���ꍇ
	if (!m_bMotionStop)
	{
		// ���f���Z�b�g���g�p����Ă���ꍇ
		if (!m_ModelSet.empty())
		{
			// ���݃��[�V�����̃��[�V���������擾(���[�V�����ԍ�, ���g�̖��O)
			CMotion::MotionPattern MotionSet = CApplication::GetMotion()->GetMotionPattern(m_nCurrentMotion, m_name);

			for (int nCnt = 0; nCnt < (int)m_ModelSet.size(); nCnt++)
			{
				if (m_ModelSet[nCnt].pModel != nullptr)
				{
					// ���Βl
					float fRelative = (float)m_nCountMotion / (float)MotionSet.aKeySet[m_nCurrentKey].nFrame;

					// ����
					D3DXVECTOR3 fPosDifference;		// �ʒu�p
					D3DXVECTOR3 fRotDifference;		// ��]�p

													// �Ō�̃L�[����Ȃ��ꍇ
					if (m_nCurrentKey != MotionSet.nMaxKey - 1)
					{
						// �ʒu
						fPosDifference = MotionSet.aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyPos
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;					// �I���l - �J�n�l

																									// �p�x
						fRotDifference = MotionSet.aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyRot
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;					// �I���l - �J�n�l
					}
					// �Ō�̃L�[�̏ꍇ
					else if (m_nCurrentKey == MotionSet.nMaxKey - 1)
					{
						// �ʒu
						fPosDifference = MotionSet.aKeySet[0].aKey[nCnt].KeyPos
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;	// �I���l - �J�n�l

																					// �p�x
						fRotDifference = MotionSet.aKeySet[0].aKey[nCnt].KeyRot
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;	// �I���l - �J�n�l
					}

					// ���ݒl
					D3DXVECTOR3 Pos = m_ModelSet[nCnt].InitPos + MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos + (fPosDifference * fRelative);	// �ʒu
					D3DXVECTOR3 Rot = m_ModelSet[nCnt].InitRot + MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot + (fRotDifference * fRelative);	// ��]

					m_ModelSet[nCnt].pModel->SetPos(Pos);	// �ʒu�̐ݒ�
					m_ModelSet[nCnt].pModel->SetRot(Rot);	// ��]�̐ݒ�

					// �e���f���̈ʒu�𒆐S�ʒu�ɐݒ�
					if (m_ModelSet[nCnt].bParentIndex == true && m_pParent != nullptr)
					{
						// ���S�ʒu�̐ݒ�
						m_pParent->SetCenterPos(Pos);
					}
				}
			}

			// ���[�V�����J�E���^�[
			m_nCountMotion++;

			// �Ō�̃t���[���܂Ői��
			if (m_nCountMotion >= MotionSet.aKeySet[m_nCurrentKey].nFrame)
			{
				// �t���[����0�ɖ߂�
				m_nCountMotion = 0;

				// �L�[��i�߂�
				m_nCurrentKey++;

				if (m_nCurrentKey >= MotionSet.nMaxKey)
				{
					// ���[�v����
					if (MotionSet.bLoop)
					{
						// �L�[��߂��ă��[�v����
						m_nCurrentKey = 0;
					}
					// ���[�v���Ȃ�
					else
					{
						m_bMotionStop = true;
					}
				}
			}
		}
	}
}

//==============================================================================================
// ���[�V�����ύX
//==============================================================================================
void CParts::ChangeMotion()
{
	// ���[�V�������؂�ւ�����ꍇ
	if (m_nCurrentMotion != m_nMotion)
	{
		// �O��̎~�܂������[�V������false�ɂ���
		m_bMotionStop = false;

		m_nCurrentMotion = m_nMotion;	// ���[�V������؂�ւ���
		m_nCurrentKey = 0;				// �L�[��0�ɂ���
		m_nCountMotion = 0;				// ���[�V�����J�E���g��0�ɂ���
	}
}

//==============================================================================================
// ��]�����֐U��������鏈��
//==============================================================================================
void CParts::Rotation()
{
	// �ړI�̊p�x�ɂ���
	m_rot.y += (m_rotDest.y - m_rot.y) * m_fRotSpeed;
}

//==============================================================================================
// �p�x�̐��K��
//==============================================================================================
void CParts::NormalizeRot()
{
	// �p�x�̐��K��
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y -= D3DX_PI * 2;
	}
	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}

	// �ړI�̊p�x�̐��K��
	if (m_rotDest.y - m_rot.y > D3DX_PI)
	{
		m_rotDest.y -= D3DX_PI * 2;
	}
	else if (m_rotDest.y - m_rot.y < -D3DX_PI)
	{
		m_rotDest.y += D3DX_PI * 2;
	}
}

//==============================================================================================
// �e�p�[�c�𑼃p�[�c�̎q�ɐݒ肷�鏈��
//==============================================================================================
void CParts::SetModelParent(CObjectX* parts, const bool parent)
{
	m_ModelSet[0].bParentIndex = parent;
	m_ModelSet[0].pModel->SetParent(parts);
}

//==============================================================================================
// ���f���p�[�c�̐ݒ�
//==============================================================================================
CObjectX* CParts::SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename)
{
	// ���f�������݂��Ȃ��ꍇ
	if ((int)m_ModelSet.size() <= index)
	{
		// ���f���Z�b�g�̃������̈���m�ۂ���
		m_ModelSet.emplace_back();
	}

	if (m_ModelSet[index].pModel == nullptr)
	{
		if (parent >= 0)
		{// �e������ꍇ
			m_ModelSet[index].pModel = CObjectX::Create(pos, rot, m_ModelSet[parent].pModel, Xfilename);
			m_ModelSet[index].bParentIndex = false;
		}
		else
		{// �e�����Ȃ��ꍇ
			m_ModelSet[index].pModel = CObjectX::Create(pos, rot, nullptr, Xfilename);
			m_ModelSet[index].bParentIndex = true;

			// �p�[�c�ł��鎖��ݒ肷��
			m_ModelSet[index].pModel->SetParts(true);
		}

		// �p�[�c�̏����ʒu
		m_ModelSet[index].InitPos = m_ModelSet[index].pModel->GetPos();
		m_ModelSet[index].InitRot = m_ModelSet[index].pModel->GetRot();
	}

	return m_ModelSet[index].pModel;
}

//============================================================================
// ���g�̑S�Ẵ��f���̎擾����
//============================================================================
std::vector<CObjectX*> CParts::GetModelAll()
{
	std::vector<CObjectX*> vpModel;

	// ���f���Z�b�g�̃��f���̏������o��
	for (auto ModelSet : m_ModelSet)
	{
		vpModel.push_back(ModelSet.pModel);
	}

	// ���g���������Ă���S�Ẵ��f���̃|�C���^��Ԃ�
	return vpModel;
}

//============================================================================
// ��������
//============================================================================
CParts* CParts::Create(const D3DXVECTOR3 pos, const char* Xfilename, CCharacter* parent)
{
	CParts* pParts = new CParts;

	if (FAILED(pParts->Init()))
	{
		return nullptr;
	}

	pParts->SetPos(pos);
	pParts->LoadFile(Xfilename);
	pParts->SetParent(parent);

	return pParts;
}

//==============================================================================================
// ���f���p�[�c�̐ݒ�
//==============================================================================================
void CParts::LoadFile(const char* Xfilename)
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
		m_name = Xfilename;

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
								SetModel(nPartsIndex, nParentIndex, PartsStartPos, PartsStartRot, &XFileName[nPartsIndex][0]);
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
						pMotion->SetMotionData(vMotionPattern, m_name);

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