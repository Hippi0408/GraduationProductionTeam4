//==============================================================================================
//
// ゲージマネージャー	　　gauge_manager.h
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
	D3DXVECTOR3 m_Pos;			// 位置
	D3DXVECTOR2 m_Size;			// サイズ
	int m_nBease_GaugeSize;		// 元のゲージサイズ
	int m_nBease_Life;			// 元の体力
	D3DXCOLOR m_Col;			// 色
	D3DXCOLOR m_BackCol;		// 背景ゲージの色
	CObject2D *m_BackGauge;		// ゲージの背景
};

#endif // !_GAUGE_MANAGER_H_
