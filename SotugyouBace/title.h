//==============================================================================================
//
// �^�C�g���@�@�@title.h
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#ifndef _TITLE_H_
#define	_TITLE_H_

#include"mode.h"

class CHalfSphere;

class CTitle : public CMode
{
public:
	CTitle();
	~CTitle();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CTitle* Create();

private:
	CHalfSphere* m_pHalfSphere;
	bool m_bWindow;		// �E�B���h�E�g�p���
};

#endif // !_TITLE_H_
