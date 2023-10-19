//============================
//
// ファイル設定
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
// 読込み
//============================
nlohmann::json CFile::LoadJsonStage(const wchar_t* cUrl)
{
	std::ifstream ifs(cUrl);

	if (ifs)
	{
		nlohmann::json list;	// リストの作成

		ifs >> list;
		return list;
	}

	/* ↓ファイルを開くのを失敗した場合↓ */

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
	ofn.lpstrFilter = TEXT("全てのファイル(*.*)\0*.*\0");
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = sizeof(fileName) * MAX_PATH;
	ofn.lpstrInitialDir = initDir;
	ofn.lpstrTitle = TEXT("ファイル指定");
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_EXPLORER;
	ofn.lpstrDefExt = "";

	return GetOpenFileName(&ofn);
}