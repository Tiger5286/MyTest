#pragma once
#include "Character.h"

class Shot;

/// <summary>
/// �v���C���[�N���X
/// </summary>
class Player : public Character
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Player();

	/// <summary>
	/// ����������
	/// </summary>
	void Init() override;

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update() override;

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw() override;

	/// <summary>
	/// �e����
	/// </summary>
	/// <returns>Shot�|�C���^</returns>
	Shot* CreateShot();
private:
	/// <summary>
	/// �ړ�����
	/// </summary>
	void Move();

	/// <summary>
	/// �W�����v����
	/// </summary>
	void Jump();
};

