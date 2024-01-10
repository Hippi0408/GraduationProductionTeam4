//==============================================================================================
//
// リザルト　　　result.h
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#ifndef _RESULT_H_
#define	_RESULT_H_

#include"mode.h"

class CHalfSphere;

class CResult : public CMode
{
public:

	CResult();
	~CResult();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CResult* Create();

private:
	CHalfSphere* m_pHalfSphere;
	int m_Index;
};

#endif // !_GAME_H_
