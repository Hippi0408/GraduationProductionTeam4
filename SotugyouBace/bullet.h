//==============================================
//
// �e.h (Bullet.h)
// Author : Saito Shian
// Author : Tanimoto Kosuke
//
//==============================================
#ifndef  _BULLET_H_				//���̃}�N����`������ĂȂ�������
#define  _BULLET_H_				//��d�C���N���[�h�h�~�̃}�N����`

//==============================================
// �C���N���[�h
//==============================================
#include "main.h"
#include "move_object.h"

//==============================================
// �O���錾
//==============================================
class CObject3D;

//==============================================
// �e�N���X
//==============================================
class CBullet : public CMove_Object
{
	static const int BULLET_LIFE = 50;			// �e�̎���
	static const int BULLET_POWER = 30;			// �e�̈З�
	static const float BULLET_SPEED;			// �e�̑��x
	static const float BULLET_COLLISION_RADIUS;	// �e�̓����蔻��̑傫��
public:

	//****************
	// public�Ȋ֐�
	//****************
	CBullet(const PRIORITY priority);		// �i���o�[�̃R���X�g���N�^
	~CBullet() override;					// �i���o�[�̃f�X�g���N�^

	HRESULT Init() override;				// ����������
	void Uninit() override;					// �I������
	void Update() override;					// �X�V����
	void Draw() override;					// �`�揈��

	void FieldCollision();					//���̓����蔻��
	void Hit(CMove_Object* pHit) override;	// ��e����
	void Destroy();							// �j�󏈗�

	void SetLife(const int life) { m_nLife = life; }		// �e�̎����̐ݒ�
	void SetSpeed(const float speed) { m_fSpeed = speed; }	// �e�̑��x�̐ݒ�
	void SetPower(const int power) { m_nPower = power; }
	void SetMove(const D3DXVECTOR3 move) { m_move = move; }	// �ړ��ʂ̐ݒ�
	void AddMove(const D3DXVECTOR3 move) { m_move += move; }// �ړ��ʂ̉��Z
	void SetSize(const D3DXVECTOR2 size) { m_size = size; }	// �T�C�Y�̐ݒ�

	const int GetLife() { return m_nLife; }					// �e�̎����̎擾
	const float GetSpeed() { return m_fSpeed; }				// �e�̑��x�̎擾
	const int GetPower() override { return m_nPower; }		// �З͂̎擾
	const D3DXVECTOR3 GetMove() { return m_move; }			// �ړ��ʂ̎擾
	const D3DXVECTOR2 GetSize() { return m_size; }			// �T�C�Y�̎擾

	static CBullet* Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, const D3DXVECTOR3 move,  const PRIORITY priority = PRIORITY_BACK);	// ����

private:
	//****************
	// private�ȕϐ�
	//****************
	D3DXVECTOR3 m_move;						// �e�̈ړ���
	D3DXVECTOR3 m_nPosOld;					// �O��̈ʒu
	D3DXVECTOR2 m_size;						// �e�̃T�C�Y
	int m_nLife;							// �e�̎���
	int m_nPower;							// �e�̈З�
	float m_fSpeed;							// �e�̃X�s�[�h

	CObject3D* m_pObj3D;					// �I�u�W�F�N�g3D�̃|�C���^
};
#endif
