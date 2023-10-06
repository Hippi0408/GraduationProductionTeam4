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
#include "object.h"
#include "objectX.h"
#include <vector>

//---------------------------
// クラス宣言
//---------------------------
class CCharacter : public CObject
{
	static const float MOVE_INERTIE;		// キャラクターの移動慣性
	static const float CHARACTER_ROT_SPEED;	// キャラクターの回転する速度

public:

	CCharacter(const PRIORITY priority = PRIORITY_BACK);
	virtual ~CCharacter() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Move();						// 移動処理
	void Motion();						// モーションの設定
	virtual void ChangeMotion();		// モーションの切り替え
	void Rotation();					// 回転方向へ振り向かせる処理
	void NormalizeRot();				// 角度の正規化
	void Destroy();						// 自身を破壊する処理
	void Damage(const int value);		// ダメージ処理
	void Recovery(const int value);		// 回復処理

	void LoadFile(const char* Xfilename);

	CObjectX* SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename);								// モデルパーツの設定
	void SetMotionData(const int maxkey, const int key, const int parts, const int motion, const int frame, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const bool loop);	// モーション値の読み込み

	void SetMotion(const int motion) { m_nMotion = motion; }
	void SetCurrentMotion(const int motion) { m_nCurrentMotion = motion; }
	void SetLife(const int life) { m_nLife = life; }
	void SetMaxLife(const int maxlife) { m_nMaxLife = maxlife; }
	void SetSpeed(const float speed) { m_fSpeed = speed; }
	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetMove(const D3DXVECTOR3 move) { m_move = move; }
	void AddMove(const D3DXVECTOR3 move) { m_move += move; }
	void SetRotDest(const D3DXVECTOR3 rot) { m_rotDest = rot; }
	void AddRotDest(const D3DXVECTOR3 rot) { m_rotDest += rot; }
	void SetRadius(const float radius) { m_fRadius = radius; }
	
	const int GetMotion() { return m_nMotion; }
	const int GetCurrentMotion() { return m_nCurrentMotion; }
	const D3DXVECTOR3 GetPos() { return m_pos; }
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	const float GetRadius() { return m_fRadius; }
	CObjectX* GetModel(const int index) { return m_ModelSet.empty() ? nullptr : m_ModelSet[index].m_pModel; }
	std::vector<CObjectX*> GetModelAll();

private:

	// キー
	struct KEY
	{
		D3DXVECTOR3 KeyPos;
		D3DXVECTOR3 KeyRot;
	};

	// キーセット
	struct KEY_SET
	{
		int nFrame;
		std::vector<KEY> aKey;
	};

	// モーションセット
	struct MOTION_SET
	{
		int nMaxKey;			// キーの総数
		bool bLoop;				// ループするか
		bool bStop;				// モーションが止まったか
		std::vector<KEY_SET> aKeySet;
	};
	std::vector<MOTION_SET> m_MotionSet;

	// モデルセット
	struct MODEL_SET
	{
		D3DXVECTOR3 m_InitPos;
		D3DXVECTOR3 m_InitRot;
		CObjectX* m_pModel;
	};
	std::vector<MODEL_SET> m_ModelSet;

	D3DXMATRIX m_mtxWorld;				// ワールドマトリックス
	D3DXVECTOR3 m_pos;					// 位置
	D3DXVECTOR3 m_posOld;				// 過去の位置
	D3DXVECTOR3 m_move;					// 移動量
	D3DXVECTOR3 m_rot;					// 現在の角度
	D3DXVECTOR3 m_rotDest;				// 目的の角度
	float m_fRadius;					// 当たり判定の半径

	D3DXCOLOR m_col;					// モデルの色

	int m_nMotion;						// モーション
	int m_nCurrentMotion;				// 現在のモーション番号
	int m_nCountMotion;					// モーションカウンター
	int m_nCurrentKey;					// 現在のキー番号

	int m_nLife;						// 体力
	int m_nMaxLife;						// 最大体力

	float m_fSpeed;						// 移動速度
	float m_fRotSpeed;					// 回転のスピード
};

#endif// _CHARACTER_H_