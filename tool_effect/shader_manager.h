//
//ShaderManager.h
//
#ifndef _SHADER_MANAGER_H_
#define _SHADER_MANAGER_H_

#include "file.h"

class CShaderManager
{
public:
	CShaderManager();
	~CShaderManager();

	void Load(nlohmann::json& list);
	void LoadAll();
	void ReleaseAll();
	void Apply(std::string label);
	void End(std::string label);
	void AddTechniqueCache(const std::string& label, const std::string& handleName);
	void AddParameterCache(const std::string& label, const std::string& handleName);

	std::unordered_map<std::string, LPD3DXEFFECT> GetEffectData() { return m_effect; }
	std::vector<D3DVERTEXELEMENT9> GetDeclaration() { return m_decl; }
	LPD3DXEFFECT GetEffect(std::string label) { return m_effect[label]; }
	D3DXHANDLE GetTechniqueCache(const std::string& label, const std::string& handleName);
	D3DXHANDLE GetParameterCache(const std::string& label, const std::string& handleName);
	IDirect3DVertexDeclaration9* GetVertexDeclaration() { return m_vtxDecl; }

private:
	std::unordered_map<std::string, LPD3DXEFFECT> m_effect;
	std::vector<D3DVERTEXELEMENT9> m_decl;
	IDirect3DVertexDeclaration9* m_vtxDecl;

	std::unordered_map<std::string, D3DXHANDLE> m_techniqueCache;
	std::unordered_map<std::string, D3DXHANDLE> m_parameterCache;

};

#endif
