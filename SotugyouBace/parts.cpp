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
// デフォルトコンストラクタ
//=====================================
CParts::CParts(const CObject::PRIORITY priority) : CObject(priority)
{

}

//=====================================
// デストラクタ
//=====================================
CParts::~CParts()
{
}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CParts::Init()
{
	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CParts::Uninit()
{
	// 全てのモデルセットの終了
	while (!m_ModelSet.empty())
	{
		m_ModelSet.back().pModel->Uninit();
		m_ModelSet.pop_back();
	}

	Release();
}

//============================================================================
// 更新処理
//============================================================================
void CParts::Update()
{
	// モーションを切り替える場合
	ChangeMotion();

	// モーション
	Motion();

	// 角度の正規化
	NormalizeRot();
}

//============================================================================
// 描画処理
//============================================================================
void CParts::Draw()
{
	// 描画中の場合
	if (GetDrawFlag())
	{
		LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

		//計算用のマトリックス
		D3DXMATRIX mtxRot, mtxTrans, mtxParent;

		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&m_mtxWorld);

		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

		if (m_pParent != nullptr)
		{
			// 親のマトリックスの取得
			mtxParent = m_pParent->GetWorldMtx();

			// 親モデルのマトリックスとの掛け算
			D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxParent);
		}

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	}
}

//==============================================================================================
// モーションの再生
//==============================================================================================
void CParts::Motion()
{
	// モーションがストップしている場合
	if (!m_bMotionStop)
	{
		// モデルセットが使用されている場合
		if (!m_ModelSet.empty())
		{
			// 現在モーションのモーション情報を取得(モーション番号, 自身の名前)
			CMotion::MotionPattern MotionSet = CApplication::GetMotion()->GetMotionPattern(m_nCurrentMotion, m_name);

			for (int nCnt = 0; nCnt < (int)m_ModelSet.size(); nCnt++)
			{
				if (m_ModelSet[nCnt].pModel != nullptr)
				{
					// 相対値
					float fRelative = (float)m_nCountMotion / (float)MotionSet.aKeySet[m_nCurrentKey].nFrame;

					// 差分
					D3DXVECTOR3 fPosDifference;		// 位置用
					D3DXVECTOR3 fRotDifference;		// 回転用

													// 最後のキーじゃない場合
					if (m_nCurrentKey != MotionSet.nMaxKey - 1)
					{
						// 位置
						fPosDifference = MotionSet.aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyPos
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;					// 終了値 - 開始値

																									// 角度
						fRotDifference = MotionSet.aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyRot
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;					// 終了値 - 開始値
					}
					// 最後のキーの場合
					else if (m_nCurrentKey == MotionSet.nMaxKey - 1)
					{
						// 位置
						fPosDifference = MotionSet.aKeySet[0].aKey[nCnt].KeyPos
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;	// 終了値 - 開始値

																					// 角度
						fRotDifference = MotionSet.aKeySet[0].aKey[nCnt].KeyRot
							- MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;	// 終了値 - 開始値
					}

					// 現在値
					D3DXVECTOR3 Pos = m_ModelSet[nCnt].InitPos + MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos + (fPosDifference * fRelative);	// 位置
					D3DXVECTOR3 Rot = m_ModelSet[nCnt].InitRot + MotionSet.aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot + (fRotDifference * fRelative);	// 回転

					m_ModelSet[nCnt].pModel->SetPos(Pos);	// 位置の設定
					m_ModelSet[nCnt].pModel->SetRot(Rot);	// 回転の設定

					// 親モデルの位置を中心位置に設定
					if (m_ModelSet[nCnt].bParentIndex == true && m_pParent != nullptr)
					{
						// 中心位置の設定
						m_pParent->SetCenterPos(Pos);
					}
				}
			}

			// モーションカウンター
			m_nCountMotion++;

			// 最後のフレームまで進んだ
			if (m_nCountMotion >= MotionSet.aKeySet[m_nCurrentKey].nFrame)
			{
				// フレームを0に戻す
				m_nCountMotion = 0;

				// キーを進める
				m_nCurrentKey++;

				if (m_nCurrentKey >= MotionSet.nMaxKey)
				{
					// ループする
					if (MotionSet.bLoop)
					{
						// キーを戻してループする
						m_nCurrentKey = 0;
					}
					// ループしない
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
// モーション変更
//==============================================================================================
void CParts::ChangeMotion()
{
	// モーションが切り替わった場合
	if (m_nCurrentMotion != m_nMotion)
	{
		// 前回の止まったモーションをfalseにする
		m_bMotionStop = false;

		m_nCurrentMotion = m_nMotion;	// モーションを切り替える
		m_nCurrentKey = 0;				// キーを0にする
		m_nCountMotion = 0;				// モーションカウントを0にする
	}
}

//==============================================================================================
// 回転方向へ振り向かせる処理
//==============================================================================================
void CParts::Rotation()
{
	// 目的の角度にする
	m_rot.y += (m_rotDest.y - m_rot.y) * m_fRotSpeed;
}

//==============================================================================================
// 角度の正規化
//==============================================================================================
void CParts::NormalizeRot()
{
	// 角度の正規化
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y -= D3DX_PI * 2;
	}
	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}

	// 目的の角度の正規化
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
// 親パーツを他パーツの子に設定する処理
//==============================================================================================
void CParts::SetModelParent(CObjectX* parts, const bool parent)
{
	m_ModelSet[0].bParentIndex = parent;
	m_ModelSet[0].pModel->SetParent(parts);
}

//==============================================================================================
// モデルパーツの設定
//==============================================================================================
CObjectX* CParts::SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename)
{
	// モデルが存在しない場合
	if ((int)m_ModelSet.size() <= index)
	{
		// モデルセットのメモリ領域を確保する
		m_ModelSet.emplace_back();
	}

	if (m_ModelSet[index].pModel == nullptr)
	{
		if (parent >= 0)
		{// 親がいる場合
			m_ModelSet[index].pModel = CObjectX::Create(pos, rot, m_ModelSet[parent].pModel, Xfilename);
			m_ModelSet[index].bParentIndex = false;
		}
		else
		{// 親がいない場合
			m_ModelSet[index].pModel = CObjectX::Create(pos, rot, nullptr, Xfilename);
			m_ModelSet[index].bParentIndex = true;

			// パーツである事を設定する
			m_ModelSet[index].pModel->SetParts(true);
		}

		// パーツの初期位置
		m_ModelSet[index].InitPos = m_ModelSet[index].pModel->GetPos();
		m_ModelSet[index].InitRot = m_ModelSet[index].pModel->GetRot();
	}

	return m_ModelSet[index].pModel;
}

//============================================================================
// 自身の全てのモデルの取得処理
//============================================================================
std::vector<CObjectX*> CParts::GetModelAll()
{
	std::vector<CObjectX*> vpModel;

	// モデルセットのモデルの情報を取り出す
	for (auto ModelSet : m_ModelSet)
	{
		vpModel.push_back(ModelSet.pModel);
	}

	// 自身が所持している全てのモデルのポインタを返す
	return vpModel;
}

//============================================================================
// 生成処理
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
// モデルパーツの設定
//==============================================================================================
void CParts::LoadFile(const char* Xfilename)
{
	// モーション情報のポインタを取得
	CMotion* pMotion = CApplication::GetMotion();

	// ファイル名
	FILE* pFile = fopen(Xfilename, "r");

	// キャラクターセット用
	D3DXVECTOR3 Rot;				// 角度
	int nIndex = 0;					// 番号
	int nParentIndex = 0;				// 親の番号
	int nPartsIndex = 0;			// パーツの番号
	D3DXVECTOR3 PartsStartPos;		// 初期位置
	D3DXVECTOR3 PartsStartRot;		// 初期角度
	char XFileName[0x20][0xff] = {};	// Xファイル名

	int nNumMotion = 0;		// 現在のモーション

	char m_aString[0xff];
	memset(m_aString, 0, sizeof(m_aString));

	// ファイルが開いた場合
	if (pFile != NULL)
	{
		// 名前を設定する
		m_name = Xfilename;

		while (strcmp(&m_aString[0], "END_SCRIPT") != 0)
		{
			fscanf(pFile, "%s", &m_aString[0]);

			// SCRIPTが一致
			if (strcmp(&m_aString[0], "SCRIPT") == 0)
			{
				while (strcmp(&m_aString[0], "END_SCRIPT") != 0)
				{
					fscanf(pFile, "%s", &m_aString[0]);

					// ファイル名
					if (strcmp(&m_aString[0], "MODEL_FILENAME") == 0)
					{
						// ＝を読み飛ばす
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

									// 親の番号
									if (strcmp(&m_aString[0], "PARENT") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%d", &nParentIndex);
									}

									// パーツの位置
									if (strcmp(&m_aString[0], "POS") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%f", &PartsStartPos.x);
										fscanf(pFile, "%f", &PartsStartPos.y);
										fscanf(pFile, "%f", &PartsStartPos.z);
									}

									// パーツの向き
									if (strcmp(&m_aString[0], "ROT") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%f", &PartsStartRot.x);
										fscanf(pFile, "%f", &PartsStartRot.y);
										fscanf(pFile, "%f", &PartsStartRot.z);
									}
								}
								// モデルパーツの設定
								SetModel(nPartsIndex, nParentIndex, PartsStartPos, PartsStartRot, &XFileName[nPartsIndex][0]);
								nPartsIndex++;
							}
						}
					}

					if (strcmp(&m_aString[0], "MOTIONSET") == 0)
					{
						int nKey = 0;			// 現在のキーの数

												// モーション情報
						CMotion::MotionPattern vMotionPattern = {};	// キーセットの情報

						while (strcmp(&m_aString[0], "END_MOTIONSET") != 0)
						{
							fscanf(pFile, "%s", &m_aString[0]);

							// ループするか
							if (strcmp(&m_aString[0], "LOOP") == 0)
							{
								int nLoop;
								fscanf(pFile, "%s", &m_aString[0]);
								fscanf(pFile, "%d", &nLoop);

								// ループ判定の代入(true = 1, false = 0)
								vMotionPattern.bLoop = nLoop == 1;
							}

							// キーの数
							if (strcmp(&m_aString[0], "NUM_KEY") == 0)
							{
								fscanf(pFile, "%s", &m_aString[0]);
								//fscanf(pFile, "%d", &vMotionPattern.nMaxKey);
							}

							if (strcmp(&m_aString[0], "KEYSET") == 0)
							{
								// キーセットのメモリ領域を確保
								vMotionPattern.aKeySet.emplace_back();

								int nParts = 0;			// 現在のパーツ

								while (strcmp(&m_aString[0], "END_KEYSET") != 0)
								{
									fscanf(pFile, "%s", &m_aString[0]);

									// キーフレーム
									if (strcmp(&m_aString[0], "FRAME") == 0)
									{
										fscanf(pFile, "%s", &m_aString[0]);
										fscanf(pFile, "%d", &vMotionPattern.aKeySet[nKey].nFrame);
									}

									if (strcmp(&m_aString[0], "KEY") == 0)
									{
										// キーのメモリ領域を確保
										vMotionPattern.aKeySet[nKey].aKey.emplace_back();

										while (strcmp(&m_aString[0], "END_KEY") != 0)
										{
											fscanf(pFile, "%s", &m_aString[0]);

											// 位置
											if (strcmp(&m_aString[0], "POS") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyPos.x);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyPos.y);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyPos.z);
											}

											// 角度
											if (strcmp(&m_aString[0], "ROT") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyRot.x);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyRot.y);
												fscanf(pFile, "%f", &vMotionPattern.aKeySet[nKey].aKey[nParts].KeyRot.z);
											}

											if (strcmp(&m_aString[0], "END_KEY") == 0)
											{
												// 次のパーツ
												nParts++;
											}
										}
									}
								}
								nKey++;
							}
						}
						vMotionPattern.nMaxKey = nKey;

						// モーションに設定
						pMotion->SetMotionData(vMotionPattern, m_name);

						nNumMotion++;
					}
				}
			}
		}
		//ファイルを閉じる
		fclose(pFile);

		// モーションに名前を設定する
		pMotion->SetUseFileName(Xfilename);
	}
}