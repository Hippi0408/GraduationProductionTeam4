//=============================================================================
//
// charselect_window.h (�L�����I���E�B���h�E.h)
// Author : Saito Shian
//
//=============================================================================
#ifndef  _CHARSELECT_WINDOW_H_				//���̃}�N����`������ĂȂ�������
#define  _CHARSELECT_WINDOW_H_				//��d�C���N���[�h�h�~�̃}�N����`

//=============================================================================
// �C���N���[�h
//=============================================================================
#include "main.h"
#include "object.h"
#include "d3dx9.h"
#include "fontString.h"
#include <vector>

//=============================================================================
// �O���錾
//=============================================================================
class CObject2D;
class CFontString;
class CCharDecision_Window;

//=============================================================================
// �L�����I���E�B���h�E�N���X
//=============================================================================
class CCharSelect_Window
{
	static const float BLINK_SPEED;							// �I�����̓_�ő��x
	static const float MINI_ALPHA;							// �I�����̍Œᓧ���l
	const float SizeXScaleSpeed = 31.8f;					// x�T�C�Y�g��k���X�s�[�h
	const float SizeYScaleSpeed = 27.5f;					// y�T�C�Y�g��k���X�s�[�h

public:
	CCharSelect_Window();									// �L�����I���E�B���h�E�̃R���X�g���N�^
	~CCharSelect_Window();									// �L�����I���E�B���h�E�̃f�X�g���N�^

	HRESULT Init();											// ����������
	void Uninit();											// �I������
	void Update();											// �X�V����

	virtual void CharSelectChoice();						// �I�����̏���
	void CharSelectMenuScale();								// �L�����I���E�B���h�E�̃T�C�Y����
	bool CharSelectMenuScaleReduce();						// �L�����I���E�B���h�E�̃T�C�Y�k������
	void CharSelectChangeChoice(const int nextChoice);		// �I������ύX�������̏���
	void InitSelect();										// �I�����̏���������
	void UninitFont();										// �t�H���g�̍폜����

	void SetSelectChoice(int index);														// �I�������ԍ�
	void SetCharSelectDisplay(const bool display);											// �I�����̕\�������ݒ肷��
	void SetSkillName(const std::string name, const std::string skillname);					// �X�L����
	void SetCharSelectChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }		// �I�����|�C���^�̐ݒ菈��
	void SetSkillSelectChoice(const std::string typename, const std::string name, const std::string name1, const std::string name2, const std::string name3);	// �I�������ԍ��ɂ���ăX�L����ς��鏈��

	CCharDecision_Window* GetCharDecision() { return m_pCharDecision; }						// �L��������C���X�^���X�̎擾����
	int GetSelectChoice() { return 	m_nCharSelectWindowSelectChoice; }						// �I�����̔ԍ��̎擾����
	bool GetPreviousWindow() { return m_bPreviousWindowCreate; }							// �O�̃E�B���h�E�ɖ߂����̂��̎擾����

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }						// �I�����|�C���^�̎擾����
	
	static CCharSelect_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);	// ����

private:
	CCharDecision_Window* m_pCharDecision;		// �L��������̃C���X�^���X
	CObject2D* m_pObject2D;						// �I�u�W�F�N�g2D�̃C���X�^���X
	
	D3DXVECTOR2 m_CharSelectWindowSize;			// �T�C�Y
	D3DXVECTOR2 m_CharSelectWindowMaxSize;		// �ő�T�C�Y
	CFontString* m_pFont;						// �t�H���g
	D3DXVECTOR3 m_pos;							// �ʒu
	D3DXCOLOR m_Color;							// �F

	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
	std::string m_nLetter[2];					// �������i�[����ϐ�

	int		m_nCharSelectWindowSelectChoice;	// �I�����̔ԍ�

	float	m_fCharSelectWindowBlinkSpeed;		// �_�ő��x

	bool	m_bCharSelectWindowMaxSize;			// X��Y�̃T�C�Y���ő�l�܂ōs������
	bool	m_bCharSelectWindowDisplay;			// �\�����̔��� a
	bool	m_bCharSelectWindowScale;			// �g��k���̃t���O
	bool    m_bCharSelectWindowDecition;		// ���肳�ꂽ��
	bool    m_bCharSelectWindowWindowUse;		// �L�����I���E�B���h�E���g���Ă���̂�
	bool	m_bCharSelectWindowUninitFlag;		// �L�����I���E�B���h�E���폜���ꂽ��
	bool    m_bCharSelectWindowBackFlag;		// �O�̃E�B���h�E����߂��Ă�����
	bool    m_bPreviousWindowCreate;			// �O�̃E�B���h�E�ɖ߂�̂�
	bool    m_bDicisionCreateFlag;				// �L��������E�B���h�E���������ꂽ��
	bool    m_bDicisionUse;						// �L��������E�B���h�E���g���Ă��邩
};
#endif