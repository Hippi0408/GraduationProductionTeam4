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
#include "objectX.h"
#include "particle_emitter.h"
#include "tutorial.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
const float CBullet::BULLET_SPEED = 50.0f;				// �e�̑��x
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
	// 3D�I�u�W�F�N�g���g�p����Ă���ꍇ
	if (m_pObj3D != nullptr)
	{
		m_pObj3D->Uninit();
		m_pObj3D = nullptr;
	}
	if (m_pObjX != nullptr)
	{
		m_pObjX->Uninit();
		m_pObjX = nullptr;
	}

	// �I�u�W�F�N�g3D�̏I������
	CMove_Object::Uninit();
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
	if (m_pObj3D != nullptr)
	{
		m_pObj3D->SetPos(pos);
		m_pObj3D->SetSize(size);
	}
	if (m_pObjX != nullptr)
	{
		m_pObjX->SetPos(pos);
	}

	// ���������炷
	m_nLife--;
	if (m_nLife <= 0)
	{
		Uninit();
		return;
	}

	// ���̓����蔻��
	FieldCollision();

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

	CMeshField* pMeshField = nullptr;

	if(CApplication::GetModeType() == CApplication::MODE_GAME)
		pMeshField = CGame::GetMeshField();
	else if(CApplication::GetModeType() == CApplication::MODE_TUTORIAL)
		pMeshField = CTutorial::GetMeshField();

	if (pMeshField != nullptr)
	{
		// ���̓����蔻�肩�獂����萔�Ƃ��Ď擾
		const float a = pMeshField->MeshCollision(pos);

		// ���b�V���t�B�[���h��艺�̈ʒu�ɂ���ꍇ
		if (a >= pos.y)
		{
			//pMeshField->Ground_Broken(pos, 50.0f, 5);

			// �e��j�󂷂�
			Destroy();
		}
	}
}

//=============================================================================
// ��e����
//=============================================================================
void CBullet::Hit(CMove_Object* pHit)
{
	// �e�ł͖����ꍇ && �����T�C�h�ł͂Ȃ��ꍇ
	if (pHit->GetTag() != TAG_BULLET && GetPlayerSide() != pHit->GetPlayerSide())
	{
		Destroy();
	}
}

//=============================================================================
// �j�󏈗�
//=============================================================================
void CBullet::Destroy()
{
	// �U���p�[�e�B�N��
	std::move(CParticleEmitter::Create("Attack", GetPos()));

	Uninit();
}

//=============================================================================
// ��������
//=============================================================================
CBullet* CBullet::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, D3DXVECTOR3 move, const bool side, const PRIORITY priority)
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
		pBullet->SetPlayerSide(side);

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

