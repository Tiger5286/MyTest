#include "Shot.h"
#include "Dxlib.h"

namespace
{
	constexpr float kDrawScale = 1.0f; // �`��{��
	constexpr float kSpeed = 20.0f; // �e�̑��x

	constexpr float kShotSize = 16.0f; // �e�̃T�C�Y
}

Shot::Shot() :
	m_pos(0.0f, 0.0f),
	m_move(kSpeed, 0.0f)
{
	// �R���X�g���N�^�ŉ摜���������Ƀ��[�h
	m_handle = LoadGraph("data/shot.png");
}

Shot::~Shot()
{
	// �f�X�g���N�^�ŉ摜��������������
	DeleteGraph(m_handle);
}

void Shot::Init()
{
}

void Shot::Update()
{
	m_colRect.SetCenter(m_pos.x, m_pos.y, kShotSize, kShotSize);
	m_pos += m_move;
}

void Shot::Draw()
{
	DrawRotaGraph(m_pos.x, m_pos.y, kDrawScale, 0.0f, m_handle, true);
#ifdef _DEBUG
	// �����蔻��̕`��
	m_colRect.Draw(0x00ff00, false);
#endif // _DEBUG
}

void Shot::SetInfo(const Vec2& pos, bool isLeft)
{
	m_pos = pos;

	if (isLeft)
	{
		m_move.x = -kSpeed;
	}
	else
	{
		m_move.x = kSpeed;
	}
}
