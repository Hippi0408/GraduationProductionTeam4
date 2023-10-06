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

class CScore;
class CTime;
class CHalfSphere;

// �O���錾
class CMeshField;

class CGame : public CMode
{
public:

	CGame();
	~CGame() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CGame* Create();

	static CMeshField *GetMeshField() { return pMeshField; }

private:
	CScore* m_pScore;
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	static CMeshField *pMeshField;		// ���b�V���t�B�[���h
};

#endif // !_GAME_H_