#ifndef _SOUND_H_
#define _SOUND_H_

#include <d3dx9.h>
#include <xaudio2.h>

// DirectShow
#include <dshow.h>
#pragma comment(lib, "strmiids.lib")

class CSound
{
public:
	enum EAudioType
	{
		AUDIO_WAV,
		AUDIO_MP3,
		AUDIO_MAX
	};

	struct STrack
	{
		std::string soundLabel;
		int startTime;
		int volume;
	};

	struct SParam
	{
		std::string fileName;	// ファイル名
		int loop;				// ループ
	};

	struct SAudioData
	{
		IXAudio2SourceVoice* sourceVoice;	// ソースボイス
		BYTE* dataAudio;					// オーディオデータ
		DWORD sizeAudio;					// オーディオデータサイズ
	};

	struct SMp3Data
	{
		IGraphBuilder* graphBuilder;
		IMediaControl* mediaControl;
		IMediaSeeking* mediaSeeking;
		IBaseFilter* sourceFilter;
		IPin* pin;
	};

	struct SBundleData
	{
		SAudioData audio;
		SMp3Data mp3;
		EAudioType type;
	};

	CSound();
	~CSound();

	HRESULT Init(HWND hWnd);
	void Uninit();
	HRESULT Play(std::string sound);
	void Stop(std::string label);
	void Stop();
	void SetVolume(std::string label, long volume);
	void loopMp3(std::string label);

	void LoadAll();

	std::map<std::string, SParam, std::less<>> GetSoundPath() { return m_soundPath; }

private:
	HRESULT CreateAudioWav(HWND hWnd, std::string label, SParam param);
	HRESULT CreateAudioMp3(HWND hWnd, std::string label, SParam param);

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD* pChunkSize, DWORD* pChunkDataPosition);	// チャンクのチェック
	HRESULT LoadChunkData(HANDLE hFile, void* pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);	// チャンクデータの読み込み

	IXAudio2* m_pXAudio2;							// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice* m_pMasteringVoice;		// マスターボイス

	std::map<std::string, SParam, std::less<>> m_soundPath;				// オーディオのパス
	std::map<std::string, SBundleData, std::less<>> m_audio;			// オーディオの情報
};

#endif
