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

//---------------------------
// クラス宣言
//---------------------------
class CPlayer : public CCharacter
{
	static const int FIRST_MAX_LIFE = 100;		// 初期最大体力の値
	static const float PLAYER_COLLISION_RADIUS;	// プレイヤーの当たり判定の大きさ
	static const float PLAYER_JUMP_POWER;		// プレイヤーのジャンプ力

public:

	// モデルの配置情報
	enum MODEL
	{
		MODEL_BODY = 0,			// [0]胴
		MODEL_HIP,				// [1]腰
		MODEL_HEAD,				// [2]頭
		MODEL_RIGHT_UPPER_ARM,	// [3]右上腕
		MODEL_RIGHT_FOREARM,	// [4]右前腕
		MODEL_RIGHT_ARM,		// [5]右手
		MODEL_LEFT_UPPER_ARM,	// [6]左上腕
		MODEL_LEFT_FOREARM,		// [7]左前腕
		MODEL_LEFT_ARM,			// [8]左手
		MODEL_RIGHT_THIGH,		// [9]右腿
		MODEL_RIGHT_SHIN,		// [10]右脛
		MODEL_RIGHT_LEG,		// [11]右足
		MODEL_LEFT_THIGH,		// [12]左腿
		MODEL_LEFT_SHIN,		// [13]左脛
		MODEL_LEFT_LEG,			// [14]左足
		MODEL_MAX,				// モデルの最大数
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

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// モーションの切り替え
	void Hit(CMove_Object* pHit) override;

	void PlayerAttack();				// プレイヤーの攻撃処理
	void JumpStart();					// プレイヤーのジャンプ処理
	void JumpBoost();					// プレイヤーのジャンプブースト処理
	void Landing(const D3DXVECTOR3 pos) override;	// 着地処理

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }
	//void SetEnergyGauge(CEnergy_Gauge *pEnergy) { m_pEnergy_Gauge = pEnergy; }

	const int GetCharaIndex() { return m_nCharaIndex; }
	//CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	int m_nCharaIndex;					// 自身の番号
	//CEnergy_Gauge* m_pEnergy_Gauge;		// エネルギーゲージ
};

#endif// _PLAYER_H_