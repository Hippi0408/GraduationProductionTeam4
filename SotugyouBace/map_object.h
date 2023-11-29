//==============================================================================================
//
// マップのオブジェクト　　　map_object.h
// Author : tutida ryousei
//
//==============================================================================================
#ifndef _MAP_OBJECT_H_
#define	_MAP_OBJECT_H_

#include"move_object.h"

class CMap_Object : public CMove_Object
{
public:
	CMap_Object(const PRIORITY priority);
	~CMap_Object();

private:

};

#endif // !_MAP_OBJECT_H_
