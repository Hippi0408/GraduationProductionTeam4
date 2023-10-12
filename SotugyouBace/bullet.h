//==============================================
//
// �e.h (Bullet.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _BULLET_H_				//���̃}�N����`������ĂȂ�������
#define  _BULLET_H_				//��d�C���N���[�h�h�~�̃}�N����`

//==============================================
// �C���N���[�h
//==============================================
#include "main.h"
#include "object3D.h"

//==============================================
// �e�N���X
//==============================================
class CBullet : public CObject3D
{
	static const int BULLET_LIFE = 50;			// �e�̎���
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

	void FieldCollision();				//���̓����蔻��
	void Hit() override;

	void SetLife(const int life) { m_nLife = life; }		// �e�̎����̐ݒ�
	void SetSpeed(const float speed) { m_fSpeed = speed; }	// �e�̑��x�̐ݒ�

	const int GetLife() { return m_nLife; }			// �e�̎����̎擾
	const float GetSpeed() { return m_fSpeed; }		// �e�̑��x�̎擾

	static CBullet* Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, const D3DXVECTOR3 move, const PRIORITY priority = PRIORITY_BACK);	// ����

private:
	//****************
	// private�ȕϐ�
	//****************
	D3DXVECTOR3 m_nPosOld;					// �O��̈ʒu
	int m_nLife;							// �e�̎���
	float m_fSpeed;							// �e�̃X�s�[�h
};
#endif
