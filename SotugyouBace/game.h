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

// 前方宣言
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

	static CCharacter *GetBoss() { return pBoss; }
	static CMeshField *GetMeshField() { return pMeshField; }
	static CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	CScore* m_pScore;
	CTime* m_pTime;
	CHalfSphere* m_pHalfSphere;
	CCollision *pCollision;					// 当たり判定
	static CCharacter *pBoss;				// ボス
	static CMeshField *pMeshField;			// メッシュフィールド
	static CEnergy_Gauge* m_pEnergy_Gauge;	// エネルギーゲージ

};

#endif // !_GAME_H_