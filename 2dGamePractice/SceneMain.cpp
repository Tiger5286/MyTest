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

	if (!m_pEnemy || !m_pPlayer) return; // どちらかが死んでいたら以降の処理をしない

	// プレイヤーが敵と当たったらダメージを受ける
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

	DrawLine(0, 600, Game::kScreenW, 600, 0xffffff); // 地面の描画
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

	Shot* newShot = nullptr;							// 新しい弾用のポインタを用意
	if (m_pPlayer) newShot = m_pPlayer->CreateShot();	// プレイヤーが生きていたら弾を生成したか確認
	if (newShot != nullptr)		// 弾が生成されていたら
	{
		for (int i = 0; i < kShotMax; i++)	
		{									// 弾の配列の中から空いているところを探す
			if (m_pShot[i] == nullptr)
			{
				m_pShot[i] = newShot; // 空いているところにセット
				break;
			}
		}
	}

	for (int i = 0; i < kShotMax; i++)
	{
		if (!m_pShot[i]) continue; // 弾が存在しなかったら次のループへ
		m_pShot[i]->Update();

		// 弾が敵に当たった場合
		bool isColEnemy = m_pEnemy && m_pShot[i]->GetColRect().IsCollision(m_pEnemy->GetColRect());
		if (isColEnemy) m_pEnemy->OnDamage();	// 敵にダメージを与える

		// 画面外に出た場合
		bool isOutScreen = m_pShot[i]->GetPos().x < 0 || m_pShot[i]->GetPos().x > Game::kScreenW;

		// どちらかの条件を満たしたら弾を削除
		if (isOutScreen || isColEnemy) DeleteShot(i);
	}
}

void SceneMain::DeleteShot(int index)
{
	if (!m_pShot[index]) return;

	delete m_pShot[index];
	m_pShot[index] = nullptr;
}
