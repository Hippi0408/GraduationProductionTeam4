//**********************************************************************************************
// 
// texture.cpp
// Author  : tanimoto kosuke
// 
//**********************************************************************************************

//==============================================================================================
// �C���N���[�h
//==============================================================================================
#include "application.h"
#include "texture.h"
#include "renderer.h"

#include <assert.h>

//==============================================================================================
// ��`
//==============================================================================================
const char* CTexture::s_FileName[] =
{// �e�N�X�`���̃p�X
	"Data/texture/Font/Font_Japanese002.png",			// ���{��t�H���g
	"Data/texture/Font/Font_Japanese003.png",	// ���{��t�H���g
	"Data/texture/Font/Font_Alphabet.png",				// �A���t�@�x�b�g�t�H���g�t�H���g
	"Data/texture/number.png",						// �i���o�[�̃e�N�X�`��
	"Data/texture/bullet000.png",					// �e�̃e�N�X�`��
	"Data/texture/floor.png",						// �n�ʂ̃e�N�X�`��
	"Data/texture/reticle.png",						// ���e�B�N���̃e�N�X�`��
	"Data/texture/circle.png",						// �~�̃e�N�X�`��
	"Data/texture/UI_00.png",						// UI�̃e�N�X�`��

	/* �G�t�F�N�g�Q */
	"Data/texture/particle/smoke.png",				// ��
	"Data/texture/particle/flare.png",				// �G�t�F�N�g1
	"Data/texture/particle/star.png",				// �G�t�F�N�g2
	"Data/texture/particle/bright.png",				// �L���L��A
	"Data/texture/particle/bright2.png",			// �L���L��B
	"Data/texture/particle/ray.png",				// ���C
	"Data/texture/particle/coin.png",				// �R�C��
	"Data/texture/particle/jewel.png",				// �p�[�e�B�N���p���
	"Data/texture/particle/soul.png",				// ��
	"Data/texture/particle/up.png",					// ����
	"Data/texture/reticle.png",						// ���e�B�N��

};

static_assert(sizeof(CTexture::s_FileName) / sizeof(CTexture::s_FileName[0]) == CTexture::TEXTURE_MAX, "aho");

//----------------------------------------------------------------------------------------------
// �f�t�H���g�R���X�g���N�^
//----------------------------------------------------------------------------------------------
CTexture::CTexture() :
	s_pTexture()
{
	memset(s_pTexture, 0, sizeof(s_pTexture));
}

//----------------------------------------------------------------------------------------------
// �f�X�g���N�^
//----------------------------------------------------------------------------------------------
CTexture::~CTexture()
{
}

//----------------------------------------------------------------------------------------------
// �S�Ă̓ǂݍ���
//----------------------------------------------------------------------------------------------
void CTexture::LoadAll()
{
	// �f�o�C�X�ւ̃|�C���^�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	for (int i = 0; i < TEXTURE_MAX; ++i)
	{
		if (s_pTexture[i] != nullptr)
		{// �e�N�X�`���̓ǂݍ��݂�����Ă���
			continue;
		}

		// �e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(pDevice,
			s_FileName[i],
			&s_pTexture[i]);
	}
}

//----------------------------------------------------------------------------------------------
// �S�Ẳ��
//----------------------------------------------------------------------------------------------
void CTexture::ReleaseAll(void)
{
	for (int i = 0; i < TEXTURE_MAX; ++i)
	{
		if (s_pTexture[i] != NULL)
		{// �e�N�X�`���̉��
			s_pTexture[i]->Release();
			s_pTexture[i] = NULL;
		}
	}
}

//----------------------------------------------------------------------------------------------
// ���
//----------------------------------------------------------------------------------------------
void CTexture::Release(TEXTURE inTexture)
{
	assert(inTexture >= 0 && inTexture < TEXTURE_MAX);

	if (s_pTexture[inTexture] != NULL)
	{// �e�N�X�`���̉��
		s_pTexture[inTexture]->Release();
		s_pTexture[inTexture] = NULL;
	}
}

//----------------------------------------------------------------------------------------------
// �擾
//----------------------------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 CTexture::GetTexture(TEXTURE inTexture)
{
	if (inTexture == TEXTURE_NONE)
	{// �e�N�X�`�����g�p���Ȃ�
		return nullptr;
	}

	assert(inTexture >= 0 && inTexture < TEXTURE_MAX);

	return s_pTexture[inTexture];
}
