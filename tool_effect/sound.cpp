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
	// COM���C�u�����̏�����
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	if (FAILED(XAudio2Create(&m_pXAudio2, 0)))
	{// XAudio2�I�u�W�F�N�g�̍쐬
		MessageBox(hWnd, "XAudio2�I�u�W�F�N�g�̍쐬�Ɏ��s�I", "�x���I", MB_ICONWARNING);

		// COM���C�u�����̏I������
		CoUninitialize();

		return E_FAIL;
	}

	if (FAILED(m_pXAudio2->CreateMasteringVoice(&m_pMasteringVoice)))
	{// �}�X�^�[�{�C�X�̐���
		MessageBox(hWnd, "�}�X�^�[�{�C�X�̐����Ɏ��s�I", "�x���I", MB_ICONWARNING);

		if (m_pXAudio2 != nullptr)
		{// null�`�F�b�N
		 // XAudio2�I�u�W�F�N�g�̊J��
			m_pXAudio2->Release();
			m_pXAudio2 = nullptr;
		}

		// COM���C�u�����̏I������
		CoUninitialize();

		return E_FAIL;
	}

	// �T�E���h�f�[�^�̏�����
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
// �I������
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
				// �ꎞ��~
				wavData.sourceVoice->Stop(0);

				// �\�[�X�{�C�X�̔j��
				wavData.sourceVoice->DestroyVoice();
				wavData.sourceVoice = nullptr;

				// �I�[�f�B�I�f�[�^�̊J��
				free(wavData.dataAudio);
				wavData.dataAudio = nullptr;
			}
			break;

		case AUDIO_MP3:
			CSound::SMp3Data mp3Data = p.second.mp3;
			if (mp3Data.pin != nullptr)
			{
				// �ꎞ��~
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

	// �}�X�^�[�{�C�X�̔j��
	m_pMasteringVoice->DestroyVoice();
	m_pMasteringVoice = nullptr;

	if (m_pXAudio2 != nullptr)
	{	// XAudio2�I�u�W�F�N�g�̊J��
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

	// COM���C�u�����̏I������
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

	// �o�b�t�@�̃N���A
	memset(&wfx, 0, sizeof(WAVEFORMATEXTENSIBLE));
	memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));

	/* ���T�E���h�f�[�^�t�@�C���̐����� */

	hFile = CreateFile(param.fileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(hWnd, "�T�E���h�f�[�^�t�@�C���̐����Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
		return HRESULT_FROM_WIN32(GetLastError());
	}

	if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
	{// �t�@�C���|�C���^��擪�Ɉړ�
		MessageBox(hWnd, "�T�E���h�f�[�^�t�@�C���̐����Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
		return HRESULT_FROM_WIN32(GetLastError());
	}

	/* ��WAVE�t�@�C���̃`�F�b�N�� */

	if (FAILED(CheckChunk(hFile, 'FFIR', &dwChunkSize, &dwChunkPosition)))
	{
		MessageBox(hWnd, "WAVE�t�@�C���̃`�F�b�N�Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	if (FAILED(LoadChunkData(hFile, &dwFiletype, sizeof(DWORD), dwChunkPosition)))
	{
		MessageBox(hWnd, "WAVE�t�@�C���̃`�F�b�N�Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	if (dwFiletype != 'EVAW')
	{
		MessageBox(hWnd, "WAVE�t�@�C���̃`�F�b�N�Ɏ��s�I(3)", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	/* ���t�H�[�}�b�g�`�F�b�N�� */

	if (FAILED(CheckChunk(hFile, ' tmf', &dwChunkSize, &dwChunkPosition)))
	{
		MessageBox(hWnd, "�t�H�[�}�b�g�`�F�b�N�Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	if (FAILED(LoadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition)))
	{
		MessageBox(hWnd, "�t�H�[�}�b�g�`�F�b�N�Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	/* ���I�[�f�B�I�f�[�^�ǂݍ��݁� */

	if (FAILED(CheckChunk(hFile, 'atad', &audioData.sizeAudio, &dwChunkPosition)))
	{
		MessageBox(hWnd, "�I�[�f�B�I�f�[�^�ǂݍ��݂Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	audioData.dataAudio = (BYTE*)malloc(audioData.sizeAudio);
	if (FAILED(LoadChunkData(hFile, audioData.dataAudio, audioData.sizeAudio, dwChunkPosition)))
	{
		MessageBox(hWnd, "�I�[�f�B�I�f�[�^�ǂݍ��݂Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	/* ���\�[�X�{�C�X�̐����� */

	if (FAILED(m_pXAudio2->CreateSourceVoice(&audioData.sourceVoice, &(wfx.Format))))
	{
		MessageBox(hWnd, "�\�[�X�{�C�X�̐����Ɏ��s�I", "�x���I", MB_ICONWARNING);
		return S_FALSE;
	}

	// �o�b�t�@�̒l�ݒ�
	buffer.AudioBytes = audioData.sizeAudio;
	buffer.pAudioData = audioData.dataAudio;
	buffer.Flags = XAUDIO2_END_OF_STREAM;
	buffer.LoopCount = param.loop;

	// �I�[�f�B�I�o�b�t�@�̓o�^
	audioData.sourceVoice->SubmitSourceBuffer(&buffer);

	// �I�[�f�B�I�f�[�^���i�[
	m_audio[label].audio = audioData;
	m_audio[label].type = AUDIO_WAV;

	// �t�@�C�����N���[�Y
	CloseHandle(hFile);

	return S_OK;
}

HRESULT CSound::CreateAudioMp3(HWND hWnd, std::string label, SParam param)
{
	SMp3Data mp3Data = {};

	// �t�B���^�[�O���t�}�l�[�W���[�I�u�W�F�N�g�̍쐬
	IGraphBuilder* pGraphBuilder = nullptr;
	if (CoCreateInstance(CLSID_FilterGraph, nullptr, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraphBuilder) != S_OK)
	{
		MessageBox(hWnd, "�C���X�^���X�̍쐬���s", "�x���I", MB_ICONWARNING);
		CoUninitialize();
		return S_FALSE;
	}

	// �t�B���^�[�O���t�r���_�[�I�u�W�F�N�g�̍쐬
	IMediaControl* pMediaControl = nullptr;
	if (pGraphBuilder->QueryInterface(IID_IMediaControl, (void**)&pMediaControl) != S_OK)
	{
		MessageBox(hWnd, "IMediaControl�̃|�C���^�擾���s", "�x���I", MB_ICONWARNING);
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// IMediaSeeking �C���^�[�t�F�[�X�̎擾
	IMediaSeeking* pMediaSeeking = nullptr;
	if (pGraphBuilder->QueryInterface(IID_IMediaSeeking, (void**)&pMediaSeeking) != S_OK) 
	{
		MessageBox(hWnd, "IMediaSeeking�̃|�C���^�擾���s", "�x���I", MB_ICONWARNING);
		pMediaControl->Release();
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// MP3�t�@�C�����Đ����邽�߂̃t�B���^�[�I�u�W�F�N�g�̍쐬
	IBaseFilter* pSourceFilter = nullptr;
	std::wstring wstr(param.fileName.begin(), param.fileName.end());	// wstr�ɕϊ����Ȃ��ƕ�������
	const wchar_t* mp3fileName = wstr.c_str();
	if (pGraphBuilder->AddSourceFilter(mp3fileName, nullptr, &pSourceFilter) != S_OK)
	{
		MessageBox(hWnd, "�t�B���^�[�I�u�W�F�N�g�𐳏�ɒǉ��ł��܂���ł���", "�x���I", MB_ICONWARNING);
		pMediaSeeking->Release();
		pMediaControl->Release();
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// �o�̓s���̎擾
	IPin* pPin = nullptr;
	if (pSourceFilter->FindPin(L"Output", &pPin) != S_OK)
	{
		MessageBox(hWnd, "�s���̖��O���������w�肳��Ă��Ȃ��\��������܂�", "�x���I", MB_ICONWARNING);
		pSourceFilter->Release();
		pMediaSeeking->Release();
		pMediaControl->Release();
		pGraphBuilder->Release();
		CoUninitialize();
		return S_FALSE;
	}

	// �o�̓s�����t�B���^�[�O���t�ɐڑ�
	if (pGraphBuilder->Render(pPin) != S_OK)
	{
		MessageBox(hWnd, "�ڑ����T�|�[�g����Ă��Ȃ��\��������܂�", "�x���I", MB_ICONWARNING);
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
// �Z�O�����g�Đ�(�Đ����Ȃ��~)
//=============================================================================
HRESULT CSound::Play(std::string label)
{
	switch (m_audio[label].type)
	{
	case AUDIO_WAV:
		XAUDIO2_BUFFER buffer;

		// �o�b�t�@�̒l�ݒ�
		memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
		buffer.AudioBytes = m_audio[label].audio.sizeAudio;
		buffer.pAudioData = m_audio[label].audio.dataAudio;
		buffer.Flags = XAUDIO2_END_OF_STREAM;
		buffer.LoopCount = m_soundPath[label].loop;

		// �Z�O�����g��~(���x���w��)
		Stop(label);

		// �I�[�f�B�I�o�b�t�@�̓o�^
		m_audio[label].audio.sourceVoice->SubmitSourceBuffer(&buffer);

		// �Đ�
		m_audio[label].audio.sourceVoice->Start(0);
		break;

	case AUDIO_MP3:
		// �Đ��ʒu���ŏ��ɖ߂��čĐ�
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
// �Z�O�����g��~(���x���w��)
//=============================================================================
void CSound::Stop(std::string label)
{
	switch (m_audio[label].type)
	{
	case AUDIO_WAV:
		XAUDIO2_VOICE_STATE xa2state;

		// ��Ԏ擾
		m_audio[label].audio.sourceVoice->GetState(&xa2state);

		if (xa2state.BuffersQueued != 0)
		{// �Đ���
		 // �ꎞ��~
			m_audio[label].audio.sourceVoice->Stop(0);

			// �I�[�f�B�I�o�b�t�@�̍폜
			m_audio[label].audio.sourceVoice->FlushSourceBuffers();
		}
		break;

	case AUDIO_MP3:
		OAFilterState state;
		m_audio[label].mp3.mediaControl->GetState(100, &state);

		if (state == State_Running)
		{
			// �ꎞ��~
			m_audio[label].mp3.mediaControl->Stop();
		}

		break;

	default:
		assert(false);
		break;
	}
}

//=============================================================================
// �Z�O�����g��~(�S��)
//=============================================================================
void CSound::Stop()
{
	// �ꎞ��~
	for (auto it = m_audio.begin(); it != m_audio.end();)
	{
		CSound::SAudioData data = it->second.audio;
		if (data.sourceVoice != nullptr)
		{
			// �ꎞ��~
			data.sourceVoice->Stop(0);
		}
		CSound::SMp3Data mp3Data = it->second.mp3;
		if (mp3Data.mediaControl != nullptr)
		{
			// �ꎞ��~
			mp3Data.mediaControl->Pause();
		}
	}
}

//��������������������������������������������������������������
// ���ʐݒ菈��
//��������������������������������������������������������������
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

//��������������������������������������������������������������
// MP3�̃��[�v�Đ�����
//��������������������������������������������������������������
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
// �`�����N�̃`�F�b�N
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
	{// �t�@�C���|�C���^��擪�Ɉړ�
		return HRESULT_FROM_WIN32(GetLastError());
	}

	while (hr == S_OK)
	{
		if (!ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL))
		{// �`�����N�̓ǂݍ���
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		if (!ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL))
		{// �`�����N�f�[�^�̓ǂݍ���
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		switch (dwChunkType)
		{
		case 'FFIR':
			dwRIFFDataSize = dwChunkDataSize;
			dwChunkDataSize = 4;

			if (!ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL))
			{// �t�@�C���^�C�v�̓ǂݍ���
				hr = HRESULT_FROM_WIN32(GetLastError());
			}

			break;

		default:
			if (SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT) == INVALID_SET_FILE_POINTER)
			{// �t�@�C���|�C���^���`�����N�f�[�^���ړ�
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
// �`�����N�f�[�^�̓ǂݍ���
//=============================================================================
HRESULT CSound::LoadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset)
{
	DWORD dwRead;

	if (SetFilePointer(hFile, dwBufferoffset, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
	{// �t�@�C���|�C���^���w��ʒu�܂ňړ�
		return HRESULT_FROM_WIN32(GetLastError());
	}

	if (!ReadFile(hFile, pBuffer, dwBuffersize, &dwRead, NULL))
	{// �f�[�^�̓ǂݍ���
		return HRESULT_FROM_WIN32(GetLastError());
	}

	return S_OK;
}
