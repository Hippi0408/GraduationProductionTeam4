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

	static void SetGameEnd();

	static CGame* Create();

	static const bool GetGameEnd() { return m_bGameEnd; }
	static void SetGameWindow(bool flag) { m_bGameWindow = flag; }
	static const bool GetGameWindow() { return m_bGameWindow; }
	static CMeshField *GetMeshField() { return pMeshField; }
	static CPlayerManager* GetPlayerManager() { return m_pPlayer_Manager; }

private:


	static bool m_bGameEnd;							// �Q�[���I������
	static bool m_bGameWindow;
	int m_nEndCounter;								// �Q�[���I���܂ł̎���
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	
	CConfirmation_Window* m_ponfirmationWindow;		// ���j���[�E�B���h�E
	static CMeshField *pMeshField;					// ���b�V���t�B�[���h
	static CEnergy_Gauge* m_pEnergy_Gauge;			// �G�l���M�[�Q�[�W
	static CFontString* m_pFinishRogo;				// �I�����S 


	static CPlayerManager *m_pPlayer_Manager;	// �v���C���[�}�l�[�W���[
};

#endif // !_GAME_H_