#pragma once
#include "Vec2.h"

class Player;

/// <summary>
/// �w�i�Ǘ��N���X
/// </summary>
class Bg
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Bg(Player* pPlayer);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Bg();

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
	/// ���̃X�N���[���ʂ����肷��
	/// </summary>
	/// <returns>���X�N���[����</returns>
	int GetScrollX();

	/// <summary>
	/// �c�̃X�N���[���ʂ����肷��
	/// </summary>
	/// <returns>�c�X�N���[����</returns>
	int GetScrollY();

private:
	/// <summary>
	/// �w�i�`��
	/// </summary>
	void DrawBg();

private:
	int m_bgHandle; // �w�i�摜�n���h��
	Vec2 m_pos;     // �ʒu
	Player* m_pPlayer; // �v���C���[�̃|�C���^
};