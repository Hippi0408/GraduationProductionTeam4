//==============================================================================================
//
// コリジョンマネージャー　　　collision_manager.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"collision_manager.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CCollision_Manager::CCollision_Manager()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CCollision_Manager::~CCollision_Manager()
{
}

//==============================================================================================
// 全ての当たり判定の解放処理
//==============================================================================================
void CCollision_Manager::ReleaseAllCollision()
{
	// 全ての当たり判定のメモリを解放
	for (auto pCollision : m_AllCollision)
	{
		pCollision->Uninit();
		delete pCollision;
	}
	// 全ての当たり判定の情報を解放
	m_AllCollision.clear();
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CCollision_Manager::UpdateAll()
{
	// 全ての当たり判定の更新処理
	for (auto pCollision : m_AllCollision)
	{
		// 死亡フラグが建っていない場合
		if (!pCollision->GetDeath())
		{
			pCollision->Update();
		}
	}

	// 全ての当たり判定の解放判定の処理
	for (auto it = m_AllCollision.begin(); it != m_AllCollision.end();)
	{
		CCollision* pCollision = *it;

		// 死亡フラグが建っている場合
		if (pCollision->GetDeath())
		{
			it = m_AllCollision.erase(it);
			delete pCollision;
		}
		else
		{
			it++;
		}
	}
}