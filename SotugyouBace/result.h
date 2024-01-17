//==============================================================================================
//
// リザルト　　　result.h
// tutida ryousei
// tanimoto kosuke
// Saito shian
//
//==============================================================================================
#ifndef _RESULT_H_
#define	_RESULT_H_

//==============================================================================================
// インクルード
//==============================================================================================
#include"mode.h"

//==============================================================================================
// 前方宣言
//==============================================================================================
class CHalfSphere;
class CObjectX;
class CPlayerManager;
class CPlayer_Parameter;
class CWeapon_Parameter;
class CObject2D;
class CParts;
class CFontString;
class CScore;

//==============================================================================================
// リザルトクラス
//==============================================================================================
class CResult : public CMode
{
	const float SizeXScaleSpeed = 26.8f;			// xサイズ拡大縮小スピード
	const float SizeYScaleSpeed = 22.5f;			// yサイズ拡大縮小スピード
public:

	CResult();										// コンストラクタ
	~CResult();										// デストラクタ

	HRESULT Init() override;						// 初期化処理
	void Uninit() override;							// 終了処理
	void Update() override;							// 更新処理

	void SkillType();								// スキルの種類処理
	void ScaleExpansion();							// サイズ拡大処理
	void InformationUninit();						// 情報の破棄
			
	static CResult* Create();						// 生成処理
	static CPlayer_Parameter *GetPlayerParameter() { return m_pPlayerParameter; }	// プレイヤーパラメータ取得処理
	static CPlayerManager* GetPlayerManager() { return m_pPlayerManager; }

private:
	static CPlayer_Parameter *m_pPlayerParameter;	// プレイヤーパラメーター
	static CPlayerManager* m_pPlayerManager;		// プレイヤーマネージャー
	CWeapon_Parameter *m_pWeaponParameter;			// 武器パラメーター
	CParts* m_pParts[3];							// パーツ
	CHalfSphere* m_pHalfSphere;						// ハーフスフィア
	CObject2D* m_pObject2D;							// オブジェクト2D
	CFontString* m_pFont[3];						// フォント
	CScore* m_pScore;								// スコア
	D3DXVECTOR3 m_pos;								// 位置
	D3DXVECTOR3 m_move;								// 移動量
	D3DXVECTOR2 m_size;								// サイズ
	int m_Index;									// プレイヤー番号
	int m_MoveCount;								// 移動時間
	int m_PlayerIndex;								// プレイヤーの番号
	bool m_bGetFlag;								// 取得フラグ
	bool m_bCreateFlag;								// 生成フラグ
};

#endif // !_GAME_H_
