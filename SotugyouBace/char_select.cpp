//==============================================================================================
//
// キャラクターセレクト　　　char_select.cpp
// tutida ryousei
//
//==============================================================================================
#include"char_select.h"
#include"input.h"
#include"application.h"
#include"fade.h"
#include"fontString.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CChar_Select::CChar_Select()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CChar_Select::~CChar_Select()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CChar_Select::Init()
{
	CFontString::Create({ 280.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "キャラクターセレクト");

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CChar_Select::Uninit()
{

}

//==============================================================================================
// 更新処理
//==============================================================================================
void CChar_Select::Update()
{
	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			CFade::SetFade(CApplication::MODE_STAGE_SELECT, 0.05f);
		}

		// キャラセレクト画面に戻る
		if (pInput->Trigger(DIK_BACK, nCnt)
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			// 画面遷移
			CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
		}
	}
}

//==============================================================================================
// 生成処理
//==============================================================================================
CChar_Select* CChar_Select::Create()
{
	CChar_Select* pChar_Select = new CChar_Select;

	if (FAILED(pChar_Select->Init()))
	{
		return nullptr;
	}

	return pChar_Select;
}
