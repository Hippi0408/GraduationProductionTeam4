//=============================================================================
//
// collision.cpp
// Author : Tutida Ryousei
//
//=============================================================================
#include "collision.h"
#include "collision_manager.h"
#include "application.h"
#include "tutorial.h"
#include "game.h"
#include "move_object.h"
#include "object3D.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCollision::CCollision()
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �������Ɏ��g�̃|�C���^�𓖂��蔻��}�l�[�W���[�ɐݒ�
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CTutorial::GetCollision_Manager()->SetCollision(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CGame::GetCollision_Manager()->SetCollision(this);
	}
	m_bDeath = false;
	m_bNoneHit = false;
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
	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCollision::Uninit()
{
	// �e�̓����蔻��|�C���^����������
	m_pParent->CollisionDestroy();

#ifdef _DEBUG
	// �f�o�b�O�I�u�W�F�N�g���g�p���̏ꍇ
	if (m_pDebugObj != nullptr)
	{
		m_pDebugObj->Uninit();
		m_pDebugObj = nullptr;
	}
#endif // _DEBUG

	Releace();
}

//=============================================================================
// �X�V����
//=============================================================================
void CCollision::Update()
{
#ifdef _DEBUG
	DebugObj();
#endif // _DEBUG

	// �����蔻��
	Collision();
}

//=============================================================================
// �����蔻��
//=============================================================================
void CCollision::Collision()
{
	// �q�b�g������ǂݍ��ޏꍇ
	if (m_bNoneHit == false)
	{
		// �����̈ʒu
		D3DXVECTOR3 pos = m_pParent->GetCenterPos();
		// ���a
		float fRadius = m_pParent->GetRadius();
		// �T�C�Y
		D3DXVECTOR3 Size = m_pParent->GetSize();

		// ���݂̃��[�h
		CApplication::MODE Mode = CApplication::GetModeType();

		CCollision_Manager* pCollision_Manager = nullptr;

		// ���[�h���Ƀv���C���[��ǂݍ���
		if (Mode == CApplication::MODE_TUTORIAL)
		{
			pCollision_Manager = CTutorial::GetCollision_Manager();
		}
		else if (Mode == CApplication::MODE_GAME)
		{
			pCollision_Manager = CGame::GetCollision_Manager();
		}

		// �S�Ă̓����蔻����ʂɔ���
		for (auto pCollision : pCollision_Manager->GetAllCollision())
		{
			// �����蔻�肪���݂���ꍇ && �����蔻�肪���g�ł͂Ȃ��ꍇ
			if (!pCollision->GetParent()->GetDeathFlag() && !pCollision->GetDeath() && pCollision != this)
			{
				// �����moveobject�̏��
				CMove_Object* pMove_Object = pCollision->GetParent();

				// ����̈ʒu
				D3DXVECTOR3 OtherPos = pMove_Object->GetCenterPos();
				bool bHit = false;

				if (pMove_Object->GetCollision_Type() == CMove_Object::COLLISION_TYPE_SHERER)
				{
					// ���a
					float fOtherRadius = pMove_Object->GetRadius();

					// �~���m�̓����蔻��̌v�Z
					bHit = Sphere_Collision(pos, fRadius, OtherPos, fOtherRadius);
				}
				else
				{
					// �O��̈ʒu
					D3DXVECTOR3 PosOld = m_pParent->GetPosOld();

					// �T�C�Y
					D3DXVECTOR3 OtherSize = pMove_Object->GetSize();

					// �~���m�̓����蔻��̌v�Z
					bHit = Block_Collision(pos, PosOld, Size, OtherPos, OtherSize);
				}

				// �q�b�g�����ꍇ
				if (bHit)
				{
					// ���q�b�g���Ă��܂�
					m_pParent->Hit(pMove_Object);
					pMove_Object->Hit(m_pParent);
				}
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

//=============================================================================
// ��`�̓����蔻��
//=============================================================================
bool CCollision::Block_Collision(const D3DXVECTOR3 pos, const D3DXVECTOR3 posold, const D3DXVECTOR3 size, const D3DXVECTOR3 otherpos, const D3DXVECTOR3 othersize)
{
	if (otherpos.x + othersize.x > pos.x - size.x
		&& otherpos.x - othersize.x < pos.x + size.x)
	{
		// �������O
		if (otherpos.z + othersize.z > pos.z - size.z
			&& otherpos.z + othersize.z <= posold.z - size.z)
		{
			// �����o��

			return true;
		}

		// ��O���牜
		else if (otherpos.z - othersize.z < pos.z + size.z
			&& otherpos.z - othersize.z >= posold.z + size.z)
		{
			return true;
		}
	}
	else if (otherpos.z + othersize.z > pos.z - size.z
		&& otherpos.z - othersize.z < pos.z + size.z)
	{
		// �E���獶
		if (otherpos.x + othersize.x > pos.x - size.x
			&& otherpos.x + othersize.x <= posold.x - size.x)
		{
			return true;
		}

		// ������E
		else if (otherpos.x - othersize.x < pos.x + size.x
			&& otherpos.x - othersize.x >= posold.x + size.x)
		{
			return true;
		}
	}

	return false;
}

// �f�o�b�O�p�֐��̏���
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

//=============================================================================
// �f�o�b�O�I�u�W�F�N�g�̏���
//=============================================================================
void CCollision::SetDebugObj()
{
	const float fRadius = m_pParent->GetRadius() * 2.0f;

	// �f�o�b�O�I�u�W�F�N�g�̐���
	m_pDebugObj = CObject3D::Create(m_pParent->GetCenterPos(), D3DXVECTOR2(fRadius, fRadius));

	// �F�̐ݒ�(�v���C���[�����ǂ��� ? ���F : �ԐF)
	m_pDebugObj->SetCol(m_pParent->GetPlayerSide() ? D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f) : D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f));
	m_pDebugObj->SetTexture(CTexture::TEXTURE_CIRCLE);
	m_pDebugObj->Setbillboard(true);
}
#endif // _DEBUG

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
			// �f�o�b�O�I�u�W�F�N�g�̐ݒ�
			pCollision->SetDebugObj();
#endif // _DEBUG

		}
	}

	return pCollision;
}