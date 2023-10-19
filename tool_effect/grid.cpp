#include "grid.h"
#include "cell.h"
#include "object.h"
#include "utility.h"

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// グリッドのコンストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CGrid::CGrid(SGridData cell) : m_gridData(cell)
{
	// セルの配列の初期化
	int numCellsX = cell.gridSizeX / cell.cellSize;
	int numCellsY = cell.gridSizeY / cell.cellSize;
	int numCellsZ = cell.gridSizeZ / cell.cellSize;

	cell.cellIndexX = numCellsX;
	cell.cellIndexY = numCellsY;
	cell.cellIndexZ = numCellsZ;

	m_gridData = cell;

	m_cells.resize(numCellsX, std::vector<std::vector<CCell>>(numCellsY, std::vector<CCell>(numCellsZ)));
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// グリッドのデストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CGrid::~CGrid()
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// オブジェクトをセルに配置する処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CGrid::PlaceObject(CObject* obj)
{
	// オブジェクトの位置からセルのインデックスを計算
	int cellX = static_cast<int>(obj->GetPos().x / m_gridData.cellSize);
	int cellY = static_cast<int>(obj->GetPos().y / m_gridData.cellSize);
	int cellZ = static_cast<int>(obj->GetPos().z / m_gridData.cellSize);

	// インデックスが範囲外の場合範囲内に収める
	cellX = utility::Clamp(cellX, 0, m_gridData.cellIndexX - 1);
	cellY = utility::Clamp(cellY, 0, m_gridData.cellIndexY - 1);
	cellZ = utility::Clamp(cellZ, 0, m_gridData.cellIndexZ - 1);

	// オブジェクトを適切なセルに追加
	bool check = (cellX < 0 || cellY < 0 || cellZ < 0 || cellX >= m_gridData.cellIndexX || cellY >= m_gridData.cellIndexY || cellZ >= m_gridData.cellIndexZ);
	if (!check)
	{
		m_cells[cellX][cellY][cellZ].AddObject(obj);

		// セルのインデックスをキャッシュ
		SCache cache = {};
		cache.cacheIndexX = cellX;
		cache.cacheIndexY = cellY;
		cache.cacheIndexZ = cellZ;
		obj->SetGridCache(cache);
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// セルに配置したオブジェクトを削除する処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CGrid::RemoveObject(CObject* obj)
{
	SCache cache = obj->GetGridCache();
	int cellX = cache.cacheIndexX;
	int cellY = cache.cacheIndexY;
	int cellZ = cache.cacheIndexZ;

	// オブジェクトをセルから削除
	m_cells[cellX][cellY][cellZ].RemoveObject(obj);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 全てのセル情報を削除する処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CGrid::ClearObject()
{
	m_cells.clear();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 指定したオブジェクトが別のセルに移動したかチェックする処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
bool CGrid::CheckGridChange(CObject* obj)
{
	int cellX = static_cast<int>(obj->GetPos().x / m_gridData.cellSize);
	int cellY = static_cast<int>(obj->GetPos().y / m_gridData.cellSize);
	int cellZ = static_cast<int>(obj->GetPos().z / m_gridData.cellSize);

	SCache cache = obj->GetGridCache();
	int currentX = cache.cacheIndexX;
	int currentY = cache.cacheIndexY;
	int currentZ = cache.cacheIndexZ;

	return (cellX != currentX || cellY != currentY || cellZ != currentZ);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 指定したオブジェクトの位置のセルを取得する処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
std::vector<CObject*> CGrid::GetCellsAtPosition(D3DXVECTOR3 pos)
{
	std::vector<CObject*> overlappObjects;

	// セルのインデックス位置を補正
	float adjustedX = pos.x + m_gridData.cellSize / 2.0f;
	float adjustedY = pos.y + m_gridData.cellSize / 2.0f;
	float adjustedZ = pos.z + m_gridData.cellSize / 2.0f;

	// 位置からセルのインデックスを計算
	int cellX = static_cast<int>(adjustedX / m_gridData.cellSize);
	int cellY = static_cast<int>(adjustedY / m_gridData.cellSize);
	int cellZ = static_cast<int>(adjustedZ / m_gridData.cellSize);

	// セルが範囲外の場合は空のオブジェクトリストを返す
	if (cellX < 0 || cellX >= m_gridData.cellIndexX ||
		cellY < 0 || cellY >= m_gridData.cellIndexY ||
		cellZ < 0 || cellZ >= m_gridData.cellIndexZ)
	{
		return overlappObjects;
	}

	// セル内のオブジェクトを取得
	overlappObjects = m_cells[cellX][cellY][cellZ].GetMyObject();

	return overlappObjects;
}