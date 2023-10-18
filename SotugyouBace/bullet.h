//==============================================
//
// 弾.h (Bullet.h)
// Author : Saito Shian
// Author : Tanimoto Kosuke
//
//==============================================
#ifndef  _BULLET_H_				//このマクロ定義がされてなかったら
#define  _BULLET_H_				//二重インクルード防止のマクロ定義

//==============================================
// インクルード
//==============================================
#include "main.h"
#include "move_object.h"

//==============================================
// 前方宣言
//==============================================
class CObject3D;

//==============================================
// 弾クラス
//==============================================
class CBullet : public CMove_Object
{
	static const int BULLET_LIFE = 50;			// 弾の寿命
	static const int BULLET_POWER = 30;			// 弾の威力
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

	void FieldCollision();					//床の当たり判定
	void Hit(CMove_Object* pHit) override;	// 被弾処理
	void Destroy();							// 破壊処理

	void SetLife(const int life) { m_nLife = life; }		// 弾の寿命の設定
	void SetSpeed(const float speed) { m_fSpeed = speed; }	// 弾の速度の設定
	void SetPower(const int power) { m_nPower = power; }
	void SetMove(const D3DXVECTOR3 move) { m_move = move; }	// 移動量の設定
	void AddMove(const D3DXVECTOR3 move) { m_move += move; }// 移動量の加算
	void SetSize(const D3DXVECTOR2 size) { m_size = size; }	// サイズの設定

	const int GetLife() { return m_nLife; }					// 弾の寿命の取得
	const float GetSpeed() { return m_fSpeed; }				// 弾の速度の取得
	const int GetPower() override { return m_nPower; }		// 威力の取得
	const D3DXVECTOR3 GetMove() { return m_move; }			// 移動量の取得
	const D3DXVECTOR2 GetSize() { return m_size; }			// サイズの取得

	static CBullet* Create(const D3DXVECTOR3 pos, const D3DXVECTOR2 size, const D3DXVECTOR3 move,  const PRIORITY priority = PRIORITY_BACK);	// 生成

private:
	//****************
	// privateな変数
	//****************
	D3DXVECTOR3 m_move;						// 弾の移動量
	D3DXVECTOR3 m_nPosOld;					// 前回の位置
	D3DXVECTOR2 m_size;						// 弾のサイズ
	int m_nLife;							// 弾の寿命
	int m_nPower;							// 弾の威力
	float m_fSpeed;							// 弾のスピード

	CObject3D* m_pObj3D;					// オブジェクト3Dのポインタ
};
#endif
