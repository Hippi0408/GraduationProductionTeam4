//==============================================================================================
//
// ƒ}ƒbƒv			map.h
// tutida ryousei
//
//==============================================================================================
#ifndef _MAP_H_
#define _MAP_H_

class CRestraint_Switch;

class CMap
{
public:
	CMap();
	~CMap();

	void ReadMap(char *filename);

	CRestraint_Switch *GetRestraint_Switch(int index) { return Restraint_Switch[index]; }

private:
	CRestraint_Switch *Restraint_Switch[4];
};

#endif // !_MAP_H_
