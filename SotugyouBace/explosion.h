//==============================================================================================
//
// ”š”­ 		explosion.h
// tutida ryousei
//
//==============================================================================================
#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

#include"move_object.h"

class CExplosion : public CMove_Object
{
public:
	CExplosion(const PRIORITY priority);
	~CExplosion();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	void Hit(CMove_Object* pHit) override;

	static CExplosion *Create(D3DXVECTOR3 pos, float radius, int power, const bool side, const CObject::PRIORITY priority);

	const int GetPower() override { return m_nPower; }		// ˆÐ—Í‚ÌŽæ“¾

private:
	int m_nPower;
	int m_nContinuation;
	bool m_bHit;
};

#endif // !_EXPLOSION_H_
