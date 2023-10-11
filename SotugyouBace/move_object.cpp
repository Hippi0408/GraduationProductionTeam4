//==============================================================================================
//
// 動くオブジェクト　　　move_object.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"move_object.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CMove_Object::CMove_Object(const PRIORITY priority) : CObject(priority)
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CMove_Object::~CMove_Object()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CMove_Object::Init()
{
	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CMove_Object::Uninit()
{
	if (m_pCollision != nullptr)
	{
		m_pCollision->SetCollision_Death(true);
		m_pCollision->Uninit();
		m_pCollision = nullptr;
	}
}