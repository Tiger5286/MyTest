#pragma once
#include "Vec2.h"

/// <summary>
/// 矩形を管理するクラス
/// </summary>
class Rect
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Rect();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Rect();

	/// <summary>
	/// 矩形の描画
	/// </summary>
	/// <param name="color">矩形の色</param>
	/// <param name="isFill">矩形の中を塗りつぶすかどうか</param>
	void Draw(unsigned int color, bool isFill);

	/// <summary>
	/// 左上座標と幅、高さを設定
	/// </summary>
	/// <param name="left">左x座標</param>
	/// <param name="top">上y座標</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	void SetLT(float left, float top, float width, float height);

	/// <summary>
	/// 中心座標と幅、高さを設定
	/// </summary>
	/// <param name="x">中心のx座標</param>
	/// <param name="y">中心のy座標</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	void SetCenter(float x, float y, float width, float height);

	/// <summary>
	/// 矩形の幅を取得
	/// </summary>
	/// <returns>幅</returns>
	float GetWidth() const;

	/// <summary>
	/// 矩形の高さを取得
	/// </summary>
	/// <returns>高さ</returns>
	float GetHeight() const;

	/// <summary>
	/// 矩形の中心座標を取得
	/// </summary>
	/// <returns>中心座標</returns>
	Vec2 GetCenter() const;

	/// <summary>
	/// 矩形の左上X座標を取得
	/// </summary>
	/// <returns></returns>
	float GetLeft() const { return m_left; }

	/// <summary>
	/// 矩形の左上Y座標を取得
	/// </summary>
	/// <returns></returns>
	float GetTop() const { return m_top; }

	/// <summary>
	/// 矩形の右下X座標を取得
	/// </summary>
	/// <returns></returns>
	float GetRight() const { return m_right; }

	/// <summary>
	/// 矩形の右下Y座標を取得
	/// </summary>
	/// <returns></returns>
	float GetBottom() const { return m_bottom; }

	bool IsCollision(const Rect& rect);

public:

	float m_left;	// 左上のX座標
	float m_top;	// 左上のY座標
	float m_right;	// 右下のX座標
	float m_bottom; // 右下のY座標
};

