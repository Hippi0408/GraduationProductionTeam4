
//=============================================================================
//
// read.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// インクルード
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
// コンストラクタ
//*****************************************************************************
CRead::CRead()
{
}

//*****************************************************************************
// デストラクタ
//*****************************************************************************
CRead::~CRead()
{
}

//*****************************************************************************
// マップTetの読み込み
//*****************************************************************************
CMeshfield *CRead::ReadMap(char * sFilePath)
{
	//マネージャーの取得
	CManager* pManager = GetManager();

	//ゲームの取得
	CGame* pGame = (CGame*)pManager->GetGameObject();

	//メッシュフィールド用のポインタ宣言
	CMeshfield *pMeshfield = nullptr;

	//モデルインデックス
	int *pModelIndex = nullptr;

	FILE *pFile = NULL;			//ファイルポインター宣言

	char cBff[LINE_MAX_READING_LENGTH];		//一行分読み取るための変数
	char cBffHead[LINE_MAX_READING_LENGTH];	//頭の文字を読み取るための変数

	//メッシュフィールド
	pMeshfield = new CMeshfield;

	//初期化
	if (FAILED(pMeshfield->Init()))
	{
		assert(false);
	}

	//メッシュ情報の一時保存
	MeshfieldStructure MeshData;
	ZeroMemory(&MeshData, sizeof(MeshData));

	//読み込み可能モデル数
	int nModelNumber = 0;

	//モデルの読み込む数の保存
	int nModelNumberMax = 0;

	//ファイルを開く
	pFile = fopen(sFilePath, "r");

	if (pFile == nullptr)
	{//開けなかった時用
		assert(false);
	}

	//文字列の読み取りループ処理
	while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
	{
		//文字列の分析
		sscanf(cBff, "%s", &cBffHead);

		if (strcmp(&cBffHead[0], "TEXTURE_FILENAME") == 0)
		{//テクスチャの読み込み

			//テクスチャパスを読み取るための変数
			char cBffPath[LINE_MAX_READING_LENGTH];	
			//文字列の分析
			sscanf(cBff, "%s = %s", &cBffHead, &cBffPath);
			//テクスチャの読み込み
			MeshData.nTextIndex = CTexture::LoadTexture(cBffPath);
		}
		else if (strcmp(&cBffHead[0], "NUM_MODEL") == 0)
		{//モデルの読み込み数

			//モデル番号の配列ポインタのNULLチェック
			if (pModelIndex != nullptr)
			{
				assert(false);
			}

			//文字列の分析
			sscanf(cBff, "%s = %d", &cBffHead, &nModelNumberMax);
			//モデル番号の配列で管理
			pModelIndex = new int[nModelNumberMax];
		}
		else if (strcmp(&cBffHead[0], "MODEL_FILENAME") == 0)
		{//モデルファイルの読み込み

			//モデル番号の配列ポインタのNULLチェック
			if (pModelIndex == nullptr)
			{
				assert(false);
			}

			//登録予定の数より多かった場合
			if (nModelNumber >= nModelNumberMax)
			{
				assert(false);
			}

			//モデルパスを読み取るための変数
			char cBffPath[LINE_MAX_READING_LENGTH];
			//文字列の分析
			sscanf(cBff, "%s = %s", &cBffHead, &cBffPath);

			//モデルのロードとインデックスの保存
			pModelIndex[nModelNumber] = ReadXFile(cBffPath);

			//モデル番号配列の保存先を変更
			nModelNumber++;

		}
		else if (strcmp(&cBffHead[0], "FIELDSET") == 0)
		{//地面の設定

			//文字列の読み取りループ処理
			while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
			{
				//文字列の分析
				sscanf(cBff, "%s", &cBffHead);

				if (strcmp(&cBffHead[0], "POS") == 0)
				{//Posの設定

					//Posの一時保存
					D3DXVECTOR3 pos;

					//文字列の分析
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &pos.x, &pos.y, &pos.z);

					//メッシュフィールドのPosの設定
					MeshData.pos = pos;
				}
				else if (strcmp(&cBffHead[0], "ROT") == 0)
				{//Rotの設定

					//Rotの一時保存
					D3DXVECTOR3 rot;

					//文字列の分析
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &rot.x, &rot.y, &rot.z);

					//メッシュフィールドのRotの設定
					MeshData.rot = rot;
				}
				else if (strcmp(&cBffHead[0], "COLOR") == 0)
				{//Colorの設定

					//Colorの一時保存
					D3DXCOLOR Color;

					//文字列の分析
					sscanf(cBff, "%s = %f %f %f %f", &cBffHead, &Color.r, &Color.g, &Color.b, &Color.a);

					//メッシュフィールドのColorの設定
					MeshData.col = Color;
				}
				else if (strcmp(&cBffHead[0], "SIZE") == 0)
				{//SIZEの設定

					//SIZEの一時保存
					float fSizeX ,fSizeZ;

					//文字列の分析
					sscanf(cBff, "%s = %f %f", &cBffHead, &fSizeX, &fSizeZ);

					//メッシュフィールドのSizeの設定
					MeshData.fRadiusX = fSizeX / 2.0f;
					MeshData.fRadiusZ = fSizeZ / 2.0f;
				}
				else if (strcmp(&cBffHead[0], "DIVISION") == 0)
				{//DIVISIONの設定

					//DIVISIONの一時保存
					int nMeshX, nMeshZ;

					//文字列の分析
					sscanf(cBff, "%s = %d %d", &cBffHead, &nMeshX, &nMeshZ);

					//メッシュフィールドのDIVISIONの設定
					MeshData.nMeshX = nMeshX;
					MeshData.nMeshZ = nMeshZ;
				}
				else if (strcmp(&cBffHead[0], "END_FIELDSET") == 0)
				{//メッシュ情報の終わりの設定

					MeshData.pos = D3DXVECTOR3(-MeshData.fRadiusX, 0.0f,MeshData.fRadiusZ);

					//メッシュ情報の設定
					pMeshfield->SetMeshfield(MeshData);

					//瓦礫マネージャーの生成
					pGame->CreateBallastManager(pMeshfield);

					break;
				}

				//保存中の文字列の初期化
				ZeroMemory(&cBff, sizeof(cBff));
				ZeroMemory(&cBffHead, sizeof(cBffHead));
			}

		}
		else if (strcmp(&cBffHead[0], "MODELSET") == 0)
		{//モデルの設定

			//３DOBJ情報の一時保管場所
			Object_Data Data;
			ZeroMemory(&Data, sizeof(Data));

			//瓦礫マネージャーの取得
			CBallast_Manager* pBallast_Manager = pGame->GetBallast_Manager();

			//文字列の読み取りループ処理
			while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
			{
				

				//文字列の分析
				sscanf(cBff, "%s", &cBffHead);

				if (strcmp(&cBffHead[0], "TYPE") == 0)
				{//TYPEの設定

					int nPattn = 0;

					//文字列の分析
					sscanf(cBff, "%s = %d", &cBffHead,&nPattn);

					Data.nPattn = pModelIndex[nPattn];

				}
				else if (strcmp(&cBffHead[0], "POS") == 0)
				{//POSの設定

					//Pos一時保管場所
					D3DXVECTOR3 pos;

					//文字列の分析
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &pos.x, &pos.y, &pos.z);

					//Posの保存
					Data.pos = pos;
				}
				else if (strcmp(&cBffHead[0], "ROT") == 0)
				{//ROTの設定

					//Rot一時保管場所
					D3DXVECTOR3 rot;

					//文字列の分析
					sscanf(cBff, "%s = %f %f %f", &cBffHead, &rot.x, &rot.y, &rot.z);

					//Rotの保存
					Data.rot = rot;
				}
				else if (strcmp(&cBffHead[0], "END_MODELSET") == 0)
				{//モデルの設定の終わり

					//このオブジェクトがメッシュのどこに居るかを調べる用
					int nPosLocationm = 0;

					////引く数のPosがどのマスに居るかを返す
					//nPosLocationm = pMeshfield->CheckPosLocation(Data.pos);

					////エラー検知用
					//if (nPosLocationm < 0)
					//{
					//	assert(false);
					//}

					//瓦礫マネージャーがNULLだったら
					if (pBallast_Manager == nullptr)
					{
						assert(false);
					}

					//瓦礫の設置
					pBallast_Manager->SetBallast(nPosLocationm, Data);

					break;
				}

				//保存中の文字列の初期化
				ZeroMemory(&cBff, sizeof(cBff));
				ZeroMemory(&cBffHead, sizeof(cBffHead));
			}
		}
		else if (strcmp(&cBffHead[0], "END_SCRIPT") == 0)
		{//スクリプトの終わり
			break;
		}

		//保存中の文字列の初期化
		ZeroMemory(&cBff, sizeof(cBff));
		ZeroMemory(&cBffHead, sizeof(cBffHead));
	}

	//モデルインデックス
	if (pModelIndex != nullptr)
	{
		delete[] pModelIndex;
		pModelIndex = nullptr;
	}

	//ファイルを閉じる
	fclose(pFile);

	//メッシュポインタ宣言のリターン
	return pMeshfield;
}

//*****************************************************************************
// Xファイルの読み込み
//*****************************************************************************
int CRead::ReadXFile(char * sXFilePath)
{
	C3DObject::ModelPattern Model;

	CManager *pManager = GetManager();

	LPDIRECT3DDEVICE9 pD3DDevice = nullptr;

	pD3DDevice = pManager->GetDeviceManager();

	//Xファイルの読み込み
	D3DXLoadMeshFromX(sXFilePath,
		D3DXMESH_SYSTEMMEM,
		pD3DDevice,
		nullptr,
		&Model.pBuffMatModel,
		nullptr,
		&Model.nNumMatModel,
		&Model.pMeshModel);

	Model.bUse = true;

	// バッファの先頭ポインタをD3DXMATERIALにキャストして取得
	D3DXMATERIAL *pMat = (D3DXMATERIAL*)Model.pBuffMatModel->GetBufferPointer();

	// 各メッシュのマテリアル情報を取得する
	for (int i = 0; i < (int)Model.nNumMatModel; i++)
	{
		Model.pTexture[i] = nullptr;

		if (pMat[i].pTextureFilename != nullptr)
		{// マテリアルで設定されているテクスチャ読み込み
			D3DXCreateTextureFromFileA(pD3DDevice,
				pMat[i].pTextureFilename,
				&Model.pTexture[i]);
		}
		else
		{
			Model.pTexture[i] = nullptr;
		}
	}

	//モデルの登録
	return C3DObject::SetModel(&Model);
}

//*****************************************************************************
// エディタ用テキストの読み込み
//*****************************************************************************
void CRead::ReadEditorText(char * sFilePath)
{
	//マネージャーの取得
	CManager* pManager = GetManager();

	//ゲームの取得
	CGame* pGame = (CGame*)pManager->GetGameObject();

	//プレイヤーの取得
	CPlayer* pPlayer = pGame->GetPlayer();

	//モデルインデックス
	int *pModelIndex = nullptr;

	FILE *pFile = NULL;			//ファイルポインター宣言

	char cBff[LINE_MAX_READING_LENGTH];		//一行分読み取るための変数
	char cBffHead[LINE_MAX_READING_LENGTH];	//頭の文字を読み取るための変数

	//読み込み可能モデル数
	int nModelNumber = 0;

	//モデルの読み込む数の保存
	int nModelNumberMax = 0;

	//ファイルを開く
	pFile = fopen(sFilePath, "r");

	if (pFile == nullptr)
	{//開けなかった時用
		assert(false);
	}

	//文字列の読み取りループ処理
	while (fgets(cBff, LINE_MAX_READING_LENGTH, pFile) != nullptr)
	{
		//文字列の分析
		sscanf(cBff, "%s", &cBffHead);

		if (strcmp(&cBffHead[0], "NUM_MODEL") == 0)
		{//モデルの読み込み数

		 //モデル番号の配列ポインタのNULLチェック
			if (pModelIndex != nullptr)
			{
				assert(false);
			}

			//文字列の分析
			sscanf(cBff, "%s = %d", &cBffHead, &nModelNumberMax);
			//モデル番号の配列で管理
			pModelIndex = new int[nModelNumberMax];
		}
		else if (strcmp(&cBffHead[0], "MODEL_FILENAME") == 0)
		{//モデルファイルの読み込み

			//モデル番号の配列ポインタのNULLチェック
			if (pModelIndex == nullptr)
			{
				assert(false);
			}

			//登録予定の数より多かった場合
			if (nModelNumber >= nModelNumberMax)
			{
				assert(false);
			}

			//モデルパスを読み取るための変数
			char cBffPath[LINE_MAX_READING_LENGTH];
			//文字列の分析
			sscanf(cBff, "%s = %s", &cBffHead, &cBffPath);

			//モデルのロードとインデックスの保存
			pModelIndex[nModelNumber] = ReadXFile(cBffPath);

			//モデル番号配列の保存先を変更
			nModelNumber++;

		}
		else if (strcmp(&cBffHead[0], "END_SCRIPT") == 0)
		{//スクリプトの終わり
			break;
		}

		//保存中の文字列の初期化
		ZeroMemory(&cBff, sizeof(cBff));
		ZeroMemory(&cBffHead, sizeof(cBffHead));
	}

	//モデルインデックス
	pPlayer->SetModelIndex(pModelIndex);

	//登録モデル数
	pPlayer->SetModelIndexMax(nModelNumberMax);

	//ファイルを閉じる
	fclose(pFile);
}

//*****************************************************************************
// エディタデータの保存
//*****************************************************************************
void CRead::SaveEditorData(std::list<C3DObject*> data)
{
	FILE *pFile = NULL;			//ファイルポインター宣言

	//ファイルを開く
	pFile = fopen("Data/EDITOR_TEXT/EditorData.txt", "w");

	if (pFile == nullptr)
	{//開けなかった時用
		assert(false);
	}

	//イテレーターループ
	for (auto itr = data.begin(); itr != data.end(); itr++)
	{
		//イテレーターから瓦礫のポインタの代入
		C3DObject* p3DObject = *itr;

		//瓦礫情報の保存
		if (p3DObject != nullptr)
		{
			//出力情報の一時保管
			int nMudelNum;
			D3DXVECTOR3 pos, rot;
			
			//モデル番号
			nMudelNum = p3DObject->GetModelNumIndex();

			//位置
			pos = p3DObject->GetPos();

			//向き
			rot = p3DObject->GetRot();

			//テキストに出力の始まり
			fprintf(pFile, "MODELSET\n");

			//モデル番号
			fprintf(pFile, "	TYPE = %d\n",nMudelNum);

			//位置
			fprintf(pFile, "	POS = %.1f %.1f %.1f\n", pos.x, pos.y, pos.z);

			//向き
			fprintf(pFile, "	ROT = %.1f %.1f %.1f\n", rot.x, rot.y, rot.z);

			//当たり判定
			if (p3DObject->GetCollision())
			{
				fprintf(pFile, "	COLLISION_OFF = 1\n");
			}
			else
			{
				fprintf(pFile, "	COLLISION_OFF = 0\n");
			}

			//オープニングロスト
			if (p3DObject->GetOpeningLost())
			{
				fprintf(pFile, "	OPENING_LOST = 1\n");
			}
			else
			{
				fprintf(pFile, "	OPENING_LOST = 0\n");
			}

			//砲台
			if (p3DObject->GetSwitch())
			{
				fprintf(pFile, "	SWITCH = 1\n");
			}
			else
			{
				fprintf(pFile, "	SWITCH = 0\n");
			}

			//テキストに出力の終わり
			fprintf(pFile, "END_MODELSET\n\n");
		}
	}

	//ファイルを閉じる
	fclose(pFile);
}
