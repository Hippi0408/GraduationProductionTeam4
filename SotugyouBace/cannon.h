//==============================================================================================
//
// ñCë‰	Å@Å@cannon.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _CANNON_H_
#define	_CANNON_H_

#include"move_object.h"

class CCannon : public CMove_Object
{
public:
	CCannon(CObject::PRIORITY priority);
	~CCannon();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void Hit(CMove_Object* pHit) override;

	static CCannon *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, CObjectX* parent, const char* Xfilename, int index, const PRIORITY priority = PRIORITY_MODEL);

private:
	int m_nIndex;
	bool m_bTarget;
	float m_fRot;
};

#endif // !_CANNON_H_
