#include "Enemy.h"
#include "Dxlib.h"

namespace
{
	float kDrawScale = 4.0f; // �`��{��
}

Enemy::Enemy()
{
	// �R���X�g���N�^�ŉ摜���������Ƀ��[�h
	m_handle = LoadGraph("data/enemy.png");
}

Enemy::~Enemy()
{
	// �f�X�g���N�^�ŉ摜��������������
	DeleteGraph(m_handle);
}

void Enemy::Init()
{
	m_pos = Vec2(200.0f, 100.0f);
}

void Enemy::Update()
{
	Character::Update();
	m_damageFrame = 0; // ���G���Ԗ�����
	m_pos += m_move;
}

void Enemy::Draw()
{
	//DrawRotaGraph(m_pos.x, m_pos.y, kDrawScale, 0, m_handle, false, m_isLeft);
#ifdef _DEBUG
	// �����蔻��̕`��
	m_colRect.Draw(0xff0000, false);
	// HP�\��
	DrawFormatString(0, 16, 0xffffff, "Enemy HP:%d", m_hp);
#endif // _DEBUG
}
