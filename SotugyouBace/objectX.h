//==============================================================================================
//
// オブジェクトX　　　objectX.h
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#ifndef _OBJECTX_H_
#define	_OBJECTX_H_

#include"object.h"
#include "model.h"
#include <vector>

class CObjectX : public CObject
{
public:
	CObjectX(const PRIORITY priority);
	virtual ~CObjectX() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void DrawShadow(const LPDIRECT3DDEVICE9 device, CModel::ModelPattern model);
	void Stencil();

	static CObjectX* Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, CObjectX* parent, const char* Xfilename, const PRIORITY priority = PRIORITY_BACK);

	void SetShadow(const bool shadow) { m_bShadow = shadow; }
	void SetIndex(const int index) { m_nIndex = index; }
	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetSize(const D3DXVECTOR3 size) { m_size = size; }
	void SetParent(CObjectX* pModel) { m_pParent = pModel; }
	void SetModel(const char* Xfilename);

	// マテリアルの色情報を初期マテリアル色に戻す処理
	void SetColor(const D3DXCOLOR col) { for (int nCntMat = 0; nCntMat < m_nNumMat; nCntMat++) { m_col[nCntMat] = col; } }
	void AddColor(const D3DXCOLOR col) { for (int nCntMat = 0; nCntMat < m_nNumMat; nCntMat++) { m_col[nCntMat] += col; } }
	void SetAlpha(const float alpha) { for (int nCntMat = 0; nCntMat < m_nNumMat; nCntMat++) { m_col[nCntMat].a = alpha; } }
	void AddAlpha(const float alpha) { for (int nCntMat = 0; nCntMat < m_nNumMat; nCntMat++) { m_col[nCntMat].a += alpha; } }

	const D3DXVECTOR3 GetPos() { return m_pos; }
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXMATRIX GetMatrix() { return m_mtxWorld; }
	const CObjectX* GetParent() { return m_pParent; }
	const D3DXVECTOR3 GetMaxSize() { return m_vtxMaxModel; }
	const D3DXVECTOR3 GetMinSize() { return m_vtxMinModel; }

private:

	D3DXVECTOR3 m_pos;			// 位置
	D3DXVECTOR3 m_rot;			// 現在の角度
	D3DXVECTOR3 m_size;			// サイズ
	D3DXVECTOR3 m_vtxMinModel;	// 頂点の最小値
	D3DXVECTOR3 m_vtxMaxModel;	// 頂点の最大値
	D3DXMATRIX m_mtxWorld;		// ワールドマトリックス
	std::vector <D3DXCOLOR> m_col;		// モデルの色
	CObjectX* m_pParent;			// 親モデルへのポインタ
	int m_nIndex;				// Xファイルの番号
	int m_nNumMat;				// 現在のモデルのマテリアル数
	bool m_bShadow;				// 影の描画処理
};

#endif // !_MODEL_H_
