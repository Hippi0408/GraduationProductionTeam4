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

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// ���[�V�����̐؂�ւ�

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }

	const int GetCharaIndex() { return m_nCharaIndex; }

	void PlayerAttack();				// �v���C���[�̍U������

private:
	int m_nCharaIndex;					// ���g�̔ԍ�
};

#endif// _PLAYER_H_