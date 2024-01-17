//=============================================================================
//
// 3dobject.h
// Author : koduna hirohito
//
//=============================================================================
#ifndef _3DOBJECT_H_			//���̃}�N����`������Ȃ�������
#define _3DOBJECT_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "object.h"

//*****************************************************************************
// �\���̐錾
//*****************************************************************************
//���f���̏��̍\����
typedef struct
{
	int nPattn;							//���f���ԍ�
	D3DXVECTOR3 pos;					//�ʒu
	D3DXVECTOR3 rot;					//����
}Object_Data;

//*****************************************************************************
// �O���錾
//*****************************************************************************
enum Object_Type_List;

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class C3DObject : public CObject
{
public:
	static const int MODEL_MAX_TEXTURE = 30;
	static const int MODEL_PATTERN_MAX = 120;

	//���f���p�^�[���\����
	typedef struct
	{
		LPD3DXMESH pMeshModel;		//���b�V�����ւ̃|�C���^
		LPD3DXBUFFER pBuffMatModel;	//�}�e���A�����ւ̃|�C���^
		DWORD nNumMatModel;				//�}�e���A�����̐�
		LPDIRECT3DTEXTURE9 pTexture[MODEL_MAX_TEXTURE];		// �e�N�X�`���ւ̃|�C���^
		bool bUse;
	}ModelPattern;

	//���f���\����
	typedef struct
	{
		D3DXVECTOR3* pNormalPolygon;						//�ʖ@��
		D3DXVECTOR3* pTopPos;								//���_�̈ʒu
		D3DXMATRIX mtxWorld;								//���[���h�}�g���b�N�X
		D3DXMATRIX mtxWorldRot;								//���[���h�}�g���b�N�X(��������)
		D3DXVECTOR3 posParent;								//�ʒu�e
		D3DXVECTOR3 rotParent;								//�����e
		D3DXVECTOR3 rot;									//����
		D3DXVECTOR3 pos;									//�ʒu
		D3DXVECTOR3 move;									//�ړ�
		D3DXVECTOR3 vtxMin, vtxMax;							//���f���̃T�C�Y(��)
		D3DXVECTOR3 vtxMin2, vtxMax2;						//���f���̃T�C�Y(���[���h�}�g���b�N�X�ŕϊ���������)
		D3DXVECTOR3 posMove = D3DXVECTOR3(0.0f,0.0f,0.0f);	//�ʒu�������p
		int nPattn;											//���f���̃p�^�[��
		bool bCollision;									//�����蔻��̗L��
		bool bOpeningLost;									//�I�[�v�j���O��ɔj�����郂�f��
		bool bSwitch;										//�C��̐؂�ւ�
	}Model;

public:
	C3DObject();
	virtual ~C3DObject() override;

	virtual HRESULT Init() override;
	virtual void Uninit() override;
	virtual void Update() override;
	virtual void Draw() override;
	void Set3DObject(int nPattn, D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	D3DXVECTOR3 GetPos() { return m_Model.pos; }
	D3DXVECTOR3 GetRot() { return m_Model.rot; }
	void SetPos(D3DXVECTOR3 pos) { m_Model.pos = pos; }
	void SetRot(D3DXVECTOR3 rot) { m_Model.rot = rot; }
	D3DXVECTOR3 GetParentPos() { return m_Model.posParent; }
	D3DXVECTOR3 GetParentRot() { return m_Model.rotParent; }
	void SetParentPos(D3DXVECTOR3 pos) { m_Model.posParent = pos; }
	void SetParentRot(D3DXVECTOR3 rot) { m_Model.rotParent = rot; }
	void AddParentPos(D3DXVECTOR3 add) { m_Model.posParent += add; }
	void SetPosMove(D3DXVECTOR3 pos) { m_Model.posMove = pos; }
	D3DXVECTOR3 GetPosMove() { return m_Model.posMove; }
	void AddPosMove(D3DXVECTOR3 add) { m_Model.posMove += add; }
	void AddPos(D3DXVECTOR3 add) { m_Model.pos += add; }
	void AddRot(D3DXVECTOR3 add) { m_Model.rot += add; }
	void SetSize(float fSize) { m_fSize = fSize; }
	void SetLightVec(D3DXVECTOR3 LightVec) { m_LightVec = LightVec; }
	void SetShadowPos(D3DXVECTOR3 shadowpos) { m_ShadowPos = shadowpos; }
	D3DXVECTOR3 GetWorldPos();
	D3DXVECTOR3 GetWorlMatrixRot();
	D3DXVECTOR3 GetWorldRot();
	D3DXMATRIX GetMatrix() { return m_Model.mtxWorld; }
	void SetMatrix(D3DXMATRIX mtx) { m_Model.mtxWorld = mtx; }
	D3DXVECTOR3 GetSize();
	void SetModelPattnNum(int nPattnNum) { m_Model.nPattn = nPattnNum; }
	void CalculationMatrix();
	void SetNormal();			//�@���ݒ�
	void UpdateNormal();		//�@���̌����̍X�V
	virtual D3DXVECTOR3 Collision(D3DXVECTOR3 pos, D3DXVECTOR3 oldpos);//�����蔻��
	virtual bool NormalCollision(D3DXVECTOR3 pos);//�����蔻��
	bool TriangleInOut(D3DXVECTOR3 pos, D3DXVECTOR3 vtx0, D3DXVECTOR3 vtx1, D3DXVECTOR3 vtx2);//�O�p�`�̓��ɂ��邩�ǂ���
	bool SquareInOut(D3DXVECTOR3 pos , D3DXVECTOR3 vtx0, D3DXVECTOR3 vtx1, D3DXVECTOR3 vtx2, D3DXVECTOR3 vtx3);//�l�p�`�̓��ɂ��邩�ǂ���
	D3DXVECTOR3 GetVtxMin() { return m_Model.vtxMin; }
	D3DXVECTOR3 GetVtxMax() { return m_Model.vtxMax; }
	void SetModelNumIndex(int nModelNumIndex) { m_nModelNumIndex = nModelNumIndex; }
	int GetModelNumIndex() { return m_nModelNumIndex; }

	void SetCollision(bool bCollision) { m_Model.bCollision = bCollision; }
	void SetOpeningLost(bool bOpeningLost) { m_Model.bOpeningLost = bOpeningLost; }
	void SetSwitch(bool bSwitch) { m_Model.bSwitch = bSwitch; }

	bool GetCollision() { return m_Model.bCollision; }
	bool GetOpeningLost() { return m_Model.bOpeningLost; }
	bool GetSwitch() { return m_Model.bSwitch; }

	void SetObject_Type_List(Object_Type_List object_type_list) { m_Object_Type_List = object_type_list; }
	Object_Type_List GetObject_Type_List() { return m_Object_Type_List; }

	static int SetModel(ModelPattern *pModel);
	static void UninitAllModel();

private:
	static ModelPattern m_ModelPattern[MODEL_PATTERN_MAX];
	Model m_Model;
	float m_fSize;//�T�C�Y
	D3DXVECTOR3 m_LightVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f); 
	D3DXVECTOR3 m_ShadowPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	Object_Type_List m_Object_Type_List;

	int m_nModelNumIndex;
};

#endif