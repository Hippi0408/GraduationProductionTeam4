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
#include"collision_manager.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCollision::CCollision()
{
	CApplication::GetCollision_Manager()->SetCollision(this);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCollision::~CCollision()
{
	CCollision_Manager* pManager = CApplication::GetCollision_Manager();

	if (pManager != nullptr)
	{
		pManager->DestroyCollision(this);
	}
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

	m_bCollision_Death = false;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCollision::Uninit()
{
	Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CCollision::Update()
{
	// ���̎擾
	m_pMove_Object;

	// �����蔻��
	Collision();
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
CCollision *CCollision::Create(CMove_Object* pParent)
{
	CCollision *pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();
		pCollision->m_pMove_Object = pParent;
	}

	return pCollision;
}

//=============================================================================
// �����蔻��
//=============================================================================
void CCollision::Collision()
{
	// �����̈ʒu
	D3DXVECTOR3 pos = m_pMove_Object->GetPos();
	// ���a
	float fRadius = m_pMove_Object->GetRadius();
	
	for (auto pCollision : CApplication::GetCollision_Manager()->GetAllCollision())
	{
		if (pCollision != nullptr && pCollision != this)
		{
			// �����moveobject�̏��
			CMove_Object* pMove_Object = pCollision->GetParent();

			// ����̈ʒu
			D3DXVECTOR3 OtherPos = pMove_Object->GetPos();
			// ���a
			float fOtherRadius = pMove_Object->GetRadius();

			bool Hit = Sphere_Collision(pos, 50, { OtherPos.x,OtherPos.y + 200,OtherPos.z }, 50);

			if (Hit)
			{
				m_pMove_Object->Hit();
				pMove_Object->Hit();
			}
			if (m_bCollision_Death)
			{
				return;
			}
		}
	}

	//	// ���b�V���ƒe�̓����蔻��
	//	CMeshField *pMeshField = nullptr;
	//	pMeshField = CGame::GetMeshField();
	//	bool bHit = false;

	//	if (pMeshField != nullptr)
	//	{
	//		// �n�ʂɓ���������
	//		pMeshField->MeshCollision(m_Pos);
	//		bHit = pMeshField->GetHit();
	//	}
	//	if (bHit)
	//	{
	//		// �n�ʂ��ւ��܂���
	//		pMeshField->Ground_Broken(m_Pos, 10.0f, 1);
	//		m_pBullet->SetLife(0);
	//	}
	//}
}