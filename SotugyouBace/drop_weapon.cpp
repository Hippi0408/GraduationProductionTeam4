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

const float CDrop_Weapon::PARTS_COLLISION_RADIUS = 30.0f;	// ボスの当たり判定の大きさ
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

	// 当たり判定の生成
	SetCollision();

	// 落ちてる武器の種類
	m_pDrop_Weapon = CObjectX::Create(GetCenterPos(), { 0.0f,0.0f,0.0f }, nullptr, m_Weapon_Type.pXFileName);

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
		float MeshY = pMesh->MeshCollision(GetPos());

		if (pMesh->GetHit())
		{
			SetPos({ GetCenterPos().x, MeshY, GetCenterPos().z });
			m_pDrop_Weapon->SetPos(GetCenterPos());
		}
	}
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
	// 当たり判定とモデルを消す
	Uninit();
	m_pDrop_Weapon->Uninit();
}

//=============================================================================
// 生成処理
//=============================================================================
CDrop_Weapon *CDrop_Weapon::Creat(D3DXVECTOR3 pos, char *xfilename)
{
	CDrop_Weapon *pDrop_Weapon = nullptr;

	pDrop_Weapon = new CDrop_Weapon(PRIORITY_MODEL);

	if (pDrop_Weapon != nullptr)
	{
		pDrop_Weapon->SetPos(pos);
		pDrop_Weapon->SetFileName(xfilename);
		pDrop_Weapon->Init();
	}

	return pDrop_Weapon;
}