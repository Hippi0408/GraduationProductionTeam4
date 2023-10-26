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
#include"move_object.h"
#include "objectX.h"
#include "character.h"
#include "motion.h"
#include <vector>
#include <map>

//---------------------------
// クラス宣言
//---------------------------
class CParts : public CMove_Object
{
	// モデルセット
	struct MODEL_SET
	{
		D3DXVECTOR3 InitPos;	// 初期位置
		D3DXVECTOR3 InitRot;	// 初期回転
		CObjectX* pModel;		// モデル
		int nParentIndex;		// 親モデルの番号
	};

public:

	CParts(const CObject::PRIORITY priority = CObject::PRIORITY_MODEL);
	virtual ~CParts() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void Motion();							// モーションの設定
	virtual void ChangeMotion();			// モーションの切り替え
	void Rotation();								// 回転方向へ振り向かせる処理
	void NormalizeRot();							// 角度の正規化
	void Hit(CMove_Object* pHit) override;

	void SetMotion(const int motion) { m_nMotion = motion; }
	void SetCurrentMotion(const int motion) { m_nCurrentMotion = motion; }
	
	void SetRot(const D3DXVECTOR3 rot) { m_rot = rot; }
	void SetRotDest(const D3DXVECTOR3 rot) { m_rotDest = rot; }
	void AddRotDest(const D3DXVECTOR3 rot) { m_rotDest += rot; }

	CObjectX* SetModel(const int index, const int parent, const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, const char* Xfilename);		// モデルパーツの設定

	const bool GetMotionStop() { return m_bMotionStop; }	// 現在モーションの終了判定を読み込む
	const int GetMotion() { return m_nMotion; }
	const int GetCurrentMotion() { return m_nCurrentMotion; }
	const D3DXVECTOR3 GetRot() { return m_rot; }
	const D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	MODEL_SET GetModelSet(const int index) { return m_ModelSet[index]; }
	std::vector<CObjectX*> GetModelAll();

	static CParts* Create(const D3DXVECTOR3 pos, CMove_Object* parent, const bool side);

	void LoadFile(const char* Xfilename);

private:

	D3DXMATRIX m_mtxWorld;				// ワールドマトリックス
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

	std::string m_name;					// 自身の名前
	std::vector<MODEL_SET> m_ModelSet;	// キャラクターのモデル情報

	CCharacter* m_pParent;				// 自身の親キャラのポインタ
};

#endif// _PARTS_H_