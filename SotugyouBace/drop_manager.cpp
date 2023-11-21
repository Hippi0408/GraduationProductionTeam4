//=============================================================================
//
// 落とし物の管理　　　drop_manager.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "drop_manager.h"

//=====================================
// デフォルトコンストラクタ
//=====================================
CDropManager::CDropManager()
{
}

//=====================================
// デストラクタ
//=====================================
CDropManager::~CDropManager()
{
	// 全ての落とし物の解放
	m_AllDrop.clear();
}