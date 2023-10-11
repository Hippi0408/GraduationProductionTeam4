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

//---------------------------
// クラス宣言
//---------------------------
class CPlayer : public CCharacter
{
	static const int FIRST_MAX_LIFE = 100;	// 初期最大体力の値
	static const float PLAYER_JUMP_POWER;	// プレイヤーのジャンプ力

public:

	// モデルの配置情報
	enum Model
	{
		MODEL_BODY = 0,			// [0]胴
		MODEL_HEAD,				// [1]頭
		MODEL_RIGHT_UPPER_ARM,	// [2]右上腕
		MODEL_RIGHT_FOREARM,	// [3]右前腕
		MODEL_RIGHT_ARM,		// [4]右手
		MODEL_LEFT_UPPER_ARM,	// [5]左上腕
		MODEL_LEFT_FOREARM,		// [6]左前腕
		MODEL_LEFT_ARM,			// [7]左手
		MODEL_RIGHT_THIGH,		// [8]右腿
		MODEL_RIGHT_SHIN,		// [9]右脛
		MODEL_RIGHT_LEG,		// [10]右足
		MODEL_LEFT_THIGH,		// [11]左腿
		MODEL_LEFT_SHIN,		// [12]左脛
		MODEL_LEFT_LEG,			// [13]左足
		MODEL_MAX,				// モデルの最大数
	};

	// モーションのタイプ
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// ニュートラル
		MOTION_WALK,		// 歩き
		MOTION_JUMP,		// ジャンプ
		MOTION_LANDING,		// 着地
		MOTION_MAX,
	};

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// モーションの切り替え

	void PlayerAttack();				// プレイヤーの攻撃処理
	void PlayerJump();					// プレイヤーのジャンプ処理
	void Landing(const D3DXVECTOR3 pos) override;	// 着地処理

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }

	const int GetCharaIndex() { return m_nCharaIndex; }

private:
	int m_nCharaIndex;					// 自身の番号
};

#endif// _PLAYER_H_