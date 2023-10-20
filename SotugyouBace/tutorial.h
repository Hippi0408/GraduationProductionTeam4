//==============================================================================================
//
// �`���[�g���A���@�@�@tutorial.h
// tutida ryousei
//
//==============================================================================================
#ifndef _TUTORIAL_H_
#define _TUTORIAL_H_

#include"mode.h"

class CMeshField;
class CEnergy_Gauge;

class CTutorial : public CMode
{
public:
	CTutorial();
	~CTutorial();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;

	static CTutorial *Create();

	static CMeshField *GetMeshField() { return pMeshField; }
	static CEnergy_Gauge* GetEnergy_Gauge() { return m_pEnergy_Gauge; }

private:
	static CMeshField *pMeshField;			// ���b�V���t�B�[���h
	static CEnergy_Gauge* m_pEnergy_Gauge;	// �G�l���M�[�Q�[�W
};

#endif // !_TUTORIAL_H_
