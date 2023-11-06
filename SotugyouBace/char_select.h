//==============================================================================================
//
// キャラクターセレクト　　　char_select.h
// tutida ryousei
//
//==============================================================================================
#ifndef _CHAR_SELECT_H_
#define	_CHAR_SELECT_H_

#include"mode.h"

class CConfirmation_Window;

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
};

#endif // !_CHAR_SELECT_H_
