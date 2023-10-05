//==============================================
//
// score.h (�X�R�A.h)
// Author : Saito Shian
//
//==============================================

//==============================================
// �C���N���[�h
//==============================================
#include "main.h"
#include "object.h"

//==============================================
// �O���錾
//==============================================
class CNumber;

//==============================================
// �X�R�A�N���X
//==============================================
class CScore : public CObject
{
public:
	static const int MAX_DIGIT = 10;		// �ő包��

	//****************
	// public�Ȋ֐�
	//****************
	CScore();								// �X�R�A�̃R���X�g���N�^
	~CScore() override;						// �X�R�A�̃f�X�g���N�^

	HRESULT Init() override;				// ����������
	void Uninit() override;					// �I������
	void Update() override;					// �X�V����
	void Draw() override;					// �`�揈��

	void SetScore(int nScore);				//�X�R�A�̐ݒ菈��
	void AddScore(int nValue);				//�X�R�A�̉��Z����

	//void SetPosition(D3DXVECTOR3 pos) { pos; }					// �ʒu�̐ݒ�

	static CScore *Create();				// ����

private:
	//****************
	// private�ȕϐ�
	//****************
	CNumber *m_apNumber[MAX_DIGIT];			//�X�R�A�̐���(����)
	int m_aPosTexU[MAX_DIGIT];				//�e���̃X�R�A���i�[
	int m_nScore;							//�X�R�A
	
};
