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

// �O���錾
class CTime;
class CHalfSphere;
class CMeshField;
class CCharacter;
class CCollision;
class CEnergy_Gauge;
class CFontString;

class CGame : public CMode
{
	static const int MAX_END_TIMER = 120;	// �Q�[���I���܂ł̎���

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

	static bool m_bGameEnd;					// �Q�[���I������
	int m_nEndCounter;						// �Q�[���I���܂ł̎���
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	static CMeshField *pMeshField;			// ���b�V���t�B�[���h
	static CEnergy_Gauge* m_pEnergy_Gauge;	// �G�l���M�[�Q�[�W
	static CFontString* m_pFinishRogo;		// �I�����S
};

#endif // !_GAME_H_