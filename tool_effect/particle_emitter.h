//����������������������������������������
//ParticleEmitter.h
//����������������������������������������
#ifndef _PARTICLE_EMITTER_H_
#define _PARTICLE_EMITTER_H_

#include "particle.h"
#include "mesh_particle.h"
#include "physics.h"
#include "sound.h"
#include "instancing.h"

class CParticle;
class CMeshParticle;
class CPhysics;
class CSound;

class CParticleEmitter : public CObject
{
public:
	enum EBehavior
	{
		Behavior_None,
		Behavior_Circle,
		Behavior_Sphere,
		Behavior_Rotate,
		Behavior_Max
	};

	enum EObjectType
	{
		OBJECT_BILLBOARD,
		OBJECT_MESH,
		OBJECT_2D,
		OBJECT_MAX
	};

	struct SEmitterInfo
	{
		EBehavior behavior;					// ����
		EObjectType objType;				// �I�u�W�F�N�g�^�C�v
		CPhysics::SPhysics physics;			// ����
		CPhysics::EPhysicsType physicsType;	// �����̗�
		std::vector<CSound::STrack> tracks;	// ���f�[�^
		std::string modelTag;				// ���f���̃^�O
		std::string particleTag;			// �p�[�e�B�N���̃^�O
		std::string texTag;					// �e�N�X�`���̃^�O
		std::string maskTexTag;				// �}�X�N�p�e�N�X�`���̃^�O
		float radius;						// ���a
		int popDelay;						// �����̒x��
		int popParticleNum;					// �������鐔
		int emitterIndex;					// �p�[�e�B�N���G�~�b�^�p�̔ԍ�
		bool usePhysics;					// �������g�p���邩�ǂ���
		bool enableShader;					// �V�F�[�_�[���g�p���邩�ǂ���
		bool enableInstancing;				// �C���X�^���V���O���s�����ǂ���
	};

	CParticleEmitter();
	~CParticleEmitter();

	static CParticleEmitter* Create(const std::string& str);

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw() { ; }
	void CreateParticle(int index);
	void CreateMesh(int index);
	void PlayEmitterSound();
	void CheckCollision(CParticle* particle);
	void AfterRelease() { m_afterRelease = true; }
	void Destroy() { m_isRelease = true; }

	void SetPos(D3DXVECTOR3 pos);

	D3DXVECTOR3 GetPos();
	bool GetDestroy() { return m_isRelease; }

private:
	void SetPosBillboard(D3DXVECTOR3 pos);
	void SetPosMesh(D3DXVECTOR3 pos);

	std::vector<CParticle*> m_particle;
	std::vector<CParticle::SInfo> m_particleInfo;
	std::vector<CMeshParticle*> m_mesh;
	std::vector<CMeshParticle::SInfo> m_meshInfo;
	std::vector<SEmitterInfo> m_emitterInfo;
	std::vector<CInstancing*> m_instancingData;
	D3DXVECTOR3 m_popPos;
	D3DXVECTOR3 m_move;
	int m_cntBillboard;
	int m_cntMesh;
	int m_time;
	int m_soundTime;
	bool m_soundOnce;
	bool m_afterRelease;
	bool m_isRelease;
};

#endif