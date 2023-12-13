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
class CDrop_Weapon;
class CWeapon;
class CEnemy;

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

	// �p�[�c�̎��
	enum PARTS
	{
		PARTS_BODY = 0,			// ����
		PARTS_ARMS,				// �r
		PARTS_LEG,				// �r

		PARTS_MAX,
		PARTS_WEAPON,			// ����
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

	// �W���u�̎���
	enum JOB
	{
		JOB_RUSH = 0,	// ���b�V��
		JOB_VANGUARD,	// ���@���K�[�h
		JOB_EAGLEEYE,	// �C�[�O���A�C
		JOB_MARSHALL,	// �}�[�V����
		JOB_MECHANIC,	// ���J�j�b�N
		JOB_RAIDER,		// ���C�_�[
		JOB_ARKPHILIA,	// �A�[�N�t�B���A
		JOB_CONTROL,	// �R���g���[��
		JOB_MAX
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
	void DropGet(CDrop_Weapon* pDrop);		// ���Ƃ�������肷�鏈��

	void CollisionDropWeapon();			// �����Ă镐��̓����蔻��

	void SettingParameter();			// �p�����[�^�[�̐ݒ菈��

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }
	void SetEnergyGauge(CEnergy_Gauge *pEnergy) { m_pEnergy_Gauge = pEnergy; }
	void SetDropGet(const bool drop_get) { m_bDrop_Get = drop_get; };
	void SetAllJobIndex(const int index) { for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++) { m_Job[nCnt] = (JOB)index; } }
	void SetPlayerParts(const PARTS parts, const int weapon, const int rarity);
	void SetPlayerWeapon(const int weapon);


	const bool GetDropContact() { return m_bDrop_Contact; }
	const int GetCharaIndex() { return m_nCharaIndex; }
	CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	int m_nCharaIndex;		// ���g�̔ԍ�
	float m_fTarget_Scope;	// �^�[�Q�b�g��_���͈�
	bool m_bTarget;			// �^�[�Q�b�g�����邩
	bool m_bDrop_Contact;	// ���Ƃ����Ƃ̐ڐG����
	bool m_bDrop_Get;		// ���Ƃ�������肷�锻��

	CEnergy_Gauge* m_pEnergy_Gauge;		// �G�l���M�[�Q�[�W

	D3DXVECTOR3 m_NearMob_Pos;
	CObject3D *m_pReticle;				// ���e�B�N��
	D3DXVECTOR3 m_Reticle_Pos;
	D3DXVECTOR2 m_Reticle_Size;
	D3DXVECTOR2 m_Reticle_Tran_Size;
	float m_fReticle_Alpha;
	float m_fHypotenuse;
	bool m_bReticle_Draw;
	bool m_bReticle_Reset;
	int m_nEnemy_Count;
	float m_fEnemy_Speed;
	float m_fAngle;
	int m_nStan_Tolerance;				// �X�^�����e�l
	int m_nGravity;						// �d��

	JOB m_Job[PARTS_MAX];				// �v���C���[�̃p�[�c���̃W���u���
	int m_nRarity_Arms;					// �r�̃��A���e�B
	int m_nRarity_Leg;					// �r�̃��A���e�B
	CWeapon* m_pRightWeapon;			// �E�蕐��
	CWeapon* m_pLeftWeapon;				// ���蕐��

};

#endif// _PLAYER_H_