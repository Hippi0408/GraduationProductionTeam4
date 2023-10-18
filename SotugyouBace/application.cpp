//==============================================================================================
//
// アプリケーション
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================

//**********************************************************************************************
// インクルード
//**********************************************************************************************
#include "application.h"
#include "object.h"
#include "camera.h"
#include "model.h"
#include "light.h"
#include "mode.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "fade.h"
#include "input.h"
#include "menu.h"
#include "title_menu.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "collision_manager.h"
#include "char_select.h"
#include "stage_select.h"
#include <time.h>

#ifdef _DEBUG
#include "debugProc.h"
#endif

//**********************************************************************************************
// 静的メンバ変数の宣言
//**********************************************************************************************
CRenderer* CApplication::m_pRenderer = nullptr;
CApplication::MODE CApplication::m_modeType = MODE_NONE;
CMode* CApplication::m_pGameMode = nullptr;
CTexture* CApplication::m_pTexture = nullptr;
CModel* CApplication::m_pModel = nullptr;
CSound* CApplication::m_pSound = nullptr;
CLight* CApplication::m_pLight = nullptr;
CCamera* CApplication::m_pCamera = nullptr;
CFade* CApplication::m_pFade = nullptr;
CMenu* CApplication::m_pMenu = nullptr;
CPlayerManager* CApplication::m_pPlayerManager = nullptr;
CEnemyManager* CApplication::m_pEnemyManager = nullptr;
CCollision_Manager* CApplication::m_pCollision_Manager = nullptr;

bool CApplication::m_bGameStart = false;
bool CApplication::m_bPauce = false;

#ifdef _DEBUG
CDebugProc *CApplication::m_pDebugProc = nullptr;
#endif
//==============================================================================================
// コンストラクタ
//==============================================================================================
CApplication::CApplication()
{
	m_pInput = nullptr;
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CApplication::~CApplication()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CApplication::Init(HINSTANCE hInstance, HWND hWnd)
{
	// クラスの生成
	m_pRenderer = new CRenderer;				// レンダリング
	m_pTexture = new CTexture;					// テクスチャ
	m_pModel = new CModel;						// モデル
	m_pLight = new CLight;						// ライト
	m_pCamera = new CCamera;					// カメラ
	m_pCollision_Manager = new CCollision_Manager;

	//入力処理
	m_pInput = CInput::Create();
	//入力処理の初期化処理
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{
		return E_FAIL;
	}

	//ウィンドウの設定
	BOOL bWindow = FALSE;

#ifdef _DEBUG
	bWindow = TRUE;
#endif

	m_pRenderer->Init(hWnd, bWindow);				// レンダリング
	m_pLight->Init();							// ライト
	m_pCamera->Init();							// カメラ

	m_pTexture->LoadAll();						// 全てのテクスチャの読み込み

	m_pSound = CSound::Create(hWnd);			// サウンドの生成

	m_pFade = CFade::Create();					// フェード

	m_pPlayerManager = CPlayerManager::Create();	// プレイヤーマネージャーの生成
	m_pEnemyManager = new CEnemyManager;			// 敵キャラマネージャーの生成

	//リリース時はマウスポインターを消す
	m_pInput->SetCursorErase(false);
#ifdef _DEBUG
	m_pDebugProc = CDebugProc::Create();		// デバッグテキスト

	//デバック時はマウスポインターを表示
	m_pInput->SetCursorErase(true);
#endif

	// ゲームモード
	m_modeType = MODE_TITLE;

	// モードの定設
	SetMode(m_modeType);

	srand((unsigned int)time(0));

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CApplication::Uninit()
{
	// 入力処理の終了処理
	m_pInput->Uninit();

	// レンダリングの終了
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	// テクスチャの終了
	if (m_pTexture != nullptr)
	{
		m_pTexture->ReleaseAll();
		delete m_pTexture;
		m_pTexture = nullptr;
	}

	// モデルの終了
	if (m_pModel != nullptr)
	{
		m_pModel->ReleaseAll();
		delete m_pModel;
		m_pModel = nullptr;
	}

	// ライトの終了
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	// カメラの終了
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}

#ifdef _DEBUG
	// デバッグテキストの破棄
	if (m_pDebugProc != nullptr)
	{
		m_pDebugProc->Uninit();
		delete m_pDebugProc;
		m_pDebugProc = nullptr;
	}
#endif

	// フェードの破棄
	if (m_pFade != nullptr)
	{
		m_pFade->Uninit();
		delete m_pFade;
		m_pFade = nullptr;
	}

	// モードの破棄
	if (m_pGameMode != nullptr)
	{
		m_pGameMode->Uninit();
		delete m_pGameMode;
		m_pGameMode = nullptr;
	}

	// メニューの破棄
	if (m_pMenu != nullptr)
	{
		m_pMenu->Uninit();
		delete m_pMenu;
		m_pMenu = nullptr;
	}

	// サウンドの終了
	if (m_pSound != nullptr)
	{
		m_pSound->Uninit();
		delete m_pSound;
		m_pSound = nullptr;
	}

	CObject::ReleaseAll();

	// プレイヤーマネージャーの破棄
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}

	// 敵キャラマネージャーの破棄
	if (m_pEnemyManager != nullptr)
	{
		delete m_pEnemyManager;
		m_pEnemyManager = nullptr;
	}

	// コリジョンマネージャーの破棄
	if (m_pCollision_Manager != nullptr)
	{
		delete m_pCollision_Manager;
		m_pCollision_Manager = nullptr;
	}
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CApplication::Update()
{
	//入力処理の更新処理
	m_pInput->Update();

	// サウンドの更新処理
	m_pSound->Update();

	m_pFade->Update();

	// 使用中のメニュー更新処理
	if (m_pMenu != nullptr)
	{
		m_pMenu->Update();
	}

	m_pRenderer->Update();

	// カメラの更新処理
	m_pCamera->Update();
}

//==============================================================================================
// 描画処理
//==============================================================================================
void CApplication::Draw()
{
	m_pRenderer->Draw();
}

//==============================================================================================
// モードの設定
//==============================================================================================
void CApplication::SetMode(MODE mode)
{
	// ゲーム開始判定を停止させる
	m_bGameStart = false;

	// ゲームモードが使用されている場合の終了処理
	if (m_pGameMode != nullptr)
	{
		// ゲームモードの終了処理
		m_pGameMode->Uninit();
		delete m_pGameMode;
		m_pGameMode = nullptr;

		// メニューの終了処理
		if (m_pMenu != nullptr)
		{
			m_pMenu->Uninit();
			delete m_pMenu;
			m_pMenu = nullptr;
		}

		// プレイヤーマネージャーが使用されている場合
		if (m_pPlayerManager != nullptr)
		{
			m_pPlayerManager->Uninit();
		}

		// 全てのオブジェクトの解放処理
		CObject::ReleaseAll();
	}
	// カメラの初期化
	m_pCamera->Init();

	// 全てのモデル情報の解放処理
	m_pModel->ReleaseAll();

	// モードを切り替える
	m_modeType = mode;

	// 指定のモードの設定
	switch (m_modeType)
	{
	case CApplication::MODE_TITLE:
		m_pGameMode = CTitle::Create();
		m_pMenu = CTitleMenu::Create();
		break;
	/*case CApplication::MODE_CHAR_SELECT:
		m_pGameMode = CChar_Select::Create();
		break;
	case CApplication::MODE_STAGE_SELECT:
		m_pGameMode = CStage_Select::Create();
		break;*/
	case CApplication::MODE_GAME:
		m_pGameMode = CGame::Create();
		break;
	case CApplication::MODE_RESULT:
		m_pGameMode = CResult::Create();
		break;
	default:
		break;
	}
}