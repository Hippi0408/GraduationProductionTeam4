//=============================================================================
//
// player_parameter.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "player_parameter.h"
#include "application.h"

//=====================================
// デフォルトコンストラクタ
//=====================================
CPlayer_Parameter::CPlayer_Parameter()
{

}

//=====================================
// デストラクタ
//=====================================
CPlayer_Parameter::~CPlayer_Parameter()
{
}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CPlayer_Parameter::Init()
{
	// パラメーターファイルの読み込み
	LoadFile();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CPlayer_Parameter::Uninit()
{

}

//==============================================================================================
// パラメーターの設定
//==============================================================================================
void CPlayer_Parameter::LoadFile()
{
	// ファイル名
	FILE* pFile = fopen("Data\\text\\Parameter\\parameter_Player.txt", "r");

	int nJob_Index = 0;					// ジョブの番号
	int nParameter_Index = 0;			// パラメータの番号
	char aString[0xff];
	memset(aString, 0, sizeof(aString));

	// ファイルが開いた場合
	if (pFile != NULL)
	{
		while (strcmp(&aString[0], "END_SCRIPT") != 0)
		{
			fscanf(pFile, "%s", &aString[0]);

			// SCRIPTが一致
			if (strcmp(&aString[0], "SCRIPT") == 0)
			{
				while (strcmp(&aString[0], "END_SCRIPT") != 0)
				{
					fscanf(pFile, "%s", &aString[0]);

					// 全てのパラメータセット
					if (strcmp(&aString[0], "ALL_PARAM_SET") == 0)
					{
						while (strcmp(&aString[0], "END_ALL_PARAM_SET") != 0)
						{
							fscanf(pFile, "%s", &aString[0]);

							// ジョブ毎のパラメーターセット
							if (strcmp(&aString[0], "JOB_PARAM_SET") == 0)
							{
								while (strcmp(&aString[0], "END_JOB_PARAM_SET") != 0)
								{
									fscanf(pFile, "%s", &aString[0]);

									// パラメーターセット
									if (strcmp(&aString[0], "PARAM_SET") == 0)
									{
										while (strcmp(&aString[0], "END_PARAM_SET") != 0)
										{
											fscanf(pFile, "%s", &aString[0]);

											// 体力
											if (strcmp(&aString[0], "LIFE") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nLife);
											}

											// スタミナ
											if (strcmp(&aString[0], "STAMINA") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nStamina);
											}

											// スタン許容値
											if (strcmp(&aString[0], "STAN_TOLERANCE") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nStan_Tolerance);
											}

											// スタミナ
											if (strcmp(&aString[0], "GRAVITY") == 0)
											{
												fscanf(pFile, "%s", &aString[0]);
												fscanf(pFile, "%d", &m_Parameter[nJob_Index][nParameter_Index].nGravity);
											}
										}
										nParameter_Index++;	// パラメーターのカウント
									}
								}
								nParameter_Index = 0;		// パラメーター数の初期化
								nJob_Index++;				// ジョブのカウント
							}
						}
					}
				}
			}
		}
		//ファイルを閉じる
		fclose(pFile);
	}
}