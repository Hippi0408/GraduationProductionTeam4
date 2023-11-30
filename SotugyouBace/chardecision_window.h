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
	static const int MAX_TEXTURE = 2;							// テクスチャの最大数
	static const float BLINK_SPEED;								// 選択肢の点滅速度
	static const float MINI_ALPHA;								// 選択肢の最低透明値
	const float SizeXScaleSpeed = 11.8f;						// xサイズ拡大縮小スピード
	const float SizeYScaleSpeed = 7.5f;							// yサイズ拡大縮小スピード

	CCharDecision_Window();										// メニューウィンドウのコンストラクタ
	~CCharDecision_Window();									// メニューウィンドウのデストラクタ

	HRESULT Init();												// 初期化処理
	void Uninit();												// 終了処理
	void Update();												// 更新処理

	void SetFont(const std::string lette[]);					// フォントの設定処理
	void SetTextue(CTexture::TEXTURE texture, CTexture::TEXTURE texture1);							// テクスチャの設定
	void UninitExplanation();									// 説明用テクスチャ、フォントの破棄処理
	void CharDecisionMenuScale();								// メニューのサイズ処理
	void CharSelectChoice();									// 選択肢の処理

	bool GetSapawnWindow() { return m_bSpawnWindow; }			// ウィンドウが生成されたかの取得処理
	bool GetMaxScale() { return m_bMaxSize; }					// ウィンドウが最大サイズまで行ったのかを取得する処理
	bool GetExplanationUninit() { return m_bExplanationUninit; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }										// 選択肢ポインタの取得処理
	static CCharDecision_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);			// 生成処理

private:
	CObject2D* m_pWindow;						// オブジェクト2Dのインスタンス
	CObject2D* m_pObject2D[MAX_TEXTURE];		// オブジェクト2Dのインスタンス
	CFontString* m_pFont[2];					// フォント
	D3DXVECTOR3 m_posDest;						// 目的位置
	D3DXVECTOR3 m_pos;							// 位置
	D3DXCOLOR m_Color;							// 色

	int		m_nMenuInitiative;					// メニューの主導権
	int		m_nSelectIndex;
	int index;

	float	m_SizeX;							// Xサイズ
	float	m_SizeY;							// Yサイズ
	float	m_MaxSizeX;							// Xの最大サイズ
	float	m_MaxSizeY;							// Yの最大サイズ
	float	m_fBlinkSpeed;						// 点滅速度
	float	m_fMoveX;

	bool	m_bMaxSize;							// XとYのサイズが最大値まで行ったか
	bool	m_bDisplay;							// 表示中の判定
	bool	m_bScale;							// 拡大縮小のフラグ
	bool    m_bUninitFlag;						// 削除フラグ
	bool    m_bCreateFlag;
	bool    m_bFontFlag;
	bool    m_bDecition;						// 決定されたか
	bool    m_bSpawnWindow;						// ウィンドウが生成されたか
	bool    m_bStopFlag;
	bool    m_bExplanationUninit;					// テクスチャとフォントの削除フラグ
	bool    m_bPosDest;	// 目的の位置まで行ったのか

	

	std::vector<CFontString*> m_vpListChoice;	// 選択肢ポインタの配列
};
#endif