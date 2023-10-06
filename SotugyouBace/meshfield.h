//==============================================================================================
//
// ���b�V���t�B�[���h�̏���			meshfield.h
// tutida ryousei
//
//==============================================================================================
#ifndef _MESHFIELD_H_
#define _MESHFIELD_H_

//**********************************************************************************************
// �C���N���[�h
//**********************************************************************************************
#include"renderer.h"
#include"Object3D.h"
#include"texture.h"

class CMeshField : CObject3D
{
public:
	CMeshField();
	~CMeshField() override;

	HRESULT Init() override;		// ����������
	void Uninit(void) override;		// �I������
	void Update(void) override;		// �X�V����
	void Draw(void) override;		// �`�揈��

	void Stencil();		// �X�e���V��
	static CMeshField *Create(D3DXVECTOR3 pos, int Xblock, int Zblock, float size);	// ��������
	float MeshCollision(D3DXVECTOR3 pos);	// �����蔻��
	float Ground_Broken(D3DXVECTOR3 pos, float damage, int scope);	// �n�ʂ�����
	void Normal();			// �@���̐ݒ�
	
	void SetPos(D3DXVECTOR3 pos) { m_Pos = pos; }		// �ʒu�̐ݒ�
	void SetNumBlock(int Xblock, int Zblock) { m_nXBlock = Xblock; m_nZBlock = Zblock; }	// �u���b�N�̐��̐ݒ�
	void SetSize(float size) { m_fSize = size; }		// �T�C�Y�̐ݒ�

private:
	int m_nVertexNum;						// ���_��
	int m_nIndexNum;						// �C���f�b�N�X�o�b�t�@
	int m_nPrimitiveNum;					// �v���~�e�B�u��
	int m_nXBlock;							// X�����̃u���b�N�̐�
	int m_nZBlock;							// Z�����̃u���b�N�̐�
	int m_nHeight;							// ���_�̍���
	int m_nVecCount;						// �O�ς��}�C�i�X�ɂȂ�����
	int m_nPolyCount;						// ���_�o�b�t�@�̃J�E���g
	int m_nScope;							// �P���͈�
	int m_nCntIndex;						// �������Ă��钸�_�ԍ�
	float m_fSize;							// �T�C�Y
	bool m_bPorigon_Scope;					// �|���S���͈̔�
	D3DXVECTOR3 m_Pos;						// �ʒu
	D3DXVECTOR3 m_Rot;						// ����
	D3DXMATRIX m_MtxWorld;					// ���[���h�}�g���b�N�X
	D3DXVECTOR3 m_NorVec;					// �@���ʂ̃x�N�g��
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// ���_�o�b�t�@�ւ̃|�C���^
	LPDIRECT3DINDEXBUFFER9 m_pIdxBuff;		// �C���f�b�N�X�o�b�t�@�ւ̃|�C���^
	CTexture::TEXTURE m_Texture;			// �e�N�X�`��
};

#endif // !_MESHFIELD_H_