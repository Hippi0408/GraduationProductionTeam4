//=============================================================================
//
// �^�C�g�����j���[
// title_menu.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _TITLE_MENU_H_
#define _TITLE_MENU_H_

#include "menu.h"
#include "object2D.h"

class CConfirmation_Window;

//---------------------------
// �N���X�錾
//---------------------------
class CTitleMenu : public CMenu
{
public:
	enum Choice_Type
	{
		Choice_GameStart,		// �Q�[���X�^�[�g
		Choice_Window_Exit,		// �E�B���h�E�����
		Choice_Max,
		Choice_Invalid = -1,		// �����Ă΂�Ă��Ȃ�
	};

	CTitleMenu();
	~CTitleMenu() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	void Choice() override;		// �I�����̏���

	static CTitleMenu* Create();

private:
	CConfirmation_Window* m_pConfirmationWindow;
	bool m_bConfirmation;
};

#endif // !_TITLE_MENU_H_