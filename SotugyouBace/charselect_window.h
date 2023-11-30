//==============================================
//
// charselect_window.h (キャラ選択ウィンドウ.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _CHARSELECT_WINDOW_H_				//このマクロ定義がされてなかったら
#define  _CHARSELECT_WINDOW_H_				//二重インクルード防止のマクロ定義

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
class CCharDecision_Window;

//==============================================
// メニューウィンドウクラス
//==============================================
class CCharSelect_Window
{
public:
	static const float BLINK_SPEED;							// 選択肢の点滅速度
	static const float MINI_ALPHA;							// 選択肢の最低透明値
	const float SizeXScaleSpeed = 11.8f;					// xサイズ拡大縮小スピード
	const float SizeYScaleSpeed = 7.5f;						// yサイズ拡大縮小スピード

	CCharSelect_Window();									// メニューウィンドウのコンストラクタ
	~CCharSelect_Window();									// メニューウィンドウのデストラクタ

	HRESULT Init();											// 初期化処理
	void Uninit();											// 終了処理
	void Update();											// 更新処理

	void CharSelectMenuScale();								// メニューのサイズ処理
	bool CharSelectMenuScaleReduce();						// タイトルメニューのサイズ縮小処理

	virtual void CharSelectChoice();						// 選択肢の処理
	void CharSelectChangeChoice(const int nextChoice);		// 選択肢を変更した時の処理

	void CharName(const std::string name, const std::string skillname);						// キャラクター名
	void InitSelect();

	void SetSelectChoice(int index);
	void SetCharSelectDisplay(const bool display);											// 選択肢の表示判定を設定する
	void SetCharSelectChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }
	void SetSapawnWindow(bool flag) { m_bSpawnWindow = flag; }
	void SetScale(bool flag) { m_bScale = flag; }

	int GetSelectChoice() { return 	m_nSelectChoice; }
	bool GetSapawnWindow() { return m_bSpawnWindow; }
	bool GetScale() { return m_bScale; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

	static CCharSelect_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);			// 生成

private:
	CObject2D* m_pObject2D;						// オブジェクト2Dのインスタンス
	CCharDecision_Window* m_pCharDecision;		// キャラ決定のインスタンス
	CFontString* m_pFont;						// フォント
	D3DXVECTOR3 m_pos;							// 位置
	D3DXCOLOR m_Color;							// 色

	std::string m_nLetter[2];

	int		m_nMenuInitiative;					// メニューの主導権
	int		m_nSelectChoice;

	float	m_SizeX;							// Xサイズ
	float	m_SizeY;							// Yサイズ
	float	m_MaxSizeX;							// Xの最大サイズ
	float	m_MaxSizeY;							// Yの最大サイズ
	float	m_fBlinkSpeed;						// 点滅速度

	bool	m_bMaxSize;							// XとYのサイズが最大値まで行ったか
	bool	m_bDisplay;							// 表示中の判定 a
	bool	m_bScale;							// 拡大縮小のフラグ
	bool    m_bDecition;						// 決定されたか
	bool    m_bSpawnWindow;						// ウィンドウが生成されたか
	bool    m_bDicisionCreateFlag;
	bool    m_bWindowUse;

	std::vector<CFontString*> m_vpListChoice;	// 選択肢ポインタの配列
};
#endif