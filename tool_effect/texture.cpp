//**************************************************
// 
// texture.cpp
// Author  : katsuki mizuki
// Author  : Yuda Kaito
// 
//**************************************************

//==================================================
// �C���N���[�h
//==================================================
#include "application.h"
#include "renderer.h"
#include "texture.h"
#include "file.h"
#include "window.h"
#include <assert.h>

#include "utility.h"

//--------------------------------------------------
// �f�t�H���g�R���X�g���N�^
//--------------------------------------------------
CTexture::CTexture()
{
}

//--------------------------------------------------
// �f�X�g���N�^
//--------------------------------------------------
CTexture::~CTexture()
{
}

//--------------------------------------------------
// �S�Ă̓ǂݍ���
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
// �ǂݍ���
//--------------------------------------------------
void CTexture::Load(std::string inKey, std::string inFileName, int index)
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	if (index == 0)
	{	// �e�E�B���h�E
		pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	}
	else
	{	// �q�E�B���h�E
		pDevice = CApplication::GetInstance()->GetChildWindow()->GetDevice();
	}

	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inFileName;

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, &fileName.front(), &texture);

	assert(texture != nullptr);	// �e�N�X�`����URL���Ȃ����L�[���Ԉ���Ă�B

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
// �ǂݍ���
//--------------------------------------------------
void CTexture::Load(std::vector<std::string> inTexture, int index)
{
	LPDIRECT3DDEVICE9 pDevice = nullptr;
	if (index == 0)
	{	// �e�E�B���h�E
		pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	}
	else
	{	// �q�E�B���h�E
		pDevice = CApplication::GetInstance()->GetChildWindow()->GetDevice();
	}

	LPDIRECT3DTEXTURE9 texture = nullptr;
	std::string fileName = inTexture[1];

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, &fileName.front(), &texture);

	assert(texture != nullptr);	// �e�N�X�`����URL���Ȃ����L�[���Ԉ���Ă�B

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
// �S�Ẳ��
//--------------------------------------------------
void CTexture::UnloadAll()
{
	m_texture.clear();
}

//--------------------------------------------------
// ���
//--------------------------------------------------
void CTexture::Unload(std::string inKey)
{
	m_texture.erase(inKey);
}

//--------------------------------------------------
// �t�H���_���̂̃e�N�X�`���p�X�𒊏o
//--------------------------------------------------
void GetFilePath(std::string& folder, std::vector<std::string>& file)
{
	WIN32_FIND_DATA findData;
	HANDLE find = INVALID_HANDLE_VALUE;

	// �t�H���_�̍ŏ��̃t�@�C��������
	std::string search = folder;
	find = FindFirstFile(search.c_str(), &findData);

	if (find != INVALID_HANDLE_VALUE)
	{
		do 
		{
			std::string filePath = folder + "\\" + findData.cFileName;

			// �t�@�C���̑������f�B���N�g���ł͂Ȃ����ǂ���
			if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				// �t�@�C���̊g���q�擾
				std::string ext = filePath.substr(filePath.find_last_of(".") + 1);

				// �g���q���摜�t�@�C���������ꍇ
				if (ext == "png" || ext == "jpg" || ext == "jpeg" || ext == "bmp")
				{
					file.push_back(filePath);
				}
			}

		} while (FindNextFile(find, &findData) != 0);

		// �n���h�����N���[�Y
		FindClose(find);
	}
}

//--------------------------------------------------
// �擾
//--------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(std::string inKey, int index)
{
	// Key�����݂��邩�ۂ��B
	if (!ExistsPath(inKey))
	{
		// Key���Ȃ������ꍇ
		return nullptr;
	}

	// Key�����݂��邩�ۂ��B
	if (!ExistsKey(inKey))
	{
		Load(inKey, m_texturePath[inKey], index);
	}

	/* ��Key���������ꍇ�� */

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

	//�e�N�X�`���̓ǂݍ���
	Load(path, path);
	m_texturePath.insert(std::make_pair(path, path));

	return m_texture[path];
}
