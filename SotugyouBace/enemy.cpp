//=============================================================================
//
// enemy.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "enemy.h"
#include "enemy_manager.h"
#include "application.h"
#include "tutorial.h"
#include "game.h"

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CEnemy::CEnemy()
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �������Ɏ��g�̃|�C���^��G�L�����}�l�[�W���[�ɐݒ�
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CTutorial::GetEnemyManager()->SetEnemy(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CGame::GetEnemyManager()->SetEnemy(this);
	}
}

//=====================================
// �f�X�g���N�^
//=====================================
CEnemy::~CEnemy()
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �}�l�[�W���[���g�p���̏ꍇ�A������Ɏ��g�̃|�C���^��z�񂩂珜�O����
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		CEnemyManager* pManager = CTutorial::GetEnemyManager();
		if(pManager != nullptr) pManager->DestroyEnemy(this);
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		CEnemyManager* pManager = CGame::GetEnemyManager();
		if (pManager != nullptr) pManager->DestroyEnemy(this);
	}
}

//============================================================================
// ����������
//============================================================================
HRESULT CEnemy::Init()
{
	// �G���ɐݒ�
	SetPlayerSide(false);

	// �T�C�Y�̐ݒ�
	SetSize({ GetRadius(),GetRadius(),GetRadius() });

	// �����蔻��̐���
	SetCollision();

	CCharacter::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CEnemy::Uninit()
{
	CCharacter::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CEnemy::Update()
{
	// �L�����N�^�[�̍X�V
	CCharacter::Update();
}

//============================================================================
// �`�揈��
//============================================================================
void CEnemy::Draw()
{
	CCharacter::Draw();
}

//============================================================================
// ��e����
//============================================================================
void CEnemy::Hit(CMove_Object* pHit)
{
	// �q�b�g�����ړ��I�u�W�F�N�g���g�p���̏ꍇ
	if (pHit != nullptr && GetPlayerSide() != pHit->GetPlayerSide())
	{
		// �q�b�g�����ړ��I�u�W�F�N�g�̃^�O���擾
		TAG tag = pHit->GetTag();

		// �^�O�����ނ�I��
		switch (tag)
		{
		case TAG_CHARACTER:
			break;
		case TAG_BULLET:
			// �e�̃_���[�W��Ԃ�
			Damage(pHit->GetPower());
			break;
		case TAG_EXPLOSION:
			// �����̃_���[�W��Ԃ�
			Damage(pHit->GetPower());
			break;
		default:
			break;
		}
	}
}

//============================================================================
// �j�󏈗�
//============================================================================
void CEnemy::Destroy()
{
	CCharacter::Destroy();
}