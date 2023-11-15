//==============================================================================================
//
// チュートリアル　　　tutorial.h
// tutida ryousei
//
//==============================================================================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include"mode.h"

class CMeshField;
class CPause;

class CTutorial : public CMode
{
public:
	CTutorial();
	~CTutorial();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CTutorial *Create();

	static CMeshField *GetMeshField() { return pMeshField; }
	static CPause *GetPause() { return m_pPause; }

private:
	static CMeshField *pMeshField;			// メッシュフィールド
	static CPause *m_pPause;
};

#endif // !_TUTORIAL_H_
