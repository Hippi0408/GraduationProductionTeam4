#ifndef _MESH_PARTICLE_H_
#define _MESH_PARTICLE_H_

#include "object.h"
#include "model.h"

class CTrail;
class CModel;

class CMeshParticle : public CObject
{
public:
	//--------------------------------------
	// ���b�V���p�[�e�B�N�����̍\����
	//--------------------------------------
	struct SRotate
	{
		float angle;
		float radius;
		float randomMin;
		float randomMax;
		bool useRotate;
	};

	struct SColor
	{
		D3DXCOLOR col;							// �F
		D3DXCOLOR destCol;						// �ړI�̐F
		float randomMin;						// �����_���F�̍Œ�l
		float randomMax;						// �����_���F�̍ő�l
		float colAttenuation;					// �F�̌�����
		float emissive;							// ������
		bool randomColor;						// �F�Ƀ����_����K�p
	};

	struct SHandlers
	{
		D3DXHANDLE technique;
		D3DXHANDLE wvp;
		D3DXHANDLE animationUV;
		D3DXHANDLE maskTexture;
		D3DXHANDLE haveMainTexture;
		D3DXHANDLE haveMaskTexture;
		D3DXHANDLE diffuse;
	};

	struct SInfo
	{
		D3DXVECTOR3 pos;						// �ʒu
		D3DXVECTOR3 posOffset;					// �ʒu�̃I�t�Z�b�g
		D3DXVECTOR3 move;						// �ړ���
		D3DXVECTOR3 scale;						// �傫��
		D3DXVECTOR3 scalingValue;				// �g�k��
		D3DXVECTOR3 rot;						// ����
		D3DXVECTOR2 moveUV;						// UV���W�̈ړ�
		SColor color;							// �F�̍\����
		SRotate rotate;							// ������ړ��̍\����
		std::string modelTag;					// ���f���̃^�O
		std::string texTag;						// �e�N�X�`���̃^�O
		std::string maskTexTag;					// �}�X�N�p�e�N�X�`���̃^�O
		int beginDelay;							// �J�n�̒x��
		int fallDelayTime;						// ������܂ł̒x��
		int popTime;							// ��������
		float moveAttenuation;					// �ړ��̌�����
		float rotationVolume;					// ��]��
		float weight;							// �d��
		float circleDistance;					// �~�͈̔�
		float randomWeightMin;					// �d���̃����_���̍Œ�l
		float randomWeightMax;					// �d���̃����_���̍ő�l
		bool randomPos;							// �ʒu�Ƀ����_����K�p
		bool randomWeight;						// �d���Ƀ����_����K�p���邩�ǂ���
		bool useTexture;						// �e�N�X�`�����g�p���邩�ǂ���
		bool useMaskTexture;					// �}�X�N�e�N�X�`�����g�p���邩�ǂ���
		bool useTrail;							// �g���C�����g�p���邩�ǂ���
		bool useShader;							// �V�F�[�_�[���g�p���邩�ǂ���
	};

	explicit CMeshParticle(int nPriority = CObject::PRIORITY_THIRD);
	~CMeshParticle() override;

	static CMeshParticle *Create(SInfo& info, int nPriority = CObject::PRIORITY_THIRD);	// ��������

	HRESULT Init() override;												// ����������
	void Uninit() override;													// �I������
	void Update() override;													// �X�V����
	void Draw() override;													// �`�揈��
	void AnimationDraw();
	void LoadModel(const std::string& path);
	void BindTexture(const std::string& inPath);
	void BindMaskTexture(const std::string& inPath);
	bool isExpired() { return m_DestroyTime <= 0; }							// �����؂ꂩ�ǂ���
	void Destroy() { m_isRelease = true; }

	//�Z�b�^�[
	void SetInfo(SInfo& info) { m_info = info; }
	void SetPos(D3DXVECTOR3 pos) override { m_info.pos = pos; }

	SInfo GetInfo() { return m_info; }
	D3DXVECTOR3 GetPos() override { return  m_info.pos; }
	bool GetDestroy() { return m_isRelease; }

private:
	LPDIRECT3DTEXTURE9 m_pTexture;			// �e�N�X�`��
	LPDIRECT3DTEXTURE9 m_pMaskTexture;
	D3DXVECTOR2 m_uv;
	D3DXMATRIX m_mtxWorld;
	std::vector<CModel::SModelData> m_modelData;
	std::string m_shaderLabel;
	SInfo m_info;						// �p�[�e�B�N���̏��
	SHandlers m_handler;
	CTrail *m_pTrail;

	int m_delayStartTime;
	int m_nTime;						// ����
	int m_DestroyTime;
	bool m_isRelease;
};
#endif