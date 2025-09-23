#pragma once
#include <cmath>

class Vec2
{
public:
	float x;
	float y;

	// �R���X�g���N�^
	Vec2() :
		x(0.0f),
		y(0.0f)
	{
	}

	// �����t���R���X�g���N�^
	Vec2(float posX, float posY) :
		x(posX),
		y(posY)
	{
	}

	// �P�����Z�q+
	Vec2 operator+() const
	{
		return *this;
	}

	// �P�����Z�q-
	Vec2 operator-() const
	{
		return Vec2(-x, -y);
	}

	// �����Z
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

	// �����Z
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

	// �X�J���[�{
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

	// �X�J���[���Z
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

	// �x�N�g���̒����̓��
	float sqLength() const
	{
		return x * x + y * y;
	}

	// �x�N�g���̒���
	float length() const
	{
		return sqrtf(sqLength());
	}

	// ���g�𐳋K������
	void normalize()
	{
		float len = length();
		if (len != 0.0f)
		{
			x /= len;
			y /= len;
		}
		// ������0�̂Ƃ��͐��K���ł��Ȃ��̂ł��̂܂�
	}

	// ���g�𐳋K�������x�N�g����Ԃ�
	Vec2 GetNormalize() const
	{
		float len = length();
		if (len != 0.0f)
		{
			return Vec2(x / len, y / len);
		}
		// ������0�̂Ƃ��͐��K���ł��Ȃ��̂�(0,0)��Ԃ�
		return Vec2(0.0f, 0.0f);
	}
};