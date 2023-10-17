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

	CMove_Object(const PRIORITY priority);
	~CMove_Object();

	virtual HRESULT Init();
	virtual void Uninit();

	virtual void Hit() = 0;

	void AddPos(const D3DXVECTOR3 pos) { m_pos += pos; }				// 位置の加算

	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }					// 位置の設定
	void SetCenterPos(const D3DXVECTOR3 pos) { m_CenterPos = pos; }		// 初期位置の設定
	void SetRadius(const float radius) { m_fRadius = radius; }			// 半径の設定
	void SetCollision() { m_pCollision = CCollision::Create(this); }	// 当たり判定の生成

	const D3DXVECTOR3 GetPos() { return m_pos; }						// 位置の取得
	const D3DXVECTOR3 GetCenterPos() { return m_pos + m_CenterPos; }	// 中心位置の取得
	const float GetRadius() { return m_fRadius; }						// 半径の取得

private:
	D3DXVECTOR3 m_pos;			// 位置
	D3DXVECTOR3 m_CenterPos;	// 中心位置
	float m_fRadius;			// 半径
	CCollision* m_pCollision;	// 当たり判定の情報
};

#endif // !_MOVE_OBJECT_H_
