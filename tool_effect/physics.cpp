#include "physics.h"

CPhysics::CPhysics()
{
}

CPhysics::~CPhysics()
{
}

D3DXVECTOR3 CPhysics::ProcessPhysics(SPhysics* physics, EPhysicsType type, SPhysics* another)
{
	D3DXVECTOR3 result(0.0f, 0.0f, 0.0f);
	switch (type)
	{
	case PHYSICS_NONE:
		result = physics->velocity;
		break;

	case PHYSICS_BOUNCE:
		result = Bounce(physics);
		break;

	case PHYSICS_AIR:
		result = AerodynamicDrag(physics, another);
		break;

	default:
		break;
	}
	return result;
}

D3DXVECTOR3 CPhysics::Bounce(SPhysics* data)
{
	SPhysics physics = m_physics;
	SBounce bounce = m_physics.bounce;

	// ���˃x�N�g��
	float dot = D3DXVec3Dot(&physics.velocity, &bounce.normal);

	// �o�E���X�v�Z
	D3DXVECTOR3 reflect = D3DXVECTOR3((physics.velocity.x - bounce.elasticityCoefficient) * dot * bounce.normal.x,
		(physics.velocity.y - bounce.elasticityCoefficient) * dot * bounce.normal.y,
		(physics.velocity.z - bounce.elasticityCoefficient) * dot * bounce.normal.z);
	reflect *= bounce.bounceFactor;
	if (data != nullptr)
	{
		data->bounce.bounceFactor *= 0.5f;
	}

	// ��т����}��
	float maxSpeed = 7.0f;
	float currentSpeed = D3DXVec3Length(&reflect);
	if (currentSpeed > maxSpeed)
	{
		D3DXVec3Normalize(&reflect, &reflect);
		reflect *= maxSpeed;
	}
	float maxY = 500.0f;
	if (reflect.y > maxY)
	{
		reflect.y = maxY;
	}
	return reflect;
}

D3DXVECTOR3 CPhysics::AerodynamicDrag(SPhysics* data, SPhysics* anotherData)
{
	D3DXVECTOR3 velocityA = data->velocity;
	D3DXVECTOR3 velocityB = anotherData->velocity;

	// �ڐG�����p�[�e�B�N���Ԃ̑��Α��x�x�N�g���̌v�Z
	D3DXVECTOR3 relativeVelocity = velocityB - velocityA;

	// ��C��R�̌���
	D3DXVECTOR3 dragForce = -data->air.dragCoefficient * relativeVelocity;

	velocityA += dragForce * data->air.vecFactor;
	velocityB -= dragForce * anotherData->air.vecFactor;

	return velocityA;
}

//��������������������������������������������������������������
// �Փ˔���i�ہj
//��������������������������������������������������������������
bool CPhysics::isCircleCollision(const D3DXVECTOR3& pos, float radius, const D3DXVECTOR3& destPos, float destRadius)
{
	D3DXVECTOR3 vec = destPos - pos;
	float distance = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);

	if (distance < radius + destRadius)
	{
		return true;
	}
	return false;
}

//��������������������������������������������������������������
// �Փ˔���i�o�E���f�B���O�{�b�N�X)
//��������������������������������������������������������������
bool CPhysics::isBoundingBoxCollision(const SBoundingBox& boxA, const SBoundingBox& boxB)
{
	// X,Y,Z�Ŕ͈͂��d�Ȃ��Ă��邩�ǂ���
	if (boxA.maxPoint.x < boxB.minPoint.x || boxA.minPoint.x > boxB.maxPoint.x)
	{
		return false;
	}
	if (boxA.maxPoint.y < boxB.minPoint.y || boxA.minPoint.y > boxB.maxPoint.y)
	{
		return false;
	}
	if (boxA.maxPoint.z < boxB.minPoint.z || boxA.minPoint.z > boxB.maxPoint.z)
	{
		return false;
	}
	return true;
}

bool CPhysics::isOrientedBoundingBoxCollision(const SBoundingBox& boxA, const SBoundingBox& boxB)
{
	const int boxVertex = 8;

	// OBB���m�̒��_���v�Z
	std::vector<D3DXVECTOR3> boxAVertices(boxVertex);
	CalcBoundingBoxVtx(boxA, boxAVertices);

	std::vector<D3DXVECTOR3> boxBVertices(boxVertex);
	CalcBoundingBoxVtx(boxB, boxBVertices);

	for (int i = 0; i < boxVertex; i++)
	{
		for (int j = 0; j < boxVertex; j++)
		{
			// ���_���m�̋������v�Z
			D3DXVECTOR3 distance = boxAVertices[i] - boxBVertices[j];
			if (D3DXVec3Length(&distance) <= 0.0f)
			{
				return true;
			}
		}
	}
	return false;
}

//��������������������������������������������������������������
// �Փ˔���i�_�Ɣj
//��������������������������������������������������������������
bool CPhysics::PointPlaneCollision(const D3DXVECTOR3& pt, const D3DXVECTOR3& planePos, const D3DXVECTOR3& planeNor, const D3DXVECTOR3& velocity, D3DXVECTOR3& reflect)
{
	D3DXPLANE plane;
	D3DXPlaneFromPointNormal(&plane, &planePos, &planeNor);
	float distance = D3DXPlaneDotCoord(&plane, &pt);
	float dot = D3DXVec3Dot(&velocity, &planeNor);

	if (distance < 0.0f)
	{
		// ���ˊp
		int incidenceAngle = acosf(dot);

		// ���ˊp
		float reflectionAngle = D3DX_PI - incidenceAngle;
		reflect = D3DXVECTOR3(cosf(reflectionAngle), sinf(reflectionAngle), 0.0f);
		D3DXVec3Normalize(&reflect, &reflect);

		return true;
	}
	return false;
}

//��������������������������������������������������������������
// �o�E���f�B���O�{�b�N�X�̒��_�v�Z����
//��������������������������������������������������������������
void CPhysics::CalcBoundingBoxVtx(const SBoundingBox& box, std::vector<D3DXVECTOR3>& vtx)
{
	D3DXVECTOR3 obbExtents[] = {
		D3DXVECTOR3(box.scale.x, 0.0f, 0.0f),
		D3DXVECTOR3(0.0f, box.scale.y, 0.0f),
		D3DXVECTOR3(0.0f, 0.0f, box.scale.z)
	};

	D3DXMATRIX mtxRot = box.mtxRot;
	D3DXMatrixTranspose(&mtxRot, &box.mtxRot);

	for (int i = 0; i < 3; i++)
	{
		vtx[i * 2] = box.center + D3DXVECTOR3(mtxRot._11, mtxRot._21, mtxRot._31) * obbExtents[i].x
			+ D3DXVECTOR3(mtxRot._12, mtxRot._22, mtxRot._32) * obbExtents[i].y
			+ D3DXVECTOR3(mtxRot._13, mtxRot._23, mtxRot._33) * obbExtents[i].z;

		vtx[i * 2 + 1] = box.center - D3DXVECTOR3(mtxRot._11, mtxRot._21, mtxRot._31) * obbExtents[i].x
			- D3DXVECTOR3(mtxRot._12, mtxRot._22, mtxRot._32) * obbExtents[i].y
			- D3DXVECTOR3(mtxRot._13, mtxRot._23, mtxRot._33) * obbExtents[i].z;
	}
}