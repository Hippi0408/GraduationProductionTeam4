//=============================================================================
//
// ボスキャラ　　　boss.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _BOSS_H_
#define _BOSS_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "enemy.h"

//---------------------------
// クラス宣言
//---------------------------
class CBoss : public CEnemy
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

	CBoss();
	virtual ~CBoss() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// モーションの切り替え

	static CBoss* Create(const D3DXVECTOR3 pos);

private:
	int m_nCharaIndex;					// 自身の番号

};

#endif// _BOSS_H_