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
#include "drop_manager.h"
#include "game.h"
#include "tutorial.h"
#include "energy_gauge.h"
#include "camera.h"
#include <vector>
#include"debugProc.h"
#include"object3D.h"
#include "drop_weapon.h"
#include "weapon.h"

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

}

//============================================================================
// 初期化処理
//============================================================================
HRESULT CPlayer::Init()
{
	// プレイヤーのモデルを読み込む
	SetParts(PARTS_BODY, CParts_File::PARTS_PLAYER_BODY_1, CMotion::MOTION_PLAYER_BODY);
	SetParts(PARTS_ARMS, CParts_File::PARTS_PLAYER_ARMS_1, CMotion::MOTION_PLAYER_ARMS);
	SetParts(PARTS_LEG, CParts_File::PARTS_PLAYER_LEG_1, CMotion::MOTION_PLAYER_LEG);
	SetWeapon(CWeapon::WEAPON_NONE);

	// タグの設定
	SetTag(TAG_CHARACTER);

	// プレイヤー側に設定
	SetPlayerSide(true);

	// 当たり判定の生成
	SetCollision();

	m_bTarget = false;
	m_bReticle_Reset = true;
	m_bDrop_Contact = false;
	m_bDrop_Get = false;
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
	// 右手武器の終了
	if(m_pRightWeapon != nullptr)
	{
		m_pRightWeapon->Uninit();
		m_pRightWeapon = nullptr;
	}
	// 左手武器の終了
	if (m_pLeftWeapon != nullptr)
	{
		m_pLeftWeapon->Uninit();
		m_pLeftWeapon = nullptr;
	}

	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	CPlayerManager* pPlayerManager = nullptr;

	// プレイヤーマネージャーの自身を削除
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pPlayerManager = CTutorial::GetPlayerManager();
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pPlayerManager = CGame::GetPlayerManager();
	}
	if (pPlayerManager != nullptr)
	{
		pPlayerManager->PlayerRelease(m_nCharaIndex);

		if (m_pEnergy_Gauge != nullptr)
		{
			// エネルギーゲージの破棄
			m_pEnergy_Gauge->Uninit();
			m_pEnergy_Gauge = nullptr;
		}

		CCharacter::Uninit();
	}
}

//============================================================================
// 更新処理
//============================================================================
void CPlayer::Update()
{
	// ターゲット
	Target();

	// 落ちてる武器の当たり判定
	CollisionDropWeapon();

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
	TAG tag = pHit->GetTag();

	// 自身の情報
	const D3DXVECTOR3 Pos = GetPos();

	// 相手の情報
	const D3DXVECTOR3 AtherPos = pHit->GetPos();

	// 自身と相手の距離
	const D3DXVECTOR3 VecPos = AtherPos - Pos;

	// 落ちてるパーツとの距離
	const float fDistanceNear = sqrtf(VecPos.x * VecPos.x + VecPos.z * VecPos.z);

	// 相手が敵だった場合
	if (GetPlayerSide() != pHit->GetPlayerSide())
	{
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

	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	CEnemyManager* pEnemyManager = nullptr;

	// モード毎に敵キャラを読み込む
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pEnemyManager = CTutorial::GetEnemyManager();
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pEnemyManager = CGame::GetEnemyManager();
	}

	while (true)
	{
		// 雑魚敵の情報
		for (auto pEnemy : pEnemyManager->GetAllEnemy())
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
	{
		m_pReticle = CObject3D::Create({ m_Reticle_Pos }, { m_Reticle_Size }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,m_fReticle_Alpha }, true);
		m_pReticle->SetTexture(CTexture::TEXTURE_RETICLE);
	}

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

//============================================================================
// 落とし物を入手する処理
//============================================================================
void CPlayer::DropGet(CDrop_Weapon* pDrop)
{
	// プレイヤー用パーツの情報
	CPlayer::PARTS Parts = pDrop->GetPartsType();

	// 武器の情報
	const int nWeapon = pDrop->GetWeaponType();

	// 武器パーツではない場合
	if (Parts != PARTS_WEAPON)
	{
		int nPartsFileIndex = 0;	// パーツの番号

		// パーツファイルの最低値を設定
		switch (Parts)
		{
		case CPlayer::PARTS_BODY:
			nPartsFileIndex = CParts_File::PARTS_PLAYER_BODY_1;
			break;
		case CPlayer::PARTS_ARMS:
			nPartsFileIndex = CParts_File::PARTS_PLAYER_ARMS_1;
			break;
		case CPlayer::PARTS_LEG:
			nPartsFileIndex = CParts_File::PARTS_PLAYER_LEG_1;
			break;
		default:
			break;
		}

		int nWeaponIndex = 0;	// 武器の番号

		// パーツの最低値を設定
		if (nWeapon >= CDrop_Weapon::LEG_SG01)
		{
			nWeaponIndex = CDrop_Weapon::LEG_SG01;
		}
		else if (nWeapon >= CDrop_Weapon::ARMS_SG01)
		{
			nWeaponIndex = CDrop_Weapon::ARMS_SG01;
		}
		//else if (nWeapon >= CDrop_Weapon::BODY_SG01)
		//{
		//	nWeaponIndex = CParts_File::PARTS_PLAYER_BODY_1;
		//}

		// パーツの番号(パーツファイルの番号 + パーツの番号(パーツそのままの番号 - パーツの最低値))
		int nPartsIndex = nPartsFileIndex + (nWeapon - nWeaponIndex);

		// 指定したパーツの、パーツ変更処理
		GetParts(Parts)->SetParts(nPartsIndex);
	}
	// 武器パーツの場合
	else
	{
		// 武器パーツの変更処理
		ChangeWeapon(nWeapon - CDrop_Weapon::WEAPON_NONE);
	}

	// 落とし物の終了処理
	pDrop->Uninit();
}

//============================================================================
// 落ちてる武器の当たり判定
//============================================================================
void CPlayer::CollisionDropWeapon()
{
	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	CDropManager* pManager = nullptr;

	// モード毎に落とし物を読み込む
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pManager = CTutorial::GetDropManager();
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pManager = CGame::GetDropManager();
	}

	// 自身の情報
	const D3DXVECTOR3 pos = GetPos();
	const float fRadius = GetRadius();

	CDrop_Weapon* pNearDrop = nullptr;	// 最も距離が近い落とし物
	float fNearDistance = 0.0f;			// 最も近い距離

	// 全ての落とし物を読み込む
	for (auto pDrop : pManager->GetAllDrop())
	{
		// プレイヤーから落ちてるパーツの距離
		D3DXVECTOR3 Vec = pDrop->GetPos() - pos;

		// 距離の算出
		float fDistance = sqrtf(Vec.x * Vec.x + Vec.z * Vec.z);

		// 最短距離が更新された場合
		if (fNearDistance > fDistance)
		{
			fNearDistance = fDistance;
			pNearDrop = pDrop;
		}
		// 距離が格納されていない場合 且つ 円と円の当たり判定の中にいる場合
		else if(fNearDistance == 0.0f && fRadius + CDrop_Weapon::PARTS_COLLISION_RADIUS >= fDistance)
		{
			fNearDistance = fDistance;
			pNearDrop = pDrop;
		}
	}

	// 接触している落とし物が存在する場合
	m_bDrop_Contact = pNearDrop != nullptr;

	// 落とし物と接触している場合
	if (m_bDrop_Contact == true)
	{
		// ピックアップ状態を返す
		pNearDrop->SetPick_Up(true);

		// 落とし物を入手する場合
		if (m_bDrop_Get == true)
		{
			// 落とし物を入手する処理
			DropGet(pNearDrop);
		}
	}
	// 落とし物を入手する判定のリセット
	m_bDrop_Get = false;
}

//============================================================================
// 武器の変更
//============================================================================
void CPlayer::ChangeWeapon(const int weapon)
{
	// 右手(腕[3])に武器を変更
	m_pRightWeapon->ChangeWeapon(weapon);

	// 左手(腕[6])に素手を設定
	m_pLeftWeapon->ChangeWeapon(CWeapon::WEAPON_NONE);
}

//============================================================================
// 武器の設定
//============================================================================
void CPlayer::SetWeapon(const int weapon)
{
	// 右手(腕[3])に武器を設定
	m_pRightWeapon = CWeapon::Create({0.0f, 0.0f, 0.0f}, (CWeapon::WEAPON_TYPE)weapon, GetParts(PARTS_ARMS)->GetModel(3));

	// 左手(腕[6])に素手を設定
	m_pLeftWeapon = CWeapon::Create({ 0.0f, 0.0f, 0.0f }, CWeapon::WEAPON_NONE, GetParts(PARTS_ARMS)->GetModel(6));
}