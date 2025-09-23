#include "DxLib.h"
#include "Game.h"
#include "SceneMain.h"
#include "Pad.h"

// �v���O������ WinMain ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �E�C���h�E���[�h�ݒ�
	ChangeWindowMode(true);
	// �E�C���h�E�̃^�C�g���ύX
	SetMainWindowText("�Q�[����");
	// ��ʂ̃T�C�Y�ύX
	SetGraphMode(Game::kScreenW, Game::kScreenH, 32);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �`��Ώۂ��o�b�N�o�b�t�@�ɕύX
	SetDrawScreen(DX_SCREEN_BACK);

	SceneMain* pScene = new SceneMain();
	pScene->Init();

	while (ProcessMessage() != -1)
	{
		// ���̃t���[���̊J�n���Ԃ��擾
		LONGLONG start = GetNowHiPerformanceCount();

		// �O�̃t���[���ɕ`�悵�����e���N���A����
		ClearDrawScreen();

		Pad::Update();
		pScene->Update();
		pScene->Draw();

		ScreenFlip();

		// esc�L�[����������Q�[���������I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// �t���[�����[�g��60�ɌŒ�
		while (GetNowHiPerformanceCount() - start < Game::kFrameRate)
		{

		}
	}

	delete pScene;
	pScene = nullptr;

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}