//==============================================================================================
//
// 動くオブジェクト　　　move_object.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _MOVE_OBJECT_H_
#define	_MOVE_OBJECT_H_

#include"object.h"
#include"collision.h"

class CMove_Object : public CObject
{
public:
	// 移動オブジェクトのタグ
	enum TAG
	{
		TAG_NONE = 0,
		TAG_CHARACTER,		// キャラクタータグ
		TAG_BULLET,			// 弾タグ
		TAG_EXPLOSION,	// 爆発タグ
		TAG_MAX,
	};


	CMove_Object(const PRIORITY priority);
	~CMove_Object();

	virtual HRESULT Init();
	virtual void Uninit();

	virtual void Hit(CMove_Object* pHit) = 0;
	void CollisionDestroy();											// 当たり判定ポインタを消す処理

	void AddPos(const D3DXVECTOR3 pos) { m_pos += pos; }				// 位置の加算

	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }					// 位置の設定
	void SetCenterPos(const D3DXVECTOR3 pos) { m_CenterPos = pos; }		// 初期位置の設定
	void SetRadius(const float radius) { m_fRadius = radius; }			// 半径の設定
	void SetTag(TAG tag) { m_tag = tag; }								// タグの設定
	void SetPlayerSide(const bool side) { m_bPlayerSide = side; }		// プレイヤー側かどうかの設定
	void SetCollision() { m_pCollision = CCollision::Create(this); }	// 当たり判定の生成

	const D3DXVECTOR3 GetPos() { return m_pos; }						// 位置の取得
	const D3DXVECTOR3 GetCenterPos() { return m_pos + m_CenterPos; }	// 中心位置の取得
	virtual const int GetPower() { return NULL; }						// 威力の取得
	const float GetRadius() { return m_fRadius; }						// 半径の取得
	TAG GetTag() { return m_tag; }										// タグの取得
	const bool GetPlayerSide() { return m_bPlayerSide; }				// プレイヤー側かどうかの取得
	CCollision* GetCollision() { return m_pCollision; }					// 当たり判定の情報

private:
	D3DXVECTOR3 m_pos;			// 位置
	D3DXVECTOR3 m_CenterPos;	// 中心位置
	float m_fRadius;			// 半径
	TAG m_tag;					// タグ
	CCollision* m_pCollision;	// 当たり判定の情報
	bool m_bPlayerSide;			// プレイヤー側かどうか
};

#endif // !_MOVE_OBJECT_H_
