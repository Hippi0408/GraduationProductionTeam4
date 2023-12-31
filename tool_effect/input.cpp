#include "main.h"
#include "input.h"

//
//L[{[hΜRXgN^
//
CInput::CInput() : m_pDevice(nullptr)
{
}

//
//L[{[hΜfXgN^
//
CInput::~CInput()
{

}

HRESULT CInput::Init(HINSTANCE hInstance, HWND hWnd)
{
	//DirectXIuWFNgΜμ¬
	if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pInput, NULL)))
	{
		return E_FAIL;
	}

	switch (m_inputType)
	{
	case CInput::INPUTTYPE_KEYBOARD:
		//όΝfoCXiL[{[hΜΆ¬j
		if (FAILED(m_pInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, NULL)))
		{
			return E_FAIL;
		}
		break;

	case CInput::INPUTTYPE_MOUSE:
		// όΝfoCXi}EXjΜΆ¬
		if (FAILED(m_pInput->CreateDevice(GUID_SysMouse, &m_pDevice, NULL)))
		{
			return E_FAIL;
		}
		break;

	default:
		assert(m_inputType > INPUTTYPE_MAX);
		break;
	}

	return S_OK;
}

void CInput::Uninit()
{
	//όΝfoCXiL[{[hΜjόj
	if (m_pDevice != NULL)
	{
		m_pDevice->Unacquire();
		m_pDevice->Release();
		m_pDevice = NULL;
	}

	//DirectXIuWFNgΜjό
	if (m_pInput != NULL)
	{
		m_pInput->Release();
		m_pInput = NULL;
	}
}