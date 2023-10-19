//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//ParticleEmitter.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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
		EBehavior behavior;					// 挙動
		EObjectType objType;				// オブジェクトタイプ
		CPhysics::SPhysics physics;			// 物理
		CPhysics::EPhysicsType physicsType;	// 物理の列挙
		std::vector<CSound::STrack> tracks;	// 音データ
		std::string modelTag;				// モデルのタグ
		std::string particleTag;			// パーティクルのタグ
		std::string texTag;					// テクスチャのタグ
		std::string maskTexTag;				// マスク用テクスチャのタグ
		float radius;						// 半径
		int popDelay;						// 生成の遅延
		int popParticleNum;					// 生成する数
		int emitterIndex;					// パーティクルエミッタ用の番号
		bool usePhysics;					// 物理を使用するかどうか
		bool enableShader;					// シェーダーを使用するかどうか
		bool enableInstancing;				// インスタンシングを行うかどうか
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