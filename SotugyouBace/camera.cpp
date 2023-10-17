//==============================================
//
// カメラの処理[camera.cpp]
// Author：tutida ryousei
// Author：tanimoto kosuke
// Author：saito shian
//
//==============================================
#include "camera.h"
#include "input.h"
#include "application.h"
#include "player_manager.h"
#include "application.h"
#include "mode.h"
#include "fade.h"

//==============================================
//コンストラクタ
//==============================================
CCamera::CCamera()
{

}

//==============================================
//デストラクタ
//==============================================
CCamera::~CCamera()
{

}

//==============================================
//カメラの初期化処理
//==============================================
void CCamera::Init(void)
{
	//視点・注視点・上方向を設定する
	m_posV = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// 視点(オフセット)
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// 注視点(オフセット)
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			// 角度
	m_fRotSpeed = 0.03f;							// 回転速度
	m_CPos = { 0.0f,0.0f,0.0f };
	m_posVDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_posRDest = D3DXVECTOR3(600.0f, 150.0f, 0.0f);
}

//==============================================
//カメラの終了処理
//==============================================
void CCamera::Uninit(void)
{

}

//==============================================
//カメラの更新処理
//==============================================
void CCamera::Update(void)
{
	if (CApplication::GetPlayerManager()->GetPlayer(0) != nullptr)
	{
		// 視点移動
		Perspective();
	}

#ifdef _DEBUG
	// カメラの移動
	Move();
#endif
}

//==============================================
// カメラのセット処理
//==============================================
void CCamera::SetCamera(void)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	// ビューマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxView);

	// ビューマトリックスの生成
	D3DXMatrixLookAtLH(&m_mtxView,
		&m_worldCameraPosV,
		&m_worldCameraPosR,
		&m_vecU);

	// ビューマトリックスの設定
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);

	// プロジェクションマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxProjection);

	// プロジェクションマトリックスの生成
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,
		D3DXToRadian(45.0f),
		(float)1280.0f / (float)720.0f,
		10.0f,
		10000.0f);

	// プロジェクションマトリックスの設定
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);
}

//==============================================
// 行列を使ったカメラ制御
//==============================================
void CCamera::Matrix(D3DXVECTOR3 rot,D3DXVECTOR3 pos)
{
	// デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
	D3DXMATRIX mtxRot, mtxTrans;		//計算用のマトリックス

	// ワールドマトリックス
	D3DXMatrixIdentity(&m_mtxWorld);

	// 行列を回転に反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, rot.y, rot.x, rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// 行列に移動を反映(プレイヤーの位置)
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	D3DXVec3TransformCoord(&m_worldCameraPosV, &m_posV, &m_mtxWorld);
	D3DXVec3TransformCoord(&m_worldCameraPosR, &m_posR, &m_mtxWorld);
}

#ifdef _DEBUG
//==============================================
// カメラの移動
//==============================================
void CCamera::Move()
{
	// 入力デバイスの情報
	CInput* pInput = CInput::GetKey();

	// カメラの移動
	if (pInput->Press(DIK_RIGHT))
	{
		//m_rot.y += m_fRotSpeed;
		m_posV.x += 10.0f;
		m_posR.x += 10.0f;
	}
	if (pInput->Press(DIK_LEFT))
	{
		//m_rot.y -= m_fRotSpeed;
		m_posV.x -= 10.0f;
		m_posR.x -= 10.0f;
	}
	if (pInput->Press(DIK_UP))
	{
		//m_rot.x -= m_fRotSpeed;
		m_posV.z += 10.0f;
		m_posR.z += 10.0f;
	}
	if (pInput->Press(DIK_DOWN))
	{
		//m_rot.x += m_fRotSpeed;
		m_posV.z -= 10.0f;
		m_posR.z -= 10.0f;
	}

	if (pInput->Press(DIK_RSHIFT))
	{
		//m_rot.x -= m_fRotSpeed;
		m_posV.y += 10.0f;
		m_posR.y += 10.0f;
	}
	if (pInput->Press(DIK_RCONTROL))
	{
		//m_rot.x += m_fRotSpeed;
		m_posV.y -= 10.0f;
		m_posR.y -= 10.0f;
	}
	if (pInput->Press(DIK_Q))
	{
		m_rot.y -= m_fRotSpeed;
	}
	if (pInput->Press(DIK_E))
	{
		m_rot.y += m_fRotSpeed;
	}

	// 角度の正規化
	if (m_rot.y > D3DX_PI)
	{
		m_rot.y -= D3DX_PI * 2;
	}
	else if (m_rot.y < -D3DX_PI)
	{
		m_rot.y += D3DX_PI * 2;
	}
}

//==============================================
// カメラの視点
//==============================================
void CCamera::Perspective()
{
	if (CApplication::GetPlayerManager()->GetPlayer(0) != nullptr)
	{	// プレイヤーが使われていたら実行

		//取得処理
		D3DXVECTOR3 PlayerPos = CApplication::GetPlayerManager()->GetPlayer(0)->GetPos();

		// 行列を使ったカメラ制御
		Matrix(m_rot, PlayerPos);
	}
}

//============================================
// 距離の設定
//============================================
void CCamera::SetOffset(D3DXVECTOR3 posV, D3DXVECTOR3 posR)
{
	m_OffsetV = posV;
	m_OffsetR = posR;
}
#endif