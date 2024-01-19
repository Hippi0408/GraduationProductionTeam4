//=============================================================================
//
// �{�X�L�����@�@�@boss.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _BOSS_H_
#define _BOSS_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "enemy.h"

//---------------------------
// �N���X�錾
//---------------------------
class CBoss : public CEnemy
{
	static const int FIRST_MAX_LIFE = 10000;		// �����ő�̗͂̒l
	static const float BOSS_COLLISION_RADIUS;	// �{�X�̓����蔻��̑傫��
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
		MOTION_ENTRANCE,	// �o��
		MOTION_LANDING,		// ���n
		MOTION_MAX,
	};

	CBoss();
	virtual ~CBoss() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Destroy() override;			// �j�󏈗�
	void ChangeMotion();
	void Landing(const D3DXVECTOR3 pos) override;	// ���n����

	static CBoss* Create(const D3DXVECTOR3 pos);

private:
	bool m_bOpening;
};

#endif// _BOSS_H_