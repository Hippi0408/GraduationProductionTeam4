//==============================================================================================
//
// 通常弾　　　normal_bullet.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"normal_bullet.h"
#include"object3D.h"
#include "application.h"
#include"enemy_manager.h"
#include "game.h"
#include "tutorial.h"
#include "player.h"
#include "player_manager.h"

//==============================================================================================
// コンストラクタ
//==============================================================================================
CNormal_Bullet::CNormal_Bullet(const PRIORITY priority) : CBullet(priority)
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CNormal_Bullet::~CNormal_Bullet()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CNormal_Bullet::Init()
{
	CBullet::Init();

	// 弾が敵に届くまでの時間
	float fHitCnt = m_fHypotenuse / GetSpeed_XZ();

	if (m_bTarget && GetPlayerSide())
	{
		// ターゲットしている敵の位置
		D3DXVECTOR3 Enemy_Pos = pEnemy->GetCenterPos();
		// 移動量
		D3DXVECTOR3 Enemy_Move = pEnemy->GetMove();

		// 弾が届くときの敵の位置
		Enemy_Pos.x += (Enemy_Move.x * m_fSpeed * fHitCnt);
		Enemy_Pos.z += (Enemy_Move.z * m_fSpeed * fHitCnt);

		// 弾から敵までのベクトル
		D3DXVECTOR3 Mob_Vec = Enemy_Pos - GetPos();
		D3DXVec3Normalize(&Mob_Vec, &Mob_Vec);
		SetMove(Mob_Vec);
	}
	else if (!GetPlayerSide())
	{
		CPlayer* pPlayer = nullptr;

		// プレイヤーの情報
		pPlayer = CGame::GetPlayerManager()->GetPlayer(0);


	}

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CNormal_Bullet::Uninit()
{
	CBullet::Uninit();
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CNormal_Bullet::Update()
{
	CBullet::Update();
}

//==============================================================================================
// 描画処理
//==============================================================================================
void CNormal_Bullet::Draw()
{
	CBullet::Draw();
}

//==============================================================================================
// 生成処理
//==============================================================================================
CNormal_Bullet *CNormal_Bullet::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, D3DXVECTOR3 move, float hypotenuse, CEnemy *enemy, float enemy_speed, bool target, const bool side, const CObject::PRIORITY priority)
{
	//クラスの生成
	CNormal_Bullet* pNormal_Bullet = new CNormal_Bullet(priority);

	//nullチェック
	if (pNormal_Bullet != nullptr)
	{
		pNormal_Bullet->SetPos(pos);
		pNormal_Bullet->SetSize(size);
		pNormal_Bullet->SetPlayerSide(side);
		pNormal_Bullet->m_fHypotenuse = hypotenuse;
		pNormal_Bullet->pEnemy = enemy;
		pNormal_Bullet->m_fSpeed = enemy_speed;
		pNormal_Bullet->m_bTarget = target;
		pNormal_Bullet->Init();

		// 弾オブジェクトの生成
		pNormal_Bullet->SetObj3D(CObject3D::Create(pos, size, priority));
		// 弾のテクスチャ
		pNormal_Bullet->GetObj3D()->SetTexture(CTexture::TEXTURE_BULLET);

		// ビルボードの設定
		pNormal_Bullet->GetObj3D()->Setbillboard(true);
	}
	else
		assert(false);

	return pNormal_Bullet;
}