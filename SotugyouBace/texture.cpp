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
	"Data/texture/Font/Font_Japanese002.png",			// 日本語フォント
	"Data/texture/Font/Font_Japanese003.png",	// 日本語フォント
	"Data/texture/Font/Font_Alphabet.png",				// アルファベットフォントフォント
	"Data/texture/number.png",						// ナンバーのテクスチャ
	"Data/texture/bullet000.png",					// 弾のテクスチャ
	"Data/texture/floor.png",						// 地面のテクスチャ
	"Data/texture/reticle.png",						// レティクルのテクスチャ
	"Data/texture/circle.png",						// 円のテクスチャ
	"Data/texture/UI_00.png",						// UIのテクスチャ

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
