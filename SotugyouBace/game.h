//==============================================================================================
//
// �Q�[���@�@�@game.h
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#ifndef _GAME_H_
#define	_GAME_H_

#include"mode.h"
#include <vector>

// �O���錾
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
class CPlayerUi;
class CPause;

class CGame : public CMode
{
	static const int MAX_FINISH_ROGO = 60;	// �I�����S�܂ł̎���
	static const int MAX_END_TIMER = 240;	// �Q�[���I���܂ł̎���

public:
	CGame();
	~CGame() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	void GameEnd();
	void MenuWindow();

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

	static bool m_bGameEnd;							// �Q�[���I������
	static bool m_bGameWindow;
	bool m_bInputFlag;
	int m_nEndCounter;								// �Q�[���I���܂ł̎���
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	CPlayerUi* m_pPlayerUI;
	
	static CConfirmation_Window* m_pConfirmationWindow;		// ���j���[�E�B���h�E
	static CPlayerManager* m_pPlayerManager;
	static CEnemyManager* m_pEnemyManager;
	static CDropManager* m_pDropManager;
	static CCollision_Manager* m_pCollision_Manager;
	static CMeshField *m_pMeshField;				// ���b�V���t�B�[���h
	static CEnergy_Gauge* m_pEnergy_Gauge;			// �G�l���M�[�Q�[�W
	static CFontString* m_pFinishRogo;				// �I�����S 
	static CPause *m_pPause;

};

#endif // !_GAME_H_