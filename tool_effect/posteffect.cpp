#include "posteffect.h"
#include "application.h"
#include "renderer.h"
#include "object2d.h"

CPostEffect::CPostEffect()
{
}

CPostEffect::~CPostEffect()
{
}

HRESULT CPostEffect::Init()
{
	// �f�o�C�X�̃|�C���^���擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetInstance()->GetRenderer()->GetDevice();

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,		// �m�ۂ���o�b�t�@�̃T�C�Y
		D3DUSAGE_WRITEONLY,									// ���\�[�X�̎g�p���@
		FVF_VERTEX_2D,										// ���_�t�H�[�}�b�g
		D3DPOOL_MANAGED,									// ���\�[�X�z�u�̃v�[���^�C�v
		&m_pVtxBuff,										// ���_�o�b�t�@���\�[�X
		NULL);

	VERTEX_2D* pVtx;		//���_���ւ̃|�C���^

	// ���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	// ���_����ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	// ���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	// �e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	// ���_�o�b�t�@�̃A�����b�N
	m_pVtxBuff->Unlock();

	return S_OK;
}

void CPostEffect::Apply() 
{
	CRenderer* pRender = CApplication::GetInstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRender->GetDevice();

	// �����_�[�^�[�Q�b�g�̐ݒ�
	pDevice->SetRenderTarget(0, pRender->GetTargetSurface());

	pDevice->SetTexture(0, nullptr);

	// Direct3D�ɂ��`��̊J�n
	if (SUCCEEDED(pDevice->BeginScene()))
	{
		// ���_�t�H�[�}�b�g�̐ݒ�
		pDevice->SetFVF(FVF_VERTEX_2D);

		// �|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,		// �v���~�e�B�u�̎��
			0,											// �ŏ��̒��_�C���f�b�N�X
			2);											// �v���~�e�B�u(�|���S��)��

		// Direct3D�ɂ��`��̏I��
		pDevice->EndScene();
	}

	// �����_�[�^�[�Q�b�g�����ɖ߂�
	pDevice->SetRenderTarget(0, pRender->GetOriginalSurface());
}