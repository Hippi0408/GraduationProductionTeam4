//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//Renderer.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#ifndef _RENDERER_H_
#define _RENDERER_H_

class CRenderer
{
public:
	CRenderer();
	~CRenderer();

	HRESULT Init(HWND hWnd, bool bWindow);
	void Uninit();
	void Update();
	void Draw();

	LPDIRECT3DDEVICE9 GetDevice() { return m_pD3DDevice; }
	D3DPRESENT_PARAMETERS GetParameter() { return m_pD3dpp; }
	LPDIRECT3DTEXTURE9 GetRenderTexture() { return m_pDrawTexture; }
	IDirect3DSurface9* GetTargetSurface() { return m_pDrawSurface; }
	IDirect3DSurface9* GetOriginalSurface() { return m_pOriginalSurface; }

private:
	void DrawFPS();

	// Direct3Dオブジェクト
	LPDIRECT3D9 m_pD3D;

	// Deviceオブジェクト
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	LPD3DXFONT m_pFont;
	D3DPRESENT_PARAMETERS m_pD3dpp;

	IDirect3DSurface9* m_pDrawSurface;		// 描画サーフェス
	IDirect3DSurface9* m_pZBuffSurface;		// Zバッファサーフェス
	IDirect3DSurface9* m_pOriginalSurface;	// 元の描画サーフェス
	IDirect3DSurface9* m_pOriginalZBuffer;	// 元のZバッファサーフェス
	LPDIRECT3DTEXTURE9 m_pDrawTexture;		// 描画用テクスチャ
};

#endif