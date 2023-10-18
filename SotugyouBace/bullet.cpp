//=============================================================================
//
// �e.cpp (Bullet.cpp)
// Author : Saito Shian
//
//=============================================================================

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "bullet.h"
#include "game.h"
#include "meshfield.h"
#include "object3D.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
const float CBullet::BULLET_SPEED = 15.0f;				// �e�̑��x
const float CBullet::BULLET_COLLISION_RADIUS = 30.0f;	// �e�̓����蔻��̑傫��
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CBullet::CBullet(const CObject::PRIORITY priority) : CMove_Object(priority)
{
	m_nLife = BULLET_LIFE;
	SetPower(BULLET_POWER);
	m_fSpeed = BULLET_SPEED;
	SetRadius(BULLET_COLLISION_RADIUS);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CBullet::~CBullet()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CBullet::Init()
{
	// �^�O�̐ݒ�
	SetTag(TAG_BULLET);

	// �I�u�W�F�N�g3D�̏���������
	CMove_Object::Init();

	//==================================================
	// �����o�ϐ��̏�����
	//==================================================
	// �����蔻��̐���
	SetCollision();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CBullet::Uninit()
{
	// �I�u�W�F�N�g3D�̏I������
	CMove_Object::Uninit();

	// 3D�I�u�W�F�N�g���g�p����Ă���ꍇ
	if (m_pObj3D != nullptr)
	{
		m_pObj3D->Uninit();
		m_pObj3D = nullptr;
	}
}

//=============================================================================
// �X�V����
//=============================================================================
void CBullet::Update()
{
	// �擾
	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 move = GetMove();
	D3DXVECTOR2 size = GetSize();

	//�e�̈ʒu�X�V
	pos += move * m_fSpeed;

	//�O��̈ʒu��ۑ�
	m_nPosOld = pos;

	// �ʒu�̐ݒ�
	SetPos(pos);

	// �I�u�W�F�N�g3D�̈ʒu��ݒ�
	m_pObj3D->SetPos(pos);
	m_pObj3D->SetSize(size);

	// ���̓����蔻��
	FieldCollision();

	// ���������炷
	m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
		return;
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CBullet::Draw()
{

}

//============================================================================
// ���̓����蔻��
//============================================================================
void CBullet::FieldCollision()
{
	// ���݂̈ʒu��萔�Ƃ��Ď擾
	const D3DXVECTOR3 pos = GetPos();

	CMeshField* pMesfField = CGame::GetMeshField();

	// ���̓����蔻�肩�獂����萔�Ƃ��Ď擾
	const float a = pMesfField->MeshCollision(pos);

	// ���b�V���t�B�[���h��艺�̈ʒu�ɂ���ꍇ
	if (a >= pos.y)
	{
		// �e��j�󂷂�
		Destroy();

		pMesfField->Ground_Broken(pos, 50.0f, 5);
	}
}

//=============================================================================
// ��e����
//=============================================================================
void CBullet::Hit(CMove_Object* /* pHit */)
{
	Destroy();
}

//=============================================================================
// �j�󏈗�
//=============================================================================
void CBullet::Destroy()
{
	Uninit();
}

//=============================================================================
// ��������
//=============================================================================
CBullet* CBullet::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, D3DXVECTOR3 move, const PRIORITY priority)
{
	//�N���X�̐���
	CBullet* pBullet = new CBullet(priority);

	//null�`�F�b�N
	if (pBullet != nullptr)
	{
		//����������
		pBullet->Init();
		//�ݒ菈��
		pBullet->SetPos(pos);
		pBullet->SetMove(move);
		pBullet->SetSize(size);

		// �e�I�u�W�F�N�g�̐���
		pBullet->m_pObj3D = CObject3D::Create(pos, size, priority);
		// �e�̃e�N�X�`��
		pBullet->m_pObj3D->SetTexture(CTexture::TEXTURE_BULLET);

		// �r���{�[�h�̐ݒ�
		pBullet->m_pObj3D->Setbillboard(true);
	}
	else
	{
		assert(false);
	}

	return pBullet;
}

