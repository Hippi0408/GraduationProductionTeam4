//==============================================================================================
//
// �A�v���P�[�V�����@�@�@application.h
// tutida ryousei
// tanimoto kosuke
//
//==============================================================================================
#ifndef _APPLICATION_H_
#define	_APPLICATION_H_

#include "renderer.h"
#include "sound.h"
#include "texture.h"

//�O���錾
class CObject;
class CTexture;
class CModel;
class CSound;
class CLight;
class CCamera;
class CFade;
class CInput;
class CMenu;
class CMode;
class CPlayerManager;
class CEnemyManager;

#ifdef _DEBUG
class CDebugProc;
#endif

class CApplication
{
public:

	// ���[�h�̎��
	enum MODE
	{
		MODE_NONE = 0,
		MODE_TITLE,
		MODE_GAME,
		MODE_RESULT,
		MODE_MAX,
	};

	CApplication();
	~CApplication();

	HRESULT Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit();
	void Update();
	void Draw();

	static void SetMode(MODE mode);		// ���[�h�̐ݒ�
	static void SetGameStart(const bool game_start) { m_bGameStart = game_start; }
	static void SetPauce(const bool pauce) { m_bPauce = pauce; }

	static CRenderer* GetRenderer() { return m_pRenderer; }
	static CTexture* GetTexture() { return m_pTexture; }
	static CModel* GetModel() { return m_pModel; }
	static CSound* GetSound() { return m_pSound; }
	static CLight* GetLight() { return m_pLight; }
	static CCamera* GetCamera() { return m_pCamera; }
	static CMode* GetGameMode() { return m_pGameMode; }
	static CFade* GetFade() { return m_pFade; }
	static CMenu* GetMenu() { return m_pMenu; }
	static CPlayerManager* GetPlayerManager() { return m_pPlayerManager; }
	static CEnemyManager* GetEnemyManager() { return m_pEnemyManager; }

	static MODE GetModeType() { return m_modeType; }

	static const bool GetGameStart() { return m_bGameStart; }
	static const bool GetPauce() { return m_bPauce; }

private:

	static CRenderer* m_pRenderer;
	static CTexture* m_pTexture;
	static CModel* m_pModel;
	static CSound* m_pSound;
	static CMode* m_pGameMode;
	static CLight* m_pLight;
	static CCamera* m_pCamera;
	static CFade* m_pFade;
	static CMenu* m_pMenu;
	static CPlayerManager* m_pPlayerManager;
	static CEnemyManager* m_pEnemyManager;
	CInput* m_pInput;

#ifdef _DEBUG
	static CDebugProc* m_pDebugProc;
#endif

	static MODE m_modeType;	// ���݂̃��[�h

	bool m_bWireFrame;
	static bool m_bGameStart;
	static bool m_bPauce;
};

#endif // !_APPLICATION_H_
