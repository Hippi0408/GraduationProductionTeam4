//============================
//
// �t�@�C���ݒ�
// Author:hamada ryuuga
// Author:Yuda Kaito
//
//============================
#include "file.h"
#include <fstream>

CFile::CFile()
{
}

CFile::~CFile()
{
}

//============================
// �Ǎ���
//============================
nlohmann::json CFile::LoadJsonStage(const wchar_t* cUrl)
{
	std::ifstream ifs(cUrl);

	if (ifs)
	{
		nlohmann::json list;	// ���X�g�̍쐬

		ifs >> list;
		return list;
	}

	/* ���t�@�C�����J���̂����s�����ꍇ�� */

	return nullptr;
}

void CFile::SaveJson(nlohmann::json inJson, const std::string cUrl)
{
	auto jobj = inJson.dump();
	std::ofstream writing_file;
	const std::string pathToJSON = "data/FILE/" + cUrl;
	writing_file.open(pathToJSON, std::ios::out);
	writing_file << jobj << std::endl;
	writing_file.close();
}

BOOL CFile::ShowDirectory(HWND hWnd, TCHAR* fileName, TCHAR* initDir)
{
	OPENFILENAME ofn;
	fileName[0] = TEXT('\0');

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFilter = TEXT("�S�Ẵt�@�C��(*.*)\0*.*\0");
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = sizeof(fileName) * MAX_PATH;
	ofn.lpstrInitialDir = initDir;
	ofn.lpstrTitle = TEXT("�t�@�C���w��");
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_EXPLORER;
	ofn.lpstrDefExt = "";

	return GetOpenFileName(&ofn);
}