//����������������������������������������
//Renderer.h
//����������������������������������������
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

	// Direct3D�I�u�W�F�N�g
	LPDIRECT3D9 m_pD3D;

	// Device�I�u�W�F�N�g
	LPDIRECT3DDEVICE9 m_pD3DDevice;
	LPD3DXFONT m_pFont;
	D3DPRESENT_PARAMETERS m_pD3dpp;

	IDirect3DSurface9* m_pDrawSurface;		// �`��T�[�t�F�X
	IDirect3DSurface9* m_pZBuffSurface;		// Z�o�b�t�@�T�[�t�F�X
	IDirect3DSurface9* m_pOriginalSurface;	// ���̕`��T�[�t�F�X
	IDirect3DSurface9* m_pOriginalZBuffer;	// ����Z�o�b�t�@�T�[�t�F�X
	LPDIRECT3DTEXTURE9 m_pDrawTexture;		// �`��p�e�N�X�`��
};

#endif