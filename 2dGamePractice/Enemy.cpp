#include "Enemy.h"
#include "Dxlib.h"

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
	//DrawRotaGraph(m_pos.x, m_pos.y, kDrawScale, 0, m_handle, false, m_isLeft);
#ifdef _DEBUG
	// 当たり判定の描画
	m_colRect.Draw(0xff0000, false);
	// HP表示
	DrawFormatString(0, 16, 0xffffff, "Enemy HP:%d", m_hp);
#endif // _DEBUG
}
