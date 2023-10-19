#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "billboard.h"
#include "trail.h"
#include "physics.h"
#include "grid.h"

class CTrail;
class CPhysics;
class CGrid;
class CParticleEmitter;

class CParticle : public CBillboard
{
public:
	//--------------------------------------
	// �p�[�e�B�N�����̗�
	//--------------------------------------
	enum ERandomBehavior
	{
		RandomBehavior_Default,
		RandomBehavior_Circle,
		RandomBehavior_MAX
	};

	enum ELockVector
	{
		Lock_None,
		Lock_X,
		Lock_Y,
		Lock_Z,
		Lock_XY,
		Lock_XZ,
		Lock_YZ,
		Lock_MAX
	};

	//--------------------------------------
	// �p�[�e�B�N�����̍\����
	//--------------------------------------
	struct SRotate
	{
		float angle;
		float radius;
		float randomMin;
		float randomMax;
		bool useRotate;
	};

	struct SRandom
	{
		D3DXVECTOR3 randomVelocityMin;
		D3DXVECTOR3 randomVelocityMax;
		D3DXVECTOR2 randomWeight;
		D3DXVECTOR2 randomRotate;
		ERandomBehavior randomBehavior;
		ELockVector randomLockVector;
		D3DXVECTOR2 distortion;
	};

	struct SColor
	{
		D3DXCOLOR color;
		int colorPtTime;
	};

	struct SInfo
	{
		D3DXVECTOR3 pos;						// �ʒu
		D3DXVECTOR3 destPos;					// �ړI�̈ʒu
		D3DXVECTOR3 posOffset;					// �ʒu�̃I�t�Z�b�g
		D3DXVECTOR3 move;						// �ړ���
		D3DXVECTOR3 velocity;
		D3DXVECTOR3 scale;						// �傫��
		D3DXVECTOR3 scalingValue;				// �g�k��
		std::vector<SColor> colorProp;
		D3DXCOLOR col;							// �F
		D3DXCOLOR destCol;						// �ړI�̐F
		CTrail::SInfo trailInfo;				// �g���C���̃f�[�^
		CBillboard::SAnimation animation;		// �e�N�X�`���A�j���[�V����
		CPhysics::SPhysics physics;				// ����
		CPhysics::EPhysicsType physicsType;		// �����̗�
		CBillboard::EBlend blendState;
		SRotate rotate;
		SRandom random;
		int beginDelay;							// �J�n�̒x��
		int fallDelayTime;						// ������܂ł̒x��
		int popTime;							// ��������
		float moveAttenuation;					// �ړ��̌�����
		float colAttenuation;					// �F�̌�����
		float rotateValue;						// ��]��
		float weight;							// �d��
		float circleDistance;					// �~�͈̔�
		bool collision;							// ����
		bool isInstancing;
		bool useRandom;							// �����_����K�p���邩�ǂ���
		bool usePhysics;
		bool useAnimation;
		bool useTrail;							// �g���C�����g�p���邩�ǂ���
		bool separateTrail;						// �g���C���̏����p�[�e�B�N���Ƃ͕ʂɂ��邩�ǂ���
	};

	explicit CParticle(int nPriority = CObject::PRIORITY_THIRD);
	~CParticle() override;

	static CParticle *Create(SInfo& info, const std::string& url, int nPriority = CObject::PRIORITY_THIRD, CGrid* grid = nullptr, CParticleEmitter* emitter = nullptr);	// ��������

	HRESULT Init() override;												// ����������
	void Uninit() override;
	void Update() override;													// �X�V����
	void Draw() override;													// �`�揈��
	bool isExpired() { return m_DestroyTime <= 0; }							// �����؂ꂩ�ǂ���
	void CollisionData(CParticle* particle) { m_collisionData = particle; }

	//�Z�b�^�[
	void SetInfo(SInfo& info) { m_info = info; }
	void SetPath(const std::string& path) { m_path = path; }
	void SetGrid();

	SInfo GetInfo() { return m_info; }
	CParticle* GetCollisionData() { return m_collisionData; }
	CGrid* GetGrid() { return m_pGrid; }

private:
	void ProcessPhysics(CPhysics::EPhysicsType state, D3DXVECTOR3& move);
	void InstancingUpdate();

	SInfo m_info;						// �p�[�e�B�N���̏��
	CParticle* m_collisionData;
	CTrail *m_pTrail;
	CPhysics *m_pPhysics;
	CGrid *m_pGrid;
	CParticleEmitter *m_pEmitter;
	std::string m_path;					// �e�N�X�`���̃p�X

	int m_delayStartTime;
	int m_nTime;						// ����
	int m_DestroyTime;
};
#endif