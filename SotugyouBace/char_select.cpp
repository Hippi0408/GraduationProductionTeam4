//==============================================================================================
//
// キャラクターセレクト　　　char_select.cpp
// tutida ryousei
//
//==============================================================================================
#include "char_select.h"
#include "input.h"
#include "application.h"
#include "fade.h"
#include "fontString.h"
#include "confirmation_window.h"
#include "charselect_window.h"
#include "camera.h"
#include "halfsphere.h"
#include "playerdata.h"
#include "model.h"
#include "objectX.h"

//==============================================================================================
// 静的メンバ変数宣言
//==============================================================================================
CConfirmation_Window* CChar_Select::m_pConfirmation = nullptr;

//==============================================================================================
// コンストラクタ
//==============================================================================================
CChar_Select::CChar_Select()
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CChar_Select::~CChar_Select()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CChar_Select::Init()
{
	//======================================
	// メンバ変数の初期化処理
	//======================================
	m_nIndex = 0;
	m_nPlayerIndex = 0;

	m_pFont = CFontString::Create({ 280.0f, 200.0f, 0.0f }, { 50.0f, 50.0f }, "キャラクターセレクト");

	// カメラのポインタ
	CCamera* pCamera = CApplication::GetCamera();

	m_pPlayerData = new CPlayerData;

	pCamera->SetPosV({ 0.0f, 100.0f, -100.0f });
	pCamera->SetPosR({ 0.0f, 0.0f, 100.0f });

	m_pPlayerData->Init();

	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		m_pObjectX[nCnt] = CObjectX::Create(D3DXVECTOR3(-80.0f + 55.0f * nCnt, 600.0f, 0.0f), D3DXVECTOR3(0.0f, -0.3f + 0.5f * nCnt, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
	}
	//m_pObjectX[1] = CObjectX::Create(D3DXVECTOR3(-25.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
	//m_pObjectX[2] = CObjectX::Create(D3DXVECTOR3(30.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");
	//m_pObjectX[3] = CObjectX::Create(D3DXVECTOR3(85.0f, 600.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), nullptr, "Data/model/SelectMode/view_Body_00.x");

	m_pWareHouse = CObjectX::Create(D3DXVECTOR3(0.0f, 300.0f, 1000.0f), D3DXVECTOR3(0.0f, 0.0, 0.0f), nullptr, "Data/model/CharacterSelect/Warehouse.x");

	// ハーフスフィアの生成
	//m_pHalfSphere = CHalfSphere::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(2500.0f, 2500.0f, 2500.0f),  D3DXVECTOR3(0.0f, 0.0f, 0.0f), CHalfSphere::SPHERE_UP);
	//m_pHalfSphere->LoadTexture("Data/texture/sky000.jpg");

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CChar_Select::Uninit()
{
	// メニューウィンドウの終了処理
	if (m_pConfirmation != nullptr)
	{
		m_pConfirmation->Uninit();
		delete m_pConfirmation;
		m_pConfirmation = nullptr;
	}

	// プレイヤーデータ
	if (m_pPlayerData != nullptr)
	{
		m_pPlayerData->Uninit();
		delete m_pPlayerData;
		m_pPlayerData = nullptr;
	}
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CChar_Select::Update()
{
	CInput* pInput = CInput::GetKey();

	for (int nCnt = 0; nCnt < 4; nCnt++)
	{
		if ((pInput->Trigger(DIK_RETURN) || pInput->Press(JOYPAD_B, nCnt) || pInput->Press(JOYPAD_A, nCnt)
			|| pInput->Trigger(JOYPAD_START, nCnt))
			&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		{
			if (m_pConfirmation == nullptr)
			{
				m_pConfirmation = CConfirmation_Window::Create(D3DXVECTOR3(SCREEN_WIDTH / 2, 450.0f, 0.0f), 500.0f, 120.0f, D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f));
			}
		}

		//// キャラセレクト画面に戻る
		//if (pInput->Trigger(DIK_BACK, nCnt)
		//	&& CApplication::GetFade()->GetFade() == CFade::FADE_NONE)
		//{
		//	// 画面遷移
		//	CFade::SetFade(CApplication::MODE_TITLE, 0.05f);
		//}
	}

	if (m_pConfirmation != nullptr)
	{
		m_pConfirmation->Update();

		/*if (m_pConfirmation->GetSelectChoice() == true)
		{
			CFade::SetFade(CApplication::MODE_STAGE_SELECT, 0.05f);
		}*/
	}

	// ウィンドウが閉じた場合 
	if (m_pConfirmation != nullptr && m_pConfirmation->GetSapawnWindow() == true)
	{
		m_pConfirmation->SetSapawnWindow(false);
		delete m_pConfirmation;
		m_pConfirmation = nullptr;
	}

	// プレイヤーデータの更新処理
	if (m_pPlayerData != nullptr)
	{
		m_pPlayerData->Update();
	}

	// キャラ切り替え処理
	CharSwitching(2);
}

//==============================================================================================
//	キャラ切り替え処理
//==============================================================================================
void CChar_Select::CharSwitching(int PlayerIndex)
{
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		if (nCnt == PlayerIndex)
		{
			// 現在の番号の取得
			m_nIndex = m_pPlayerData->GetPlayerIndex();

			if (CChar_Select::GetConfimationWindow() != nullptr
				&& CChar_Select::GetConfimationWindow()->GetCharSelect() != nullptr)
			{
				m_nIndex = CChar_Select::GetConfimationWindow()->GetCharSelect()->GetSelectChoice();
			}

			if (m_nIndex <= -1)
			{
				m_nIndex = 3;
			}
			if (m_nIndex >= 4)
			{
				m_nIndex = 0;
			}

			// 現在の番号と前の番号が一致していなかったら
			if (m_nIndex != m_nIndexKeep)
			{
				// オブジェクトXの削除
				if (m_pObjectX[nCnt] != nullptr)
				{
					m_pObjectX[nCnt]->Uninit();
					m_pObjectX[nCnt] = nullptr;
				}
			}

			// 番号の保存
			m_nIndexKeep = m_nIndex;

			// モデルの設定
			if (CChar_Select::GetConfimationWindow() != nullptr)
			{
				if (CChar_Select::GetConfimationWindow()->GetSelectChoice() == true)
				{
					SetModel(0, "Data/model/SelectMode/view_Body_00.x");
					SetModel(1, "Data/model/SelectMode/view_Body_01.x");
					SetModel(2, "Data/model/SelectMode/view_Body_02.x");
					SetModel(3, "Data/model/SelectMode/view_Body_03.x");
				}
				else
				{
					SetModel(0, "Data/model/SelectMode/view_Body_04.x");
					SetModel(1, "Data/model/SelectMode/view_Body_05.x");
					SetModel(2, "Data/model/SelectMode/view_Body_06.x");
					SetModel(3, "Data/model/SelectMode/view_Body_07.x");
				}
			}
		}
	}
}

//==============================================================================================
// モデルの設定処理
//==============================================================================================
void CChar_Select::SetModel(int index, const char * Xfilename)
{
	for (int nCnt = 0; nCnt < MAX_PLAYER; nCnt++)
	{
		if (m_pObjectX[nCnt] == nullptr)
		{
			if (m_nIndex == index)
			{
				m_pObjectX[nCnt] = CObjectX::Create(D3DXVECTOR3(-80.0f + 55.0f * nCnt, 600.0f, 0.0f), D3DXVECTOR3(0.0f, -0.3f, 0.0f), nullptr, Xfilename);
			}
		}
	}
}

//==============================================================================================
// 生成処理
//==============================================================================================
CChar_Select* CChar_Select::Create()
{
	CChar_Select* pChar_Select = new CChar_Select;

	if (FAILED(pChar_Select->Init()))
	{
		return nullptr;
	}

	return pChar_Select;
}
