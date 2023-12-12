//=============================================================================
//
// player_parameter.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _PLAYER_PARAMETER_H_
#define _PLAYER_PARAMETER_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "d3dx9.h"
#include "player.h"

//---------------------------
// �N���X�錾
//---------------------------
class CPlayer_Parameter
{

public:

	// �p�����[�^�[
	struct PARAMETERS
	{
		int nLife;					// �ϋv�l
		int nStamina;				// �X�^�~�i�e��
		int nStan_Tolerance;		// �X�^�����e�l
		int nGravity;				// �d��

									//Skill m_skill;					// �X�L���^�C�v
	};

	CPlayer_Parameter();
	~CPlayer_Parameter();

	HRESULT Init();
	void Uninit();

	void LoadFile();		// �p�����[�^�[�̓ǂݍ���

	// �v���C���[�p�����[�^�[�̎擾
	PARAMETERS GetParameter(const int job, const int parts) { return m_Parameter[job][parts]; }

private:

	PARAMETERS m_Parameter[CPlayer::JOB_MAX][CPlayer::PARTS_MAX];	// �W���u�����̃p�����[�^�[
};

#endif// _PLAYER_PARAMETER_H_