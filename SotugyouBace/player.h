//=============================================================================
//
// player.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "character.h"

class CBullet;
class CEnergy_Gauge;
class CObject3D;
class CDrop_Weapon;
class CWeapon;
class CEnemy;

//---------------------------
// クラス宣言
//---------------------------
class CPlayer : public CCharacter
{

	static const int FIRST_MAX_LIFE = 100;			// 初期最大体力の値
	static const float PLAYER_COLLISION_RADIUS;		// プレイヤーの当たり判定の大きさ
	static const float PLAYER_JUMP_POWER;			// プレイヤーのジャンプ力
	static const float VIEW_SCOPE_ANGLE;			// 画面に映るぎりぎりの位置
	static const float RETICLE_TRANSPARENCY_SIZE;	// レティクル透明時のサイズ
	static const float RETICLE_SIZE;				// レティクルのサイズ

public:

	// パーツの種類
	enum PARTS
	{
		PARTS_BODY = 0,			// 胴体
		PARTS_ARMS,				// 腕
		PARTS_LEG,				// 脚

		PARTS_MAX,
		PARTS_WEAPON,			// 武器
	};

	// モーションのタイプ
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// ニュートラル
		MOTION_WALK,		// 歩き
		MOTION_JUMP,		// ジャンプ
		MOTION_LANDING,		// 着地
		MOTION_BOOST_RUN,	// ブーストダッシュ
		MOTION_MAX,
	};

	// ジョブの種種類
	enum JOB
	{
		JOB_RUSH = 0,	// ラッシュ
		JOB_VANGUARD,	// ヴァンガード
		JOB_EAGLEEYE,	// イーグルアイ
		JOB_MARSHALL,	// マーシャル
		JOB_MECHANIC,	// メカニック
		JOB_RAIDER,		// レイダー
		JOB_ARKPHILIA,	// アークフィリア
		JOB_CONTROL,	// コントロール
		JOB_MAX
	};

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion();		// モーションの切り替え
	void Hit(CMove_Object* pHit) override;

	void PlayerAttack();				// プレイヤーの攻撃処理
	void JumpStart();					// プレイヤーのジャンプ処理
	void JumpBoost();					// プレイヤーのジャンプブースト処理
	void Landing(const D3DXVECTOR3 pos) override;	// 着地処理
	void Target();						// ターゲット
	bool Target_Scope(D3DXVECTOR3 nearpos);				// ターゲットを狙う範囲
	void Reticle(D3DXVECTOR3 target);	// レティクル
	void DropGet(CDrop_Weapon* pDrop);		// 落とし物を入手する処理

	void CollisionDropWeapon();			// 落ちてる武器の当たり判定

	void SettingParameter();			// パラメーターの設定処理

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }
	void SetEnergyGauge(CEnergy_Gauge *pEnergy) { m_pEnergy_Gauge = pEnergy; }
	void SetDropGet(const bool drop_get) { m_bDrop_Get = drop_get; };
	void SetAllJobIndex(const int index) { for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++) { m_Job[nCnt] = (JOB)index; } }
	void SetPlayerParts(const PARTS parts, const int weapon, const int rarity);
	void SetPlayerWeapon(const int weapon);


	const bool GetDropContact() { return m_bDrop_Contact; }
	const int GetCharaIndex() { return m_nCharaIndex; }
	CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	int m_nCharaIndex;		// 自身の番号
	float m_fTarget_Scope;	// ターゲットを狙う範囲
	bool m_bTarget;			// ターゲットがいるか
	bool m_bDrop_Contact;	// 落とし物との接触判定
	bool m_bDrop_Get;		// 落とし物を入手する判定

	CEnergy_Gauge* m_pEnergy_Gauge;		// エネルギーゲージ

	D3DXVECTOR3 m_NearMob_Pos;
	CObject3D *m_pReticle;				// レティクル
	D3DXVECTOR3 m_Reticle_Pos;
	D3DXVECTOR2 m_Reticle_Size;
	D3DXVECTOR2 m_Reticle_Tran_Size;
	float m_fReticle_Alpha;
	float m_fHypotenuse;
	bool m_bReticle_Draw;
	bool m_bReticle_Reset;
	int m_nEnemy_Count;
	float m_fEnemy_Speed;
	float m_fAngle;
	int m_nStan_Tolerance;				// スタン許容値
	int m_nGravity;						// 重量

	JOB m_Job[PARTS_MAX];				// プレイヤーのパーツ毎のジョブ種類
	int m_nRarity_Arms;					// 腕のレアリティ
	int m_nRarity_Leg;					// 脚のレアリティ
	CWeapon* m_pRightWeapon;			// 右手武器
	CWeapon* m_pLeftWeapon;				// 左手武器

};

#endif// _PLAYER_H_