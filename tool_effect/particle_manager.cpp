#include "application.h"
#include "object3d.h"
#include "file.h"
#include "particle_manager.h"
#include "physics.h"
#include "utility.h"
#include <thread>

namespace 
{
	// 列挙型の読み込みをする処理
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//パーティクルマネージャのコンストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CParticleManager::CParticleManager()
{
	// グリッドの生成
	CGrid::SGridData gridData = {};
	int gridSize = 5000;
	gridData.gridSizeX = gridSize;
	gridData.gridSizeY = gridSize;
	gridData.gridSizeZ = gridSize;
	gridData.cellSize = 100;
	m_pGrid = new CGrid(gridData);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルマネージャのデストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CParticleManager::~CParticleManager()
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルマネージャの初期化
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
HRESULT CParticleManager::Init()
{
	return S_OK;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルマネージャの解放
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ファイル読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ファイルの全ての要素を読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テキストファイルのデータ読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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
	{	// 一行ずつ読み込む
		// 空白を削除
		line.erase(std::remove_if(line.begin(), line.end(), [](char c) { return std::isspace(c); }), line.end());

		std::stringstream ss(line);

		if (ReadString(ss, "Tag", tag[tagIndex]))
		{
			dataIndex = tagIndex;
			tagIndex++;
			continue;
		}

		if (ReadInt(ss, "Index", index))		// インデックス
		{
			bundleData[tag[dataIndex]].resize(index + 1);
			continue;
		}

		bundleData[tag[dataIndex]][index].emitterData.emitterIndex = index;
		int behaviorIndex;
		int setRandomPosIndex;
		int lockPosIndex;
		int blendIndex;

		ReadBool(ss, "UseRandom", bundleData[tag[dataIndex]][index].info.useRandom);							// ランダムを使用するかどうか
		ReadVector3(ss, "RandomVelocityMin", bundleData[tag[dataIndex]][index].info.random.randomVelocityMin);	// 移動量のランダムの最低値
		ReadVector3(ss, "RandomVelocityMax", bundleData[tag[dataIndex]][index].info.random.randomVelocityMax);	// 移動量のランダムの最大値
		ReadFloat(ss, "RandomRotateMin", bundleData[tag[dataIndex]][index].info.random.randomRotate.y);			// 回転のランダムの最低値
		ReadFloat(ss, "RandomRotateMax", bundleData[tag[dataIndex]][index].info.random.randomRotate.x);			// 回転のランダムの最大値
		ReadFloat(ss, "RandomWeightMin", bundleData[tag[dataIndex]][index].info.random.randomWeight.y);			// 重さのランダムの最低値
		ReadFloat(ss, "RandomWeightMax", bundleData[tag[dataIndex]][index].info.random.randomWeight.x);			// 重さのランダムの最大値
		ReadFloat(ss, "DistortionMin", bundleData[tag[dataIndex]][index].info.random.distortion.y);
		ReadFloat(ss, "DistortionMax", bundleData[tag[dataIndex]][index].info.random.distortion.x);
		ReadInt(ss, "RandomCreate", setRandomPosIndex);															// ランダムな位置設定の列挙
		ReadInt(ss, "LockPosition", lockPosIndex);																// 位置のロック設定
		ReadInt(ss, "DelayStartTime", bundleData[tag[dataIndex]][index].info.beginDelay);						// 開始時間の遅延
		ReadFloat(ss, "CreateRange", bundleData[tag[dataIndex]][index].info.circleDistance);					// 生成位置の範囲
		ReadVector3(ss, "PosOffset", bundleData[tag[dataIndex]][index].info.posOffset);							// 位置のオフセット
		ReadVector3(ss, "Velocity", bundleData[tag[dataIndex]][index].info.move);								// 移動量
		ReadFloat(ss, "VelocityAttenuation", bundleData[tag[dataIndex]][index].info.moveAttenuation);			// 移動の減衰量
		ReadInt(ss, "Behavior", behaviorIndex);																	// 挙動の列挙
		ReadVector3(ss, "Scale", bundleData[tag[dataIndex]][index].info.scale);									// 大きさ
		ReadColor(ss, "Color", bundleData[tag[dataIndex]][index].info.col);										// 色
		ReadColor(ss, "DestColor", bundleData[tag[dataIndex]][index].info.destCol);								// 目的の色
		ReadFloat(ss, "ColorAttenuation", bundleData[tag[dataIndex]][index].info.colAttenuation);				// 色の減衰量
		ReadInt(ss, "BlendType", blendIndex);
		ReadVector3(ss, "Scaling", bundleData[tag[dataIndex]][index].info.scalingValue);						// 拡縮量
		ReadFloat(ss, "Weight", bundleData[tag[dataIndex]][index].info.weight);									// 重さ
		ReadFloat(ss, "Radius", bundleData[tag[dataIndex]][index].emitterData.radius);							// 円周
		ReadFloat(ss, "RotateAngle", bundleData[tag[dataIndex]][index].info.rotate.angle);						// 螺旋状の回転量
		ReadFloat(ss, "RotateRadius", bundleData[tag[dataIndex]][index].info.rotate.radius);					// 螺旋状の半径
		ReadFloat(ss, "RandomRotateMaxBH", bundleData[tag[dataIndex]][index].info.rotate.randomMax);				// 回転量のランダムの最大値
		ReadFloat(ss, "RandomRotateMinBH", bundleData[tag[dataIndex]][index].info.rotate.randomMin);				// 回転量のランダムの最低値
		ReadInt(ss, "PopTime", bundleData[tag[dataIndex]][index].info.popTime);									// 生存時間
		ReadInt(ss, "Quantity", bundleData[tag[dataIndex]][index].emitterData.popParticleNum);					// 生成量
		ReadString(ss, "TextureTag", bundleData[tag[dataIndex]][index].emitterData.texTag);						// テクスチャのタグ
		ReadBool(ss, "Trail", bundleData[tag[dataIndex]][index].info.useTrail);									// トレイルを使用するかどうか

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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テキストファイルのベクターの読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::ReadVector3(std::stringstream& ss, std::string name, D3DXVECTOR3& vec)
{
	std::vector<float> num;
	std::string str;
	std::string result;
	float value;

	// ：が見つかるまでの文字を抽出
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ssの状態をクリアし、読み取り位置を先頭に戻す
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);

		// 先頭から":"まで読み飛ばす
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テキストファイルの色の読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::ReadColor(std::stringstream& ss, std::string name, D3DXCOLOR& color)
{
	std::vector<float> num;
	std::string str;
	std::string result;
	float value;

	// ：が見つかるまでの文字を抽出
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ssの状態をクリアし、読み取り位置を先頭に戻す
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);

		// 先頭から":"まで読み飛ばす
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テキストファイルの文字の読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CParticleManager::ReadString(std::stringstream& ss, std::string name, std::string& tag)
{
	std::vector<float> num;
	std::string str;
	std::string result;

	// ：が見つかるまでの文字を抽出
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ssの状態をクリアし、読み取り位置を先頭に戻す
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);
		std::string str_tag;

		// 先頭から":"まで読み飛ばす
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テキストファイルの整数の読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CParticleManager::ReadInt(std::stringstream& ss, std::string name, int& value)
{
	std::string str;
	std::string result;

	// ：が見つかるまでの文字を抽出
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ssの状態をクリアし、読み取り位置を先頭に戻す
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);

		// 先頭から":"まで読み飛ばす
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テキストファイルの浮動小数の読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::ReadFloat(std::stringstream& ss, std::string name, float& value)
{
	std::string str;
	std::string result;

	// ：が見つかるまでの文字を抽出
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ssの状態をクリアし、読み取り位置を先頭に戻す
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		std::string str_random;

		ssInitialize(ss);

		// 先頭から":"まで読み飛ばす
		std::getline(ss, str, ':');

		while (std::getline(ss, str, ','))
		{
			value = std::stof(str);
		}
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テキストファイルの真偽の読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CParticleManager::ReadBool(std::stringstream& ss, std::string name, bool& value)
{
	std::string str;
	std::string result;

	// ：が見つかるまでの文字を抽出
	size_t pos = ss.str().find(":");
	if (pos != std::string::npos)
	{
		result = ss.str().substr(0, pos);
	}

	// ssの状態をクリアし、読み取り位置を先頭に戻す
	ssInitialize(ss);

	if (ss >> str && result == name)
	{
		ssInitialize(ss);
		std::string str_boolean;

		// 先頭から":"まで読み飛ばす
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ファイル書き出し（txt）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::SaveText(std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>>& data)
{
	// ファイルを開く
	std::ofstream out(L"Data/FILE/particle.txt");

	for (auto &p : data)
	{
		SaveString(out, "Tag", static_cast<const std::string>(p.first));				// タグ
	
		for (size_t i = 0; i < p.second.size(); i++)
		{
			CParticle::SInfo info = p.second[i].info;
			CParticleEmitter::SEmitterInfo emitInfo = p.second[i].emitterData;

			SaveInt(out, "Index", i);												// ベクターのインデックス
			SaveBool(out, "UseRandom", info.useRandom);								// ランダムを使用するかどうか
			SaveVector3(out, "RandomVelocityMin", info.random.randomVelocityMin);	// 移動量のランダムの最低値
			SaveVector3(out, "RandomVelocityMax", info.random.randomVelocityMax);	// 移動量のランダムの最大値
			SaveFloat(out, "RandomRotateMin", info.random.randomRotate.y);			// 回転のランダムの最低値
			SaveFloat(out, "RandomRotateMax", info.random.randomRotate.x);			// 回転のランダムの最大値
			SaveFloat(out, "RandomWeightMin", info.random.randomWeight.y);			// 重さのランダムの最低値
			SaveFloat(out, "RandomWeightMax", info.random.randomWeight.x);			// 重さのランダムの最大値
			SaveFloat(out, "DistortionMin", info.random.distortion.y);				// 球体放出
			SaveFloat(out, "DistortionMax", info.random.distortion.x);
			SaveInt(out, "RandomCreate", info.random.randomBehavior);				// ランダムな位置設定の列挙
			SaveInt(out, "LockPosition", info.random.randomLockVector);				// 位置のロック設定
			SaveInt(out, "DelayStartTime", info.beginDelay);						// 開始時間の遅延
			SaveFloat(out, "CreateRange", info.circleDistance);						// 生成位置の範囲
			SaveVector3(out, "PosOffset", info.posOffset);							// 位置のオフセット
			SaveVector3(out, "Velocity", info.move);								// 移動量
			SaveFloat(out, "VelocityAttenuation", info.moveAttenuation);			// 移動の減衰量
			SaveInt(out, "Behavior", emitInfo.behavior);							// 挙動の列挙
			SaveVector3(out, "Scale", info.scale);									// 大きさ
			SaveColor(out, "Color", info.col);										// 色
			SaveColor(out, "DestColor", info.destCol);								// 目的の色
			SaveFloat(out, "ColorAttenuation", info.colAttenuation);				// 色の減衰量
			SaveInt(out, "BlendType", info.blendState);								// ブレンドタイプ
			SaveVector3(out, "Scaling", info.scalingValue);							// 拡縮量
			SaveFloat(out, "Weight", info.weight);									// 重さ
			SaveFloat(out, "Radius", emitInfo.radius);								// 円周
			SaveFloat(out, "RotateAngle", info.rotate.angle);						// 螺旋状の回転量
			SaveFloat(out, "RotateRadius", info.rotate.radius);						// 螺旋状の半径
			SaveFloat(out, "RandomRotateMinBH", info.rotate.randomMin);				// 螺旋状の回転量の最低値
			SaveFloat(out, "RandomRotateMaxBH", info.rotate.randomMax);				// 螺旋状の回転量の最大値
			SaveInt(out, "PopTime", info.popTime);									// 生存時間
			SaveInt(out, "Quantity", emitInfo.popParticleNum);						// 生成量
			SaveString(out, "TextureTag", emitInfo.texTag);							// テクスチャのタグ
			SaveBool(out, "Trail", info.useTrail);									// トレイルを使用するかどうか
		}
	}

	// ファイルを閉じる
	out.close();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ファイル書き出し（Json）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::SaveJson(std::string path, std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>>& data)
{
	nlohmann::json saveData;//リストの生成
	
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの読み込み（ビルボード）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::LoadJsonBillboard(nlohmann::json& list, CParticleManager::SBundleData& data)
{
	SafeLoad(list, "Tag", data.emitterData.particleTag);					// タグ
	SafeLoad(list, "RandomWeight", data.info.random.randomWeight.y);		// ランダムの最低値
	SafeLoad(list, "RandomMax", data.info.random.randomWeight.x);			// ランダムの最大値
	SafeLoad(list, "DistortionMin", data.info.random.distortion.y);			// 球状放出歪み最低値
	SafeLoad(list, "DistortionMax", data.info.random.distortion.x);			// 球状放出歪み最大値
	SafeLoadEnum(list, "RandomCreate", data.info.random.randomBehavior);	// ランダムな位置設定の列挙
	SafeLoadEnum(list, "LockPosition", data.info.random.randomLockVector);	// 位置のロック設定
	SafeLoad(list, "DelayStartTime", data.info.beginDelay);					// 開始時間の遅延
	SafeLoad(list, "UseRandom", data.info.useRandom);						// ランダムを適用
	SafeLoad(list, "CreateRange", data.info.circleDistance);				// 生成位置の範囲
	SafeLoad(list, "PosOffset", data.info.posOffset);						// 位置のオフセット
	SafeLoad(list, "Velocity", data.info.move);								// 移動量
	SafeLoad(list, "VelocityAttenuation", data.info.moveAttenuation);		// 移動の減衰量
	SafeLoadEnum(list, "Behavior", data.emitterData.behavior);				// 挙動の列挙
	SafeLoad(list, "Scale", data.info.scale);								// 大きさ
	SafeLoad(list, "Color", data.info.col);									// 色
	SafeLoad(list, "DestColor", data.info.destCol);							// 目的の色
	SafeLoad(list, "ColorAttenuation", data.info.colAttenuation);			// 色の減衰量
	SafeLoad(list, "Scaling", data.info.scalingValue);						// 拡縮量
	SafeLoad(list, "Weight", data.info.weight);								// 重さ
	SafeLoad(list, "Radius", data.emitterData.radius);						// 円周
	SafeLoad(list, "RotateAngle", data.info.rotate.angle);					// 螺旋状の回転量
	SafeLoad(list, "RotateRadius", data.info.rotate.radius);				// 螺旋状の半径
	SafeLoad(list, "RandomRotateMax", data.info.rotate.randomMax);			// 回転量のランダムの最大値
	SafeLoad(list, "RandomRotateMin", data.info.rotate.randomMin);			// 回転量のランダムの最低値
	SafeLoad(list, "PopTime", data.info.popTime);							// 生存時間
	SafeLoad(list, "Quantity", data.emitterData.popParticleNum);			// 生成量
	SafeLoad(list, "TextureTag", data.emitterData.texTag);					// テクスチャのタグ
	SafeLoad(list, "Trail", data.info.useTrail);							// トレイルを使用するかどうか
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの読み込み（メッシュ）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::LoadJsonMeshData(nlohmann::json& list, CParticleManager::SBundleData& data)
{
	SafeLoad(list, "Tag", data.emitterData.particleTag);					// タグ
	SafeLoad(list, "DelayStartTime", data.meshInfo.beginDelay);				// 開始時間の遅延
	SafeLoad(list, "CreateRandomPos", data.meshInfo.randomPos);				// 生成位置のランダム
	SafeLoad(list, "CreateRange", data.meshInfo.circleDistance);			// 生成位置の範囲
	SafeLoad(list, "PosOffset", data.meshInfo.posOffset);					// 位置のオフセット
	SafeLoad(list, "Velocity", data.meshInfo.move);							// 移動量
	SafeLoad(list, "VelocityAttenuation", data.meshInfo.moveAttenuation);	// 移動の減衰量
	SafeLoadEnum(list, "Behavior", data.emitterData.behavior);				// 挙動の列挙
	SafeLoad(list, "Scale", data.meshInfo.scale);							// 大きさ
	SafeLoad(list, "Color", data.meshInfo.color.col);						// 色
	SafeLoad(list, "DestColor", data.meshInfo.color.destCol);				// 目的の色
	SafeLoad(list, "ColorAttenuation", data.meshInfo.color.colAttenuation);	// 色の減衰量
	SafeLoad(list, "Scaling", data.meshInfo.scalingValue);					// 拡縮量
	SafeLoad(list, "Weight", data.meshInfo.weight);							// 重さ
	SafeLoad(list, "Radius", data.emitterData.radius);						// 円周
	SafeLoad(list, "RotateAngle", data.meshInfo.rotate.angle);				// 螺旋状の回転量
	SafeLoad(list, "RotateRadius", data.meshInfo.rotate.radius);			// 螺旋状の半径
	SafeLoad(list, "RandomRotateMax", data.meshInfo.rotate.randomMax);		// 回転量のランダムの最大値
	SafeLoad(list, "RandomRotateMin", data.meshInfo.rotate.randomMin);		// 回転量のランダムの最低値
	SafeLoad(list, "PopTime", data.meshInfo.popTime);						// 生存時間
	SafeLoad(list, "Quantity", data.emitterData.popParticleNum);			// 生成量
	SafeLoad(list, "ModelTag", data.emitterData.modelTag);					// モデルのタグ
	SafeLoad(list, "TextureTag", data.emitterData.texTag);					// テクスチャのタグ
	SafeLoad(list, "Trail", data.meshInfo.useTrail);						// トレイルを使用するかどうか
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの保存（ビルボード）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの保存（メッシュ）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ファイルのバックアップを行う処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::BackUpFile(std::string path)
{
	std::string name = "Data/FILE/" + path;
	std::string newName = "Data/FILE/backup_" + path;

	// ファイルのコピー
	CopyFile(name.c_str(), newName.c_str(), FALSE);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの判定用処理（全て判定）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの判定用処理（自分とそれ以外）
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
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

	// グリッドを使用して衝突判定
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

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// データを設定する処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticleManager::SetParticleData(std::string& str, std::vector<SBundleData>& info)
{
	m_data[str] = info;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 抽出したデータを返す処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
std::vector<CParticleManager::SBundleData> CParticleManager::GetParticleData(std::string str)
{
	if (m_data.count(str) == 0)
	{	//モデルデータが入ってなかった場合
		assert(false);
	}

	return m_data[str];
}