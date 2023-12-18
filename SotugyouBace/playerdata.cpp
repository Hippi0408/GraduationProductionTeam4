//=============================================================================
//
// PlayerData.cpp (プレイヤーデータ.cpp)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "application.h"
#include "playerdata.h"
#include "char_select.h"
#include "confirmation_window.h"
#include "charselect_window.h"
#include "chardecision_window.h"
#include "player_manager.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CPlayerData::CPlayerData()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CPlayerData::~CPlayerData()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CPlayerData::Init()
{
	//==================================================
	// メンバ変数の初期化
	//================================================== 
	PlayerIndex = 0;
	m_pPlayerManager = CPlayerManager::Create();				// プレイヤーマネージャーの生成

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CPlayerData::Uninit()
{
	// プレイヤーマネージャーの破棄
	if (m_pPlayerManager != nullptr)
	{
		m_pPlayerManager->Uninit();
		delete m_pPlayerManager;
		m_pPlayerManager = nullptr;
	}
}

//=============================================================================
// 更新処理
//=============================================================================
void CPlayerData::Update()
{
	if (CChar_Select::GetConfimationWindow() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision() != nullptr
		&& CChar_Select::GetConfimationWindow()->GetCharSelect()->GetCharDecision()->GetScaleReduce() == true)
	{// 全ウィンドウのnullチェック && キャラ決定ウィンドウが閉じたら

	 // プレイヤーのジョブ番号
		int nJob_Index = CApplication::GetPlayerJobIndex() % 3;
		m_pPlayerManager->SetPlayer({ 0.0f, 0.0f, 0.0f }, CPlayerManager::TYPE_PC, 0, nJob_Index);
	}
}
