#include "application.h"
#include "renderer.h"
#include "texture.h"
#include "keyboard.h"
#include "mouse.h"
#include "camera.h"
#include "light.h"
#include "object.h"
#include "object3d.h"
#include "objectx.h"
#include "file.h"
#include "model.h"
#include "myimgui.h"
#include "pointer.h"
#include "particle_manager.h"
#include "sound.h"
#include "window.h"
#include "shader_manager.h"
#include "object2d.h"

#include "utility.h"

CApplication* CApplication::m_pApplication = nullptr;

CObject *g_apObject = nullptr;
CObject3D *g_apObject3d = nullptr;

CApplication* CApplication::GetInstance()
{
	if (m_pApplication == nullptr)
	{
		m_pApplication = new CApplication;
	}

	return m_pApplication;
}

CApplication::CApplication() :
	m_pRenderer(nullptr)
{
	m_bWire = false;
}

CApplication::~CApplication()
{

}

HRESULT CApplication::Init(HWND hWnd, HINSTANCE hInstance)
{
	srand(0);

	m_hWnd = hWnd;

	// レンダリングクラスの生成
	m_pRenderer = new CRenderer;
	if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
	{	// 初期化処理が失敗した場合
		return -1;
	}

	// ウィンドウクラスの生成
	m_pWindow = new CWindow;
	if (FAILED(m_pWindow->Init(hInstance)))
	{
		return -1;
	}

	// キーボードクラスの生成
	m_pInputKeyboard = new CInputKeyboard;
	if (FAILED(m_pInputKeyboard->Init(hInstance, hWnd)))
	{	// 初期化処理が失敗した場合
		return -1;
	}

	// マウスクラスの生成
	m_pInputMouse = new CInputMouse;
	if (FAILED(m_pInputMouse->Init(hInstance, hWnd)))
	{	// 初期化処理が失敗した場合
		return -1;
	}
	m_pInputMouse->DrawCursor(true);

	// ファイルクラスの生成
	m_pFile = new CFile;

	// シェーダーマネージャの生成
	m_pShaderManager = new CShaderManager;
	m_pShaderManager->LoadAll();

	// テクスチャクラスの生成
	m_pTexture = new CTexture;
	m_pTexture->LoadAll();

	// モデルクラスの生成
	m_pModel = new CModel;
	m_pModel->LoadAll();

	// サウンドクラスの生成
	m_pSound = new CSound;
	m_pSound->LoadAll();
	if (FAILED(m_pSound->Init(hWnd)))
	{	// 初期化処理が失敗した場合
		return -1;
	}

	// ライトクラスの生成
	m_pLight = new CLight;
	m_pLight->Init();

	// カメラクラスの生成
	m_pCamera = new CCamera;
	m_pCamera->Init();

	// 物理クラスの生成
	m_pPhysics = new CPhysics;

	// パーティクルマネージャの生成
	m_pParticleManager = new CParticleManager;
	//m_pParticleManager->LoadAll();

	m_pPointer = new CPointer;
	m_pPointer = CPointer::Create(D3DXVECTOR3(0.0f, 10.0f, 0.0f));

	// Imgui
	m_pMyImgui = new CMyImgui;
	m_pMyImgui->Init();

	// 床
	CObjectX *pObjX;
	pObjX = CObjectX::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), "PLANE");
	pObjX->SetScale(D3DXVECTOR3(100.0f, 0.0f,100.0f));
	pObjX->SetCol(D3DXCOLOR(0.25f, 0.25f,0.25f,1.0f));

	return S_OK;
}

void CApplication::Uninit()
{
	CObject::ReleaseAll();

	// Imgui
	if (m_pMyImgui != nullptr)
	{
		m_pMyImgui->Uninit();
		delete m_pMyImgui;
		m_pMyImgui = nullptr;
	}

	// テクスチャクラスの破棄
	if (m_pTexture != nullptr)
	{
		m_pTexture->UnloadAll();
		delete m_pTexture;
		m_pTexture = nullptr;
	}

	// パーティクルマネージャの破棄
	if (m_pParticleManager != nullptr)
	{
		m_pParticleManager->ReleaseAll();
		delete m_pParticleManager;
		m_pParticleManager = nullptr;
	}

	// モデルクラスの破棄
	if (m_pModel != nullptr)
	{
		m_pModel->Clear();
		delete m_pModel;
		m_pModel = nullptr;
	}

	// サウンドクラスの破棄
	if (m_pSound != nullptr)
	{
		m_pSound->Uninit();
		delete m_pSound;
		m_pSound = nullptr;
	}

	// カメラクラスの破棄
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}

	// ライトクラスの破棄
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	// シェーダーマネージャの破棄
	if (m_pShaderManager != nullptr)
	{
		m_pShaderManager->ReleaseAll();
		delete m_pShaderManager;
		m_pShaderManager = nullptr;
	}

	// 物理クラスの破棄
	if (m_pPhysics != nullptr)
	{
		delete m_pPhysics;
		m_pPhysics = nullptr;
	}

	// キーボードクラスの破棄
	if (m_pInputKeyboard != nullptr)
	{
		m_pInputKeyboard->Uninit();
		delete m_pInputKeyboard;
		m_pInputKeyboard = nullptr;
	}

	// マウスクラスの破棄
	if (m_pInputMouse != nullptr)
	{
		m_pInputMouse->Uninit();
		delete m_pInputMouse;
		m_pInputMouse = nullptr;
	}

	// レンダリングクラスの破棄
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	// ファイルクラスの破棄
	if (m_pFile != nullptr)
	{
		delete m_pFile;
		m_pFile = nullptr;
	}

	// ウィンドウクラスの破棄
	if (m_pWindow != nullptr)
	{
		m_pWindow->Uninit();
		delete m_pWindow;
		m_pWindow = nullptr;
	}

	// アプリケーションの解放
	if (m_pApplication != nullptr)
	{
		delete m_pApplication;
		m_pApplication = nullptr;
	}
}

void CApplication::Update()
{
	// インプットの更新処理は最初に行う
	if (m_pInputKeyboard != nullptr)
	{
		m_pInputKeyboard->Update();
	}
	if (m_pInputMouse != nullptr)
	{
		m_pInputMouse->Update();
	}

	m_pRenderer->Update();
	m_pWindow->Update();
	m_pMyImgui->Update();
	m_pCamera->Update();

	// ワイヤーフレームにする処理
	if (m_pInputKeyboard->GetTrigger(DIK_F2))
	{
		m_bWire = !m_bWire;
		if (m_bWire) m_pRenderer->GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
		else if (!m_bWire) m_pRenderer->GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	}
}

void CApplication::Draw()
{
	m_pRenderer->Draw();
	m_pWindow->Draw();
	m_pCamera->SetCamera();
}
