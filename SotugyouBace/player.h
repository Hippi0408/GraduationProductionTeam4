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

public:

	// モデルの配置情報
	enum Model
	{
		MODEL_BODY = 0,		// [0]体
		MODEL_HEAD,			// [1]頭
		MODEL_RIGHT_ARM,	// [2]右腕
		MODEL_LEFT_ARM,		// [3]左腕
		MODEL_RIGHT_LEG,	// [4]右脚
		MODEL_LEFT_LEG,		// [5]左脚
		MODEL_MAX,			// モデルの最大数
	};

	// モーションのタイプ
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// ニュートラル
		MOTION_WALK,		// 歩き
		MOTION_MAX,
	};

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// モーションの切り替え

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }

	const int GetCharaIndex() { return m_nCharaIndex; }

	void PlayerAttack();				// プレイヤーの攻撃処理

private:
	int m_nCharaIndex;					// 自身の番号
};

#endif// _PLAYER_H_