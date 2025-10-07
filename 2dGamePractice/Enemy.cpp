#include "Enemy.h"
#include "Dxlib.h"
#include "Bg.h"

namespace
{
	float kDrawScale = 4.0f; // 描画倍率
}

Enemy::Enemy()
{
	// コンストラクタで画像をメモリにロード
	m_handle = LoadGraph("data/enemy.png");
}

Enemy::~Enemy()
{
	// デストラクタで画像をメモリから解放
	DeleteGraph(m_handle);
}

void Enemy::Init()
{
	m_pos = Vec2(200.0f, 100.0f);
}

void Enemy::Update()
{
	Character::Update();
	m_damageFrame = 0; // 無敵時間無効化
	m_pos += m_move;
}

void Enemy::Draw()
{
	Character::Draw();
#ifdef _DEBUG
	// 当たり判定の描画
	m_colRect.DrawScroll(m_pBg->GetScrollX(), m_pBg->GetScrollY(), 0xff0000, false);
	// HP表示
	DrawFormatString(0, 16, 0xffffff, "Enemy HP:%d", m_hp);
#endif // _DEBUG
}
