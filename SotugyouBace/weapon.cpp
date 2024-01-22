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

	"Data/model/Weapon/Melee_Weapon/knuckle.x",			// ナックル
	"Data/model/Weapon/Melee_Weapon/pilebunker.x",		// パイルバンカー
	"Data/model/Weapon/Melee_Weapon/brandmarkers.x",	// ブランドマーカー
	"Data/model/Weapon/Melee_Weapon/stunbaton.x",		// スタンバトン

	"Data/model/Weapon/Melee_Weapon/samuraiSword.x",		// 太刀
	"Data/model/Weapon/Melee_Weapon/hammer.x",			// ハンマー
	"Data/model/Weapon/Melee_Weapon/beamSword.x",		// ビームサーベル
	"Data/model/Weapon/Melee_Weapon/basterSword.x",		// バスターソード

	"Data/model/Weapon/Melee_Weapon/lance.x",			// ランス
	"Data/model/Weapon/Melee_Weapon/rapier.x",			// レイピア
	"Data/model/Weapon/Melee_Weapon/partisan.x",		// パルチザン
	"Data/model/Weapon/Melee_Weapon/beamjavelin.x",		// ビームジャベリン
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
	SetModel(CApplication::GetModel()->ReadObject(m_cWeaponFileName[type]));
}

//============================================================================
// 生成処理
//============================================================================
CWeapon* CWeapon::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, int type, CObjectX* parent)
{
	CWeapon* pParts = new CWeapon;

	if (FAILED(pParts->Init()))
	{
		return nullptr;
	}

	pParts->SetPos(pos);
	pParts->SetRot(rot);
	pParts->ChangeWeapon(type);
	pParts->SetParent(parent);

	return pParts;
}
