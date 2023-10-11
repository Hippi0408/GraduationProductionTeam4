//==============================================================================================
//
// 動くオブジェクト　　　move_object.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _MOVE_OBJECT_H_
#define	_MOVE_OBJECT_H_

#include"object.h"

class CCollision;

class CMove_Object : public CObject
{
public:
	CMove_Object(const PRIORITY priority);
	~CMove_Object();

	virtual HRESULT Init();
	virtual void Uninit();

	virtual void Hit() = 0;

	void AddPos(const D3DXVECTOR3 pos) { m_pos += pos; }			// 位置の加算

	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }				// 位置の設定
	void SetRadius(const float radius) { m_fRadius = radius; }		// 半径の設定

	D3DXVECTOR3 GetPos() { return m_pos; }		// 位置の取得
	float GetRadius() { return m_fRadius; }		// 半径の取得

private:
	D3DXVECTOR3 m_pos;			// 位置
	float m_fRadius;			// 半径
	CCollision* m_pCollision;	// 当たり判定の情報
};

#endif // !_MOVE_OBJECT_H_
