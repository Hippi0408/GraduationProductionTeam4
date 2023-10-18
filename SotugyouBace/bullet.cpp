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

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
const float CBullet::BULLET_SPEED = 15.0f;				// 弾の速度
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
	// オブジェクト3Dの終了処理
	CMove_Object::Uninit();

	// 3Dオブジェクトが使用されている場合
	if (m_pObj3D != nullptr)
	{
		m_pObj3D->Uninit();
		m_pObj3D = nullptr;
	}
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
	m_pObj3D->SetPos(pos);
	m_pObj3D->SetSize(size);

	// 床の当たり判定
	FieldCollision();

	// 寿命を減らす
	m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
		return;
	}
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

	CMeshField* pMesfField = CGame::GetMeshField();

	// 床の当たり判定から高さを定数として取得
	const float a = pMesfField->MeshCollision(pos);

	// メッシュフィールドより下の位置にいる場合
	if (a >= pos.y)
	{
		// 弾を破壊する
		Destroy();

		pMesfField->Ground_Broken(pos, 50.0f, 5);
	}
}

//=============================================================================
// 被弾処理
//=============================================================================
void CBullet::Hit(CMove_Object* /* pHit */)
{
	Destroy();
}

//=============================================================================
// 破壊処理
//=============================================================================
void CBullet::Destroy()
{
	Uninit();
}

//=============================================================================
// 生成処理
//=============================================================================
CBullet* CBullet::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, D3DXVECTOR3 move, const PRIORITY priority)
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

