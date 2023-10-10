//=============================================================================
//
// collision.cpp
// Author : Tutida Ryousei
//
//=============================================================================
#include"collision.h"
#include"game.h"
#include"character.h"
#include"bullet.h"
#include"application.h"
#include"player_manager.h"
#include"meshfield.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCollision::CCollision()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCollision::~CCollision()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCollision::Init()
{
	m_Pos = { 0.0f,0.0f,0.0f };
	m_OtherPos = { 0.0f,0.0f,0.0f };
	m_fRadius = 0.0f;
	m_fOtherRadius = 0.0f;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCollision::Uninit()
{

}

//=============================================================================
// �X�V����
//=============================================================================
void CCollision::Update()
{
	// ���̎擾
	m_pPlayerManager = CApplication::GetPlayerManager();	// �v���C���[�}�l�[�W���[
	m_pCharacter = m_pPlayerManager->GetPlayer(0);			// �v���C���[
	m_pBullet = m_pCharacter->GetBullet();					// �e
	m_pBoss = CGame::GetBoss();								// �{�X

	// �e�̓����蔻��
	Bullet_Collision();
}

//=============================================================================
// �`�揈��
//=============================================================================
void CCollision::Draw()
{

}

//=============================================================================
// ��������
//=============================================================================
CCollision *CCollision::Create()
{
	CCollision *pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();
	}

	return pCollision;
}

//=============================================================================
// �e�̓����蔻��
//=============================================================================
void CCollision::Bullet_Collision()
{
	// �ʒu�Ɣ��a�̎擾
	if (m_pBullet != nullptr)
	{
		// �e�̏��
		m_Pos = m_pBullet->GetPos();
		m_fRadius = m_pBullet->GetScale().x;

		if (m_pBoss != nullptr)
		{
			// �{�X�̏��
			m_OtherPos = m_pBoss->GetPos();
			m_fOtherRadius = m_pBoss->GetRadius();
		}

		// �~�̓����蔻��
		bool Collision = Sphere_Collision(m_Pos, m_fRadius, { m_OtherPos.x,m_OtherPos.y + 200,m_OtherPos.z }, 100);

		// �e�����������ꍇ
		if (Collision)
		{
			m_pBullet->SetLife(0);
		}

		// ���b�V���ƒe�̓����蔻��
		CMeshField *pMeshField = nullptr;
		pMeshField = CGame::GetMeshField();
		bool hit = false;

		if (pMeshField != nullptr)
		{
			pMeshField->MeshCollision(m_Pos);
			hit = pMeshField->GetHit();
		}
		if (hit)
		{
			pMeshField->Ground_Broken(m_Pos, 10.0f, 1);
			m_pBullet->SetLife(0);
		}
	}
}