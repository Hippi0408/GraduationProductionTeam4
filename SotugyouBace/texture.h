//**********************************************************************************************
// 
// texture.h
// Author  : tanimoto kosuke
// 
//**********************************************************************************************
#ifndef _TEXTURE_H_	//このマクロ定義がされてなかったら
#define _TEXTURE_H_	//２重インクルード防止のマクロ定義

//==============================================================================================
// インクルード
//==============================================================================================
#include <d3dx9.h>

//==============================================================================================
// 定義
//==============================================================================================
class CTexture
{
public: /* 定義 */
	enum TEXTURE
	{
		TEXTURE_FONT_JAPANESE,		// 日本語フォント
		TEXTURE_FONT_JAPANESE_VER2,	// 日本語フォント
		TEXTURE_FONT_ALPHABET,		// アルファベットフォント
		TEXTURE_NUMBER,				// ナンバー
		TEXTURE_BULLET,				// 弾
		TEXTURE_FLOOR,				// 地面
		TEXTURE_RETICLE,			// レティクル
		TEXTURE_CIRCLE,				// 円
		TEXTURE_ITEM_POINTER,		// アイテムポインター
		TEXTURE_UI,					// UI
		TEXTURE_KEY_E,				// Eキー

		/* タイトルロゴ */
		TEXTURE_TITLE_00,
		TEXTURE_TITLE_01,
		TEXTURE_TITLE_02,
		TEXTURE_TITLE_03,
		TEXTURE_TITLE_04,
		TEXTURE_TITLE_05,
		TEXTURE_TITLE_06,
		TEXTURE_TITLE_07,
		TEXTURE_TITLE_08,
		TEXTURE_TITLE_ROBOT,

		/* タイトル歯車*/
		TEXTURE_TITLE_GEAR_00,
		TEXTURE_TITLE_GEAR_01,
		TEXTURE_TITLE_GEAR_02,
		TEXTURE_TITLE_GEAR_03,
		TEXTURE_TITLE_GEAR_04,
		TEXTURE_TITLE_GEAR_05,
		TEXTURE_TITLE_GEAR_06,

		/* エフェクト群 */
		TEXTURE_EFFECT_SMOKE,
		TEXTURE_EFFECT_FLARE,
		TEXTURE_EFFECT_STAR,
		TEXTURE_EFFECT_BRIGHTA,
		TEXTURE_EFFECT_BRIGHTB,
		TEXTURE_EFFECT_RAY,
		TEXTURE_EFFECT_SHOCK,
		TEXTURE_EFFECT_JEWEL,
		TEXTURE_EFFECT_SOUL,
		TEXTURE_EFFECT_UP,
		TEXTURE_EFFECT_RETICLE,
		TEXTURE_CHAIN,

		/* 武器 */
		TEXTURE_WEAPON_KNUCKLE,			// 素手アイコン
		TEXTURE_WEAPON_SLASH,			// スラッシュアイコン

		/* アタックスキル */
		TEXTURE_ATTACK_SKILL_KNUCKLE,	// 素手のアタックスキルアイコン
		TEXTURE_ATTACK_SKILL_SLASH,		// スラッシュのアタックスキルアイコン

		/* サポートスキル */
		TEXTURE_SKILL_RUSH,				// ラッシュ
		TEXTURE_SKILL_VANGUARD,			// ヴァンガード
		TEXTURE_SKILL_EAGLEEYE,			// イーグルアイ
		TEXTURE_SKILL_MARSHALL,			// マーシャル
		TEXTURE_SKILL_MECHANIC,			// メカニック
		TEXTURE_SKILL_RAIDER,			// レイダー
		TEXTURE_SKILL_ARCPHILIA,		// アークフィリア
		TEXTURE_SKILL_CONTROL,			// コントロール

		/* サポートスキル説明 */
		TEXTURE_SKILLEXPLANATION_RUSH,				// ラッシュ説明
		TEXTURE_SKILLEXPLANATION_VANGUARD,			// ヴァンガード説明
		TEXTURE_SKILLEXPLANATION_EAGLEEYE,			// イーグルアイ説明
		TEXTURE_SKILLEXPLANATION_MARSHALL,			// マーシャル説明
		TEXTURE_SKILLEXPLANATION_MECHANIC,			// メカニック説明
		TEXTURE_SKILLEXPLANATION_RAIDER,			// レイダー説明
		TEXTURE_SKILLEXPLANATION_ARCPHILIA,			// アークフィリア説明
		TEXTURE_SKILLEXPLANATION_CONTROL,			// コントロール説明

		TEXTURE_MAX,
		TEXTURE_NONE
	};

	static const char* s_FileName[];	// ファイルパス

public:
	CTexture();		// デフォルトコンストラクタ
	~CTexture();	// デストラクタ

public: /* メンバ関数 */
	void LoadAll();										// 全ての読み込み
	void ReleaseAll();									// 全ての破棄
	void Release(TEXTURE inTexture);					// 指定の破棄
	LPDIRECT3DTEXTURE9 GetTexture(TEXTURE inTexture);	// 情報の取得

private: /* メンバ変数 */
	LPDIRECT3DTEXTURE9 s_pTexture[TEXTURE_MAX];			// テクスチャの情報
};

#endif // !_TEXTURE_H_
