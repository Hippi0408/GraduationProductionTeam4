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

//---------------------------
// �N���X�錾
//---------------------------
class CPlayer : public CCharacter
{
	static const int FIRST_MAX_LIFE = 100;	// �����ő�̗͂̒l
	static const float PLAYER_JUMP_POWER;	// �v���C���[�̃W�����v��

public:

	// ���f���̔z�u���
	enum Model
	{
		MODEL_BODY = 0,			// [0]��
		MODEL_HEAD,				// [1]��
		MODEL_RIGHT_UPPER_ARM,	// [2]�E��r
		MODEL_RIGHT_FOREARM,	// [3]�E�O�r
		MODEL_RIGHT_ARM,		// [4]�E��
		MODEL_LEFT_UPPER_ARM,	// [5]����r
		MODEL_LEFT_FOREARM,		// [6]���O�r
		MODEL_LEFT_ARM,			// [7]����
		MODEL_RIGHT_THIGH,		// [8]�E��
		MODEL_RIGHT_SHIN,		// [9]�E��
		MODEL_RIGHT_LEG,		// [10]�E��
		MODEL_LEFT_THIGH,		// [11]����
		MODEL_LEFT_SHIN,		// [12]����
		MODEL_LEFT_LEG,			// [13]����
		MODEL_MAX,				// ���f���̍ő吔
	};

	// ���[�V�����̃^�C�v
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// �j���[�g����
		MOTION_WALK,		// ����
		MOTION_JUMP,		// �W�����v
		MOTION_LANDING,		// ���n
		MOTION_MAX,
	};

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// ���[�V�����̐؂�ւ�

	void PlayerAttack();				// �v���C���[�̍U������
	void PlayerJump();					// �v���C���[�̃W�����v����
	void Landing(const D3DXVECTOR3 pos) override;	// ���n����

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }

	const int GetCharaIndex() { return m_nCharaIndex; }

private:
	int m_nCharaIndex;					// ���g�̔ԍ�
};

#endif// _PLAYER_H_