//=============================================================================
//
// charselect_window.h (キャラ選択ウィンドウ.h)
// Author : Saito Shian
//
//=============================================================================
#ifndef  _CHARSELECT_WINDOW_H_				//このマクロ定義がされてなかったら
#define  _CHARSELECT_WINDOW_H_				//二重インクルード防止のマクロ定義

//=============================================================================
// インクルード
//=============================================================================
#include "main.h"
#include "object.h"
#include "d3dx9.h"
#include "fontString.h"
#include <vector>

//=============================================================================
// 前方宣言
//=============================================================================
class CObject2D;
class CFontString;
class CCharDecision_Window;

//=============================================================================
// キャラ選択ウィンドウクラス
//=============================================================================
class CCharSelect_Window
{
	static const float BLINK_SPEED;							// 選択肢の点滅速度
	static const float MINI_ALPHA;							// 選択肢の最低透明値
	const float SizeXScaleSpeed = 31.8f;					// xサイズ拡大縮小スピード
	const float SizeYScaleSpeed = 27.5f;					// yサイズ拡大縮小スピード

public:
	CCharSelect_Window();									// キャラ選択ウィンドウのコンストラクタ
	~CCharSelect_Window();									// キャラ選択ウィンドウのデストラクタ

	HRESULT Init();											// 初期化処理
	void Uninit();											// 終了処理
	void Update();											// 更新処理

	virtual void CharSelectChoice();						// 選択肢の処理
	void CharSelectMenuScale();								// キャラ選択ウィンドウのサイズ処理
	bool CharSelectMenuScaleReduce();						// キャラ選択ウィンドウのサイズ縮小処理
	void CharSelectChangeChoice(const int nextChoice);		// 選択肢を変更した時の処理
	void InitSelect();										// 選択肢の初期化処理
	void UninitFont();										// フォントの削除処理

	void SetSelectChoice(int index);														// 選択した番号
	void SetCharSelectDisplay(const bool display);											// 選択肢の表示判定を設定する
	void SetSkillName(const std::string name, const std::string skillname);					// スキル名
	void SetCharSelectChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }		// 選択肢ポインタの設定処理
	void SetSkillSelectChoice(const std::string typename, const std::string name, const std::string name1, const std::string name2, const std::string name3);	// 選択した番号によってスキルを変える処理

	CCharDecision_Window* GetCharDecision() { return m_pCharDecision; }						// キャラ決定インスタンスの取得処理
	int GetSelectChoice() { return 	m_nCharSelectWindowSelectChoice; }						// 選択肢の番号の取得処理
	bool GetPreviousWindow() { return m_bPreviousWindowCreate; }							// 前のウィンドウに戻ったのかの取得処理

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }						// 選択肢ポインタの取得処理
	
	static CCharSelect_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);	// 生成

private:
	CCharDecision_Window* m_pCharDecision;		// キャラ決定のインスタンス
	CObject2D* m_pObject2D;						// オブジェクト2Dのインスタンス
	
	D3DXVECTOR2 m_CharSelectWindowSize;			// サイズ
	D3DXVECTOR2 m_CharSelectWindowMaxSize;		// 最大サイズ
	CFontString* m_pFont;						// フォント
	D3DXVECTOR3 m_pos;							// 位置
	D3DXCOLOR m_Color;							// 色

	std::vector<CFontString*> m_vpListChoice;	// 選択肢ポインタの配列
	std::string m_nLetter[2];					// 文字を格納する変数

	int		m_nCharSelectWindowSelectChoice;	// 選択肢の番号

	float	m_fCharSelectWindowBlinkSpeed;		// 点滅速度

	bool	m_bCharSelectWindowMaxSize;			// XとYのサイズが最大値まで行ったか
	bool	m_bCharSelectWindowDisplay;			// 表示中の判定 a
	bool	m_bCharSelectWindowScale;			// 拡大縮小のフラグ
	bool    m_bCharSelectWindowDecition;		// 決定されたか
	bool    m_bCharSelectWindowWindowUse;		// キャラ選択ウィンドウが使われているのか
	bool	m_bCharSelectWindowUninitFlag;		// キャラ選択ウィンドウが削除されたか
	bool    m_bCharSelectWindowBackFlag;		// 前のウィンドウから戻ってきたか
	bool    m_bPreviousWindowCreate;			// 前のウィンドウに戻るのか
	bool    m_bDicisionCreateFlag;				// キャラ決定ウィンドウが生成されたか
	bool    m_bDicisionUse;						// キャラ決定ウィンドウが使われているか
};
#endif