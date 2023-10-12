//==============================================
//
// 弾.h (Bullet.h)
// Author : Saito Shian
//
//==============================================
#ifndef  _BULLET_H_				//このマクロ定義がされてなかったら
#define  _BULLET_H_				//二重インクルード防止のマクロ定義

//==============================================
// インクルード
//==============================================
#include "main.h"
#include "object3D.h"

//==============================================
// 弾クラス
//==============================================
class CBullet : public CObject3D
{
	static const int BULLET_LIFE = 50;			// 弾の寿命
	static const float BULLET_SPEED;			// 弾の速度
	static const float BULLET_COLLISION_RADIUS;	// 弾の当たり判定の大きさ
public:

	//****************
	// publicな関数
	//****************
	CBullet(const PRIORITY priority);		// ナンバーのコンストラクタ
	~CBullet() override;					// ナンバーのデストラクタ

	HRESULT Init() override;				// 初期化処理
	void Uninit() override;					// 終了処理
	void Update() override;					// 更新処理
	void Draw() override;					// 描画処理

	void FieldCollision();				//床の当たり判定
	void Hit() override;

	void SetLife(const int life) { m_nLife = life; }		// 弾の寿命の設定
	void SetSpeed(const float speed) { m_fSpeed = speed; }	// 弾の速度の設定

	const int GetLife() { return m_nLife; }			// 弾の寿命の取得
	const float GetSpeed() { return m_fSpeed; }		// 弾の速度の取得

	static CBullet* Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, const D3DXVECTOR3 move, const PRIORITY priority = PRIORITY_BACK);	// 生成

private:
	//****************
	// privateな変数
	//****************
	D3DXVECTOR3 m_nPosOld;					// 前回の位置
	int m_nLife;							// 弾の寿命
	float m_fSpeed;							// 弾のスピード
};
#endif
