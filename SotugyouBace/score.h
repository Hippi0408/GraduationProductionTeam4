//==============================================
//
// score.h (スコア.h)
// Author : Saito Shian
//
//==============================================

//==============================================
// インクルード
//==============================================
#include "main.h"
#include "object.h"

//==============================================
// 前方宣言
//==============================================
class CNumber;

//==============================================
// スコアクラス
//==============================================
class CScore : public CObject
{
public:
	static const int MAX_DIGIT = 10;		// 最大桁数

	//****************
	// publicな関数
	//****************
	CScore();								// スコアのコンストラクタ
	~CScore() override;						// スコアのデストラクタ

	HRESULT Init() override;				// 初期化処理
	void Uninit() override;					// 終了処理
	void Update() override;					// 更新処理
	void Draw() override;					// 描画処理

	void SetScore(int nScore);				//スコアの設定処理
	void AddScore(int nValue);				//スコアの加算処理

	//void SetPosition(D3DXVECTOR3 pos) { pos; }					// 位置の設定

	static CScore *Create();				// 生成

private:
	//****************
	// privateな変数
	//****************
	CNumber *m_apNumber[MAX_DIGIT];			//スコアの数字(桁数)
	int m_aPosTexU[MAX_DIGIT];				//各桁のスコアを格納
	int m_nScore;							//スコア
	
};
