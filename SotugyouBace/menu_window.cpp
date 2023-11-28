//=============================================================================
//
// menu_window.h (メニューウィンドウ.h)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "menu_window.h"
#include "object2D.h"
#include "menu.h"
#include "title.h"
#include "title_menu.h"
#include "confirmation_window.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CMenuWindow::CMenuWindow()
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CMenuWindow::~CMenuWindow()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CMenuWindow::Init()
{
	//==================================================
	// メンバ変数の初期化
	//==================================================  
	SizeX = 0.0f;
	SizeY = 0.0f;
	m_bScaleFlag = false;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 450.0f, 0.0f), D3DXVECTOR2(0.0f, 0.0f),CObject::PRIORITY_FRONT);
	m_pObject2D->SetCol(D3DXCOLOR(0.5f, 0.5f, 1.0f, 1.0f));

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CMenuWindow::Uninit()
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
void CMenuWindow::Update()
{
	if (CTitle::GetUninitWindow() == false && m_bScaleFlag == false)
	{ // メニューのサイズ拡大処理
		MenuScale();
	}
}

//=============================================================================
// メニューのサイズ拡大処理
//=============================================================================
void CMenuWindow::MenuScale()
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
			CTitle::SetWindow(true);						// ウィンドウを使用している状態にする
			m_bScaleFlag = true;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
}

//=============================================================================
// メニューのサイズ縮小処理処理
//=============================================================================
bool CMenuWindow::MenuScaleReduce()
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
			CTitleMenu::GetComfirmationWindow()->SetSapawnWindow(false);
			if (CTitleMenu::GetComfirmationWindow()->GetSelectChoice() == true)
			{
				DestroyWindow(CApplication::GetWindow());
			}
		
			//Uninit();						// メニューウィンドウの削除
			CTitle::UninitMenuWindow();
			CTitleMenu::UninitComfirmationWindow();
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
CMenuWindow* CMenuWindow::Create()
{
	//クラスの生成
	CMenuWindow* pMenuWindow = new CMenuWindow;

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