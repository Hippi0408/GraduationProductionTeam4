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
#include "diffusion_bullet.h"
#include "parabola_bullet.h"
#include "player_manager.h"
#include "enemy_manager.h"
#include "drop_manager.h"
#include "game.h"
#include "tutorial.h"
#include "energy_gauge.h"
#include "camera.h"
#include <vector>
#include"debugProc.h"
#include"object3D.h"
#include "drop_weapon.h"
#include "weapon.h"
#include "player_parameter.h"
#include "weapon_parameter.h"
#include "weapon_attack.h"

const float CPlayer::PLAYER_COLLISION_RADIUS = 30.0f;	// �v���C���[�̓����蔻��̑傫��
const float CPlayer::PLAYER_JUMP_POWER = 10.0f;			// �v���C���[�̃W�����v��
const float CPlayer::VIEW_SCOPE_ANGLE = 44.3f;		// �v���C���[�̎���p
const float CPlayer::RETICLE_TRANSPARENCY_SIZE = 300.0f;
const float CPlayer::RETICLE_SIZE = 200.0f;
//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CPlayer::CPlayer()
{
	// �v���C���[�̏����l��ݒ�
	//SetMaxLife(FIRST_MAX_LIFE);
	//SetLife(FIRST_MAX_LIFE);
	SetRadius(PLAYER_COLLISION_RADIUS);
}

//=====================================
// �f�X�g���N�^
//=====================================
CPlayer::~CPlayer()
{

}

//============================================================================
// ����������
//============================================================================
HRESULT CPlayer::Init()
{
	// �v���C���[�̃��f����ǂݍ���
	SetParts(PARTS_BODY, CParts_File::PARTS_PLAYER_BODY_1 + m_Parts_Job[PARTS_BODY], CMotion::MOTION_PLAYER_BODY);
	SetParts(PARTS_ARMS, CParts_File::PARTS_PLAYER_ARMS_1 + m_Parts_Job[PARTS_ARMS], CMotion::MOTION_PLAYER_ARMS);
	SetParts(PARTS_LEG, CParts_File::PARTS_PLAYER_LEG_1 + m_Parts_Job[PARTS_LEG], CMotion::MOTION_PLAYER_LEG);
	SetPlayerWeapon(CWeapon::WEAPON_KNUCKLE, 0);

	// �p�����[�^�̐ݒ�
	SettingParameter();

	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �������Ɏ��g�̃|�C���^��G�L�����}�l�[�W���[�ɐݒ�
	/*if (Mode == CApplication::MODE_TUTORIAL)
	{
	CTutorial::SetPlayerUI(CPlayerUi::UITYPE_SUPPORT, m_Job[PARTS_BODY]);
	}
	else*/ if (Mode == CApplication::MODE_GAME)
	{
		CGame::SetPlayerUI(CPlayerUi::UITYPE_SUPPORT, m_Parts_Job[PARTS_BODY]);
	}

	// �^�O�̐ݒ�
	SetTag(TAG_CHARACTER);

	// �v���C���[���ɐݒ�
	SetPlayerSide(true);

	// �T�C�Y�̐ݒ�
	SetSize({ GetRadius(),GetRadius(),GetRadius() });

	// �����蔻��̐���
	SetCollision();

	m_bTarget = false;
	m_bReticle_Reset = true;
	m_bDrop_Contact = false;
	m_bDrop_Get = false;
	m_bChange_Parameter = false;
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
	// �E�蕐��̏I��
	if(m_pRightWeapon != nullptr)
	{
		m_pRightWeapon->Uninit();
		m_pRightWeapon = nullptr;
	}
	// ���蕐��̏I��
	if (m_pLeftWeapon != nullptr)
	{
		m_pLeftWeapon->Uninit();
		m_pLeftWeapon = nullptr;
	}

	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	CPlayerManager* pPlayerManager = nullptr;

	// �v���C���[�}�l�[�W���[�̎��g���폜
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pPlayerManager = CTutorial::GetPlayerManager();
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pPlayerManager = CGame::GetPlayerManager();
	}
	if (pPlayerManager != nullptr)
	{
		pPlayerManager->PlayerRelease(m_nCharaIndex);

		if (m_pEnergy_Gauge != nullptr)
		{
			// �G�l���M�[�Q�[�W�̔j��
			m_pEnergy_Gauge->Uninit();
			m_pEnergy_Gauge = nullptr;
		}

		CCharacter::Uninit();
	}
}

//============================================================================
// �X�V����
//============================================================================
void CPlayer::Update()
{
	// �p�����[�^�[�̕ύX���������ꍇ�Ƀp�����[�^�[��ݒ肵��������
	if (m_bChange_Parameter == true) SettingParameter();

	// �^�[�Q�b�g
	Target();

	// �����Ă镐��̓����蔻��
	CollisionDropWeapon();

	// ���[�V�����ԍ��̐ݒ�
	ChangeMotion();

	// �v���C���[�̍U������
	PlayerAttack();

	// �L�����N�^�[�̍X�V
	CCharacter::Update();
	//CDebugProc::Print("�v���C���[���C�t�F%d / %d\n", GetLife(), GetMaxLife());
	//CDebugProc::Print("�r�p�[�c�F%d\n�r�p�[�c : %d\n", m_nRarity_Arms, m_nRarity_Leg);
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

		// ���[�V���������[�v���Ȃ��ꍇ
		if (pParts->GetMotionLoop() == false && pParts->GetMotionStop() == true)
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
	// �U�����肪�^�̏ꍇ�A�U��������ǂݍ��ݑ�����
	if (m_bPlayer_Attack == true)
	{
		const int nWeaponType = m_nWeapon_type + CDrop_Weapon::MELEE_WEAPON_NONE;

		if (nWeaponType < CDrop_Weapon::MELEE_WEAPON_MAX)
		{
			MeleeWeaponAttack();
		}
		else
		{
			// ���̎擾
			D3DXVECTOR3 pos = GetCenterPos();
			D3DXVECTOR3 rot = GetBulletRot();

			D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };

			// �e�̐���
			CNormal_Bullet::Create(pos, { 60.0f,60.0f }, pos_vec, m_fHypotenuse, m_pEnemy, m_fEnemy_Speed, m_bReticle_Draw, true, PRIORITY_BACK);
			/*CHoming_Bullet::Create(pos, rot, pos_vec, m_NearMob_Pos, "Data/model/Weapon/knife.x", true, PRIORITY_BACK);
			CDiffusion_Bullet::Create(pos, { 30.0f,30.0f }, pos_vec, 10, true, PRIORITY_BACK);
			CParabola_Bullet::Create(pos, pos_vec, m_fHypotenuse, rot, "Data/model/Weapon/knife.x", true, PRIORITY_BACK);*/
		}
	}
}

//============================================================================
// �ߐڕ���̍U������
//============================================================================
void CPlayer::MeleeWeaponAttack()
{
	// ����ԍ�
	int nWeaponNumber = 0;

	// �ߐڕ���̍Œ�l���傫���ꍇ
	if (m_nWeapon_type >= CWeapon::MELEE_WEAPON_STABBING_LANCE)
	{
		// ����̍Œ�l�������l�ɐݒ�
		nWeaponNumber = MOTION_POKE_1;
	}
	// �ߐڕ���̍Œ�l���傫���ꍇ
	else if (m_nWeapon_type >= CWeapon::MELEE_WEAPON_SLASH_SAMURAI_SWORD)
	{
		// ����̍Œ�l�������l�ɐݒ�
		nWeaponNumber = MOTION_SLASH_1;
	}
	// �f��̍Œ�l���傫���ꍇ
	else
	{
		// ����̍Œ�l�������l�ɐݒ�
		nWeaponNumber = MOTION_FIST_1;
	}

	// ���[�V�����ԍ�
	const int nMotion = nWeaponNumber + m_nAdditional_Attack;

	// ���[�V�������
	CMotion* pMotion = CApplication::GetMotion();

	// �U���J�n����
	if (m_nAttackRate_Counter == 0)
	{
		// (�r���[�V�����̑S�t���[���� - 1) ���v��
		CMotion::MotionPattern pMotionPattern = pMotion->GetMotionPattern(nMotion, CMotion::m_cMotionFileName[PARTS_ARMS]);

		// ���[�V�����S�̂̕b����ݒ�
		for (int nCnt = 0; nCnt < pMotionPattern.nMaxKey - 1; nCnt++)
		{
			m_nAttackRate_Max_Counter += pMotionPattern.aKeySet[nCnt].nFrame;
		}

		// �U�����[�V������ݒ�
		for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
		{
			// �p�[�c
			CParts* pParts = GetParts(nCnt);

			// �U�����[�V���� + �ǉ��U���̉�
			pParts->SetMotion(nMotion);
		}
	}
	// 0�Ԗڂ̍U���I�����ɍU�����s��
	else if (m_nAttackRate_Counter == pMotion->GetMotionPattern(nMotion, CMotion::m_cMotionFileName[PARTS_ARMS]).aKeySet[0].nFrame)
	{
		// ���݂̃��[�h
		CApplication::MODE Mode = CApplication::GetModeType();

		CWeapon_Parameter::MELEE_WEAPON_PARAMETERS Melee_Parameter = {};

		CWeapon_Parameter* pWeapon_Parameter = nullptr;

		//�p�����[�^�̎擾
		/*if (Mode == CApplication::MODE_TUTORIAL)
		{
		pWeapon_Parameter = CTutorial::GetWeaponParameter();
		}
		else*/
		if (Mode == CApplication::MODE_GAME)
		{
			pWeapon_Parameter = CGame::GetWeaponParameter();
		}

		// ����p�����[�^�[
		Melee_Parameter = pWeapon_Parameter->GetParameterMeleeWeapon(m_nWeapon_type, m_nWeapon_Rarity);

		// ���̎擾
		D3DXVECTOR3 pos = GetCenterPos();
		D3DXVECTOR3 rot = GetRot();

		D3DXVECTOR3 pos_vec = { -sinf(rot.y), sinf(rot.x), -cosf(rot.y) };

		// �����蔻��̑傫��
		float radiusSize = 80.0f * (Melee_Parameter.nLength + 2);

		// �˒��̉��Z
		pos += pos_vec * radiusSize / 2.0f;

		// ����U��(�ʒu�A�傫���A�T�C�h�A�З�, ����)
		CWeapon_Attack::Create(pos, radiusSize, true, Melee_Parameter.nPower, 20);
	}

	// ���[�V�������I�������ꍇ
	if (m_nAttackRate_Counter++ >= m_nAttackRate_Max_Counter)
	{
		// �U���������ɍU���R�}���h���I�����ꂽ�ꍇ�ɒǉ��U��������
		if (m_bAdditional_Attack == true && m_nAdditional_Attack < 2)
		{
			// �U���񐔂𑝂₷
			m_nAdditional_Attack++;
		}
		// ���[�V�����I�����ɒǉ��R�}���h�������ꍇ�ɏI������
		else
		{
			m_nAdditional_Attack = 0;
		}
		// ������
		m_bPlayer_Attack = false;
		m_bAdditional_Attack = false;
		m_nAttackRate_Counter = 0;
		m_nAttackRate_Max_Counter = 0;
	}
}

//============================================================================
// �v���C���[�̃W�����v����
//============================================================================
void CPlayer::JumpStart()
{
	// �ڒn���Ă���ꍇ�̂�
	if (GetGround())
	{
		// �W�����v���[�V������ݒ�
		GetParts(PARTS_LEG)->SetMotion(MOTION_JUMP);

		// ������Ԃɂ���
		SetGround(false);
		SetLandObj(false);
		SetObjXZ(false);

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
		CParts* pParts = GetParts(nCnt);

		// �ʏ탂�[�V�����̏ꍇ
		if (pParts->GetMotion() == MOTION_NEUTRAL || pParts->GetMotion() == MOTION_JUMP)
		{
			pParts->SetMotion(MOTION_LANDING);
		}
	}
	// �L�����N�^�[�̒��n����
	CCharacter::Landing(pos);
}

//============================================================================
// ��e����
//============================================================================
void CPlayer::Hit(CMove_Object* pHit)
{
	TAG tag = pHit->GetTag();

	// ���g�̏��
	const D3DXVECTOR3 Pos = GetPos();

	// ����̏��
	const D3DXVECTOR3 AtherPos = pHit->GetPos();

	// ���g�Ƒ���̋���
	const D3DXVECTOR3 VecPos = AtherPos - Pos;

	// �����Ă�p�[�c�Ƃ̋���
	const float fDistanceNear = sqrtf(VecPos.x * VecPos.x + VecPos.z * VecPos.z);

	// ���肪�G�������ꍇ
	if (GetPlayerSide() != pHit->GetPlayerSide())
	{
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
		case TAG_MAP_OBJECT:
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

	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	CEnemyManager* pEnemyManager = nullptr;

	// ���[�h���ɓG�L������ǂݍ���
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pEnemyManager = CTutorial::GetEnemyManager();
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pEnemyManager = CGame::GetEnemyManager();
	}

	while (true)
	{
		// �G���G�̏��
		for (auto pEnemy : pEnemyManager->GetAllEnemy())
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
					m_pEnemy = pEnemy;

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
		m_fAngle = atan2(BulletVec.x, BulletVec.z);
		float AngleY = 0.0f;

		// �v���C���[����G�̒�������
		m_fHypotenuse = sqrt((BulletVec.y * BulletVec.y) + (NearDistance * NearDistance));

		// Y���W�̒Ǐ]
		AngleY = sinf(BulletVec.y / m_fHypotenuse);

		// �ړI�̊p�x�̐ݒ�
		CCharacter::SetBulletRot({ AngleY,m_fAngle + D3DX_PI,0.0f });
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

	// ����p
	float fView_Angle = VIEW_SCOPE_ANGLE;

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		// ��ʂɉf�邬�肬��̈ʒu
		D3DXVECTOR3 Reflected_Pos = {0.0f, 0.0f, 0.0f};
		D3DXVECTOR3 Reflected_PosVec = { 0.0f, 0.0f, 0.0f };

		// �^�[�Q�b�g�o���邬�肬��̈ʒu
		Reflected_Pos.x = Camera->GetWorldPosV().x + sinf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
		Reflected_Pos.z = Camera->GetWorldPosV().z + cosf(rotCamera.y + fView_Angle) * m_fTarget_Scope;
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
		Reflected_PosVec = Reflected_Pos - WorldPosV;

		// ���K��
		D3DXVec3Normalize(&Reflected_PosVec, &Reflected_PosVec);

		// ���_����G�̃x�N�g��
		EnemyVec = nearpos - WorldPosV;

		// ���K��
		D3DXVec3Normalize(&EnemyVec, &EnemyVec);

		// �O�ς̊i�[��
		float fCp = Reflected_PosVec.x * EnemyVec.z - Reflected_PosVec.z * EnemyVec.x;

		// ��ʓ��ɉf���Ă��邩
		if (nCnt == 0)
		{
			if (fCp > 0.0f)
				continue;
			else
				break;
		}
		else
			if (fCp <= 0.0f)
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
	float Size_Speed = 10.0f;
	// �A���t�@�l�̉��Z���Z�̑��x
	float Alpha_Speed = 1.0f / ((RETICLE_TRANSPARENCY_SIZE - RETICLE_SIZE) / Size_Speed);

	// ���e�B�N���̐���
	if (m_pReticle == nullptr && m_bReticle_Draw)
	{
		m_pReticle = CObject3D::Create({ m_Reticle_Pos }, { m_Reticle_Size }, PRIORITY_CENTER, { 1.0f,1.0f,1.0f,m_fReticle_Alpha }, true);
		m_pReticle->SetTexture(CTexture::TEXTURE_RETICLE);
	}

	// ���e�B�N������������Ă���ꍇ
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
		m_pReticle->SetTexture(CTexture::TEXTURE_EFFECT_RETICLE);
	}
}

//============================================================================
// ���Ƃ�������肷�鏈��
//============================================================================
void CPlayer::DropGet(CDrop_Weapon* pDrop)
{
	// �v���C���[�p�p�[�c�̏��
	CPlayer::PARTS Parts = pDrop->GetPartsType();

	// ����̏��
	const int nWeapon = pDrop->GetWeaponType();

	// ���A���e�B�̎擾
	const int nRarity = pDrop->GetRarity();

	// ����p�[�c�ł͂Ȃ��ꍇ
	if (Parts != PARTS_WEAPON)
	{
		SetPlayerParts(Parts, nWeapon, nRarity);
	}
	// ����p�[�c�̏ꍇ
	else
	{
		// ����p�[�c�̕ύX����
		SetPlayerWeapon(nWeapon - CDrop_Weapon::MELEE_WEAPON_NONE, nRarity);
	}

	// ���Ƃ����̏I������
	pDrop->Uninit();
}

//============================================================================
// �����Ă镐��̓����蔻��
//============================================================================
void CPlayer::CollisionDropWeapon()
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	CDropManager* pManager = nullptr;

	// ���[�h���ɗ��Ƃ�����ǂݍ���
	if (Mode == CApplication::MODE_TUTORIAL)
	{
		pManager = CTutorial::GetDropManager();
	}
	else if (Mode == CApplication::MODE_GAME)
	{
		pManager = CGame::GetDropManager();
	}

	// ���g�̏��
	const D3DXVECTOR3 pos = GetPos();
	const float fRadius = GetRadius();

	CDrop_Weapon* pNearDrop = nullptr;	// �ł��������߂����Ƃ���
	float fNearDistance = 0.0f;			// �ł��߂�����

	// �S�Ă̗��Ƃ�����ǂݍ���
	for (auto pDrop : pManager->GetAllDrop())
	{
		// �v���C���[���痎���Ă�p�[�c�̋���
		D3DXVECTOR3 Vec = pDrop->GetPos() - pos;

		// �����̎Z�o
		float fDistance = sqrtf(Vec.x * Vec.x + Vec.z * Vec.z);

		// �ŒZ�������X�V���ꂽ�ꍇ
		if (fNearDistance > fDistance)
		{
			fNearDistance = fDistance;
			pNearDrop = pDrop;
		}
		// �������i�[����Ă��Ȃ��ꍇ ���� �~�Ɖ~�̓����蔻��̒��ɂ���ꍇ
		else if(fNearDistance == 0.0f && fRadius + CDrop_Weapon::PARTS_COLLISION_RADIUS >= fDistance)
		{
			fNearDistance = fDistance;
			pNearDrop = pDrop;
		}
	}

	// �ڐG���Ă��闎�Ƃ��������݂���ꍇ
	m_bDrop_Contact = pNearDrop != nullptr;

	// ���Ƃ����ƐڐG���Ă���ꍇ
	if (m_bDrop_Contact == true)
	{
		// �s�b�N�A�b�v��Ԃ�Ԃ�
		pNearDrop->SetPick_Up(true);

		// ���Ƃ�������肷��ꍇ
		if (m_bDrop_Get == true)
		{
			// ���Ƃ�������肷�鏈��
			DropGet(pNearDrop);
		}
	}
	// ���Ƃ�������肷�锻��̃��Z�b�g
	m_bDrop_Get = false;
}

//============================================================================
// �p�����[�^�[�̐ݒ菈��
//============================================================================
void CPlayer::SettingParameter()
{
	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �p�����[�^�[�̏��
	CPlayer_Parameter::PARAMETERS Parameter = {};

	int nLife = 0;				// �ϋv�l
	int nStamina = 0;			// �X�^�~�i�e��
	int nStan_Tolerance = 0;	// �X�^�����e�l
	int nGravity = 0;			// �d��

	CPlayer_Parameter* pPlayer_Parameter = nullptr;
	CWeapon_Parameter* pWeapon_Parameter = nullptr;

	//�p�����[�^�̎擾
	/*if (Mode == CApplication::MODE_TUTORIAL)
	{
		pParameter = CTutorial::GetPlayerParameter();
		pWeapon_Parameter = CTutorial::GetWeaponParameter();
	}
	else*/
	if (Mode == CApplication::MODE_GAME)
	{
		pPlayer_Parameter = CGame::GetPlayerParameter();
		pWeapon_Parameter = CGame::GetWeaponParameter();
	}

	// �p�[�c���̃p�����[�^�[
	for (int nCnt = 0; nCnt < PARTS_MAX; nCnt++)
	{
		switch (nCnt)
		{
		case 0:
			Parameter = pPlayer_Parameter->GetParameterJob(m_Parts_Job[nCnt]);
			break;
		case 1:
			Parameter = pPlayer_Parameter->GetParameterArms(m_Parts_Job[nCnt], m_nArms_Rarity);
			break;
		case 2:
			Parameter = pPlayer_Parameter->GetParameterLeg(m_Parts_Job[nCnt], m_nLeg_Rarity);
			break;
		default:
			break;
		}

		nLife += Parameter.nLife;
		nStamina += Parameter.nStamina;
		nStan_Tolerance += Parameter.nStan_Tolerance;
		nGravity += Parameter.nGravity;
	}

	CWeapon_Parameter::MELEE_WEAPON_PARAMETERS Melee_Parameter = {};

	// ����p�����[�^�[
	Melee_Parameter = pWeapon_Parameter->GetParameterMeleeWeapon(m_nWeapon_type, m_nWeapon_Rarity);
	m_nGravity += Melee_Parameter.nGravity;

	// �e�p�����[�^�̐ݒ�
	SetMaxLife(nLife);
	m_pEnergy_Gauge->SetMaxEnerugy(nStamina);
	m_nStan_Tolerance = nStan_Tolerance;
	m_nGravity = nGravity;
}

//============================================================================
// �p�[�c�̐ݒ�
//============================================================================
void CPlayer::SetPlayerParts(const PARTS parts, const int weapon, const int rarity)
{
	int nPartsFileIndex = 0;	// �p�[�c�̔ԍ�

	// ���݂̃��A���e�B�̐F
	float fRarity_Color = 0;

	// �p�[�c�t�@�C���̍Œ�l��ݒ�
	switch (parts)
	{
	case CPlayer::PARTS_BODY:
		nPartsFileIndex = CParts_File::PARTS_PLAYER_BODY_1;
		break;
	case CPlayer::PARTS_ARMS:
		nPartsFileIndex = CParts_File::PARTS_PLAYER_ARMS_1;
		fRarity_Color = (float)m_nArms_Rarity;
		m_nArms_Rarity = rarity;
		break;
	case CPlayer::PARTS_LEG:
		nPartsFileIndex = CParts_File::PARTS_PLAYER_LEG_1;
		fRarity_Color = (float)m_nLeg_Rarity;
		m_nLeg_Rarity = rarity;
		break;
	default:
		break;
	}

	int nWeaponIndex = 0;	// ����̔ԍ�

							// �p�[�c�̍Œ�l��ݒ�
	if (weapon >= CDrop_Weapon::LEG_SG01)
	{
		nWeaponIndex = CDrop_Weapon::LEG_SG01;
	}
	else if (weapon >= CDrop_Weapon::ARMS_SG01)
	{
		nWeaponIndex = CDrop_Weapon::ARMS_SG01;
	}
	//else if (nWeapon >= CDrop_Weapon::BODY_SG01)
	//{
	//	nWeaponIndex = CParts_File::PARTS_PLAYER_BODY_1;
	//}

	// �p�[�c�̃W���u���̍X�V
	m_Parts_Job[parts] = (JOB)(weapon - nWeaponIndex);

	// �p�����[�^�̍X�V
	m_bChange_Parameter = true;

	// �p�[�c�̔ԍ�(�p�[�c�t�@�C���̔ԍ� + �p�[�c�̔ԍ�(�p�[�c���̂܂܂̔ԍ� - �p�[�c�̍Œ�l))
	int nPartsIndex = nPartsFileIndex + (weapon - nWeaponIndex);

	// �w�肵���p�[�c�́A�p�[�c�ύX����
	GetParts(parts)->SetParts(nPartsIndex);

	// �ύX���郌�A���e�B�̐F
	//const float nChange_Color = 0.1f * rarity;

	// ���A���e�B�ɂ��F�̕ω�
	const float fAddCol = -(rarity - fRarity_Color) * 0.05f;

	for (auto pParts : GetParts(parts)->GetModelAll())
	{
		pParts->AddColor({ fAddCol, fAddCol,fAddCol, 0.0f });
	}
}

//============================================================================
// ����̐ݒ�
//============================================================================
void CPlayer::SetPlayerWeapon(const int weapon, const int rarity)
{
	m_nWeapon_type = weapon;
	m_nWeapon_Rarity = rarity;

	// �E�肪�g�p����Ă��Ȃ��ꍇ
	if (m_pRightWeapon == nullptr)
	{
		// �E��(�r[3])�ɕ����ݒ�
		m_pRightWeapon = CWeapon::Create({ 1.0f, -6.0f, 0.0f }, { -D3DX_PI / 2.0f, 0.0f, 0.0f}, (CWeapon::WEAPON_TYPE)weapon, GetParts(PARTS_ARMS)->GetModel(4));
		m_pRightWeapon->SetDrawFlag(false);
	}
	else
	{	// �E��(�r[3])�ɕ����ύX
		m_pRightWeapon->ChangeWeapon(weapon);
		m_pRightWeapon->SetDrawFlag(true);
	}

	// ���肪�g�p����Ă��Ȃ��ꍇ
	if (m_pLeftWeapon == nullptr)
	{
		// ����(�r[6])�ɑf���ݒ�
		m_pLeftWeapon = CWeapon::Create({ -1.0f, -6.0f, 0.0f }, { -D3DX_PI / 2.0f, 0.0f, 0.0f }, CWeapon::WEAPON_KNUCKLE, GetParts(PARTS_ARMS)->GetModel(6));
		m_pLeftWeapon->SetDrawFlag(false);
	}
	else
	{
		// ����(�r[6])�ɑf���ݒ�
		m_pLeftWeapon->ChangeWeapon(CWeapon::WEAPON_KNUCKLE);
		m_pLeftWeapon->SetDrawFlag(true);
	}

	// ���݂̃��[�h
	CApplication::MODE Mode = CApplication::GetModeType();

	// �������Ɏ��g�̃|�C���^��G�L�����}�l�[�W���[�ɐݒ�
	/*if (Mode == CApplication::MODE_TUTORIAL)
	{
		CTutorial::SetPlayerUI(CPlayerUi::UITYPE_ATTACK, weapon);
		CTutorial::SetPlayerUI(CPlayerUi::UITYPE_WEAPON, weapon);
	}
	else*/ if (Mode == CApplication::MODE_GAME)
	{
		CGame::SetPlayerUI(CPlayerUi::UITYPE_ATTACK, weapon);
		CGame::SetPlayerUI(CPlayerUi::UITYPE_WEAPON, weapon);
	}
}