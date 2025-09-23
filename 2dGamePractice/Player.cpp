#include "Player.h"
#include "Dxlib.h"
#include "Pad.h"
#include "Shot.h"

namespace // 定数定義
{
	constexpr float kSpeed	   = 10.0f;	// 移動速度
	constexpr float kJumpPower = 20.0f; // ジャンプ力
	constexpr float kDrawScale = 4.0f;  // 描画倍率
}

Player::Player()
{
	// コンストラクタで画像をメモリにロード
	m_handle = LoadGraph("data/player.png");
}

Player::~Player()
{
	// デストラクタで画像をメモリから解放
	DeleteGraph(m_handle);
}

void Player::Init()
{
	m_pos = Vec2(100.0f, 100.0f);	// 初期位置
}

void Player::Update()
{
	Character::Update();
	Move();
	Jump();
	m_pos += m_move;
}

void Player::Draw()
{
	// ダメージを受けている間は点滅させる
	if (!(m_damageFrame > 0 && (m_damageFrame / 5) % 2 == 0))
	{
		DrawRotaGraph(m_pos.x, m_pos.y, kDrawScale, 0, m_handle, true, m_isLeft);
	}

#ifdef _DEBUG
	// 当たり判定の描画
	m_colRect.Draw(0x0000ff, false);
	// HP表示
	DrawFormatString(0, 0, 0xffffff, "Player HP:%d", m_hp);
#endif // _DEBUG
}

Shot* Player::CreateShot()
{
	if (Pad::IsTrigger(PAD_INPUT_2))	// Bボタンが押されたとき
	{
		Shot* pShot = new Shot();		 // 弾を生成
		pShot->SetInfo(m_pos, m_isLeft); // 弾の情報を設定
		return pShot;					 // 生成した弾のポインタを返す
	}
	return nullptr;
}

void Player::Move()
{
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		m_move.x = -kSpeed;
		m_isLeft = true;
	}
	else if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		m_move.x = kSpeed;
		m_isLeft = false;
	}
	else
	{
		m_move.x = 0.0f;
	}
}

void Player::Jump()
{
	// 接地していない時は実行しない
	if (!m_isGround) return;

	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		m_move.y = -kJumpPower;
		m_isGround = false;
	}
}
