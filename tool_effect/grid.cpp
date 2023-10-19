#include "grid.h"
#include "cell.h"
#include "object.h"
#include "utility.h"

//��������������������������������������������������������������
// �O���b�h�̃R���X�g���N�^
//��������������������������������������������������������������
CGrid::CGrid(SGridData cell) : m_gridData(cell)
{
	// �Z���̔z��̏�����
	int numCellsX = cell.gridSizeX / cell.cellSize;
	int numCellsY = cell.gridSizeY / cell.cellSize;
	int numCellsZ = cell.gridSizeZ / cell.cellSize;

	cell.cellIndexX = numCellsX;
	cell.cellIndexY = numCellsY;
	cell.cellIndexZ = numCellsZ;

	m_gridData = cell;

	m_cells.resize(numCellsX, std::vector<std::vector<CCell>>(numCellsY, std::vector<CCell>(numCellsZ)));
}

//��������������������������������������������������������������
// �O���b�h�̃f�X�g���N�^
//��������������������������������������������������������������
CGrid::~CGrid()
{
}

//��������������������������������������������������������������
// �I�u�W�F�N�g���Z���ɔz�u���鏈��
//��������������������������������������������������������������
void CGrid::PlaceObject(CObject* obj)
{
	// �I�u�W�F�N�g�̈ʒu����Z���̃C���f�b�N�X���v�Z
	int cellX = static_cast<int>(obj->GetPos().x / m_gridData.cellSize);
	int cellY = static_cast<int>(obj->GetPos().y / m_gridData.cellSize);
	int cellZ = static_cast<int>(obj->GetPos().z / m_gridData.cellSize);

	// �C���f�b�N�X���͈͊O�̏ꍇ�͈͓��Ɏ��߂�
	cellX = utility::Clamp(cellX, 0, m_gridData.cellIndexX - 1);
	cellY = utility::Clamp(cellY, 0, m_gridData.cellIndexY - 1);
	cellZ = utility::Clamp(cellZ, 0, m_gridData.cellIndexZ - 1);

	// �I�u�W�F�N�g��K�؂ȃZ���ɒǉ�
	bool check = (cellX < 0 || cellY < 0 || cellZ < 0 || cellX >= m_gridData.cellIndexX || cellY >= m_gridData.cellIndexY || cellZ >= m_gridData.cellIndexZ);
	if (!check)
	{
		m_cells[cellX][cellY][cellZ].AddObject(obj);

		// �Z���̃C���f�b�N�X���L���b�V��
		SCache cache = {};
		cache.cacheIndexX = cellX;
		cache.cacheIndexY = cellY;
		cache.cacheIndexZ = cellZ;
		obj->SetGridCache(cache);
	}
}

//��������������������������������������������������������������
// �Z���ɔz�u�����I�u�W�F�N�g���폜���鏈��
//��������������������������������������������������������������
void CGrid::RemoveObject(CObject* obj)
{
	SCache cache = obj->GetGridCache();
	int cellX = cache.cacheIndexX;
	int cellY = cache.cacheIndexY;
	int cellZ = cache.cacheIndexZ;

	// �I�u�W�F�N�g���Z������폜
	m_cells[cellX][cellY][cellZ].RemoveObject(obj);
}

//��������������������������������������������������������������
// �S�ẴZ�������폜���鏈��
//��������������������������������������������������������������
void CGrid::ClearObject()
{
	m_cells.clear();
}

//��������������������������������������������������������������
// �w�肵���I�u�W�F�N�g���ʂ̃Z���Ɉړ��������`�F�b�N���鏈��
//��������������������������������������������������������������
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

//��������������������������������������������������������������
// �w�肵���I�u�W�F�N�g�̈ʒu�̃Z�����擾���鏈��
//��������������������������������������������������������������
std::vector<CObject*> CGrid::GetCellsAtPosition(D3DXVECTOR3 pos)
{
	std::vector<CObject*> overlappObjects;

	// �Z���̃C���f�b�N�X�ʒu��␳
	float adjustedX = pos.x + m_gridData.cellSize / 2.0f;
	float adjustedY = pos.y + m_gridData.cellSize / 2.0f;
	float adjustedZ = pos.z + m_gridData.cellSize / 2.0f;

	// �ʒu����Z���̃C���f�b�N�X���v�Z
	int cellX = static_cast<int>(adjustedX / m_gridData.cellSize);
	int cellY = static_cast<int>(adjustedY / m_gridData.cellSize);
	int cellZ = static_cast<int>(adjustedZ / m_gridData.cellSize);

	// �Z�����͈͊O�̏ꍇ�͋�̃I�u�W�F�N�g���X�g��Ԃ�
	if (cellX < 0 || cellX >= m_gridData.cellIndexX ||
		cellY < 0 || cellY >= m_gridData.cellIndexY ||
		cellZ < 0 || cellZ >= m_gridData.cellIndexZ)
	{
		return overlappObjects;
	}

	// �Z�����̃I�u�W�F�N�g���擾
	overlappObjects = m_cells[cellX][cellY][cellZ].GetMyObject();

	return overlappObjects;
}