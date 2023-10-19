#include "shader_manager.h"
#include "application.h"
#include "renderer.h"
#include "file.h"
#include "utility.h"

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// シェーダーマネージャのコンストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CShaderManager::CShaderManager() : m_vtxDecl(nullptr)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	// 頂点宣言オブジェクト
	m_decl.push_back({ 0 , 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 });	// pos
	m_decl.push_back({ 0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 });		// nor
	m_decl.push_back({ 0, 24, D3DDECLTYPE_D3DCOLOR, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0 });	// col
	m_decl.push_back({ 0, 28, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 });	// tex
	m_decl.push_back(D3DDECL_END());

	// 頂点宣言オブジェクトの生成
	pDevice->CreateVertexDeclaration(m_decl.data(), &m_vtxDecl);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// シェーダーマネージャのデストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CShaderManager::~CShaderManager()
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// エフェクト、ハンドルの読み込み
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CShaderManager::Load(nlohmann::json& list)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPD3DXBUFFER errorBuffer = nullptr;
	std::string label = list["Label"];
	std::string path = list["Path"];

	// エフェクトファイルの読み込み
	LPD3DXEFFECT effect = nullptr;
	if (FAILED(D3DXCreateEffectFromFile(pDevice,
		_T(path.c_str()),
		nullptr,
		nullptr,
		0,
		nullptr,
		&effect,
		&errorBuffer)))
	{
		if (errorBuffer != nullptr)
		{
			const char* errorMessage = static_cast<const char*>(errorBuffer->GetBufferPointer());
			MessageBox(CApplication::GetInstance()->GetWindow(), errorMessage, "警告！", MB_ICONWARNING);
			errorBuffer->Release(); // リソースの解放
		}

		assert(false);
	}

	m_effect.insert(std::make_pair(label, effect));

	// テクニックのハンドルを保存
	size_t techniqueSize = list["Technique"].size();
	for (size_t i = 0; i < techniqueSize; i++)
	{
		std::string techName = "Technique" + std::to_string(i);
		AddTechniqueCache(label, list["Technique"][techName]);
	}

	// パラメータのハンドルを保存
	size_t parameterSize = list["Parameter"].size();
	for (size_t i = 0; i < parameterSize; i++)
	{
		std::string paramName = "Parameter" + std::to_string(i);
		AddParameterCache(label, list["Parameter"][paramName]);
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// Jsonからシェーダーを使用するための情報の読み取り
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CShaderManager::LoadAll()
{
	nlohmann::json list = CFile::LoadJsonStage(L"Data/FILE/shader.json");

	size_t size = list["SHADER"].size();
	for (size_t i = 0; i < size; i++)
	{
		Load(list["SHADER"].at(i));
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// シェーダーマネージャの破棄
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CShaderManager::ReleaseAll()
{
	for (auto &p : m_effect)
	{
		if (p.second != nullptr)
		{
			p.second->Release();
		}
	}
	m_effect.clear();

	// 頂点宣言オブジェクトの破棄
	if (!m_decl.empty())
	{
		m_decl.clear();
	}

	if (m_vtxDecl != nullptr)
	{
		m_vtxDecl->Release();
		m_vtxDecl = nullptr;
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// シェーダーの適用処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CShaderManager::Apply(std::string label)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPD3DXEFFECT pShader = m_effect[label];
	if (pShader != nullptr)
	{
		pShader->Begin(NULL, 0);
		pShader->BeginPass(0);
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// シェーダーの終了処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CShaderManager::End(std::string label)
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	LPD3DXEFFECT pShader = m_effect[label];
	if (pShader != nullptr)
	{
		pShader->EndPass();
		pShader->End();
	}

	// 固定機能パイプラインに戻す
	pDevice->SetVertexShader(NULL);
	pDevice->SetPixelShader(NULL);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テクニックのキャッシュに要素を追加
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CShaderManager::AddTechniqueCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	if (m_techniqueCache.count(key) > 0)
	{
		assert(false);
	}
	m_techniqueCache[key] = m_effect[label]->GetTechniqueByName(handleName.c_str());
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パラメータのキャッシュに要素を追加
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CShaderManager::AddParameterCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	if (m_parameterCache.count(key) > 0)
	{
		assert(false);
	}
	m_parameterCache[key] = m_effect[label]->GetParameterByName(NULL, handleName.c_str());
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// テクニックのキャッシュを取得
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
D3DXHANDLE CShaderManager::GetTechniqueCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	// キャッシュからハンドルを取得
	if (m_techniqueCache.count(key) < 0)
	{
		return nullptr;
	}
	return m_techniqueCache[key];
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パラメータのキャッシュを取得
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
D3DXHANDLE CShaderManager::GetParameterCache(const std::string& label, const std::string& handleName)
{
	std::string key = label + "_" + handleName;

	// キャッシュからハンドルを取得
	if (m_parameterCache.count(key) < 0)
	{
		return nullptr;
	}
	return m_parameterCache[key];
}