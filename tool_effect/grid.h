#ifndef _GRID_H_
#define _GRID_H_

class CCell;
class CObject;

class CGrid
{
public:
	struct SGridData
	{
		int cellIndexX;
		int cellIndexY;
		int cellIndexZ;
		int gridSizeX;		// 幅
		int gridSizeY;		// 高さ
		int gridSizeZ;		// 奥行き
		int cellSize;		// セルサイズ
	};

	struct SCache
	{
		int cacheIndexX;
		int cacheIndexY;
		int cacheIndexZ;
	};

	CGrid(SGridData cell);
	~CGrid();

	void PlaceObject(CObject* obj);
	void RemoveObject(CObject* obj);
	void ClearObject();
	bool CheckGridChange(CObject* obj);

	std::vector<CObject*> GetCellsAtPosition(D3DXVECTOR3 pos);

private:
	SGridData m_gridData;
	std::vector<std::vector<std::vector<CCell>>> m_cells;
};

#endif