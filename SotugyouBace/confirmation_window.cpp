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
#include "fade.h"
#include "input.h"
#include "game.h"
#include "title.h"
#include "menu_window.h"
#include "title_menu.h"
#include "charselect_window.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
CCharSelect_Window* CConfirmation_Window::m_pCharSelectWindow = nullptr;
const float CConfirmation_Window::BLINK_SPEED = 0.02f;	// 選択肢の点滅速度
const float CConfirmation_Window::MINI_ALPHA = 0.5f;	// 選択肢の最低透明値

//=============================================================================
// コンストラクタ
//=============================================================================
CConfirmation_Window::CConfirmation_Window() : m_bSelectChoice(1), m_fBlinkSpeed(BLINK_SPEED)
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
	m_bScale = false;
	m_bMaxSize = false;
	m_bUninitFlag = false;
	m_bSpawnWindow = false;
	m_bSelectChoice = false;
	m_bDecition = false;
	m_pObject2D = CObject2D::Create(D3DXVECTOR3(m_pos.x, m_pos.y, 0.0f), D3DXVECTOR2(0.0f, 0.0f), CObject::PRIORITY_SCREEN);
	m_pObject2D->SetCol(D3DXCOLOR(m_Color.r, m_Color.g, m_Color.b, m_Color.a));

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CConfirmation_Window::Uninit()
{
	//メンバ変数の破棄
	if (m_pObject2D != nullptr)
	{
		m_pObject2D->Uninit();
		m_pObject2D = nullptr;
	}

	// キャラ選択画面の破棄
	if (m_pCharSelectWindow != nullptr)
	{
		m_pCharSelectWindow->Uninit();
		delete m_pCharSelectWindow;
		m_pCharSelectWindow = nullptr;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void CConfirmation_Window::Update()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	if (m_bScale == false)
	{// 拡大されていない時

		// ウィンドウの拡大処理
		ConfirmatiomnMenuScale();
	}
	else
	{// 拡大した時

		// ウィンドウの縮小処理
		ConfirmatiomnMenuScaleReduce();
	}

	// 選択肢処理
	Choice();
}

//=============================================================================
// メニューのサイズ拡大処理
//=============================================================================
void CConfirmation_Window::ConfirmatiomnMenuScale()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	if (m_pObject2D != nullptr)
	{// nullチェック

		// サイズの拡大
		SizeX += SizeXScaleSpeed;
		SizeY += SizeYScaleSpeed;

		if (SizeX >= MaxSizeX)
		{// Xサイズの最大
			SizeX = MaxSizeX;
		}
		if (SizeY >= MaxSizeY)
		{// Yサイズの最大
			SizeY = MaxSizeY;
		}

		// ウィンドウが最大値まで行ったら
		if (SizeX >= MaxSizeX && SizeY >= MaxSizeY && m_bMaxSize == false)
		{
			// ゲームモードの取得
			CApplication::MODE Mode = CApplication::GetModeType();

			if (Mode == CApplication::MODE_TITLE || Mode == CApplication::MODE_GAME)
			{ // タイトルかゲーム画面だったら
				
				// 文字の生成
				if (m_pFont == nullptr)
				{
					m_pFont = CFontString::Create({ 420.0f, 350.0f, 0.0f }, { 30.0f, 30.0f }, "やめますか?");
				}

				// 選択肢の生成
				SetChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "はい"));
				SetChoice(CFontString::Create({ 700.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "いいえ"));
			}
			else if(Mode == CApplication::MODE_CHAR_SELECT)
			{ // キャラ選択画面だったら

				// 選択肢の生成
				SetChoice(CFontString::Create({ 400.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "ストライカー"));
				SetChoice(CFontString::Create({ 700.0f, 450.0f, 0.0f }, { 25.0f, 25.0f }, "コマンダー"));
			}

			// 選択肢が使用されている場合
			if (!m_vpListChoice.empty())
			{
				for (auto pChoice : GetChoiceAll())
				{
					pChoice->SetAlpha(MINI_ALPHA);
				}
				// 選択されている選択肢
				m_vpListChoice[m_bSelectChoice]->SetBlink(BLINK_SPEED);
				m_vpListChoice[m_bSelectChoice]->SetAlpha(1.0f);
			}

			SetDisplay(true);		// 選択肢の表示判定を使用
			m_bMaxSize = true;		// 最大サイズに到達
			return;
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

	 // 現在のモード
		CApplication::MODE Mode = CApplication::GetModeType();

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

		// フォントの削除
		if (m_pFont != nullptr)
		{
			m_pFont->Uninit();
			m_pFont = nullptr;
		}

		// ウィンドウが最小値まで行ったら
		if (SizeX <= 0.0f && SizeY <= 0.0f)
		{
			// ゲーム終了
			if (m_bSelectChoice == true && Mode == CApplication::MODE_GAME)
			{
				m_bUninitFlag = true;							// ゲーム内ウィンドウの破棄
				m_bSpawnWindow = true;							// メニューウィンドウの破棄
				DestroyWindow(CApplication::GetWindow());		// ウィンドウの破棄
			}
			else if (m_bSelectChoice == false && Mode == CApplication::MODE_GAME)
			{
				m_bUninitFlag = true;							// ゲーム内ウィンドウの破棄
				m_bSpawnWindow = true;							// メニューウィンドウの破棄
				m_bScale = false;								// 拡大縮小フラグを初期化			
				Uninit();										// メニューウィンドウの削除			
			}
			if (Mode == CApplication::MODE_TITLE)
			{
				m_bScale = false;								// 拡大縮小フラグを初期化	
				m_bSpawnWindow = true;							// メニューウィンドウの破棄
				Uninit();										// メニューウィンドウの削除
			}
			return true;
		}

		// サイズの設定
		m_pObject2D->SetSize(D3DXVECTOR2(SizeX, SizeY));
	}
	return false;
}

//============================================================================
// 選択肢の処理
//============================================================================
void CConfirmation_Window::Choice()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();
	
	// フェード中では無い場合 && 表示中の場合
	if (CApplication::GetFade()->GetFade() == CFade::FADE_NONE && m_bDisplay == true)
	{
		// 選択肢が使用されている場合
		if (!m_vpListChoice.empty())
		{
			// 選択肢が2つ以上使用されている場合
			if (m_vpListChoice.size() >= 2)
			{
				// 上に移動する
				if (pInput->Trigger(DIK_A) || (pInput->Trigger(JOYPAD_UP, m_nMenuInitiative)))
				{
					// 選択SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// 現在の番号が0以下である場合
					ChangeChoice(false);
				}
				// 下に移動する
				else if (pInput->Trigger(DIK_D) || (pInput->Trigger(JOYPAD_DOWN, m_nMenuInitiative)))
				{
					// 選択SE
					CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_SELECT);

					// 現在の番号が最大数以上の場合
					ChangeChoice(true);
				}
			}

			if (pInput->Trigger(DIK_RETURN) || (pInput->Trigger(JOYPAD_B, m_nMenuInitiative) || pInput->Trigger(JOYPAD_A, m_nMenuInitiative)))
			{
				// 決定SE
				CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

				// 選択を決定する
				m_bDecition = true;
			}
			// 決定された場合
			if (m_bDecition == true)
			{
				// 左の選択肢の場合
				if (m_bSelectChoice == false)
				{
					CreateCharSelect();			// キャラ選択画面の生成
					m_bScale = true;			// 拡大縮小フラグが使われている
					SetDisplay(false);			// 選択肢の表示判定を使用していない状態にする
					m_bSelectChoice = true;		// 左の選択肢を選んだ
				}
				// 右の選択肢の場合
				else
				{
					CreateCharSelect();			// キャラ選択画面の生成
					m_bScale = true;            // 拡大縮小フラグが使われている
					SetDisplay(false);			// 選択肢の表示判定を使用していない状態にする
					m_bSelectChoice = false;    // 左の選択肢を選んだ
				}
			}
		}
	}

	// nullチェック
	if (m_pCharSelectWindow != nullptr)
	{ 
		// キャラ選択ウィンドウの更新処理
		m_pCharSelectWindow->Update();
	}

	// キャラ選択ウィンドウが閉じた場合 
	if (m_pCharSelectWindow != nullptr && m_pCharSelectWindow->GetSapawnWindow() == true)
	{
		// キャラ選択画面の破棄
		m_pCharSelectWindow->SetSapawnWindow(false);	// ウィンドウの生成フラグを初期化
		delete m_pCharSelectWindow;
		m_pCharSelectWindow = nullptr;
	}

	// メニューウィンドウが閉じた時
	if (m_bSpawnWindow == true && CTitle::GetMenuWindow() != nullptr)
	{
		CApplication::GetMenu()->SetDisplay(false);		// 文字を消す
		CTitle::GetMenuWindow()->MenuScaleReduce();		// ゲーム開閉時のウィンドウの縮小
	}
}

//============================================================================
// 選択肢を変更した時の処理
//============================================================================
void CConfirmation_Window::ChangeChoice(const bool nextChoice)
{
	// 現在の選択肢の処理
	m_vpListChoice[m_bSelectChoice]->BlinkFinish();
	m_vpListChoice[m_bSelectChoice]->SetAlpha(MINI_ALPHA);

	// 選択肢の変更
	m_bSelectChoice = (int)nextChoice;

	// 変更後の選択肢の処理
	m_vpListChoice[m_bSelectChoice]->SetBlink(m_fBlinkSpeed);
	m_vpListChoice[m_bSelectChoice]->SetAlpha(1.0f);
}

//============================================================================
// 選択肢の表示判定を設定する
//============================================================================
void CConfirmation_Window::SetDisplay(const bool decition)
{
	m_bDisplay = decition;
	for (auto pChoice : GetChoiceAll()) { pChoice->SetFontDraw(decition); }

	// 表示を消す場合
	if (decition == false)
	{
		// 選択肢の情報を初期化する
		ChangeChoice(0);
	}
}

//=============================================================================
// キャラ選択画面の生成
//=============================================================================
void CConfirmation_Window::CreateCharSelect()
{
	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();		

	if (Mode == CApplication::MODE_CHAR_SELECT)
	{ // キャラ選択宅画面だったら

		// nullチェック
		if (m_pCharSelectWindow == nullptr)
		{
			// キャラ選択ウィンドウの生成
			m_pCharSelectWindow = CCharSelect_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 400.0f, 0.0f), 900.0f, 500.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
		}
	}
}

//=============================================================================
// メニューの生成
//=============================================================================
CConfirmation_Window* CConfirmation_Window::Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col)
{
	//クラスの生成
	CConfirmation_Window* pMenuWindow = new CConfirmation_Window;

	//nullチェック
	if (pMenuWindow != nullptr)
	{
		// 設定処理
		pMenuWindow->m_pos = pos;
		pMenuWindow->m_Color = col;
		pMenuWindow->MaxSizeX = xsize;
		pMenuWindow->MaxSizeY = ysize;
		// 初期化処理
		pMenuWindow->Init();
	}
	else
	{
		assert(false);
	}

	return pMenuWindow;
}