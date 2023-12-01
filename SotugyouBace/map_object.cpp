//==============================================================================================
//
// マップのオブジェクト　　　map_object.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"map_object.h"
#include"objectX.h"

CMap_Object::CMap_Object(const PRIORITY priority) : CMove_Object(priority)
{
}

CMap_Object::~CMap_Object()
{
}

HRESULT CMap_Object::Init()
{
	CMove_Object::Init();

	//SetCollision();

	// 当たり判定のタイプ
	SetCollision_Type(CMove_Object::COLLISION_TYPE_BLOCK);

	return S_OK;
}

void CMap_Object::Uninit()
{
	CMove_Object::Uninit();
}

void CMap_Object::Update()
{
	CMove_Object::Update();
}

void CMap_Object::Draw()
{

}

void CMap_Object::Hit(CMove_Object* pHit)
{

}

CMap_Object *CMap_Object::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, CObjectX* parent, const char* Xfilename, const PRIORITY priority)
{
	CMap_Object *pMap_Object = new CMap_Object(priority);

	if (pMap_Object != nullptr)
	{
		pMap_Object->pMap_ObjectX = CObjectX::Create(pos, rot, parent, Xfilename, priority);
		pMap_Object->SetSize(pMap_Object->pMap_ObjectX->GetMaxSize());
		pMap_Object->SetPos(pos);
		//pMap_Object->SetRadius(100.0f);
		pMap_Object->Init();
	}

	return pMap_Object;
}