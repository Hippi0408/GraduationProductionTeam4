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
	static const float BLINK_SPEED;		// 選択肢の点滅速度
	static const float MINI_ALPHA;		// 選択肢の最低透明値
	const float SizeXScaleSpeed = 11.8f;
	const float SizeYScaleSpeed = 7.5f;
	const float SizeXScaleMax = 500.0f;
	const float SizeYScaleMax = 320.0f;

	CConfirmation_Window();							// メニューウィンドウのコンストラクタ
	~CConfirmation_Window();						// メニューウィンドウのデストラクタ

	HRESULT Init();									// 初期化処理
	void Uninit();									// 終了処理
	void Update();									// 更新処理

	void ConfirmatiomnMenuScale();					// メニューのサイズ処理
	bool ConfirmatiomnMenuScaleReduce();			// メニューのサイズ縮小処理

	virtual void Choice();						// 選択肢の処理
	void ChangeChoice(const bool nextChoice);	// 選択肢を変更した時の処理
	void SetDisplay(const bool display);		// 選択肢の表示判定を設定する
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }

	int GetSelect() { return m_bSelectChoice; }

	bool GetFlag() { return m_bflag; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

	static CConfirmation_Window* Create();			// 生成

private:
	CObject2D* m_pObject2D;

	float SizeX;
	float SizeY;

	bool m_bMaxSize;
	bool m_bflag;

	int		m_nMenuInitiative;					// メニューの主導権
	bool	m_bSelectChoice;					// 選択肢の番号
	float	m_fBlinkSpeed;						// 点滅速度
	bool	m_bDisplay;							// 表示中の判定
	bool	m_bScale;


	std::vector<CFontString*> m_vpListChoice;	// 選択肢ポインタの配列
};
#endif


