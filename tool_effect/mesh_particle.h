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
	// メッシュパーティクル情報の構造体
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
		D3DXCOLOR col;							// 色
		D3DXCOLOR destCol;						// 目的の色
		float randomMin;						// ランダム色の最低値
		float randomMax;						// ランダム色の最大値
		float colAttenuation;					// 色の減衰量
		float emissive;							// 発光量
		bool randomColor;						// 色にランダムを適用
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
		D3DXVECTOR3 pos;						// 位置
		D3DXVECTOR3 posOffset;					// 位置のオフセット
		D3DXVECTOR3 move;						// 移動量
		D3DXVECTOR3 scale;						// 大きさ
		D3DXVECTOR3 scalingValue;				// 拡縮量
		D3DXVECTOR3 rot;						// 向き
		D3DXVECTOR2 moveUV;						// UV座標の移動
		SColor color;							// 色の構造体
		SRotate rotate;							// 螺旋状移動の構造体
		std::string modelTag;					// モデルのタグ
		std::string texTag;						// テクスチャのタグ
		std::string maskTexTag;					// マスク用テクスチャのタグ
		int beginDelay;							// 開始の遅延
		int fallDelayTime;						// 落ちるまでの遅延
		int popTime;							// 生存時間
		float moveAttenuation;					// 移動の減衰量
		float rotationVolume;					// 回転量
		float weight;							// 重さ
		float circleDistance;					// 円の範囲
		float randomWeightMin;					// 重さのランダムの最低値
		float randomWeightMax;					// 重さのランダムの最大値
		bool randomPos;							// 位置にランダムを適用
		bool randomWeight;						// 重さにランダムを適用するかどうか
		bool useTexture;						// テクスチャを使用するかどうか
		bool useMaskTexture;					// マスクテクスチャを使用するかどうか
		bool useTrail;							// トレイルを使用するかどうか
		bool useShader;							// シェーダーを使用するかどうか
	};

	explicit CMeshParticle(int nPriority = CObject::PRIORITY_THIRD);
	~CMeshParticle() override;

	static CMeshParticle *Create(SInfo& info, int nPriority = CObject::PRIORITY_THIRD);	// 生成処理

	HRESULT Init() override;												// 初期化処理
	void Uninit() override;													// 終了処理
	void Update() override;													// 更新処理
	void Draw() override;													// 描画処理
	void AnimationDraw();
	void LoadModel(const std::string& path);
	void BindTexture(const std::string& inPath);
	void BindMaskTexture(const std::string& inPath);
	bool isExpired() { return m_DestroyTime <= 0; }							// 期限切れかどうか
	void Destroy() { m_isRelease = true; }

	//セッター
	void SetInfo(SInfo& info) { m_info = info; }
	void SetPos(D3DXVECTOR3 pos) override { m_info.pos = pos; }

	SInfo GetInfo() { return m_info; }
	D3DXVECTOR3 GetPos() override { return  m_info.pos; }
	bool GetDestroy() { return m_isRelease; }

private:
	LPDIRECT3DTEXTURE9 m_pTexture;			// テクスチャ
	LPDIRECT3DTEXTURE9 m_pMaskTexture;
	D3DXVECTOR2 m_uv;
	D3DXMATRIX m_mtxWorld;
	std::vector<CModel::SModelData> m_modelData;
	std::string m_shaderLabel;
	SInfo m_info;						// パーティクルの情報
	SHandlers m_handler;
	CTrail *m_pTrail;

	int m_delayStartTime;
	int m_nTime;						// 時間
	int m_DestroyTime;
	bool m_isRelease;
};
#endif