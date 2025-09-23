#include "Pad.h"
#include "Dxlib.h"

namespace
{
	// �O�̃t���[���̃{�^�����
	int lastPad = 0;

	// ���݂̃t���[���̃{�^�����
	int nowPad = 0;
}

namespace Pad
{
	void Pad::Update()
	{
		// �O�̃t���[���Ɏ擾�����{�^����Ԃ���Â���Ԃɂ���
		lastPad = nowPad;

		// ���݂̃{�^����Ԃ��擾
		nowPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}

	bool Pad::IsPress(int key)
	{
		// ���݂̃t���[���ŉ�����Ă���
		return (nowPad & key);
	}

	bool Pad::IsTrigger(int key)
	{
		bool isNow = (nowPad & key);	// ���݂̃t���[���̏��
		bool isLast = (lastPad & key);	// �O�̃t���[���̏��

		// ���̃t���[���ŉ�����Ă��āA�O�̃t���[���ŉ�����Ă��Ȃ�
		if (isNow && !isLast)
		{
			return true;
		}
		return false;
	}

	bool Pad::IsRelease(int key)
	{
		bool isNow = (nowPad & key);	// ���݂̃t���[���̏��
		bool isLast = (lastPad & key);	// �O�̃t���[���̏��

		// ���̃t���[���ŉ�����Ă��Ȃ��āA�O�̃t���[���ŉ�����Ă���
		if (!isNow && isLast)
		{
			return true;
		}
		return false;
	}
}
