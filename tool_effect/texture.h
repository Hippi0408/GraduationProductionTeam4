//**************************************************
// 
// texture.h
// Author  : katsuki mizuki
// Author  : Yuda Kaito
// 
//**************************************************
#ifndef _TEXTURE_H_	//このマクロ定義がされてなかったら
#define _TEXTURE_H_	//２重インクルード防止のマクロ定義

//==================================================
// インクルード
//==================================================
#include <d3dx9.h>
#include <vector>
#include <map>
#include <string>

//==================================================
// 定義
//==================================================
class CTexture
{
public:
	CTexture();		// デフォルトコンストラクタ
	~CTexture();	// デストラクタ

public:
	void LoadAll();											// 全ての読み込み
	void UnloadAll();										// 全ての破棄
	void Load(std::string inKey, std::string inFileName, int index = 0);	// 指定の読み込み
	void Load(std::vector<std::string> inTexture, int index = 0);			// 指定の読み込み
	void Unload(std::string inKey);	// 指定の破棄

	void GetFilePath(std::string& folder, std::vector<std::string>& file);
	std::map<std::string, std::string, std::less<>> GetTexturePath() { return m_texturePath; }

	LPDIRECT3DTEXTURE9 GetTexture(std::string inKey, int index = 0);		// 情報の取得
	LPDIRECT3DTEXTURE9 ConfirmLoadedPath(std::string path);	// 読み込んだパスの確認

private: /* プライベート関数 */
	bool ExistsPath(std::string inKey) { return m_texturePath.count(inKey) != 0; }	// Map内に指定されたKeyが存在するか否か
	bool ExistsKey(std::string inKey) { return m_texture.count(inKey) != 0; }	// Map内に指定されたKeyが存在するか否か

private: /* メンバ変数 */
	std::vector<std::string> m_texPath;

	std::map<std::string, std::string, std::less<>> m_texturePath;		// テクスチャのパス
	std::map<std::string, LPDIRECT3DTEXTURE9, std::less<>> m_texture;	// テクスチャの情報
};

#endif // !_TEXTURE_H_
