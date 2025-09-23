#pragma once

/// <summary>
/// ゲームパッドの入力を管理するクラス
/// </summary>
namespace Pad
{
	/// <summary>
	/// パッドの更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 押されているかどうか
	/// </summary>
	/// <param name="key">入力キー</param>
	/// <returns>押されているかどうか</returns>
	bool IsPress(int key);

	/// <summary>
	/// 押された瞬間を取得
	/// </summary>
	/// <param name="key">入力キー</param>
	/// <returns>押されたかどうか</returns>
	bool IsTrigger(int key);

	/// <summary>
	/// 離された瞬間を取得
	/// </summary>
	/// <param name="key">入力キー</param>
	/// <returns>離されたかどうか</returns>
	bool IsRelease(int key);
}