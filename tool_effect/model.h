//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//model.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#ifndef _MODEL_H_	//このマクロ定義がされてなかったら
#define _MODEL_H_	//２重インクルード防止のマクロ定義

#include "texture.h"

class CModel
{
public:
	struct SModelData
	{
		LPD3DXBUFFER buffMat;
		DWORD dwNum;
		LPD3DXMESH mesh;
		D3DXVECTOR3 maxModel;
		D3DXVECTOR3 minModel;
	};

	CModel();
	~CModel();

	void Load(std::string str, std::string path);
	void Load(std::vector<std::string> data);
	void LoadAll();
	void Load_XFile(std::vector<std::string> data);
	void Erase(std::string str) { m_model.erase(str); }
	void Clear() { m_model.clear(); }

	//ゲッター
	std::map<std::string, SModelData, std::less<>> GetModelData() { return m_model; }
	CModel GetParent() { return *m_pParent; }
	D3DXMATRIX GetMtxWorld() { return m_mtxWorld; }
	D3DXVECTOR3 GetMinModel(std::string model);
	D3DXVECTOR3 GetMaxModel(std::string model);
	LPD3DXBUFFER GetBuffMat(std::string model);
	LPD3DXMESH GetMesh(std::string model);
	DWORD GetModelNum(std::string model);
	SModelData GetModelStructure(std::string model);

private:
	// モデルの情報
	std::map<std::string, SModelData, std::less<>> m_model;

	CModel *m_pParent;

	D3DXVECTOR3 m_scale;
	D3DXVECTOR3 m_modelSize;
	D3DXMATRIX m_mtxWorld;
};

#endif
