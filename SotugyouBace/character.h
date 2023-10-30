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
#include "move_object.h"
#include "parts.h"
#include <vector>
#include <map>

//---------------------------
// クラス宣言
//---------------------------
class CCharacter : public CMove_Object
{
	static const float CHARACTER_FIRST_MOVE_SPEED;	// キャラクターの初期移動速度

	static const float CHARACTER_ROT_SPEED;			// キャラクターの回転する速度
	static const float CHARACTER_MOVE_INERTIE;		// キャラクターの移動慣性
	static const float CHARACTER_GRAVITY;			// キャラクターの重力

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
	virtual void Destroy();							// 自身を破壊する処理
	virtual void Landing(const D3DXVECTOR3 pos);	// 着地処理
	void FieldCollision();							// 床の当たり判定
	void Rotation();								// 回転方向へ振り向かせる処理
	void NormalizeRot();							// 角度の正規化
	virtual void Hit(CMove_Object* pHit) override = 0;

	void SetGround(const bool ground) { m_bGround = ground; }
	void SetLife(const int life) { m_nLife = life; }
	void SetMaxLife(const int maxlife) { m_nMaxLife = maxlife; }
	void SetSpeed(const float speed) { m_fSpeed = speed; }
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetMove(const D3DXVECTOR3 move) { m_move = move; }
	void AddMove(const D3DXVECTOR3 move) { m_move += move; }
	void SetRotDest(const D3DXVECTOR3 rot) { m_rotDest = rot; }
	void AddRotDest(const D3DXVECTOR3 rot) { m_rotDest += rot; }
	void SetBoost(const bool boost) { m_bBoost = boost; }
	void SetJump_Boost(const bool jumpboost) { m_bJump_Boost = jumpboost; }
	void SetJump_PressCount(const int jumpcount) { Jump_PressCount = jumpcount; }
	void AddJump_PressCount(const int jumpcount) { Jump_PressCount += jumpcount; }

	void SetParts(const int index, const char* Xfilename);				// パーツの設定処理
	//void ChangeParts(std::string name, const char* Xfilename);		// パーツの変更処理
	
	const bool GetGround() { return m_bGround; }
	const int GetLife() { return m_nLife; }
	const D3DXVECTOR3 GetMove() { return m_move; }
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	const D3DXMATRIX GetWorldMtx() { return m_mtxWorld; }
	CParts* GetParts(const int index) { return m_Parts[index]; }
	std::map<int, CParts*> GetAllParts() { return m_Parts; }
	const bool GetBoost() { return m_bBoost; }
	const bool GetJump_Boost() { return m_bJump_Boost; }
	const int GetJump_PressCount() { return Jump_PressCount; }

private:

	D3DXMATRIX m_mtxWorld;					// ワールドマトリックス
	D3DXVECTOR3 m_posOld;					// 過去の位置
	D3DXVECTOR3 m_move;						// 移動量
	D3DXVECTOR3 m_rot;						// 現在の角度
	D3DXVECTOR3 m_rotDest;					// 目的の角度

	D3DXCOLOR m_col;						// モデルの色

	bool m_bGround;							// 接地判定

	int m_nLife;							// 体力
	int m_nMaxLife;							// 最大体力

	float m_fSpeed;							// 移動速度
	float m_fRotSpeed;						// 回転のスピード

	bool m_bBoost;							// ブーストしているか
	bool m_bJump_Boost;						// ジャンプブーストしているか
	int Jump_PressCount;					// ジャンプの長押ししてる時間

	std::string m_name;						// 自身の名前
	std::map<int, CParts*> m_Parts;			// パーツ情報のポインタ
};

#endif// _CHARACTER_H_