//==============================================================================================
//
// マップ			map.cpp
// tutida ryousei
//
//==============================================================================================
#include"map.h"
#include"map_object.h"
#include <stdio.h>
#include "d3dx9.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CMap::CMap()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CMap::~CMap()
{
}

//==============================================================================================
// マップの読み込み
//==============================================================================================
void CMap::ReadMap(char *filename)
{
	// ファイル名
	FILE* pFile = fopen(filename, "r");

	char m_aString[0xff];
	memset(m_aString, 0, sizeof(m_aString));

	char XFileName[0x20][0xff] = {};	// Xファイル名

	int nNumModel = 0;
	int nIndex = 0;
	int nType = 0;
	D3DXVECTOR3 Pos = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 Rot = { 0.0f,0.0f,0.0f };

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

					if (strcmp(&m_aString[0], "NUM_MODEL") == 0)
					{
						// モデルの数
						fscanf(pFile, "%s", &m_aString[0]);
						fscanf(pFile, "%d", &nNumModel);
					}

					if (strcmp(&m_aString[0], "MODEL_FILENAME") == 0)
					{
						// ファイルネーム
						fscanf(pFile, "%s", &m_aString[0]);
						fscanf(pFile, "%s", &XFileName[nIndex][0]);
						nIndex++;
					}

					if (strcmp(&m_aString[0], "MODELSET") == 0)
					{
						while (strcmp(&m_aString[0], "END_MODELSET") != 0)
						{
							fscanf(pFile, "%s", &m_aString[0]);

							if (strcmp(&m_aString[0], "TYPE") == 0)
							{
								// モデルタイプ
								fscanf(pFile, "%s", &m_aString[0]);
								fscanf(pFile, "%d", &nType);
							}
							if (strcmp(&m_aString[0], "POS") == 0)
							{
								// 位置
								fscanf(pFile, "%s", &m_aString[0]);
								fscanf(pFile, "%f", &Pos.x);
								fscanf(pFile, "%f", &Pos.y);
								fscanf(pFile, "%f", &Pos.z);
							}
							if (strcmp(&m_aString[0], "ROT") == 0)
							{
								// 角度
								fscanf(pFile, "%s", &m_aString[0]);
								fscanf(pFile, "%f", &Rot.x);
								fscanf(pFile, "%f", &Rot.y);
								fscanf(pFile, "%f", &Rot.z);
							}
						}

						// モデル生成
						CMap_Object::Create(Pos, Rot, nullptr, &XFileName[nType][0]);
					}
				}
			}
		}
	}

	//ファイルを閉じる
	fclose(pFile);
}