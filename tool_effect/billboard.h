//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
//Billboard.h
//＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_

#include "object.h"
#include "texture.h"

class CBillboard : public CObject
{
public:
	//--------------------------------------
	// ブレンドタイプの列挙
	//--------------------------------------
	enum EBlend
	{
		Blend_Additive,
		Blend_Subtractive,
		Blend_Normal,
		Blend_MAX
	};

	struct SAnimation
	{
		int u;
		int v;
		int speed;
		bool loop;
	};

	explicit CBillboard(int nPriority = CObject::PRIORITY_THIRD);
	~CBillboard() override;

	static CBillboard* Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, int priority);							// 生成処理

	HRESULT Init() override;																				// 初期化処理
	void Uninit() override;																					// 終了処理
	void Update() override;																					// 更新処理
	void Draw() override;																					// 描画処理
	void Draw(std::string label);
	void BindTexture(std::string inPath);																	// テクスチャをバインド
	void Blending(EBlend state);
	void SetUV(float Xtop, float Xbottom, float Ytop, float Ybottom);										// UV座標の設定
	void SetAnimation(const int U, const int V, const int Speed, const int Drawtimer, const bool loop);		// アニメーションの設定
	void Destroy() override { m_isRelease = true; }															// 死亡フラグの設定
	void AlphaTest() { m_bIsAlphaTest = true; }																// テクスチャのアルファ値のテストを開始
	void Rotate(float rot) { m_bIsRotate = true, m_destRotate = rot; }										// 回転の設定

	//セッター
	void SetPos(D3DXVECTOR3 pos) override { m_objpos = pos; }												// 位置の設定
	void SetMove(D3DXVECTOR3 move) { m_move = move; }														// 移動量の設定
	void SetRot(D3DXVECTOR3 rot) { m_rot = rot; }															// 向きの設定
	void SetScale(D3DXVECTOR3 scale) { m_scale = scale; }													// 大きさの設定
	void SetCol(D3DXCOLOR col) { m_col = col; }																// 色の設定
	void SetBlendState(EBlend blend) { m_blendState = blend; }														// ブレンドタイプの設定
	void SetZBuff(_D3DCMPFUNC func) { m_Zfunc = func; }														// Zバッファテストの設定
	void SetMtxWorld(D3DXMATRIX mtx) { m_mtxWorld = mtx; }
	void SetShaderLabel(const std::string& label) { m_shaderLabel = label; }

	//ゲッター
	D3DXVECTOR3 GetPos() override { return m_objpos; }														// 位置の取得
	D3DXVECTOR3 GetMove() { return m_move; }																// 移動量の取得
	D3DXVECTOR3 GetRot() { return m_rot; }																	// 向きの取得
	D3DXVECTOR3 GetScale() { return m_scale; }																// 大きさの取得
	D3DXCOLOR GetCol() { return m_col; }																	// 色の取得
	EBlend GetBlendState() { return m_blendState; }																	// ブレンドタイプの取得
	D3DXMATRIX GetMtxWorld() { return m_mtxWorld; }
	LPDIRECT3DTEXTURE9 GetMyTexture() { return m_pTexture; }
	std::string GetShaderLabel() { return m_shaderLabel; }
	float GetWidth() { return m_Width; }																	// 幅の取得
	float GetHeight() { return m_Height; }																	// 高さの取得
	bool GetDestroy() override { return m_isRelease; }														// 死亡しているかどうか

private:
	void DefaultBlending();
	void Additive();
	void Subtractive();

	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// 頂点バッファ
	LPDIRECT3DTEXTURE9 m_pTexture;			// テクスチャ
	D3DXVECTOR3 m_objpos;					// 位置
	D3DXVECTOR3 m_move;						// 移動量
	D3DXVECTOR3 m_rot;						// 向き
	D3DXVECTOR3 m_scale;					// 大きさ
	D3DXCOLOR m_col;						// 色
	D3DXMATRIX m_mtxWorld;					// ワールドマトリックス
	D3DXHANDLE m_hTechnique;
	D3DXHANDLE m_wvp;
	D3DXHANDLE m_tex;
	EBlend m_blendState;							// ブレンドタイプ
	_D3DCMPFUNC m_Zfunc;					// Zバッファのタイプ
	std::string m_shaderLabel;
	int m_CounterAnim;						// アニメーションカウンター
	int m_PatternAnimX;						// Xのパターン
	int m_PatternAnimY;						// Yのパターン
	int m_DivisionX;						// X分割数
	int m_DivisionY;						// Y分割数
	int m_DivisionMAX;						// 最大分割数
	int m_AnimationSpeed;					// アニメーションする速度
	int m_AnimationSpdCnt;					// アニメーションのスピードカウンター
	int m_Timer;							// タイマー
	int m_CntTime;							// テクスチャアニメーションのタイマー
	float m_Width;							// 幅
	float m_Height;							// 高さ
	float m_destRotate;						// 回転の速さ
	bool m_bAnimation;						// アニメーションをするかどうか
	bool m_bLoop;							// アニメーションをループするかどうか
	bool m_bIsRotate;						// 回転させるかどうか
	bool m_bIsAlphaTest;					// アルファテストをするかどうか
	bool m_isRelease;						// 死亡フラグ
};

#endif