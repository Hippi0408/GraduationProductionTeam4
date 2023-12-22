//============================================================================
//
// fog.cpp (�t�H�O.cpp)
// Author : Saito Shian
//
//============================================================================

//============================================================================
// �C���N���[�h
//============================================================================
#include "fog.h"
#include "application.h"
#include "renderer.h"
#include "object.h"
#include "input.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
bool CFog::m_bCreate = false;
bool CFog::m_bIntensityFlag = false;
float CFog::m_fIntensity = 0.0f;
float CFog::m_fIntensityDest = 0.5f;

float CFog::m_fFogStartPos = 0.0f;
float CFog::m_fFogEndPos = 0.0f;


//============================================================================
// �R���X�g���N�^
//============================================================================
CFog::CFog()
{
}

//============================================================================
// �f�X�g���N�^
//============================================================================
CFog::~CFog()
{
}

//============================================================================
// �t�H�O�̐ݒ菈��
//============================================================================
void CFog::SetFog(D3DXCOLOR col)
{
	// ���̓f�o�C�X�̏��
	CInput* pInput = CInput::GetKey();
	m_fIntensityDest = 0.0005f;

	// �t�H�O�̐���
	if (pInput->Trigger(DIK_O) && m_bCreate == false)
	{
		m_bIntensityFlag = true;
	}
	// �t�H�O�̍폜
	else if (pInput->Trigger(DIK_O) && m_bCreate == true && m_bIntensityFlag == true)
	{
		m_bIntensityFlag = false;
	}

	if (m_bIntensityFlag == false && m_bCreate == true)
	{
		// �f�o�C�X�̎擾
		LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();
		//���x�w��(��EXP���Ɏw��)
		m_fIntensity -= 0.000001f;
		pDevice->SetRenderState(D3DRS_FOGDENSITY, *(DWORD*)(&m_fIntensity));

		if (m_fIntensity <= 0.0f)
		{
			//�t�H�O�̗L���ݒ�
			pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
			m_bCreate = false;
		}
	}

	if (m_bIntensityFlag == true && m_bCreate == false)
	{
		// �f�o�C�X�̎擾
		LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

		//�t�H�O�̗L���ݒ�
		pDevice->SetRenderState(D3DRS_FOGENABLE, TRUE);

		//�t�H�O�J���[
		pDevice->SetRenderState(D3DRS_FOGCOLOR, D3DXCOLOR(col.a, col.g, col.b, col.a));

		//�t�H�O�̃��[�h(�͈͎w��:D3DFOG_LINEAR,���x�w��:D3DFOG_EXP)
		pDevice->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_EXP);

		//���x�w��(��EXP���Ɏw��)
		m_fIntensity += 0.000001f;
		pDevice->SetRenderState(D3DRS_FOGDENSITY, *(DWORD*)(&m_fIntensity));
	}
	if (m_fIntensity >= m_fIntensityDest)
	{
		m_fIntensity = m_fIntensityDest;
		m_bCreate = true;
	}

}
