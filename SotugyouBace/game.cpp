//==============================================================================================
//
// ゲーム　　　game.cpp
// tutida ryousei
//
//==============================================================================================
#include "game.h"
#include "application.h"
#include "camera.h"
#include "fade.h"
#include "input.h"
#include "fontString.h"
#include "player_manager.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CGame::CGame()
{
	
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CGame::~CGame()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CGame::Init()
{
	// カメラのポインタ
	CCamera* pCamera = CApplication::GetCamera();

	// 視点、注視点の設定
	pCamera->SetPosV({ 0.0f, 500.0f, -1000.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 1000.0f });

	CFontString::Create({ 515.0f, SCREEN_HEIGHT / 2, 0.0f }, { 50.0f, 50.0f }, "ゲーム");

	// プレイヤーの生成(テスト)
	CApplication::GetPlayerManager()->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0);

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CGame::Uninit()
{

}

//==============================================================================================
//更新処理
//==============================================================================================
void CGame::Update()
{
	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Trigger(DIK_SPACE) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			CFade::SetFade(CApplication::MODE_RESULT, 0.05f);
		}
	}
	// デバッグ専用コマンド
#ifdef _DEBUG
	// 左Shiftキーを押したままの場合
	if (pInput->Press(DIK_LSHIFT))
	{
		int nKey = -1;
		if (pInput->Trigger(DIK_1))
		{
			nKey = 0;
		}
		if (pInput->Trigger(DIK_2))
		{
			nKey = 1;
		}
		if (pInput->Trigger(DIK_3))
		{
			nKey = 2;
		}
		if (pInput->Trigger(DIK_4))
		{
			nKey = 3;
		}

		if (nKey >= 0)
		{
			CPlayerManager* pPlayerManager = CApplication::GetPlayerManager();
			CPlayer* pPlayer = pPlayerManager->GetPlayer(nKey);

			if (pPlayer == nullptr)
			{
				// プレイヤーの生成
				pPlayerManager->SetPlayer({ -300.0f + (200.0f * nKey), 0.0f, 0.0f }, CPlayerManager::TYPE_PC, nKey);
			}
			else
			{
				pPlayerManager->PlayerRelease(nKey);
			}
		}
	}
#endif
}

//==============================================================================================
// 生成処理
//==============================================================================================
CGame* CGame::Create()
{
	CGame* pGame = new CGame;

	if (FAILED(pGame->Init()))
	{
		return nullptr;
	}

	return pGame;
}