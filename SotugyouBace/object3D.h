//==============================================================================================
//
// 3Dポリゴン　　　Object3D.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _OBJECT3D_H_
#define	_OBJECT3D_H_

#include <d3dx9.h>
#include"object.h"
#include"texture.h"
#include"move_object.h"

class CObject3D : public CMove_Object
{
public:
	// 3D頂点フォーマット
	const DWORD FVF_VERTEX_3D = (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1);

	struct VERTEX_3D
	{
		D3DXVECTOR3 pos;		//頂点座標
		D3DXVECTOR3 nor;		//法線ベクトル
		D3DCOLOR col;			//頂点カラー
		D3DXVECTOR2 tex;		//テクスチャ座標
		bool broken;			//メッシュを削る
	};

	CObject3D(const CObject::PRIORITY priority = CObject::PRIORITY_CENTER);
	~CObject3D() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw()  override;

	void UV();
	virtual void Hit() override {};

	static CObject3D* Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, const CObject::PRIORITY priority = CObject::PRIORITY_CENTER, const D3DXCOLOR col = {1.0f,1.0f, 1.0f, 1.0f}, const bool billboard = false);

	void SetTexPos(const float top, const float row, const float right, const float left);			// テクスチャの分割

	void SetMove(const D3DXVECTOR3 move) { m_move = move; }
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetSize(const D3DXVECTOR2 size) { m_size = size; }
	void SetCol(const D3DXCOLOR col) { m_col = col; }
	void SetAlpha(const float alpha) { m_col.a = alpha; }
	void AddAlpha(const float alpha) { m_col.a += alpha; }
	void Setbillboard(const bool billboard) { m_bBillboard = billboard; }
	void SetTexture(CTexture::TEXTURE texture) { m_texture = texture; }

	const D3DXVECTOR3 GetMove() { return m_move; }
	const D3DXVECTOR2 GetScale() { return m_size; }
	const D3DXCOLOR GetCol() { return m_col; }
	const D3DXMATRIX GetMtxWorld() { return m_mtxWorld; }

private:

	// 頂点フォーマット
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// 頂点バッファ
	D3DXMATRIX m_mtxWorld;					// ワールドマトリックス
	D3DXVECTOR2 m_size;						// サイズ
	D3DXVECTOR3 m_move;						// 移動量
	D3DXVECTOR3 m_rot;						// 角度
	D3DXCOLOR m_col;						// 色
	CTexture::TEXTURE m_texture;			// テクスチャ
	bool m_bBillboard;						// ビルボードか
};

#endif // !_OBJECT3D_H_