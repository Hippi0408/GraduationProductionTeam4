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
#include "diffusion_bullet.h"
#include "parabola_bullet.h"
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
#include "player_parameter.h"
#include "weapon_parameter.h"
#include "weapon_attack.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// プレイヤーの当たり判定の大きさ
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// プレイヤーのジャンプ力
const float CPlayer::VIEW_SCOPE_ANGLE = 44.3f;		// プレイヤーの視野角
const float CPlayer::RETICLE_TRANSPARENCY_SIZE = 300.0f;
const float CPlayer::RETICLE_SIZE = 200.0f;
//=====================================
// デフォルトコンストラクタ
//=====================================
CPlayer::CPlayer()
{
	// プレイヤーの初期値を設定
	//SetMaxLife(FIRST_MAX_LIFE);
	//SetLife(FIRST_MAX_LIFE);
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
	SetParts(PARTS_BODY, CParts_File::PARTS_PLAYER_BODY_1 + m_Parts_Job[PARTS_BODY], CMotion::MOTION_PLAYER_BODY);
	SetParts(PARTS_ARMS, CParts_File::PARTS_PLAYER_ARMS_1 + m_Parts_Job[PARTS_ARMS], CMotion::MOTION_PLAYER_ARMS);
	SetParts(PARTS_LEG, CParts_File::PARTS_PLAYER_LEG_1 + m_Parts_Job[PARTS_LEG], CMotion::MOTION_PLAYER_LEG);
	SetPlayerWeapon(CWeapon::WEAPON_KNUCKLE, 0);

	// パラメータの設定
	SettingParameter();

	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	// 生成時に自身のポインタを敵キャラマネージャーに設定
	/*if (Mode == CApplication::MODE_TUTORIAL)
	{
	CTutorial::SetPlayerUI(CPlayerUi::UITYPE_SUPPORT, m_Job[PARTS_BODY]);
	}
	else*/ if (Mode == CApplication::MODE_GAME)
	{
		CGame::SetPlayerUI(CPlayerUi::UITYPE_SUPPORT, m_Parts_Job[PARTS_BODY]);
	}

	// タグの設定
	SetTag(TAG_CHARACTER);

	// プレイヤー側に設定
	SetPlayerSide(true);

	// サイズの設定
	SetSize({ GetRadius(),GetRadius(),GetRadius() });

	// 当たり判定の生成
	SetCollision();

	m_bTarget = false;
	m_bReticle_Reset = true;
	m_bDrop_Contact = false;
	m_bDrop_Get = false;
	m_bChange_Parameter = false;
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
	// パラメーターの変更があった場合にパラメーターを設定し直す処理
	if (m_bChange_Parameter == true) SettingParameter();

	// ターゲット
	Target();

	// 落ちてる武器の当たり判定
	CollisionDropWeapon();

	// モーション番号の設定
	ChangeMotion();

	// プレイヤーの攻撃処理
	PlayerAttack();

	// キャラクターの更新
	CCharacter::Update();
	//CDebugProc::Print("プレイヤーライフ：%d / %d\n", GetLife(), GetMaxLife());
	//CDebugProc::Print("腕パーツ：%d\n脚パーツ : %d\n", m_nRarity_Arms, m_nRarity_Leg);
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

		// モーションがループしない場合
		if (pParts->GetMotionLoop() == false && pParts->GetMotionStop() == true)
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
	// 攻撃判定が真の場合、攻撃処理を読み込み続ける
	if (m_bPlayer_Attack == true)
	{
		const int nWeaponType = m_nWeapon_type + CDrop_Weapon::MELEE_WEAPON_NONE;

		if (nWeaponType < CDrop_Weapon::MELEE_WEAPON_MAX)
		{
			MeleeWeaponAttack();
		}
		else
		{
			// 情報の取得
			D3DXVECTOR3 pos = GetCenterPos();
			D3DXVECTOR3 rot = GetBulletRot();

			D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };

			// 弾の生成
			CNormal_Bullet::Create(pos, { 60.0f,60.0f }, pos_vec, m_fHypotenuse, m_pEnemy, m_fEnemy_Speed, m_bReticle_Draw, true, PRIORITY_BACK);
			/*CHoming_Bullet::Create(pos, rot, pos_vec, m_NearMob_Pos, "Data/model/Weapon/knife.x", true, PRIORITY_BACK);
			CDiffusion_Bullet::Create(pos, { 30.0f,30.0f }, pos_vec, 10, true, PRIORITY_BACK);
			CParabola_Bullet::Create(pos, pos_vec, m_fHypotenuse, rot, "Data/model/Weapon/knife.x", true, PRIORITY_BACK);*/
		}
	}
}

//============================================================================
// 近接武器の攻撃処理
//============================================================================
void CPlayer::MeleeWeaponAttack()
{
	// 武器番号
	int nWeaponNumber = 0;

	// 近接武器の最低値より大きい場合
	if (m_nWeapon_type >= CWeapon::MELEE_WEAPON_STABBING_LANCE)
	{
		// 武器の最低値を初期値に設定
		nWeaponNumber = MOTION_POKE_1;
	}
	// 近接武器の最低値より大きい場合
	else if (m_nWeapon_type >= CWeapon::MELEE_WEAPON_SLASH_SAMURAI_SWORD)
	{
		// 武器の最低値を初期値に設定
		nWeaponNumber = MOTION_SLASH_1;
	}
	// 素手の最低値より大きい場合
	else
	{
		// 武器の最低値を初期値に設定
		nWeaponNumber = MOTION_FIST_1;
	}

	// モーション番号
	const int nMotion = nWeaponNumber + m_nAdditional_Attack;

	// モーション情報
	CMotion* pMotion = CApplication::GetMotion();

	// 攻撃開始処理
	if (m_nAttackRate_Counter == 0)
	{
		// (腕モーションの全フレーム数 - 1) を計測
		CMotion::MotionPattern pMotionPattern = pMotion->GetMotionPattern(nMotion, CMotion::m_cMotionFileName[PARTS_ARMS]);

		// モーション全体の秒数を設定
		for (int nCnt = 0; nCnt < pMotionPattern.nMaxKey - 1; nCnt++)
		{
			m_nAttackRate_Max_Counter += pMotionPattern.aKeySet[nCnt].nFrame;
		}

		// 攻撃モーションを設定
		for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
		{
			// パーツ
			CParts* pParts = GetParts(nCnt);

			// 攻撃モーション + 追加攻撃の回数
			pParts->SetMotion(nMotion);
		}
	}
	// 0番目の攻撃終了時に攻撃を行う
	else if (m_nAttackRate_Counter == pMotion->GetMotionPattern(nMotion, CMotion::m_cMotionFileName[PARTS_ARMS]).aKeySet[0].nFrame)
	{
		// 現在のモード
		CApplication::MODE Mode = CApplication::GetModeType();

		CWeapon_Parameter::MELEE_WEAPON_PARAMETERS Melee_Parameter = {};

		CWeapon_Parameter* pWeapon_Parameter = nullptr;

		//パラメータの取得
		/*if (Mode == CApplication::MODE_TUTORIAL)
		{
		pWeapon_Parameter = CTutorial::GetWeaponParameter();
		}
		else*/
		if (Mode == CApplication::MODE_GAME)
		{
			pWeapon_Parameter = CGame::GetWeaponParameter();
		}

		// 武器パラメーター
		Melee_Parameter = pWeapon_Parameter->GetParameterMeleeWeapon(m_nWeapon_type, m_nWeapon_Rarity);

		// 情報の取得
		D3DXVECTOR3 pos = GetCenterPos();
		D3DXVECTOR3 rot = GetRot();

		D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };

		// 当たり判定の大きさ
		float radiusSize = 80.0f * (Melee_Parameter.nLength + 2);

		// 射程の加算
		pos += pos_vec * radiusSize / 2.0f;

		// 武器攻撃(位置、大きさ、サイド、威力, 寿命)
		CWeapon_Attack::Create(pos, radiusSize, true, Melee_Parameter.nPower, 20);
	}

	// モーションが終了した場合
	if (m_nAttackRate_Counter++ >= m_nAttackRate_Max_Counter)
	{
		// 攻撃処理中に攻撃コマンドが選択された場合に追加攻撃をする
		if (m_bAdditional_Attack == true && m_nAdditional_Attack < 2)
		{
			// 攻撃回数を増やす
			m_nAdditional_Attack++;
		}
		// モーション終了時に追加コマンドが無い場合に終了する
		else
		{
			m_nAdditional_Attack = 0;
		}
		// 初期化
		m_bPlayer_Attack = false;
		m_bAdditional_Attack = false;
		m_nAttackRate_Counter = 0;
		m_nAttackRate_Max_Counter = 0;
	}
}

//============================================================================
// プレイヤーのジャンプ処理
//============================================================================
void CPlayer::JumpStart()
{
	// 接地している場合のみ
	if (GetGround())
	{
		// ジャンプモーションを設定
		GetParts(PARTS_LEG)->SetMotion(MOTION_JUMP);

		// 離着状態にする
		SetGround(false);
		SetLandObj(false);
		SetObjXZ(false);

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
		CParts* pParts = GetParts(nCnt);

		// 通常モーションの場合
		if (pParts->GetMotion() == MOTION_NEUTRAL || pParts->GetMotion() == MOTION_JUMP)
		{
			pParts->SetMotion(MOTION_LANDING);
		}
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
		case TAG_EXPLOSION:
			// 爆発のダメージを返す
			Damage(pHit->GetPower());
		case TAG_MAP_OBJECT:
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
					m_pEnemy = pEnemy;

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
		m_fAngle = atan2(BulletVec.x, BulletVec.z);
		float AngleY = 0.0f;

		// プレイヤーから敵の直線距離
		m_fHypotenuse = sqrt((BulletVec.y * BulletVec.y) + (NearDistance * NearDistance));

		// Y座標の追従
		AngleY = sinf(BulletVec.y / m_fHypotenuse);

		// 目的の角度の設定
		CCharacter::SetBulletRot({ AngleY,m_fAngle + D3DX_PI,0.0f });
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

	// 視野角
	float fView_Angle = VIEW_SCOPE_ANGLE;

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		// 画面に映るぎりぎりの位置
		D3DXVECTOR3 Reflected_Pos = {0.0f, 0.0f, 0.0f};
		D3DXVECTOR3 Reflected_PosVec = { 0.0f, 0.0f, 0.0f };

		// ターゲット出来るぎりぎりの位置
		Reflected_Pos.x = Camera->GetWorldPosV().x + sinf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		Reflected_Pos.z = Camera->GetWorldPosV().z + cosf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
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
		Reflected_PosVec = Reflected_Pos - WorldPosV;

		// 正規化
		D3DXVec3Normalize(&Reflected_PosVec, &Reflected_PosVec);

		// 視点から敵のベクトル
		EnemyVec = nearpos - WorldPosV;

		// 正規化
		D3DXVec3Normalize(&EnemyVec, &EnemyVec);

		// 外積の格納先
		float fCp = Reflected_PosVec.x * EnemyVec.z - Reflected_PosVec.z * EnemyVec.x;

		// 画面内に映っているか
		if (nCnt == 0)
		{
			if (fCp > 0.0f)
				continue;
			else
				break;
		}
		else
			if (fCp <= 0.0f)
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
	float Size_Speed = 10.0f;
	// アルファ値の加算減算の速度
	float Alpha_Speed = 1.0f / ((RETICLE_TRANSPARENCY_SIZE - RETICLE_SIZE) / Size_Speed);

	// レティクルの生成
	if (m_pReticle == nullptr && m_bReticle_Draw)
	{
		m_pReticle = CObject3D::Create({ m_Reticle_Pos }, { m_Reticle_Size }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,m_fReticle_Alpha }, true);
		m_pReticle->SetTexture(CTexture::TEXTURE_RETICLE);
	}

	// レティクルが生成されている場合
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
		m_pReticle->SetTexture(CTexture::TEXTURE_EFFECT_RETICLE);
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

	// レアリティの取得
	const int nRarity = pDrop->GetRarity();

	// 武器パーツではない場合
	if (Parts != PARTS_WEAPON)
	{
		SetPlayerParts(Parts, nWeapon, nRarity);
	}
	// 武器パーツの場合
	else
	{
		// 武器パーツの変更処理
		SetPlayerWeapon(nWeapon - CDrop_Weapon::MELEE_WEAPON_NONE, nRarity);
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
// パラメーターの設定処理
//============================================================================
void CPlayer::SettingParameter()
{
	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	// パラメーターの情報
	CPlayer_Parameter::PARAMETERS Parameter = {};

	int nLife = 0;				// 耐久値
	int nStamina = 0;			// スタミナ容量
	int nStan_Tolerance = 0;	// スタン許容値
	int nGravity = 0;			// 重量

	CPlayer_Parameter* pPlayer_Parameter = nullptr;
	CWeapon_Parameter* pWeapon_Parameter = nullptr;

	//パラメータの取得
	/*if (Mode == CApplication::MODE_TUTORIAL)
	{
		pParameter = CTutorial::GetPlayerParameter();
		pWeapon_Parameter = CTutorial::GetWeaponParameter();
	}
	else*/
	if (Mode == CApplication::MODE_GAME)
	{
		pPlayer_Parameter = CGame::GetPlayerParameter();
		pWeapon_Parameter = CGame::GetWeaponParameter();
	}

	// パーツ毎のパラメーター
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		switch (nCnt)
		{
		case 0:
			Parameter = pPlayer_Parameter->GetParameterJob(m_Parts_Job[nCnt]);
			break;
		case 1:
			Parameter = pPlayer_Parameter->GetParameterArms(m_Parts_Job[nCnt], m_nArms_Rarity);
			break;
		case 2:
			Parameter = pPlayer_Parameter->GetParameterLeg(m_Parts_Job[nCnt], m_nLeg_Rarity);
			break;
		default:
			break;
		}

		nLife += Parameter.nLife;
		nStamina += Parameter.nStamina;
		nStan_Tolerance += Parameter.nStan_Tolerance;
		nGravity += Parameter.nGravity;
	}

	CWeapon_Parameter::MELEE_WEAPON_PARAMETERS Melee_Parameter = {};

	// 武器パラメーター
	Melee_Parameter = pWeapon_Parameter->GetParameterMeleeWeapon(m_nWeapon_type, m_nWeapon_Rarity);
	m_nGravity += Melee_Parameter.nGravity;

	// 各パラメータの設定
	SetMaxLife(nLife);
	m_pEnergy_Gauge->SetMaxEnerugy(nStamina);
	m_nStan_Tolerance = nStan_Tolerance;
	m_nGravity = nGravity;
}

//============================================================================
// パーツの設定
//============================================================================
void CPlayer::SetPlayerParts(const PARTS parts, const int weapon, const int rarity)
{
	int nPartsFileIndex = 0;	// パーツの番号

	// 現在のレアリティの色
	float fRarity_Color = 0;

	// パーツファイルの最低値を設定
	switch (parts)
	{
	case CPlayer::PARTS_BODY:
		nPartsFileIndex = CParts_File::PARTS_PLAYER_BODY_1;
		break;
	case CPlayer::PARTS_ARMS:
		nPartsFileIndex = CParts_File::PARTS_PLAYER_ARMS_1;
		fRarity_Color = (float)m_nArms_Rarity;
		m_nArms_Rarity = rarity;
		break;
	case CPlayer::PARTS_LEG:
		nPartsFileIndex = CParts_File::PARTS_PLAYER_LEG_1;
		fRarity_Color = (float)m_nLeg_Rarity;
		m_nLeg_Rarity = rarity;
		break;
	default:
		break;
	}

	int nWeaponIndex = 0;	// 武器の番号

							// パーツの最低値を設定
	if (weapon >= CDrop_Weapon::LEG_SG01)
	{
		nWeaponIndex = CDrop_Weapon::LEG_SG01;
	}
	else if (weapon >= CDrop_Weapon::ARMS_SG01)
	{
		nWeaponIndex = CDrop_Weapon::ARMS_SG01;
	}
	//else if (nWeapon >= CDrop_Weapon::BODY_SG01)
	//{
	//	nWeaponIndex = CParts_File::PARTS_PLAYER_BODY_1;
	//}

	// パーツのジョブ情報の更新
	m_Parts_Job[parts] = (JOB)(weapon - nWeaponIndex);

	// パラメータの更新
	m_bChange_Parameter = true;

	// パーツの番号(パーツファイルの番号 + パーツの番号(パーツそのままの番号 - パーツの最低値))
	int nPartsIndex = nPartsFileIndex + (weapon - nWeaponIndex);

	// 指定したパーツの、パーツ変更処理
	GetParts(parts)->SetParts(nPartsIndex);

	// 変更するレアリティの色
	//const float nChange_Color = 0.1f * rarity;

	// レアリティによる色の変化
	const float fAddCol = -(rarity - fRarity_Color) * 0.05f;

	for (auto pParts : GetParts(parts)->GetModelAll())
	{
		pParts->AddColor({ fAddCol, fAddCol,fAddCol, 0.0f });
	}
}

//============================================================================
// 武器の設定
//============================================================================
void CPlayer::SetPlayerWeapon(const int weapon, const int rarity)
{
	m_nWeapon_type = weapon;
	m_nWeapon_Rarity = rarity;

	// 右手が使用されていない場合
	if (m_pRightWeapon == nullptr)
	{
		// 右手(腕[3])に武器を設定
		m_pRightWeapon = CWeapon::Create({ 1.0f, -6.0f, 0.0f }, { -D3DX_PI / 2.0f, 0.0f, 0.0f}, (CWeapon::WEAPON_TYPE)weapon, GetParts(PARTS_ARMS)->GetModel(4));
		m_pRightWeapon->SetDrawFlag(false);
	}
	else
	{	// 右手(腕[3])に武器を変更
		m_pRightWeapon->ChangeWeapon(weapon);
		m_pRightWeapon->SetDrawFlag(true);
	}

	// 左手が使用されていない場合
	if (m_pLeftWeapon == nullptr)
	{
		// 左手(腕[6])に素手を設定
		m_pLeftWeapon = CWeapon::Create({ -1.0f, -6.0f, 0.0f }, { -D3DX_PI / 2.0f, 0.0f, 0.0f }, CWeapon::WEAPON_KNUCKLE, GetParts(PARTS_ARMS)->GetModel(6));
		m_pLeftWeapon->SetDrawFlag(false);
	}
	else
	{
		// 左手(腕[6])に素手を設定
		m_pLeftWeapon->ChangeWeapon(CWeapon::WEAPON_KNUCKLE);
		m_pLeftWeapon->SetDrawFlag(true);
	}

	// 現在のモード
	CApplication::MODE Mode = CApplication::GetModeType();

	// 生成時に自身のポインタを敵キャラマネージャーに設定
	/*if (Mode == CApplication::MODE_TUTORIAL)
	{
		CTutorial::SetPlayerUI(CPlayerUi::UITYPE_ATTACK, weapon);
		CTutorial::SetPlayerUI(CPlayerUi::UITYPE_WEAPON, weapon);
	}
	else*/ if (Mode == CApplication::MODE_GAME)
	{
		CGame::SetPlayerUI(CPlayerUi::UITYPE_ATTACK, weapon);
		CGame::SetPlayerUI(CPlayerUi::UITYPE_WEAPON, weapon);
	}
}