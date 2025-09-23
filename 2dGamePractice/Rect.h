#pragma once
#include "Vec2.h"

/// <summary>
/// ��`���Ǘ�����N���X
/// </summary>
class Rect
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Rect();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Rect();

	/// <summary>
	/// ��`�̕`��
	/// </summary>
	/// <param name="color">��`�̐F</param>
	/// <param name="isFill">��`�̒���h��Ԃ����ǂ���</param>
	void Draw(unsigned int color, bool isFill);

	/// <summary>
	/// ������W�ƕ��A������ݒ�
	/// </summary>
	/// <param name="left">��x���W</param>
	/// <param name="top">��y���W</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	void SetLT(float left, float top, float width, float height);

	/// <summary>
	/// ���S���W�ƕ��A������ݒ�
	/// </summary>
	/// <param name="x">���S��x���W</param>
	/// <param name="y">���S��y���W</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	void SetCenter(float x, float y, float width, float height);

	/// <summary>
	/// ��`�̕����擾
	/// </summary>
	/// <returns>��</returns>
	float GetWidth() const;

	/// <summary>
	/// ��`�̍������擾
	/// </summary>
	/// <returns>����</returns>
	float GetHeight() const;

	/// <summary>
	/// ��`�̒��S���W���擾
	/// </summary>
	/// <returns>���S���W</returns>
	Vec2 GetCenter() const;

	/// <summary>
	/// ��`�̍���X���W���擾
	/// </summary>
	/// <returns></returns>
	float GetLeft() const { return m_left; }

	/// <summary>
	/// ��`�̍���Y���W���擾
	/// </summary>
	/// <returns></returns>
	float GetTop() const { return m_top; }

	/// <summary>
	/// ��`�̉E��X���W���擾
	/// </summary>
	/// <returns></returns>
	float GetRight() const { return m_right; }

	/// <summary>
	/// ��`�̉E��Y���W���擾
	/// </summary>
	/// <returns></returns>
	float GetBottom() const { return m_bottom; }

	bool IsCollision(const Rect& rect);

public:

	float m_left;	// �����X���W
	float m_top;	// �����Y���W
	float m_right;	// �E����X���W
	float m_bottom; // �E����Y���W
};

