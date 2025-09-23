#include "Player.h"
#include "Dxlib.h"
#include "Pad.h"
#include "Shot.h"

namespace // �萔��`
{
	constexpr float kSpeed	   = 10.0f;	// �ړ����x
	constexpr float kJumpPower = 20.0f; // �W�����v��
	constexpr float kDrawScale = 4.0f;  // �`��{��
}

Player::Player()
{
	// �R���X�g���N�^�ŉ摜���������Ƀ��[�h
	m_handle = LoadGraph("data/player.png");
}

Player::~Player()
{
	// �f�X�g���N�^�ŉ摜��������������
	DeleteGraph(m_handle);
}

void Player::Init()
{
	m_pos = Vec2(100.0f, 100.0f);	// �����ʒu
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
	// �_���[�W���󂯂Ă���Ԃ͓_�ł�����
	if (!(m_damageFrame > 0 && (m_damageFrame / 5) % 2 == 0))
	{
		DrawRotaGraph(m_pos.x, m_pos.y, kDrawScale, 0, m_handle, true, m_isLeft);
	}

#ifdef _DEBUG
	// �����蔻��̕`��
	m_colRect.Draw(0x0000ff, false);
	// HP�\��
	DrawFormatString(0, 0, 0xffffff, "Player HP:%d", m_hp);
#endif // _DEBUG
}

Shot* Player::CreateShot()
{
	if (Pad::IsTrigger(PAD_INPUT_2))	// B�{�^���������ꂽ�Ƃ�
	{
		Shot* pShot = new Shot();		 // �e�𐶐�
		pShot->SetInfo(m_pos, m_isLeft); // �e�̏���ݒ�
		return pShot;					 // ���������e�̃|�C���^��Ԃ�
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
	// �ڒn���Ă��Ȃ����͎��s���Ȃ�
	if (!m_isGround) return;

	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		m_move.y = -kJumpPower;
		m_isGround = false;
	}
}
