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
class CPlayerManager;

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

	static void SetGameEnd();

	static CGame* Create();

	static const bool GetGameEnd() { return m_bGameEnd; }
	static CMeshField *GetMeshField() { return pMeshField; }
	static CPlayerManager* GetPlayerManager() { return m_pPlayer_Manager; }
	static std::vector<CCharacter*> GetMob() { return m_pMob; }
	static CCharacter *GetBoss() { return m_pBoss; }

private:

	static bool m_bGameEnd;						// �Q�[���I������
	int m_nEndCounter;							// �Q�[���I���܂ł̎���
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	static CMeshField *pMeshField;				// ���b�V���t�B�[���h
	static CFontString* m_pFinishRogo;			// �I�����S
	static CPlayerManager *m_pPlayer_Manager;	// �v���C���[�}�l�[�W���[
	static std::vector<CCharacter*> m_pMob;		// ���u
	static CCharacter *m_pBoss;					// �{�X
};

#endif // !_GAME_H_