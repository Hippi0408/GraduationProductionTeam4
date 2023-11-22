//**********************************************************************************************
// 
// texture.h
// Author  : tanimoto kosuke
// 
//**********************************************************************************************
#ifndef _TEXTURE_H_	//���̃}�N����`������ĂȂ�������
#define _TEXTURE_H_	//�Q�d�C���N���[�h�h�~�̃}�N����`

//==============================================================================================
// �C���N���[�h
//==============================================================================================
#include <d3dx9.h>

//==============================================================================================
// ��`
//==============================================================================================
class CTexture
{
public: /* ��` */
	enum TEXTURE
	{	
		TEXTURE_FONT_JAPANESE,		// ���{��t�H���g
		TEXTURE_FONT_ALPHABET,		// �A���t�@�x�b�g�t�H���g
		TEXTURE_NUMBER,				// �i���o�[
		TEXTURE_BULLET,				// �e
		TEXTURE_FLOOR,				// �n��
		TEXTURE_CIRCLE,				// ��

		/* �G�t�F�N�g�Q */
		TEXTURE_EFFECT_SMOKE,
		TEXTURE_EFFECT_FLARE,
		TEXTURE_EFFECT_STAR,
		TEXTURE_EFFECT_BRIGHTA,
		TEXTURE_EFFECT_BRIGHTB,
		TEXTURE_EFFECT_RAY,
		TEXTURE_EFFECT_COIN,
		TEXTURE_EFFECT_JEWEL,
		TEXTURE_EFFECT_SOUL,
		TEXTURE_EFFECT_UP,
		TEXTURE_EFFECT_RETICLE,

		TEXTURE_MAX,
		TEXTURE_NONE
	};

	static const char* s_FileName[];	// �t�@�C���p�X

public:
	CTexture();		// �f�t�H���g�R���X�g���N�^
	~CTexture();	// �f�X�g���N�^

public: /* �����o�֐� */
	void LoadAll();										// �S�Ă̓ǂݍ���
	void ReleaseAll();									// �S�Ă̔j��
	void Release(TEXTURE inTexture);					// �w��̔j��
	LPDIRECT3DTEXTURE9 GetTexture(TEXTURE inTexture);	// ���̎擾

private: /* �����o�ϐ� */
	LPDIRECT3DTEXTURE9 s_pTexture[TEXTURE_MAX];			// �e�N�X�`���̏��
};

#endif // !_TEXTURE_H_
