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
class CMenuWindow;
class CConfirmation_Window;
class CPlayerManager;
class CEnergy_Gauge;

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
	void MenuWindow();

	static void SetGameEnd();

	static CGame* Create();

	static const bool GetGameEnd() { return m_bGameEnd; }
	static void SetGameWindow(bool flag) { m_bGameWindow = flag; }
	static const bool GetGameWindow() { return m_bGameWindow; }
	static CMeshField *GetMeshField() { return pMeshField; }
	static CPlayerManager* GetPlayerManager() { return m_pPlayer_Manager; }

private:


	static bool m_bGameEnd;							// ゲーム終了判定
	static bool m_bGameWindow;
	int m_nEndCounter;								// ゲーム終了までの時間
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	
	CConfirmation_Window* m_ponfirmationWindow;		// メニューウィンドウ
	static CMeshField *pMeshField;					// メッシュフィールド
	static CEnergy_Gauge* m_pEnergy_Gauge;			// エネルギーゲージ
	static CFontString* m_pFinishRogo;				// 終了ロゴ 


	static CPlayerManager *m_pPlayer_Manager;	// プレイヤーマネージャー
};

#endif // !_GAME_H_