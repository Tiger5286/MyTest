#include "DxLib.h"
#include "Game.h"
#include "SceneMain.h"
#include "Pad.h"

// プログラムは WinMain から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウインドウモード設定
	ChangeWindowMode(true);
	// ウインドウのタイトル変更
	SetMainWindowText("ゲーム名");
	// 画面のサイズ変更
	SetGraphMode(Game::kScreenW, Game::kScreenH, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 描画対象をバックバッファに変更
	SetDrawScreen(DX_SCREEN_BACK);

	SceneMain* pScene = new SceneMain();
	pScene->Init();

	while (ProcessMessage() != -1)
	{
		// このフレームの開始時間を取得
		LONGLONG start = GetNowHiPerformanceCount();

		// 前のフレームに描画した内容をクリアする
		ClearDrawScreen();

		Pad::Update();
		pScene->Update();
		pScene->Draw();

		ScreenFlip();

		// escキーを押したらゲームを強制終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// フレームレートを60に固定
		while (GetNowHiPerformanceCount() - start < Game::kFrameRate)
		{

		}
	}

	delete pScene;
	pScene = nullptr;

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}