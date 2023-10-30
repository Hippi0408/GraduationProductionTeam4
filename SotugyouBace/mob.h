//=============================================================================
//
// モブキャラ　　　mob.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _MOB_H_
#define _MOB_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "enemy.h"

class CMob_Life_Gauge;

//---------------------------
// クラス宣言
//---------------------------
class CMob : public CEnemy
{
	static const int FIRST_MAX_LIFE = 100;		// 初期最大体力の値
	static const float MOB_COLLISION_RADIUS;	// ボスの当たり判定の大きさ
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

	CMob();
	virtual ~CMob() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	//void ChangeMotion() override;		// モーションの切り替え
	void Destroy() override;			// 破壊処理

	static CMob* Create(const D3DXVECTOR3 pos, const int index);

	void SetMobIndex(int index) { m_nMob_Index = index; }

private:
	CMob_Life_Gauge *m_LifeGauge;
	int m_nMob_Index;
};

#endif// _MOB_H_