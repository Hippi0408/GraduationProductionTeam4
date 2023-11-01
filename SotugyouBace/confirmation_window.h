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
	static const float BLINK_SPEED;					// �I�����̓_�ő��x
	static const float MINI_ALPHA;					// �I�����̍Œᓧ���l
	const float SizeXScaleSpeed = 11.8f;			// x�T�C�Y�g��k���X�s�[�h
	const float SizeYScaleSpeed = 7.5f;				// y�T�C�Y�g��k���X�s�[�h
	const float SizeXScaleMax = 500.0f;				// x�T�C�Y�̍ő�X�P�[��
	const float SizeYScaleMax = 320.0f;				// y�T�C�Y�̍ŏ��X�P�[��

	CConfirmation_Window();							// ���j���[�E�B���h�E�̃R���X�g���N�^
	~CConfirmation_Window();						// ���j���[�E�B���h�E�̃f�X�g���N�^

	HRESULT Init();									// ����������
	void Uninit();									// �I������
	void Update();									// �X�V����

	void ConfirmatiomnMenuScale();					// ���j���[�̃T�C�Y����
	bool ConfirmatiomnMenuScaleReduce();			// ���j���[�̃T�C�Y�k������

	virtual void Choice();							// �I�����̏���
	void ChangeChoice(const bool nextChoice);		// �I������ύX�������̏���
	void SetDisplay(const bool display);			// �I�����̕\�������ݒ肷��
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }

	bool GetUninit() { return m_bUninitFlag; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

	static CConfirmation_Window* Create();			// ����
	static bool GetBf() { return m_bf; }
	static void SetBf(bool f) { m_bf = f; }

private:
	CObject2D* m_pObject2D;
	CFontString* m_pFont;

	int		m_nMenuInitiative;					// ���j���[�̎哱��

	float	SizeX;								// X�T�C�Y
	float	SizeY;								// Y�T�C�Y
	float	m_fBlinkSpeed;						// �_�ő��x

	bool	m_bMaxSize;							// X��Y�̃T�C�Y���ő�l�܂ōs������
	bool	m_bflag;
	bool	m_bSelectChoice;					// �I�����̔ԍ�
	bool	m_bDisplay;							// �\�����̔���
	bool	m_bScale;
	bool    m_bUninitFlag;
	static bool    m_bf;

	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
};
#endif