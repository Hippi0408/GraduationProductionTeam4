//==============================================================================================
//
// プレイヤーの管理　　　player_manager.cpp
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#include "player_manager.h"
#include "pc.h"
#include "cpu.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CPlayerManager::CPlayerManager()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CPlayerManager::~CPlayerManager()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CPlayerManager::Init()
{
	// 全てのキャラクターの初期化処理
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		m_pPlayer[nCnt] = nullptr;
	}

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CPlayerManager::Uninit()
{
	PlayerReleaseAll();
}

//==============================================================================================
// 全てのプレイヤーを終了させる処理
//==============================================================================================
void CPlayerManager::PlayerReleaseAll()
{
	// 全てのプレイヤーの終了処理
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		if (m_pPlayer[nCnt] != nullptr)
		{
			m_pPlayer[nCnt]->Uninit();
			m_pPlayer[nCnt] = nullptr;
		}
	}
}

//==============================================================================================
// 指定のプレイヤーを終了させる処理
//==============================================================================================
void CPlayerManager::PlayerRelease(const int index)
{
	// 全てのプレイヤーの終了処理
	if (m_pPlayer[index] != nullptr)
	{
		m_pPlayer[index] = nullptr;
	}
}

//==============================================================================================
// キャラ設定処理
//==============================================================================================
CPlayer* CPlayerManager::SetPlayer(const D3DXVECTOR3 pos, const Chara_Type type, const int index)
{
	// キャラクターが使用中では無い場合
	if (m_pPlayer[index] == nullptr)
	{
		// キャラクターの種類毎の生成
		switch (type)
		{
		case TYPE_PC:
			m_pPlayer[index] = CPC::Create(pos, index);
			break;
		case TYPE_CPU:
			m_pPlayer[index] = CCPU::Create(pos, index);
			break;
		default:
			break;
		}

		// 生成したキャラクターのポインタを返す
		return m_pPlayer[index];
	}
	return nullptr;
}

//==============================================================================================
// プレイヤーマネージャーの生成
//==============================================================================================
CPlayerManager* CPlayerManager::Create()
{
	CPlayerManager* pPlayerManager = new CPlayerManager;

	if (FAILED(pPlayerManager->Init()))
	{
		return nullptr;
	}

	return pPlayerManager;
}