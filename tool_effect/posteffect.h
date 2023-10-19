#ifndef _POSTEFFECT_H_
#define _POSTEFFECT_H_

class CPostEffect
{
public:
	CPostEffect();
	~CPostEffect();

	HRESULT Init();
	void Apply();

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
};

#endif
