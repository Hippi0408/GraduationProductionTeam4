//=============================================================================
//
// player_parameter.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _PLAYER_PARAMETER_H_
#define _PLAYER_PARAMETER_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "d3dx9.h"
#include "player.h"

//---------------------------
// クラス宣言
//---------------------------
class CPlayer_Parameter
{

public:

	// パラメーター
	struct PARAMETERS
	{
		int nLife;					// 耐久値
		int nStamina;				// スタミナ容量
		int nStan_Tolerance;		// スタン許容値
		int nGravity;				// 重量

									//Skill m_skill;					// スキルタイプ
	};

	CPlayer_Parameter();
	~CPlayer_Parameter();

	HRESULT Init();
	void Uninit();

	void LoadFile();		// パラメーターの読み込み

	// プレイヤーパラメーターの取得
	PARAMETERS GetParameter(const int job, const int parts) { return m_Parameter[job][parts]; }

private:

	PARAMETERS m_Parameter[CPlayer::JOB_MAX][CPlayer::PARTS_MAX];	// ジョブ数分のパラメーター
};

#endif// _PLAYER_PARAMETER_H_