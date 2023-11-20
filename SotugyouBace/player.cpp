//=============================================================================
//
// player.cpp
// Author : Tanimoto Kosuke
//
//=============================================================================
#include "player.h"
#include "application.h"
#include "input.h"
#include "bullet.h"
#include "normal_bullet.h"
#include "homing_bullet.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "game.h"
#include "energy_gauge.h"
#include "tutorial.h"
#include "camera.h"
#include <vector>
#include"debugProc.h"
#include"object3D.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// �v���C���[�̓����蔻��̑傫��
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// �v���C���[�̃W�����v��
const float CPlayer::VIEW_SCOPE_ANGLE = 44.5f;		// �v���C���[�̎���p
const float CPlayer::RETICLE_TRANSPARENCY_SIZE = 300.0f;
const float CPlayer::RETICLE_SIZE = 200.0f;
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CPlayer::CPlayer()
{
	// �v���C���[�̏����l��ݒ�
	SetMaxLife(FIRST_MAX_LIFE);
	SetLife(FIRST_MAX_LIFE);
	SetRadius(PLAYER_COLLISION_RADIUS);
}

//=====================================
// �f�X�g���N�^
//=====================================
CPlayer::~CPlayer()
{
	// �v���C���[�}�l�[�W���[�̎��g���폜
	CApplication::GetPlayerManager()->PlayerRelease(m_nCharaIndex);
}

//============================================================================
// ����������
//============================================================================
HRESULT CPlayer::Init()
{
	// �v���C���[�̃��f����ǂݍ���
	SetParts(PARTS_BODY, "Data\\text\\Motion\\parts\\motion_Body.txt");
	SetParts(PARTS_LEG, "Data\\text\\Motion\\parts\\motion_Leg.txt");
	SetParts(PARTS_ARMS, "Data\\text\\Motion\\parts\\motion_Arms.txt");

	// �^�O�̐ݒ�
	SetTag(TAG_CHARACTER);

	// �v���C���[���ɐݒ�
	SetPlayerSide(true);

	// �����蔻��̐���
	SetCollision();

	m_bTarget = false;
	m_bReticle_Reset = true;
	m_Reticle_Size = { RETICLE_TRANSPARENCY_SIZE,RETICLE_TRANSPARENCY_SIZE };
	m_fReticle_Alpha = 0.0f;

	CCharacter::Init();

	return S_OK;
}

//============================================================================
// �I������
//============================================================================
void CPlayer::Uninit()
{
	if (m_pEnergy_Gauge != nullptr)
	{
		// �G�l���M�[�Q�[�W�̔j��
		m_pEnergy_Gauge->Uninit();
		m_pEnergy_Gauge = nullptr;
	}

	CCharacter::Uninit();
}

//============================================================================
// �X�V����
//============================================================================
void CPlayer::Update()
{
	// �^�[�Q�b�g
	Target();

	// ���[�V�����ԍ��̐ݒ�
	ChangeMotion();

	// �L�����N�^�[�̍X�V
	CCharacter::Update();
}

//============================================================================
// �`�揈��
//============================================================================
void CPlayer::Draw()
{
	CCharacter::Draw();
}

//============================================================================
// ���[�V�����ύX����
//============================================================================
void CPlayer::ChangeMotion()
{
	// ���n���[�V������ݒ�
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		// �p�[�c
		CParts* pParts = GetParts(nCnt);

		// ���n���[�V�������I�������ꍇ
		if (pParts->GetCurrentMotion() == MOTION_LANDING && pParts->GetMotionStop() == true)
		{
			pParts->SetMotion(MOTION_NEUTRAL);
		}
	}
}

//============================================================================
// �v���C���[�̍U������
//============================================================================
void CPlayer::PlayerAttack()
{
	// ���̎擾
	D3DXVECTOR3 pos = GetCenterPos();
	D3DXVECTOR3 rot = GetBulletRot();

	D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };

	// �e�̐���
	CNormal_Bullet::Create(pos, { 60.0f,60.0f }, pos_vec, m_fHypotenuse, m_nEnemy_Count, m_fEnemy_Speed, m_bReticle_Draw, true, PRIORITY_BACK);
	//CHoming_Bullet::Create(pos, rot, pos_vec, m_NearMob_Pos, m_nEnemy_Count, "Data/model/Weapon/knife.x", true, PRIORITY_BACK);
}

//============================================================================
// �v���C���[�̃W�����v����
//============================================================================
void CPlayer::JumpStart()
{
	// �ڒn���Ă���ꍇ�̂�
	if (GetGround() == true)
	{
		// �W�����v���[�V������ݒ�
		GetParts(PARTS_LEG)->SetMotion(MOTION_JUMP);

		// ������Ԃɂ���
		SetGround(false);

		// �㏸����
		AddMove({ 0.0f, PLAYER_JUMP_POWER, 0.0f });
	}
}

//============================================================================
// �v���C���[�̃W�����v�u�[�X�g����
//============================================================================
void CPlayer::JumpBoost()
{
	if (m_pEnergy_Gauge != nullptr)
	{
		// �󒆂ɂ���ꍇ�A�G�l���M�[���c���Ă���ꍇ
		if (!GetGround() && !m_pEnergy_Gauge->GetConsumption())
		{
			// �㏸����
			AddMove({ 0.0f, 0.5f, 0.0f });

			// �G�l���M�[�������
			m_pEnergy_Gauge->Consumption_Gauge();
		}
	}
}

//============================================================================
// �v���C���[�̒��n����
//============================================================================
void CPlayer::Landing(const D3DXVECTOR3 pos)
{
	// ���n���[�V������ݒ�
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		GetParts(nCnt)->SetMotion(MOTION_LANDING);
	}

	// �L�����N�^�[�̒��n����
	CCharacter::Landing(pos);
}

//============================================================================
// ��e����
//============================================================================
void CPlayer::Hit(CMove_Object* pHit)
{
	// ���g�ł͂Ȃ� ���� �v���C���[���ł͂Ȃ��ꍇ
	if (pHit != nullptr && GetPlayerSide() != pHit->GetPlayerSide())
	{
		TAG tag = pHit->GetTag();

		switch (tag)
		{
		case TAG_CHARACTER:
			break;
		case TAG_BULLET:
			// �e�̃_���[�W��Ԃ�
			Damage(pHit->GetPower());
			break;
		default:
			break;
		}
	}
}

//============================================================================
// �^�[�Q�b�g
//============================================================================
void CPlayer::Target()
{
	D3DXVECTOR3 Player_Pos = GetPos();				// �v���C���[�̈ʒu
	D3DXVECTOR3 Mob_Pos = { 0.0f,0.0f,0.0f };		// �G�̈ʒu
	m_NearMob_Pos = { 0.0f,0.0f,0.0f };				// ��ԋ߂��G�̈ʒu
	m_fTarget_Scope = 3000.0f;						// �^�[�Q�b�g��_���͈�
	float NearDistance = m_fTarget_Scope;			// �G�Ƃ̋���
	float NextNearDistance = 0.0f;					// ���ɋ߂��G�Ƃ̋���
	m_bTarget = false;								// �߂��ɓG�����邩
	bool bScreen = false;							// ��ʂɉf���Ă��邩
	float DistanceXZ = 0.0f;						// �v���C���[�ƓG��XZ���W�̋���
	D3DXVECTOR3 BulletVec = {0.0f,0.0f,0.0f};
	m_nEnemy_Count = 0;
	int nCnt = 0;

	while (true)
	{
		// �G���G�̏��
		for (auto pEnemy : CApplication::GetEnemyManager()->GetAllEnemy())
		{
			nCnt++;

			if (pEnemy->GetLife() > 0)
			{
				// �G�̈ʒu�̎擾
				Mob_Pos = pEnemy->GetCenterPos();

				// �v���C���[����G�̋���
				BulletVec = Mob_Pos - Player_Pos;

				// �����̎Z�o
				DistanceXZ = sqrtf(BulletVec.x * BulletVec.x
					+ BulletVec.z * BulletVec.z);

				// ����3000�ȏ�
				if (DistanceXZ > m_fTarget_Scope)
					continue;

				// �������ׂ�
				if (NearDistance >= DistanceXZ && NextNearDistance < DistanceXZ)
				{
					// �Z�����̋����ƈʒu����
					NearDistance = DistanceXZ;
					m_NearMob_Pos = Mob_Pos;
					m_nEnemy_Count = nCnt;
					m_fEnemy_Speed = pEnemy->GetSpeed();

					m_bTarget = true;

					// ��ʂɉf���Ă��鎞�����^�[�Q�b�g����
					bScreen = Target_Scope(m_NearMob_Pos);
				}
			}
		}

		if (m_bTarget != bScreen)
		{
			// �������߂�����ʂɉf���Ă��Ȃ��G�Ƃ̋���
			NextNearDistance = NearDistance;
			NearDistance = m_fTarget_Scope;
			nCnt = 0;
			m_bTarget = false;
		}
		else
			break;
	}

	if (m_bTarget && bScreen)
	{
		m_bReticle_Draw = true;

		// �v���C���[����G�̋���
		BulletVec = m_NearMob_Pos - GetPos();

		// �^�[�Q�b�g�����G�̕���
		float Angle = atan2(BulletVec.x, BulletVec.z);
		float AngleY = 0.0f;

		// �v���C���[����G�̒�������
		m_fHypotenuse = sqrt((BulletVec.y * BulletVec.y) + (NearDistance * NearDistance));

		// Y���W�̒Ǐ]
		AngleY = sinf(BulletVec.y / m_fHypotenuse);

		// �ړI�̊p�x�̐ݒ�
		CCharacter::SetBulletRot({ AngleY,Angle + D3DX_PI,0.0f });
	}
	else
	{// �^�[�Q�b�g�����Ȃ��ꍇ�͐��ʂɒe������
		m_bReticle_Draw = false;

		// �J�����̊p�x
		CCamera *Camera = CApplication::GetCamera();
		D3DXVECTOR3 rotCamera = Camera->GetRot();

		// �ړI�̊p�x�̐ݒ�
		CCharacter::SetBulletRot({ rotCamera.x + D3DX_PI,rotCamera.y + D3DX_PI ,rotCamera.z + D3DX_PI });

		m_NearMob_Pos = { 0.0f,0.0f,0.0f };
	}

	// ���e�B�N���̐ݒ�
	Reticle(m_NearMob_Pos);
}

//============================================================================
// �^�[�Q�b�g��_���͈�
//============================================================================
bool CPlayer::Target_Scope(D3DXVECTOR3 nearpos)
{
	// �J�����̊p�x
	CCamera *Camera = CApplication::GetCamera();
	D3DXVECTOR3 rotCamera = Camera->GetRot();

	// �v���C���[���璍���_�܂ł̃x�N�g��
	D3DXVECTOR3 CameraVec = Camera->GetWorldPosR() - GetPos();

	// ���K��
	D3DXVec3Normalize(&CameraVec, &CameraVec);

	// �v���C���[����G�̃x�N�g��
	D3DXVECTOR3 EnemyVec = nearpos - GetPos();

	// ���K��
	D3DXVec3Normalize(&EnemyVec, &EnemyVec);

	// ����
	float fInner = D3DXVec3Dot(&EnemyVec, &CameraVec);

	// �J�����̌��ɓG������ꍇ
	if (fInner < 0)
		return false;

	// ��ʂɉf�邬�肬��̈ʒu
	D3DXVECTOR3 Reflected_Pos[2] = {};
	D3DXVECTOR3 Reflected_PosVec[2] = {};

	// ����p
	float fView_Angle = VIEW_SCOPE_ANGLE;

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		// �^�[�Q�b�g�o���邬�肬��̈ʒu
		Reflected_Pos[nCnt].x = Camera->GetWorldPosV().x + sinf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		Reflected_Pos[nCnt].z = Camera->GetWorldPosV().z + cosf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		fView_Angle *= -1;

		// �J�����̎��_
		D3DXVECTOR3 WorldPosV = Camera->GetWorldPosV();

		// �J�����̎��_�����p�����炷
		if (nCnt == 0)
		{
			WorldPosV.x += sinf(rotCamera.y + D3DX_PI / 2) * 500;
			WorldPosV.z += cosf(rotCamera.y + D3DX_PI / 2) * 500;
		}
		else
		{
			WorldPosV.x += sinf(rotCamera.y - D3DX_PI / 2) * 500;
			WorldPosV.z += cosf(rotCamera.y - D3DX_PI / 2) * 500;
		}

		// �J�����̎��_����̃x�N�g��
		Reflected_PosVec[nCnt] = Reflected_Pos[nCnt] - WorldPosV;

		// ���K��
		D3DXVec3Normalize(&Reflected_PosVec[nCnt], &Reflected_PosVec[nCnt]);

		// ���_����G�̃x�N�g��
		EnemyVec = nearpos - WorldPosV;

		// ���K��
		D3DXVec3Normalize(&EnemyVec, &EnemyVec);

		// �O�ς̊i�[��
		float fCp[2] = {};

		// �O��
		fCp[nCnt] = Reflected_PosVec[nCnt].x * EnemyVec.z - Reflected_PosVec[nCnt].z * EnemyVec.x;

		// ��ʓ��ɉf���Ă��邩
		if (nCnt == 0)
		{
			if (fCp[nCnt] > 0.0f)
				continue;
			else
				break;
		}
		else
			if (fCp[nCnt] <= 0.0f)
				return true;
	}

	return false;
}

//============================================================================
// ���e�B�N��
//============================================================================
void CPlayer::Reticle(D3DXVECTOR3 target)
{
	// �^�[�Q�b�g�̈ʒu
	if (m_bReticle_Reset)
		m_Reticle_Pos = target;

	// �g��k���̑��x
	float Size_Speed = 7;
	// �A���t�@�l�̉��Z���Z�̑��x
	float Alpha_Speed = 1 / ((RETICLE_TRANSPARENCY_SIZE - RETICLE_SIZE) / Size_Speed);

	// ���e�B�N���̐���
	if (m_pReticle == nullptr && m_bReticle_Draw)
		m_pReticle = CObject3D::Create({ m_Reticle_Pos }, { m_Reticle_Size }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,m_fReticle_Alpha }, true);

	if (m_pReticle != nullptr)
	{
		if (m_bReticle_Draw)
		{
			// ���e�B�N���̈ړ�
			if (m_Reticle_Pos != target)
				m_Reticle_Pos += (target - m_Reticle_Pos) *  0.1f;

			if (m_Reticle_Size.x > RETICLE_SIZE)
			{
				// �T�C�Y�ƃA���t�@�l�̐ݒ�
				m_fReticle_Alpha += Alpha_Speed;
				m_Reticle_Size.x -= Size_Speed;
				m_Reticle_Size.y -= Size_Speed;
			}

			// �ʒu�̐ݒ�
			m_pReticle->SetPos(m_Reticle_Pos);

			m_bReticle_Reset = false;
		}
		else
		{
			if (m_Reticle_Size.x < RETICLE_TRANSPARENCY_SIZE)
			{
				// �T�C�Y�ƃA���t�@�l�̐ݒ�
				m_fReticle_Alpha -= Alpha_Speed;
				m_Reticle_Size.x += Size_Speed;
				m_Reticle_Size.y += Size_Speed;
			}
			else
				// ���e�B�N���̃��Z�b�g
				m_bReticle_Reset = true;
		}

		// �T�C�Y�ƐF�̐ݒ�
		m_pReticle->SetSize({ m_Reticle_Size });
		m_pReticle->SetCol({ 1.0f,1.0f,1.0f,m_fReticle_Alpha });
	}
}