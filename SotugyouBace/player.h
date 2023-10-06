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
public:

	// ���f���̔z�u���
	enum Model
	{
		MODEL_BODY = 0,
		MODEL_MAX,
	};

	// ���[�V�����̃^�C�v
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// �j���[�g����
		MOTION_WALK,			// ����
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

private:
	int m_nCharaIndex;					// ���g�̔ԍ�
};

#endif// _PLAYER_H_