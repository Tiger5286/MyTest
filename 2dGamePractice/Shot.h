#pragma once
#include "Vec2.h"
#include "Rect.h"

/// <summary>
/// 弾管理クラス
/// </summary>
class Shot
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary> 
	Shot();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Shot();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 当たり判定を取得
	/// </summary>
	/// <returns>当たり判定情報</returns>
	Rect GetColRect() const { return m_colRect; }

	/// <summary>
	/// 弾の情報を設定
	/// </summary>
	/// <param name="pos">座標</param>
	/// <param name="isLeft">左方向に移動するか</param>
	void SetInfo(const Vec2& pos, bool isLeft);

	Vec2 GetPos() const { return m_pos; } // 位置取得
private:
	// 画像ハンドル
	int m_handle;
	
	Vec2 m_pos;		// 位置
	Vec2 m_move;	// 移動量

	// 当たり判定用の矩形
	Rect m_colRect;
};

