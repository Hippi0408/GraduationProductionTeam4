//=============================================================================
//
// タイトルメニュー
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
// クラス宣言
//---------------------------
class CTitleMenu : public CMenu
{
public:
	enum Choice_Type
	{
		Choice_GameStart,		// ゲームスタート
		Choice_Window_Exit,		// ウィンドウを閉じる
		Choice_Max,
		Choice_Invalid = -1,		// 何も呼ばれていない
	};

	CTitleMenu();
	~CTitleMenu() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	void Choice() override;		// 選択肢の処理

	static CTitleMenu* Create();
	static CConfirmation_Window* GetComfirmationWindow() { return m_pConfirmationWindow; }
	static void UninitComfirmationWindow();

private:
	static CConfirmation_Window* m_pConfirmationWindow;
	bool m_bConfirmation;
};

#endif // !_TITLE_MENU_H_