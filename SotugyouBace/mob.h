//=============================================================================
//
// ���u�L�����@�@�@mob.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _MOB_H_
#define _MOB_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "enemy.h"

class CMob_Life_Gauge;

//---------------------------
// �N���X�錾
//---------------------------
class CMob : public CEnemy
{
	static const int FIRST_MAX_LIFE = 2000;		// �����ő�̗͂̒l
	static const float MOB_COLLISION_RADIUS;	// �{�X�̓����蔻��̑傫��
	static const int DRAW_HP_DISTANCE = 3000;	// HP�Q�[�W��\�����鋗��
	static const int DRAW_DISTANCE = 7000;		// �G��\�����鋗��
public:

	// �p�[�c�̎��
	enum PARTS
	{
		PARTS_BODY = 0,			// ����

		PARTS_MAX
	};

	// ���[�V�����̃^�C�v
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// �j���[�g����
		MOTION_WALK,		// ����
		MOTION_MAX,
	};

	CMob();
	virtual ~CMob() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Destroy() override;			// �j�󏈗�
	void DrawLifeGauge();		// �̗̓Q�[�W�̕\��

	static CMob* Create(const D3DXVECTOR3 pos);

private:
	float m_fDistance;
};

#endif// _MOB_H_