//=============================================================================
//
// drop_weapon.p
// Author : tutida ryousei
//
//=============================================================================
#include"drop_weapon.h"
#include"objectX.h"
#include"meshfield.h"
#include"game.h"
#include"input.h"
#include"object3D.h"

const float CDrop_Weapon::PARTS_COLLISION_RADIUS = 150.0f;	// 落ちてる武器の当たり判定の大きさ

//=============================================================================
// 定義
//=============================================================================
const char* CDrop_Weapon::s_Weapon_FileName[] =
{// 武器モデルのパス
	"Data/model/Weapon/hammer.x",
	"Data/model/Weapon/knife.x",
	"Data/model/Weapon/scythe.x"
};

//=============================================================================
// コンストラクタ
//=============================================================================
CDrop_Weapon::CDrop_Weapon(const PRIORITY priority) : CMove_Object(priority)
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CDrop_Weapon::~CDrop_Weapon()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CDrop_Weapon::Init()
{
	SetRadius(PARTS_COLLISION_RADIUS);
	SetCenterPos({ 0.0f,100.0f,0.0f });

	// 当たり判定の生成
	SetCollision();

	// 落ちてる武器の生成
	m_pDrop_Weapon = CObjectX::Create(GetCenterPos(), { 0.0f,0.0f,0.0f }, nullptr, s_Weapon_FileName[m_nWeapon_Type]);
	m_pDrop_Weapon->SetSize({ 3.0f,3.0f,3.0f });

	m_bPick_Up = false;
	m_fMove = 0.0f;

	CMove_Object::Init();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CDrop_Weapon::Uninit()
{
	CMove_Object::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CDrop_Weapon::Update()
{
	CMeshField *pMesh = CGame::GetMeshField();

	if (pMesh != nullptr)
	{
		// メッシュフィールドとの当たり判定
		float MeshY = pMesh->MeshCollision(GetPos());

		// メッシュフィールドに乗ってる
		if (pMesh->GetHit())
		{
			// 当たり判定の位置
			SetPos({ GetCenterPos().x, MeshY, GetCenterPos().z });
			// モデルの位置
			m_pDrop_Weapon->SetPos({ GetCenterPos().x, GetCenterPos().y + MeshY, GetCenterPos().z });
		}
		else
		{
			// モデルの位置
			D3DXVECTOR3 Weapon_Pos = m_pDrop_Weapon->GetPos();
			// 落下速度
			m_fMove += 0.5f;
			// Y座標の移動
			Weapon_Pos.y -= m_fMove;
			
			// 当たり判定の位置
			SetPos(Weapon_Pos);
			// モデルの位置
			m_pDrop_Weapon->SetPos(Weapon_Pos);
		}
	}

	// 武器を拾う
	Pick_Up_Weapon();

	// 回転速度
	m_fRot += 0.03f;
	// 角度の設定
	m_pDrop_Weapon->SetRot({ 0.4f,m_fRot,0.0f });

	m_bPick_Up = false;
}

//=============================================================================
// 描画処理
//=============================================================================
void CDrop_Weapon::Draw()
{
}

//=============================================================================
// ヒット
//=============================================================================
void CDrop_Weapon::Hit(CMove_Object* pHit)
{
	// プレイヤー側の場合
	if (pHit != nullptr && pHit->GetPlayerSide())
	{
		TAG tag = pHit->GetTag();

		switch (tag)
		{
		case TAG_CHARACTER:
			m_bPick_Up = true;
			break;
		case TAG_BULLET:
			break;
		default:
			break;
		}
	}
}

//=============================================================================
// 武器を拾う
//=============================================================================
void CDrop_Weapon::Pick_Up_Weapon()
{
	//入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	if (m_pPick_Up == nullptr)
		m_pPick_Up = CObject3D::Create({ GetCenterPos().x,GetCenterPos().y + 200.0f,GetCenterPos().z }, { 70.0f,70.0f }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,1.0f }, true);

	if(m_pPick_Up != nullptr)
	{
		if (m_bPick_Up)
		{
			// 色の設定
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,1.0f });

			m_pPick_Up->SetPos({ GetCenterPos().x,GetCenterPos().y + 200.0f,GetCenterPos().z });

			// 拾う
			if (pInput->Trigger(DIK_E))
			{
				// 終了処理
				Uninit();
				m_pDrop_Weapon->Uninit();
				m_pPick_Up->Uninit();
			}
		}
		else
			// 色の設定
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,0.0f });
	}
}

//=============================================================================
// 生成処理
//=============================================================================
CDrop_Weapon *CDrop_Weapon::Creat(D3DXVECTOR3 pos, int weapon)
{
	CDrop_Weapon *pDrop_Weapon = nullptr;

	pDrop_Weapon = new CDrop_Weapon(PRIORITY_MODEL);

	if (pDrop_Weapon != nullptr)
	{
		pDrop_Weapon->SetPos(pos);
		pDrop_Weapon->SetWeapon_Type(weapon);
		pDrop_Weapon->Init();
	}

	return pDrop_Weapon;
}