#pragma once
#include "Vec2.h"

class Player;

/// <summary>
/// 背景管理クラス
/// </summary>
class Bg
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bg(Player* pPlayer);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bg();

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
	/// 横のスクロール量を決定する
	/// </summary>
	/// <returns>横スクロール量</returns>
	int GetScrollX();

	/// <summary>
	/// 縦のスクロール量を決定する
	/// </summary>
	/// <returns>縦スクロール量</returns>
	int GetScrollY();

private:
	/// <summary>
	/// 背景描画
	/// </summary>
	void DrawBg();

private:
	int m_bgHandle; // 背景画像ハンドル
	Vec2 m_pos;     // 位置
	Player* m_pPlayer; // プレイヤーのポインタ
};