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
	static const int MAX_TEXTURE = 3;							// �e�N�X�`���̍ő吔
	const float SizeXScaleSpeed = 11.8f;						// x�T�C�Y�g��k���X�s�[�h
	const float SizeYScaleSpeed = 7.5f;							// y�T�C�Y�g��k���X�s�[�h

	CCharDecision_Window();										// ���j���[�E�B���h�E�̃R���X�g���N�^
	~CCharDecision_Window();									// ���j���[�E�B���h�E�̃f�X�g���N�^

	HRESULT Init();												// ����������
	void Uninit();												// �I������
	void Update();												// �X�V����

	void SetFont(const std::string lette[]);
	void UninitFont();
	void CharDecisionMenuScale();								// ���j���[�̃T�C�Y����
	bool CharDecisionMenuScaleReduce();							// �^�C�g�����j���[�̃T�C�Y�k������

	int GetSelectChoice() { return 	m_nSelectChoice = 0; }
	bool GetUninit() { return m_bUninitFlag; }	
	bool GetCreateFlag() { return m_bCreateFlag; }
	bool GetSapawnWindow() { return m_bSpawnWindow; }
	bool GetMaxScale() { return m_bMaxSize; }

	void SetCharDecisionChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }
	void SetUninit(bool flag) { m_bUninitFlag = flag; }
	void SetSapawnWindow(bool flag) { m_bSpawnWindow = flag; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }
	static CObject2D* GetObject2D() { return m_pObject2D[MAX_TEXTURE]; }
	static CCharDecision_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);			// ����

private:
	static CObject2D* m_pObject2D[MAX_TEXTURE];						// �I�u�W�F�N�g2D�̃C���X�^���X
	CFontString* m_pFont[2];						// �t�H���g
	D3DXVECTOR3 m_pos;							// �ʒu
	D3DXCOLOR m_Color;							// �F

	int		m_nMenuInitiative;					// ���j���[�̎哱��
	int		m_nSelectChoice;

	float	m_SizeX;							// X�T�C�Y
	float	m_SizeY;							// Y�T�C�Y
	float	m_MaxSizeX;							// X�̍ő�T�C�Y
	float	m_MaxSizeY;							// Y�̍ő�T�C�Y
	float	m_fBlinkSpeed;						// �_�ő��x

	bool	m_bMaxSize;							// X��Y�̃T�C�Y���ő�l�܂ōs������
	bool	m_bDisplay;							// �\�����̔���
	bool	m_bScale;							// �g��k���̃t���O
	bool    m_bUninitFlag;						// �폜�t���O
	bool    m_bCreateFlag;
	bool    m_bFontFlag;
	bool    m_bDecition;						// ���肳�ꂽ��
	bool    m_bSpawnWindow;						// �E�B���h�E���������ꂽ��

	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
};
#endif