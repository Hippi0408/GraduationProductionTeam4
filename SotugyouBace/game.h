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
	static CMeshField *pMeshField;		// メッシュフィールド
};

#endif // !_GAME_H_