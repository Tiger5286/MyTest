#pragma once
#include "cmath"
class Vec2
{
public:
	float x;
	float y;

	Vec2()
	{
		x = 0; y = 0;
	}
	Vec2(float _x,float _y)
	{
		x = _x;
		y = _y;
	}
	~Vec2()
	{
	}

	/// <summary>
	/// 自身の大きさを返す
	/// </summary>
	/// <returns></returns>
	float Length()
	{
		float len = x * x + y * y;
		len = sqrt(len);
		return len;
	}

	/// <summary>
	/// 自身の大きさの2乗を返す
	/// </summary>
	/// <returns>float</returns>
	float Magnitude()
	{
		float mag = x * x + y + y;
		return mag;
	}
};

Vec2 operator+(Vec2 a,Vec2 b)
{
	Vec2 ans;
	ans.x = a.x + b.x;
	ans.y = a.y + b.y;
}
//Vec2 ans = a + b;