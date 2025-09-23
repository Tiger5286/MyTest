#include "Bg.h"
#include "Dxlib.h"
#include "Game.h"
#include "Player.h"

namespace
{
	constexpr float kMapWidth = 5000.0f; // マップ全体の幅
	constexpr float kMapHeight = 1080.0f; // マップ全体の高さ
}

Bg::Bg(Player* pPlayer):
	m_pos(),
	m_pPlayer(pPlayer)
{
	m_bgHandle = LoadGraph("data/bg.png");
}

Bg::~Bg()
{
	DeleteGraph(m_bgHandle);
}

void Bg::Init()
{
}

void Bg::Update()
{
}

void Bg::Draw()
{
	DrawBg();
}

int Bg::GetScrollX()
{
	int result = static_cast<int>(m_pPlayer->GetPos().x - Game::kScreenW / 2);
	if (result < 0)
	{
		result = 0;
	}
	if (result > kMapWidth - Game::kScreenW)
	{
		result = kMapWidth - Game::kScreenW;
	}
	return result;
}

int Bg::GetScrollY()
{
	int result = static_cast<int>(m_pPlayer->GetPos().y - Game::kScreenH / 2);
	if (result < 0)
	{
		result = 0;
	}
	if (result > kMapHeight - Game::kScreenH)
	{
		result = kMapHeight - Game::kScreenH;
	}
	return result;
}

void Bg::DrawBg()
{
	const Vec2 bgSize = Vec2(Game::kScreenW, Game::kScreenH);

	int scrollBg = GetScrollX() % static_cast<int>(bgSize.x);

	DrawExtendGraph(-scrollBg, m_pos.y, -scrollBg + Game::kScreenW, m_pos.y + Game::kScreenH, m_bgHandle, true);
	if (scrollBg > 0)
	{
		DrawExtendGraph(bgSize.x - scrollBg, Game::kScreenH - bgSize.y, (bgSize.x - scrollBg) + Game::kScreenW, (Game::kScreenH - bgSize.y) + Game::kScreenH, m_bgHandle, true);
	}
}
