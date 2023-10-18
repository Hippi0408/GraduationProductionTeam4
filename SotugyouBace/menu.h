//=============================================================================
//
// menu.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _MENU_H_
#define _MENU_H_

#include "d3dx9.h"
#include "fontString.h"
#include <vector>

//---------------------------
// クラス宣言
//---------------------------
class CMenu
{
	static const float CHOICE_BLINK_SPEED;		// 選択肢の点滅速度
	static const float CHOICE_MINI_ALPHA;		// 選択肢の最低透明値

public:
	CMenu();
	virtual ~CMenu();

	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();

	virtual void Choice();						// 選択肢の処理
	void ChangeChoice(const int nextChoice);	// 選択肢を変更した時の処理

	void SetMenuInitiative(const int index) { m_nMenuInitiative = index; }
	void SetDecition(const bool decition) { m_bDecition = decition; }
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }
	void SetDisplay(const bool display);		// 選択肢の表示判定を設定する

	const int GetMenuInitiative() { return m_nMenuInitiative; }
	const int GetSelectChoice() { return m_nSelectChoice; }
	const bool GetDecition() { return m_bDecition; }
	const bool GetDisplay() { return m_bDisplay; }
	CFontString* GetChoice(const int index) { return m_vpListChoice[index]; }
	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

private:

	int		m_nMenuInitiative;					// メニューの主導権
	int		m_nSelectChoice;					// 選択肢の番号
	float	m_fBlinkSpeed;						// 点滅速度
	bool	m_bDecition;						// 決定の判定
	bool	m_bDisplay;							// 表示中の判定

	std::vector<CFontString*> m_vpListChoice;	// 選択肢ポインタの配列
};

#endif // !_MENU_H_