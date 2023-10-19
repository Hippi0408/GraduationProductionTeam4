//����������������������������������������
//Mouse.h
//����������������������������������������
#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "input.h"

class CInputMouse : public CInput
{
public:
	enum SMOUSE_KEY
	{
		MOUSE_KEY_LEFT = 0,		// �}�E�X���{�^��
		MOUSE_KEY_RIGHT,		// �}�E�X�E�{�^��
		MOUSE_KEY_MIDDLE,		// �}�E�X�����{�^��
		MOUSE_KEY_SIDE_0,		// �}�E�X�T�C�h�{�^��0
		MOUSE_KEY_SIDE_1,		// �}�E�X�T�C�h�{�^��1
		MOUSE_KEY_SIDE_2,		// �}�E�X�T�C�h�{�^��2
		MOUSE_KEY_SIDE_3,		// �}�E�X�T�C�h�{�^��3
		MOUSE_KEY_SIDE_4,		// �}�E�X�T�C�h�{�^��4
		MOUSE_KEY_MAX,			// �}�E�X�̃{�^���̍ő吔
	};

	CInputMouse();
	~CInputMouse() override;

	HRESULT Init(HINSTANCE hInstance, HWND hWnd) override;
	void Uninit() override;
	void Update() override;
	void DrawCursor(bool draw) { ShowCursor(draw); }

	D3DXVECTOR3 GetMouseCursor(void);								// �J�[�\���̃X�N���[�����W�̎擾
	D3DXVECTOR3 GetMouseMove(void);									// �}�E�X�̈ړ���
	int GetMouseWheel(void) { return (int)m_mouseState.lZ; }		// �}�E�X�z�C�[���̏���
	bool GetTrigger(int nKey);
	bool GetPress(int nKey);

private:
	static const int NUM_KEY_MAX = 256;

	DIMOUSESTATE2 m_mouseState;					// �}�E�X�̃v���X���
	DIMOUSESTATE2 m_mouseStateTrigger;			// �}�E�X�̃g���K�[���
	DIMOUSESTATE2 m_mouseStateRelease;			// �}�E�X�̃����[�X���
	POINT m_mouseCursor;						// �}�E�X�J�[�\���̈ʒu
};

#endif