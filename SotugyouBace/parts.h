//=============================================================================
//
// parts.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _PARTS_H_
#define _PARTS_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "object.h"
#include "objectX.h"
#include "motion.h"
#include "parts_file.h"

class CCharacter;

//---------------------------
// クラス宣言
//---------------------------
class CParts : public CObject
{
	//// モデルセット
	//struct MODEL_SET
	//{
	//	D3DXVECTOR3 InitPos;	// 初期位置
	//	D3DXVECTOR3 InitRot;	// 初期回転
	//	CObjectX* pModel;		// モデル
	//	bool bParentIndex;		// 親モデルの判定
	//};

public:

	CParts(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CParts() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Motion();							// モーションの設定
	void ChangeMotion();					// モーションの切り替え
	void Rotation();								// 回転方向へ振り向かせる処理
	void NormalizeRot();							// 角度の正規化

	void SetMotion(const int motion) { m_nMotion = motion; }
	void SetCurrentMotion(const int motion) { m_nCurrentMotion = motion; }
	
	void AddPos(const D3DXVECTOR3 pos) { m_pos += pos; }				// 位置の加算
	void SetPos(const D3DXVECTOR3 pos) { m_pos = pos; }					// 位置の設定
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetRotDest(const D3DXVECTOR3 rot) { m_rotDest = rot; }
	void AddRotDest(const D3DXVECTOR3 rot) { m_rotDest += rot; }

	void SetParts(const int partsIndex);
	void SetParent(CCharacter* parent) { m_pParent = parent; }
	void SetModelParent(CObjectX* parts, const bool parent = false);
	//void ChangeParts(const int index);

	const bool GetMotionStop() { return m_bMotionStop; }	// 現在モーションの終了判定を読み込む
	const int GetMotion() { return m_nMotion; }
	const int GetCurrentMotion() { return m_nCurrentMotion; }
	const D3DXVECTOR3 GetPos() { return m_pos; }						// 位置の取得
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	//MODEL_SET GetModelSet(const int index) { return m_ModelSet[index]; }
	CObjectX* GetModel(const int index) { return m_vpModel[index]; }
	std::vector<CObjectX*> GetModelAll() { return m_vpModel; }	// 全てのモデルの取得処理

	static CParts* Create(const D3DXVECTOR3 pos, const int partsIndex, CCharacter* parent = nullptr);

private:
	int m_nPartsIndex;					// 自身の番号

	D3DXMATRIX m_mtxWorld;				// ワールドマトリックス
	D3DXVECTOR3 m_pos;					// 位置
	D3DXVECTOR3 m_posOld;				// 過去の位置
	D3DXVECTOR3 m_rot;					// 現在の角度
	D3DXVECTOR3 m_rotDest;				// 目的の角度

	D3DXCOLOR m_col;					// モデルの色

	bool m_bMotionStop;					// 現在のモーションが止まったか
	int m_nMotion;						// モーション
	int m_nCurrentMotion;				// 現在のモーション番号
	int m_nCountMotion;					// モーションカウンター
	int m_nCurrentKey;					// 現在のキー番号

	float m_fRotSpeed;					// 回転のスピード

	std::vector<CObjectX*> m_vpModel;	// モデル
	//std::vector<MODEL_SET> m_ModelSet;	// キャラクターのモデル情報

	CCharacter* m_pParent;				// 自身の親キャラのポインタ
};

#endif// _PARTS_H_