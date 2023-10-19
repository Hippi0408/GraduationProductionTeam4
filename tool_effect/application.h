//
//Application.h
//
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "main.h"

class CInputKeyboard;
class CInputMouse;
class CObject;
class CRenderer;
class CTexture;
class CCamera;
class CLight;
class CFile;
class CMyImgui;
class CModel;
class CPointer;
class CParticleManager;
class CPhysics;
class CSound;
class CWindow;
class CShaderManager;

class CApplication
{
public:
	static CApplication *GetInstance();

	CApplication();
	~CApplication();

	HRESULT Init(HWND hWnd, HINSTANCE hInstance);
	void Uninit();
	void Update();
	void Draw();

	void SetMyClassName(LPCTSTR name) { m_className = name; }
	void SetMyWindowName(std::string name) { m_windowName = name; }

	CInputKeyboard *GetInputKeyboard() { return m_pInputKeyboard; }
	CInputMouse *GetInputMouse() { return m_pInputMouse; }
	CRenderer *GetRenderer() { return m_pRenderer; }
	CCamera *GetCamera() { return m_pCamera; }
	CFile *GetFile() { return m_pFile; }
	CLight *GetLight() { return m_pLight; }
	CTexture *GetTexture() { return m_pTexture; }
	CMyImgui *GetMyImgui() { return m_pMyImgui; }
	CModel *GetModel() { return m_pModel; }
	CPointer *GetPointer() { return m_pPointer; }
	CParticleManager *GetParticleManager() { return m_pParticleManager; }
	CPhysics *GetPhysics() { return m_pPhysics; }
	CSound *GetSound() { return m_pSound; }
	CWindow *GetChildWindow() { return m_pWindow; }
	CShaderManager *GetShaderManager() { return m_pShaderManager; }

	HWND GetWindow() { return m_hWnd; }
	LPCTSTR GetMyClassName() { return m_className; }
	std::string GetMyWindowName() { return m_windowName; }

private:
	static CApplication *m_pApplication;

	CObject *m_pObject;
	CLight *m_pLight;
	CCamera *m_pCamera;
	CInputKeyboard *m_pInputKeyboard;
	CInputMouse *m_pInputMouse;
	CRenderer *m_pRenderer;
	CTexture *m_pTexture;
	CFile *m_pFile;
	CMyImgui *m_pMyImgui;
	CModel *m_pModel;
	CPointer *m_pPointer;
	CParticleManager *m_pParticleManager;
	CPhysics *m_pPhysics;
	CSound *m_pSound;
	CWindow *m_pWindow;
	CShaderManager *m_pShaderManager;

	HWND m_hWnd;
	LPCTSTR m_className;
	std::string m_windowName;

	bool m_bWire;
};

#endif