#pragma once
#include "Character.h"

/// <summary>
/// �G�N���X
/// </summary>
class Enemy : public Character
{
public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Enemy();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Enemy();

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
};

