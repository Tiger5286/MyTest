#pragma once

/// <summary>
/// �Q�[���p�b�h�̓��͂��Ǘ�����N���X
/// </summary>
namespace Pad
{
	/// <summary>
	/// �p�b�h�̍X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// ������Ă��邩�ǂ���
	/// </summary>
	/// <param name="key">���̓L�[</param>
	/// <returns>������Ă��邩�ǂ���</returns>
	bool IsPress(int key);

	/// <summary>
	/// �����ꂽ�u�Ԃ��擾
	/// </summary>
	/// <param name="key">���̓L�[</param>
	/// <returns>�����ꂽ���ǂ���</returns>
	bool IsTrigger(int key);

	/// <summary>
	/// �����ꂽ�u�Ԃ��擾
	/// </summary>
	/// <param name="key">���̓L�[</param>
	/// <returns>�����ꂽ���ǂ���</returns>
	bool IsRelease(int key);
}