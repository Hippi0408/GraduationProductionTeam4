//=============================================================================
//
// player.h
// Author : Tanimoto Kosuke
//
//=============================================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "character.h"

//---------------------------
// クラス宣言
//---------------------------
class CPlayer : public CCharacter
{
public:

	// モデルの配置情報
	enum Model
	{
		MODEL_BODY = 0,
		MODEL_MAX,
	};

	// モーションのタイプ
	enum MOTION_TYPE
	{
		MOTION_NEUTRAL = 0,	// ニュートラル
		MOTION_WALK,			// 歩き
		MOTION_MAX,
	};

	CPlayer();
	virtual ~CPlayer() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;

	void ChangeMotion() override;		// モーションの切り替え

	void SetCharaIndex(const int index) { m_nCharaIndex = index; }

	const int GetCharaIndex() { return m_nCharaIndex; }

private:
	int m_nCharaIndex;					// 自身の番号
};

#endif// _PLAYER_H_