#include "application.h"
#include "renderer.h"
#include "mesh_particle.h"
#include "trail.h"
#include "utility.h"
#include "model.h"
#include "object3d.h"
#include "shader_manager.h"
#include "camera.h"

namespace
{
	struct WVP
	{
		D3DXMATRIX mtxWorld;
		D3DXMATRIX mtxView;
		D3DXMATRIX mtxProjection;
	};
}

//��������������������������������������������������������������
// �p�[�e�B�N���̃R���X�g���N�^
//��������������������������������������������������������������
CMeshParticle::CMeshParticle(int nPriority) :
	CObject(CObject::PRIORITY_THIRD),
	m_info({}),
	m_nTime(0)			// ����
{
}

//��������������������������������������������������������������
// �p�[�e�B�N���̃f�X�g���N�^
//��������������������������������������������������������������
CMeshParticle::~CMeshParticle()
{
}

//��������������������������������������������������������������
// �p�[�e�B�N���̐���
//��������������������������������������������������������������
CMeshParticle * CMeshParticle::Create(SInfo& info, int nPriority)
{
	CMeshParticle *pParticle = new CMeshParticle(nPriority);

	if (pParticle != nullptr)
	{
		pParticle->SetInfo(info);
		pParticle->Init();
	}
	else
	{
		assert(false);
	}

	return pParticle;
}

//��������������������������������������������������������������
// �p�[�e�B�N���̏�����
//��������������������������������������������������������������
HRESULT CMeshParticle::Init()
{
	// �e�N�X�`���̓ǂݍ���
	if (m_info.useTexture)
	{
		BindTexture(m_info.texTag);
		BindMaskTexture(m_info.maskTexTag);
	}

	// ���f���̓ǂݍ���
	LoadModel(m_info.modelTag);

	m_DestroyTime = m_info.popTime;

	if (m_info.color.randomColor)
	{
		m_info.color.col = D3DXCOLOR(utility::Random(m_info.color.randomMax, m_info.color.randomMin),
			utility::Random(m_info.color.randomMax, m_info.color.randomMin),
			utility::Random(m_info.color.randomMax, m_info.color.randomMin),
			m_info.color.col.a);
	}

	if (m_info.useTrail)
	{
		m_pTrail = std::move(m_pTrail->Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), m_mtxWorld));
	}

	if (m_info.randomWeight)
	{
		m_info.weight = utility::Random(m_info.randomWeightMax, m_info.randomWeightMin);
	}

	if (!m_info.useShader)
	{
		return S_OK;
	}

	m_uv = D3DXVECTOR2(0.0f, 1.0f);

	m_shaderLabel = "UVAnimation";
	CShaderManager* pShader = CApplication::GetInstance()->GetShaderManager();
	if (!m_shaderLabel.empty())
	{
		m_handler.technique = pShader->GetTechniqueCache(m_shaderLabel, "TechShader");
		m_handler.wvp = pShader->GetParameterCache(m_shaderLabel, "g_wvp");
		m_handler.animationUV = pShader->GetParameterCache(m_shaderLabel, "g_animationUV");
		m_handler.maskTexture = pShader->GetParameterCache(m_shaderLabel, "g_maskTexture");
		m_handler.haveMaskTexture = pShader->GetParameterCache(m_shaderLabel, "g_hasMaskTexture");
		m_handler.diffuse = pShader->GetParameterCache(m_shaderLabel, "g_diffuse");
	}

	return S_OK;
}

//��������������������������������������������������������������
// �p�[�e�B�N���̔j��
//��������������������������������������������������������������
void CMeshParticle::Uninit()
{
	if (m_pTrail != nullptr)
	{
		m_pTrail->Destroy();
	}

	if (m_modelData.empty())
	{
		m_modelData.clear();
	}

	Destroy();
}

//��������������������������������������������������������������
// �p�[�e�B�N���̍X�V
//��������������������������������������������������������������
void CMeshParticle::Update()
{
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

	D3DXVECTOR3 velocity = m_info.move;
	m_info.pos += m_info.move;

	// ���f���̑傫��
	m_info.scale += m_info.scalingValue;

	// ���f���̉�]��
	m_info.rot.y += m_info.rotationVolume;

	if (m_info.rotate.useRotate)
	{
		velocity = D3DXVECTOR3(m_info.move.x + (m_info.rotate.angle * m_info.rotate.radius) * sinf(D3DXToRadian(m_info.rotate.angle)),
			velocity.y,
			m_info.move.z + (m_info.rotate.angle * m_info.rotate.radius) * cosf(D3DXToRadian(m_info.rotate.angle)));

		m_info.move = velocity;

		m_info.rotate.angle += utility::Random(m_info.rotate.randomMax, m_info.rotate.randomMin);
	}

	// ����
	if (m_nTime >= m_info.fallDelayTime)
	{
		m_info.move.y -= m_info.weight;
	}

	// �F�֌W
	if (m_info.color.destCol.r >= 0.0f && m_info.color.destCol.g >= 0.0f && m_info.color.destCol.b >= 0.0f)
	{
		m_info.color.col.r += (m_info.color.destCol.r - m_info.color.col.r) / (m_info.popTime * m_info.color.colAttenuation);
		m_info.color.col.g += (m_info.color.destCol.g - m_info.color.col.g) / (m_info.popTime * m_info.color.colAttenuation);
		m_info.color.col.b += (m_info.color.destCol.b - m_info.color.col.b) / (m_info.popTime * m_info.color.colAttenuation);
	}
	if (m_info.color.destCol.a >= 0.0f)
	{
		m_info.color.col.a += (m_info.color.destCol.a - m_info.color.col.a) / (m_info.popTime * m_info.color.colAttenuation);
	}

	m_nTime++;

	if (m_pTrail != nullptr)
	{
		m_pTrail->SetColor(m_info.color.destCol, m_info.color.col);
		m_pTrail->SetMtxParent(m_mtxWorld);
	}

	m_DestroyTime--;

	// �����̐��K��
	utility::AngleNormalize(m_info.rot.y);
}

//��������������������������������������������������������������
// �p�[�e�B�N���̕`��
//��������������������������������������������������������������
void CMeshParticle::Draw()
{
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

	if (m_info.useShader)
	{
		AnimationDraw();
		return;
	}

	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	D3DXMATRIX mtxTrans, mtxScale, mtxRot;		// �v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;						// ���݂̃}�e���A����ۑ�
	D3DXMATERIAL *pMat;							// �}�e���A���f�[�^�ւ̃|�C���^

	// �e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, NULL);

	// ���[���h�}�g���b�N�X��������
	D3DXMatrixIdentity(&m_mtxWorld);

	// �����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_info.rot.y, m_info.rot.x, m_info.rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �s��g�k�֐�
	D3DXMatrixScaling(&mtxScale, m_info.scale.x, m_info.scale.y, m_info.scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_info.pos.x, m_info.pos.y, m_info.pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// Z�e�X�g
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// �A���t�@�e�X�g
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 210);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);

	// ���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	// ���݂̃}�e���A����ۑ�
	pDevice->GetMaterial(&matDef);

	for (auto &p : m_modelData)
	{
		// �}�e���A���f�[�^�ւ̃|�C���^���擾
		pMat = (D3DXMATERIAL*)p.buffMat->GetBufferPointer();
		pMat->MatD3D.Diffuse = m_info.color.col;
		pMat->MatD3D.Emissive = m_info.color.col * m_info.color.emissive;

		for (int j = 0; j < (int)p.dwNum; j++)
		{
			// �}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat->MatD3D);

			// �e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, m_pTexture);

			// ���f���p�[�c�̕`��
			p.mesh->DrawSubset(j);
		}

		// �G�~�b�V�u�͓����f���̑��I�u�W�F�N�g�ɂ��e�����Ă��邽�߁A���ɖ߂�
		pMat->MatD3D.Emissive = D3DXCOLOR(0.0f,0.0f,0.0f,1.0f);
	}

	// �ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

	// Z�o�b�t�@�̐ݒ�����ɖ߂�
	pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
	pDevice->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);

	// �A���t�@�e�X�g�𖳌�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// �e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, NULL);
}

void CMeshParticle::AnimationDraw()
{
	LPD3DXEFFECT pEffect = CApplication::GetInstance()->GetShaderManager()->GetEffect(m_shaderLabel);
	CShaderManager *pShaderManager = CApplication::GetInstance()->GetShaderManager();
	CCamera *pCamera = CApplication::GetInstance()->GetCamera();
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();	//�f�o�C�X�̎擾
	D3DXMATRIX mtxTrans, mtxScale, mtxRot;			// �v�Z�p�}�g���b�N�X
	D3DMATERIAL9 matDef;							// ���݂̃}�e���A����ۑ�
	D3DXMATERIAL *pMat;								// �}�e���A���f�[�^�ւ̃|�C���^

	// �e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, nullptr);
	pDevice->SetTexture(1, nullptr);

	// ���[���h�}�g���b�N�X��������
	D3DXMatrixIdentity(&m_mtxWorld);

	// �����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_info.rot.y, m_info.rot.x, m_info.rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	// �ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_info.pos.x, m_info.pos.y, m_info.pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	// �s��g�k�֐�
	D3DXMatrixScaling(&mtxScale, m_info.scale.x, m_info.scale.y, m_info.scale.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxScale);

	// �A���t�@�e�X�g
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	pDevice->SetRenderState(D3DRS_ALPHAREF, 0);
	pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);

	// ���Z����
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	// ���݂̃}�e���A����ۑ�
	pDevice->GetMaterial(&matDef);

	// ���_�錾�I�u�W�F�N�g�̐ݒ�
	pDevice->SetVertexDeclaration(pShaderManager->GetVertexDeclaration());

	// �e�N�X�`����UV�A�j���[�V�����ݒ�
	m_uv += m_info.moveUV;
	pEffect->SetFloatArray(m_handler.animationUV, m_uv, sizeof(D3DXVECTOR2));

	// �}�g���b�N�X�̐ݒ�
	WVP worldViewProjection = {};
	worldViewProjection.mtxWorld = m_mtxWorld;
	worldViewProjection.mtxView = pCamera->GetCamera()->mtxView;
	worldViewProjection.mtxProjection = pCamera->GetCamera()->mtxProjection;
	pEffect->SetValue(m_handler.wvp, &worldViewProjection, sizeof(WVP));

	// �e�N�X�`���̐ݒ�
	bool hasMain = (m_pTexture != nullptr);
	pEffect->SetBool(m_handler.haveMainTexture, hasMain);
	pDevice->SetTexture(0, m_pTexture);

	// �}�X�N�p�e�N�X�`���̐ݒ�
	bool hasMask = (m_pMaskTexture != nullptr);
	pEffect->SetBool(m_handler.haveMaskTexture, hasMask);
	pDevice->SetTexture(1, m_pMaskTexture);

	// �F�̐ݒ�
	pEffect->SetFloatArray(m_handler.diffuse, m_info.color.col, sizeof(D3DXCOLOR));

	// �e�N�j�b�N�̐ݒ�
	pEffect->SetTechnique(m_handler.technique);

	// �V�F�[�_�[�̓K�p
	pShaderManager->Apply(m_shaderLabel);

	for (auto& p : m_modelData)
	{
		// �}�e���A���f�[�^�ւ̃|�C���^���擾
		pMat = (D3DXMATERIAL*)p.buffMat->GetBufferPointer();
		pMat->MatD3D.Diffuse = m_info.color.col;
		pMat->MatD3D.Emissive = m_info.color.col * m_info.color.emissive;

		for (int j = 0; j < (int)p.dwNum; j++)
		{
			// �}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat->MatD3D);

			// ���f���p�[�c�̕`��
			p.mesh->DrawSubset(j);
		}

		// �G�~�b�V�u�͓����f���̑��I�u�W�F�N�g�ɂ��e�����Ă��邽�߁A���ɖ߂�
		pMat->MatD3D.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	}

	// �V�F�[�_�[�̏I��
	pShaderManager->End(m_shaderLabel);

	// �ێ����Ă����}�e���A����߂�
	pDevice->SetMaterial(&matDef);

	// �A���t�@�e�X�g�𖳌�
	pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);

	// �ݒ�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	// �e�N�X�`���̐ݒ��߂�
	pDevice->SetTexture(0, nullptr);
	pDevice->SetTexture(1, nullptr);
}

//��������������������������������������������������������������
// �p�[�e�B�N���̃e�N�X�`�����o�C���h
//��������������������������������������������������������������
void CMeshParticle::BindTexture(const std::string& inPath)
{
	m_pTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//�e�N�X�`���̃|�C���^
}

void CMeshParticle::BindMaskTexture(const std::string& inPath)
{
	m_pMaskTexture = CApplication::GetInstance()->GetTexture()->GetTexture(inPath);		//�e�N�X�`���̃|�C���^
}

//��������������������������������������������������������������
// ���b�V���̃��f���f�[�^���擾
//��������������������������������������������������������������
void CMeshParticle::LoadModel(const std::string& path)
{
	// ���f���f�[�^�̃|�C���^���擾
	CModel *pModel = CApplication::GetInstance()->GetModel();

	CModel::SModelData data = {};
	data = std::move(pModel->GetModelStructure(path));

	m_modelData.push_back(data);
}
