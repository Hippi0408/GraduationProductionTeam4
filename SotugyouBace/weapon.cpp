//=============================================================================
//
// weapon.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "weapon.h"
#include "application.h"

const char* CWeapon::m_cWeaponFileName[] =
{
	"Data/model/SG_01/DummyParent.x",
	"Data/model/Weapon/knife.x",
	"Data/model/Weapon/hammer.x",
	"Data/model/Weapon/scythe.x",
};
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
	CObjectX::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CWeapon::Uninit()
{
	CObjectX::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CWeapon::Update()
{
	CObjectX::Update();
}

//============================================================================
// 描画処理
//============================================================================
void CWeapon::Draw()
{
	CObjectX::Draw();
}

//============================================================================
// 武器の変更
//============================================================================
void CWeapon::ChangeWeapon(const int type)
{
	SetModel(CApplication::GetModel()->ReadObject(m_cWeaponFileName[m_nWeaponType = type]));
}

//============================================================================
// 生成処理
//============================================================================
CWeapon* CWeapon::Create(const D3DXVECTOR3 pos, int type, CObjectX* parent)
{
	CWeapon* pParts = new CWeapon;

	if (FAILED(pParts->Init()))
	{
		return nullptr;
	}

	pParts->SetPos(pos);
	pParts->SetType(type);
	pParts->SetParent(parent);

	return pParts;
}
