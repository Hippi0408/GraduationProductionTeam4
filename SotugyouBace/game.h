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

class CGame : public CMode
{
public:

	CGame();
	~CGame() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CGame* Create();

private:

};

#endif // !_GAME_H_