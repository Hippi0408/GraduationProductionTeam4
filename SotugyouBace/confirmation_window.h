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

#include "d3dx9.h"
#include "fontString.h"
#include <vector>

//==============================================
// �O���錾
//==============================================
class CObject2D;
class CFontString;

//==============================================
// ���j���[�E�B���h�E�N���X
//==============================================
class CConfirmation_Window
{
public:
	static const float BLINK_SPEED;		// �I�����̓_�ő��x
	static const float MINI_ALPHA;		// �I�����̍Œᓧ���l
	const float SizeXScaleSpeed = 11.8f;
	const float SizeYScaleSpeed = 7.5f;
	const float SizeXScaleMax = 500.0f;
	const float SizeYScaleMax = 320.0f;

	CConfirmation_Window();							// ���j���[�E�B���h�E�̃R���X�g���N�^
	~CConfirmation_Window();						// ���j���[�E�B���h�E�̃f�X�g���N�^

	HRESULT Init();									// ����������
	void Uninit();									// �I������
	void Update();									// �X�V����

	void ConfirmatiomnMenuScale();					// ���j���[�̃T�C�Y����
	bool ConfirmatiomnMenuScaleReduce();			// ���j���[�̃T�C�Y�k������

	virtual void Choice();						// �I�����̏���
	void ChangeChoice(const bool nextChoice);	// �I������ύX�������̏���
	void SetDisplay(const bool display);		// �I�����̕\�������ݒ肷��
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }

	int GetSelect() { return m_bSelectChoice; }

	bool GetFlag() { return m_bflag; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

	static CConfirmation_Window* Create();			// ����

private:
	CObject2D* m_pObject2D;

	float SizeX;
	float SizeY;

	bool m_bMaxSize;
	bool m_bflag;

	int		m_nMenuInitiative;					// ���j���[�̎哱��
	bool	m_bSelectChoice;					// �I�����̔ԍ�
	float	m_fBlinkSpeed;						// �_�ő��x
	bool	m_bDisplay;							// �\�����̔���
	bool	m_bScale;


	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
};
#endif


