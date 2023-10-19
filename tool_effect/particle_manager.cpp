#include "application.h"
#include "object3d.h"
#include "file.h"
#include "particle_manager.h"
#include "physics.h"
#include "utility.h"
#include <thread>

namespace 
{
	// �񋓌^�̓ǂݍ��݂����鏈��
	template<typename T>
	inline void SafeLoadEnum(nlohmann::json check, std::string str, T& value)
	{
		if (check[str].empty())
		{
			value = utility::IntToEnum<T>(0);
		}
		else 
		{
			value = utility::IntToEnum<T>(check[str]);
		}
	}
}

//��������������������������������������������������������������
//�p�[�e�B�N���}�l�[�W���̃R���X�g���N�^
//��������������������������������������������������������������
CParticleManager::CParticleManager()
{
	// �O���b�h�̐���
	CGrid::SGridData gridData = {};
	int gridSize = 5000;
	gridData.gridSizeX = gridSize;
	gridData.gridSizeY = gridSize;
	gridData.gridSizeZ = gridSize;
	gridData.cellSize = 100;
	m_pGrid = new CGrid(gridData);
}

//��������������������������������������������������������������
// �p�[�e�B�N���}�l�[�W���̃f�X�g���N�^
//��������������������������������������������������������������
CParticleManager::~CParticleManager()
{
}

//��������������������������������������������������������������
// �p�[�e�B�N���}�l�[�W���̏�����
//��������������������������������������������������������������
HRESULT CParticleManager::Init()
{
	return S_OK;
}

//��������������������������������������������������������������
// �p�[�e�B�N���}�l�[�W���̉��
//��������������������������������������������������������������
void CParticleManager::ReleaseAll()
{
	if (m_pGrid != nullptr)
	{
		m_pGrid->ClearObject();
		delete m_pGrid;
		m_pGrid = nullptr;
	}

	m_data.clear();
}

//��������������������������������������������������������������
// �t�@�C���ǂݍ���
//��������������������������������������������������������������
void CParticleManager::LoadJson(nlohmann::json& list)
{
	size_t size = list["Object"].size();

	std::vector <CParticleManager::SBundleData> data = {};
	data.resize(size);

	for (size_t i = 0; i < size; i++)
	{
		int objectType = 0;

		data[i].emitterData.particleTag = list["DataTag"];
		objectType = list["Object"][i]["ParticleType"];
		data[i].emitterData.objType = static_cast<CParticleEmitter::EObjectType>(objectType);

		switch (data[i].emitterData.objType)
		{
		case CParticleEmitter::OBJECT_BILLBOARD:
			LoadJsonBillboard(list["Object"][i], data[i]);
			break;

		case CParticleEmitter::OBJECT_MESH:
			LoadJsonMeshData(list["Object"][i], data[i]);
			break;
		}
	}

	m_data.insert(std::make_pair(list["DataTag"], data));
}

//��������������������������������������������������������������
// �t�@�C���̑S�Ă̗v�f��ǂݍ���
//��������������������������������������������������������������
void CParticleManager::LoadAll()
{
	nlohmann::json list = CFile::LoadJsonStage(L"Data/FILE/particle.json");

	size_t size = list["PARTICLE"].size();
	for (size_t i = 0; i < size; i++)
	{
		if (list["PARTICLE"][i]["DataTag"].empty())
		{
			continue;
		}

		LoadJson(list["PARTICLE"].at(i));
	}
}

//��������������������������������������������������������������
// �e�L�X�g�t�@�C���̃f�[�^�ǂݍ���
//��������������������������������������������������������������
void CParticleManager::LoadText(std::string path, std::map<std::string, std::vector<SBundleData>, std::less<>>& data)
{
	std::string name = "Data/FILE/" + path;
	std::ifstream file(name);

	std::map<std::string, std::vector<SBundleData>, std::less<>> bundleData = {};
	std::vector<std::string> tag(32, "");
	std::string line;
	int index = 0;
	int tagIndex = 0;
	int dataIndex = 0;

	while (std::getline(file, line))
	{	// ��s���ǂݍ���
		// �󔒂��폜
		line.erase(std::remove_if(line.begin(), line.end(), [](char c) { return std::isspace(c); }), line.end());

		std::stringstream ss(line);

		if (ReadString(ss, "Tag", tag[tagIndex]))
		{
			dataIndex = tagIndex;
			tagIndex++;
			continue;
		}

		if (ReadInt(ss, "Index", index))		// �C���f�b�N�X
		{
			bundleData[tag[dataIndex]].resize(index + 1);
			continue;
		}

		bundleData[tag[dataIndex]][index].emitterData.emitterIndex = index;
		int behaviorIndex;
		int setRandomPosIndex;
		int lockPosIndex;
		int blendIndex;

		ReadBool(ss, "UseRandom", bundleData[tag[dataIndex]][index].info.useRandom);							// �����_�����g�p���邩�ǂ���
		ReadVector3(ss, "RandomVelocityMin", bundleData[tag[dataIndex]][index].info.random.randomVelocityMin);	// �ړ��ʂ̃����_���̍Œ�l
		ReadVector3(ss, "RandomVelocityMax", bundleData[tag[dataIndex]][index].info.random.randomVelocityMax);	// �ړ��ʂ̃����_���̍ő�l
		ReadFloat(ss, "RandomRotateMin", bundleData[tag[dataIndex]][index].info.random.randomRotate.y);			// ��]�̃����_���̍Œ�l
		ReadFloat(ss, "RandomRotateMax", bundleData[tag[dataIndex]][index].info.random.randomRotate.x);			// ��]�̃����_���̍ő�l
		ReadFloat(ss, "RandomWeightMin", bundleData[tag[dataIndex]][index].info.random.randomWeight.y);			// �d���̃����_���̍Œ�l
		ReadFloat(ss, "RandomWeightMax", bundleData[tag[dataIndex]][index].info.random.randomWeight.x);			// �d���̃����_���̍ő�l
		ReadFloat(ss, "DistortionMin", bundleData[tag[dataIndex]][index].info.random.distortion.y);
		ReadFloat(ss, "DistortionMax", bundleData[tag[dataIndex]][index].info.random.distortion.x);
		ReadInt(ss, "RandomCreate", setRandomPosIndex);															// �����_���Ȉʒu�ݒ�̗�
		ReadInt(ss, "LockPosition", lockPosIndex);																// �ʒu�̃��b�N�ݒ�
		ReadInt(ss, "DelayStartTime", bundleData[tag[dataIndex]][index].info.beginDelay);						// �J�n���Ԃ̒x��
		ReadFloat(ss, "CreateRange", bundleData[tag[dataIndex]][index].info.circleDistance);					// �����ʒu�͈̔�
		ReadVector3(ss, "PosOffset", bundleData[tag[dataIndex]][index].info.posOffset);							// �ʒu�̃I�t�Z�b�g
		ReadVector3(ss, "Velocity", bundleData[tag[dataIndex]][index].info.move);								// �ړ���
		ReadFloat(ss, "VelocityAttenuation", bundleData[tag[dataIndex]][index].info.moveAttenuation);			// �ړ��̌�����
		ReadInt(ss, "Behavior", behaviorIndex);																	// �����̗�
		ReadVector3(ss, "Scale", bundleData[tag[dataIndex]][index].info.scale);									// �傫��
		ReadColor(ss, "Color", bundleData[tag[dataIndex]][index].info.col);										// �F
		ReadColor(ss, "DestColor", bundleData[tag[dataIndex]][index].info.destCol);								// �ړI�̐F
		ReadFloat(ss, "ColorAttenuation", bundleData[tag[dataIndex]][index].info.colAttenuation);				// �F�̌�����
		ReadInt(ss, "BlendType", blendIndex);
		ReadVector3(ss, "Scaling", bundleData[tag[dataIndex]][index].info.scalingValue);						// �g�k��
		ReadFloat(ss, "Weight", bundleData[tag[dataIndex]][index].info.weight);									// �d��
		ReadFloat(ss, "Radius", bundleData[tag[dataIndex]][index].emitterData.radius);							// �~��
		ReadFloat(ss, "RotateAngle", bundleData[tag[dataIndex]][index].info.rotate.angle);						// ������̉�]��
		ReadFloat(ss, "RotateRadius", bundleData[tag[dataIndex]][index].info.rotate.radius);					// ������̔��a
		ReadFloat(ss, "RandomRotateMaxBH", bundleData[tag[dataIndex]][index].info.rotate.randomMax);				// ��]�ʂ̃����_���̍ő�l
		ReadFloat(ss, "RandomRotateMinBH", bundleData[tag[dataIndex]][index].info.rotate.randomMin);				// ��]�ʂ̃����_���̍Œ�l
		ReadInt(ss, "PopTime", bundleData[tag[dataIndex]][index].info.popTime);									// ��������
		ReadInt(ss, "Quantity", bundleData[tag[dataIndex]][index].emitterData.popParticleNum);					// ������
		ReadString(ss, "TextureTag", bundleData[tag[dataIndex]][index].emitterData.texTag);						// �e�N�X�`���̃^�O
		ReadBool(ss, "Trail", bundleData[tag[dataIndex]][index].info.useTrail);									// �g���C�����g�p���邩�ǂ���

		bundleData[tag[dataIndex]][index].emitterData.behavior = (CParticleEmitter::EBehavior)behaviorIndex;
		bundleData[tag[dataIndex]][index].info.blendState = (CParticle::EBlend)blendIndex;
		bundleData[tag[dataIndex]][index].info.random.randomBehavior = (CParticle::ERandomBehavior)setRandomPosIndex;
		bundleData[tag[dataIndex]][index].info.random.randomLockVector = (CParticle::ELockVector)lockPosIndex;
	}

	int cnt = 0;
	std::string old_tag;
	for (size_t i = 0; i < bundleData.size(); i++)
	{
		if (tag[i] == "")
		{
			break;
		}

		if (tag[i] != old_tag)
		{
			cnt = 0;
		}

		old_tag = tag[i];
		m_data[tag[i]] = std::move(bundleData[tag[i]]);
		cnt++;
	}

	data = m_data;
}

//��������������������������������������������������������������
// �e�L�X�g�t�@�C���̃x�N�^�[�̓ǂݍ���
//��������������������������������������������������������������
void CParticleManager::ReadVector3(std::stringstream& ss, std::string name, D3DXVECTOR3& vec)
{
	std::vector<float> num;
	std::string str;
	std::string result;
	float value;

	// �F��������܂ł̕����𒊏o
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ss�̏�Ԃ��N���A���A�ǂݎ��ʒu��擪�ɖ߂�
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);

		// �擪����":"�܂œǂݔ�΂�
		std::getline(ss, str, ':');

		while (std::getline(ss, str, ','))
		{
			value = std::stof(str);
			num.push_back(value);
		}
	}

	if (num.size() == 3)
	{
		vec.x = num[0];
		vec.y = num[1];
		vec.z = num[2];
	}
}

//��������������������������������������������������������������
// �e�L�X�g�t�@�C���̐F�̓ǂݍ���
//��������������������������������������������������������������
void CParticleManager::ReadColor(std::stringstream& ss, std::string name, D3DXCOLOR& color)
{
	std::vector<float> num;
	std::string str;
	std::string result;
	float value;

	// �F��������܂ł̕����𒊏o
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ss�̏�Ԃ��N���A���A�ǂݎ��ʒu��擪�ɖ߂�
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);

		// �擪����":"�܂œǂݔ�΂�
		std::getline(ss, str, ':');

		while (std::getline(ss, str, ','))
		{
			value = std::stof(str);
			num.push_back(value);
		}
	}

	if (num.size() == 4)
	{
		color.r = num[0];
		color.g = num[1];
		color.b = num[2];
		color.a = num[3];
	}
}

//��������������������������������������������������������������
// �e�L�X�g�t�@�C���̕����̓ǂݍ���
//��������������������������������������������������������������
bool CParticleManager::ReadString(std::stringstream& ss, std::string name, std::string& tag)
{
	std::vector<float> num;
	std::string str;
	std::string result;

	// �F��������܂ł̕����𒊏o
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ss�̏�Ԃ��N���A���A�ǂݎ��ʒu��擪�ɖ߂�
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);
		std::string str_tag;

		// �擪����":"�܂œǂݔ�΂�
		std::getline(ss, str, ':');

		if (ss >> str_tag)
		{
			tag = str_tag;
		}
	}
	else
	{
		return false;
	}

	return true;
}

//��������������������������������������������������������������
// �e�L�X�g�t�@�C���̐����̓ǂݍ���
//��������������������������������������������������������������
bool CParticleManager::ReadInt(std::stringstream& ss, std::string name, int& value)
{
	std::string str;
	std::string result;

	// �F��������܂ł̕����𒊏o
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ss�̏�Ԃ��N���A���A�ǂݎ��ʒu��擪�ɖ߂�
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);

		// �擪����":"�܂œǂݔ�΂�
		std::getline(ss, str, ':');

		while (std::getline(ss, str, ','))
		{
			value = std::stoi(str);
		}
	}
	else
	{
		return false;
	}

	return true;
}

//��������������������������������������������������������������
// �e�L�X�g�t�@�C���̕��������̓ǂݍ���
//��������������������������������������������������������������
void CParticleManager::ReadFloat(std::stringstream& ss, std::string name, float& value)
{
	std::string str;
	std::string result;

	// �F��������܂ł̕����𒊏o
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ss�̏�Ԃ��N���A���A�ǂݎ��ʒu��擪�ɖ߂�
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		std::string str_random;

		ssInitialize(ss);

		// �擪����":"�܂œǂݔ�΂�
		std::getline(ss, str, ':');

		while (std::getline(ss, str, ','))
		{
			value = std::stof(str);
		}
	}
}

//��������������������������������������������������������������
// �e�L�X�g�t�@�C���̐^�U�̓ǂݍ���
//��������������������������������������������������������������
bool CParticleManager::ReadBool(std::stringstream& ss, std::string name, bool& value)
{
	std::string str;
	std::string result;

	// �F��������܂ł̕����𒊏o
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ss�̏�Ԃ��N���A���A�ǂݎ��ʒu��擪�ɖ߂�
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);
		std::string str_boolean;

		// �擪����":"�܂œǂݔ�΂�
		std::getline(ss, str, ':');

		if (ss >> str_boolean)
		{
			value = (str_boolean == "true");
		}
	}
	else
	{
		return false;
	}

	return true;
}

//��������������������������������������������������������������
// �t�@�C�������o���itxt�j
//��������������������������������������������������������������
void CParticleManager::SaveText(std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>>& data)
{
	// �t�@�C�����J��
	std::ofstream out(L"Data/FILE/particle.txt");

	for (auto &p : data)
	{
		SaveString(out, "Tag", static_cast<const std::string>(p.first));				// �^�O
	
		for (size_t i = 0; i < p.second.size(); i++)
		{
			CParticle::SInfo info = p.second[i].info;
			CParticleEmitter::SEmitterInfo emitInfo = p.second[i].emitterData;

			SaveInt(out, "Index", i);												// �x�N�^�[�̃C���f�b�N�X
			SaveBool(out, "UseRandom", info.useRandom);								// �����_�����g�p���邩�ǂ���
			SaveVector3(out, "RandomVelocityMin", info.random.randomVelocityMin);	// �ړ��ʂ̃����_���̍Œ�l
			SaveVector3(out, "RandomVelocityMax", info.random.randomVelocityMax);	// �ړ��ʂ̃����_���̍ő�l
			SaveFloat(out, "RandomRotateMin", info.random.randomRotate.y);			// ��]�̃����_���̍Œ�l
			SaveFloat(out, "RandomRotateMax", info.random.randomRotate.x);			// ��]�̃����_���̍ő�l
			SaveFloat(out, "RandomWeightMin", info.random.randomWeight.y);			// �d���̃����_���̍Œ�l
			SaveFloat(out, "RandomWeightMax", info.random.randomWeight.x);			// �d���̃����_���̍ő�l
			SaveFloat(out, "DistortionMin", info.random.distortion.y);				// ���̕��o
			SaveFloat(out, "DistortionMax", info.random.distortion.x);
			SaveInt(out, "RandomCreate", info.random.randomBehavior);				// �����_���Ȉʒu�ݒ�̗�
			SaveInt(out, "LockPosition", info.random.randomLockVector);				// �ʒu�̃��b�N�ݒ�
			SaveInt(out, "DelayStartTime", info.beginDelay);						// �J�n���Ԃ̒x��
			SaveFloat(out, "CreateRange", info.circleDistance);						// �����ʒu�͈̔�
			SaveVector3(out, "PosOffset", info.posOffset);							// �ʒu�̃I�t�Z�b�g
			SaveVector3(out, "Velocity", info.move);								// �ړ���
			SaveFloat(out, "VelocityAttenuation", info.moveAttenuation);			// �ړ��̌�����
			SaveInt(out, "Behavior", emitInfo.behavior);							// �����̗�
			SaveVector3(out, "Scale", info.scale);									// �傫��
			SaveColor(out, "Color", info.col);										// �F
			SaveColor(out, "DestColor", info.destCol);								// �ړI�̐F
			SaveFloat(out, "ColorAttenuation", info.colAttenuation);				// �F�̌�����
			SaveInt(out, "BlendType", info.blendState);								// �u�����h�^�C�v
			SaveVector3(out, "Scaling", info.scalingValue);							// �g�k��
			SaveFloat(out, "Weight", info.weight);									// �d��
			SaveFloat(out, "Radius", emitInfo.radius);								// �~��
			SaveFloat(out, "RotateAngle", info.rotate.angle);						// ������̉�]��
			SaveFloat(out, "RotateRadius", info.rotate.radius);						// ������̔��a
			SaveFloat(out, "RandomRotateMinBH", info.rotate.randomMin);				// ������̉�]�ʂ̍Œ�l
			SaveFloat(out, "RandomRotateMaxBH", info.rotate.randomMax);				// ������̉�]�ʂ̍ő�l
			SaveInt(out, "PopTime", info.popTime);									// ��������
			SaveInt(out, "Quantity", emitInfo.popParticleNum);						// ������
			SaveString(out, "TextureTag", emitInfo.texTag);							// �e�N�X�`���̃^�O
			SaveBool(out, "Trail", info.useTrail);									// �g���C�����g�p���邩�ǂ���
		}
	}

	// �t�@�C�������
	out.close();
}

//��������������������������������������������������������������
// �t�@�C�������o���iJson�j
//��������������������������������������������������������������
void CParticleManager::SaveJson(std::string path, std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>>& data)
{
	nlohmann::json saveData;//���X�g�̐���
	
	int index = 0;
	for (auto &p : data)
	{
		saveData["PARTICLE"][index]["DataTag"] = p.first;

		for (size_t i = 0; i < p.second.size(); i++)
		{
			switch (p.second[i].emitterData.objType)
			{
			case 0:
				SaveJsonBillboardData(saveData["PARTICLE"][index]["Object"][i], p.second[i]);
				break;

			case 1:
				SaveJsonMeshData(saveData["PARTICLE"][index]["Object"][i], p.second[i]);
				break;
			}
		}
		index++;
	}

	CFile::SaveJson(saveData, path);
}

//��������������������������������������������������������������
// �p�[�e�B�N���̓ǂݍ��݁i�r���{�[�h�j
//��������������������������������������������������������������
void CParticleManager::LoadJsonBillboard(nlohmann::json& list, CParticleManager::SBundleData& data)
{
	SafeLoad(list, "Tag", data.emitterData.particleTag);					// �^�O
	SafeLoad(list, "RandomWeight", data.info.random.randomWeight.y);		// �����_���̍Œ�l
	SafeLoad(list, "RandomMax", data.info.random.randomWeight.x);			// �����_���̍ő�l
	SafeLoad(list, "DistortionMin", data.info.random.distortion.y);			// ������o�c�ݍŒ�l
	SafeLoad(list, "DistortionMax", data.info.random.distortion.x);			// ������o�c�ݍő�l
	SafeLoadEnum(list, "RandomCreate", data.info.random.randomBehavior);	// �����_���Ȉʒu�ݒ�̗�
	SafeLoadEnum(list, "LockPosition", data.info.random.randomLockVector);	// �ʒu�̃��b�N�ݒ�
	SafeLoad(list, "DelayStartTime", data.info.beginDelay);					// �J�n���Ԃ̒x��
	SafeLoad(list, "UseRandom", data.info.useRandom);						// �����_����K�p
	SafeLoad(list, "CreateRange", data.info.circleDistance);				// �����ʒu�͈̔�
	SafeLoad(list, "PosOffset", data.info.posOffset);						// �ʒu�̃I�t�Z�b�g
	SafeLoad(list, "Velocity", data.info.move);								// �ړ���
	SafeLoad(list, "VelocityAttenuation", data.info.moveAttenuation);		// �ړ��̌�����
	SafeLoadEnum(list, "Behavior", data.emitterData.behavior);				// �����̗�
	SafeLoad(list, "Scale", data.info.scale);								// �傫��
	SafeLoad(list, "Color", data.info.col);									// �F
	SafeLoad(list, "DestColor", data.info.destCol);							// �ړI�̐F
	SafeLoad(list, "ColorAttenuation", data.info.colAttenuation);			// �F�̌�����
	SafeLoad(list, "Scaling", data.info.scalingValue);						// �g�k��
	SafeLoad(list, "Weight", data.info.weight);								// �d��
	SafeLoad(list, "Radius", data.emitterData.radius);						// �~��
	SafeLoad(list, "RotateAngle", data.info.rotate.angle);					// ������̉�]��
	SafeLoad(list, "RotateRadius", data.info.rotate.radius);				// ������̔��a
	SafeLoad(list, "RandomRotateMax", data.info.rotate.randomMax);			// ��]�ʂ̃����_���̍ő�l
	SafeLoad(list, "RandomRotateMin", data.info.rotate.randomMin);			// ��]�ʂ̃����_���̍Œ�l
	SafeLoad(list, "PopTime", data.info.popTime);							// ��������
	SafeLoad(list, "Quantity", data.emitterData.popParticleNum);			// ������
	SafeLoad(list, "TextureTag", data.emitterData.texTag);					// �e�N�X�`���̃^�O
	SafeLoad(list, "Trail", data.info.useTrail);							// �g���C�����g�p���邩�ǂ���
}

//��������������������������������������������������������������
// �p�[�e�B�N���̓ǂݍ��݁i���b�V���j
//��������������������������������������������������������������
void CParticleManager::LoadJsonMeshData(nlohmann::json& list, CParticleManager::SBundleData& data)
{
	SafeLoad(list, "Tag", data.emitterData.particleTag);					// �^�O
	SafeLoad(list, "DelayStartTime", data.meshInfo.beginDelay);				// �J�n���Ԃ̒x��
	SafeLoad(list, "CreateRandomPos", data.meshInfo.randomPos);				// �����ʒu�̃����_��
	SafeLoad(list, "CreateRange", data.meshInfo.circleDistance);			// �����ʒu�͈̔�
	SafeLoad(list, "PosOffset", data.meshInfo.posOffset);					// �ʒu�̃I�t�Z�b�g
	SafeLoad(list, "Velocity", data.meshInfo.move);							// �ړ���
	SafeLoad(list, "VelocityAttenuation", data.meshInfo.moveAttenuation);	// �ړ��̌�����
	SafeLoadEnum(list, "Behavior", data.emitterData.behavior);				// �����̗�
	SafeLoad(list, "Scale", data.meshInfo.scale);							// �傫��
	SafeLoad(list, "Color", data.meshInfo.color.col);						// �F
	SafeLoad(list, "DestColor", data.meshInfo.color.destCol);				// �ړI�̐F
	SafeLoad(list, "ColorAttenuation", data.meshInfo.color.colAttenuation);	// �F�̌�����
	SafeLoad(list, "Scaling", data.meshInfo.scalingValue);					// �g�k��
	SafeLoad(list, "Weight", data.meshInfo.weight);							// �d��
	SafeLoad(list, "Radius", data.emitterData.radius);						// �~��
	SafeLoad(list, "RotateAngle", data.meshInfo.rotate.angle);				// ������̉�]��
	SafeLoad(list, "RotateRadius", data.meshInfo.rotate.radius);			// ������̔��a
	SafeLoad(list, "RandomRotateMax", data.meshInfo.rotate.randomMax);		// ��]�ʂ̃����_���̍ő�l
	SafeLoad(list, "RandomRotateMin", data.meshInfo.rotate.randomMin);		// ��]�ʂ̃����_���̍Œ�l
	SafeLoad(list, "PopTime", data.meshInfo.popTime);						// ��������
	SafeLoad(list, "Quantity", data.emitterData.popParticleNum);			// ������
	SafeLoad(list, "ModelTag", data.emitterData.modelTag);					// ���f���̃^�O
	SafeLoad(list, "TextureTag", data.emitterData.texTag);					// �e�N�X�`���̃^�O
	SafeLoad(list, "Trail", data.meshInfo.useTrail);						// �g���C�����g�p���邩�ǂ���
}

//��������������������������������������������������������������
// �p�[�e�B�N���̕ۑ��i�r���{�[�h�j
//��������������������������������������������������������������
void CParticleManager::SaveJsonBillboardData(nlohmann::json& list, CParticleManager::SBundleData& data)
{
	list = {
		{ "ParticleType" , data.emitterData.objType },
		{ "RandomMin" , data.info.random.randomWeight.y },
		{ "RandomMax" , data.info.random.randomWeight.x },
		{ "DelayStartTime" , data.info.beginDelay },
		{ "DistortionMin" , data.info.random.distortion.y },
		{ "DistortionMax" , data.info.random.distortion.x },
		{ "RandomCreate", data.info.random.randomBehavior },
		{ "LockPosition", data.info.random.randomLockVector },
		{ "UseRandom" , data.info.useRandom },
		{ "CreateRange" , data.info.circleDistance },
		{ "PosOffset",{ { "X", data.info.posOffset.x },
						{ "Y", data.info.posOffset.y },
						{ "Z", data.info.posOffset.z } } },
		{ "Velocity",{ { "X", data.info.move.x },
						{ "Y",data.info.move.y },
						{ "Z",data.info.move.z } } },
		{ "VelocityAttenuation", data.info.moveAttenuation },
		{ "Behavior", data.emitterData.behavior },
		{ "Scale",{ { "X", data.info.scale.x },
					{ "Y", data.info.scale.y },
					{ "Z", data.info.scale.z } } },
		{ "Color",{ { "R", data.info.col.r },
					{ "G", data.info.col.g },
					{ "B", data.info.col.b },
					{ "A", data.info.col.a } } },
		{ "DestColor",{ { "R", data.info.destCol.r },
						{ "G", data.info.destCol.g },
						{ "B", data.info.destCol.b },
						{ "A", data.info.destCol.a } } },
		{ "ColorAttenuation", data.info.colAttenuation },
		{ "Scaling",{ { "X", data.info.scalingValue.x },
					{ "Y", data.info.scalingValue.y },
					{ "Z", data.info.scalingValue.z } } },
		{ "Weight", data.info.weight },
		{ "Radius", data.emitterData.radius },
		{ "RotateAngle", data.info.rotate.angle },
		{ "RotateRadius", data.info.rotate.radius },
		{ "RandomRotateMax", data.info.rotate.randomMax },
		{ "RandomRotateMin", data.info.rotate.randomMin },
		{ "PopTime", data.info.popTime },
		{ "Quantity", data.emitterData.popParticleNum },
		{ "TextureTag", data.emitterData.texTag },
		{ "Trail", data.info.useTrail },
		{ "SeparateTrailColors", data.info.separateTrail },
		{ "Physics",{ { "Type", data.info.physicsType },
					{ "Bounce",{ "BounceFactor", data.info.physics.bounce.bounceFactor },
								{ "Coefficient", data.info.physics.bounce.elasticityCoefficient } },
					{ "Air" ,{ "VectorFactor", data.info.physics.air.vecFactor },
								{ "Coefficient", data.info.physics.air.dragCoefficient } } } }
	};
}

//��������������������������������������������������������������
// �p�[�e�B�N���̕ۑ��i���b�V���j
//��������������������������������������������������������������
void CParticleManager::SaveJsonMeshData(nlohmann::json& list, CParticleManager::SBundleData& data)
{
	list = {
		{ "ParticleType" , data.emitterData.objType },
		{ "DelayStartTime" , data.meshInfo.beginDelay },
		{ "CreateRandomPos" , data.meshInfo.randomPos },
		{ "CreateRange" , data.meshInfo.circleDistance },
		{ "PosOffset",{ { "X", data.meshInfo.posOffset.x },
						{ "Y", data.meshInfo.posOffset.y },
						{ "Z", data.meshInfo.posOffset.z } } },
		{ "Velocity",{ { "X", data.meshInfo.move.x },
						{ "Y",data.meshInfo.move.y },
						{ "Z",data.meshInfo.move.z } } },
		{ "VelocityAttenuation", data.meshInfo.moveAttenuation },
		{ "Behavior", data.emitterData.behavior },
		{ "Scale",{ { "X", data.meshInfo.scale.x },
					{ "Y", data.meshInfo.scale.y },
					{ "Z", data.meshInfo.scale.z } } },
		{ "Color",{ { "R", data.meshInfo.color.col.r },
					{ "G", data.meshInfo.color.col.g },
					{ "B", data.meshInfo.color.col.b },
					{ "A", data.meshInfo.color.col.a } } },
		{ "DestColor",{ { "R", data.meshInfo.color.destCol.r },
						{ "G", data.meshInfo.color.destCol.g },
						{ "B", data.meshInfo.color.destCol.b },
						{ "A", data.meshInfo.color.destCol.a } } },
		{ "Scaling",{ { "X", data.meshInfo.scalingValue.x },
					{ "Y", data.meshInfo.scalingValue.y },
					{ "Z", data.meshInfo.scalingValue.z } } },
		{ "Weight", data.meshInfo.weight },
		{ "Radius", data.emitterData.radius },
		{ "RotateAngle", data.meshInfo.rotate.angle },
		{ "RotateRadius", data.meshInfo.rotate.radius },
		{ "RandomRotateMax", data.meshInfo.rotate.randomMax },
		{ "RandomRotateMin", data.meshInfo.rotate.randomMin },
		{ "PopTime", data.meshInfo.popTime },
		{ "Quantity", data.emitterData.popParticleNum },
		{ "ModelTag", data.emitterData.modelTag },
		{ "TextureTag", data.emitterData.texTag },
		{ "Trail", data.meshInfo.useTrail },
	};
}

void CParticleManager::LoadInitializeData(CParticleManager::SBundleData& data)
{
	nlohmann::json list = CFile::LoadJsonStage(L"Data/FILE/particle_Initialize.json");
	int objectType = 0;

	data.emitterData.particleTag = list["DataTag"];
	objectType = list["Object"][0]["ParticleType"];
	data.emitterData.objType = static_cast<CParticleEmitter::EObjectType>(objectType);

	LoadJsonBillboard(list["Object"][0], data);
	LoadJsonMeshData(list["Object"][0], data);
}

//��������������������������������������������������������������
// �t�@�C���̃o�b�N�A�b�v���s������
//��������������������������������������������������������������
void CParticleManager::BackUpFile(std::string path)
{
	std::string name = "Data/FILE/" + path;
	std::string newName = "Data/FILE/backup_" + path;

	// �t�@�C���̃R�s�[
	CopyFile(name.c_str(), newName.c_str(), FALSE);
}

//��������������������������������������������������������������
// �p�[�e�B�N���̔���p�����i�S�Ĕ���j
//��������������������������������������������������������������
void CParticleManager::CheckCollision(std::vector<CParticle*> data)
{
	if (data.empty())
	{
		return;
	}

	CPhysics *pPhysics = CApplication::GetInstance()->GetPhysics();
	for (size_t i = 0; i < data.size(); i++)
	{
		if (data[i] == nullptr)
		{
			continue;
		}

		CParticle::SInfo infoA = data[i]->GetInfo();

		for (size_t j = i + 1; j < data.size(); j++)
		{
			if (data[j] == nullptr)
			{
				continue;
			}

			CParticle::SInfo infoB = data[j]->GetInfo();

			CPhysics::SBoundingBox boxA, boxB;
			D3DXVECTOR3 large(20.0f, 20.0f, 20.0f);
			boxA.minPoint = data[i]->GetPos() - large;
			boxA.maxPoint = data[i]->GetPos() + large;
			boxB.minPoint = data[j]->GetPos() - large;
			boxB.maxPoint = data[j]->GetPos() + large;

			if (pPhysics->isBoundingBoxCollision(boxA, boxB))
			{
				infoA.collision = true;
				infoB.collision = true;
				data[i]->SetInfo(infoA);
				data[j]->SetInfo(infoB);
			}
			else
			{
				infoA.collision = false;
				infoB.collision = false;
			}

			data[i]->SetInfo(infoA);
			data[j]->SetInfo(infoB);
		}
	}
}

//��������������������������������������������������������������
// �p�[�e�B�N���̔���p�����i�����Ƃ���ȊO�j
//��������������������������������������������������������������
void CParticleManager::CheckCollision(std::vector<CParticle*> data, CParticle* self)
{
	if (data.empty())
	{
		return;
	}

	CPhysics* pPhysics = CApplication::GetInstance()->GetPhysics();
	CParticle::SInfo infoA = self->GetInfo();
	D3DXVECTOR3 selfPos = self->GetPos();
	const float large = 15.0f;

	// �O���b�h���g�p���ďՓ˔���
	std::vector<CObject*> neighboringParticles = self->GetGrid()->GetCellsAtPosition(selfPos);
	for (size_t i = 0; i < neighboringParticles.size(); i++)
	{
		if (neighboringParticles[i] == nullptr || 
			neighboringParticles[i]->GetObjType() != CObject::EObjType::OBJTYPE_PARTICLE || 
			neighboringParticles[i]->GetObjState() != CObject::EObjState::OBJSTATE_3D || 
			i >= data.size())
		{
			continue;
		}

		CParticle* anotherParticle = dynamic_cast<CParticle*>(neighboringParticles[i]);

		CParticle::SInfo infoB = anotherParticle->GetInfo();

		if (pPhysics->isCircleCollision(selfPos, large, data[i]->GetPos(), large))
		{
			infoA.collision = true;
			infoB.collision = true;
			self->SetInfo(infoA);
			anotherParticle->SetInfo(infoB);

			self->CollisionData(anotherParticle);
			anotherParticle->CollisionData(self);
		}
		else
		{
			infoB.collision = false;
			anotherParticle->SetInfo(infoB);
		}
	}

	self->SetInfo(infoA);
}

//��������������������������������������������������������������
// �f�[�^��ݒ肷�鏈��
//��������������������������������������������������������������
void CParticleManager::SetParticleData(std::string& str, std::vector<SBundleData>& info)
{
	m_data[str] = info;
}

//��������������������������������������������������������������
// ���o�����f�[�^��Ԃ�����
//��������������������������������������������������������������
std::vector<CParticleManager::SBundleData> CParticleManager::GetParticleData(std::string str)
{
	if (m_data.count(str) == 0)
	{	//���f���f�[�^�������ĂȂ������ꍇ
		assert(false);
	}

	return m_data[str];
}