#pragma once
#include "Vec2.h"
#include "Rect.h"

/// <summary>
/// �e�Ǘ��N���X
/// </summary>
class Shot
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary> 
	Shot();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Shot();

	/// <summary>
	/// ����������
	/// </summary>
	void Init();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �����蔻����擾
	/// </summary>
	/// <returns>�����蔻����</returns>
	Rect GetColRect() const { return m_colRect; }

	/// <summary>
	/// �e�̏���ݒ�
	/// </summary>
	/// <param name="pos">���W</param>
	/// <param name="isLeft">�������Ɉړ����邩</param>
	void SetInfo(const Vec2& pos, bool isLeft);

	Vec2 GetPos() const { return m_pos; } // �ʒu�擾
private:
	// �摜�n���h��
	int m_handle;
	
	Vec2 m_pos;		// �ʒu
	Vec2 m_move;	// �ړ���

	// �����蔻��p�̋�`
	Rect m_colRect;
};

