//==============================================================================================
//
// �ʏ�e�@�@�@normal_bullet.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _NORMAL_BULLET_H_
#define	_NORMAL_BULLET_H_

#include"bullet.h"

class CNormal_Bullet : public CBullet
{
public:
	CNormal_Bullet(const PRIORITY priority);
	~CNormal_Bullet();

	HRESULT Init() override;	// ����������
	void Uninit() override;		// �I������
	void Update() override;		// �X�V����
	void Draw() override;		// �`�揈��

	static CNormal_Bullet *Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, D3DXVECTOR3 move, float hypotenuse, int enemy_cnt, float enemy_speed, bool target, const bool side, const CObject::PRIORITY priority);

private:
	float m_fHypotenuse;
	float m_fSpeed;
	int m_nEnemy_Count;
	bool m_bTarget;
};

#endif // !_NORMAL_BULLET_H_
