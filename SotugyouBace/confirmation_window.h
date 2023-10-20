//==============================================
//
// confirmatiomn_window.h (���j���[�E�B���h�E.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _CONFIRMATION_WINDOW_H_				//���̃}�N����`������ĂȂ�������
#define  _CONFIRMATION_WINDOW_H_				//��d�C���N���[�h�h�~�̃}�N����`

//==============================================
// �C���N���[�h
//==============================================
#include "main.h"
#include "object.h"

//==============================================
// �O���錾
//==============================================
class CObject2D;

//==============================================
// ���j���[�E�B���h�E�N���X
//==============================================
class CConfirmation_Window
{
public:
	const float SizeXScaleSpeed = 11.8f;
	const float SizeYScaleSpeed = 7.5f;
	const float SizeXScaleMax = 500.0f;
	const float SizeYScaleMax = 320.0f;

	CConfirmation_Window();							// ���j���[�E�B���h�E�̃R���X�g���N�^
	~CConfirmation_Window();							// ���j���[�E�B���h�E�̃f�X�g���N�^

	HRESULT Init();									// ����������
	void Uninit();									// �I������
	void Update();									// �X�V����

	void ConfirmatiomnMenuScale();					// ���j���[�̃T�C�Y����
	bool ConfirmatiomnMenuScaleReduce();			// ���j���[�̃T�C�Y�k������

	static CConfirmation_Window* Create();			// ����

private:
	CObject2D* m_pObject2D;

	float SizeX;
	float SizeY;

	bool m_bMaxSize;
};
#endif


