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
class CObject3D;

//---------------------------
// �N���X�錾
//---------------------------
class CPlayer : public CCharacter
{

	static const int FIRST_MAX_LIFE = 100;			// �����ő�̗͂̒l
	static const float PLAYER_COLLISION_RADIUS;		// �v���C���[�̓����蔻��̑傫��
	static const float PLAYER_JUMP_POWER;			// �v���C���[�̃W�����v��
	static const float VIEW_SCOPE_ANGLE;			// ��ʂɉf�邬�肬��̈ʒu
	static const float RETICLE_TRANSPARENCY_SIZE;	// ���e�B�N���������̃T�C�Y
	static const float RETICLE_SIZE;				// ���e�B�N���̃T�C�Y

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

	// �p�[�c�̎��
	enum PARTS
	{
		PARTS_BODY = 0,			// ����
		PARTS_ARMS,				// �r
		PARTS_LEG,				// �r
		//PARTS_WEAPON,			// ����

		PARTS_MAX
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

	void ChangeMotion();		// ���[�V�����̐؂�ւ�
	void Hit(CMove_Object* pHit) override;

	void PlayerAttack();				// �v���C���[�̍U������
	void JumpStart();					// �v���C���[�̃W�����v����
	void JumpBoost();					// �v���C���[�̃W�����v�u�[�X�g����
	void Landing(const D3DXVECTOR3 pos) override;	// ���n����
	void Target();						// �^�[�Q�b�g
	bool Target_Scope(D3DXVECTOR3 nearpos);				// �^�[�Q�b�g��_���͈�
	void Reticle(D3DXVECTOR3 target);	// ���e�B�N��

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }
	void SetEnergyGauge(CEnergy_Gauge *pEnergy) { m_pEnergy_Gauge = pEnergy; }

	const int GetCharaIndex() { return m_nCharaIndex; }
	CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	int m_nCharaIndex;		// ���g�̔ԍ�
	float m_fTarget_Scope;	// �^�[�Q�b�g��_���͈�
	bool m_bTarget;			// �^�[�Q�b�g�����邩

	CEnergy_Gauge* m_pEnergy_Gauge;		// �G�l���M�[�Q�[�W

	CObject3D *m_pReticle;				// ���e�B�N��
	D3DXVECTOR3 m_Reticle_Pos;
	D3DXVECTOR2 m_Reticle_Size;
	D3DXVECTOR2 m_Reticle_Tran_Size;
	float m_fReticle_Alpha;
	bool m_bReticle_Draw;
	bool m_bReticle_Reset;
};

#endif// _PLAYER_H_