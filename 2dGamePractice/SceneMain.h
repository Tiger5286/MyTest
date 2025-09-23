#pragma once

namespace
{
	constexpr int kShotMax = 10; // 弾の最大数
}

class Player;
class Enemy;
class Shot;

/// <summary>
/// シーンメイン
/// </summary>
class SceneMain
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneMain();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SceneMain();

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

private:
	/// <summary>
	/// キャラクターが死んでいるかチェック
	/// </summary>
	void CheckCharacterDeath();

	/// <summary>
	/// 弾の更新処理
	/// </summary>
	void UpdateShot();

	/// <summary>
	/// 弾削除
	/// </summary>
	void DeleteShot(int index);

private:
	Player* m_pPlayer;
	Enemy* m_pEnemy;
	Shot* m_pShot[kShotMax];
};

