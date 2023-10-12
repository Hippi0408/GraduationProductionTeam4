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
	m_pParent;

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
			bool Hit = Sphere_Collision(pos, fRadius, { OtherPos.x, OtherPos.y, OtherPos.z }, fOtherRadius);

			// �q�b�g�����ꍇ
			if (Hit)
			{
				m_pParent->Hit();
				pMove_Object->Hit();
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
// ��������
//=============================================================================
CCollision *CCollision::Create(CMove_Object* pParent)
{
	CCollision *pCollision = new CCollision;

	if (pCollision != nullptr)
	{
		pCollision->Init();
		pCollision->m_pParent = pParent;
	}

	return pCollision;
}