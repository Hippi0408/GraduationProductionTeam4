#include "sound.h"
#include "application.h"
#include "file.h"

#include <assert.h>

CSound::CSound() :
	m_pMasteringVoice(nullptr),
	m_pXAudio2(nullptr)
{
}

CSound::~CSound()
{
	assert(m_pMasteringVoice == nullptr);
	assert(m_pXAudio2 == nullptr);
}

HRESULT CSound::Init(HWND hWnd)
{
	// COMライブラリの初期化
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (FAILED(XAudio2Create(&m_pXAudio2, 0)))
	{// XAudio2オブジェクトの作成
		MessageBox(hWnd, "XAudio2オブジェクトの作成に失敗！", "警告！", MB_ICONWARNING);

		// COMライブラリの終了処理
		CoUninitialize();

		return E_FAIL;
	}

	if (FAILED(m_pXAudio2->CreateMasteringVoice(&m_pMasteringVoice)))
	{// マスターボイスの生成
		MessageBox(hWnd, "マスターボイスの生成に失敗！", "警告！", MB_ICONWARNING);

		if (m_pXAudio2 != nullptr)
		{// nullチェック
		 // XAudio2オブジェクトの開放
			m_pXAudio2->Release();
			m_pXAudio2 = nullptr;
		}

		// COMライブラリの終了処理
		CoUninitialize();

		return E_FAIL;
	}

	// サウンドデータの初期化
	for (auto &p : m_soundPath)
	{
		std::string fileName = p.second.fileName;
		std::string extension;

		size_t dotPos = fileName.find_last_of('.');
		if (dotPos != std::string::npos && dotPos < fileName.length() - 1)
		{
			extension = fileName.substr(dotPos + 1);
		}

		if (extension == "wav")
		{
			CreateAudioWav(hWnd, p.first, p.second);
		}
		if (extension == "mp3")
		{
			CreateAudioMp3(hWnd, p.first, p.second);
		}
	}

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CSound::Uninit()
{
	for (auto &p : m_audio)
	{
		CSound::SBundleData soundData = p.second;

		switch (p.second.type)
		{
		case AUDIO_WAV:
			CSound::SAudioData wavData = p.second.audio;
			if (wavData.sourceVoice != nullptr)
			{
				// 一時停止
				wavData.sourceVoice->Stop(0);

				// ソースボイスの破棄
				wavData.sourceVoice->DestroyVoice();
				wavData.sourceVoice = nullptr;

				// オーディオデータの開放
				free(wavData.dataAudio);
				wavData.dataAudio = nullptr;
			}
			break;

		case AUDIO_MP3:
			CSound::SMp3Data mp3Data = p.second.mp3;
			if (mp3Data.pin != nullptr)
			{
				// 一時停止
				mp3Data.mediaControl->Stop();

				mp3Data.pin->Release();
				mp3Data.sourceFilter->Release();
				mp3Data.mediaControl->Release();
				mp3Data.mediaSeeking->Release();
				mp3Data.graphBuilder->Release();
			}
			break;
		}
	}

	// マスターボイスの破棄
	m_pMasteringVoice->DestroyVoice();
	m_pMasteringVoice = nullptr;

	if (m_pXAudio2 != nullptr)
	{	// XAudio2オブジェクトの開放
		m_pXAudio2->Release();
		m_pXAudio2 = nullptr;
	}
	
	if (!m_soundPath.empty())
	{
		m_soundPath.clear();
	}

	if (!m_audio.empty())
	{
		m_audio.clear();
	}

	// COMライブラリの終了処理
	CoUninitialize();
}

HRESULT CSound::CreateAudioWav(HWND hWnd, std::string label, SParam param)
{
	SAudioData audioData = {};

	WAVEFORMATEXTENSIBLE wfx;
	XAUDIO2_BUFFER buffer;

	HANDLE hFile = INVALID_HANDLE_VALUE;
	DWORD dwChunkSize = 0;
	DWORD dwChunkPosition = 0;
	DWORD dwFiletype = 0;

	// バッファのクリア
	memset(&wfx, 0, sizeof(WAVEFORMATEXTENSIBLE));
	memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));

	/* ↓サウンドデータファイルの生成↓ */

	hFile = CreateFile(param.fileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(hWnd, "サウンドデータファイルの生成に失敗！(1)", "警告！", MB_ICONWARNING);
		return HRESULT_FROM_WIN32(GetLastError());
	}

	if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
	{// ファイルポインタを先頭に移動
		MessageBox(hWnd, "サウンドデータファイルの生成に失敗！(2)", "警告！", MB_ICONWARNING);
		return HRESULT_FROM_WIN32(GetLastError());
	}

	/* ↓WAVEファイルのチェック↓ */

	if (FAILED(CheckChunk(hFile, 'FFIR', &dwChunkSize, &dwChunkPosition)))
	{
		MessageBox(hWnd, "WAVEファイルのチェックに失敗！(1)", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	if (FAILED(LoadChunkData(hFile, &dwFiletype, sizeof(DWORD), dwChunkPosition)))
	{
		MessageBox(hWnd, "WAVEファイルのチェックに失敗！(2)", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	if (dwFiletype != 'EVAW')
	{
		MessageBox(hWnd, "WAVEファイルのチェックに失敗！(3)", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	/* ↓フォーマットチェック↓ */

	if (FAILED(CheckChunk(hFile, ' tmf', &dwChunkSize, &dwChunkPosition)))
	{
		MessageBox(hWnd, "フォーマットチェックに失敗！(1)", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	if (FAILED(LoadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition)))
	{
		MessageBox(hWnd, "フォーマットチェックに失敗！(2)", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	/* ↓オーディオデータ読み込み↓ */

	if (FAILED(CheckChunk(hFile, 'atad', &audioData.sizeAudio, &dwChunkPosition)))
	{
		MessageBox(hWnd, "オーディオデータ読み込みに失敗！(1)", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	audioData.dataAudio = (BYTE*)malloc(audioData.sizeAudio);
	if (FAILED(LoadChunkData(hFile, audioData.dataAudio, audioData.sizeAudio, dwChunkPosition)))
	{
		MessageBox(hWnd, "オーディオデータ読み込みに失敗！(2)", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	/* ↓ソースボイスの生成↓ */

	if (FAILED(m_pXAudio2->CreateSourceVoice(&audioData.sourceVoice, &(wfx.Format))))
	{
		MessageBox(hWnd, "ソースボイスの生成に失敗！", "警告！", MB_ICONWARNING);
		return S_FALSE;
	}

	// バッファの値設定
	buffer.AudioBytes = audioData.sizeAudio;
	buffer.pAudioData = audioData.dataAudio;
	buffer.Flags = XAUDIO2_END_OF_STREAM;
	buffer.LoopCount = param.loop;

	// オーディオバッファの登録
	audioData.sourceVoice->SubmitSourceBuffer(&buffer);

	// オーディオデータを格納
	m_audio[label].audio = audioData;
	m_audio[label].type = AUDIO_WAV;

	// ファイルをクローズ
	CloseHandle(hFile);

	return S_OK;
}

HRESULT CSound::CreateAudioMp3(HWND hWnd, std::string label, SParam param)
{
	SMp3Data mp3Data = {};

	// フィルターグラフマネージャーオブジェクトの作成
	IGraphBuilder* pGraphBuilder = nullptr;
	if (CoCreateInstance(CLSID_FilterGraph, nullptr, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraphBuilder) != S_OK)
	{
		MessageBox(hWnd, "インスタンスの作成失敗", "警告！", MB_ICONWARNING);
		CoUninitialize();
		return S_FALSE;
	}

	// フィルターグラフビルダーオブジェクトの作成
	IMediaControl* pMediaControl = nullptr;
	if (pGraphBuilder->QueryInterface(IID_IMediaControl, (void**)&pMediaControl) != S_OK)
	{
		MessageBox(hWnd, "IMediaControlのポインタ取得失敗", "警告！", MB_ICONWARNING);
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// IMediaSeeking インターフェースの取得
	IMediaSeeking* pMediaSeeking = nullptr;
	if (pGraphBuilder->QueryInterface(IID_IMediaSeeking, (void**)&pMediaSeeking) != S_OK) 
	{
		MessageBox(hWnd, "IMediaSeekingのポインタ取得失敗", "警告！", MB_ICONWARNING);
		pMediaControl->Release();
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// MP3ファイルを再生するためのフィルターオブジェクトの作成
	IBaseFilter* pSourceFilter = nullptr;
	std::wstring wstr(param.fileName.begin(), param.fileName.end());	// wstrに変換しないと文字化け
	const wchar_t* mp3fileName = wstr.c_str();
	if (pGraphBuilder->AddSourceFilter(mp3fileName, nullptr, &pSourceFilter) != S_OK)
	{
		MessageBox(hWnd, "フィルターオブジェクトを正常に追加できませんでした", "警告！", MB_ICONWARNING);
		pMediaSeeking->Release();
		pMediaControl->Release();
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// 出力ピンの取得
	IPin* pPin = nullptr;
	if (pSourceFilter->FindPin(L"Output", &pPin) != S_OK)
	{
		MessageBox(hWnd, "ピンの名前が正しく指定されていない可能性があります", "警告！", MB_ICONWARNING);
		pSourceFilter->Release();
		pMediaSeeking->Release();
		pMediaControl->Release();
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// 出力ピンをフィルターグラフに接続
	if (pGraphBuilder->Render(pPin) != S_OK)
	{
		MessageBox(hWnd, "接続がサポートされていない可能性があります", "警告！", MB_ICONWARNING);
		pPin->Release();
		pSourceFilter->Release();
		pMediaSeeking->Release();
		pMediaControl->Release();
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	mp3Data.graphBuilder = pGraphBuilder;
	mp3Data.mediaControl = pMediaControl;
	mp3Data.mediaSeeking = pMediaSeeking;
	mp3Data.sourceFilter = pSourceFilter;
	mp3Data.pin = pPin;
	m_audio[label].mp3 = mp3Data;
	m_audio[label].type = AUDIO_MP3;

	return S_OK;
}

void CSound::LoadAll()
{
	nlohmann::json list = CFile::LoadJsonStage(L"Data/FILE/sound.json");

	for (int i = 0; i < (int)list["SOUND"].size(); ++i)
	{
		SParam param = {};
		param.fileName = list["SOUND"].at(i)[1];
		param.loop = list["SOUND"].at(i)[2];

		m_soundPath.insert(std::make_pair(list["SOUND"].at(i)[0], param));
	}
}

//=============================================================================
// セグメント再生(再生中なら停止)
//=============================================================================
HRESULT CSound::Play(std::string label)
{
	switch (m_audio[label].type)
	{
	case AUDIO_WAV:
		XAUDIO2_BUFFER buffer;

		// バッファの値設定
		memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
		buffer.AudioBytes = m_audio[label].audio.sizeAudio;
		buffer.pAudioData = m_audio[label].audio.dataAudio;
		buffer.Flags = XAUDIO2_END_OF_STREAM;
		buffer.LoopCount = m_soundPath[label].loop;

		// セグメント停止(ラベル指定)
		Stop(label);

		// オーディオバッファの登録
		m_audio[label].audio.sourceVoice->SubmitSourceBuffer(&buffer);

		// 再生
		m_audio[label].audio.sourceVoice->Start(0);
		break;

	case AUDIO_MP3:
		// 再生位置を最初に戻して再生
		m_audio[label].mp3.mediaControl->Stop();

		IMediaPosition* mediaPosition;
		m_audio[label].mp3.mediaControl->QueryInterface(IID_IMediaPosition, (void**)&mediaPosition);
		mediaPosition->put_CurrentPosition(0);
		m_audio[label].mp3.mediaControl->Run();
		mediaPosition->Release();
		break;

	default:
		assert(false);
		break;
	}

	return S_OK;
}

//=============================================================================
// セグメント停止(ラベル指定)
//=============================================================================
void CSound::Stop(std::string label)
{
	switch (m_audio[label].type)
	{
	case AUDIO_WAV:
		XAUDIO2_VOICE_STATE xa2state;

		// 状態取得
		m_audio[label].audio.sourceVoice->GetState(&xa2state);

		if (xa2state.BuffersQueued != 0)
		{// 再生中
		 // 一時停止
			m_audio[label].audio.sourceVoice->Stop(0);

			// オーディオバッファの削除
			m_audio[label].audio.sourceVoice->FlushSourceBuffers();
		}
		break;

	case AUDIO_MP3:
		OAFilterState state;
		m_audio[label].mp3.mediaControl->GetState(100, &state);

		if (state == State_Running)
		{
			// 一時停止
			m_audio[label].mp3.mediaControl->Stop();
		}

		break;

	default:
		assert(false);
		break;
	}
}

//=============================================================================
// セグメント停止(全て)
//=============================================================================
void CSound::Stop()
{
	// 一時停止
	for (auto it = m_audio.begin(); it != m_audio.end();)
	{
		CSound::SAudioData data = it->second.audio;
		if (data.sourceVoice != nullptr)
		{
			// 一時停止
			data.sourceVoice->Stop(0);
		}
		CSound::SMp3Data mp3Data = it->second.mp3;
		if (mp3Data.mediaControl != nullptr)
		{
			// 一時停止
			mp3Data.mediaControl->Pause();
		}
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 音量設定処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CSound::SetVolume(std::string label, long volume)
{
	switch (m_audio[label].type)
	{
	case AUDIO_WAV:
		m_audio[label].audio.sourceVoice->SetVolume(volume);
		break;

	case AUDIO_MP3:
		IBasicAudio* basicAudio;
		m_audio[label].mp3.mediaControl->QueryInterface(IID_IBasicAudio, (void**)&basicAudio);
		basicAudio->put_Volume(volume);
		break;

	default:
		assert(false);
		break;
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// MP3のループ再生処理
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CSound::loopMp3(std::string label)
{
	if (m_audio[label].type != AUDIO_MP3 || m_soundPath[label].loop != -1)
	{
		return;
	}

	REFERENCE_TIME maxLength = 0;
	m_audio[label].mp3.mediaSeeking->GetDuration(&maxLength);

	REFERENCE_TIME currentPos = 0;
	m_audio[label].mp3.mediaSeeking->GetCurrentPosition(&currentPos);

	if (currentPos >= maxLength)
	{
		IMediaPosition* mediaPosition = nullptr;
		m_audio[label].mp3.mediaControl->QueryInterface(IID_IMediaPosition, (void**)&mediaPosition);
		mediaPosition->put_CurrentPosition(0);
		m_audio[label].mp3.mediaControl->Run();
		mediaPosition->Release();
	}
}

//=============================================================================
// チャンクのチェック
//=============================================================================
HRESULT CSound::CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition)
{
	HRESULT hr = S_OK;
	DWORD dwRead = 0;
	DWORD dwChunkType = 0;
	DWORD dwChunkDataSize = 0;
	DWORD dwRIFFDataSize = 0;
	DWORD dwFileType = 0;
	DWORD dwBytesRead = 0;
	DWORD dwOffset = 0;

	if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
	{// ファイルポインタを先頭に移動
		return HRESULT_FROM_WIN32(GetLastError());
	}

	while (hr == S_OK)
	{
		if (!ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL))
		{// チャンクの読み込み
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		if (!ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL))
		{// チャンクデータの読み込み
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		switch (dwChunkType)
		{
		case 'FFIR':
			dwRIFFDataSize = dwChunkDataSize;
			dwChunkDataSize = 4;

			if (!ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL))
			{// ファイルタイプの読み込み
				hr = HRESULT_FROM_WIN32(GetLastError());
			}

			break;

		default:
			if (SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT) == INVALID_SET_FILE_POINTER)
			{// ファイルポインタをチャンクデータ分移動
				return HRESULT_FROM_WIN32(GetLastError());
			}
			break;
		}

		dwOffset += sizeof(DWORD) * 2;
		if (dwChunkType == format)
		{
			*pChunkSize = dwChunkDataSize;
			*pChunkDataPosition = dwOffset;

			return S_OK;
		}

		dwOffset += dwChunkDataSize;
		if (dwBytesRead >= dwRIFFDataSize)
		{
			return S_FALSE;
		}
	}

	return S_OK;
}

//=============================================================================
// チャンクデータの読み込み
//=============================================================================
HRESULT CSound::LoadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset)
{
	DWORD dwRead;

	if (SetFilePointer(hFile, dwBufferoffset, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
	{// ファイルポインタを指定位置まで移動
		return HRESULT_FROM_WIN32(GetLastError());
	}

	if (!ReadFile(hFile, pBuffer, dwBuffersize, &dwRead, NULL))
	{// データの読み込み
		return HRESULT_FROM_WIN32(GetLastError());
	}

	return S_OK;
}
