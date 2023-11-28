//=============================================================================
//
// drop_weapon.p
// Author : tutida ryousei
//
//=============================================================================
#include"drop_weapon.h"
#include"drop_manager.h"
#include"objectX.h"
#include"meshfield.h"
#include"tutorial.h"
#include"game.h"
#include"input.h"
#include"object3D.h"
#include"debugProc.h"
#include"application.h"
#include"player_manager.h"
#include"model.h"


const float CDrop_Weapon::PARTS_COLLISION_RADIUS = 150.0f;	// 落ちてる武器の当たり判定の大きさ
const float CDrop_Weapon::PARTS_FLOTIONG_POS = 100.0f;		// 落ちてる武器の浮遊位置

//=============================================================================
// 定義
//=============================================================================
const char* CDrop_Weapon::s_Weapon_FileName[] =
{
	// 腕
	"Data/model/DropParts/SG_01/SG_01_DropArm.x",
	"Data/model/DropParts/SG_02/SG_02_DropArm.x",
	"Data/model/DropParts/SG_03/SG_03_DropArm.x",
	nullptr,

	// 脚
	"Data/model/DropParts/SG_01/SG_01_DropLeg.x",
	"Data/model/DropParts/SG_02/SG_02_DropLeg.x",
	"Data/model/DropParts/SG_03/SG_03_DropLeg.x",
	nullptr,

	// 武器
	"Data/model/SG_01/DummyParent.x",
	"Data/model/Weapon/knife.x",
	"Data/model/Weapon/hammer.x",
	"Data/model/Weapon/scythe.x",
	nullptr,
};

//=============================================================================
// コンストラクタ
//=============================================================================
CDrop_Weapon::CDrop_Weapon(const PRIORITY priority) : CObjectX(priority)
{
	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	// 生成時に自身のポインタを敵キャラマネージャーに設定
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CTutorial::GetDropManager()->SetDrop(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CGame::GetDropManager()->SetDrop(this);
	}
}

//=============================================================================
// デストラクタ
//=============================================================================
CDrop_Weapon::~CDrop_Weapon()
{
	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	// マネージャーが使用中の場合、解放時に自身のポインタを配列から除外する
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CDropManager* pManager = CTutorial::GetDropManager();
		if (pManager != nullptr) pManager->DestroyDrop(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CDropManager* pManager = CGame::GetDropManager();
		if (pManager != nullptr) pManager->DestroyDrop(this);
	}
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CDrop_Weapon::Init()
{
	m_CenterPos = { 0.0f,PARTS_FLOTIONG_POS,0.0f };

	// 角度の設定
	SetRot({ 0.4f,0.0f,0.0f });

	// 落ちてる武器の生成
	//m_pDrop_Weapon->SetSize({ 3.0f,3.0f,3.0f });

	// パーツの部位の設定
	Parts_Type();

	m_bPick_Up = false;
	m_fMove = 0.0f;

	D3DXVECTOR3 ModelPos = GetPos() + m_CenterPos;

	// ピックアップUIの生成
	m_pPick_Up = CObject3D::Create({ ModelPos.x, ModelPos.y + 200.0f, ModelPos.z }, { 70.0f,70.0f }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,1.0f }, true);
	m_pPick_Up->SetDrawFlag(false);

	CObjectX::Init();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CDrop_Weapon::Uninit()
{
	if (m_pPick_Up != nullptr)
	{
		m_pPick_Up->Uninit();
		m_pPick_Up = nullptr;
	}

	CObjectX::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CDrop_Weapon::Update()
{
	CObjectX::Update();

	// 床との当たり判定
	FieldCollision();

	// 角度の加算
	AddRot({ 0.0f,0.03f,0.0f });

	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	CPlayer* pPlayer = nullptr;

	// モード毎にプレイヤーを読み込む
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pPlayer = CTutorial::GetPlayerManager()->GetPlayer(0);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pPlayer = CGame::GetPlayerManager()->GetPlayer(0);
	}

	D3DXVECTOR3 Player_Pos = { 0.0f,0.0f,0.0f };
	D3DXVECTOR3 Mob_Pos = { 0.0f,0.0f,0.0f };

	if (pPlayer != nullptr)
	{
		// 位置の取得
		Player_Pos = pPlayer->GetPos();
		Mob_Pos = GetPos();
	}

	// プレイヤーから落ちてるパーツの距離
	D3DXVECTOR3 Vec = Player_Pos - Mob_Pos;

	// 距離の算出
	float fDistance = sqrtf(Vec.x * Vec.x + Vec.z * Vec.z);

	// 距離7000以上
	if (fDistance > DRAW_DROP_DISTANCE)
		SetDrawFlag(false);
	else
		SetDrawFlag(true);

	// 武器を拾う
	Pick_Up_Weapon();

	// ピックアップ状態をリセットする
	m_bPick_Up = false;
}

//=============================================================================
// 描画処理
//=============================================================================
void CDrop_Weapon::Draw()
{
	CObjectX::Draw();
}

//=============================================================================
// 武器を拾う
//=============================================================================
void CDrop_Weapon::Pick_Up_Weapon()
{
	// ピックアップUIが存在する場合
	if(m_pPick_Up != nullptr)
	{
		// 描画判定
		m_pPick_Up->SetDrawFlag(m_bPick_Up);

		// ピックアップされている場合
		if (m_bPick_Up)
		{
			D3DXVECTOR3 ModelPos = GetPos() + m_CenterPos;

			// 色の設定
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,1.0f });

			m_pPick_Up->SetPos({ ModelPos.x, ModelPos.y + 200.0f, ModelPos.z });
		}
		else
		{
			// 色の設定
			m_pPick_Up->SetCol({ 1.0f,1.0f,1.0f,0.0f });
		}
	}
}

//=============================================================================
// パーツの部位の設定
//=============================================================================
void CDrop_Weapon::Parts_Type()
{
	if (ARMS_MAX > m_nWeapon_Type)
	m_Parts = CPlayer::PARTS_ARMS;
	else if(LEG_MAX > m_nWeapon_Type)
	m_Parts = CPlayer::PARTS_LEG;
	else if (WEAPON_MAX > m_nWeapon_Type)
	m_Parts = CPlayer::PARTS_WEAPON;
}

//=============================================================================
// 床との当たり判定
//=============================================================================
void CDrop_Weapon::FieldCollision()
{
	CMeshField *pMesh = CGame::GetMeshField();

	if (pMesh != nullptr)
	{
		const D3DXVECTOR3 pos = GetPos();
		const D3DXVECTOR3 rot = GetRot();

		// メッシュフィールドとの当たり判定
		float MeshY = pMesh->MeshCollision(pos);

		// メッシュフィールドに乗ってる
		if (pMesh->GetHit())
		{
			m_fMove = 0.0f;
			// 自身の位置
			SetPos({ pos.x, MeshY, pos.z });
		}
		else
		{
			// モデルの位置
			D3DXVECTOR3 Weapon_Pos = pos;
			// 落下速度
			m_fMove += 0.5f;
			// Y座標の移動
			Weapon_Pos.y -= m_fMove;

			// 当たり判定の位置
			SetPos({ Weapon_Pos.x, Weapon_Pos.y, Weapon_Pos.z });
		}
	}
}

//=============================================================================
// 生成処理
//=============================================================================
CDrop_Weapon *CDrop_Weapon::Create(D3DXVECTOR3 pos, int weapon)
{
	CDrop_Weapon *pDrop_Weapon = nullptr;

	pDrop_Weapon = new CDrop_Weapon(PRIORITY_MODEL);

	if (pDrop_Weapon != nullptr)
	{
		pDrop_Weapon->SetPos(pos);
		pDrop_Weapon->SetModel(CApplication::GetModel()->ReadObject(s_Weapon_FileName[pDrop_Weapon->m_nWeapon_Type = weapon]));
		pDrop_Weapon->Init();
	}

	return pDrop_Weapon;
}

//==============================================================================================
// 全てのドロップパーツの読み込み
//==============================================================================================
void CDrop_Weapon::LoadAllFile()
{
	for (int nCnt = 0; nCnt < DROP_PARTS_MAX; nCnt++)
	{
		// 名前が存在する場合
		if (s_Weapon_FileName[nCnt] != nullptr)
		{
			CApplication::GetModel()->ReadObject(s_Weapon_FileName[nCnt]);
		}
	}
}