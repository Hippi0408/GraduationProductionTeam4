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

	//データフォーマットを設定
	if (FAILED(CInput::GetInputDevice()->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}

	//協調モードを設定
	if (FAILED(CInput::GetInputDevice()->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		return E_FAIL;
	}

	//キーボードのアクセス権を獲得
	CInput::GetInputDevice()->Acquire();

	return S_OK;
}

void CInputMouse::Uninit(void)
{
	// インプットの終了
	CInput::Uninit();
}

void CInputMouse::Update(void)
{
	// 親クラスのメンバ変数を取得
	LPDIRECTINPUTDEVICE8 pDevice = GetInputDevice();

	// 変数宣言
	DIMOUSESTATE2 mouseState;		// マウス入力情報
	int nCntKey;

	// 入力デバイスからデータを取得
	if (SUCCEEDED(pDevice->GetDeviceState(sizeof(mouseState), &mouseState)))
	{
		for (nCntKey = 0; nCntKey < MOUSE_KEY_MAX; nCntKey++)
		{
			// マウストリガー情報を保存
			m_mouseStateTrigger.rgbButtons[nCntKey] = (m_mouseState.rgbButtons[nCntKey] ^ mouseState.rgbButtons[nCntKey]) & mouseState.rgbButtons[nCntKey];

			// マウスリリース情報を保存
			m_mouseStateRelease.rgbButtons[nCntKey] = (m_mouseState.rgbButtons[nCntKey] ^ mouseState.rgbButtons[nCntKey]) & m_mouseState.rgbButtons[nCntKey];

			// マウスプレス情報を保存
			m_mouseState = mouseState;
		}
	}
	else
	{
		// マウスへのアクセス権を獲得
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
	// スクリーン座標上のマウスカーソルの位置の取得
	GetCursorPos(&m_mouseCursor);

	// ウィンドウ上のマウスカーソルの位置の取得
	ScreenToClient(CApplication::GetInstance()->GetWindow(), &m_mouseCursor);

	return D3DXVECTOR3((float)m_mouseCursor.x, (float)m_mouseCursor.y, 0.0f);
}

D3DXVECTOR3 CInputMouse::GetMouseMove(void)
{
	return D3DXVECTOR3((float)(m_mouseState.lX), (float)(m_mouseState.lY), (float)(m_mouseState.lZ));
}
