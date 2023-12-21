//==============================================================================================
//
// �L�����N�^�[�Z���N�g�@�@�@char_select.h
// tutida ryousei
//
//==============================================================================================
#ifndef _CHAR_SELECT_H_
#define	_CHAR_SELECT_H_

#include"mode.h"
#include "fontString.h"
#include <vector>

class CConfirmation_Window;
class CFontString;
class CHalfSphere;
class CPlayerData;
class CModel;
class CObjectX;

class CChar_Select : public CMode
{
	static const int MAX_PLAYER = 4;
public:
	CChar_Select();
	~CChar_Select();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	void CharSwitching();
	void SetModel(int index, const char* Xfilename);
	void SetPlayerIndex(int index) { m_nPlayerIndex = index; }

	static CConfirmation_Window* GetConfimationWindow() { return m_pConfirmation; }

	static CChar_Select* Create();

private:
	static CConfirmation_Window* m_pConfirmation;
	CFontString* m_pFont;
	CHalfSphere* m_pHalfSphere;
	CPlayerData* m_pPlayerData;
	CObjectX* m_pObjectX[MAX_PLAYER];
	CObjectX* m_pWareHouse;

	int m_nPlayerIndex;				// �v���C���[�ԍ�
	int m_nIndex;					// �X�L�����݂̔ԍ�
	int m_nIndexKeep;				// �X�L���ԍ��ۑ��p�ϐ�
};

#endif // !_CHAR_SELECT_H_
