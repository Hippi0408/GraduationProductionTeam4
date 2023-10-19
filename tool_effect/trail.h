#ifndef _ORBIT_H_
#define _ORBIT_H_

#include "object.h"

class CTrail : public CObject
{
public:
	struct SInfo
	{
		D3DXCOLOR beginCol;
		D3DXCOLOR endCol;
		std::string texPath;
		float trailWidth;
		bool useTexture;
	};

	CTrail();	//�R���X�g���N�^
	~CTrail();	//�f�X�g���N�^

	static CTrail* Create(D3DXVECTOR3 offset, D3DXMATRIX mtx, std::string path = "");

	HRESULT Init() override { return S_OK; }
	HRESULT Init(D3DXVECTOR3 pos);
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void BindTexture(std::string inPath);
	void Destroy() { m_isRelease = true; }

	void SetTrail(D3DXMATRIX mtx, SInfo set);
	void SetMtxParent(D3DXMATRIX pMtx) { m_pMtxParent = pMtx; };	//�e�̃}�g���b�N�X�̐ݒ�
	void SetPos(D3DXVECTOR3 offset) { m_offsetPos = offset; }	//�I�t�Z�b�g���W�̐ݒ�
	void SetColor(D3DXCOLOR col, D3DXCOLOR destcol);			//�F�̐ݒ�

	D3DXVECTOR3 GetPos() override { return m_offsetPos; }	//�ʒu�̎擾
	bool GetDestroy() { return m_isRelease; }

private:
	static const int nMaxVtx = 1024;		//���_�̍ő吔

	LPDIRECT3DTEXTURE9 m_pTexture;			// �e�N�X�`��
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// ���_�o�b�t�@
	D3DXVECTOR3 m_offsetPos;				// �I�t�Z�b�g���W
	D3DXVECTOR3 m_worldPos;					// ���[���h���W
	D3DXMATRIX	m_mtxWorld;					// ���[���h�}�g���b�N�X
	D3DXMATRIX m_pMtxParent;				// �O�Ղ̐e���f���̃}�g���b�N�X
	SInfo m_info;
	std::string m_path;
	int m_nNumVtx;							// ���_��
	bool m_isRelease;
};

#endif