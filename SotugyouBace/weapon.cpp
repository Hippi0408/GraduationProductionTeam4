//=============================================================================
//
// weapon.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "weapon.h"
#include "application.h"
#include "character.h"

//=====================================
// デフォルトコンストラクタ
//=====================================
CWeapon::CWeapon(const CObject::PRIORITY priority) : CObjectX(priority)
{

}

//=====================================
// デストラクタ
//=====================================
CWeapon::~CWeapon()
{
}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CWeapon::Init()
{
	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CWeapon::Uninit()
{
	Release();
}

//============================================================================
// 更新処理
//============================================================================
void CWeapon::Update()
{
}

//============================================================================
// 描画処理
//============================================================================
void CWeapon::Draw()
{

}

//============================================================================
// 生成処理
//============================================================================
CWeapon* CWeapon::Create(const D3DXVECTOR3 pos, const int partsIndex, CObjectX* parent)
{
	CWeapon* pParts = new CWeapon;

	if (FAILED(pParts->Init()))
	{
		return nullptr;
	}

	pParts->SetPos(pos);
	pParts->SetParts(partsIndex);
	pParts->SetParent(parent);

	return pParts;
}
