//==============================================
//
// chardecision_window.h (�L��������E�B���h�E.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _CHARDECISISION_WINDOW_H_				//���̃}�N����`������ĂȂ�������
#define  _CHARDECISISION_WINDOW_H_				//��d�C���N���[�h�h�~�̃}�N����`

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
// �L��������E�B���h�E�N���X
//==============================================
class CCharDecision_Window
{
public:
	static const int MAX_TEXTURE = 2;							// �e�N�X�`���̍ő吔
	static const float BLINK_SPEED;								// �I�����̓_�ő��x
	static const float MINI_ALPHA;								// �I�����̍Œᓧ���l
	const float SizeXScaleSpeed = 11.8f;						// x�T�C�Y�g��k���X�s�[�h
	const float SizeYScaleSpeed = 7.5f;							// y�T�C�Y�g��k���X�s�[�h

	CCharDecision_Window();										// ���j���[�E�B���h�E�̃R���X�g���N�^
	~CCharDecision_Window();									// ���j���[�E�B���h�E�̃f�X�g���N�^

	HRESULT Init();												// ����������
	void Uninit();												// �I������
	void Update();												// �X�V����

	void SetFont(const std::string lette[]);					// �t�H���g�̐ݒ菈��
	void SetTextue(CTexture::TEXTURE texture, CTexture::TEXTURE texture1);							// �e�N�X�`���̐ݒ�
	void UninitExplanation();									// �����p�e�N�X�`���A�t�H���g�̔j������
	void CharDecisionMenuScale();								// ���j���[�̃T�C�Y����
	void CharSelectChoice();									// �I�����̏���

	bool GetSapawnWindow() { return m_bSpawnWindow; }			// �E�B���h�E���������ꂽ���̎擾����
	bool GetMaxScale() { return m_bMaxSize; }					// �E�B���h�E���ő�T�C�Y�܂ōs�����̂����擾���鏈��
	bool GetExplanationUninit() { return m_bExplanationUninit; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }										// �I�����|�C���^�̎擾����
	static CCharDecision_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);			// ��������

private:
	CObject2D* m_pWindow;						// �I�u�W�F�N�g2D�̃C���X�^���X
	CObject2D* m_pObject2D[MAX_TEXTURE];		// �I�u�W�F�N�g2D�̃C���X�^���X
	CFontString* m_pFont[2];					// �t�H���g
	D3DXVECTOR3 m_posDest;						// �ړI�ʒu
	D3DXVECTOR3 m_pos;							// �ʒu
	D3DXCOLOR m_Color;							// �F

	int		m_nMenuInitiative;					// ���j���[�̎哱��
	int		m_nSelectIndex;
	int index;

	float	m_SizeX;							// X�T�C�Y
	float	m_SizeY;							// Y�T�C�Y
	float	m_MaxSizeX;							// X�̍ő�T�C�Y
	float	m_MaxSizeY;							// Y�̍ő�T�C�Y
	float	m_fBlinkSpeed;						// �_�ő��x
	float	m_fMoveX;

	bool	m_bMaxSize;							// X��Y�̃T�C�Y���ő�l�܂ōs������
	bool	m_bDisplay;							// �\�����̔���
	bool	m_bScale;							// �g��k���̃t���O
	bool    m_bUninitFlag;						// �폜�t���O
	bool    m_bCreateFlag;
	bool    m_bFontFlag;
	bool    m_bDecition;						// ���肳�ꂽ��
	bool    m_bSpawnWindow;						// �E�B���h�E���������ꂽ��
	bool    m_bStopFlag;
	bool    m_bExplanationUninit;					// �e�N�X�`���ƃt�H���g�̍폜�t���O
	bool    m_bPosDest;	// �ړI�̈ʒu�܂ōs�����̂�

	

	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
};
#endif