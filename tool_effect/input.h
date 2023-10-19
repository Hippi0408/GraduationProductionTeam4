//
//Input.h
//
#ifndef _INPUT_H_
#define _INPUT_H_

class CInput
{
public:
	enum EInputType
	{
		INPUTTYPE_KEYBOARD,
		INPUTTYPE_MOUSE,
		INPUTTYPE_MAX
	};

	CInput();
	virtual ~CInput();

	virtual HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	virtual void Uninit();
	virtual void Update() = 0;

	void SetInputDevice(LPDIRECTINPUTDEVICE8 device) { m_pDevice = device; }
	void SetInputType(EInputType type) { m_inputType = type; }

	LPDIRECTINPUTDEVICE8 GetInputDevice() { return m_pDevice; }
	EInputType GetInputType() { return m_inputType; }

private:
	LPDIRECTINPUT8 m_pInput;
	LPDIRECTINPUTDEVICE8 m_pDevice;
	EInputType m_inputType;
};

#endif