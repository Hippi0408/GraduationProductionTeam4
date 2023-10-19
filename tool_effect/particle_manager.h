#ifndef _PARTICLE_MANAGER_H_
#define _PARTICLE_MANAGER_H_

#include "file.h"
#include "grid.h"
#include "particle.h"
#include "mesh_particle.h"
#include "particle_emitter.h"

#include <fstream>
#include <sstream>

class CParticle;
class CMeshParticle;
class CParticleEmitter;
class CGrid;

class CParticleManager
{
public:
	struct SBundleData
	{
		CParticle::SInfo info;
		CMeshParticle::SInfo meshInfo;
		CParticleEmitter::SEmitterInfo emitterData;
	};

	CParticleManager();
	~CParticleManager();

	HRESULT Init();
	void ReleaseAll();
	void LoadJson(nlohmann::json& list);
	void LoadAll();
	void LoadText(std::string path, std::map<std::string, std::vector<SBundleData>, std::less<>>& data);
	void SaveText(std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>>& data);
	void SaveJson(std::string path, std::map<std::string, std::vector<CParticleManager::SBundleData>, std::less<>>& data);
	void BackUpFile(std::string path);

	void CheckCollision(std::vector<CParticle*> data);
	void CheckCollision(std::vector<CParticle*> data, CParticle* self);

	void SetParticleData(std::string& str, std::vector<SBundleData>& info);

	std::vector<SBundleData> GetParticleData(std::string str);
	std::map<std::string, std::vector<SBundleData>, std::less<>> GetData() { return m_data; }

	CGrid* GetGrid() { return m_pGrid; }

private:
	// JSONファイルのデータ読み込み関係
	void SafeLoad(nlohmann::json check, std::string str, int& value) { if (check[str].empty()) value = 0;	 else value = check[str]; }
	void SafeLoad(nlohmann::json check, std::string str, float& value) { if (check[str].empty()) value = 0.0f;  else value = check[str]; }
	void SafeLoad(nlohmann::json check, std::string str, bool& value) { if (check[str].empty()) value = false; else value = check[str]; }
	void SafeLoad(nlohmann::json check, std::string str, std::string& name) { if (check[str].empty()) name = "null"; else name = check[str]; }
	void SafeLoad(nlohmann::json check, std::string str, D3DXVECTOR3& value)
	{
		if (check[str].empty()) value = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		else value = D3DXVECTOR3(check[str]["X"], check[str]["Y"], check[str]["Z"]);
	}
	void SafeLoad(nlohmann::json check, std::string str, D3DXCOLOR& value)
	{
		if (check[str].empty()) value = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		else value = D3DXCOLOR(check[str]["R"], check[str]["G"], check[str]["B"], check[str]["A"]);
	}

	// ベクターをテキストファイルに保存
	void SaveVector3(std::ofstream& out, std::string name, D3DXVECTOR3& vec)
	{
		out << name << " : " << vec.x << " , " << vec.y << " , " << vec.z << std::endl;
	}

	// カラーをテキストファイルに保存
	void SaveColor(std::ofstream& out, std::string name, D3DXCOLOR& color)
	{
		out << name << " : " << color.r << " , " << color.g << " , " << color.b << " , " << color.a << std::endl;
	}

	// それぞれstring, Int, Float, Boolをテキストファイルに保存
	void SaveString(std::ofstream& out, std::string name, std::string& tag) { out << name << " : " << tag << std::endl; }
	void SaveInt(std::ofstream& out, std::string name, int value) { out << name << " : " << value << std::endl; }
	void SaveFloat(std::ofstream& out, std::string name, float value) { out << name << " : " << value << std::endl; }
	void SaveBool(std::ofstream& out, std::string name, bool value)
	{
		if(value) out << name << " : " << "true" << std::endl;
		else  out << name << " : " << "false" << std::endl;
	}
	
	// テキストファイルのデータ読み込み関係
	void ReadVector3(std::stringstream& ss, std::string name, D3DXVECTOR3& vec);
	void ReadColor(std::stringstream& ss, std::string name, D3DXCOLOR& color);
	bool ReadString(std::stringstream& ss, std::string name, std::string& tag);
	bool ReadInt(std::stringstream& ss, std::string name, int& value);
	void ReadFloat(std::stringstream& ss, std::string name, float& value);
	bool ReadBool(std::stringstream& ss, std::string name, bool& value);

	// ssの状態をクリアし、読み取り位置を先頭に戻す処理
	void ssInitialize(std::stringstream& ss) { ss.clear(), ss.seekg(0); }

	void LoadJsonBillboard(nlohmann::json& list, CParticleManager::SBundleData& data);
	void LoadJsonMeshData(nlohmann::json& list, CParticleManager::SBundleData& data);
	void SaveJsonBillboardData(nlohmann::json& list, CParticleManager::SBundleData& data);
	void SaveJsonMeshData(nlohmann::json& list, CParticleManager::SBundleData& data);

	void LoadInitializeData(CParticleManager::SBundleData& data);

	std::map<std::string, std::vector<SBundleData>, std::less<>> m_data;
	CGrid* m_pGrid;
};

#endif