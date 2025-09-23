#pragma once

namespace
{
	constexpr int kShotMax = 10; // �e�̍ő吔
}

class Player;
class Enemy;
class Shot;

/// <summary>
/// �V�[�����C��
/// </summary>
class SceneMain
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SceneMain();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SceneMain();

	/// <summary>
	/// ����������
	/// </summary>
	void Init();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

private:
	/// <summary>
	/// �L�����N�^�[������ł��邩�`�F�b�N
	/// </summary>
	void CheckCharacterDeath();

	/// <summary>
	/// �e�̍X�V����
	/// </summary>
	void UpdateShot();

	/// <summary>
	/// �e�폜
	/// </summary>
	void DeleteShot(int index);

private:
	Player* m_pPlayer;
	Enemy* m_pEnemy;
	Shot* m_pShot[kShotMax];
};

