//=============================================================================
//
// character.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include"move_object.h"
#include "objectX.h"
#include "motion.h"
#include <vector>
#include <map>

class CEnergy_Gauge;
class CGauge_Manager;

//---------------------------
// クラス宣言
//---------------------------
class CCharacter : public CMove_Object
{
	static const float CHARACTER_FIRST_MOVE_SPEED;	// キャラクターの初期移動速度

	static const float CHARACTER_ROT_SPEED;			// キャラクターの回転する速度
	static const float CHARACTER_MOVE_INERTIE;		// キャラクターの移動慣性
	static const float CHARACTER_GRAVITY;			// キャラクターの重力

	// モデルセット
	struct MODEL_SET
	{
		D3DXVECTOR3 InitPos;	// 初期位置
		D3DXVECTOR3 InitRot;	// 初期回転
		CObjectX* pModel;		// モデル
		int nParentIndex;		// 親モデルの番号
	};

public:

	CCharacter(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CCharacter() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Move();
	void Damage(const int value);
	void Recovery(const int value);
	virtual void Destroy();						// 自身を破壊する処理
	virtual void Landing(const D3DXVECTOR3 pos);	// 着地処理
	void FieldCollision();							// 床の当たり判定
	void Motion();							// モーションの設定
	virtual void ChangeMotion();		// モーションの切り替え
	void Rotation();								// 回転方向へ振り向かせる処理
	void NormalizeRot();							// 角度の正規化
	virtual void Hit(CMove_Object* pHit) override = 0;

	void SetGround(const bool ground) { m_bGround = ground; }
	void SetMotion(const int motion) { m_nMotion = motion; }
	void SetCurrentMotion(const int motion) { m_nCurrentMotion = motion; }
	void SetLife(const int life) { m_nLife = life; }
	void SetMaxLife(const int maxlife) { m_nMaxLife = maxlife; }
	void SetSpeed(const float speed) { m_fSpeed = speed; }
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetMove(const D3DXVECTOR3 move) { m_move = move; }
	void AddMove(const D3DXVECTOR3 move) { m_move += move; }
	void SetRotDest(const D3DXVECTOR3 rot) { m_rotDest = rot; }
	void AddRotDest(const D3DXVECTOR3 rot) { m_rotDest += rot; }
	void SetBulletRot(const D3DXVECTOR3 bulletrot) { m_BulletRot = bulletrot; }
	void SetBoost(const bool boost) { m_bBoost = boost; }
	void SetJump_Boost(const bool jumpboost) { m_bJump_Boost = jumpboost; }

	void SetJump_PressCount(const int jumpcount) { m_nJump_PressCount = jumpcount; }
	void AddJump_PressCount(const int jumpcount) { m_nJump_PressCount += jumpcount; }
	void SetAvoidance(const bool avoidance) { m_bAvoidance = avoidance; }
	void SetAvoidanceCount(const int avoidancecount) { m_nAvoidance_Count = avoidancecount; }
	void SetEnergyGauge(CEnergy_Gauge *pEnergy) { m_pEnergy_Gauge = pEnergy; }
	void SetGaugeManager(CGauge_Manager *gauge) { m_pGaugeManager = gauge; }

	CObjectX* SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename);								// モデルパーツの設定

	const bool GetGround() { return m_bGround; }
	const bool GetMotionStop() { return m_bMotionStop; }	// 現在モーションの終了判定を読み込む
	const int GetMotion() { return m_nMotion; }
	const int GetCurrentMotion() { return m_nCurrentMotion; }
	const int GetLife() { return m_nLife; }
	const D3DXVECTOR3 GetMove() { return m_move; }
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	const D3DXVECTOR3 GetBulletRot() { return m_BulletRot; }
	MODEL_SET GetModelSet(const int index) { return m_ModelSet[index]; }
	std::vector<CObjectX*> GetModelAll();
	const bool GetBoost() { return m_bBoost; }
	const bool GetJump_Boost() { return m_bJump_Boost; }
	const int GetJump_PressCount() { return m_nJump_PressCount; }
	const bool GetAvoidance() { return m_bAvoidance; }
	CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }
	const CGauge_Manager *GetGaugeManager() { return m_pGaugeManager; }

	void LoadFile(const char* Xfilename);

private:

	D3DXMATRIX m_mtxWorld;				// ワールドマトリックス
	D3DXVECTOR3 m_posOld;				// 過去の位置
	D3DXVECTOR3 m_move;					// 移動量
	D3DXVECTOR3 m_rot;					// 現在の角度
	D3DXVECTOR3 m_rotDest;				// 目的の角度
	D3DXVECTOR3 m_BulletRot;			// 弾を撃つ角度

	D3DXCOLOR m_col;					// モデルの色

	bool m_bGround;						// 接地判定

	bool m_bMotionStop;					// 現在のモーションが止まったか
	int m_nMotion;						// モーション
	int m_nCurrentMotion;				// 現在のモーション番号
	int m_nCountMotion;					// モーションカウンター
	int m_nCurrentKey;					// 現在のキー番号

	int m_nLife;						// 体力
	int m_nMaxLife;						// 最大体力

	float m_fSpeed;						// 移動速度
	float m_fRotSpeed;					// 回転のスピード

	bool m_bBoost;						// ブーストしているか
	bool m_bJump_Boost;					// ジャンプブーストしているか
	int m_nJump_PressCount;				// ジャンプの長押ししてる時間
	bool m_bAvoidance;					// 回避しているか
	int m_nAvoidance_Count;				// 回避の硬直時間

	CEnergy_Gauge* m_pEnergy_Gauge;		// エネルギーゲージ
	CGauge_Manager *m_pGaugeManager;	// ゲージマネージャー

	std::string m_name;					// 自身の名前
	std::vector<MODEL_SET> m_ModelSet;	// キャラクターのモデル情報
};

#endif// _CHARACTER_H_