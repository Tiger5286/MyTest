#pragma once
#include <cmath>

class Vec2
{
public:
	float x;
	float y;

	// コンストラクタ
	Vec2() :
		x(0.0f),
		y(0.0f)
	{
	}

	// 引数付きコンストラクタ
	Vec2(float posX, float posY) :
		x(posX),
		y(posY)
	{
	}

	// 単項演算子+
	Vec2 operator+() const
	{
		return *this;
	}

	// 単項演算子-
	Vec2 operator-() const
	{
		return Vec2(-x, -y);
	}

	// 足し算
	Vec2 operator+(Vec2 vec) const
	{
		return Vec2(x + vec.x, y + vec.y);
	}

	Vec2 operator+=(Vec2 vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}

	// 引き算
	Vec2 operator-(Vec2 vec) const
	{
		return Vec2(x - vec.x, y - vec.y);
	}

	Vec2 operator-=(Vec2 vec)
	{
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	// スカラー倍
	Vec2 operator*(float scale) const
	{
		return Vec2(x * scale, y * scale);
	}

	Vec2 operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	// スカラー除算
	Vec2 operator/(float scale) const
	{
		return Vec2(x / scale, y / scale);
	}

	Vec2 operator/=(float scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	}

	// ベクトルの長さの二乗
	float sqLength() const
	{
		return x * x + y * y;
	}

	// ベクトルの長さ
	float length() const
	{
		return sqrtf(sqLength());
	}

	// 自身を正規化する
	void normalize()
	{
		float len = length();
		if (len != 0.0f)
		{
			x /= len;
			y /= len;
		}
		// 長さが0のときは正規化できないのでそのまま
	}

	// 自身を正規化したベクトルを返す
	Vec2 GetNormalize() const
	{
		float len = length();
		if (len != 0.0f)
		{
			return Vec2(x / len, y / len);
		}
		// 長さが0のときは正規化できないので(0,0)を返す
		return Vec2(0.0f, 0.0f);
	}
};