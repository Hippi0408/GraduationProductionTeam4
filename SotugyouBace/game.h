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
#include"player_ui.h"
#include <vector>

// 前方宣言
class CPlayerManager;
class CEnemyManager;
class CDropManager;
class CCollision_Manager;
class CTime;
class CHalfSphere;
class CMeshField;
class CCharacter;
class CCollision;
class CFontString;
class CMenuWindow;
class CConfirmation_Window;
class CEnergy_Gauge;
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

	static void SetPlayerUI(const int index, const int type);
	static void SetDrop_Parts(int num, D3DXVECTOR3 pos, bool random = false);
	static void SetGameEnd();

	static CGame* Create();

	static const bool GetGameEnd() { return m_bGameEnd; }
	static void SetGameWindow(bool flag) { m_bGameWindow = flag; }
	static const bool GetGameWindow() { return m_bGameWindow; }
	static CPlayerManager* GetPlayerManager() { return m_pPlayerManager; }
	static CEnemyManager* GetEnemyManager() { return m_pEnemyManager; }
	static CDropManager* GetDropManager() { return m_pDropManager; }
	static CCollision_Manager* GetCollision_Manager() { return m_pCollision_Manager; }
	static CMeshField *GetMeshField() { return m_pMeshField; }
	static CConfirmation_Window* GetConfirmationWindow() { return m_pConfirmationWindow; }
	static CPause *GetPause() { return m_pPause; }

private:

	static bool m_bGameEnd;							// ゲーム終了判定
	static bool m_bGameWindow;
	bool m_bInputFlag;
	int m_nEndCounter;								// ゲーム終了までの時間
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;

	static CPlayerUi* m_pPlayer_UI[CPlayerUi::UITYPE_MAX];
	static CConfirmation_Window* m_pConfirmationWindow;		// メニューウィンドウ
	static CPlayerManager* m_pPlayerManager;
	static CEnemyManager* m_pEnemyManager;
	static CDropManager* m_pDropManager;
	static CCollision_Manager* m_pCollision_Manager;
	static CMeshField *m_pMeshField;				// メッシュフィールド
	static CEnergy_Gauge* m_pEnergy_Gauge;			// エネルギーゲージ
	static CFontString* m_pFinishRogo;				// 終了ロゴ 
	static CPause *m_pPause;

};

#endif // !_GAME_H_