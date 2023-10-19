//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//Pointer.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#ifndef _POINTER_H_
#define _POINTER_H_

#include "object.h"

class CParticleEmitter;
class CModel;

class CPointer : public CObject
{
public:
	//--------------------------------------
	// モデルデータの構造体
	//--------------------------------------
	struct SModelData
	{
		LPD3DXMESH mesh;						// メッシュ情報
		LPD3DXBUFFER buffMat;					// マテリアル情報
		DWORD dwNum;							// マテリアルの個数
		D3DXVECTOR3 maxModel;					// モデルの最大値
		D3DXVECTOR3 minModel;					// モデルの最小値
	};

	CPointer();
	~CPointer() override;

	static CPointer *Create(D3DXVECTOR3 pos);
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void Movement();
	void LoadModel(std::string path);
	void BindTexture(std::string inPath);
	void Destroy() override { m_isRelease = true; }
	void Invisible() { m_bVisible = false; }
	void Visible() { m_bVisible = true; }

	void SetPos(D3DXVECTOR3 pos) override { m_objpos = pos; }
	void SetRotDest(D3DXVECTOR3 rot) { m_rotDest = rot; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }

	D3DXVECTOR3 GetPos() override { return m_objpos; }
	D3DXVECTOR3 GetPosOld() { return m_posOld; }
	D3DXVECTOR3 GetMove() { return m_move; }
	D3DXVECTOR3 GetRot() { return m_rot; }
	D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	D3DXVECTOR3 GetVec() { return m_vec; }
	D3DXMATRIX GetMatrix() { return m_mtxWorld; }
	bool GetVisible() { return m_bVisible; }
	bool GetDestroy() override { return m_isRelease; }

	CParticleEmitter *GetEmitter() { return m_pParticleEmitter; }

private:
	LPDIRECT3DTEXTURE9 m_pTexture;			// テクスチャ

	D3DXVECTOR3 m_objpos;					// 位置
	D3DXVECTOR3 m_posOld;					// 前回の位置
	D3DXVECTOR3 m_move;						// プレイヤーの移動量
	D3DXVECTOR3 m_rot;						// 向き
	D3DXVECTOR3 m_rotDest;					// 目的の向き
	D3DXVECTOR3 m_scale;
	D3DXVECTOR3 m_vec;						// プレイヤーの向きのベクトル
	D3DXMATRIX m_mtxWorld;					// ワールドマトリックス
	std::vector<SModelData> m_modelData;
	CParticleEmitter *m_pParticleEmitter;
	float m_fSpeed;

	bool m_bVisible;
	bool m_isRelease;						// オブジェクトの死亡フラグ
};

#endif