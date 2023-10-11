//=============================================================================
//
// charactery.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "character.h"
#include "application.h"
#include "game.h"
#include "meshfield.h"

const float CCharacter::CHARACTER_FIRST_MOVE_SPEED = 10.0f;
const float CCharacter::CHARACTER_ROT_SPEED = 0.1f;
const float CCharacter::CHARACTER_MOVE_INERTIE = 0.2f;
const float CCharacter::CHARACTER_GRAVITY = 0.25f;

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CCharacter::CCharacter(const CObject::PRIORITY priority) : CMove_Object(priority)
{
	m_fSpeed = CHARACTER_FIRST_MOVE_SPEED;
	m_fRotSpeed = CHARACTER_ROT_SPEED;
	m_bGround = false;
}

//=====================================
// �f�X�g���N�^
//=====================================
CCharacter::~CCharacter()
{
}

//============================================================================
// ����������
//============================================================================
HRESULT CCharacter::Init()
{
	m_nMotion = 0;
	m_nCurrentMotion = 0;			// ���݂̃��[�V�����ԍ�

	m_nCurrentKey = 0;				// �L�[��0�ɂ���
	m_nCountMotion = 0;				// ���[�V�����J�E���g��0�ɂ���

	m_move = { 0.0f, 0.0f, 0.0f };

	CMove_Object::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CCharacter::Uninit()
{
	// �S�Ẵ��f���Z�b�g�̏I��
	while (!m_ModelSet.empty())
	{
		m_ModelSet.back().pModel->Uninit();
		m_ModelSet.pop_back();
	}

	CMove_Object::Uninit();

	Release();
}

//============================================================================
// �X�V����
//============================================================================
void CCharacter::Update()
{
	// ���[�V����
	//Motion();

	// �ړ��ʂ̏���
	Move();

	// �p�x�̐��K��
	NormalizeRot();

	// ���̓����蔻��
	FieldCollision();
}

//============================================================================
// �`�揈��
//============================================================================
void CCharacter::Draw()
{
	// �`�撆�̏ꍇ
	if (GetDrawFlag())
	{
		LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

		//�v�Z�p�̃}�g���b�N�X
		D3DXMATRIX mtxRot, mtxTrans;

		//���[���h�}�g���b�N�X
		D3DXMatrixIdentity(&m_mtxWorld);

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

		//���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	}
}

//==============================================================================================
// �ړ�����
//==============================================================================================
void CCharacter::Move()
{
	// �ړ��ʂ��X�V(����������)
	m_move -= m_move * CHARACTER_MOVE_INERTIE;

	// �ʒu�X�V
	m_pos += m_move * m_fSpeed;
}

//==============================================================================================
// �_���[�W����(�^�_���[�W)
//==============================================================================================
void CCharacter::Damage(const int value)
{
	// �̗� - �^�_���[�W
	m_nLife -= value;

	// �̗̓`�F�b�N
	if (m_nLife <= 0)
	{
		// �̗͂�0�ɂ���
		m_nLife = 0;

		// ���g��j�󂷂鏈��
		Destroy();
	}
}

//==============================================================================================
// �񕜏���(�񕜗�)
//==============================================================================================
void CCharacter::Recovery(const int value)
{
	// �̗� + �񕜗�
	m_nLife += value;

	
	// �̗̓`�F�b�N
	if (m_nLife > m_nMaxLife)
	{
		// �̗͂̍ő�l�𒴂��Ȃ��悤�ɂ���
		m_nLife = m_nMaxLife;
	}
	// �ʒu�X�V
	AddPos(m_move * m_fSpeed);
}

//==============================================================================================
// ���g��j�󂷂鏈��
//==============================================================================================
void CCharacter::Destroy()
{
	// ���g�̏I������
	Uninit();
}

//============================================================================
// ���n����
//============================================================================
void CCharacter::Landing(const D3DXVECTOR3 pos)
{
	// �ʒu��ݒ肷��
	m_pos = pos;

	// ���n�����^�ɂ���
	m_bGround = true;
}

//============================================================================
// ���̓����蔻��
//============================================================================
void CCharacter::FieldCollision()
{
	// ���̓����蔻�肩�獂����萔�Ƃ��Ď擾
	const float a = CGame::GetMeshField()->MeshCollision(CCharacter::GetPos());

	// ���݂̈ʒu��萔�Ƃ��Ď擾
	const D3DXVECTOR3 pos = CCharacter::GetPos();

	// �ڒn���Ă���ꍇ
	if (GetGround() == true)
	{
		// �v���C���[�̍�����ݒ�
		CCharacter::SetPos({ pos.x, a, pos.z });
	}
	// �ڒn���Ă��Ȃ��ꍇ
	else
	{
		// ���b�V���t�B�[���h��艺�̈ʒu�ɂ���ꍇ
		if (a >= pos.y)
		{
			// ���n������ǂݍ���
			Landing({ pos.x, a, pos.z });
		}
		// ���b�V���t�B�[���h�̏�ɂ���ꍇ�͏d�͂�������
		else
		{
			CCharacter::AddMove({ 0.0f, -CHARACTER_GRAVITY, 0.0f });
		}
	}
}

//==============================================================================================
// ���[�V�����̍Đ�
//==============================================================================================
void CCharacter::Motion()
{
	// ���[�V�������X�g�b�v���Ă���ꍇ
	if (!m_MotionSet[m_nCurrentMotion].bStop)
	{
		// ���f���Z�b�g���g�p����Ă���ꍇ
		if (!m_ModelSet.empty())
		{
			for (int nCnt = 0; nCnt < (int)m_ModelSet.size(); nCnt++)
			{
				if (m_ModelSet[nCnt].pModel != nullptr)
				{
					// ���Βl
					float fRelative = (float)m_nCountMotion / (float)m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].nFrame;

					// ����
					D3DXVECTOR3 fPosDifference;		// �ʒu�p
					D3DXVECTOR3 fRotDifference;		// ��]�p

													// �Ō�̃L�[����Ȃ��ꍇ
					if (m_nCurrentKey != m_MotionSet[m_nCurrentMotion].nMaxKey - 1)
					{
						// �ʒu
						fPosDifference = m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyPos
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;					// �I���l - �J�n�l

																														// �p�x
						fRotDifference = m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyRot
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;					// �I���l - �J�n�l
					}
					// �Ō�̃L�[�̏ꍇ
					else if (m_nCurrentKey == m_MotionSet[m_nCurrentMotion].nMaxKey - 1)
					{
						// �ʒu
						fPosDifference = m_MotionSet[m_nCurrentMotion].aKeySet[0].aKey[nCnt].KeyPos
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;	// �I���l - �J�n�l

																										// �p�x
						fRotDifference = m_MotionSet[m_nCurrentMotion].aKeySet[0].aKey[nCnt].KeyRot
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;	// �I���l - �J�n�l
					}

					// ���ݒl
					D3DXVECTOR3 Pos = m_ModelSet[nCnt].InitPos + m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos + (fPosDifference * fRelative);	// �ʒu
					D3DXVECTOR3 Rot = m_ModelSet[nCnt].InitRot + m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot + (fRotDifference * fRelative);	// ��]

					m_ModelSet[nCnt].pModel->SetPos(Pos);	// �ʒu�̐ݒ�
					m_ModelSet[nCnt].pModel->SetRot(Rot);	// ��]�̐ݒ�
				}
			}

			// ���[�V�����J�E���^�[
			m_nCountMotion++;

			// �Ō�̃t���[���܂Ői��
			if (m_nCountMotion >= m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].nFrame)
			{
				// �t���[����0�ɖ߂�
				m_nCountMotion = 0;

				// �L�[��i�߂�
				m_nCurrentKey++;

				if (m_nCurrentKey >= m_MotionSet[m_nCurrentMotion].nMaxKey)
				{
					// ���[�v����
					if (m_MotionSet[m_nCurrentMotion].bLoop)
					{
						// �L�[��߂��ă��[�v����
						m_nCurrentKey = 0;
					}
					// ���[�v���Ȃ�
					else
					{
						m_MotionSet[m_nCurrentMotion].bStop = true;
					}
				}
			}
		}
	}
}

//==============================================================================================
// ���[�V�����ύX
//==============================================================================================
void CCharacter::ChangeMotion()
{
	// �O��̎~�܂������[�V������false�ɂ���
	m_MotionSet[m_nCurrentMotion].bStop = false;

	m_nCurrentMotion = m_nMotion;	// ���[�V������؂�ւ���
	m_nCurrentKey = 0;				// �L�[��0�ɂ���
	m_nCountMotion = 0;				// ���[�V�����J�E���g��0�ɂ���
}

//==============================================================================================
// ��]�����֐U��������鏈��
//==============================================================================================
void CCharacter::Rotation()
{
	// �ړI�̊p�x�ɂ���
	m_rot.y += (m_rotDest.y - m_rot.y) * m_fRotSpeed;
}

//==============================================================================================
// �p�x�̐��K��
//==============================================================================================
void CCharacter::NormalizeRot()
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
// ���f���p�[�c�̐ݒ�
//==============================================================================================
CObjectX* CCharacter::SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename)
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
		}
		else
		{// �e�����Ȃ��ꍇ
			m_ModelSet[index].pModel = CObjectX::Create(pos, rot, nullptr, Xfilename);
		}
		// �e���f���̔ԍ��̒ǉ�
		m_ModelSet[index].nParentIndex = parent;

		// �p�[�c�̏����ʒu
		m_ModelSet[index].InitPos = m_ModelSet[index].pModel->GetPos();
		m_ModelSet[index].InitRot = m_ModelSet[index].pModel->GetRot();
	}

	return m_ModelSet[index].pModel;
}


//==============================================================================================
// ���[�V�����l�̓ǂݍ���
//==============================================================================================
void CCharacter::SetMotionData(const int maxkey, const int key, const int parts, const int motion, const int frame, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const bool loop)
{
	// �L�[�t���[���̐ݒ�
	m_MotionSet[motion].aKeySet[key].nFrame = frame;

	// �ʒu�Ɗp�x�̐ݒ�
	m_MotionSet[motion].aKeySet[key].aKey[parts].KeyPos = pos;
	m_MotionSet[motion].aKeySet[key].aKey[parts].KeyRot = rot;

	// �L�[�̍ő吔
	m_MotionSet[motion].nMaxKey = maxkey;

	// ���[�v���邩
	m_MotionSet[motion].bLoop = loop;
}

//============================================================================
// ���g�̏I������
//============================================================================
std::vector<CObjectX*> CCharacter::GetModelAll()
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

//==============================================================================================
// ���f���p�[�c�̐ݒ�
//==============================================================================================
void CCharacter::LoadFile(const char* Xfilename)
{
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

	// ���[�V�����p
	D3DXVECTOR3 PartsPos;	// �ʒu
	D3DXVECTOR3 PartsRot;	// ��]
	int nFrame = 0;			// �L�[�̃t���[����
	int nMaxKey = 0;		// �L�[�̐�
	int nMaxParts = 0;		// �p�[�c�̐�
	bool bLoop = false;		// ���[�v���邩
	int nKey = 0;			// ���݂̃L�[�̐�
	int nParts = 0;			// ���݂̃p�[�c
	int nNumMotion = 0;		// ���݂̃��[�V����

	char m_aString[0xff];
	memset(m_aString, 0, sizeof(m_aString));

	// �t�@�C�����J�����ꍇ
	if (pFile != NULL)
	{
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
						nMaxParts++;
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
						m_MotionSet.emplace_back();
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
								bLoop = nLoop == 1;
							}

							// �L�[�̐�
							if (strcmp(&m_aString[0], "NUM_KEY") == 0)
							{
								fscanf(pFile, "%s", &m_aString[0]);
								fscanf(pFile, "%d", &nMaxKey);
							}

							if (strcmp(&m_aString[0], "KEYSET") == 0)
							{
								m_MotionSet[nNumMotion].aKeySet.emplace_back();
								while (strcmp(&m_aString[0], "END_KEYSET") != 0)
								{
									fscanf(pFile, "%s", &m_aString[0]);

									// �L�[�t���[��
									if (strcmp(&m_aString[0], "FRAME") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%d", &nFrame);
									}

									if (strcmp(&m_aString[0], "KEY") == 0)
									{
										m_MotionSet[nNumMotion].aKeySet[nKey].aKey.emplace_back();
										while (strcmp(&m_aString[0], "END_KEY") != 0)
										{
											fscanf(pFile, "%s", &m_aString[0]);

											// �ʒu
											if (strcmp(&m_aString[0], "POS") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &PartsPos.x);
												fscanf(pFile, "%f", &PartsPos.y);
												fscanf(pFile, "%f", &PartsPos.z);
											}

											// �p�x
											if (strcmp(&m_aString[0], "ROT") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &PartsRot.x);
												fscanf(pFile, "%f", &PartsRot.y);
												fscanf(pFile, "%f", &PartsRot.z);

											}

											if (strcmp(&m_aString[0], "END_KEY") == 0)
											{
												// ���[�V�����l�̐ݒ�
												SetMotionData(nMaxKey, nKey, nParts, nNumMotion, nFrame, PartsPos, PartsRot, bLoop);

												nParts++;

												if (nParts == nMaxParts)
												{
													nParts = 0;
												}
											}
										}
									}
								}
								nKey++;
							}
						}
						nKey = 0;	// �L�[�̏�����

						nNumMotion++;
					}
				}
			}
		}

		//�t�@�C�������
		fclose(pFile);
	}
}