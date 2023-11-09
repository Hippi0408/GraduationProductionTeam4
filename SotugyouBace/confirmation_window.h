//==============================================
//
// confirmatiomn_window.h (メニューウィンドウ.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _CONFIRMATION_WINDOW_H_				//このマクロ定義がされてなかったら
#define  _CONFIRMATION_WINDOW_H_				//二重インクルード防止のマクロ定義

//==============================================
// インクルード
//==============================================
#include "main.h"
#include "object.h"

#include "d3dx9.h"
#include "fontString.h"
#include <vector>

//==============================================
// 前方宣言
//==============================================
class CObject2D;
class CFontString;

//==============================================
// メニューウィンドウクラス
//==============================================
class CConfirmation_Window
{
public:
	static const float BLINK_SPEED;					// 選択肢の点滅速度
	static const float MINI_ALPHA;					// 選択肢の最低透明値
	const float SizeXScaleSpeed = 11.8f;			// xサイズ拡大縮小スピード
	const float SizeYScaleSpeed = 7.5f;				// yサイズ拡大縮小スピード
	const float SizeXScaleMax = 500.0f;				// xサイズの最大スケール
	const float SizeYScaleMax = 320.0f;				// yサイズの最小スケール

	CConfirmation_Window();							// メニューウィンドウのコンストラクタ
	~CConfirmation_Window();						// メニューウィンドウのデストラクタ

	HRESULT Init();									// 初期化処理
	void Uninit();									// 終了処理
	void Update();									// 更新処理

	void ConfirmatiomnMenuScale();					// メニューのサイズ処理
	bool ConfirmatiomnMenuScaleReduce();			// タイトルメニューのサイズ縮小処理

	virtual void Choice();							// 選択肢の処理
	void ChangeChoice(const bool nextChoice);		// 選択肢を変更した時の処理
	void SetDisplay(const bool display);			// 選択肢の表示判定を設定する
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }

	bool GetUninit() { return m_bUninitFlag; }
	bool GetSelectChoice() { return m_bSelectChoice; }
	bool GetDecition() { return m_bDecition; }
	void SetSelectChoice(bool flag) { m_bSelectChoice = flag; }
	void SetLetter(const std::string letter[]);

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

	static CConfirmation_Window* Create(D3DXCOLOR col);			// 生成
	static bool GetSapawnWindow() { return m_bSpawnWindow; }
	static void SetSapawnWindow(bool flag) { m_bSpawnWindow = flag; }

private:
	CObject2D* m_pObject2D;
	CFontString* m_pFont;
	D3DXCOLOR m_Color;
	std::string m_Letter[3];

	int		m_nMenuInitiative;					// メニューの主導権

	float	SizeX;								// Xサイズ
	float	SizeY;								// Yサイズ
	float	m_fBlinkSpeed;						// 点滅速度

	bool	m_bMaxSize;							// XとYのサイズが最大値まで行ったか
	bool	m_bSelectChoice;					// 選択肢の番号
	bool	m_bDisplay;							// 表示中の判定
	bool	m_bScale;
	bool    m_bUninitFlag;
	bool    m_bDecition;
	static bool    m_bSpawnWindow;

	std::vector<CFontString*> m_vpListChoice;	// 選択肢ポインタの配列
};
#endif