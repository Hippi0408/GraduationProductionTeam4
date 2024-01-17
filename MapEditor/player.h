//=============================================================================
//
// player.h
// Author : koduna hirohito
//
//=============================================================================
#ifndef _PLAYER_H_			//このマクロ定義がされなかったら
#define _PLAYER_H_			//2重インクルード防止のマクロ定義

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "object.h"
#include <list>

//*****************************************************************************
// 前方宣言
//*****************************************************************************
class C3DObject;

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CPlayer : public CObject
{
private:
	static const int INIT_LIFE = 100;
	static const D3DXVECTOR3 INIT_POS;
	static const float MOVE_MAGNIFICATION;
public:
	CPlayer();
	~CPlayer() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void MovePos();
	void MoveRot();
	void ChangeMagnification();
	void ChangeModel();
	void ChangeSize();
	void SetBullast();

	D3DXVECTOR3 GetPos() { return m_Pos; }
	D3DXVECTOR3 GetRot() { return m_Rot; }
	int GetModelNum() { return m_nModelNum; }
	float GetMoveMagnification() { return m_MoveMagnification; }
	float GetSize() { return m_fSize; }

	void SetCollision(bool bCollision) { m_bCollision = bCollision; }
	void SetOpeningLost(bool bOpeningLost) { m_bOpeningLost = bOpeningLost; }
	void SetSwitch(bool bSwitch) { m_bSwitch = bSwitch; }

	bool GetCollision() { return m_bCollision; }
	bool GetOpeningLost() { return m_bOpeningLost; }
	bool GetSwitch() { return m_bSwitch; }


	void SetModelIndex(int* pModelIndex) { m_pModelIndex = pModelIndex; }
	void SetModelIndexMax(int nModelIndexMax) { m_nModelIndexMax = nModelIndexMax; }

private:
	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3 m_Rot;
	float m_MoveMagnification;
	int m_nModelNum;
	int* m_pModelIndex;
	int m_nModelIndexMax;
	bool m_bCollision;
	bool m_bOpeningLost;
	bool m_bSwitch;
	C3DObject* m_p3DObject;
	float m_fSize;
	std::list<C3DObject*> m_BallastList;
};

#endif