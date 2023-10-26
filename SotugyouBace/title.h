//==============================================================================================
//
// タイトル　　　title.h
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#ifndef _TITLE_H_
#define	_TITLE_H_

#include"mode.h"

class CHalfSphere;
class CFontString;
class CMenuWindow;

class CTitle : public CMode
{
public:
	CTitle();
	~CTitle();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static void SetWindow(bool flag) { m_bWindow = flag; }
	static void SetUninitWindow(bool flag) { m_bWindowUninit = flag; }
	static bool GetUninitWindow() { return m_bWindowUninit; }

	static CTitle* Create();

private:
	CMenuWindow* m_pMenuWindow;
	CHalfSphere* m_pHalf;
	CFontString* m_pFomntString[2];
	
	static bool m_bWindow;		// ウィンドウ使用状態
	static bool m_bWindowUninit;
	bool m_bKeyFlag;
};

#endif // !_TITLE_H_
