#include <stdlib.h>
#include "application.h"
#include "input.h"
#include "keyboard.h"
#include "camera.h"
#include "utility.h"
#include "pointer.h"
#include "model.h"
#include "texture.h"

#include "particle_manager.h"
#include "particle_emitter.h"
#include "myimgui.h"
#include "particle.h"

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターのコンストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CPointer::CPointer() : m_fSpeed(1.0f)
{
	SetObjType(OBJTYPE_PLAYER);
	SetObjState(CObject::OBJSTATE_3D);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_bVisible = true;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターのデストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CPointer::~CPointer()
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターの生成
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CPointer * CPointer::Create(D3DXVECTOR3 pos)
{
	CPointer *pObj = nullptr;
	pObj = new CPointer;

	//ヌルチェック
	if (pObj != nullptr)
	{
		// ポリゴンの初期化処理
		pObj->SetPos(pos);
		pObj->Init();
	}

	return pObj;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターの初期化
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
HRESULT CPointer::Init()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	LoadModel("SPHERE");

	m_scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	return S_OK;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターの終了
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPointer::Uninit()
{
	Destroy();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターの更新
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPointer::Update()
{
	m_posOld = m_objpos;
	m_objpos += m_move;

	//----------------------------------------------------------
	// プレイヤー行動処理
	Movement();

	static int time = 0;

	std::string tag = CApplication::GetInstance()->GetMyImgui()->GetNowTag();
	int popTime = CApplication::GetInstance()->GetMyImgui()->GetEmissionInterval();

	time++;
	// パーティクル
	if ((time % popTime) == 0)
	{
		m_pParticleEmitter = CParticleEmitter::Create(tag);
		m_pParticleEmitter->SetPos(m_objpos);
	}

	//----------------------------------------------------------
	// 正規化
	//----------------------------------------------------------
	// 目的の向きの正規化
	if (m_rotDest.x - m_rot.x > D3DX_PI)
	{
		m_rotDest.x -= D3DX_PI * 2;
	}

	else if (m_rotDest.x - m_rot.x < -D3DX_PI)
	{
		m_rotDest.x += D3DX_PI * 2;
	}

	if (m_rotDest.y - m_rot.y > D3DX_PI)
	{
		m_rotDest.y -= D3DX_PI * 2;
	}

	else if (m_rotDest.y - m_rot.y < -D3DX_PI)
	{
		m_rotDest.y += D3DX_PI * 2;
	}

	//モデルの回転の慣性
	m_rot.x += (m_rotDest.x - m_rot.x) * 0.1f;
	m_rot.y += (m_rotDest.y - m_rot.y) * 0.1f;

	// 向きの正規化
	utility::AngleNormalize(m_rot.y);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターの描画
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPointer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//デバイスの取得
	D3DXMATRIX mtxTrans, mtxScale;		// 計算用マトリックス
	D3DMATERIAL9 matDef;						// 現在のマテリアルを保存
	D3DXMATERIAL *pMat;							// マテリアルデータへのポインタ

	//テクスチャの設定を戻す
	pDevice->SetTexture(0, NULL);

	//ワールドマトリックスを初期化
	D3DXMatrixIdentity(&m_mtxWorld);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_objpos.x, m_objpos.y, m_objpos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// 行列拡縮関数
	D3DXMatrixScaling(&mtxScale, m_scale.x, m_scale.y, m_scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	//Zテスト
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	for (auto &p : m_modelData)
	{
		if (!m_bVisible)
		{	// 透明化
			break;
		}

		//現在のマテリアルを保存
		pDevice->GetMaterial(&matDef);

		//マテリアルデータへのポインタを取得
		pMat = (D3DXMATERIAL*)p.buffMat->GetBufferPointer();
		pMat->MatD3D.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		for (int j = 0; j < (int)p.dwNum; j++)
		{
			//マテリアルの設定
			pDevice->SetMaterial(&pMat->MatD3D);

			//モデルパーツの描画
			p.mesh->DrawSubset(j);
		}
	}

	//保持していたマテリアルを戻す
	pDevice->SetMaterial(&matDef);

	//テクスチャの設定を戻す
	pDevice->SetTexture(0, NULL);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターの入力情報による行動
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPointer::Movement()
{
	CCamera *pCamera = CApplication::GetInstance()->GetCamera();
	CCamera::CAMERA *camera = pCamera->GetCamera();

	D3DXVECTOR3 vec(0.0f, 0.0f, 0.0f);

	// 奥
	if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_W))
	{
		vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed));
		m_rotDest.y = camera->rot.y + D3DX_PI * 0.0f;				//目的の角度

																	// 右奥
		if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_D))
			vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y + D3DX_PI * 0.25f;

		// 左奥
		else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_A))
			vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y - D3DX_PI * 0.25f;
	}

	// 後
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_S))
	{
		vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.0f) * m_fSpeed));
		m_rotDest.y = camera->rot.y - D3DX_PI * 1.0f;

		// 右後
		if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_D))
			vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.75f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y + D3DX_PI * 0.75f;

		// 左後
		else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_A))
			vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.25f) * m_fSpeed)),
			m_rotDest.y = camera->rot.y - D3DX_PI * 0.75f;
	}

	// 右
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_D))
	{
		vec = D3DXVECTOR3(-(sinf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed), 0.0f, -(cosf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed));
		m_rotDest.y = camera->rot.y + D3DX_PI * 0.5f;
	}

	// 左
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_A))
	{
		vec = D3DXVECTOR3((sinf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed), 0.0f, (cosf(camera->rot.y + D3DX_PI * 0.5f) * m_fSpeed));
		m_rotDest.y = camera->rot.y - D3DX_PI * 0.5f;
	}

	// 上
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_R))
	{
		m_objpos.y += 1.5f;
	}

	// 下
	else if (CApplication::GetInstance()->GetInputKeyboard()->GetPress(DIK_F))
	{
		m_objpos.y -= 1.5f;
	}

	m_objpos.x += vec.x;
	m_objpos.z += vec.z;
	m_vec = vec;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターのモデルデータを取得
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPointer::LoadModel(std::string path)
{
	// モデルデータのポインタを取得
	CModel *pModel = CApplication::GetInstance()->GetModel();

	SModelData data = {};

	data.mesh = pModel->GetMesh(path);
	data.buffMat = pModel->GetBuffMat(path);
	data.dwNum = pModel->GetModelNum(path);
	data.maxModel = pModel->GetMaxModel(path);
	data.minModel = pModel->GetMinModel(path);

	m_modelData.push_back(data);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// ポインターのテクスチャをバインド
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CPointer::BindTexture(std::string inPath)
{
	m_pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//テクスチャのポインタ
}