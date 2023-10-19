//����������������������������������������
//Pointer.h
//����������������������������������������
#ifndef _POINTER_H_
#define _POINTER_H_

#include "object.h"

class CParticleEmitter;
class CModel;

class CPointer : public CObject
{
public:
	//--------------------------------------
	// ���f���f�[�^�̍\����
	//--------------------------------------
	struct SModelData
	{
		LPD3DXMESH mesh;						// ���b�V�����
		LPD3DXBUFFER buffMat;					// �}�e���A�����
		DWORD dwNum;							// �}�e���A���̌�
		D3DXVECTOR3 maxModel;					// ���f���̍ő�l
		D3DXVECTOR3 minModel;					// ���f���̍ŏ��l
	};

	CPointer();
	~CPointer() override;

	static CPointer *Create(D3DXVECTOR3 pos);
	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;
	void Movement();
	void LoadModel(std::string path);
	void BindTexture(std::string inPath);
	void Destroy() override { m_isRelease = true; }
	void Invisible() { m_bVisible = false; }
	void Visible() { m_bVisible = true; }

	void SetPos(D3DXVECTOR3 pos) override { m_objpos = pos; }
	void SetRotDest(D3DXVECTOR3 rot) { m_rotDest = rot; }
	void SetMove(D3DXVECTOR3 move) { m_move = move; }

	D3DXVECTOR3 GetPos() override { return m_objpos; }
	D3DXVECTOR3 GetPosOld() { return m_posOld; }
	D3DXVECTOR3 GetMove() { return m_move; }
	D3DXVECTOR3 GetRot() { return m_rot; }
	D3DXVECTOR3 GetRotDest() { return m_rotDest; }
	D3DXVECTOR3 GetVec() { return m_vec; }
	D3DXMATRIX GetMatrix() { return m_mtxWorld; }
	bool GetVisible() { return m_bVisible; }
	bool GetDestroy() override { return m_isRelease; }

	CParticleEmitter *GetEmitter() { return m_pParticleEmitter; }

private:
	LPDIRECT3DTEXTURE9 m_pTexture;			// �e�N�X�`��

	D3DXVECTOR3 m_objpos;					// �ʒu
	D3DXVECTOR3 m_posOld;					// �O��̈ʒu
	D3DXVECTOR3 m_move;						// �v���C���[�̈ړ���
	D3DXVECTOR3 m_rot;						// ����
	D3DXVECTOR3 m_rotDest;					// �ړI�̌���
	D3DXVECTOR3 m_scale;
	D3DXVECTOR3 m_vec;						// �v���C���[�̌����̃x�N�g��
	D3DXMATRIX m_mtxWorld;					// ���[���h�}�g���b�N�X
	std::vector<SModelData> m_modelData;
	CParticleEmitter *m_pParticleEmitter;
	float m_fSpeed;

	bool m_bVisible;
	bool m_isRelease;						// �I�u�W�F�N�g�̎��S�t���O
};

#endif