//=============================================================================
//
// player.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "player.h"
#include "application.h"
#include "input.h"
#include "bullet.h"
#include "normal_bullet.h"
#include "homing_bullet.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "game.h"
#include "energy_gauge.h"
#include "tutorial.h"
#include "camera.h"
#include <vector>
#include"debugProc.h"
#include"object3D.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// プレイヤーの当たり判定の大きさ
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// プレイヤーのジャンプ力
const float CPlayer::VIEW_SCOPE_ANGLE = 44.5f;		// プレイヤーの視野角
const float CPlayer::RETICLE_TRANSPARENCY_SIZE = 300.0f;
const float CPlayer::RETICLE_SIZE = 200.0f;
//=====================================
// デフォルトコンストラクタ
//=====================================
CPlayer::CPlayer()
{
	// プレイヤーの初期値を設定
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(PLAYER_COLLISION_RADIUS);
}

//=====================================
// デストラクタ
//=====================================
CPlayer::~CPlayer()
{
	// プレイヤーマネージャーの自身を削除
	CApplication::GetPlayerManager()->PlayerRelease(m_nCharaIndex);
}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CPlayer::Init()
{
	// プレイヤーのモデルを読み込む
	SetParts(PARTS_BODY, "Data\\text\\Motion\\parts\\motion_Body.txt");
	SetParts(PARTS_LEG, "Data\\text\\Motion\\parts\\motion_Leg.txt");
	SetParts(PARTS_ARMS, "Data\\text\\Motion\\parts\\motion_Arms.txt");

	// タグの設定
	SetTag(TAG_CHARACTER);

	// プレイヤー側に設定
	SetPlayerSide(true);

	// 当たり判定の生成
	SetCollision();

	m_bTarget = false;
	m_bReticle_Reset = true;
	m_Reticle_Size = { RETICLE_TRANSPARENCY_SIZE,RETICLE_TRANSPARENCY_SIZE };
	m_fReticle_Alpha = 0.0f;

	CCharacter::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CPlayer::Uninit()
{
	if (m_pEnergy_Gauge != nullptr)
	{
		// エネルギーゲージの破棄
		m_pEnergy_Gauge->Uninit();
		m_pEnergy_Gauge = nullptr;
	}

	CCharacter::Uninit();
}

//============================================================================
// 更新処理
//============================================================================
void CPlayer::Update()
{
	// ターゲット
	Target();

	// モーション番号の設定
	ChangeMotion();

	// キャラクターの更新
	CCharacter::Update();
}

//============================================================================
// 描画処理
//============================================================================
void CPlayer::Draw()
{
	CCharacter::Draw();
}

//============================================================================
// モーション変更処理
//============================================================================
void CPlayer::ChangeMotion()
{
	// 着地モーションを設定
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// パーツ
		CParts* pParts = GetParts(nCnt);

		// 着地モーションが終了した場合
		if (pParts->GetCurrentMotion() == MOTION_LANDING && pParts->GetMotionStop() == true)
		{
			pParts->SetMotion(MOTION_NEUTRAL);
		}
	}
}

//============================================================================
// プレイヤーの攻撃処理
//============================================================================
void CPlayer::PlayerAttack()
{
	// 情報の取得
	D3DXVECTOR3 pos = GetCenterPos();
	D3DXVECTOR3 rot = GetBulletRot();

	D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };

	// 弾の生成
	CNormal_Bullet::Create(pos, { 60.0f,60.0f }, pos_vec, m_fHypotenuse, m_nEnemy_Count, m_fEnemy_Speed, m_bReticle_Draw, true, PRIORITY_BACK);
	//CHoming_Bullet::Create(pos, rot, pos_vec, m_NearMob_Pos, m_nEnemy_Count, "Data/model/Weapon/knife.x", true, PRIORITY_BACK);
}

//============================================================================
// プレイヤーのジャンプ処理
//============================================================================
void CPlayer::JumpStart()
{
	// 接地している場合のみ
	if (GetGround() == true)
	{
		// ジャンプモーションを設定
		GetParts(PARTS_LEG)->SetMotion(MOTION_JUMP);

		// 離着状態にする
		SetGround(false);

		// 上昇する
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// プレイヤーのジャンプブースト処理
//============================================================================
void CPlayer::JumpBoost()
{
	if (m_pEnergy_Gauge != nullptr)
	{
		// 空中にいる場合、エネルギーが残っている場合
		if (!GetGround() && !m_pEnergy_Gauge->GetConsumption())
		{
			// 上昇する
			AddMove({ 0.0f, 0.5f, 0.0f });

			// エネルギーを消費する
			m_pEnergy_Gauge->Consumption_Gauge();
		}
	}
}

//============================================================================
// プレイヤーの着地処理
//============================================================================
void CPlayer::Landing(const D3DXVECTOR3 pos)
{
	// 着地モーションを設定
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		GetParts(nCnt)->SetMotion(MOTION_LANDING);
	}

	// キャラクターの着地処理
	CCharacter::Landing(pos);
}

//============================================================================
// 被弾処理
//============================================================================
void CPlayer::Hit(CMove_Object* pHit)
{
	// 自身ではない 且つ プレイヤー側ではない場合
	if (pHit != nullptr && GetPlayerSide() != pHit->GetPlayerSide())
	{
		TAG tag = pHit->GetTag();

		switch (tag)
		{
		case TAG_CHARACTER:
			break;
		case TAG_BULLET:
			// 弾のダメージを返す
			Damage(pHit->GetPower());
			break;
		default:
			break;
		}
	}
}

//============================================================================
// ターゲット
//============================================================================
void CPlayer::Target()
{
	D3DXVECTOR3 Player_Pos = GetPos();				// プレイヤーの位置
	D3DXVECTOR3 Mob_Pos = { 0.0f,0.0f,0.0f };		// 敵の位置
	m_NearMob_Pos = { 0.0f,0.0f,0.0f };				// 一番近い敵の位置
	m_fTarget_Scope = 3000.0f;						// ターゲットを狙う範囲
	float NearDistance = m_fTarget_Scope;			// 敵との距離
	float NextNearDistance = 0.0f;					// 次に近い敵との距離
	m_bTarget = false;								// 近くに敵がいるか
	bool bScreen = false;							// 画面に映っているか
	float DistanceXZ = 0.0f;						// プレイヤーと敵のXZ座標の距離
	D3DXVECTOR3 BulletVec = {0.0f,0.0f,0.0f};
	m_nEnemy_Count = 0;
	int nCnt = 0;

	while (true)
	{
		// 雑魚敵の情報
		for (auto pEnemy : CApplication::GetEnemyManager()->GetAllEnemy())
		{
			nCnt++;

			if (pEnemy->GetLife() > 0)
			{
				// 敵の位置の取得
				Mob_Pos = pEnemy->GetCenterPos();

				// プレイヤーから敵の距離
				BulletVec = Mob_Pos - Player_Pos;

				// 距離の算出
				DistanceXZ = sqrtf(BulletVec.x * BulletVec.x
					+ BulletVec.z * BulletVec.z);

				// 距離3000以上
				if (DistanceXZ > m_fTarget_Scope)
					continue;

				// 距離を比べる
				if (NearDistance >= DistanceXZ && NextNearDistance < DistanceXZ)
				{
					// 短い方の距離と位置を代入
					NearDistance = DistanceXZ;
					m_NearMob_Pos = Mob_Pos;
					m_nEnemy_Count = nCnt;
					m_fEnemy_Speed = pEnemy->GetSpeed();

					m_bTarget = true;

					// 画面に映っている時だけターゲットする
					bScreen = Target_Scope(m_NearMob_Pos);
				}
			}
		}

		if (m_bTarget != bScreen)
		{
			// 距離が近いが画面に映っていない敵との距離
			NextNearDistance = NearDistance;
			NearDistance = m_fTarget_Scope;
			nCnt = 0;
			m_bTarget = false;
		}
		else
			break;
	}

	if (m_bTarget && bScreen)
	{
		m_bReticle_Draw = true;

		// プレイヤーから敵の距離
		BulletVec = m_NearMob_Pos - GetPos();

		// ターゲットした敵の方向
		float Angle = atan2(BulletVec.x, BulletVec.z);
		float AngleY = 0.0f;

		// プレイヤーから敵の直線距離
		m_fHypotenuse = sqrt((BulletVec.y * BulletVec.y) + (NearDistance * NearDistance));

		// Y座標の追従
		AngleY = sinf(BulletVec.y / m_fHypotenuse);

		// 目的の角度の設定
		CCharacter::SetBulletRot({ AngleY,Angle + D3DX_PI,0.0f });
	}
	else
	{// ターゲットがいない場合は正面に弾を撃つ
		m_bReticle_Draw = false;

		// カメラの角度
		CCamera *Camera = CApplication::GetCamera();
		D3DXVECTOR3 rotCamera = Camera->GetRot();

		// 目的の角度の設定
		CCharacter::SetBulletRot({ rotCamera.x + D3DX_PI,rotCamera.y + D3DX_PI ,rotCamera.z + D3DX_PI });

		m_NearMob_Pos = { 0.0f,0.0f,0.0f };
	}

	// レティクルの設定
	Reticle(m_NearMob_Pos);
}

//============================================================================
// ターゲットを狙う範囲
//============================================================================
bool CPlayer::Target_Scope(D3DXVECTOR3 nearpos)
{
	// カメラの角度
	CCamera *Camera = CApplication::GetCamera();
	D3DXVECTOR3 rotCamera = Camera->GetRot();

	// プレイヤーから注視点までのベクトル
	D3DXVECTOR3 CameraVec = Camera->GetWorldPosR() - GetPos();

	// 正規化
	D3DXVec3Normalize(&CameraVec, &CameraVec);

	// プレイヤーから敵のベクトル
	D3DXVECTOR3 EnemyVec = nearpos - GetPos();

	// 正規化
	D3DXVec3Normalize(&EnemyVec, &EnemyVec);

	// 内積
	float fInner = D3DXVec3Dot(&EnemyVec, &CameraVec);

	// カメラの後ろに敵がいる場合
	if (fInner < 0)
		return false;

	// 画面に映るぎりぎりの位置
	D3DXVECTOR3 Reflected_Pos[2] = {};
	D3DXVECTOR3 Reflected_PosVec[2] = {};

	// 視野角
	float fView_Angle = VIEW_SCOPE_ANGLE;

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		// ターゲット出来るぎりぎりの位置
		Reflected_Pos[nCnt].x = Camera->GetWorldPosV().x + sinf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		Reflected_Pos[nCnt].z = Camera->GetWorldPosV().z + cosf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		fView_Angle *= -1;

		// カメラの視点
		D3DXVECTOR3 WorldPosV = Camera->GetWorldPosV();

		// カメラの視点から画角分ずらす
		if (nCnt == 0)
		{
			WorldPosV.x += sinf(rotCamera.y + D3DX_PI / 2) * 500;
			WorldPosV.z += cosf(rotCamera.y + D3DX_PI / 2) * 500;
		}
		else
		{
			WorldPosV.x += sinf(rotCamera.y - D3DX_PI / 2) * 500;
			WorldPosV.z += cosf(rotCamera.y - D3DX_PI / 2) * 500;
		}

		// カメラの視点からのベクトル
		Reflected_PosVec[nCnt] = Reflected_Pos[nCnt] - WorldPosV;

		// 正規化
		D3DXVec3Normalize(&Reflected_PosVec[nCnt], &Reflected_PosVec[nCnt]);

		// 視点から敵のベクトル
		EnemyVec = nearpos - WorldPosV;

		// 正規化
		D3DXVec3Normalize(&EnemyVec, &EnemyVec);

		// 外積の格納先
		float fCp[2] = {};

		// 外積
		fCp[nCnt] = Reflected_PosVec[nCnt].x * EnemyVec.z - Reflected_PosVec[nCnt].z * EnemyVec.x;

		// 画面内に映っているか
		if (nCnt == 0)
		{
			if (fCp[nCnt] > 0.0f)
				continue;
			else
				break;
		}
		else
			if (fCp[nCnt] <= 0.0f)
				return true;
	}

	return false;
}

//============================================================================
// レティクル
//============================================================================
void CPlayer::Reticle(D3DXVECTOR3 target)
{
	// ターゲットの位置
	if (m_bReticle_Reset)
		m_Reticle_Pos = target;

	// 拡大縮小の速度
	float Size_Speed = 7;
	// アルファ値の加算減算の速度
	float Alpha_Speed = 1 / ((RETICLE_TRANSPARENCY_SIZE - RETICLE_SIZE) / Size_Speed);

	// レティクルの生成
	if (m_pReticle == nullptr && m_bReticle_Draw)
		m_pReticle = CObject3D::Create({ m_Reticle_Pos }, { m_Reticle_Size }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,m_fReticle_Alpha }, true);

	if (m_pReticle != nullptr)
	{
		if (m_bReticle_Draw)
		{
			// レティクルの移動
			if (m_Reticle_Pos != target)
				m_Reticle_Pos += (target - m_Reticle_Pos) *  0.1f;

			if (m_Reticle_Size.x > RETICLE_SIZE)
			{
				// サイズとアルファ値の設定
				m_fReticle_Alpha += Alpha_Speed;
				m_Reticle_Size.x -= Size_Speed;
				m_Reticle_Size.y -= Size_Speed;
			}

			// 位置の設定
			m_pReticle->SetPos(m_Reticle_Pos);

			m_bReticle_Reset = false;
		}
		else
		{
			if (m_Reticle_Size.x < RETICLE_TRANSPARENCY_SIZE)
			{
				// サイズとアルファ値の設定
				m_fReticle_Alpha -= Alpha_Speed;
				m_Reticle_Size.x += Size_Speed;
				m_Reticle_Size.y += Size_Speed;
			}
			else
				// レティクルのリセット
				m_bReticle_Reset = true;
		}

		// サイズと色の設定
		m_pReticle->SetSize({ m_Reticle_Size });
		m_pReticle->SetCol({ 1.0f,1.0f,1.0f,m_fReticle_Alpha });
	}
}