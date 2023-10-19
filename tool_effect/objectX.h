//����������������������������������������
//ObjectX.h
//����������������������������������������
#ifndef _OBJECTX_H_
#define _OBJECTX_H_

#include "object.h"
#include "texture.h"

class CObjectX : public CObject
{
public:
	explicit CObjectX(int nPriority = CObject::PRIORITY_THIRD);
	~CObjectX() override;

	static CObjectX *Create(D3DXVECTOR3 pos, std::string str);	// ��������

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void LoadModel(std::string path);
	void BindTexture(std::string inPath);
	void Destroy() { m_isRelease = true; }

	//�Z�b�^�[
	void SetPos(D3DXVECTOR3 pos) override { m_objpos = pos; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }
	void SetScale(D3DXVECTOR3 scale) { m_scale = scale; }
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }
	void SetMtxWorld(D3DXMATRIX mtx) { m_mtxWorld = mtx; }
	void SetCol(D3DXCOLOR col) { m_col = col; }

	//�Q�b�^�[
	D3DXVECTOR3 GetPos() override { return m_objpos; }
	D3DXVECTOR3 GetMove() { return m_move; }
	D3DXVECTOR3 GetScale() { return m_scale; }
	D3DXVECTOR3 GetRot() { return m_rot; }
	D3DXVECTOR3 GetMaxModel() { return m_maxModel; }
	D3DXVECTOR3 GetMinModel() { return m_minModel; }
	D3DXMATRIX GetMtxWorld() { return m_mtxWorld; }
	D3DXCOLOR GetCol() { return m_col; }
	bool GetDestroy() override { return m_isRelease; }

private:
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;
	LPD3DXBUFFER m_buffMat;
	LPD3DXMESH m_mesh;
	DWORD m_dwNum;

	LPDIRECT3DTEXTURE9 m_pTexture;
	D3DXVECTOR3 m_objpos;
	D3DXVECTOR3 m_move;
	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_scale;
	D3DXVECTOR3 m_maxModel;
	D3DXVECTOR3 m_minModel;
	D3DXCOLOR m_col;
	D3DXMATRIX m_mtxWorld;
	bool m_isRelease;
};

#endif