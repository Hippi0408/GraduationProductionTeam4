//=============================================================================
//
// collision.h
// Author : Tutida Ryousei
//
//=============================================================================
#ifndef _COLLISION_H_
#define	_COLLISION_H_

#include"object.h"

// 前方宣言
class CPlayerManager;
class CPlayer;
class CBullet;
class CCharacter;

class CCollision : public CObject
{
public:
	CCollision();
	~CCollision();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	static CCollision *Create();

	void Bullet_Collision();

private:
	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3	m_OtherPos;
	float m_fRadius;
	float m_fOtherRadius;

	CPlayerManager *m_pPlayerManager;	// プレイヤーマネージャー
	CPlayer *m_pCharacter;				// プレイヤー
	CBullet *m_pBullet;					// 弾
	CCharacter *m_pBoss;				// ボス
};

#endif // !_COLLISION_H_
