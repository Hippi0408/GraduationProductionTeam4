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
	static const int FIRST_MAX_LIFE = 100;	// �����ő�̗͂̒l
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

	CBoss();
	virtual ~CBoss() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// ���[�V�����̐؂�ւ�

	static CBoss* Create(const D3DXVECTOR3 pos);

private:
	int m_nCharaIndex;					// ���g�̔ԍ�

};

#endif// _BOSS_H_