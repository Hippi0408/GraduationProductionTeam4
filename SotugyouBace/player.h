//=============================================================================
//
// player.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "character.h"

class CBullet;
class CEnergy_Gauge;

//---------------------------
// �N���X�錾
//---------------------------
class CPlayer : public CCharacter
{
	static const int FIRST_MAX_LIFE = 100;		// �����ő�̗͂̒l
	static const float PLAYER_COLLISION_RADIUS;	// �v���C���[�̓����蔻��̑傫��
	static const float PLAYER_JUMP_POWER;		// �v���C���[�̃W�����v��

public:

	// ���f���̔z�u���
	enum MODEL
	{
		MODEL_BODY = 0,			// [0]��
		MODEL_HIP,				// [1]��
		MODEL_HEAD,				// [2]��
		MODEL_RIGHT_UPPER_ARM,	// [3]�E��r
		MODEL_RIGHT_FOREARM,	// [4]�E�O�r
		MODEL_RIGHT_ARM,		// [5]�E��
		MODEL_LEFT_UPPER_ARM,	// [6]����r
		MODEL_LEFT_FOREARM,		// [7]���O�r
		MODEL_LEFT_ARM,			// [8]����
		MODEL_RIGHT_THIGH,		// [9]�E��
		MODEL_RIGHT_SHIN,		// [10]�E��
		MODEL_RIGHT_LEG,		// [11]�E��
		MODEL_LEFT_THIGH,		// [12]����
		MODEL_LEFT_SHIN,		// [13]����
		MODEL_LEFT_LEG,			// [14]����
		MODEL_MAX,				// ���f���̍ő吔
	};

	// ���[�V�����̃^�C�v
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// �j���[�g����
		MOTION_WALK,		// ����
		MOTION_JUMP,		// �W�����v
		MOTION_LANDING,		// ���n
		MOTION_BOOST_RUN,	// �u�[�X�g�_�b�V��
		MOTION_MAX,
	};

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// ���[�V�����̐؂�ւ�
	void Hit(CMove_Object* pHit) override;

	void PlayerAttack();				// �v���C���[�̍U������
	void JumpStart();					// �v���C���[�̃W�����v����
	void JumpBoost();					// �v���C���[�̃W�����v�u�[�X�g����
	void Landing(const D3DXVECTOR3 pos) override;	// ���n����

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }
	//void SetEnergyGauge(CEnergy_Gauge *pEnergy) { m_pEnergy_Gauge = pEnergy; }

	const int GetCharaIndex() { return m_nCharaIndex; }
	//CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	int m_nCharaIndex;					// ���g�̔ԍ�
	//CEnergy_Gauge* m_pEnergy_Gauge;		// �G�l���M�[�Q�[�W
};

#endif// _PLAYER_H_