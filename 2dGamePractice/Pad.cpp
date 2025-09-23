#include "Pad.h"
#include "Dxlib.h"

namespace
{
	// 前のフレームのボタン状態
	int lastPad = 0;

	// 現在のフレームのボタン状態
	int nowPad = 0;
}

namespace Pad
{
	void Pad::Update()
	{
		// 前のフレームに取得したボタン状態を一つ古い状態にする
		lastPad = nowPad;

		// 現在のボタン状態を取得
		nowPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}

	bool Pad::IsPress(int key)
	{
		// 現在のフレームで押されている
		return (nowPad & key);
	}

	bool Pad::IsTrigger(int key)
	{
		bool isNow = (nowPad & key);	// 現在のフレームの状態
		bool isLast = (lastPad & key);	// 前のフレームの状態

		// 今のフレームで押されていて、前のフレームで押されていない
		if (isNow && !isLast)
		{
			return true;
		}
		return false;
	}

	bool Pad::IsRelease(int key)
	{
		bool isNow = (nowPad & key);	// 現在のフレームの状態
		bool isLast = (lastPad & key);	// 前のフレームの状態

		// 今のフレームで押されていなくて、前のフレームで押されている
		if (!isNow && isLast)
		{
			return true;
		}
		return false;
	}
}
