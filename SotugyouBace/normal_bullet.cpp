//==============================================================================================
//
// �ʏ�e�@�@�@normal_bullet.cpp
// Author : tutida ryousei
//
//==============================================================================================
#include"normal_bullet.h"
#include"object3D.h"
#include "application.h"
#include"enemy_manager.h"
#include "game.h"
#include "tutorial.h"

//==============================================================================================
// �R���X�g���N�^
//==============================================================================================
CNormal_Bullet::CNormal_Bullet(const PRIORITY priority) : CBullet(priority)
{
}

//==============================================================================================
// �f�X�g���N�^
//==============================================================================================
CNormal_Bullet::~CNormal_Bullet()
{
}

//==============================================================================================
// ����������
//==============================================================================================
HRESULT CNormal_Bullet::Init()
{
	CBullet::Init();

	// �e���G�ɓ͂��܂ł̎���
	float fHitCnt = m_fHypotenuse / GetSpeed_XZ();

	int nCnt = 0;
	if (m_bTarget)
	{
		// ���݂̃��[�h
		CApplication::MODE Mode = CApplication::GetModeType();

		CEnemyManager* pManager = nullptr;

		// ���[�h���ɓG�L������ǂݍ���
		if (Mode == CApplication::MODE_TUTORIAL)
		{
			pManager = CTutorial::GetEnemyManager();
		}
		else if (Mode == CApplication::MODE_GAME)
		{
			pManager = CGame::GetEnemyManager();
		}

		for (auto pEnemy : pManager->GetAllEnemy())
		{
			nCnt++;

			if (nCnt == m_nEnemy_Count)
			{
				// �^�[�Q�b�g���Ă���G�̈ʒu
				D3DXVECTOR3 Enemy_Pos = pEnemy->GetPos();
				// �ړ���
				D3DXVECTOR3 Enemy_Move = pEnemy->GetMove();

				// �e���͂��Ƃ��̓G�̈ʒu
				Enemy_Pos.x += (Enemy_Move.x * m_fSpeed * fHitCnt);
				Enemy_Pos.z += (Enemy_Move.z * m_fSpeed * fHitCnt);

				// �e����G�܂ł̃x�N�g��
				D3DXVECTOR3 Mob_Vec = Enemy_Pos - GetPos();
				D3DXVec3Normalize(&Mob_Vec, &Mob_Vec);
				SetMove(Mob_Vec);
			}
		}
	}

	return S_OK;
}

//==============================================================================================
// �I������
//==============================================================================================
void CNormal_Bullet::Uninit()
{
	CBullet::Uninit();
}

//==============================================================================================
// �X�V����
//==============================================================================================
void CNormal_Bullet::Update()
{
	CBullet::Update();
}

//==============================================================================================
// �`�揈��
//==============================================================================================
void CNormal_Bullet::Draw()
{
	CBullet::Draw();
}

//==============================================================================================
// ��������
//==============================================================================================
CNormal_Bullet *CNormal_Bullet::Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, D3DXVECTOR3 move, float hypotenuse, int enemy_cnt, float enemy_speed, bool target, const bool side, const CObject::PRIORITY priority)
{
	//�N���X�̐���
	CNormal_Bullet* pNormal_Bullet = new CNormal_Bullet(priority);

	//null�`�F�b�N
	if (pNormal_Bullet != nullptr)
	{
		pNormal_Bullet->SetPos(pos);
		pNormal_Bullet->SetMove(move);
		pNormal_Bullet->SetSize(size);
		pNormal_Bullet->SetPlayerSide(side);
		pNormal_Bullet->m_fHypotenuse = hypotenuse;
		pNormal_Bullet->m_nEnemy_Count = enemy_cnt;
		pNormal_Bullet->m_fSpeed = enemy_speed;
		pNormal_Bullet->m_bTarget = target;
		pNormal_Bullet->Init();

		// �e�I�u�W�F�N�g�̐���
		pNormal_Bullet->SetObj3D(CObject3D::Create(pos, size, priority));
		// �e�̃e�N�X�`��
		pNormal_Bullet->GetObj3D()->SetTexture(CTexture::TEXTURE_BULLET);

		// �r���{�[�h�̐ݒ�
		pNormal_Bullet->GetObj3D()->Setbillboard(true);
	}
	else
		assert(false);

	return pNormal_Bullet;
}