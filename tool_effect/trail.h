#ifndef _ORBIT_H_
#define _ORBIT_H_

#include "object.h"

class CTrail : public CObject
{
public:
	struct SInfo
	{
		D3DXCOLOR beginCol;
		D3DXCOLOR endCol;
		std::string texPath;
		float trailWidth;
		bool useTexture;
	};

	CTrail();	//コンストラクタ
	~CTrail();	//デストラクタ

	static CTrail* Create(D3DXVECTOR3 offset, D3DXMATRIX mtx, std::string path = "");

	HRESULT Init() override { return S_OK; }
	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void BindTexture(std::string inPath);
	void Destroy() { m_isRelease = true; }

	void SetTrail(D3DXMATRIX mtx, SInfo set);
	void SetMtxParent(D3DXMATRIX pMtx) { m_pMtxParent = pMtx; };	//親のマトリックスの設定
	void SetPos(D3DXVECTOR3 offset) { m_offsetPos = offset; }	//オフセット座標の設定
	void SetColor(D3DXCOLOR col, D3DXCOLOR destcol);			//色の設定

	D3DXVECTOR3 GetPos() override { return m_offsetPos; }	//位置の取得
	bool GetDestroy() { return m_isRelease; }

private:
	static const int nMaxVtx = 1024;		//頂点の最大数

	LPDIRECT3DTEXTURE9 m_pTexture;			// テクスチャ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// 頂点バッファ
	D3DXVECTOR3 m_offsetPos;				// オフセット座標
	D3DXVECTOR3 m_worldPos;					// ワールド座標
	D3DXMATRIX	m_mtxWorld;					// ワールドマトリックス
	D3DXMATRIX m_pMtxParent;				// 軌跡の親モデルのマトリックス
	SInfo m_info;
	std::string m_path;
	int m_nNumVtx;							// 頂点数
	bool m_isRelease;
};

#endif