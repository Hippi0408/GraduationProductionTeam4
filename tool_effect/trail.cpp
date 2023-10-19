//===================================================
//
// 軌跡の処理
// Author: Teruto Sato
// Author: Kota Tanaka
//
//===================================================

//-----------------------
// インクルード
//-----------------------

#include "trail.h"
#include "application.h"
#include "renderer.h"
#include "model.h"
#include "object3d.h"

//==========================
// コンストラクタ
//==========================
CTrail::CTrail() : CObject(CObject::PRIORITY_THIRD),
	m_offsetPos(0.0f, 0.0f, 0.0f),		// オフセット座標
	m_worldPos(0.0f, 0.0f, 0.0f),		// ワールド座標
	m_nNumVtx(0),						// 頂点数
	m_pVtxBuff(nullptr)					// 頂点バッファへのポインタ
{
	D3DXMatrixIdentity(&m_mtxWorld);	// ワールドマトリックス
	D3DXMatrixIdentity(&m_pMtxParent);	// 親のマトリックス
}

//==========================
// デストラクタ
//==========================
CTrail::~CTrail()
{
}

CTrail* CTrail::Create(D3DXVECTOR3 offset, D3DXMATRIX mtx, std::string path)
{
	CTrail* pOrbit = nullptr;

	//----------------------------------
	// ポリゴンの生成と初期化
	//----------------------------------
	pOrbit = new CTrail;	//生成

	if (pOrbit != nullptr)
	{//NULLチェック
	 //引数の代入
		pOrbit->m_pMtxParent = mtx;	//親のマトリックス
		pOrbit->m_path = path;
		pOrbit->Init(offset);
	}

	return pOrbit;
}

//==========================
// 初期化
//==========================
HRESULT CTrail::Init(D3DXVECTOR3 pos)
{
	BindTexture(m_path);

	//初期値の設定
	m_offsetPos = pos;			// 位置

	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得

	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * nMaxVtx,	//確保するバッファのサイズ
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,			//頂点フォーマット
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	VERTEX_3D *pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//----------------------------------
	// 頂点情報の設定
	//----------------------------------
	for (int i = 0; i < nMaxVtx; i++)
	{
		// 頂点座標の設定
		pVtx[i].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		// 法線の設定
		pVtx[i].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		// 頂点カラーの設定
		pVtx[i].col = m_info.beginCol;

		pVtx[i].tex = D3DXVECTOR2(0.0f,1.0f);
	}

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

//==========================
// 終了
//==========================
void CTrail::Uninit()
{
	//頂点バッファの破壊
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}
}

//==========================
// 更新
//==========================
void CTrail::Update()
{
	VERTEX_3D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//--------------------------------------
	// 頂点座標を後ろからコピーする
	//--------------------------------------
	for (int i = m_nNumVtx - 1; i > 0; i--)
	{//頂点数分降順に回す
		if (i - 2 >= 0)
		{
			pVtx[i].pos = pVtx[i - 2].pos;
			pVtx[i].col = pVtx[i - 2].col;
			pVtx[i].tex = pVtx[i - 2].tex;
		}
	}

	// 色の更新
	float rate = 1.0f / m_nNumVtx;
	for (int i = 0; i < m_nNumVtx; i++)
	{
		float progress = i * rate;
		float attenuation = 3.0f;
		D3DXCOLOR col = pVtx[i].col;

		col.a -= 0.005f;

		pVtx[i].col = D3DXCOLOR(m_info.beginCol.r + progress * (m_info.endCol.r - m_info.beginCol.r) * attenuation,
			m_info.beginCol.g + progress * (m_info.endCol.g - m_info.beginCol.g) * attenuation,
			m_info.beginCol.b + progress * (m_info.endCol.b - m_info.beginCol.b) * attenuation,
			col.a);
	}

	//--------------------------------------
	// 空いた0と1に軌跡の新しい座標を代入
	//--------------------------------------
	//親モデルの原点からオフセット分移動した座標を代入
	D3DXVec3TransformCoord(&m_worldPos, &m_offsetPos, &m_pMtxParent);
	pVtx[1].pos = m_worldPos;	//座標の設定
	pVtx[1].col = m_info.beginCol;	//色の設定
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);

	//親モデルの原点の座標を代入
	D3DXVec3TransformCoord(&m_worldPos, &D3DXVECTOR3(0.0f, m_info.trailWidth, 0.0f), &m_pMtxParent);
	pVtx[0].pos = m_worldPos;	//座標の設定
	pVtx[0].col = m_info.beginCol;
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);

	//色の設定
	{
		D3DXCOLOR newCol = m_info.beginCol;
		newCol.a = 0.1f;
		pVtx[0].col = newCol;
	}

	if (m_nNumVtx < nMaxVtx - 2)
	{//頂点の数が最大値を超えないなら
		m_nNumVtx += 2;	//頂点数を加算
	}

	// UV 座標の計算
	float step = 1.0f / (m_nNumVtx - 1);
	for (int i = 0; i < m_nNumVtx; i++)
	{
		pVtx[i].tex.x = i * step;
		pVtx[i].tex.y = (i % 2 == 0) ? 0.0f : 1.0f;
	}
	pVtx[m_nNumVtx - 1].tex.x = 1.0f;

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

//==========================
// 描画
//==========================
void CTrail::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得

	D3DXMATRIX mtxRot, mtxTrans;	//計算用マトリックス

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// レンダリングステートの設定
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	// Zテスト
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	// アルファテスト
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 215);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);

	// ライトを無効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//裏面から見えるようにする
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	// テクスチャの設定
	if (m_info.useTexture)
	{
		pDevice->SetTexture(0, m_pTexture);
	}

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,		// プリミティブの種類
		0,											// 描画する最初の頂点インデックス
		m_nNumVtx - 4);								// 描画するプリミティブ数

	//裏面から見えなくする
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	// アルファテストを無効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// Zバッファの設定を元に戻す
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// ライトを有効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	// 設定を元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// テクスチャの設定を戻す
	pDevice->SetTexture(0, NULL);
}

void CTrail::BindTexture(std::string inPath)
{
	m_pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//テクスチャのポインタ
}

void CTrail::SetColor(D3DXCOLOR col, D3DXCOLOR destcol)
{
	VERTEX_3D*pVtx;		//頂点情報へのポインタ

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	m_info.beginCol = col;
	m_info.endCol = destcol;

	//-------------------------------
	// 色の変更
	//-------------------------------
	pVtx[1].col = col;

	D3DXCOLOR newCol = col;
	newCol.a = 0.1f;

	pVtx[0].col = newCol;

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();
}

void CTrail::SetTrail(D3DXMATRIX mtx, SInfo set)
{
	// マトリクスの設定
	m_pMtxParent = mtx;

	m_info = set;
	SetColor(set.endCol, set.beginCol);
}