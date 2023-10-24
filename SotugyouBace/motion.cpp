//============================================================================
//
// ���[�V����	motion.cpp
// Author : Tanimoto Kosuke
//
//============================================================================
#include "motion.h"

//=====================================
// �f�t�H���g�R���X�g���N�^
//=====================================
CMotion::CMotion()
{

}

//=====================================
// �f�X�g���N�^
//=====================================
CMotion::~CMotion()
{

}

//=====================================
// �S�Ẵ��[�V�����̔j������
//=====================================
void CMotion::ReleaseAll()
{
	// ���[�V������S�ďI��������
	m_MotionPatternData.clear();
	m_UseFileName.clear();
}

//==============================================================================================
// ���[�V�����l�̓ǂݍ���
//==============================================================================================
void CMotion::SetMotionData(MotionPattern motion, std::string name)
{
	// ���O���g�p����Ă��Ȃ��ꍇ
	if (std::count(m_UseFileName.begin(), m_UseFileName.end(), name) == false)
	{
		// ���[�V��������ݒ�
		m_MotionPatternData[name].push_back(motion);
	}
}