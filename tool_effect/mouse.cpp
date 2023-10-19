#include "application.h"
#include "renderer.h"
#include "input.h"
#include "mouse.h"

CInputMouse::CInputMouse()
{
}

CInputMouse::~CInputMouse()
{
}

HRESULT CInputMouse::Init(HINSTANCE hInstance, HWND hWnd)
{
	CInput::SetInputType(CInput::INPUTTYPE_MOUSE);
	CInput::Init(hInstance, hWnd);

	//�f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(CInput::GetInputDevice()->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}

	//�������[�h��ݒ�
	if (FAILED(CInput::GetInputDevice()->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//�L�[�{�[�h�̃A�N�Z�X�����l��
	CInput::GetInputDevice()->Acquire();

	return S_OK;
}

void CInputMouse::Uninit(void)
{
	// �C���v�b�g�̏I��
	CInput::Uninit();
}

void CInputMouse::Update(void)
{
	// �e�N���X�̃����o�ϐ����擾
	LPDIRECTINPUTDEVICE8 pDevice = GetInputDevice();

	// �ϐ��錾
	DIMOUSESTATE2 mouseState;		// �}�E�X���͏��
	int nCntKey;

	// ���̓f�o�C�X����f�[�^���擾
	if (SUCCEEDED(pDevice->GetDeviceState(sizeof(mouseState), &mouseState)))
	{
		for (nCntKey = 0; nCntKey < MOUSE_KEY_MAX; nCntKey++)
		{
			// �}�E�X�g���K�[����ۑ�
			m_mouseStateTrigger.rgbButtons[nCntKey] = (m_mouseState.rgbButtons[nCntKey] ^ mouseState.rgbButtons[nCntKey]) & mouseState.rgbButtons[nCntKey];

			// �}�E�X�����[�X����ۑ�
			m_mouseStateRelease.rgbButtons[nCntKey] = (m_mouseState.rgbButtons[nCntKey] ^ mouseState.rgbButtons[nCntKey]) & m_mouseState.rgbButtons[nCntKey];

			// �}�E�X�v���X����ۑ�
			m_mouseState = mouseState;
		}
	}
	else
	{
		// �}�E�X�ւ̃A�N�Z�X�����l��
		pDevice->Acquire();
	}

	SetInputDevice(pDevice);
}

bool CInputMouse::GetPress(int nKey)
{
	return (m_mouseState.rgbButtons[nKey] & 0x80) ? true : false;
}

bool CInputMouse::GetTrigger(int nKey)
{
	return (m_mouseStateTrigger.rgbButtons[nKey] & 0x80) ? true : false;
}

D3DXVECTOR3 CInputMouse::GetMouseCursor(void)
{
	// �X�N���[�����W��̃}�E�X�J�[�\���̈ʒu�̎擾
	GetCursorPos(&m_mouseCursor);

	// �E�B���h�E��̃}�E�X�J�[�\���̈ʒu�̎擾
	ScreenToClient(CApplication::GetInstance()->GetWindow(), &m_mouseCursor);

	return D3DXVECTOR3((float)m_mouseCursor.x, (float)m_mouseCursor.y, 0.0f);
}

D3DXVECTOR3 CInputMouse::GetMouseMove(void)
{
	return D3DXVECTOR3((float)(m_mouseState.lX), (float)(m_mouseState.lY), (float)(m_mouseState.lZ));
}
