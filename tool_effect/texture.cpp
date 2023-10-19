//**************************************************
// 
// texture.cpp
// Author  : katsuki mizuki
// Author  : Yuda Kaito
// 
//**************************************************

//==================================================
// インクルード
//==================================================
#include "application.h"
#include "renderer.h"
#include "texture.h"
#include "file.h"
#include "window.h"
#include <assert.h>

#include "utility.h"

//--------------------------------------------------
// デフォルトコンストラクタ
//--------------------------------------------------
CTexture::CTexture()
{
}

//--------------------------------------------------
// デストラクタ
//--------------------------------------------------
CTexture::~CTexture()
{
}

//--------------------------------------------------
// 全ての読み込み
//--------------------------------------------------
void CTexture::LoadAll()
{
	nlohmann::json list = CFile::LoadJsonStage(L"Data/FILE/texture.json");

	std::function<void()> func = [&]() {
		for (int i = 0; i < (int)list["TEXTURE"].size(); ++i)
		{
			m_texturePath.insert(std::make_pair(list["TEXTURE"].at(i)[0], list["TEXTURE"].at(i)[1]));
		}
	};

	long long execTime = utility::ExecutionTime(func);
}

//--------------------------------------------------
// 読み込み
//--------------------------------------------------
void CTexture::Load(std::string inKey, std::string inFileName, int index)
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	if (index == 0)
	{	// 親ウィンドウ
		pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	}
	else
	{	// 子ウィンドウ
		pDevice = CApplication::GetInstance()->GetChildWindow()->GetDevice();
	}

	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inFileName;

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, &fileName.front(), &texture);

	assert(texture != nullptr);	// テクスチャのURLがないかキーが間違ってる。

	if (!ExistsKey(inKey))
	{
		m_texture.insert(std::make_pair(inKey, texture));
	}
	else
	{
		m_texture[inKey] = texture;
	}
}

//--------------------------------------------------
// 読み込み
//--------------------------------------------------
void CTexture::Load(std::vector<std::string> inTexture, int index)
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	if (index == 0)
	{	// 親ウィンドウ
		pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	}
	else
	{	// 子ウィンドウ
		pDevice = CApplication::GetInstance()->GetChildWindow()->GetDevice();
	}

	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inTexture[1];

	// テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice, &fileName.front(), &texture);

	assert(texture != nullptr);	// テクスチャのURLがないかキーが間違ってる。

	if (!ExistsKey(inTexture[0]))
	{
		m_texture.insert(std::make_pair(inTexture[0], texture));
	}
	else
	{
		m_texture[inTexture[0]] = texture;
	}
}

//--------------------------------------------------
// 全ての解放
//--------------------------------------------------
void CTexture::UnloadAll()
{
	m_texture.clear();
}

//--------------------------------------------------
// 解放
//--------------------------------------------------
void CTexture::Unload(std::string inKey)
{
	m_texture.erase(inKey);
}

//--------------------------------------------------
// フォルダ自体のテクスチャパスを抽出
//--------------------------------------------------
void GetFilePath(std::string& folder, std::vector<std::string>& file)
{
	WIN32_FIND_DATA findData;
	HANDLE find = INVALID_HANDLE_VALUE;

	// フォルダの最初のファイルを検索
	std::string search = folder;
	find = FindFirstFile(search.c_str(), &findData);

	if (find != INVALID_HANDLE_VALUE)
	{
		do 
		{
			std::string filePath = folder + "\\" + findData.cFileName;

			// ファイルの属性がディレクトリではないかどうか
			if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				// ファイルの拡張子取得
				std::string ext = filePath.substr(filePath.find_last_of(".") + 1);

				// 拡張子が画像ファイルだった場合
				if (ext == "png" || ext == "jpg" || ext == "jpeg" || ext == "bmp")
				{
					file.push_back(filePath);
				}
			}

		} while (FindNextFile(find, &findData) != 0);

		// ハンドルをクローズ
		FindClose(find);
	}
}

//--------------------------------------------------
// 取得
//--------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(std::string inKey, int index)
{
	// Keyが存在するか否か。
	if (!ExistsPath(inKey))
	{
		// Keyがなかった場合
		return nullptr;
	}

	// Keyが存在するか否か。
	if (!ExistsKey(inKey))
	{
		Load(inKey, m_texturePath[inKey], index);
	}

	/* ↓Keyがあった場合↓ */

	return m_texture[inKey];
}

LPDIRECT3DTEXTURE9 CTexture::ConfirmLoadedPath(std::string path)
{
	for (auto &p : m_texturePath)
	{
		if (p.second == path)
		{
			return m_texture[p.first];
		}
	}

	//テクスチャの読み込み
	Load(path, path);
	m_texturePath.insert(std::make_pair(path, path));

	return m_texture[path];
}
