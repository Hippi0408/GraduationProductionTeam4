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

//==============================================
// 前方宣言
//==============================================
class CObject2D;

//==============================================
// メニューウィンドウクラス
//==============================================
class CConfirmation_Window
{
public:
	const float SizeXScaleSpeed = 11.8f;
	const float SizeYScaleSpeed = 7.5f;
	const float SizeXScaleMax = 500.0f;
	const float SizeYScaleMax = 320.0f;

	CConfirmation_Window();							// メニューウィンドウのコンストラクタ
	~CConfirmation_Window();							// メニューウィンドウのデストラクタ

	HRESULT Init();									// 初期化処理
	void Uninit();									// 終了処理
	void Update();									// 更新処理

	void ConfirmatiomnMenuScale();					// メニューのサイズ処理
	bool ConfirmatiomnMenuScaleReduce();			// メニューのサイズ縮小処理

	static CConfirmation_Window* Create();			// 生成

private:
	CObject2D* m_pObject2D;

	float SizeX;
	float SizeY;

	bool m_bMaxSize;
};
#endif


