//==============================================================================================
//
// ƒ}ƒbƒv			map.h
// tutida ryousei
//
//==============================================================================================
#ifndef _MAP_H_
#define _MAP_H_

class CRestraint_Switch;
class CCannon;

class CMap
{
public:
	CMap();
	~CMap();

	void ReadMap(char *filename);

	CRestraint_Switch *GetRestraint_Switch(int index) { return m_pRestraint_Switch[index]; }

private:
	CRestraint_Switch *m_pRestraint_Switch[4];
};

#endif // !_MAP_H_
