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
class CCharSelect_Window;

//==============================================
// メニューウィンドウクラス
//==============================================
class CConfirmation_Window
{
public:
	static const float BLINK_SPEED;			// 選択肢の点滅速度
	static const float MINI_ALPHA;			// 選択肢の最低透明値
	const float SizeXScaleSpeed = 11.8f;	// xサイズ拡大縮小スピード
	const float SizeYScaleSpeed = 7.5f;		// yサイズ拡大縮小スピード

	CConfirmation_Window();					// メニューウィンドウのコンストラクタ
	~CConfirmation_Window();				// メニューウィンドウのデストラクタ

	HRESULT Init();							// 初期化処理
	void Uninit();							// 終了処理
	void Update();							// 更新処理

	void ConfirmatiomnMenuScale();			// メニューのサイズ処理
	bool ConfirmatiomnMenuScaleReduce();	// タイトルメニューのサイズ縮小処理

	// Setter
	virtual void Choice();														// 選択肢の処理
	void CreateCharSelect();													// キャラ選択画面の生成処理
	void SetDisplay(const bool display);										// 選択肢の表示判定を設定する
	void ChangeChoice(const bool nextChoice);									// 選択肢を変更した時の処理
	void SetSapawnWindow(bool flag) { m_bSpawnWindow = flag; }					// ウィンドウ生成の設定処理
	void SetSelectChoice(bool flag) { m_bSelectChoice = flag; }					// 選択した番号の設定処理
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }	// 選択肢ポインタの設定処理

	// Getter
	bool GetUninit() { return m_bUninitFlag; }									// 削除フラグの取得処理
	bool GetSapawnWindow() { return m_bSpawnWindow; }							// ウィンドウ生成フラグの取得処理
	bool GetSelectChoice() { return m_bSelectChoice; }							// 選択肢番号の取得処理
	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }			// 選択肢ポインタの取得処理
	static CCharSelect_Window* GetCharSelect() { return m_pCharSelectWindow; }	// キャラ選択用ウィンドウの取得処理

	static CConfirmation_Window* Create(D3DXVECTOR3 pos,float xsize, float ysize, D3DXCOLOR col);		// 生成処理

private:
	static CCharSelect_Window* m_pCharSelectWindow;	// キャラ選択用ウィンドウのインスタンス
	CObject2D* m_pObject2D;							// オブジェクト2Dのインスタンス
	CFontString* m_pFont;							// フォント
	D3DXVECTOR3 m_pos;								// 位置
	D3DXCOLOR m_Color;								// 色

	int		m_nMenuInitiative;						// メニューの主導権

	float	SizeX;									// Xサイズ
	float	SizeY;									// Yサイズ
	float	MaxSizeX;								// Xの最大サイズ
	float	MaxSizeY;								// Yの最大サイズ
	float	m_fBlinkSpeed;							// 点滅速度

	bool	m_bMaxSize;								// XとYのサイズが最大値まで行ったか
	bool	m_bSelectChoice;						// 選択肢の番号
	bool	m_bDisplay;								// 表示中の判定
	bool	m_bScale;								// 拡大縮小のフラグ
	bool    m_bUninitFlag;							// 削除フラグ
	bool    m_bDecition;							// 決定されたか
	bool    m_bSpawnWindow;							// ウィンドウが生成されたか

	std::vector<CFontString*> m_vpListChoice;		// 選択肢ポインタの配列
};
#endif