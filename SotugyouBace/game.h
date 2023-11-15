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
class CPlayerUi;
class CPause;

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

	static void SetDrop_Parts(int num, D3DXVECTOR3 pos, bool rand = false);
	static void SetGameEnd();

	static CGame* Create();

	static const bool GetGameEnd() { return m_bGameEnd; }
	static void SetGameWindow(bool flag) { m_bGameWindow = flag; }
	static const bool GetGameWindow() { return m_bGameWindow; }
	static CMeshField *GetMeshField() { return m_pMeshField; }
	static CPlayerManager* GetPlayerManager() { return m_pPlayer_Manager; }
	static CConfirmation_Window* GetConfirmationWindow() { return m_pConfirmationWindow; }
	static CPause *GetPause() { return m_pPause; }

private:

	static bool m_bGameEnd;							// ゲーム終了判定
	static bool m_bGameWindow;
	int m_nEndCounter;								// ゲーム終了までの時間
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	CPlayerUi* m_pPlayerUI;
	
	static CConfirmation_Window* m_pConfirmationWindow;		// メニューウィンドウ
	static CMeshField *m_pMeshField;				// メッシュフィールド
	static CEnergy_Gauge* m_pEnergy_Gauge;			// エネルギーゲージ
	static CFontString* m_pFinishRogo;				// 終了ロゴ 
	static CPause *m_pPause;

	static CPlayerManager *m_pPlayer_Manager;	// プレイヤーマネージャー
};

#endif // !_GAME_H_