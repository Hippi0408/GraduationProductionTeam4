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
class CScore;
class CTime;
class CHalfSphere;
class CMeshField;
class CCharacter;
class CCollision;
class CEnergy_Gauge;

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
	static CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	CScore* m_pScore;
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	static CMeshField *pMeshField;			// ���b�V���t�B�[���h
	static CEnergy_Gauge* m_pEnergy_Gauge;	// �G�l���M�[�Q�[�W

};

#endif // !_GAME_H_