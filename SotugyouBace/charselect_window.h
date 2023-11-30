//==============================================
//
// charselect_window.h (�L�����I���E�B���h�E.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _CHARSELECT_WINDOW_H_				//���̃}�N����`������ĂȂ�������
#define  _CHARSELECT_WINDOW_H_				//��d�C���N���[�h�h�~�̃}�N����`

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
class CCharDecision_Window;

//==============================================
// ���j���[�E�B���h�E�N���X
//==============================================
class CCharSelect_Window
{
public:
	static const float BLINK_SPEED;							// �I�����̓_�ő��x
	static const float MINI_ALPHA;							// �I�����̍Œᓧ���l
	const float SizeXScaleSpeed = 11.8f;					// x�T�C�Y�g��k���X�s�[�h
	const float SizeYScaleSpeed = 7.5f;						// y�T�C�Y�g��k���X�s�[�h

	CCharSelect_Window();									// ���j���[�E�B���h�E�̃R���X�g���N�^
	~CCharSelect_Window();									// ���j���[�E�B���h�E�̃f�X�g���N�^

	HRESULT Init();											// ����������
	void Uninit();											// �I������
	void Update();											// �X�V����

	void CharSelectMenuScale();								// ���j���[�̃T�C�Y����
	bool CharSelectMenuScaleReduce();						// �^�C�g�����j���[�̃T�C�Y�k������

	virtual void CharSelectChoice();						// �I�����̏���
	void CharSelectChangeChoice(const int nextChoice);		// �I������ύX�������̏���

	void CharName(const std::string name, const std::string skillname);						// �L�����N�^�[��
	void InitSelect();

	void SetSelectChoice(int index);
	void SetCharSelectDisplay(const bool display);											// �I�����̕\�������ݒ肷��
	void SetCharSelectChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }
	void SetSapawnWindow(bool flag) { m_bSpawnWindow = flag; }
	void SetScale(bool flag) { m_bScale = flag; }

	int GetSelectChoice() { return 	m_nSelectChoice; }
	bool GetSapawnWindow() { return m_bSpawnWindow; }
	bool GetScale() { return m_bScale; }

	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

	static CCharSelect_Window* Create(D3DXVECTOR3 pos, float xsize, float ysize, D3DXCOLOR col);			// ����

private:
	CObject2D* m_pObject2D;						// �I�u�W�F�N�g2D�̃C���X�^���X
	CCharDecision_Window* m_pCharDecision;		// �L��������̃C���X�^���X
	CFontString* m_pFont;						// �t�H���g
	D3DXVECTOR3 m_pos;							// �ʒu
	D3DXCOLOR m_Color;							// �F

	std::string m_nLetter[2];

	int		m_nMenuInitiative;					// ���j���[�̎哱��
	int		m_nSelectChoice;

	float	m_SizeX;							// X�T�C�Y
	float	m_SizeY;							// Y�T�C�Y
	float	m_MaxSizeX;							// X�̍ő�T�C�Y
	float	m_MaxSizeY;							// Y�̍ő�T�C�Y
	float	m_fBlinkSpeed;						// �_�ő��x

	bool	m_bMaxSize;							// X��Y�̃T�C�Y���ő�l�܂ōs������
	bool	m_bDisplay;							// �\�����̔��� a
	bool	m_bScale;							// �g��k���̃t���O
	bool    m_bDecition;						// ���肳�ꂽ��
	bool    m_bSpawnWindow;						// �E�B���h�E���������ꂽ��
	bool    m_bDicisionCreateFlag;
	bool    m_bWindowUse;

	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
};
#endif