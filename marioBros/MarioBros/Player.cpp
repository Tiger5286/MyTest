#include "Player.h"
#include "Game.h"
#include "Dxlib.h"

namespace
{
	int kPlayerWidth = 32;
	int kPlayerHeight = 48;
	float kMaxSpeed = 5;
	float kSpeed = 0.2f;
}

Player::Player():
	m_pos(0,0),
	m_speed(0,0)
{

}

Player::~Player()
{
}

void Player::Init()
{
	m_pos.x = Game::kScreenWidth / 2;
	m_pos.y = Game::kScreenHeight / 2;
}

void Player::End()
{
}

void Player::Update()
{
	// é©ëRÇ…é~Ç‹ÇÈóÕ
	if (m_speed.x > 0)
	{
		m_speed.x -= kSpeed / 2;
	}
	if (m_speed.x < 0)
	{
		m_speed.x += kSpeed / 2;
	}
	if (m_speed.x < 0.1f && m_speed.x > -0.1f)
	{
		m_speed.x = 0;
	}

	Vec2 a;
	a.Magnitude();

	// ç∂âEì¸óÕÇ≈ç∂âEà⁄ìÆ
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_RIGHT)
	{
		if (m_speed.x < kMaxSpeed)
		{
			m_speed.x += kSpeed;
		}
	}
	if (pad & PAD_INPUT_LEFT)
	{
		if (m_speed.x > -kMaxSpeed)
		{
			m_speed.x -= kSpeed;
		}
	}
	m_pos = m_pos + m_speed;
}

void Player::Draw()
{
	DrawBox(m_pos.x - (kPlayerWidth / 2), m_pos.y - (kPlayerHeight / 2),
		m_pos.x + (kPlayerWidth / 2), m_pos.y + (kPlayerHeight / 2), GetColor(0, 255, 0), false);
}