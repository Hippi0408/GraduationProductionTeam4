//=============================================================================
//
// parts.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _PARTS_H_
#define _PARTS_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include"move_object.h"
#include "objectX.h"
#include "character.h"
#include "motion.h"
#include <vector>
#include <map>

//---------------------------
// �N���X�錾
//---------------------------
class CParts : public CMove_Object
{
	// ���f���Z�b�g
	struct MODEL_SET
	{
		D3DXVECTOR3 InitPos;	// �����ʒu
		D3DXVECTOR3 InitRot;	// ������]
		CObjectX* pModel;		// ���f��
		int nParentIndex;		// �e���f���̔ԍ�
	};

public:

	CParts(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CParts() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Motion();							// ���[�V�����̐ݒ�
	virtual void ChangeMotion();			// ���[�V�����̐؂�ւ�
	void Rotation();								// ��]�����֐U��������鏈��
	void NormalizeRot();							// �p�x�̐��K��
	void Hit(CMove_Object* pHit) override;

	void SetMotion(const int motion) { m_nMotion = motion; }
	void SetCurrentMotion(const int motion) { m_nCurrentMotion = motion; }
	
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetRotDest(const D3DXVECTOR3 rot) { m_rotDest = rot; }
	void AddRotDest(const D3DXVECTOR3 rot) { m_rotDest += rot; }

	CObjectX* SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename);		// ���f���p�[�c�̐ݒ�

	const bool GetMotionStop() { return m_bMotionStop; }	// ���݃��[�V�����̏I�������ǂݍ���
	const int GetMotion() { return m_nMotion; }
	const int GetCurrentMotion() { return m_nCurrentMotion; }
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	MODEL_SET GetModelSet(const int index) { return m_ModelSet[index]; }
	std::vector<CObjectX*> GetModelAll();

	static CParts* Create(const D3DXVECTOR3 pos, CMove_Object* parent, const bool side);

	void LoadFile(const char* Xfilename);

private:

	D3DXMATRIX m_mtxWorld;				// ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_posOld;				// �ߋ��̈ʒu
	D3DXVECTOR3 m_rot;					// ���݂̊p�x
	D3DXVECTOR3 m_rotDest;				// �ړI�̊p�x

	D3DXCOLOR m_col;					// ���f���̐F

	bool m_bMotionStop;					// ���݂̃��[�V�������~�܂�����
	int m_nMotion;						// ���[�V����
	int m_nCurrentMotion;				// ���݂̃��[�V�����ԍ�
	int m_nCountMotion;					// ���[�V�����J�E���^�[
	int m_nCurrentKey;					// ���݂̃L�[�ԍ�

	float m_fRotSpeed;					// ��]�̃X�s�[�h

	std::string m_name;					// ���g�̖��O
	std::vector<MODEL_SET> m_ModelSet;	// �L�����N�^�[�̃��f�����

	CCharacter* m_pParent;				// ���g�̐e�L�����̃|�C���^
};

#endif// _PARTS_H_