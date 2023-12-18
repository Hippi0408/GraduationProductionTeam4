//==============================================================================================
//
// 拘束スイッチ　　　restraint_switch.cpp
// tutida ryousei
//
//==============================================================================================
#include"restraint_switch.h"
#include"objectX.h"
#include "debugProc.h"

int CRestraint_Switch::m_nCount_Switch = 0;

//==============================================================================================
// コンストラクタ
//==============================================================================================
CRestraint_Switch::CRestraint_Switch(const PRIORITY priority) : CMove_Object(priority)
{
}

//==============================================================================================
// デストラクタ
//==============================================================================================
CRestraint_Switch::~CRestraint_Switch()
{
}

//==============================================================================================
// 初期化処理
//==============================================================================================
HRESULT CRestraint_Switch::Init()
{
	CMove_Object::Init();

	// 当たり判定の設定
	SetCollision();

	// 当たり判定のタイプ
	SetCollision_Type(CMove_Object::COLLISION_TYPE_BLOCK);

	// タグの設定
	SetTag(TAG_MAP_OBJECT);

	D3DXVECTOR3 Max = GetObjectX()->GetMaxSize();
	D3DXVECTOR3 Min = GetObjectX()->GetMinSize();

	SetIndex({ Min.x,0.0f,Min.z }, 0);
	SetIndex({ Min.x,0.0f,Max.z }, 1);
	SetIndex({ Max.x,0.0f,Max.z }, 2);
	SetIndex({ Max.x,0.0f,Min.z }, 3);

	SetCenterPos({ 0.0f,Max.y / 2,0.0f });
	SetSize(GetObjectX()->GetMaxSize());

	return S_OK;
}

//==============================================================================================
// 終了処理
//==============================================================================================
void CRestraint_Switch::Uninit()
{
	CMove_Object::Uninit();
}

//==============================================================================================
// 更新処理
//==============================================================================================
void CRestraint_Switch::Update()
{
	CMove_Object::Update();

	m_bHit = false;

	//CDebugProc::Print("%d", m_nCount_Switch);
}

//==============================================================================================
// 描画処理
//==============================================================================================
void CRestraint_Switch::Draw()
{

}

//==============================================================================================
// ヒット処理
//==============================================================================================
void CRestraint_Switch::Hit(CMove_Object* pHit)
{
	if (!m_bPush && pHit->GetTag() == TAG_CHARACTER && pHit->GetPlayerSide())
		m_bHit = true;
}

//==============================================================================================
// 生成処理
//==============================================================================================
CRestraint_Switch *CRestraint_Switch::Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 rot, CObjectX* parent, const char* Xfilename, const PRIORITY priority)
{
	CRestraint_Switch *pRestraint = new	CRestraint_Switch(priority);

	if (pRestraint != nullptr)
	{
		pRestraint->SetObjectX(CObjectX::Create(pos, rot, parent, Xfilename, priority));
		pRestraint->SetPos(pos);
		pRestraint->Init();
	}

	return pRestraint;
}