//==============================================================================================
//
// キャラクターセレクト　　　char_select.h
// tutida ryousei
//
//==============================================================================================
#ifndef _CHAR_SELECT_H_
#define	_CHAR_SELECT_H_

#include"mode.h"
#include "fontString.h"
#include <vector>

class CConfirmation_Window;
class CFontString;

class CChar_Select : public CMode
{
public:
	CChar_Select();
	~CChar_Select();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CChar_Select* Create();

private:
	CConfirmation_Window* m_pConfirmation;
	CFontString* m_pFont;
};

#endif // !_CHAR_SELECT_H_
