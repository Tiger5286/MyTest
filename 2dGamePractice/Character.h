#pragma once
#include "Vec2.h"
#include "Rect.h"

class Bg;

/// <summary>
/// �L�����N�^�[�̊��N���X
/// </summary>
class Character
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Character();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Character();

	/// <summary>
	/// ����������
	/// </summary>
	virtual void Init();

	/// <summary>
	/// �X�V����
	/// </summary>
	virtual void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// �_���[�W���󂯂��ꍇ�̏���
	/// </summary>
	void OnDamage();

	/// <summary>
	/// �ʒu���擾
	/// </summary>
	/// <returns>�ʒu</returns>
	Vec2 GetPos() const { return m_pos; }

	/// <summary>
	/// HP�擾
	/// </summary>
	/// <returns>HP</returns>
	int GetHp() const { return m_hp; }

	/// <summary>
	/// �����蔻����擾
	/// </summary>
	/// <returns>�����蔻����</returns>
	Rect GetColRect() const { return m_colRect; } // �����蔻��擾

	/// <summary>
	/// Bg�N���X�̃|�C���^���Z�b�g����
	/// </summary>
	/// <param name="pBg">Bg�N���X�|�C���^</param>
	void SetBgPointer(Bg* pBg) { m_pBg = pBg; }

protected:
	/// <summary>
	/// �d�͏���
	/// </summary>
	void Gravity();

protected:
	// �摜�n���h��
	int m_handle;

	Vec2 m_pos;		 // �ʒu
	Vec2 m_move;	 // �ړ���
	bool m_isLeft;	 // ���������ǂ���
	bool m_isGround; // �ڒn���Ă��邩�ǂ���

	int m_hp;		   // HP
	int m_damageFrame; // �_���[�W���󂯂Ă���̌o�߃t���[����

	Bg* m_pBg;

	// �����蔻��p�̋�`
	Rect m_colRect;
};

