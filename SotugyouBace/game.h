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
#include <vector>

// 前方宣言
class CTime;
class CHalfSphere;
class CMeshField;
class CCharacter;
class CCollision;
class CFontString;
class CPlayerManager;

class CGame : public CMode
{
	static const int MAX_FINISH_ROGO = 60;	// 終了ロゴまでの時間
	static const int MAX_END_TIMER = 240;	// ゲーム終了までの時間

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
	static CPlayerManager* GetPlayerManager() { return m_pPlayer_Manager; }
	static std::vector<CCharacter*> GetMob() { return m_pMob; }
	static CCharacter *GetBoss() { return m_pBoss; }

private:

	static bool m_bGameEnd;						// ゲーム終了判定
	int m_nEndCounter;							// ゲーム終了までの時間
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	static CMeshField *pMeshField;				// メッシュフィールド
	static CFontString* m_pFinishRogo;			// 終了ロゴ
	static CPlayerManager *m_pPlayer_Manager;	// プレイヤーマネージャー
	static std::vector<CCharacter*> m_pMob;		// モブ
	static CCharacter *m_pBoss;					// ボス
};

#endif // !_GAME_H_