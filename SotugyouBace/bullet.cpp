//=============================================================================
//
// 弾.cpp (Bullet.cpp)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// インクルード
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "bullet.h"
#include "game.h"
#include "meshfield.h"
#include "object3D.h"
#include "objectX.h"
#include "particle_emitter.h"
#include "tutorial.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
const float CBullet::BULLET_SPEED = 50.0f;				// 弾の速度
const float CBullet::BULLET_COLLISION_RADIUS = 30.0f;	// 弾の当たり判定の大きさ
//=============================================================================
// コンストラクタ
//=============================================================================
CBullet::CBullet(const CObject::PRIORITY priority) : CMove_Object(priority)
{
	m_nLife = BULLET_LIFE;
	SetPower(BULLET_POWER);
	m_fSpeed = BULLET_SPEED;
	SetRadius(BULLET_COLLISION_RADIUS);
}

//=============================================================================
// デストラクタ
//=============================================================================
CBullet::~CBullet()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CBullet::Init()
{
	// タグの設定
	SetTag(TAG_BULLET);

	// オブジェクト3Dの初期化処理
	CMove_Object::Init();

	//==================================================
	// メンバ変数の初期化
	//==================================================
	// 当たり判定の生成
	SetCollision();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CBullet::Uninit()
{
	// 3Dオブジェクトが使用されている場合
	if (m_pObj3D != nullptr)
	{
		m_pObj3D->Uninit();
		m_pObj3D = nullptr;
	}
	if (m_pObjX != nullptr)
	{
		m_pObjX->Uninit();
		m_pObjX = nullptr;
	}

	// オブジェクト3Dの終了処理
	CMove_Object::Uninit();
}

//=============================================================================
// 更新処理
//=============================================================================
void CBullet::Update()
{
	// 取得
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR2 size = GetSize();

	//弾の位置更新
	pos += move * m_fSpeed;

	//前回の位置を保存
	m_nPosOld = pos;

	// 位置の設定
	SetPos(pos);

	// オブジェクト3Dの位置を設定
	if (m_pObj3D != nullptr)
	{
		m_pObj3D->SetPos(pos);
		m_pObj3D->SetSize(size);
	}
	if (m_pObjX != nullptr)
	{
		m_pObjX->SetPos(pos);
	}

	// 寿命を減らす
	m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
		return;
	}

	// 床の当たり判定
	FieldCollision();

}

//=============================================================================
// 描画処理
//=============================================================================
void CBullet::Draw()
{

}

//============================================================================
// 床の当たり判定
//============================================================================
void CBullet::FieldCollision()
{
	// 現在の位置を定数として取得
	const D3DXVECTOR3 pos = GetPos();

	CMeshField* pMeshField = nullptr;

	if(CApplication::GetModeType() == CApplication::MODE_GAME)
		pMeshField = CGame::GetMeshField();
	else if(CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
		pMeshField = CTutorial::GetMeshField();

	if (pMeshField != nullptr)
	{
		// 床の当たり判定から高さを定数として取得
		const float a = pMeshField->MeshCollision(pos);

		// メッシュフィールドより下の位置にいる場合
		if (a >= pos.y)
		{
			//pMeshField->Ground_Broken(pos, 50.0f, 5);

			// 弾を破壊する
			Destroy();
		}
	}
}

//=============================================================================
// 被弾処理
//=============================================================================
void CBullet::Hit(CMove_Object* pHit)
{
	// 弾では無い場合 && 同じサイドではない場合
	if (pHit->GetTag() != TAG_BULLET && GetPlayerSide() != pHit->GetPlayerSide())
	{
		Destroy();
	}
}

//=============================================================================
// 破壊処理
//=============================================================================
void CBullet::Destroy()
{
	// 攻撃パーティクル
	std::move(CParticleEmitter::Create("Attack", GetPos()));

	Uninit();
}

//=============================================================================
// 生成処理
//=============================================================================
CBullet* CBullet::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, D3DXVECTOR3 move, const bool side, const PRIORITY priority)
{
	//クラスの生成
	CBullet* pBullet = new CBullet(priority);

	//nullチェック
	if (pBullet != nullptr)
	{
		//初期化処理
		pBullet->Init();
		//設定処理
		pBullet->SetPos(pos);
		pBullet->SetMove(move);
		pBullet->SetSize(size);
		pBullet->SetPlayerSide(side);

		// 弾オブジェクトの生成
		pBullet->m_pObj3D = CObject3D::Create(pos, size, priority);
		// 弾のテクスチャ
		pBullet->m_pObj3D->SetTexture(CTexture::TEXTURE_BULLET);

		// ビルボードの設定
		pBullet->m_pObj3D->Setbillboard(true);
	}
	else
	{
		assert(false);
	}

	return pBullet;
}

