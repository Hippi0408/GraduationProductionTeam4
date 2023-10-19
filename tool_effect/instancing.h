//
// instancing.h
//
#ifndef _INSTANCING_H_
#define _INSTANCING_H_

#include "object.h"

class CParticle;

class CInstancing : public CObject
{
public:
	struct SVertex
	{
		D3DXVECTOR2 vtx;
		D3DXVECTOR2 uv;
	};

	struct SInstancingData
	{
		D3DXVECTOR3 worldPos;
		D3DXCOLOR col;
	};

	struct SInfo
	{
		D3DXVECTOR3 move;
	};

	CInstancing();
	~CInstancing();

	static CInstancing* Create(std::vector<CParticle*> data, std::string tex, int num);

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void Destroy() { m_isRelease = true; }
	void BindTexture(std::string inPath);

	void SetPos(D3DXVECTOR3 pos) { m_pos = pos; }
	void SetContainer(std::vector<SInstancingData> obj) { m_objContainer = obj; }
	void SetParticlePtr(std::vector<CParticle*> ptr) { m_particles = ptr; }

	D3DXVECTOR3 GetPos() { return m_pos; }
	bool GetDestroy() { return m_isRelease; }

private:
	struct SHandler
	{
		D3DXHANDLE technique;
		D3DXHANDLE wvp;
		D3DXHANDLE tex;
		D3DXHANDLE camPos;
	};

	std::vector<SInstancingData> m_objContainer;
	std::vector<CParticle*> m_particles;
	IDirect3DVertexDeclaration9* m_decl;
	LPDIRECT3DTEXTURE9 m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuff;
	LPDIRECT3DVERTEXBUFFER9 m_pInstancingBuff;
	D3DXVECTOR3 m_pos;
	SHandler m_handler;
	std::string m_shaderLabel;
	std::string m_texTag;
	int m_numInstance;
	bool m_isRelease;
};

#endif