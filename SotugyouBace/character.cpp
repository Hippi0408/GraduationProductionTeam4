//=============================================================================
//
// character.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "character.h"
#include "application.h"
#include "game.h"
#include "meshfield.h"
#include "tutorial.h"
#include "gauge_manager.h"

const float CCharacter::CHARACTER_FIRST_MOVE_SPEED = 10.0f;
const float CCharacter::CHARACTER_ROT_SPEED = 0.1f;
const float CCharacter::CHARACTER_MOVE_INERTIE = 0.2f;
const float CCharacter::CHARACTER_GRAVITY = 0.25f;

//=====================================
// デフォルトコンストラクタ
//=====================================
CCharacter::CCharacter(const CObject::PRIORITY priority) : CMove_Object(priority)
{
	// タグの設定
	SetTag(TAG_CHARACTER);

	m_fSpeed = CHARACTER_FIRST_MOVE_SPEED;
	m_fRotSpeed = CHARACTER_ROT_SPEED;
	m_bGround = false;
	m_bBoost = false;
}

//=====================================
// デストラクタ
//=====================================
CCharacter::~CCharacter()
{
}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CCharacter::Init()
{
	m_move = { 0.0f, 0.0f, 0.0f };

	CMove_Object::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CCharacter::Uninit()
{
	// パーツの終了処理
	for (int nCnt = 0; nCnt < (int)m_Parts.size(); nCnt++)
	{
		if (m_Parts[nCnt] != nullptr)
		{
			m_Parts[nCnt]->Uninit();
			m_Parts[nCnt] = nullptr;
		}
	}

	// ゲージが使用中の場合
	if (m_pGaugeManager != nullptr)
	{
		m_pGaugeManager->Uninit();
		m_pGaugeManager = nullptr;
	}

	m_Parts.clear();

	CMove_Object::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CCharacter::Update()
{
	// 移動量の処理
	Move();

	// 角度の正規化
	NormalizeRot();

	// 床の当たり判定
	FieldCollision();
}

//============================================================================
// 描画処理
//============================================================================
void CCharacter::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//計算用のマトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, GetPos().x, GetPos().y, GetPos().z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);
}

//==============================================================================================
// 移動処理
//==============================================================================================
void CCharacter::Move()
{
	if (!m_bAvoidance)
		// 移動量を更新(減衰させる)
		m_move -= m_move * CHARACTER_MOVE_INERTIE;
	else
	{
		m_move -= m_move * 0.05f;

		m_nAvoidance_Count--;
		if (m_nAvoidance_Count <= 0)
			m_bAvoidance = false;
	}

	// 位置更新
	AddPos(m_move * m_fSpeed);
}

//==============================================================================================
// ダメージ処理(与ダメージ)
//==============================================================================================
void CCharacter::Damage(const int value)
{
	// ベースの体力の設定
	if (m_pGaugeManager != nullptr
		&& m_pGaugeManager->GetBeaseLife() == 0)
	{
		m_pGaugeManager->SetBeaseLife(m_nLife);
	}

	// 体力 - 与ダメージ
	m_nLife -= value;

	// 体力ゲージの増減
	if (m_pGaugeManager != nullptr)
	{
		m_pGaugeManager->SetLife(m_nLife);
		m_pGaugeManager->Fluctuation();
	}

	// 体力チェック
	if (m_nLife <= 0)
	{
		// 体力を0にする
		m_nLife = 0;

		// 自身を破壊する処理
		Destroy();
	}
}

//==============================================================================================
// 回復処理(回復量)
//==============================================================================================
void CCharacter::Recovery(const int value)
{
	// 体力 + 回復量
	m_nLife += value;

	// 体力チェック
	if (m_nLife > m_nMaxLife)
	{
		// 体力の最大値を超えないようにする
		m_nLife = m_nMaxLife;
	}

	// 体力ゲージの増減
	if (m_pGaugeManager != nullptr)
	{
		m_pGaugeManager->SetLife(m_nLife);
		m_pGaugeManager->Fluctuation();
	}
}

//============================================================================
// 自身を破壊する処理
//============================================================================
void CCharacter::Destroy()
{
	// 自身の終了処理
	Uninit();
}

//============================================================================
// 着地処理
//============================================================================
void CCharacter::Landing(const D3DXVECTOR3 pos)
{
	// 位置を設定する
	SetPos(pos);

	// 着地判定を真にする
	m_bGround = true;
}

//============================================================================
// 床の当たり判定
//============================================================================
void CCharacter::FieldCollision()
{
	// 現在の位置を定数として取得
	const D3DXVECTOR3 pos = CCharacter::GetPos();

	CMeshField* pMeshField = nullptr;
	float a = 0.0f;

	if (CApplication::GetModeType() == CApplication::MODE_GAME)
		pMeshField = CGame::GetMeshField();
	else if (CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
		pMeshField = CTutorial::GetMeshField();

	if (pMeshField != nullptr)
	{
		// 床の当たり判定から高さを定数として取得
		if (pMeshField != nullptr)
			a = pMeshField->MeshCollision(pos);
	}
	// 接地している場合
	if (GetGround() == true)
	{
		// プレイヤーの高さを設定
		CCharacter::SetPos({ pos.x, a, pos.z });
	}
	// 接地していない場合
	else
	{
		if (!m_bAvoidance)
		// メッシュフィールドの上にいる場合は重力をかける
		CCharacter::AddMove({ 0.0f, -CHARACTER_GRAVITY, 0.0f });

		// メッシュフィールドより下の位置にいる場合
		if (a >= pos.y)
		{
			// 着地処理を読み込む
			Landing({ pos.x, a, pos.z });
		}
	}
}

//==============================================================================================
// 回転方向へ振り向かせる処理
//==============================================================================================
void CCharacter::Rotation()
{
	// 目的の角度にする
	m_rot.y += (m_rotDest.y - m_rot.y) * m_fRotSpeed;
}

//==============================================================================================
// 角度の正規化
//==============================================================================================
void CCharacter::NormalizeRot()
{
	// 角度の正規化
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y -= D3DX_PI * 2;
	}
	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}

	// 目的の角度の正規化
	if (m_rotDest.y - m_rot.y > D3DX_PI)
	{
		m_rotDest.y -= D3DX_PI * 2;
	}
	else if (m_rotDest.y - m_rot.y < -D3DX_PI)
	{
		m_rotDest.y += D3DX_PI * 2;
	}

	m_rot.x = 0.0f;
	m_rot.z = 0.0f;
}

//==============================================================================================
// パーツの設定処理
//==============================================================================================
void CCharacter::SetParts(const int charaParts, const int partsIndex, CMotion::MOTION motion)
{
	// パーツが未使用の場合
	if (m_Parts[charaParts] == nullptr)
	{
		m_Parts[charaParts] = CParts::Create(GetPos(), partsIndex, motion, this);
	}
	//else
	//{
	//	// パーツ変更処理(index, filename)
	//	for (auto pParts : m_Parts[index]->GetModelAll())
	//	{

	//	}
	//}
}