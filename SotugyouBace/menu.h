//=============================================================================
//
// menu.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _MENU_H_
#define _MENU_H_

#include "d3dx9.h"
#include "fontString.h"
#include <vector>

//---------------------------
// �N���X�錾
//---------------------------
class CMenu
{
	static const float CHOICE_BLINK_SPEED;		// �I�����̓_�ő��x
	static const float CHOICE_MINI_ALPHA;		// �I�����̍Œᓧ���l

public:
	CMenu();
	virtual ~CMenu();

	virtual HRESULT Init();
	virtual void Uninit();
	virtual void Update();

	virtual void Choice();						// �I�����̏���
	void ChangeChoice(const int nextChoice);	// �I������ύX�������̏���

	void SetMenuInitiative(const int index) { m_nMenuInitiative = index; }
	void SetDecition(const bool decition) { m_bDecition = decition; }
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }
	void SetDisplay(const bool display);		// �I�����̕\�������ݒ肷��

	const int GetMenuInitiative() { return m_nMenuInitiative; }
	const int GetSelectChoice() { return m_nSelectChoice; }
	const bool GetDecition() { return m_bDecition; }
	const bool GetDisplay() { return m_bDisplay; }
	CFontString* GetChoice(const int index) { return m_vpListChoice[index]; }
	std::vector<CFontString*> GetChoiceAll() { return m_vpListChoice; }

private:

	int		m_nMenuInitiative;					// ���j���[�̎哱��
	int		m_nSelectChoice;					// �I�����̔ԍ�
	float	m_fBlinkSpeed;						// �_�ő��x
	bool	m_bDecition;						// ����̔���
	bool	m_bDisplay;							// �\�����̔���

	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
};

#endif // !_MENU_H_