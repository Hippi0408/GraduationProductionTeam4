#include "instancing.h"
#include "application.h"
#include "renderer.h"
#include "shader_manager.h"
#include "camera.h"
#include "texture.h"
#include "utility.h"
#include "particle.h"

namespace
{
	template<typename T>
	void CopyBuffer(unsigned size, void* src, T* buf)
	{
		void *p = 0;
		buf->Lock(0, 0, &p, 0);
		memcpy(p, src, size);
		buf->Unlock();
	}

	struct WVP
	{
		D3DXMATRIX mtxWorld;
		D3DXMATRIX mtxView;
		D3DXMATRIX mtxProjection;
	};
}

CInstancing::CInstancing()
{
	std::vector<D3DVERTEXELEMENT9> elements;

	// �X�g���[���ԍ� 0
	elements.push_back({ 0, 0, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0});		// ���[�J�����W
	elements.push_back({ 0, 8, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 });		// UV

	// �X�g���[���ԍ� 1
	elements.push_back({ 1, 0, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 1});		// ���[���h���W
	elements.push_back({ 1, 12, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 1 });		// �F
	elements.push_back(D3DDECL_END());

	// ���_�錾�I�u�W�F�N�g�̐���
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	pDevice->CreateVertexDeclaration(elements.data(), &m_decl);
}

CInstancing::~CInstancing()
{
}

CInstancing * CInstancing::Create(std::vector<CParticle*> data, std::string tex, int num)
{
	CInstancing *pParticle = new CInstancing;

	if (pParticle != nullptr)
	{
		pParticle->m_particles = data;
		pParticle->m_texTag = tex;
		pParticle->m_numInstance = num;
		pParticle->Init();
	}
	else
	{
		assert(false);
	}

	return pParticle;
}

HRESULT CInstancing::Init()
{
	m_shaderLabel = "Instancing";
	BindTexture(m_texTag);

	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	SVertex vtx[4];
	for (int i = 0; i < 4; i++)
	{
		vtx[i].vtx.x = (i % 2 == 0) ? -10.0f : 10.0f;
		vtx[i].vtx.y = (i < 2) ? -10.0f : 10.0f;
		vtx[i].uv.x = (i % 2 == 0) ? 0.0f : 1.0f;
		vtx[i].uv.y = (i < 2) ? 0.0f : 1.0f;
	}

	std::vector<SInstancingData> instData(m_numInstance);
	for (auto& p : instData)
	{
		p.worldPos = m_pos;
		p.col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}

	// �o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(vtx), 0, 0, D3DPOOL_MANAGED, &m_pVtxBuff, 0);
	CopyBuffer(sizeof(vtx), vtx, m_pVtxBuff);

	// �C���f�b�N�X�o�b�t�@�̐���
	WORD indices[] = { 0, 1, 2, 1, 3, 2 };
	pDevice->CreateIndexBuffer(sizeof(WORD) * 6, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &m_pIdxBuff, 0);
	CopyBuffer(sizeof(indices), indices, m_pIdxBuff);

	pDevice->CreateVertexBuffer(sizeof(SInstancingData) * m_numInstance, 0, 0, D3DPOOL_MANAGED, &m_pInstancingBuff, 0);
	CopyBuffer(sizeof(SInstancingData) * m_numInstance, instData.data(), m_pInstancingBuff);

	CShaderManager* pShader = CApplication::GetInstance()->GetShaderManager();
	if (!m_shaderLabel.empty())
	{
		m_handler.technique = pShader->GetTechniqueCache(m_shaderLabel, "TechShader");
		m_handler.wvp = pShader->GetParameterCache(m_shaderLabel, "g_wvp");
		m_handler.tex = pShader->GetParameterCache(m_shaderLabel, "g_tex");
		m_handler.camPos = pShader->GetParameterCache(m_shaderLabel, "g_cameraPos"); 
	}

	return S_OK;
}

void CInstancing::Uninit()
{
	if(m_decl != nullptr)
	{
		m_decl->Release();
		m_decl = nullptr;
	}

	if (m_pIdxBuff != nullptr)
	{
		m_pIdxBuff->Release();
		m_pIdxBuff = nullptr;
	}

	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}

	if (m_pInstancingBuff != nullptr)
	{
		m_pInstancingBuff->Release();
		m_pInstancingBuff = nullptr;
	}

	Destroy();
}

void CInstancing::Update()
{
	std::vector<SInstancingData> instData(m_numInstance);
	int index = 0;
	for(auto& p : m_particles)
	{
		if (index >= m_numInstance)
		{
			break;
		}
		instData[index].worldPos = p->GetPos();
		instData[index].col = p->GetCol();
		index++;
	}
	CopyBuffer(sizeof(SInstancingData) * m_numInstance, instData.data(), m_pInstancingBuff);
}

void CInstancing::Draw()
{
	LPD3DXEFFECT pEffect = CApplication::GetInstance()->GetShaderManager()->GetEffect(m_shaderLabel);
	CShaderManager *pShaderManager = CApplication::GetInstance()->GetShaderManager();
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();
	CCamera *pCamera = CApplication::GetInstance()->GetCamera();
	D3DXMATRIX mtxTrans, mtxRot, mtxScale;

	// ���Z����
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	// �A���t�@�e�X�g
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	// �J�������猩�ċ߂��������㏑��
	pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	// �C���X�^���X�錾
	pDevice->SetStreamSourceFreq(0, D3DSTREAMSOURCE_INDEXEDDATA | m_numInstance);
	pDevice->SetStreamSourceFreq(1, D3DSTREAMSOURCE_INSTANCEDATA | 1);

	// ���_�錾�I�u�W�F�N�g�̐ݒ�
	pDevice->SetVertexDeclaration(m_decl);

	// �o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(SVertex));
	pDevice->SetStreamSource(1, m_pInstancingBuff, 0, sizeof(SInstancingData));

	// �C���f�b�N�X�o�b�t�@�̐ݒ�
	pDevice->SetIndices(m_pIdxBuff);

	// �}�g���b�N�X�̎擾
	WVP worldViewProjection = {};
	D3DXMatrixIdentity(&worldViewProjection.mtxWorld);
	worldViewProjection.mtxView = pCamera->GetCamera()->mtxView;
	worldViewProjection.mtxProjection = pCamera->GetCamera()->mtxProjection;

	// �J�����ʒu�̐ݒ�
	pEffect->SetValue(m_handler.camPos, pCamera->GetCamera()->posV, sizeof(D3DXVECTOR3));

	// �e�N�X�`���̐ݒ�
	pEffect->SetTexture(m_handler.tex, m_pTexture);

	// �e�N�j�b�N�̐ݒ�
	pEffect->SetTechnique(m_handler.technique);

	// �V�F�[�_�[�̓K�p
	pShaderManager->Apply(m_shaderLabel);

	// �}�g���b�N�X�̐ݒ�
	pEffect->SetValue(m_handler.wvp, &worldViewProjection, sizeof(WVP));

	for (int i = 0; i < m_numInstance; i++)
	{
		// �|���S���̕`��
		pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
	}

	// �V�F�[�_�[�̏I��
	pShaderManager->End(m_shaderLabel);

	// �C���X�^���X�̐ݒ�����ɖ߂�
	pDevice->SetStreamSourceFreq(0, 1);
	pDevice->SetStreamSourceFreq(1, 1);

	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// �A���t�@�e�X�g�𖳌�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
}

//��������������������������������������������������������������
// �e�N�X�`�����o�C���h
//��������������������������������������������������������������
void CInstancing::BindTexture(std::string inPath)
{
	m_pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//�e�N�X�`���̃|�C���^
}
