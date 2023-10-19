#include "application.h"
#include "renderer.h"
#include "particle.h"
#include "trail.h"
#include "utility.h"
#include "particle_emitter.h"
#include "shader_manager.h"

namespace
{
	const int startCollisionTime = 30;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルのコンストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CParticle::CParticle(int nPriority) :
	CBillboard(CObject::PRIORITY_THIRD),
	m_info({}),
	m_pGrid(nullptr),
	m_nTime(0)			// 時間
{
	// 物理クラスの生成
	m_pPhysics = new CPhysics;

	CObject::SetObjType(CObject::OBJTYPE_PARTICLE);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルのデストラクタ
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CParticle::~CParticle()
{
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの生成
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
CParticle * CParticle::Create(SInfo& info, const std::string& url, int nPriority, CGrid* grid, CParticleEmitter* emitter)
{
	CParticle *pParticle = new CParticle(nPriority);

	if (pParticle != nullptr)
	{
		pParticle->SetInfo(info);
		pParticle->SetPath(url);
		pParticle->m_pEmitter = emitter;
		pParticle->m_pGrid = grid;
		pParticle->Init();
	}
	else
	{
		assert(false);
	}

	return pParticle;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの初期化
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
HRESULT CParticle::Init()
{
	CBillboard::SetShaderLabel("TEST");

	// テクスチャの読み込み
	BindTexture(m_path);

	// オブジェクトの初期化
	CBillboard::Init();

	CBillboard::SetPos(m_info.pos);
	CBillboard::SetMove(m_info.move);
	CBillboard::SetCol(m_info.col);
	CBillboard::SetScale(m_info.scale);
	CBillboard::SetBlendState(m_info.blendState);

	D3DXMATRIX mtx = CBillboard::GetMtxWorld();
	m_DestroyTime = m_info.popTime;

	if (m_info.useTrail)
	{	// トレイルを使用する場合
		m_pTrail = std::move(m_pTrail->Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), mtx, m_info.trailInfo.texPath));
	}

	if (m_info.useAnimation)
	{
		CBillboard::SetAnimation(m_info.animation.u, m_info.animation.v, m_info.animation.speed, 15, m_info.animation.loop);
	}

	if (m_info.useRandom)
	{	// ランダムな値を使用する場合
		m_info.weight = utility::Random<float>(m_info.random.randomWeight.x, m_info.random.randomWeight.y);
		m_info.velocity = D3DXVECTOR3(utility::Random<float>(m_info.random.randomVelocityMax.x, m_info.random.randomVelocityMin.x),
			utility::Random<float>(m_info.random.randomVelocityMax.y, m_info.random.randomVelocityMin.y),
			utility::Random<float>(m_info.random.randomVelocityMax.z, m_info.random.randomVelocityMin.z));
	}

	if (m_info.random.randomRotate != D3DXVECTOR2(0.0f, 0.0f))
	{	// ランダムな回転量を使用する場合
		m_info.rotateValue = utility::Random<float>(m_info.random.randomRotate.x, m_info.random.randomRotate.y);
	}

	// グリッドにパーティクルを配置
	if (m_pGrid != nullptr)
	{
		m_pGrid->PlaceObject(this);
	}

	return S_OK;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの破棄
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticle::Uninit()
{
	if (m_pGrid != nullptr)
	{
		m_pGrid->RemoveObject(this);
	}

	if (m_pTrail != nullptr)
	{
		m_pTrail->Destroy();
	}

	// 物理クラスの破棄
	if (m_pPhysics != nullptr)
	{
		delete m_pPhysics;
		m_pPhysics = nullptr;
	}

	CBillboard::Uninit();
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの更新
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticle::Update()
{
	if (m_info.isInstancing)
	{
		InstancingUpdate();
		return;
	}

	m_delayStartTime++;
	if (m_info.beginDelay >= m_delayStartTime)
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Pause();
		}
		return;
	}
	else
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Resume();
		}
	}

	CBillboard::Update();

	D3DXVECTOR3 pos = CBillboard::GetPos();
	D3DXVECTOR3 move = CBillboard::GetMove();
	D3DXVECTOR3 scale = CBillboard::GetScale();
	D3DXCOLOR col = CBillboard::GetCol();
	D3DXMATRIX mtx = CBillboard::GetMtxWorld();

	// テクスチャの大きさ
	scale += m_info.scalingValue;

	if (m_info.rotate.useRotate)
	{
		move = D3DXVECTOR3(m_info.move.x + (m_info.rotate.angle * m_info.rotate.radius) * sinf(D3DXToRadian(m_info.rotate.angle)),
			move.y,
			m_info.move.z + (m_info.rotate.angle * m_info.rotate.radius) * cosf(D3DXToRadian(m_info.rotate.angle)));
		
		m_info.rotate.angle += utility::Random(m_info.rotate.randomMax, m_info.rotate.randomMin);
	}

	// 落下
	if (m_nTime >= m_info.fallDelayTime)
	{
		move.y -= m_info.weight;
	}

	// 色関係
	if (m_info.destCol.r >= 0.0f && m_info.destCol.g >= 0.0f && m_info.destCol.b >= 0.0f)
	{
		col.r += (m_info.destCol.r - col.r) / (m_info.popTime * m_info.colAttenuation);
		col.g += (m_info.destCol.g - col.g) / (m_info.popTime * m_info.colAttenuation);
		col.b += (m_info.destCol.b - col.b) / (m_info.popTime * m_info.colAttenuation);
	}
	if (m_info.destCol.a >= 0.0f)
	{
		col.a += (m_info.destCol.a - col.a) / (m_info.popTime * m_info.colAttenuation);
	}

	m_info.physics.velocity = move;

	static int collisionTime = 0;
	collisionTime++;
	if (m_pEmitter != nullptr && m_info.usePhysics && startCollisionTime < collisionTime)
	{
		m_pEmitter->CheckCollision(this);
	}

	// 物理設定処理
	ProcessPhysics(m_info.physicsType, move);

	move += m_info.velocity * 0.4f;

	CBillboard::SetMove(move);
	CBillboard::SetScale(scale);
	CBillboard::SetCol(col);
	CBillboard::Rotate(m_info.rotateValue);

	m_nTime++;

	if (m_pTrail != nullptr)
	{
		CTrail::SInfo trailData = {};
		trailData = m_info.trailInfo;

		if (m_info.separateTrail)
		{
			trailData.beginCol = m_info.trailInfo.beginCol;
			trailData.endCol = m_info.trailInfo.endCol;
		}
		else
		{
			trailData.beginCol = m_info.col;
			trailData.endCol = m_info.destCol;
		}
		m_pTrail->SetTrail(mtx, trailData);
	}

	if (m_pGrid != nullptr && m_info.usePhysics)
	{
		SetGrid();
	}

	m_DestroyTime--;
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの描画
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticle::Draw()
{
	if (m_info.isInstancing)
	{
		return;
	}

	if (m_info.beginDelay >= m_delayStartTime)
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Invisible();
		}
		return;
	}
	else
	{
		if (m_pTrail != nullptr)
		{
			m_pTrail->Visible();
		}
	}

	// デバイスのポインタを取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	// ライトを無効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	// Zテスト
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);

	// アルファテスト
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	// 合成モードの設定
	CBillboard::Blending(GetBlendState());

	// サンプラーステートの設定
	pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);

	CBillboard::Draw(GetShaderLabel());

	// ライトを有効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);

	// Zバッファの設定を元に戻す
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// アルファテストを無効
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// 設定を元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// サンプラーステートの設定を元に戻す
	pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルの物理設定
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticle::ProcessPhysics(CPhysics::EPhysicsType state, D3DXVECTOR3& move)
{
	switch (state)
	{
	case CPhysics::EPhysicsType::PHYSICS_AIR:
		if (m_info.collision && m_collisionData != nullptr)
		{
			CPhysics::SPhysics anotherPhysics = m_collisionData->GetInfo().physics;
			m_pPhysics->SetPhysics(m_info.physics);
			move = m_pPhysics->ProcessPhysics(&m_info.physics, m_info.physicsType, &anotherPhysics);
			m_info.collision = false;
		}
		break;

	case CPhysics::EPhysicsType::PHYSICS_BOUNCE:
		if (m_pPhysics->PointPlaneCollision(GetPos(), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f), m_info.physics.velocity, m_info.physics.bounce.normal))
		{
			m_pPhysics->SetPhysics(m_info.physics);
			move = m_pPhysics->ProcessPhysics(&m_info.physics, m_info.physicsType);
		}
		break;

	default:
		break;
	}
}

//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// パーティクルのグリッドの設定
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
void CParticle::SetGrid()
{
	if (m_pGrid == nullptr && !m_pGrid->CheckGridChange(this))
	{	// 別のセルに移動していない場合
		return;
	}

	// 既存のグリッドからパーティクルを削除
	if (m_pGrid != nullptr)
	{
		m_pGrid->RemoveObject(this);
	}

	m_pGrid->PlaceObject(this); // パーティクルを新規グリッドに配置
}

void CParticle::InstancingUpdate()
{
	D3DXVECTOR3 pos = CBillboard::GetPos();
	D3DXCOLOR col = CBillboard::GetCol();

	pos += m_info.move * m_info.moveAttenuation;
	CBillboard::SetPos(pos);

	if (m_info.destCol.r >= 0.0f && m_info.destCol.g >= 0.0f && m_info.destCol.b >= 0.0f)
	{
		col.r += (m_info.destCol.r - col.r) / (m_info.popTime * m_info.colAttenuation);
		col.g += (m_info.destCol.g - col.g) / (m_info.popTime * m_info.colAttenuation);
		col.b += (m_info.destCol.b - col.b) / (m_info.popTime * m_info.colAttenuation);
	}
	if (m_info.destCol.a >= 0.0f)
	{
		col.a += (m_info.destCol.a - col.a) / (m_info.popTime * m_info.colAttenuation);
	}
	CBillboard::SetCol(col);

	m_DestroyTime--;
}