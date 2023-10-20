//=============================================================================
//
// confirmation_window.h (メニューウィンドウ.h)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "confirmation_window.h"
#include "object2D.h"
#include "menu.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CConfirmation_Window::CConfirmation_Window()
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CConfirmation_Window::~CConfirmation_Window()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CConfirmation_Window::Init()
{
	//==================================================
	// メンバ変数の初期化
	//==================================================  
	SizeX = 0.0f;
	SizeY = 0.0f;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_FRONT);
	m_pObject2D->SetCol(D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f));

	//// 選択肢の設定処理
	//CApplication::GetMenu()->SetChoice(CFontString::Create({ 400.0f, 300.0f, 0.0f }, { 40.0f, 40.0f }, "はい"));
	//CApplication::GetMenu()->SetChoice(CFontString::Create({ 800.0f / 2, 400.0f ,0.0f }, { 40.0f, 40.0f }, "いいえ"));

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CConfirmation_Window::Uninit()
{
	//メンバ変数の初期化
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void CConfirmation_Window::Update()
{
	// メニューのサイズ拡大処理
	ConfirmatiomnMenuScale();
}

//=============================================================================
// メニューのサイズ拡大処理
//=============================================================================
void CConfirmation_Window::ConfirmatiomnMenuScale()
{
	if (m_pObject2D != nullptr)
	{// nullチェック
	 // サイズの拡大
		SizeX += SizeXScaleSpeed;
		SizeY += SizeYScaleSpeed;

		if (SizeX >= SizeXScaleMax)
		{// Xサイズの最大
			SizeX = SizeXScaleMax;
		}
		if (SizeY >= SizeYScaleMax)
		{// Yサイズの最大
			SizeY = SizeYScaleMax;
		}

		// ウィンドウが最大値まで行ったら
		if (SizeX >= SizeXScaleMax && SizeY >= SizeYScaleMax)
		{
			CApplication::GetMenu()->SetDisplay(true);		// メニュー画面の表示
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
}

//=============================================================================
// メニューのサイズ縮小処理処理
//=============================================================================
bool CConfirmation_Window::ConfirmatiomnMenuScaleReduce()
{
	if (m_pObject2D != nullptr)
	{// nullチェック
	 // サイズの縮小
		SizeX -= SizeXScaleSpeed;
		SizeY -= SizeYScaleSpeed;

		if (SizeX <= 0.0f)
		{// Xサイズの最小
			SizeX = 0.0f;
		}
		if (SizeY <= 0.0f)
		{// Yサイズの最小
			SizeY = 0.0f;
		}

		// ウィンドウが最小値まで行ったら
		if (SizeX <= 0.0f && SizeY <= 0.0f)
		{
			Uninit();						// メニューウィンドウの削除
			return true;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
	return false;
}

//=============================================================================
// タイムの生成
//=============================================================================
CConfirmation_Window* CConfirmation_Window::Create()
{
	//クラスの生成
	CConfirmation_Window* pMenuWindow = new CConfirmation_Window;

	//nullチェック
	if (pMenuWindow != nullptr)
	{
		//初期化処理
		pMenuWindow->Init();
	}
	else
	{
		assert(false);
	}

	return pMenuWindow;
}