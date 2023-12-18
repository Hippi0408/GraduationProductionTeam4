//==============================================================================================
//
// �S���X�C�b�`�@�@�@restraint_switch.h
// tutida ryousei
//
//==============================================================================================
#ifndef _RESTRAINT_SWITCH_H_
#define	_RESTRAINT_SWITCH_H_

#include"move_object.h"

class CRestraint_Switch : public CMove_Object
{
public:
	CRestraint_Switch(const PRIORITY priority);
	~CRestraint_Switch();

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void Hit(CMove_Object* pHit) override;

	static CRestraint_Switch *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, CObjectX* parent, const char* Xfilename, const PRIORITY priority = PRIORITY_MODEL);

	bool GetHit() { return m_bHit; }
	int GetCountSwitch() { return m_nCount_Switch; }

	void SetHit(bool hit) { m_bHit = hit; }
	void AddCountSwitch() { m_nCount_Switch++; m_bPush = true; }

private:
	static int m_nCount_Switch;		// �����ꂽ�X�C�b�`�̐�
	bool m_bPush;
	bool m_bHit;
};

#endif // !_RESTRAINT_SWITCH_H_
