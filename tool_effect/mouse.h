//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//Mouse.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "input.h"

class CInputMouse : public CInput
{
public:
	enum SMOUSE_KEY
	{
		MOUSE_KEY_LEFT = 0,		// マウス左ボタン
		MOUSE_KEY_RIGHT,		// マウス右ボタン
		MOUSE_KEY_MIDDLE,		// マウス中央ボタン
		MOUSE_KEY_SIDE_0,		// マウスサイドボタン0
		MOUSE_KEY_SIDE_1,		// マウスサイドボタン1
		MOUSE_KEY_SIDE_2,		// マウスサイドボタン2
		MOUSE_KEY_SIDE_3,		// マウスサイドボタン3
		MOUSE_KEY_SIDE_4,		// マウスサイドボタン4
		MOUSE_KEY_MAX,			// マウスのボタンの最大数
	};

	CInputMouse();
	~CInputMouse() override;

	HRESULT Init(HINSTANCE hInstance, HWND hWnd) override;
	void Uninit() override;
	void Update() override;
	void DrawCursor(bool draw) { ShowCursor(draw); }

	D3DXVECTOR3 GetMouseCursor(void);								// カーソルのスクリーン座標の取得
	D3DXVECTOR3 GetMouseMove(void);									// マウスの移動量
	int GetMouseWheel(void) { return (int)m_mouseState.lZ; }		// マウスホイールの処理
	bool GetTrigger(int nKey);
	bool GetPress(int nKey);

private:
	static const int NUM_KEY_MAX = 256;

	DIMOUSESTATE2 m_mouseState;					// マウスのプレス情報
	DIMOUSESTATE2 m_mouseStateTrigger;			// マウスのトリガー情報
	DIMOUSESTATE2 m_mouseStateRelease;			// マウスのリリース情報
	POINT m_mouseCursor;						// マウスカーソルの位置
};

#endif