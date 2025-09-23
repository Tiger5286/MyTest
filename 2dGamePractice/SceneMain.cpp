#include "SceneMain.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Shot.h"
#include "Dxlib.h"

SceneMain::SceneMain()
{
	m_pPlayer = new Player();
	m_pEnemy = new Enemy();
	for (int i = 0; i < kShotMax; i++)
	{
		m_pShot[i] = nullptr;
	}
}

SceneMain::~SceneMain()
{
	delete m_pPlayer;
	m_pPlayer = nullptr;
	delete m_pEnemy;
	m_pEnemy = nullptr;
}

void SceneMain::Init()
{
	m_pPlayer->Init();
	m_pEnemy->Init();
}

void SceneMain::Update()
{
	if (m_pPlayer) m_pPlayer->Update();
	if (m_pEnemy) m_pEnemy->Update();
	UpdateShot();
	CheckCharacterDeath();

	if (!m_pEnemy || !m_pPlayer) return; // �ǂ��炩������ł�����ȍ~�̏��������Ȃ�

	// �v���C���[���G�Ɠ���������_���[�W���󂯂�
	bool isDamage = m_pPlayer->GetColRect().IsCollision(m_pEnemy->GetColRect());
	if (isDamage) m_pPlayer->OnDamage();
}

void SceneMain::Draw()
{
	if (m_pPlayer) m_pPlayer->Draw();
	if (m_pEnemy) m_pEnemy->Draw();

	for (int i = 0; i < kShotMax; i++)
	{
		if (!m_pShot[i]) continue;
		m_pShot[i]->Draw();
	}

	DrawLine(0, 600, Game::kScreenW, 600, 0xffffff); // �n�ʂ̕`��
}

void SceneMain::CheckCharacterDeath()
{
	if (m_pPlayer && m_pPlayer->GetHp() <= 0)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}
	if (m_pEnemy && m_pEnemy->GetHp() <= 0)
	{
		delete m_pEnemy;
		m_pEnemy = nullptr;
	}
}

void SceneMain::UpdateShot()
{

	Shot* newShot = nullptr;							// �V�����e�p�̃|�C���^��p��
	if (m_pPlayer) newShot = m_pPlayer->CreateShot();	// �v���C���[�������Ă�����e�𐶐��������m�F
	if (newShot != nullptr)		// �e����������Ă�����
	{
		for (int i = 0; i < kShotMax; i++)	
		{									// �e�̔z��̒�����󂢂Ă���Ƃ����T��
			if (m_pShot[i] == nullptr)
			{
				m_pShot[i] = newShot; // �󂢂Ă���Ƃ���ɃZ�b�g
				break;
			}
		}
	}

	for (int i = 0; i < kShotMax; i++)
	{
		if (!m_pShot[i]) continue; // �e�����݂��Ȃ������玟�̃��[�v��
		m_pShot[i]->Update();

		// �e���G�ɓ��������ꍇ
		bool isColEnemy = m_pEnemy && m_pShot[i]->GetColRect().IsCollision(m_pEnemy->GetColRect());
		if (isColEnemy) m_pEnemy->OnDamage();	// �G�Ƀ_���[�W��^����

		// ��ʊO�ɏo���ꍇ
		bool isOutScreen = m_pShot[i]->GetPos().x < 0 || m_pShot[i]->GetPos().x > Game::kScreenW;

		// �ǂ��炩�̏����𖞂�������e���폜
		if (isOutScreen || isColEnemy) DeleteShot(i);
	}
}

void SceneMain::DeleteShot(int index)
{
	if (!m_pShot[index]) return;

	delete m_pShot[index];
	m_pShot[index] = nullptr;
}
