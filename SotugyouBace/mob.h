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
	static const int FIRST_MAX_LIFE = 100;		// �����ő�̗͂̒l
	static const float MOB_COLLISION_RADIUS;	// �{�X�̓����蔻��̑傫��
public:

	// ���f���̔z�u���
	enum Model
	{
		MODEL_BODY = 0,		// [0]��
		MODEL_HEAD,			// [1]��
		MODEL_RIGHT_ARM,	// [2]�E�r
		MODEL_LEFT_ARM,		// [3]���r
		MODEL_RIGHT_LEG,	// [4]�E�r
		MODEL_LEFT_LEG,		// [5]���r
		MODEL_MAX,			// ���f���̍ő吔
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

	//void ChangeMotion() override;		// ���[�V�����̐؂�ւ�
	void Destroy() override;			// �j�󏈗�

	static CMob* Create(const D3DXVECTOR3 pos, const int index);

	void SetMobIndex(int index) { m_nMob_Index = index; }

private:
	CMob_Life_Gauge *m_LifeGauge;
	int m_nMob_Index;
};

#endif// _MOB_H_