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

	void Input();								// ���͏���
	void ChangeChoice(const int nextChoice);	// �I������ύX�������̏���

	void SetMenuInitiative(const int index) { m_nMenuInitiative = index; }
	void SetDecition(const bool decition) { m_bDecition = decition; }
	void SetChoice(CFontString* choice) { m_vpListChoice.push_back(choice); }

	const int GetMenuInitiative() { return m_nMenuInitiative; }
	const int GetSelectChoice() { return m_nSelectChoice; }
	const bool GetDecition() { return m_bDecition; }
	std::vector<CFontString*> GetChoice() { return m_vpListChoice; }

private:

	int		m_nMenuInitiative;					// ���j���[�̎哱��
	int		m_nSelectChoice;					// �I�����̔ԍ�
	float	m_fBlinkSpeed;						// �_�ő��x
	bool	m_bDecition;						// ����̔���

	std::vector<CFontString*> m_vpListChoice;	// �I�����|�C���^�̔z��
};

#endif // !_MENU_H_