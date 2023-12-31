//**********************************************************************************************
// 
// texture.cpp
// Author  : tanimoto kosuke
// 
//**********************************************************************************************

//==============================================================================================
// インクルード
//==============================================================================================
#include "application.h"
#include "texture.h"
#include "renderer.h"

#include <assert.h>

//==============================================================================================
// 定義
//==============================================================================================
const char* CTexture::s_FileName[] =
{// テクスチャのパス

	"Data/texture/Font/Font_Japanese002.png",		// 日本語フォント
	"Data/texture/Font/Font_Japanese003.png",		// 日本語フォント
	"Data/texture/Font/Font_Alphabet.png",			// アルファベットフォント
	"Data/texture/number.png",						// ナンバーのテクスチャ
	"Data/texture/bullet000.png",					// 弾のテクスチャ
	"Data/texture/floor.png",						// 地面のテクスチャ
	"Data/texture/reticle.png",						// レティクルのテクスチャ
	"Data/texture/circle.png",						// 円のテクスチャ
	"Data/texture/ItemPointer.png",					// アイテムポインターのテクスチャ
	"Data/texture/UI_00.png",						// UIのテクスチャ
	"Data/texture/Ekey.png",						// Eキーのテクスチャ

	/* タイトルロゴ */
	"Data/texture/Title/logo/title_00.png",
	"Data/texture/Title/logo/title_01.png",
	"Data/texture/Title/logo/title_02.png",
	"Data/texture/Title/logo/title_03.png",
	"Data/texture/Title/logo/title_04.png",
	"Data/texture/Title/logo/title_05.png",
	"Data/texture/Title/logo/title_06.png",
	"Data/texture/Title/logo/title_07.png",
	"Data/texture/Title/logo/title_08.png",
	"Data/texture/Title/logo/title_robot.png",

	/* タイトル歯車　*/
	"Data/texture/Title/gear/gear_00.png",
	"Data/texture/Title/gear/gear_01.png",
	"Data/texture/Title/gear/gear_02.png",
	"Data/texture/Title/gear/gear_03.png",
	"Data/texture/Title/gear/gear_04.png",
	"Data/texture/Title/gear/gear_05.png",
	"Data/texture/Title/gear/gear_06.png",
	
	/* エフェクト群 */
	"Data/texture/particle/smoke.png",				// 煙
	"Data/texture/particle/flare.png",				// エフェクト1
	"Data/texture/particle/star.png",				// エフェクト2
	"Data/texture/particle/bright.png",				// キラキラA
	"Data/texture/particle/bright2.png",			// キラキラB
	"Data/texture/particle/ray.png",				// レイ
	"Data/texture/particle/coin.png",				// コイン
	"Data/texture/particle/jewel.png",				// パーティクル用宝石
	"Data/texture/particle/soul.png",				// 魂
	"Data/texture/particle/up.png",					// 上矢印
	"Data/texture/reticle.png",						// レティクル
	"Data/texture/chain.png",						// チェーン

	"Data/texture/Weapon/Knuckle_icon.png",			// 素手アイコン
	"Data/texture/Weapon/Slash_icon.png",			// スラッシュアイコン

	"Data/texture/WeaponSkill/WeaponSkill_Knuckle.png",	// 素手のアタックスキルアイコン
	"Data/texture/WeaponSkill/WeaponSkill_Slash.png",	// スラッシュのアタックスキルアイコン

	"Data/texture/job/job_Rush.png",				// ラッシュ
	"Data/texture/job/job_Vanguard.png",			// ヴァンガード
	"Data/texture/job/job_Eagleeye.png",			// イーグルアイ
	"Data/texture/job/job_Marshall.png",			// マーシャル
	"Data/texture/job/job_Mechanic.png",			// メカニック
	"Data/texture/job/job_Raider.png",				// レイダー
	"Data/texture/job/job_Arcphilia.png",			// アークフィリア
	"Data/texture/job/job_Control.png",				// コントロール

	"Data/texture/job/JobSelect_Rush.png",				// ラッシュ
	"Data/texture/job/JobSelect_Vanguard.png",			// ヴァンガード
	"Data/texture/job/JobSelect_Eagleeye.png",			// イーグルアイ
	"Data/texture/job/JobSelect_Marshall.png",			// マーシャル
	"Data/texture/job/JobSelect_Mechanic.png",			// メカニック
	"Data/texture/job/JobSelect_Raider.png",			// レイダー
	"Data/texture/job/JobSelect_Arcphilia.png",			// アークフィリア
	"Data/texture/job/JobSelect_Control.png",			// コントロール

};

static_assert(sizeof(CTexture::s_FileName) / sizeof(CTexture::s_FileName[0]) == CTexture::TEXTURE_MAX, "aho");

//----------------------------------------------------------------------------------------------
// デフォルトコンストラクタ
//----------------------------------------------------------------------------------------------
CTexture::CTexture() :
	s_pTexture()
{
	memset(s_pTexture, 0, sizeof(s_pTexture));
}

//----------------------------------------------------------------------------------------------
// デストラクタ
//----------------------------------------------------------------------------------------------
CTexture::~CTexture()
{
}

//----------------------------------------------------------------------------------------------
// 全ての読み込み
//----------------------------------------------------------------------------------------------
void CTexture::LoadAll()
{
	// デバイスへのポインタの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	for (int i = 0; i < TEXTURE_MAX; ++i)
	{
		if (s_pTexture[i] != nullptr)
		{// テクスチャの読み込みがされている
			continue;
		}

		// テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice,
			s_FileName[i],
			&s_pTexture[i]);
	}
}

//----------------------------------------------------------------------------------------------
// 全ての解放
//----------------------------------------------------------------------------------------------
void CTexture::ReleaseAll(void)
{
	for (int i = 0; i < TEXTURE_MAX; ++i)
	{
		if (s_pTexture[i] != NULL)
		{// テクスチャの解放
			s_pTexture[i]->Release();
			s_pTexture[i] = NULL;
		}
	}
}

//----------------------------------------------------------------------------------------------
// 解放
//----------------------------------------------------------------------------------------------
void CTexture::Release(TEXTURE inTexture)
{
	assert(inTexture >= 0 && inTexture < TEXTURE_MAX);

	if (s_pTexture[inTexture] != NULL)
	{// テクスチャの解放
		s_pTexture[inTexture]->Release();
		s_pTexture[inTexture] = NULL;
	}
}

//----------------------------------------------------------------------------------------------
// 取得
//----------------------------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(TEXTURE inTexture)
{
	if (inTexture == TEXTURE_NONE)
	{// テクスチャを使用しない
		return nullptr;
	}

	assert(inTexture >= 0 && inTexture < TEXTURE_MAX);

	return s_pTexture[inTexture];
}
