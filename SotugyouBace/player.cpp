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
#include "player_manager.h"
#include "game.h"
#include "energy_gauge.h"
#include "tutorial.h"
#include "camera.h"
#include <vector>
#include"debugProc.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// プレイヤーの当たり判定の大きさ
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// プレイヤーのジャンプ力
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
	LoadFile("Data\\text\\Motion\\motion_player.txt");

	// タグの設定
	SetTag(TAG_CHARACTER);

	// プレイヤー側に設定
	SetPlayerSide(true);

	// 当たり判定の生成
	SetCollision();

	m_bTarget = false;

	CCharacter::Init();

	return S_OK;
}

//============================================================================
// 終了処理
//============================================================================
void CPlayer::Uninit()
{
	CCharacter::Uninit();

	CObject::Release();
}

//============================================================================
// 更新処理
//============================================================================
void CPlayer::Update()
{
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
	// 現在のモーション
	const int nCuttentMotion = GetCurrentMotion();

	// 着地モーションが終了した場合
	if (nCuttentMotion == MOTION_LANDING && GetMotionStop() == true)
	{
		SetMotion(MOTION_NEUTRAL);
	}

	int nMotion = GetMotion();


	// 現在のモーションから変わった場合
	if (nCuttentMotion != nMotion)
	{
		// 現在モーションの終了処理
		switch (nCuttentMotion)
		{
			// ニュートラル
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
			break;
		case MOTION_JUMP:
			break;
		case MOTION_LANDING:
			break;
		default:
			break;
		}

		// 現在モーションの開始処理
		switch (nMotion)
		{
		case MOTION_NEUTRAL:
			break;
		case MOTION_WALK:
			break;
		case MOTION_JUMP:
			break;
		case MOTION_LANDING:
			break;
		default:
			break;
		}

		// キャラクターのモーション変更処理
		CCharacter::ChangeMotion();
	}
}

//============================================================================
// プレイヤーの攻撃処理
//============================================================================
void CPlayer::PlayerAttack()
{
	Target();

	// 情報の取得
	D3DXVECTOR3 pos = GetCenterPos();
	D3DXVECTOR3 rot = GetBulletRot();

	D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };
	pos_vec *= 100.f;
	pos_vec += pos;

	// 弾の生成
	CBullet::Create({ pos.x, pos.y, pos.z}, D3DXVECTOR2(60.0f, 60.0f), D3DXVECTOR3(-sinf(rot.y), sinf(rot.x), -cosf(rot.y)), true);
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
		SetMotion(MOTION_JUMP);

		// 離着状態にする
		SetGround(false);

		// 上に上昇する
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// プレイヤーのジャンプブースト処理
//============================================================================
void CPlayer::JumpBoost()
{
	CPlayerManager *pPlayerManager = CApplication::GetPlayerManager();
	CPlayer *pPlayer = nullptr;
   	CEnergy_Gauge *pGauge = nullptr;

	if (pPlayerManager != nullptr)
	{
		pPlayer = pPlayerManager->GetPlayer(0);
		pGauge = pPlayer->GetEnergy_Gauge();
	}

	if (pGauge != nullptr)
	{
		// 空中にいる場合、エネルギーが残っている場合
		if (!GetGround() && !pGauge->GetConsumption())
		{
			// 上昇する
			AddMove({ 0.0f, 0.5f, 0.0f });

			// エネルギーを消費する
			pGauge->Consumption_Gauge();
		}
	}
}

//============================================================================
// プレイヤーの着地処理
//============================================================================
void CPlayer::Landing(const D3DXVECTOR3 pos)
{
	for (int nCnt = 0; nCnt < MODEL_MAX; nCnt++)
	{
		// 着地モーションを設定
		SetMotion(MOTION_LANDING);

		// キャラクターの着地処理
		CCharacter::Landing(pos);
	}
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
	// 雑魚敵の情報
	std::vector<CCharacter*> Mob = CGame::GetMob();

	D3DXVECTOR3 Mob_Pos = { 0.0f,0.0f,0.0f };		// 敵の位置
	D3DXVECTOR3 NearMob_Pos = { 0.0f,0.0f,0.0f };	// 一番近い敵の位置
	m_fTarget_Scope = 3000.0f;						// ターゲットを狙う範囲
	float NearDistance = m_fTarget_Scope;			// 敵との距離
	float NextNearDistance = 0.0f;					// 次に近い敵との距離
	m_bTarget = false;								// 近くに敵がいるか
	bool bScreen = false;							// 画面に映っているか

	while(true)
	{
		for (int nCnt = 0; nCnt < Mob.size(); nCnt++)
		{
			if (Mob[nCnt]->GetLife() != 0)
			{
				// 敵の位置の取得
				Mob_Pos = Mob[nCnt]->GetPos();

				// 距離の算出
				float Distance = sqrtf((Mob_Pos.x - GetPos().x) * (Mob_Pos.x - GetPos().x)
					+ (Mob_Pos.z - GetPos().z) * (Mob_Pos.z - GetPos().z));

				// 距離3000以上
				if (Distance > m_fTarget_Scope)
					continue;

				// 距離を比べる
				if (NearDistance >= Distance && NextNearDistance < Distance)
				{
					// 短い方の距離と位置を代入
					NearDistance = Distance;
					NearMob_Pos = Mob_Pos;

					m_bTarget = true;

					// 画面に映っている時だけターゲットする
					bScreen = Target_Scope(NearMob_Pos);
				}
			}
		}

		if (m_bTarget && bScreen
			|| !m_bTarget && !bScreen)
			break;

		// 距離が近いが画面に映っていない敵との距離
		NextNearDistance = NearDistance;
		NearDistance = m_fTarget_Scope;
		m_bTarget = false;
	}

	if (m_bTarget && bScreen)
	{
		D3DXVECTOR3 pos = GetPos();

		// ターゲットした敵の方向
		float Angle = atan2(NearMob_Pos.x - pos.x, NearMob_Pos.z - pos.z);
		
		// 目的の角度の設定
		CCharacter::SetBulletRot({ 0.0f,Angle + D3DX_PI,0.0f });
	}
	else
	{// ターゲットがいない場合は正面に弾を撃つ
		// カメラの角度
		CCamera *Camera = CApplication::GetCamera();
		D3DXVECTOR3 rotCamera = Camera->GetRot();

		// 目的の角度の設定
		CCharacter::SetBulletRot({ rotCamera.x + D3DX_PI,rotCamera.y + D3DX_PI ,rotCamera.z + D3DX_PI });
	}
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
	float fView_Angle = 44.5f;

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		// 画面に映るぎりぎりの位置
		Reflected_Pos[nCnt].x = Camera->GetWorldPosV().x + sinf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		Reflected_Pos[nCnt].z = Camera->GetWorldPosV().z + cosf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		fView_Angle *= -1;

		// カメラの視点
		D3DXVECTOR3 WorldPosV = Camera->GetWorldPosV();

		// カメラの視点から画角分ずらす
		/*if (nCnt == 0)
		{
			WorldPosV.x += sinf(rotCamera.y + D3DX_PI / 2) * 500;
			WorldPosV.z += cosf(rotCamera.y + D3DX_PI / 2) * 500;
		}
		else
		{
			WorldPosV.x += sinf(rotCamera.y - D3DX_PI / 2) * 500;
			WorldPosV.z += cosf(rotCamera.y - D3DX_PI / 2) * 500;
		}*/

		// カメラの視点からのベクトル
		Reflected_PosVec[nCnt] = Reflected_Pos[nCnt] - WorldPosV;

		// 正規化
		D3DXVec3Normalize(&Reflected_PosVec[nCnt], &Reflected_PosVec[nCnt]);

		// 視点からから敵のベクトル
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