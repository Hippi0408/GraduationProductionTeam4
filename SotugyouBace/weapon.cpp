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

	"Data/model/Weapon/knuckle.x",		// ナックル
	"Data/model/Weapon/pilebunker.x",	// パイルバンカー
	"Data/model/Weapon/brandmarkers.x",	// ブランドマーカー
	"Data/model/Weapon/stunbaton.x",	// スタンバトン

	"Data/model/Weapon/samuraiSword.x",	// 太刀
	"Data/model/Weapon/hammer.x",		// ハンマー
	"Data/model/Weapon/beamSword.x",	// ビームサーベル
	"Data/model/Weapon/basterSword.x",	// バスターソード

	"Data/model/Weapon/lance.x",		// ランス
	"Data/model/Weapon/rapier.x",		// レイピア
	"Data/model/Weapon/partisan.x",		// パルチザン
	"Data/model/Weapon/beamjavelin.x",	// ビームジャベリン
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
