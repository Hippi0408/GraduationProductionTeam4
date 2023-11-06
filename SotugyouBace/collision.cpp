//=============================================================================
//
// collision.cpp
// Author : Tutida Ryousei
//
//=============================================================================
#include "collision.h"
#include "application.h"
#include "collision_manager.h"
#include "move_object.h"

#ifdef _DEBUG
#include "object3D.h"
#endif

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCollision::CCollision()
{
	CApplication::GetCollision_Manager()->SetCollision(this);
	m_bDeath = false;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCollision::~CCollision()
{
	//CCollision_Manager* pManager = CApplication::GetCollision_Manager();

	//if (pManager != nullptr)
	//{
	//	// �����蔻�������
	//	pManager->DestroyCollision(this);
	//}
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCollision::Init()
{
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCollision::Uninit()
{
#ifdef _DEBUG
	// �f�o�b�O�I�u�W�F�N�g���g�p���̏ꍇ
	if (m_pDebugObj != nullptr)
	{
		m_pDebugObj->Uninit();
		m_pDebugObj = nullptr;
	}
#endif

	Releace();
}

//=============================================================================
// �X�V����
//=============================================================================
void CCollision::Update()
{
#ifdef _DEBUG
	DebugObj();
#endif

	// �����蔻��
	Collision();
}

//=============================================================================
// �����蔻��
//=============================================================================
void CCollision::Collision()
{
	// �����̈ʒu
	D3DXVECTOR3 pos = m_pParent->GetCenterPos();
	// ���a
	float fRadius = m_pParent->GetRadius();
	
	// �S�Ă̓����蔻����ʂɔ���
	for (auto pCollision : CApplication::GetCollision_Manager()->GetAllCollision())
	{
		// �����蔻�肪���݂���ꍇ && �����蔻�肪���g�ł͂Ȃ��ꍇ
		if (pCollision != nullptr && pCollision != this)
		{
			// �����moveobject�̏��
			CMove_Object* pMove_Object = pCollision->GetParent();

			// ����̈ʒu
			D3DXVECTOR3 OtherPos = pMove_Object->GetCenterPos();
			// ���a
			float fOtherRadius = pMove_Object->GetRadius();

			// �~���m�̓����蔻��̌v�Z
			bool bHit = Sphere_Collision(pos, fRadius, OtherPos, fOtherRadius);

			// �q�b�g�����ꍇ
			if (bHit)
			{
				m_pParent->Hit(pMove_Object);
				pMove_Object->Hit(m_pParent);
			}
		}
	}
}

//==============================================================================================
// �I�u�W�F�N�g���p���������̂̓����蔻��
//==============================================================================================
bool CCollision::Sphere_Collision(const D3DXVECTOR3 pos, const float radius, const D3DXVECTOR3 otherPos, const float otherRadius)
{
	// �ʒu���m�̋����̌v�Z�p�ϐ�
	D3DXVECTOR3 Distance = otherPos - pos;

	float Dis = sqrtf((otherPos.x - pos.x) * (otherPos.x - pos.x)
		+ (otherPos.z - pos.z) * (otherPos.z - pos.z));

	float DisY = otherPos.y - pos.y;
	if (DisY < 0)
		DisY *= -1;

	if (Dis <= radius + otherRadius
		&& DisY <= radius + otherRadius)
		return true;

	return false;
}

#ifdef _DEBUG
//=============================================================================
// �f�o�b�O�I�u�W�F�N�g�̏���
//=============================================================================
void CCollision::DebugObj()
{
	// �f�o�b�O�I�u�W�F�N�g���g�p���̏ꍇ
	if (m_pDebugObj != nullptr)
	{
		// �ʒu��ݒ�
		m_pDebugObj->SetPos(m_pParent->GetCenterPos());
	}
}
#endif

//=============================================================================
// ��������
//=============================================================================
CCollision* CCollision::Create(CMove_Object* pParent)
{
	CCollision* pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();

		// �e�|�C���^���g�p���̏ꍇ
		if (pParent != nullptr)
		{
			pCollision->m_pParent = pParent;

#ifdef _DEBUG
			const float fRadius = pCollision->m_pParent->GetRadius() * 2.0f;

			pCollision->m_pDebugObj = CObject3D::Create(pCollision->m_pParent->GetCenterPos(), D3DXVECTOR2(fRadius, fRadius));
			pCollision->m_pDebugObj->SetTexture(CTexture::TEXTURE_CIRCLE);
			pCollision->m_pDebugObj->SetCol({1.0f, 0.0f, 0.0f, 1.0f});
#endif
		}
	}

	return pCollision;
}