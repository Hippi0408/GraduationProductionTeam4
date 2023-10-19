#ifndef _PHYSICS_H_
#define _PHYSICS_H_

class CPhysics
{
public:
	CPhysics();
	~CPhysics();

	enum EPhysicsType
	{
		PHYSICS_NONE = 0,
		PHYSICS_BOUNCE,
		PHYSICS_AIR,
		PHYSICS_MAX
	};

	struct SBounce
	{
		D3DXVECTOR3 normal;					// 法線ベクトル
		float bounceFactor;					// 反発係数( 0 ~ 1 )
		float elasticityCoefficient = 2.0f;	// 弾性衝突
	};

	struct SAir
	{
		D3DXVECTOR3 pos;
		float dragCoefficient;
		float vecFactor;
	};

	struct SBoundingBox
	{
		D3DXVECTOR3 maxPoint;
		D3DXVECTOR3 minPoint;
		D3DXVECTOR3 center;
		D3DXVECTOR3 scale;
		D3DXVECTOR3 axis[3];
		D3DXMATRIX mtxRot;
	};

	struct SPhysics
	{
		SBounce bounce;
		SAir air;
		D3DXVECTOR3 velocity;				// 速度
	};

	D3DXVECTOR3 ProcessPhysics(SPhysics* physics, EPhysicsType type, SPhysics* another = nullptr);

	D3DXVECTOR3 Bounce(SPhysics* data = nullptr);
	D3DXVECTOR3 AerodynamicDrag(SPhysics* data, SPhysics* anotherData);

	bool isCircleCollision(const D3DXVECTOR3& pos, float radius, const D3DXVECTOR3& destPos, float destRadius);
	bool isBoundingBoxCollision(const SBoundingBox& boxA, const SBoundingBox& boxB);
	bool isOrientedBoundingBoxCollision(const SBoundingBox& boxA, const SBoundingBox& boxB);
	bool PointPlaneCollision(const D3DXVECTOR3& pt, const D3DXVECTOR3& planePos, const D3DXVECTOR3& planeNor, const D3DXVECTOR3& velocity, D3DXVECTOR3& reflect);

	void SetPhysics(SPhysics physics) { m_physics = physics; }

	SPhysics GetPhysics() { return m_physics; }

private:
	void CalcBoundingBoxVtx(const SBoundingBox& box, std::vector<D3DXVECTOR3>& vtx);

	SPhysics m_physics;
};

#endif