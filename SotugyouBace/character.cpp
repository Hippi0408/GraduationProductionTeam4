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
// デフォルトコンストラクタ
//=====================================
CCharacter::CCharacter(const CObject::PRIORITY priority) : CMove_Object(priority)
{
	m_fSpeed = CHARACTER_FIRST_MOVE_SPEED;
	m_fRotSpeed = CHARACTER_ROT_SPEED;
	m_bGround = false;
}

//=====================================
// デストラクタ
//=====================================
CCharacter::~CCharacter()
{
}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CCharacter::Init()
{
	m_nMotion = 0;
	m_nCurrentMotion = 0;			// 現在のモーション番号

	m_nCurrentKey = 0;				// キーを0にする
	m_nCountMotion = 0;				// モーションカウントを0にする

	m_move = { 0.0f, 0.0f, 0.0f };

	CMove_Object::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CCharacter::Uninit()
{
	// 全てのモデルセットの終了
	while (!m_ModelSet.empty())
	{
		m_ModelSet.back().pModel->Uninit();
		m_ModelSet.pop_back();
	}

	CMove_Object::Uninit();

	Release();
}

//============================================================================
// 更新処理
//============================================================================
void CCharacter::Update()
{
	// モーション
	//Motion();

	// 移動量の処理
	Move();

	// 角度の正規化
	NormalizeRot();

	// 床の当たり判定
	FieldCollision();
}

//============================================================================
// 描画処理
//============================================================================
void CCharacter::Draw()
{
	// 描画中の場合
	if (GetDrawFlag())
	{
		LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

		//計算用のマトリックス
		D3DXMATRIX mtxRot, mtxTrans;

		//ワールドマトリックス
		D3DXMatrixIdentity(&m_mtxWorld);

		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);
		D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

		//ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
	}
}

//==============================================================================================
// 移動処理
//==============================================================================================
void CCharacter::Move()
{
	// 移動量を更新(減衰させる)
	m_move -= m_move * CHARACTER_MOVE_INERTIE;

	// 位置更新
	m_pos += m_move * m_fSpeed;
}

//==============================================================================================
// ダメージ処理(与ダメージ)
//==============================================================================================
void CCharacter::Damage(const int value)
{
	// 体力 - 与ダメージ
	m_nLife -= value;

	// 体力チェック
	if (m_nLife <= 0)
	{
		// 体力を0にする
		m_nLife = 0;

		// 自身を破壊する処理
		Destroy();
	}
}

//==============================================================================================
// 回復処理(回復量)
//==============================================================================================
void CCharacter::Recovery(const int value)
{
	// 体力 + 回復量
	m_nLife += value;

	
	// 体力チェック
	if (m_nLife > m_nMaxLife)
	{
		// 体力の最大値を超えないようにする
		m_nLife = m_nMaxLife;
	}
	// 位置更新
	AddPos(m_move * m_fSpeed);
}

//==============================================================================================
// 自身を破壊する処理
//==============================================================================================
void CCharacter::Destroy()
{
	// 自身の終了処理
	Uninit();
}

//============================================================================
// 着地処理
//============================================================================
void CCharacter::Landing(const D3DXVECTOR3 pos)
{
	// 位置を設定する
	m_pos = pos;

	// 着地判定を真にする
	m_bGround = true;
}

//============================================================================
// 床の当たり判定
//============================================================================
void CCharacter::FieldCollision()
{
	// 床の当たり判定から高さを定数として取得
	const float a = CGame::GetMeshField()->MeshCollision(CCharacter::GetPos());

	// 現在の位置を定数として取得
	const D3DXVECTOR3 pos = CCharacter::GetPos();

	// 接地している場合
	if (GetGround() == true)
	{
		// プレイヤーの高さを設定
		CCharacter::SetPos({ pos.x, a, pos.z });
	}
	// 接地していない場合
	else
	{
		// メッシュフィールドより下の位置にいる場合
		if (a >= pos.y)
		{
			// 着地処理を読み込む
			Landing({ pos.x, a, pos.z });
		}
		// メッシュフィールドの上にいる場合は重力をかける
		else
		{
			CCharacter::AddMove({ 0.0f, -CHARACTER_GRAVITY, 0.0f });
		}
	}
}

//==============================================================================================
// モーションの再生
//==============================================================================================
void CCharacter::Motion()
{
	// モーションがストップしている場合
	if (!m_MotionSet[m_nCurrentMotion].bStop)
	{
		// モデルセットが使用されている場合
		if (!m_ModelSet.empty())
		{
			for (int nCnt = 0; nCnt < (int)m_ModelSet.size(); nCnt++)
			{
				if (m_ModelSet[nCnt].pModel != nullptr)
				{
					// 相対値
					float fRelative = (float)m_nCountMotion / (float)m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].nFrame;

					// 差分
					D3DXVECTOR3 fPosDifference;		// 位置用
					D3DXVECTOR3 fRotDifference;		// 回転用

													// 最後のキーじゃない場合
					if (m_nCurrentKey != m_MotionSet[m_nCurrentMotion].nMaxKey - 1)
					{
						// 位置
						fPosDifference = m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyPos
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;					// 終了値 - 開始値

																														// 角度
						fRotDifference = m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey + 1].aKey[nCnt].KeyRot
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;					// 終了値 - 開始値
					}
					// 最後のキーの場合
					else if (m_nCurrentKey == m_MotionSet[m_nCurrentMotion].nMaxKey - 1)
					{
						// 位置
						fPosDifference = m_MotionSet[m_nCurrentMotion].aKeySet[0].aKey[nCnt].KeyPos
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos;	// 終了値 - 開始値

																										// 角度
						fRotDifference = m_MotionSet[m_nCurrentMotion].aKeySet[0].aKey[nCnt].KeyRot
							- m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot;	// 終了値 - 開始値
					}

					// 現在値
					D3DXVECTOR3 Pos = m_ModelSet[nCnt].InitPos + m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyPos + (fPosDifference * fRelative);	// 位置
					D3DXVECTOR3 Rot = m_ModelSet[nCnt].InitRot + m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].aKey[nCnt].KeyRot + (fRotDifference * fRelative);	// 回転

					m_ModelSet[nCnt].pModel->SetPos(Pos);	// 位置の設定
					m_ModelSet[nCnt].pModel->SetRot(Rot);	// 回転の設定
				}
			}

			// モーションカウンター
			m_nCountMotion++;

			// 最後のフレームまで進んだ
			if (m_nCountMotion >= m_MotionSet[m_nCurrentMotion].aKeySet[m_nCurrentKey].nFrame)
			{
				// フレームを0に戻す
				m_nCountMotion = 0;

				// キーを進める
				m_nCurrentKey++;

				if (m_nCurrentKey >= m_MotionSet[m_nCurrentMotion].nMaxKey)
				{
					// ループする
					if (m_MotionSet[m_nCurrentMotion].bLoop)
					{
						// キーを戻してループする
						m_nCurrentKey = 0;
					}
					// ループしない
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
// モーション変更
//==============================================================================================
void CCharacter::ChangeMotion()
{
	// 前回の止まったモーションをfalseにする
	m_MotionSet[m_nCurrentMotion].bStop = false;

	m_nCurrentMotion = m_nMotion;	// モーションを切り替える
	m_nCurrentKey = 0;				// キーを0にする
	m_nCountMotion = 0;				// モーションカウントを0にする
}

//==============================================================================================
// 回転方向へ振り向かせる処理
//==============================================================================================
void CCharacter::Rotation()
{
	// 目的の角度にする
	m_rot.y += (m_rotDest.y - m_rot.y) * m_fRotSpeed;
}

//==============================================================================================
// 角度の正規化
//==============================================================================================
void CCharacter::NormalizeRot()
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
// モデルパーツの設定
//==============================================================================================
CObjectX* CCharacter::SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename)
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
		}
		else
		{// 親がいない場合
			m_ModelSet[index].pModel = CObjectX::Create(pos, rot, nullptr, Xfilename);
		}
		// 親モデルの番号の追加
		m_ModelSet[index].nParentIndex = parent;

		// パーツの初期位置
		m_ModelSet[index].InitPos = m_ModelSet[index].pModel->GetPos();
		m_ModelSet[index].InitRot = m_ModelSet[index].pModel->GetRot();
	}

	return m_ModelSet[index].pModel;
}


//==============================================================================================
// モーション値の読み込み
//==============================================================================================
void CCharacter::SetMotionData(const int maxkey, const int key, const int parts, const int motion, const int frame, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const bool loop)
{
	// キーフレームの設定
	m_MotionSet[motion].aKeySet[key].nFrame = frame;

	// 位置と角度の設定
	m_MotionSet[motion].aKeySet[key].aKey[parts].KeyPos = pos;
	m_MotionSet[motion].aKeySet[key].aKey[parts].KeyRot = rot;

	// キーの最大数
	m_MotionSet[motion].nMaxKey = maxkey;

	// ループするか
	m_MotionSet[motion].bLoop = loop;
}

//============================================================================
// 自身の終了処理
//============================================================================
std::vector<CObjectX*> CCharacter::GetModelAll()
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

//==============================================================================================
// モデルパーツの設定
//==============================================================================================
void CCharacter::LoadFile(const char* Xfilename)
{
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

	// モーション用
	D3DXVECTOR3 PartsPos;	// 位置
	D3DXVECTOR3 PartsRot;	// 回転
	int nFrame = 0;			// キーのフレーム数
	int nMaxKey = 0;		// キーの数
	int nMaxParts = 0;		// パーツの数
	bool bLoop = false;		// ループするか
	int nKey = 0;			// 現在のキーの数
	int nParts = 0;			// 現在のパーツ
	int nNumMotion = 0;		// 現在のモーション

	char m_aString[0xff];
	memset(m_aString, 0, sizeof(m_aString));

	// ファイルが開いた場合
	if (pFile != NULL)
	{
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
						m_MotionSet.emplace_back();
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
								bLoop = nLoop == 1;
							}

							// キーの数
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

									// キーフレーム
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

											// 位置
											if (strcmp(&m_aString[0], "POS") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &PartsPos.x);
												fscanf(pFile, "%f", &PartsPos.y);
												fscanf(pFile, "%f", &PartsPos.z);
											}

											// 角度
											if (strcmp(&m_aString[0], "ROT") == 0)
											{
												fscanf(pFile, "%s", &m_aString[0]);
												fscanf(pFile, "%f", &PartsRot.x);
												fscanf(pFile, "%f", &PartsRot.y);
												fscanf(pFile, "%f", &PartsRot.z);

											}

											if (strcmp(&m_aString[0], "END_KEY") == 0)
											{
												// モーション値の設定
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
						nKey = 0;	// キーの初期化

						nNumMotion++;
					}
				}
			}
		}

		//ファイルを閉じる
		fclose(pFile);
	}
}