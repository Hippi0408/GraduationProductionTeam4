//==============================================================================================
//
// ゲーム　　　game.h
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#ifndef _GAME_H_
#define	_GAME_H_

#include"mode.h"

// 前方宣言
class CTime;
class CHalfSphere;
class CMeshField;
class CCharacter;
class CCollision;
class CEnergy_Gauge;
class CFontString;

class CGame : public CMode
{
	static const int MAX_END_TIMER = 120;	// ゲーム終了までの時間

public:
	CGame();
	~CGame() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	void GameEnd();

	static void SetGameEnd();

	static CGame* Create();

	static const bool GetGameEnd() { return m_bGameEnd; }
	static CMeshField *GetMeshField() { return pMeshField; }
	static CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:

	static bool m_bGameEnd;					// ゲーム終了判定
	int m_nEndCounter;						// ゲーム終了までの時間
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	static CMeshField *pMeshField;			// メッシュフィールド
	static CEnergy_Gauge* m_pEnergy_Gauge;	// エネルギーゲージ
	static CFontString* m_pFinishRogo;		// 終了ロゴ
};

#endif // !_GAME_H_