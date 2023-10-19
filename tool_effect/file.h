//
//File.h
//
#ifndef _FILE_H_
#define _FILE_H_

#include "nlohmann/json.hpp"

class CFile
{
public:
	enum EFileType
	{
		File_txt,
		File_json,
		File_Max
	};

	CFile();
	~CFile();

	static nlohmann::json LoadJsonStage(const wchar_t* cUrl);
	static void SaveJson(nlohmann::json inJson, const std::string cUrl);
	static BOOL ShowDirectory(HWND hWnd, TCHAR* fileName, TCHAR* initDir);

private:
};

#endif