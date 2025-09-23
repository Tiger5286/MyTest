#include "Character.h"

namespace
{
	constexpr float kGravity       = 1.0f;   // 重力
	constexpr float kGround        = 600.0f; // 地面の高さ

	constexpr float kCharaSize     = 64.0f;  // キャラのサイズ

	constexpr int kMaxHp           = 10;     // 最大HP
	constexpr int kInvincibleFrame = 60;     // 無敵時間(フレーム)
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

	// 着地処理
	if (m_pos.y >= kGround)
	{
		m_pos.y = kGround;
		m_move.y = 0.0f;
		m_isGround = true;
	}

	// 当たり判定更新
	m_colRect.SetCenter(m_pos.x, m_pos.y, kCharaSize, kCharaSize);
	
	m_damageFrame--; // 無敵時間更新
}

void Character::Draw()
{
}

void Character::OnDamage()
{
	if (m_damageFrame > 0) return;	// 無敵時間中は処理しない

	m_hp--;
	m_damageFrame = kInvincibleFrame; // 無敵時間リセット
}

void Character::Gravity()
{
	m_move.y += kGravity;
}
