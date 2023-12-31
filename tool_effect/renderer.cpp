#include "application.h"
#include "renderer.h"
#include "object.h"
#include "camera.h"
#include "myimgui.h"
#include <tchar.h> // _T

CRenderer::CRenderer() :
	m_pD3D(nullptr),
	m_pD3DDevice(nullptr),
	m_pFont(nullptr)
{
}

CRenderer::~CRenderer()
{
}

//=============================================================================
// 初期化
//=============================================================================
HRESULT CRenderer::Init(HWND hWnd, bool bWindow)
{
	D3DDISPLAYMODE d3ddm;

	// Direct3Dオブジェクトの作成
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_pD3D == nullptr)
	{
		return E_FAIL;
	}

	// 現在のディスプレイモードを取得
	if (FAILED(m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return E_FAIL;
	}

	// デバイスのプレゼンテーションパラメータの設定
	ZeroMemory(&m_pD3dpp, sizeof(m_pD3dpp));						// ワークをゼロクリア
	m_pD3dpp.BackBufferCount = 1;									// バックバッファの数
	m_pD3dpp.BackBufferWidth = SCREEN_WIDTH;						// ゲーム画面サイズ(幅)
	m_pD3dpp.BackBufferHeight = SCREEN_HEIGHT;						// ゲーム画面サイズ(高さ)
	m_pD3dpp.BackBufferFormat = d3ddm.Format;						// カラーモードの指定
	m_pD3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;					// 映像信号に同期してフリップする
	m_pD3dpp.EnableAutoDepthStencil = TRUE;							// デプスバッファ（Ｚバッファ）とステンシルバッファを作成
	m_pD3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;					// デプスバッファとして16bitを使う
	m_pD3dpp.Windowed = bWindow;									// ウィンドウモード
	m_pD3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;	// リフレッシュレート
	m_pD3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;	// インターバル

	// ディスプレイアダプタを表すためのデバイスを作成
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&m_pD3dpp,
		&m_pD3DDevice)))
	{
		//Direct3Dデバイスの生成
		if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hWnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&m_pD3dpp,
			&m_pD3DDevice)))
		{
			return E_FAIL;
		}
	}

	// 描画と頂点処理をハードウェアで行なう
	if ((FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_pD3dpp, &m_pD3DDevice))) &&
		// 上記の設定が失敗したら
		// 描画をハードウェアで行い、頂点処理はCPUで行なう
		(FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_pD3dpp, &m_pD3DDevice))) &&
		// 上記の設定が失敗したら
		// 描画と頂点処理をCPUで行なう
		(FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_pD3dpp, &m_pD3DDevice))))
	{
		// 生成失敗
		return E_FAIL;
	}

	// レンダーステートの設定
	m_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	m_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	m_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// サンプラーステートの設定
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);	//テクスチャをリニア補完する
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);	//テクスチャをリニア補完する
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	m_pD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);

	// テクスチャステージステートの設定
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	m_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);

	// 描画用サーフェスを取り出すテクスチャ
	if (FAILED(D3DXCreateTexture(m_pD3DDevice,
		pow(SCREEN_WIDTH, 2),
		pow(SCREEN_HEIGHT, 2),
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&m_pDrawTexture)))
	{
		// 生成失敗
		return E_FAIL;
	}
	m_pDrawTexture->GetSurfaceLevel(0, &m_pDrawSurface);

	// Zバッファ、ステンシルバッファ用サーフェス
	m_pD3DDevice->CreateDepthStencilSurface(pow(SCREEN_WIDTH, 1),
		pow(SCREEN_HEIGHT, 1),
		D3DFMT_D24S8,
		D3DMULTISAMPLE_NONE,
		0,
		FALSE,
		&m_pZBuffSurface,
		NULL);

	// 元のサーフェスを保存
	m_pD3DDevice->GetRenderTarget(0, &m_pOriginalSurface);
	m_pD3DDevice->GetDepthStencilSurface(&m_pOriginalZBuffer);

#ifdef _DEBUG
	// デバッグ情報表示用フォントの生成
	D3DXCreateFont(m_pD3DDevice, 18, 0, 0, 0, FALSE, SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Terminal"), &m_pFont);
#endif

	return S_OK;
}

//=============================================================================
// 終了
//=============================================================================
void CRenderer::Uninit()
{
#ifdef _DEBUG
	// デバッグ情報表示用フォントの破棄
	if (m_pFont != nullptr)
	{
		m_pFont->Release();
		m_pFont = nullptr;
	}
#endif // _DEBUG

	// デバイスの破棄
	if (m_pD3DDevice != nullptr)
	{
		m_pD3DDevice->Release();
		m_pD3DDevice = nullptr;
	}

	// Direct3Dオブジェクトの破棄
	if (m_pD3D != nullptr)
	{
		m_pD3D->Release();
		m_pD3D = nullptr;
	}

	// 描画サーフェスの破棄
	if (m_pDrawSurface != nullptr)
	{
		m_pDrawSurface->Release();
		m_pDrawSurface = nullptr;
	}

	// Zバッファ、ステンシルバッファサーフェスの破棄
	if (m_pZBuffSurface != nullptr)
	{
		m_pZBuffSurface->Release();
		m_pZBuffSurface = nullptr;
	}

	// 描画用テクスチャの破棄
	if (m_pDrawTexture != nullptr)
	{
		m_pDrawTexture->Release();
		m_pDrawTexture = nullptr;
	}

	// 元のサーフェスを破棄
	if (m_pOriginalSurface != nullptr)
	{
		m_pOriginalSurface->Release();
		m_pOriginalSurface = nullptr;
	}

	if (m_pOriginalZBuffer != nullptr)
	{
		m_pOriginalZBuffer->Release();
		m_pOriginalZBuffer = nullptr;
	}
}

//=============================================================================
// 更新
//=============================================================================
void CRenderer::Update()
{
	CObject::UpdateAll();
}

//=============================================================================
// 描画
//=============================================================================
void CRenderer::Draw()
{
	m_pD3DDevice->SetRenderTarget(0, m_pDrawSurface);
	m_pD3DDevice->SetDepthStencilSurface(m_pZBuffSurface);

	// Direct3Dによる描画の開始
	if (SUCCEEDED(m_pD3DDevice->BeginScene()))
	{
		// バックバッファ＆Ｚバッファのクリア
		m_pD3DDevice->Clear(0,
			NULL,
			(D3DCLEAR_STENCIL | D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
			D3DCOLOR_RGBA(0, 0, 0, 0),
			1.0f,
			0);

		CObject::DrawAll();

		// Direct3Dによる描画の終了
		m_pD3DDevice->EndScene();
	}

	m_pD3DDevice->SetRenderTarget(0, m_pOriginalSurface);
	m_pD3DDevice->SetDepthStencilSurface(m_pOriginalZBuffer);

	// バックバッファ＆Ｚバッファのクリア
	m_pD3DDevice->Clear(0,
		NULL,
		(D3DCLEAR_STENCIL | D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		D3DCOLOR_RGBA(0, 0, 0, 0),
		1.0f,
		0);

	// Direct3Dによる描画の開始
	if (SUCCEEDED(m_pD3DDevice->BeginScene()))
	{
#ifdef _DEBUG
		// FPS表示
		DrawFPS();
#endif // _DEBUG

		CObject::DrawAll();

		CApplication::GetInstance()->GetMyImgui()->Draw();

		// Direct3Dによる描画の終了
		m_pD3DDevice->EndScene();
	} 

	// バックバッファとフロントバッファの入れ替え
	m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

#ifdef _DEBUG
//=============================================================================
// FPS表示
//=============================================================================
void CRenderer::DrawFPS()
{
	if (m_pFont == nullptr)
	{
		return;
	}

	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	TCHAR str[256];

	wsprintf(str, _T("FPS : %d\n"), GetFPS());

	// テキスト描画
	m_pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));
}
#endif // _DEBUG