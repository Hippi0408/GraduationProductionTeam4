//==============================================================================================
//
// �Q�[�W�}�l�[�W���[	�@�@gauge_manager.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _GAUGE_MANAGER_H_
#define	_GAUGE_MANAGER_H_

#include"object2D.h"

class CGauge_Manager : public CObject2D
{
public:
	CGauge_Manager(const PRIORITY priority = PRIORITY_SCREEN);
	virtual ~CGauge_Manager() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw()  override;

	virtual void Fluctuation() = 0;

	void SetGaugePos(D3DXVECTOR3 pos) { m_Pos = pos; }
	void SetGaugeSize(D3DXVECTOR2 size) { m_Size = size; }
	void SetBeaseSize(int beasesize) { m_nBease_GaugeSize = beasesize; }
	void SetBeaseLife(int beaselife) { m_nBease_Life = beaselife; }
	void SetGaugeCol(D3DXCOLOR col) { m_Col = col; }
	void SetBackCol(D3DXCOLOR backcol) { m_BackCol = backcol; }

	D3DXVECTOR3 GetGaugePos() { return m_Pos; }
	D3DXVECTOR2 GetGaugeSize() { return m_Size; }
	int GetBeaseSize() { return m_nBease_GaugeSize; }
	int GetBeaseLife() { return m_nBease_Life; }
	CObject2D *GetBackGauge() { return m_BackGauge; }

private:
	D3DXVECTOR3 m_Pos;			// �ʒu
	D3DXVECTOR2 m_Size;			// �T�C�Y
	int m_nBease_GaugeSize;		// ���̃Q�[�W�T�C�Y
	int m_nBease_Life;			// ���̗̑�
	D3DXCOLOR m_Col;			// �F
	D3DXCOLOR m_BackCol;		// �w�i�Q�[�W�̐F
	CObject2D *m_BackGauge;		// �Q�[�W�̔w�i
};

#endif // !_GAUGE_MANAGER_H_
