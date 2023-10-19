//=============================================================================
//
// タイトルメニュー
// title_menu.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
//*****************************************************************************
// インクルード
//*****************************************************************************
#include "title_menu.h"
#include "Application.h"
#include "input.h"
#include "fade.h"
#include "title.h"

//=====================================
// コンストラクタ
//=====================================
CTitleMenu::CTitleMenu()
{
}

//=====================================
// デストラクタ
//=====================================
CTitleMenu::~CTitleMenu()
{

}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CTitleMenu::Init()
{
	// 選択肢の設定処理
	SetChoice(CFontString::Create({ 400.0f, 300.0f, 0.0f}, { 40.0f, 40.0f }, "ゲームをはじめる"));
	SetChoice(CFontString::Create({ 800.0f / 2, 400.0f ,0.0f }, { 40.0f, 40.0f }, "チュートリアル"));
	SetChoice(CFontString::Create({ 800.0f / 2, 500.0f ,0.0f }, { 40.0f, 40.0f }, "とじる"));

	//GetChoice(Choice_GameStart)->SetPos({ SCREEN_WIDTH / 2 - 200, 400.0f, 0.0f });

	// 全ての選択肢を表示する
	for (auto pChoice : GetChoiceAll())
	{
		pChoice->SetFontDraw(false);
	}

	// メニューの初期化処理
	CMenu::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CTitleMenu::Uninit()
{
	// メニューの終了処理
	CMenu::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CTitleMenu::Update()
{
	// メニューの更新処理
	CMenu::Update();

	// 選択肢の処理
	Choice();
}

//============================================================================
// 選択肢の処理
//============================================================================
void CTitleMenu::Choice()
{
	// メニューの選択肢の処理
	CMenu::Choice();

	// 決定された場合
	if (GetDecition() == true)
	{
		// 現在選択されている選択肢の処理を読み込む
		switch ((Choice_Type)GetSelectChoice())
		{
			// ゲームスタート
		case Choice_GameStart:
			// 決定SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);
			// ゲームに飛ぶ
			CFade::SetFade(CApplication::MODE_GAME, 0.05f);
			CTitle::SetUninitWindow(false);
			break;

			// チュートリアル
		case Choice_Tutorial:
			// 決定SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);
			//// チュートリアル画面に飛ぶ
			//CFade::SetFade(CApplication::MODE_ENTRY, 0.05f);
			break;

			// ウィンドウを閉じる
		case Choice_Window_Exit:
			// 決定SE
			CApplication::GetSound()->Play(CSound::SOUND_LABEL_SE_YES);

			// 表示判定を偽にする
			SetDisplay(false);
			break;
		default:
			break;
		}
	}
	// 決定を破棄する
	SetDecition(false);
}

//============================================================================
// 生成処理
//============================================================================
CTitleMenu* CTitleMenu::Create()
{
	CTitleMenu* pTitleMenu = new CTitleMenu;

	if (FAILED(pTitleMenu->Init()))
	{
		return nullptr;
	}

	return pTitleMenu;
}
