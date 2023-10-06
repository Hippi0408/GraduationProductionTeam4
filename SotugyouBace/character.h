//=============================================================================
//
// character.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "object.h"
#include "objectX.h"
#include <vector>

//---------------------------
// �N���X�錾
//---------------------------
class CCharacter : public CObject
{
	static const float MOVE_INERTIE;		// �L�����N�^�[�̈ړ�����
	static const float CHARACTER_ROT_SPEED;	// �L�����N�^�[�̉�]���鑬�x

public:

	CCharacter(const PRIORITY priority = PRIORITY_BACK);
	virtual ~CCharacter() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Move();						// �ړ�����
	void Motion();						// ���[�V�����̐ݒ�
	virtual void ChangeMotion();		// ���[�V�����̐؂�ւ�
	void Rotation();					// ��]�����֐U��������鏈��
	void NormalizeRot();				// �p�x�̐��K��
	void Destroy();						// ���g��j�󂷂鏈��
	void Damage(const int value);		// �_���[�W����
	void Recovery(const int value);		// �񕜏���

	void LoadFile(const char* Xfilename);

	CObjectX* SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename);								// ���f���p�[�c�̐ݒ�
	void SetMotionData(const int maxkey, const int key, const int parts, const int motion, const int frame, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const bool loop);	// ���[�V�����l�̓ǂݍ���

	void SetMotion(const int motion) { m_nMotion = motion; }
	void SetCurrentMotion(const int motion) { m_nCurrentMotion = motion; }
	void SetLife(const int life) { m_nLife = life; }
	void SetMaxLife(const int maxlife) { m_nMaxLife = maxlife; }
	void SetSpeed(const float speed) { m_fSpeed = speed; }
	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetMove(const D3DXVECTOR3 move) { m_move = move; }
	void AddMove(const D3DXVECTOR3 move) { m_move += move; }
	void SetRotDest(const D3DXVECTOR3 rot) { m_rotDest = rot; }
	void AddRotDest(const D3DXVECTOR3 rot) { m_rotDest += rot; }
	void SetRadius(const float radius) { m_fRadius = radius; }
	
	const int GetMotion() { return m_nMotion; }
	const int GetCurrentMotion() { return m_nCurrentMotion; }
	const D3DXVECTOR3 GetPos() { return m_pos; }
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	const float GetRadius() { return m_fRadius; }
	CObjectX* GetModel(const int index) { return m_ModelSet.empty() ? nullptr : m_ModelSet[index].m_pModel; }
	std::vector<CObjectX*> GetModelAll();

private:

	// �L�[
	struct KEY
	{
		D3DXVECTOR3 KeyPos;
		D3DXVECTOR3 KeyRot;
	};

	// �L�[�Z�b�g
	struct KEY_SET
	{
		int nFrame;
		std::vector<KEY> aKey;
	};

	// ���[�V�����Z�b�g
	struct MOTION_SET
	{
		int nMaxKey;			// �L�[�̑���
		bool bLoop;				// ���[�v���邩
		bool bStop;				// ���[�V�������~�܂�����
		std::vector<KEY_SET> aKeySet;
	};
	std::vector<MOTION_SET> m_MotionSet;

	// ���f���Z�b�g
	struct MODEL_SET
	{
		D3DXVECTOR3 m_InitPos;
		D3DXVECTOR3 m_InitRot;
		CObjectX* m_pModel;
	};
	std::vector<MODEL_SET> m_ModelSet;

	D3DXMATRIX m_mtxWorld;				// ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_pos;					// �ʒu
	D3DXVECTOR3 m_posOld;				// �ߋ��̈ʒu
	D3DXVECTOR3 m_move;					// �ړ���
	D3DXVECTOR3 m_rot;					// ���݂̊p�x
	D3DXVECTOR3 m_rotDest;				// �ړI�̊p�x
	float m_fRadius;					// �����蔻��̔��a

	D3DXCOLOR m_col;					// ���f���̐F

	int m_nMotion;						// ���[�V����
	int m_nCurrentMotion;				// ���݂̃��[�V�����ԍ�
	int m_nCountMotion;					// ���[�V�����J�E���^�[
	int m_nCurrentKey;					// ���݂̃L�[�ԍ�

	int m_nLife;						// �̗�
	int m_nMaxLife;						// �ő�̗�

	float m_fSpeed;						// �ړ����x
	float m_fRotSpeed;					// ��]�̃X�s�[�h
};

#endif// _CHARACTER_H_