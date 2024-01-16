//=============================================================================
//
// player.h
// Author : koduna hirohito
//
//=============================================================================
#ifndef _PLAYER_H_			//���̃}�N����`������Ȃ�������
#define _PLAYER_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "object.h"
#include <list>

//*****************************************************************************
// �O���錾
//*****************************************************************************
class C3DObject;

//*****************************************************************************
// �N���X��`
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


	void SetModelIndex(int* pModelIndex) { m_pModelIndex = pModelIndex; }
	void SetModelIndexMax(int nModelIndexMax) { m_nModelIndexMax = nModelIndexMax; }

private:
	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3 m_Rot;
	float m_MoveMagnification;
	int m_nModelNum;
	int* m_pModelIndex;
	int m_nModelIndexMax;
	C3DObject* m_p3DObject;
	float m_fSize;
	std::list<C3DObject*> m_BallastList;
};

#endif