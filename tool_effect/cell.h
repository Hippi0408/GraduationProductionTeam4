#ifndef _CELL_H_
#define _CELL_H_

class CObject;

class CCell
{
public:
	CCell() { ; }
	~CCell() { ; }

	void AddObject(CObject* object) { m_pObj.push_back(object); }
	void RemoveObject(CObject* object)
	{
		for (auto it = m_pObj.begin(); it != m_pObj.end(); it++)
		{
			if (*it == object)
			{
				m_pObj.erase(it);
				break;
			}
		}
	}

	std::vector<CObject*> GetMyObject() { return m_pObj; }

private:
	std::vector<CObject*> m_pObj;
};

#endif