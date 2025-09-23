#include "Character.h"

namespace
{
	constexpr float kGravity       = 1.0f;   // �d��
	constexpr float kGround        = 600.0f; // �n�ʂ̍���

	constexpr float kCharaSize     = 64.0f;  // �L�����̃T�C�Y

	constexpr int kMaxHp           = 10;     // �ő�HP
	constexpr int kInvincibleFrame = 60;     // ���G����(�t���[��)
}

Character::Character():
	m_handle(-1),
	m_pos(),
	m_move(),
	m_isLeft(false),
	m_isGround(false),
	m_hp(kMaxHp),
	m_damageFrame(0)
{
}

Character::~Character()
{
}

void Character::Init()
{
}

void Character::Update()
{
	Gravity();

	// ���n����
	if (m_pos.y >= kGround)
	{
		m_pos.y = kGround;
		m_move.y = 0.0f;
		m_isGround = true;
	}

	// �����蔻��X�V
	m_colRect.SetCenter(m_pos.x, m_pos.y, kCharaSize, kCharaSize);
	
	m_damageFrame--; // ���G���ԍX�V
}

void Character::Draw()
{
}

void Character::OnDamage()
{
	if (m_damageFrame > 0) return;	// ���G���Ԓ��͏������Ȃ�

	m_hp--;
	m_damageFrame = kInvincibleFrame; // ���G���ԃ��Z�b�g
}

void Character::Gravity()
{
	m_move.y += kGravity;
}
