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
	// パーティクル情報の列挙
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
	// パーティクル情報の構造体
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
		D3DXVECTOR3 pos;						// 位置
		D3DXVECTOR3 destPos;					// 目的の位置
		D3DXVECTOR3 posOffset;					// 位置のオフセット
		D3DXVECTOR3 move;						// 移動量
		D3DXVECTOR3 velocity;
		D3DXVECTOR3 scale;						// 大きさ
		D3DXVECTOR3 scalingValue;				// 拡縮量
		std::vector<SColor> colorProp;
		D3DXCOLOR col;							// 色
		D3DXCOLOR destCol;						// 目的の色
		CTrail::SInfo trailInfo;				// トレイルのデータ
		CBillboard::SAnimation animation;		// テクスチャアニメーション
		CPhysics::SPhysics physics;				// 物理
		CPhysics::EPhysicsType physicsType;		// 物理の列挙
		CBillboard::EBlend blendState;
		SRotate rotate;
		SRandom random;
		int beginDelay;							// 開始の遅延
		int fallDelayTime;						// 落ちるまでの遅延
		int popTime;							// 生存時間
		float moveAttenuation;					// 移動の減衰量
		float colAttenuation;					// 色の減衰量
		float rotateValue;						// 回転量
		float weight;							// 重さ
		float circleDistance;					// 円の範囲
		bool collision;							// 判定
		bool isInstancing;
		bool useRandom;							// ランダムを適用するかどうか
		bool usePhysics;
		bool useAnimation;
		bool useTrail;							// トレイルを使用するかどうか
		bool separateTrail;						// トレイルの情報をパーティクルとは別にするかどうか
	};

	explicit CParticle(int nPriority = CObject::PRIORITY_THIRD);
	~CParticle() override;

	static CParticle *Create(SInfo& info, const std::string& url, int nPriority = CObject::PRIORITY_THIRD, CGrid* grid = nullptr, CParticleEmitter* emitter = nullptr);	// 生成処理

	HRESULT Init() override;												// 初期化処理
	void Uninit() override;
	void Update() override;													// 更新処理
	void Draw() override;													// 描画処理
	bool isExpired() { return m_DestroyTime <= 0; }							// 期限切れかどうか
	void CollisionData(CParticle* particle) { m_collisionData = particle; }

	//セッター
	void SetInfo(SInfo& info) { m_info = info; }
	void SetPath(const std::string& path) { m_path = path; }
	void SetGrid();

	SInfo GetInfo() { return m_info; }
	CParticle* GetCollisionData() { return m_collisionData; }
	CGrid* GetGrid() { return m_pGrid; }

private:
	void ProcessPhysics(CPhysics::EPhysicsType state, D3DXVECTOR3& move);
	void InstancingUpdate();

	SInfo m_info;						// パーティクルの情報
	CParticle* m_collisionData;
	CTrail *m_pTrail;
	CPhysics *m_pPhysics;
	CGrid *m_pGrid;
	CParticleEmitter *m_pEmitter;
	std::string m_path;					// テクスチャのパス

	int m_delayStartTime;
	int m_nTime;						// 時間
	int m_DestroyTime;
};
#endif