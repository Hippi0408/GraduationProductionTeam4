//=============================================================================
//
// player.cpp
// Author : koduna hirohito
//
//=============================================================================

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "player.h"
#include "input.h"
#include "manager.h"
#include "game.h"
#include "tps_camera.h"
#include "3dobject.h"
#include "read.h"
#include "convenience_function.h"
#include "ballast_manager.h"
#include <assert.h>

const D3DXVECTOR3 CPlayer::INIT_POS = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
const float CPlayer::MOVE_MAGNIFICATION = 1.0f;
//*****************************************************************************
// コンストラクタ
//*****************************************************************************
CPlayer::CPlayer()
{
	m_fSize = MOVE_MAGNIFICATION;
	m_nModelNum = 0;
	m_Pos = INIT_POS;
	m_Rot = INIT_POS;
	m_MoveMagnification = MOVE_MAGNIFICATION;
	m_pModelIndex = nullptr;
	m_p3DObject = nullptr;
	m_nModelIndexMax = 0;
	m_bCollision = true;
	m_bOpeningLost = true;
	m_bSwitch = false;
}

//*****************************************************************************
// デストラクタ
//*****************************************************************************
CPlayer::~CPlayer()
{
}

//*****************************************************************************
// 初期化
//*****************************************************************************
HRESULT CPlayer::Init()
{

	CRead CRead;

	CRead.ReadEditorText("data/EDITOR_TEXT/EditorText.txt");

	m_p3DObject = new C3DObject;
	if (FAILED(m_p3DObject->Init()))
	{
		return -1;
	}

	m_p3DObject->SetSize(m_fSize);
	m_p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], INIT_POS, INIT_POS);

	return S_OK;
}

//*****************************************************************************
// 終了処理
//*****************************************************************************
void CPlayer::Uninit()
{
	//モデルインデックス
	if (m_pModelIndex != nullptr)
	{
		delete[] m_pModelIndex;
		m_pModelIndex = nullptr;
	}

	if (m_p3DObject != nullptr)
	{
		m_p3DObject->Uninit();
		delete m_p3DObject;
		m_p3DObject = nullptr;
	}

	//イテレーターループ
	for (auto itr = m_BallastList.begin(); itr != m_BallastList.end();)
	{
		//イテレーターから瓦礫のポインタの代入
		C3DObject* p3DObject = *itr;

		//瓦礫ポインタの解放
		if (p3DObject != nullptr)
		{
			//終了処理
			p3DObject->Uninit();
			delete p3DObject;
			p3DObject = nullptr;
		}

		//次のイテレーターの代入、現在のイテレーターを破棄
		itr = m_BallastList.erase(itr);
	}
	
}

//*****************************************************************************
// 更新処理
//*****************************************************************************
void CPlayer::Update()
{
	
	MovePos();

	MoveRot();

	m_Rot = CConvenience_Function::NormalizationRot(m_Rot);

	ChangeSize();

	ChangeMagnification();

	ChangeModel();

	m_p3DObject->SetModelPattnNum(m_nModelNum);

	m_p3DObject->SetParentPos(m_Pos);
	m_p3DObject->SetRot(m_Rot);

	//入力デバイスの取得
	CInput* pInput = CInput::GetKey();
	if (pInput->Trigger(DIK_SPACE))
	{
		SetBullast();
	}

	if (pInput->Trigger(DIK_Y))
	{
		m_bCollision = true;
	}
	else if (pInput->Trigger(DIK_U))
	{
		m_bCollision = false;
	}

	if (pInput->Trigger(DIK_H))
	{
		m_bOpeningLost = true;
	}
	else if (pInput->Trigger(DIK_J))
	{
		m_bOpeningLost = false;
	}

	if (pInput->Trigger(DIK_N))
	{
		m_bSwitch = true;
	}
	else if (pInput->Trigger(DIK_M))
	{
		m_bSwitch = false;
	}

	m_p3DObject->Update();

	//イテレーターループ
	for (auto itr = m_BallastList.begin(); itr != m_BallastList.end();itr++)
	{
		//イテレーターから瓦礫のポインタの代入
		C3DObject* p3DObject = *itr;

		//瓦礫の更新
		if (p3DObject != nullptr)
		{
			p3DObject->Update();
		}
	}


	//外部ファイルに出力
	if (pInput->Trigger(DIK_F1))
	{
		CRead CRead;

		CRead.SaveEditorData(m_BallastList);
	}


	//設置を一個戻す
	if (pInput->Trigger(DIK_BACK))
	{
		//コンテナの中がなかったら
		if(m_BallastList.empty())
		{
			return;
		}

		//末端の取得
		C3DObject* p3DObject = m_BallastList.back();

		//瓦礫ポインタの解放
		if (p3DObject != nullptr)
		{
			//終了処理
			p3DObject->Uninit();
			delete p3DObject;
			p3DObject = nullptr;
		}

		//末端を破棄
		m_BallastList.pop_back();
	}

}

//*****************************************************************************
// 描画処理
//*****************************************************************************
void CPlayer::Draw()
{
	m_p3DObject->CalculationMatrix();
	m_p3DObject->Draw();
	//イテレーターループ
	for (auto itr = m_BallastList.begin(); itr != m_BallastList.end(); itr++)
	{
		//イテレーターから瓦礫のポインタの代入
		C3DObject* p3DObject = *itr;

		//瓦礫の描画
		if (p3DObject != nullptr)
		{
			p3DObject->CalculationMatrix();
			p3DObject->Draw();
		}
	}
}

//Posの移動
void CPlayer::MovePos()
{
	//入力デバイスの取得
	CInput* pInput = CInput::GetKey();
	//マネージャーからゲームオブジェクトの取得
	CManager *pManager = GetManager();
	CGame* pGame = (CGame*)pManager->GetGameObject();

	CTpsCamera* pTpsCamera = (CTpsCamera*)pGame->GetCamera();

	//カメラの向き（Y軸のみ）
	float rotY = pTpsCamera->GetRot();

	//視点移動
	if (pInput->Press(DIK_W))
	{//上キーが押された
		if (pInput->Press(DIK_A))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * 0.75f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * 0.75f) * m_MoveMagnification;
		}
		else if (pInput->Press(DIK_D))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * -0.75f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * -0.75f) * m_MoveMagnification;
		}
		else
		{
			m_Pos.x += sinf(rotY) * m_MoveMagnification;
			m_Pos.z += cosf(rotY) * m_MoveMagnification;
		}
	}
	else if (pInput->Press(DIK_S))
	{//下キーが押された
		if (pInput->Press(DIK_A))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * 0.25f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * 0.25f) * m_MoveMagnification;
		}
		else if (pInput->Press(DIK_D))
		{
			m_Pos.x -= sinf(rotY + D3DX_PI * -0.25f) * m_MoveMagnification;
			m_Pos.z -= cosf(rotY + D3DX_PI * -0.25f) * m_MoveMagnification;
		}
		else
		{
			m_Pos.x += sinf(rotY + D3DX_PI) * m_MoveMagnification;
			m_Pos.z += cosf(rotY + D3DX_PI) * m_MoveMagnification;
		}
	}
	else if (pInput->Press(DIK_A))
	{//左キーが押された
		m_Pos.x += sinf(rotY + D3DX_PI * -0.5f) * m_MoveMagnification;
		m_Pos.z += cosf(rotY + D3DX_PI * -0.5f) * m_MoveMagnification;
	}
	else if (pInput->Press(DIK_D))
	{//右キーが押された
		m_Pos.x += sinf(rotY + D3DX_PI * 0.5f) * m_MoveMagnification;
		m_Pos.z += cosf(rotY + D3DX_PI * 0.5f) * m_MoveMagnification;
	}

	if (pInput->Press(DIK_LSHIFT))
	{
		m_Pos.y += m_MoveMagnification;
	}
	else if (pInput->Press(DIK_LCONTROL))
	{
		m_Pos.y -= m_MoveMagnification;
	}

	//リセット
	if (!pInput->Press(DIK_0))
	{
		return;
	}

	if (pInput->Press(DIK_1))
	{
		m_Pos.x = 0.0f;
	}
	else if (pInput->Press(DIK_2))
	{
		m_Pos.y = 0.0f;
	}
	else if (pInput->Press(DIK_3))
	{
		m_Pos.z = 0.0f;
	}
	
}

//Rotの調整
void CPlayer::MoveRot()
{
	//入力デバイスの取得
	CInput* pInput = CInput::GetKey();

	if (pInput->Press(DIK_R))
	{
		m_Rot.x += D3DXToRadian(1);
	}
	else if (pInput->Press(DIK_T))
	{
		m_Rot.x -= D3DXToRadian(1);
	}

	if (pInput->Press(DIK_F))
	{
		m_Rot.y += D3DXToRadian(1);
	}
	else if (pInput->Press(DIK_G))
	{
		m_Rot.y -= D3DXToRadian(1);
	}

	if (pInput->Press(DIK_V))
	{
		m_Rot.z += D3DXToRadian(1);
	}
	else if (pInput->Press(DIK_B))
	{
		m_Rot.z -= D3DXToRadian(1);
	}


	//リセット
	if (!pInput->Press(DIK_0))
	{
		return;
	}

	if (pInput->Press(DIK_4))
	{
		m_Rot.x = 0.0f;
	}
	else if (pInput->Press(DIK_5))
	{
		m_Rot.y = 0.0f;
	}
	else if (pInput->Press(DIK_6))
	{
		m_Rot.z = 0.0f;
	}
}

//倍率の変更
void CPlayer::ChangeMagnification()
{
	//入力デバイスの取得
	CInput* pInput = CInput::GetKey();

	if (pInput->Press(DIK_LEFT))
	{
		m_MoveMagnification += MOVE_MAGNIFICATION;
	}
	else if (pInput->Press(DIK_RIGHT))
	{
		m_MoveMagnification -= MOVE_MAGNIFICATION;
	}

	//リセット
	if (!pInput->Press(DIK_0))
	{
		return;
	}

	if (pInput->Press(DIK_7))
	{
		m_MoveMagnification = MOVE_MAGNIFICATION;
	}
}

//表示モデルの変更
void CPlayer::ChangeModel()
{
	//入力デバイスの取得
	CInput* pInput = CInput::GetKey();
	bool bUes = false;

	if (pInput->Trigger(DIK_UP))
	{
		m_nModelNum++;
		bUes = true;
	}
	else if (pInput->Trigger(DIK_DOWN))
	{
		m_nModelNum--;
		bUes = true;
	}

	if (m_nModelNum >= m_nModelIndexMax)
	{
		m_nModelNum = 0;
	}
	else if (m_nModelNum < 0)
	{
		m_nModelNum = m_nModelIndexMax - 1;
	}

	if (bUes)
	{
		m_p3DObject->Uninit();
		m_p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], INIT_POS, INIT_POS);
	}
}

//チェンジサイズ
void CPlayer::ChangeSize()
{
	//入力デバイスの取得
	CInput* pInput = CInput::GetKey();
	bool bUes = false;

	if (pInput->Trigger(DIK_K))
	{
		m_fSize += m_MoveMagnification;
		bUes = true;
	}
	else if (pInput->Trigger(DIK_L))
	{
		m_fSize -= m_MoveMagnification;
		bUes = true;
	}
	//リセット
	if (pInput->Press(DIK_0) && pInput->Press(DIK_8))
	{
		m_fSize = 1.0f;
		bUes = true;
	}

	if (bUes)
	{
		m_p3DObject->Uninit();
		m_p3DObject->SetSize(m_fSize);
		m_p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], INIT_POS, m_Rot);
	}
}

//瓦礫の設置
void CPlayer::SetBullast()
{
	//瓦礫クラスの生成
	C3DObject* p3DObject = new C3DObject;

	//初期化
	if (FAILED(p3DObject->Init()))
	{
		assert(false);
	}

	//当たり判定
	p3DObject->SetCollision(m_bCollision);

	//オープニングロスト
	p3DObject->SetOpeningLost(m_bOpeningLost);

	//砲台
	p3DObject->SetSwitch(m_bSwitch);

	//モデル番号のインデックス
	p3DObject->SetModelNumIndex(m_nModelNum);

	//使用するモデル番号、瓦礫の位置、瓦礫の向き
	p3DObject->Set3DObject(m_pModelIndex[m_nModelNum], m_Pos, m_Rot);

	//法線設定
	p3DObject->SetNormal();

	//リストに瓦礫情報を追加
	m_BallastList.push_back(p3DObject);
}
