//==============================================
//
// chardecision_window.h (キャラ決定ウィンドウ.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _CHARDECISISION_WINDOW_H_				//このマクロ定義がされてなかったら
#define  _CHARDECISISION_WINDOW_H_				//二重インクルード防止のマクロ定義

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
// キャラ決定ウィンドウクラス
//==============================================
class CCharDecision_Window
{
public:
	static const int MAX_TEXTURE = 3;							// テクスチャの最大数
	const float SizeXScaleSpeed = 11.8f;						// xサイズ拡大縮小スピード
	const float SizeYScaleSpeed = 7.5f;							// yサイズ拡大縮小スピード

	CCharDecision_Window();										// メニューウィンドウのコンストラクタ
	~CCharDecision_Window();									// メニューウィンドウのデストラクタ

	HRESULT Init();												// 初期化処理
	void Uninit();												// 終了処理
	void Update();												// 更新処理

	void SetFont(const std::string lette[]);
	void UninitFont();
	void CharDecisionMenuScale();								// メニューのサイズ処理
	bool CharDecisionMenuScaleReduce();							// タイトルメニューのサイズ縮小処理

	int GetSelectChoice() { return 	m_nSelectChoice = 0; }
	bool GetUninit() { return m_bUninitFlag; }	
	bool GetCreateFlag() { return m_bCreateFlag; }
	bool GetSapawnWindow() { return m_bSpawnWindow; }
	bool GetMaxScale() { return m_bMaxSize; }

	void SetCharDecisionChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }
	void SetUninit(bool flag) { m_bUninitFlag = flag; }
	void SetSapawnWindow(bool flag) { m_bSpawnWindow = flag; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }
	static CObject2D* GetObject2D() { return m_pObject2D[MAX_TEXTURE]; }
	static CCharDecision_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);			// 生成

private:
	static CObject2D* m_pObject2D[MAX_TEXTURE];						// オブジェクト2Dのインスタンス
	CFontString* m_pFont[2];						// フォント
	D3DXVECTOR3 m_pos;							// 位置
	D3DXCOLOR m_Color;							// 色

	int		m_nMenuInitiative;					// メニューの主導権
	int		m_nSelectChoice;

	float	m_SizeX;							// Xサイズ
	float	m_SizeY;							// Yサイズ
	float	m_MaxSizeX;							// Xの最大サイズ
	float	m_MaxSizeY;							// Yの最大サイズ
	float	m_fBlinkSpeed;						// 点滅速度

	bool	m_bMaxSize;							// XとYのサイズが最大値まで行ったか
	bool	m_bDisplay;							// 表示中の判定
	bool	m_bScale;							// 拡大縮小のフラグ
	bool    m_bUninitFlag;						// 削除フラグ
	bool    m_bCreateFlag;
	bool    m_bFontFlag;
	bool    m_bDecition;						// 決定されたか
	bool    m_bSpawnWindow;						// ウィンドウが生成されたか

	std::vector<CFontString*> m_vpListChoice;	// 選択肢ポインタの配列
};
#endif