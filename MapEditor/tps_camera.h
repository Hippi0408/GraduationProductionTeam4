//=============================================================================
//
// tps_camera.h
// Author : koduna hirohito
//
//=============================================================================
#ifndef _TPS_CAMERA_H_			//���̃}�N����`������Ȃ�������
#define _TPS_CAMERA_H_			//2�d�C���N���[�h�h�~�̃}�N����`

//*****************************************************************************
// �C���N���[�h
//*****************************************************************************
#include "camera.h"

//*****************************************************************************
// �O���錾
//*****************************************************************************

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CTpsCamera : public CCamera
{
private:
	static const D3DXVECTOR3 RANGE_WITH_PLAYER_V;
	static const D3DXVECTOR3 RANGE_WITH_PLAYER_R;
	static const float DISTANCE;
public:
	CTpsCamera();
	~CTpsCamera() override;

	HRESULT Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	D3DXVECTOR3 GetCameraVec();
	
private:
	D3DXVECTOR3 m_VPos;
	D3DXVECTOR3 m_Rot;
	D3DXVECTOR3 m_CameraVec;
	D3DXVECTOR3 m_CameraVectorConversion;
	float m_fPlayerDistance;
	D3DXVECTOR3 m_DestPos;
};

#endif