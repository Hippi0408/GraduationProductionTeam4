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

	// �����_�����O�N���X�̐���
	m_pRenderer = new CRenderer;
	if (FAILED(m_pRenderer->Init(hWnd, TRUE)))
	{	// ���������������s�����ꍇ
		return -1;
	}

	// �E�B���h�E�N���X�̐���
	m_pWindow = new CWindow;
	if (FAILED(m_pWindow->Init(hInstance)))
	{
		return -1;
	}

	// �L�[�{�[�h�N���X�̐���
	m_pInputKeyboard = new CInputKeyboard;
	if (FAILED(m_pInputKeyboard->Init(hInstance, hWnd)))
	{	// ���������������s�����ꍇ
		return -1;
	}

	// �}�E�X�N���X�̐���
	m_pInputMouse = new CInputMouse;
	if (FAILED(m_pInputMouse->Init(hInstance, hWnd)))
	{	// ���������������s�����ꍇ
		return -1;
	}
	m_pInputMouse->DrawCursor(true);

	// �t�@�C���N���X�̐���
	m_pFile = new CFile;

	// �V�F�[�_�[�}�l�[�W���̐���
	m_pShaderManager = new CShaderManager;
	m_pShaderManager->LoadAll();

	// �e�N�X�`���N���X�̐���
	m_pTexture = new CTexture;
	m_pTexture->LoadAll();

	// ���f���N���X�̐���
	m_pModel = new CModel;
	m_pModel->LoadAll();

	// �T�E���h�N���X�̐���
	m_pSound = new CSound;
	m_pSound->LoadAll();
	if (FAILED(m_pSound->Init(hWnd)))
	{	// ���������������s�����ꍇ
		return -1;
	}

	// ���C�g�N���X�̐���
	m_pLight = new CLight;
	m_pLight->Init();

	// �J�����N���X�̐���
	m_pCamera = new CCamera;
	m_pCamera->Init();

	// �����N���X�̐���
	m_pPhysics = new CPhysics;

	// �p�[�e�B�N���}�l�[�W���̐���
	m_pParticleManager = new CParticleManager;
	//m_pParticleManager->LoadAll();

	m_pPointer = new CPointer;
	m_pPointer = CPointer::Create(D3DXVECTOR3(0.0f, 10.0f, 0.0f));

	// Imgui
	m_pMyImgui = new CMyImgui;
	m_pMyImgui->Init();

	// ��
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

	// �e�N�X�`���N���X�̔j��
	if (m_pTexture != nullptr)
	{
		m_pTexture->UnloadAll();
		delete m_pTexture;
		m_pTexture = nullptr;
	}

	// �p�[�e�B�N���}�l�[�W���̔j��
	if (m_pParticleManager != nullptr)
	{
		m_pParticleManager->ReleaseAll();
		delete m_pParticleManager;
		m_pParticleManager = nullptr;
	}

	// ���f���N���X�̔j��
	if (m_pModel != nullptr)
	{
		m_pModel->Clear();
		delete m_pModel;
		m_pModel = nullptr;
	}

	// �T�E���h�N���X�̔j��
	if (m_pSound != nullptr)
	{
		m_pSound->Uninit();
		delete m_pSound;
		m_pSound = nullptr;
	}

	// �J�����N���X�̔j��
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}

	// ���C�g�N���X�̔j��
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	// �V�F�[�_�[�}�l�[�W���̔j��
	if (m_pShaderManager != nullptr)
	{
		m_pShaderManager->ReleaseAll();
		delete m_pShaderManager;
		m_pShaderManager = nullptr;
	}

	// �����N���X�̔j��
	if (m_pPhysics != nullptr)
	{
		delete m_pPhysics;
		m_pPhysics = nullptr;
	}

	// �L�[�{�[�h�N���X�̔j��
	if (m_pInputKeyboard != nullptr)
	{
		m_pInputKeyboard->Uninit();
		delete m_pInputKeyboard;
		m_pInputKeyboard = nullptr;
	}

	// �}�E�X�N���X�̔j��
	if (m_pInputMouse != nullptr)
	{
		m_pInputMouse->Uninit();
		delete m_pInputMouse;
		m_pInputMouse = nullptr;
	}

	// �����_�����O�N���X�̔j��
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	// �t�@�C���N���X�̔j��
	if (m_pFile != nullptr)
	{
		delete m_pFile;
		m_pFile = nullptr;
	}

	// �E�B���h�E�N���X�̔j��
	if (m_pWindow != nullptr)
	{
		m_pWindow->Uninit();
		delete m_pWindow;
		m_pWindow = nullptr;
	}

	// �A�v���P�[�V�����̉��
	if (m_pApplication != nullptr)
	{
		delete m_pApplication;
		m_pApplication = nullptr;
	}
}

void CApplication::Update()
{
	// �C���v�b�g�̍X�V�����͍ŏ��ɍs��
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

	// ���C���[�t���[���ɂ��鏈��
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
