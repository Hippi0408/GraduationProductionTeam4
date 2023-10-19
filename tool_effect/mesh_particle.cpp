#include "application.h"
#include "renderer.h"
#include "mesh_particle.h"
#include "trail.h"
#include "utility.h"
#include "model.h"
#include "object3d.h"
#include "shader_manager.h"
#include "camera.h"

namespace
{
	struct WVP
	{
		D3DXMATRIX mtxWorld;
		D3DXMATRIX mtxView;
		D3DXMATRIX mtxProjection;
	};
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルのコンストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CMeshParticle::CMeshParticle(int nPriority) :
	CObject(CObject::PRIORITY_THIRD),
	m_info({}),
	m_nTime(0)			// 時間
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルのデストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CMeshParticle::~CMeshParticle()
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの生成
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CMeshParticle * CMeshParticle::Create(SInfo& info, int nPriority)
{
	CMeshParticle *pParticle = new CMeshParticle(nPriority);

	if (pParticle != nullptr)
	{
		pParticle->SetInfo(info);
		pParticle->Init();
	}
	else
	{
		assert(false);
	}

	return pParticle;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの初期化
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
HRESULT CMeshParticle::Init()
{
	// テクスチャの読み込み
	if (m_info.useTexture)
	{
		BindTexture(m_info.texTag);
		BindMaskTexture(m_info.maskTexTag);
	}

	// モデルの読み込み
	LoadModel(m_info.modelTag);

	m_DestroyTime = m_info.popTime;

	if (m_info.color.randomColor)
	{
		m_info.color.col = D3DXCOLOR(utility::Random(m_info.color.randomMax, m_info.color.randomMin),
			utility::Random(m_info.color.randomMax, m_info.color.randomMin),
			utility::Random(m_info.color.randomMax, m_info.color.randomMin),
			m_info.color.col.a);
	}

	if (m_info.useTrail)
	{
		m_pTrail = std::move(m_pTrail->Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_mtxWorld));
	}

	if (m_info.randomWeight)
	{
		m_info.weight = utility::Random(m_info.randomWeightMax, m_info.randomWeightMin);
	}

	if (!m_info.useShader)
	{
		return S_OK;
	}

	m_uv = D3DXVECTOR2(0.0f, 1.0f);

	m_shaderLabel = "UVAnimation";
	CShaderManager* pShader = CApplication::GetInstance()->GetShaderManager();
	if (!m_shaderLabel.empty())
	{
		m_handler.technique = pShader->GetTechniqueCache(m_shaderLabel, "TechShader");
		m_handler.wvp = pShader->GetParameterCache(m_shaderLabel, "g_wvp");
		m_handler.animationUV = pShader->GetParameterCache(m_shaderLabel, "g_animationUV");
		m_handler.maskTexture = pShader->GetParameterCache(m_shaderLabel, "g_maskTexture");
		m_handler.haveMaskTexture = pShader->GetParameterCache(m_shaderLabel, "g_hasMaskTexture");
		m_handler.diffuse = pShader->GetParameterCache(m_shaderLabel, "g_diffuse");
	}

	return S_OK;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの破棄
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMeshParticle::Uninit()
{
	if (m_pTrail != nullptr)
	{
		m_pTrail->Destroy();
	}

	if (m_modelData.empty())
	{
		m_modelData.clear();
	}

	Destroy();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの更新
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMeshParticle::Update()
{
	m_delayStartTime++;
	if (m_info.beginDelay >= m_delayStartTime)
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Pause();
		}
		return;
	}
	else
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Resume();
		}
	}

	D3DXVECTOR3 velocity = m_info.move;
	m_info.pos += m_info.move;

	// モデルの大きさ
	m_info.scale += m_info.scalingValue;

	// モデルの回転量
	m_info.rot.y += m_info.rotationVolume;

	if (m_info.rotate.useRotate)
	{
		velocity = D3DXVECTOR3(m_info.move.x + (m_info.rotate.angle * m_info.rotate.radius) * sinf(D3DXToRadian(m_info.rotate.angle)),
			velocity.y,
			m_info.move.z + (m_info.rotate.angle * m_info.rotate.radius) * cosf(D3DXToRadian(m_info.rotate.angle)));

		m_info.move = velocity;

		m_info.rotate.angle += utility::Random(m_info.rotate.randomMax, m_info.rotate.randomMin);
	}

	// 落下
	if (m_nTime >= m_info.fallDelayTime)
	{
		m_info.move.y -= m_info.weight;
	}

	// 色関係
	if (m_info.color.destCol.r >= 0.0f && m_info.color.destCol.g >= 0.0f && m_info.color.destCol.b >= 0.0f)
	{
		m_info.color.col.r += (m_info.color.destCol.r - m_info.color.col.r) / (m_info.popTime * m_info.color.colAttenuation);
		m_info.color.col.g += (m_info.color.destCol.g - m_info.color.col.g) / (m_info.popTime * m_info.color.colAttenuation);
		m_info.color.col.b += (m_info.color.destCol.b - m_info.color.col.b) / (m_info.popTime * m_info.color.colAttenuation);
	}
	if (m_info.color.destCol.a >= 0.0f)
	{
		m_info.color.col.a += (m_info.color.destCol.a - m_info.color.col.a) / (m_info.popTime * m_info.color.colAttenuation);
	}

	m_nTime++;

	if (m_pTrail != nullptr)
	{
		m_pTrail->SetColor(m_info.color.destCol, m_info.color.col);
		m_pTrail->SetMtxParent(m_mtxWorld);
	}

	m_DestroyTime--;

	// 向きの正規化
	utility::AngleNormalize(m_info.rot.y);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの描画
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMeshParticle::Draw()
{
	if (m_info.beginDelay >= m_delayStartTime)
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Invisible();
		}
		return;
	}
	else
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Visible();
		}
	}

	if (m_info.useShader)
	{
		AnimationDraw();
		return;
	}

	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	D3DXMATRIX mtxTrans, mtxScale, mtxRot;		// 計算用マトリックス
	D3DMATERIAL9 matDef;						// 現在のマテリアルを保存
	D3DXMATERIAL *pMat;							// マテリアルデータへのポインタ

	// テクスチャの設定を戻す
	pDevice->SetTexture(0, NULL);

	// ワールドマトリックスを初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_info.rot.y, m_info.rot.x, m_info.rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 行列拡縮関数
	D3DXMatrixScaling(&mtxScale, m_info.scale.x, m_info.scale.y, m_info.scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_info.pos.x, m_info.pos.y, m_info.pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// Zテスト
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// アルファテスト
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 210);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// 現在のマテリアルを保存
	pDevice->GetMaterial(&matDef);

	for (auto &p : m_modelData)
	{
		// マテリアルデータへのポインタを取得
		pMat = (D3DXMATERIAL*)p.buffMat->GetBufferPointer();
		pMat->MatD3D.Diffuse = m_info.color.col;
		pMat->MatD3D.Emissive = m_info.color.col * m_info.color.emissive;

		for (int j = 0; j < (int)p.dwNum; j++)
		{
			// マテリアルの設定
			pDevice->SetMaterial(&pMat->MatD3D);

			// テクスチャの設定
			pDevice->SetTexture(0, m_pTexture);

			// モデルパーツの描画
			p.mesh->DrawSubset(j);
		}

		// エミッシブは同モデルの他オブジェクトにも影響しているため、元に戻す
		pMat->MatD3D.Emissive = D3DXCOLOR(0.0f,0.0f,0.0f,1.0f);
	}

	// 保持していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

	// Zバッファの設定を元に戻す
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// アルファテストを無効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// テクスチャの設定を戻す
	pDevice->SetTexture(0, NULL);
}

void CMeshParticle::AnimationDraw()
{
	LPD3DXEFFECT pEffect = CApplication::GetInstance()->GetShaderManager()->GetEffect(m_shaderLabel);
	CShaderManager *pShaderManager = CApplication::GetInstance()->GetShaderManager();
	CCamera *pCamera = CApplication::GetInstance()->GetCamera();
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	D3DXMATRIX mtxTrans, mtxScale, mtxRot;			// 計算用マトリックス
	D3DMATERIAL9 matDef;							// 現在のマテリアルを保存
	D3DXMATERIAL *pMat;								// マテリアルデータへのポインタ

	// テクスチャの設定を戻す
	pDevice->SetTexture(0, nullptr);
	pDevice->SetTexture(1, nullptr);

	// ワールドマトリックスを初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	// 向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_info.rot.y, m_info.rot.x, m_info.rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_info.pos.x, m_info.pos.y, m_info.pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// 行列拡縮関数
	D3DXMatrixScaling(&mtxScale, m_info.scale.x, m_info.scale.y, m_info.scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	// アルファテスト
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	// 加算合成
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	// 現在のマテリアルを保存
	pDevice->GetMaterial(&matDef);

	// 頂点宣言オブジェクトの設定
	pDevice->SetVertexDeclaration(pShaderManager->GetVertexDeclaration());

	// テクスチャのUVアニメーション設定
	m_uv += m_info.moveUV;
	pEffect->SetFloatArray(m_handler.animationUV, m_uv, sizeof(D3DXVECTOR2));

	// マトリックスの設定
	WVP worldViewProjection = {};
	worldViewProjection.mtxWorld = m_mtxWorld;
	worldViewProjection.mtxView = pCamera->GetCamera()->mtxView;
	worldViewProjection.mtxProjection = pCamera->GetCamera()->mtxProjection;
	pEffect->SetValue(m_handler.wvp, &worldViewProjection, sizeof(WVP));

	// テクスチャの設定
	bool hasMain = (m_pTexture != nullptr);
	pEffect->SetBool(m_handler.haveMainTexture, hasMain);
	pDevice->SetTexture(0, m_pTexture);

	// マスク用テクスチャの設定
	bool hasMask = (m_pMaskTexture != nullptr);
	pEffect->SetBool(m_handler.haveMaskTexture, hasMask);
	pDevice->SetTexture(1, m_pMaskTexture);

	// 色の設定
	pEffect->SetFloatArray(m_handler.diffuse, m_info.color.col, sizeof(D3DXCOLOR));

	// テクニックの設定
	pEffect->SetTechnique(m_handler.technique);

	// シェーダーの適用
	pShaderManager->Apply(m_shaderLabel);

	for (auto& p : m_modelData)
	{
		// マテリアルデータへのポインタを取得
		pMat = (D3DXMATERIAL*)p.buffMat->GetBufferPointer();
		pMat->MatD3D.Diffuse = m_info.color.col;
		pMat->MatD3D.Emissive = m_info.color.col * m_info.color.emissive;

		for (int j = 0; j < (int)p.dwNum; j++)
		{
			// マテリアルの設定
			pDevice->SetMaterial(&pMat->MatD3D);

			// モデルパーツの描画
			p.mesh->DrawSubset(j);
		}

		// エミッシブは同モデルの他オブジェクトにも影響しているため、元に戻す
		pMat->MatD3D.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	}

	// シェーダーの終了
	pShaderManager->End(m_shaderLabel);

	// 保持していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

	// アルファテストを無効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// 設定を元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// テクスチャの設定を戻す
	pDevice->SetTexture(0, nullptr);
	pDevice->SetTexture(1, nullptr);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルのテクスチャをバインド
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMeshParticle::BindTexture(const std::string& inPath)
{
	m_pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//テクスチャのポインタ
}

void CMeshParticle::BindMaskTexture(const std::string& inPath)
{
	m_pMaskTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//テクスチャのポインタ
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// メッシュのモデルデータを取得
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CMeshParticle::LoadModel(const std::string& path)
{
	// モデルデータのポインタを取得
	CModel *pModel = CApplication::GetInstance()->GetModel();

	CModel::SModelData data = {};
	data = std::move(pModel->GetModelStructure(path));

	m_modelData.push_back(data);
}
