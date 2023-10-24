//**************************************************
// 
// texture.h
// Author  : katsuki mizuki
// Author  : Yuda Kaito
// 
//**************************************************
#ifndef _TEXTURE_H_	//���̃}�N����`������ĂȂ�������
#define _TEXTURE_H_	//�Q�d�C���N���[�h�h�~�̃}�N����`

//==================================================
// �C���N���[�h
//==================================================
#include <d3dx9.h>
#include <vector>
#include <map>
#include <string>

//==================================================
// ��`
//==================================================
class CTexture
{
public:
	CTexture();		// �f�t�H���g�R���X�g���N�^
	~CTexture();	// �f�X�g���N�^

public:
	void LoadAll();											// �S�Ă̓ǂݍ���
	void UnloadAll();										// �S�Ă̔j��
	void Load(std::string inKey, std::string inFileName, int index = 0);	// �w��̓ǂݍ���
	void Load(std::vector<std::string> inTexture, int index = 0);			// �w��̓ǂݍ���
	void Unload(std::string inKey);	// �w��̔j��

	void GetFilePath(std::string& folder, std::vector<std::string>& file);
	std::map<std::string, std::string, std::less<>> GetTexturePath() { return m_texturePath; }

	LPDIRECT3DTEXTURE9 GetTexture(std::string inKey, int index = 0);		// ���̎擾
	LPDIRECT3DTEXTURE9 ConfirmLoadedPath(std::string path);	// �ǂݍ��񂾃p�X�̊m�F

private: /* �v���C�x�[�g�֐� */
	bool ExistsPath(std::string inKey) { return m_texturePath.count(inKey) != 0; }	// Map���Ɏw�肳�ꂽKey�����݂��邩�ۂ�
	bool ExistsKey(std::string inKey) { return m_texture.count(inKey) != 0; }	// Map���Ɏw�肳�ꂽKey�����݂��邩�ۂ�

private: /* �����o�ϐ� */
	std::vector<std::string> m_texPath;

	std::map<std::string, std::string, std::less<>> m_texturePath;		// �e�N�X�`���̃p�X
	std::map<std::string, LPDIRECT3DTEXTURE9, std::less<>> m_texture;	// �e�N�X�`���̏��
};

#endif // !_TEXTURE_H_