#include "particle_emitter.h"
#include "particle_manager.h"
#include "particle.h"
#include "application.h"
#include "utility.h"
#include "sound.h"
#include "instancing.h"

namespace
{
	// �~�͈͓̔��Ń����_���Ɉʒu��ݒ�
	inline D3DXVECTOR3 CircleRandomPos(D3DXVECTOR3 pos, float circledistance, float altitude)
	{
		D3DXVECTOR3 result(0.0f, 0.0f, 0.0f);
		float angle = (float)rand() / (float)RAND_MAX * 2.0f * D3DX_PI;
		float distance = sqrtf((float)rand() / (float)RAND_MAX) * (360.0f * circledistance);

		result = D3DXVECTOR3(pos.x + distance * cosf(angle),
			pos.y + altitude,
			pos.z + distance * sinf(angle));

		return result;
	}

	// ������o�v�Z
	inline void EmitSphere(D3DXVECTOR3& vec, int num, int numAll, float radius, D3DXVECTOR2& distortion, float attenuation)
	{
		float inclination = acosf(1.0f - (2.0f * (num + 0.5f) / numAll));	// �X��
		float azimuth = 2.0f * D3DX_PI * num / (1.0f + sqrtf(5.0f));		// ���ʊp
		azimuth *= utility::Random<float>(distortion.x, distortion.y);

		// ����ɕ��o
		vec = D3DXVECTOR3(radius * sinf(inclination) * cosf(azimuth),
			radius * cosf(inclination),
			radius * sinf(inclination) * sinf(azimuth)) * attenuation;
	}
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̃R���X�g���N�^
//��������������������������������������������������������������
CParticleEmitter::CParticleEmitter() : 
	m_soundTime(0),
	m_soundOnce(true),
	m_cntBillboard(0),
	m_cntMesh(0)
{
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̃f�X�g���N�^
//��������������������������������������������������������������
CParticleEmitter::~CParticleEmitter()
{
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̐���
//��������������������������������������������������������������
CParticleEmitter* CParticleEmitter::Create(const std::string& str)
{
	CParticleEmitter* pEmitter = nullptr;
	pEmitter = new CParticleEmitter;

	CParticleManager* pManager = CApplication::GetInstance()->GetParticleManager();
	std::vector<CParticleManager::SBundleData> data;

	if (pEmitter != nullptr)
	{
		data = pManager->GetParticleData(str);
		for (auto& p : data)
		{
			switch (p.emitterData.objType)
			{
			case OBJECT_BILLBOARD:
				pEmitter->m_particleInfo.push_back(p.info);
				break;

			case OBJECT_MESH:
				pEmitter->m_meshInfo.push_back(p.meshInfo);
				break;
			}

			pEmitter->m_emitterInfo.push_back(p.emitterData);
		}
		pEmitter->Init();
	}

	return pEmitter;
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̏�����
//��������������������������������������������������������������
HRESULT CParticleEmitter::Init()
{
	// �p�[�e�B�N���̐���
	for (size_t i = 0; i < m_emitterInfo.size(); i++)
	{
		m_emitterInfo[i].enableInstancing = true;

		switch (m_emitterInfo[i].objType)
		{
		case OBJECT_BILLBOARD:
			CreateParticle(i);
			break;

		case OBJECT_MESH:
			CreateMesh(i);
			break;

		default:
			break;
		}

		if (m_emitterInfo[i].enableInstancing)
		{
			m_instancingData.push_back(CInstancing::Create(m_particle, m_emitterInfo[i].texTag, m_emitterInfo[i].popParticleNum));
			continue;
		}
	}

	return S_OK;
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̏I��
//��������������������������������������������������������������
void CParticleEmitter::Uninit()
{
	// �p�[�e�B�N���I�u�W�F�N�g�f�[�^����ł͂Ȃ��ꍇ
	if (!m_particle.empty())
	{
		for (size_t i = 0; i < m_particle.size(); i++)
		{
			m_particle[i]->Destroy();
		}
		m_particle.clear();
	}
	if (!m_mesh.empty())
	{
		for (size_t i = 0; i < m_mesh.size(); i++)
		{
			m_mesh[i]->Destroy();
		}
		m_mesh.clear();
	}
	if (!m_instancingData.empty())
	{
		for (size_t i = 0; i < m_instancingData.size(); i++)
		{
			m_instancingData[i]->Destroy();
		}
		m_instancingData.clear();
	}

	if (!m_particleInfo.empty())
	{
		m_particleInfo.clear();
	}

	if (!m_meshInfo.empty())
	{
		m_meshInfo.clear();
	}

	this->Destroy();
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̍X�V
//��������������������������������������������������������������
void CParticleEmitter::Update()
{
	// �p�[�e�B�N��
	for (auto it = m_particle.begin(); it != m_particle.end();)
	{
		CParticle *pParticle = *it;

		if (pParticle->isExpired())
		{
			pParticle->Destroy();
			it = m_particle.erase(it);
			for (auto& p : m_instancingData)
			{
				p->SetParticlePtr(m_particle);
			}
		}
		else
		{
			it++;
		}
	}

	// ���b�V��
	for (auto it = m_mesh.begin(); it != m_mesh.end();)
	{
		CMeshParticle *pMesh = *it;

		if (pMesh->isExpired())
		{
			pMesh->Destroy();
			it = m_mesh.erase(it);
		}
		else
		{
			it++;
		}
	}

	if (m_particle.empty() && m_mesh.empty())
	{
		CParticleEmitter::Uninit();
	}

	PlayEmitterSound();
}

//��������������������������������������������������������������
// �p�[�e�B�N���̐���
//��������������������������������������������������������������
void CParticleEmitter::CreateParticle(int index)
{
	float inclination = 0;
	float azimuth = 0;

	CGrid* pGrid = CApplication::GetInstance()->GetParticleManager()->GetGrid();
	D3DXVECTOR3 velocity = m_particleInfo[m_cntBillboard].move;
	float radius = m_emitterInfo[index].radius;
	float attenuation = m_particleInfo[m_cntBillboard].moveAttenuation;
	m_particle.reserve(m_emitterInfo[index].popParticleNum);

	for (int j = 0; j < m_emitterInfo[index].popParticleNum; j++)
	{
		switch (m_emitterInfo[index].behavior)
		{
		case Behavior_Circle:
			// �~��ɕ��o
			m_move = D3DXVECTOR3(-sinf((j * ((radius / m_emitterInfo[index].popParticleNum) * (D3DX_PI / 180)))),
				velocity.y,
				-cosf((j * ((radius / m_emitterInfo[index].popParticleNum) * (D3DX_PI / 180))))) * attenuation;
			break;

		case Behavior_Sphere:
			EmitSphere(m_move, j, m_emitterInfo[index].popParticleNum, radius, m_particleInfo[m_cntBillboard].random.distortion , attenuation);
			break;

		case Behavior_Rotate:
			m_move = velocity;
			m_particleInfo[m_cntBillboard].rotate.useRotate = true;
			break;

		case Behavior_None:
			m_move = velocity;
			break;

		default:
			break;
		}

		m_particleInfo[m_cntBillboard].move = m_move;
		m_particleInfo[m_cntBillboard].physics = m_emitterInfo[index].physics;
		m_particleInfo[m_cntBillboard].physicsType = m_emitterInfo[index].physicsType;
		m_particleInfo[m_cntBillboard].usePhysics = m_emitterInfo[index].usePhysics;
		m_particleInfo[m_cntBillboard].isInstancing = m_emitterInfo[index].enableInstancing;
		m_particle.push_back(CParticle::Create(m_particleInfo[m_cntBillboard], m_emitterInfo[index].texTag, CObject::PRIORITY_THIRD, pGrid, this));
	}

	m_cntBillboard++;
}

//��������������������������������������������������������������
// ���b�V���̐���
//��������������������������������������������������������������
void CParticleEmitter::CreateMesh(int index)
{
	float inclination = 0;
	float azimuth = 0;

	D3DXVECTOR3 velocity = m_meshInfo[m_cntMesh].move;
	float radius = m_emitterInfo[index].radius;
	float attenuation = m_meshInfo[m_cntMesh].moveAttenuation;
	m_particle.reserve(m_emitterInfo[index].popParticleNum);

	for (int j = 0; j < m_emitterInfo[index].popParticleNum; j++)
	{
		switch (m_emitterInfo[index].behavior)
		{
		case Behavior_Circle:
			// �~��ɕ��o
			m_move = D3DXVECTOR3(-sinf((j * ((radius / m_emitterInfo[index].popParticleNum) * (D3DX_PI / 180)))),
				velocity.y,
				-cosf((j * ((radius / m_emitterInfo[index].popParticleNum) * (D3DX_PI / 180))))) * attenuation;
			break;

		case Behavior_Sphere:
			EmitSphere(m_move, j, m_emitterInfo[index].popParticleNum, radius, D3DXVECTOR2(1.0f,1.0f), attenuation);
			break;

		case Behavior_Rotate:
			m_move = velocity;
			m_meshInfo[m_cntMesh].rotate.useRotate = true;
			break;

		case Behavior_None:
			m_move = velocity;
			break;

		default:
			break;
		}

		m_meshInfo[m_cntMesh].move = m_move;
		m_meshInfo[m_cntMesh].texTag = m_emitterInfo[index].texTag;
		m_meshInfo[m_cntMesh].maskTexTag = m_emitterInfo[index].maskTexTag;
		m_meshInfo[m_cntMesh].modelTag = m_emitterInfo[index].modelTag;
		m_meshInfo[m_cntMesh].useShader = m_emitterInfo[index].enableShader;
		m_mesh.push_back(CMeshParticle::Create(m_meshInfo[m_cntMesh]));
	}

	m_cntMesh++;
}

//��������������������������������������������������������������
// �G�~�b�^�̃T�E���h
//��������������������������������������������������������������
void CParticleEmitter::PlayEmitterSound()
{
	// �T�E���h�̃|�C���^
	CSound* pSound = CApplication::GetInstance()->GetSound();

	m_soundTime++;
	for (auto& p : m_emitterInfo[0].tracks)
	{
		if (m_soundTime < p.startTime || !m_soundOnce)
		{
			continue;
		}

		pSound->SetVolume(p.soundLabel, p.volume);
		pSound->Play(p.soundLabel);
		m_soundOnce = false;
	}
}

//��������������������������������������������������������������
// �p�[�e�B�N���̔���`�F�b�N�p����
//��������������������������������������������������������������
void CParticleEmitter::CheckCollision(CParticle* particle)
{
	CApplication::GetInstance()->GetParticleManager()->CheckCollision(m_particle, particle);
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̈ʒu�ݒ�
//��������������������������������������������������������������
void CParticleEmitter::SetPos(D3DXVECTOR3 pos)
{
	// �r���{�[�h�̃f�[�^
	SetPosBillboard(pos);

	// ���b�V���̃f�[�^
	SetPosMesh(pos);
}

//��������������������������������������������������������������
// �r���{�[�h�̈ʒu�ݒ�
//��������������������������������������������������������������
void CParticleEmitter::SetPosBillboard(D3DXVECTOR3 pos)
{
	if (m_particle.empty())
	{
		return;
	}

	for (auto& p : m_particle)
	{
		CParticle::SInfo info = {};
		info = p->GetInfo();

		D3DXVECTOR3 currentPos = pos + info.posOffset;
		D3DXVECTOR3 calcPos = CircleRandomPos(pos, info.circleDistance, info.posOffset.y);

		switch (info.random.randomBehavior)
		{
		case CParticle::RandomBehavior_Default:
			p->SetPos(currentPos);
			break;

		case CParticle::RandomBehavior_Circle:	// �~�͈͓̔��Ń����_���ɐ���
			switch (info.random.randomLockVector)
			{
			case CParticle::Lock_None:
				p->SetPos(calcPos);
				break;
			case CParticle::Lock_X:
				p->SetPos(D3DXVECTOR3(currentPos.x, calcPos.y, calcPos.z));
				break;
			case CParticle::Lock_Y:
				p->SetPos(D3DXVECTOR3(calcPos.x, currentPos.y, calcPos.z));
				break;
			case CParticle::Lock_Z:
				p->SetPos(D3DXVECTOR3(calcPos.x, calcPos.y, currentPos.z));
				break;
			case CParticle::Lock_XY:
				p->SetPos(D3DXVECTOR3(currentPos.x, currentPos.y, calcPos.z));
				break;
			case CParticle::Lock_XZ:
				p->SetPos(D3DXVECTOR3(currentPos.x, calcPos.y, currentPos.z));
				break;
			case CParticle::Lock_YZ:
				p->SetPos(D3DXVECTOR3(calcPos.x, currentPos.y, currentPos.z));
				break;
			default:
				assert(false);
				break;
			}
			break;

		default:
			//assert(false);
			break;
		}
	}
}

//��������������������������������������������������������������
// ���b�V���̈ʒu�ݒ�
//��������������������������������������������������������������
void CParticleEmitter::SetPosMesh(D3DXVECTOR3 pos)
{
	if (m_mesh.empty())
	{
		return;
	}

	for (auto& p : m_mesh)
	{
		CMeshParticle::SInfo info = {};
		info = p->GetInfo();

		if (info.randomPos)
		{
			// �~�͈͓̔��Ń����_���ɐ���
			p->SetPos(CircleRandomPos(pos, info.circleDistance, info.posOffset.y));
		}
		else
		{
			p->SetPos(pos + info.posOffset);
		}
	}
}

//��������������������������������������������������������������
// �p�[�e�B�N���G�~�b�^�̈ʒu�擾
//��������������������������������������������������������������
D3DXVECTOR3 CParticleEmitter::GetPos()
{
	return m_particle[0]->GetPos();
}