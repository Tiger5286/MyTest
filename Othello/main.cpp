#include <iostream>
#include <conio.h>  // getch() キー入力を直接取得

// コンソール削除
// std::system("cls");

#define BOARD_SIZE 10

// board: 0:空白　1:黒　2:白  3:盤外

struct Pos
{
	int x;
	int y;
};

// 画面表示用関数ここから

void DispBoard(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	std::cout << "\033[42m";
	for (int y = 1; y < BOARD_SIZE-1; y++)
	{
		for (int x = 1; x < BOARD_SIZE-1; x++)
		{
			if (choicePos.x == x && choicePos.y == y)
			{
				std::cout << "\033[41m";
			}

			if (board[y][x] == 0)
			{
				std::cout << "　";
			}
			if (board[y][x] == 1)
			{
				std::cout << "\033[30m黒";
			}
			if (board[y][x] == 2)
			{
				std::cout << "\033[37m白";
			}
			std::cout << "\033[42m";
		}
		std::cout << std::endl;
	}
	std::cout << "\033[0m";
}

void DispPieceCount(const int board[BOARD_SIZE][BOARD_SIZE])
{
	int blackPieceCount = 0;
	int whitePieceCount = 0;
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (board[y][x] == 1)
			{
				blackPieceCount++;
			}
			if (board[y][x] == 2)
			{
				whitePieceCount++;
			}
		}
	}
	std::cout << "  黒:" << blackPieceCount << " 白:" << whitePieceCount << std::endl;
}

void DispTurn(bool isTurn)
{
	if (isTurn)
	{
		std::cout << "  黒のターン" << std::endl;
	}
	else
	{
		std::cout << "  \033[47m\033[30m白のターン\033[0m" << std::endl;
	}
}

void DispResult(int blackPieceCount, int whitePieceCount)
{
	if (blackPieceCount > whitePieceCount)
	{
		std::cout << "　黒の勝ち" << std::endl;
	}
	else if (blackPieceCount < whitePieceCount)
	{
		std::cout << "  \033[47m\033[30m白のターン\033[0m" << std::endl;
	}
	else
	{
		std::cout << "　引き分け" << std::endl;
	}
}

// 画面表示用関数ここまで

int CheckBlackMinusY(const int board[BOARD_SIZE][BOARD_SIZE],Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y - checkSquare][choicePos.x] != 2)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckBlackPlusY(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y + checkSquare][choicePos.x] != 2)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckBlackMinusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y][choicePos.x - checkSquare] != 2)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckBlackPlusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y][choicePos.x + checkSquare] != 2)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckBlackMinusYMinusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y - checkSquare][choicePos.x - checkSquare] != 2)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckBlackMinusYPlusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y - checkSquare][choicePos.x + checkSquare] != 2)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckBlackPlusYMinusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y + checkSquare][choicePos.x - checkSquare] != 2)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckBlackPlusYPlusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y + checkSquare][choicePos.x + checkSquare] != 2)
		{
			break;
		}
	}
	return checkSquare;
}


int CheckWhiteMinusY(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y - checkSquare][choicePos.x] != 1)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckWhitePlusY(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y + checkSquare][choicePos.x] != 1)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckWhiteMinusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y][choicePos.x - checkSquare] != 1)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckWhitePlusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y][choicePos.x + checkSquare] != 1)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckWhiteMinusYMinusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y - checkSquare][choicePos.x - checkSquare] != 1)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckWhiteMinusYPlusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y - checkSquare][choicePos.x + checkSquare] != 1)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckWhitePlusYMinusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y + checkSquare][choicePos.x - checkSquare] != 1)
		{
			break;
		}
	}
	return checkSquare;
}

int CheckWhitePlusYPlusX(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos)
{
	int checkSquare = 0;
	while (1)
	{
		checkSquare++;
		if (board[choicePos.y + checkSquare][choicePos.x + checkSquare] != 1)
		{
			break;
		}
	}
	return checkSquare;
}


bool CheckCanPlace(const int board[BOARD_SIZE][BOARD_SIZE], Pos choicePos,bool isTurn)
{
	if (board[choicePos.y][choicePos.x] != 0)
	{
		return false;
	}

	if (isTurn)
	{
		if (CheckBlackMinusY(board,choicePos) > 1 && board[choicePos.y - CheckBlackMinusY(board, choicePos)][choicePos.x] == 1)
		{
			return true;
		}
		if (CheckBlackPlusY(board, choicePos) > 1 && board[choicePos.y + CheckBlackPlusY(board, choicePos)][choicePos.x] == 1)
		{
			return true;
		}
		if (CheckBlackMinusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x - CheckBlackMinusX(board, choicePos)] == 1)
		{
			return true;
		}
		if (CheckBlackPlusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x + CheckBlackPlusX(board, choicePos)] == 1)
		{
			return true;
		}

		if (CheckBlackMinusYMinusX(board, choicePos) > 1 && board[choicePos.y - CheckBlackMinusYMinusX(board, choicePos)][choicePos.x - CheckBlackMinusYMinusX(board, choicePos)] == 1)
		{
			return true;
		}
		if (CheckBlackMinusYPlusX(board, choicePos) > 1 && board[choicePos.y - CheckBlackMinusYPlusX(board, choicePos)][choicePos.x + CheckBlackMinusYPlusX(board, choicePos)] == 1)
		{
			return true;
		}
		if (CheckBlackPlusYMinusX(board, choicePos) > 1 && board[choicePos.y + CheckBlackPlusYMinusX(board, choicePos)][choicePos.x - CheckBlackPlusYMinusX(board, choicePos)] == 1)
		{
			return true;
		}
		if (CheckBlackPlusYPlusX(board, choicePos) > 1 && board[choicePos.y + CheckBlackPlusYPlusX(board, choicePos)][choicePos.x + CheckBlackPlusYPlusX(board, choicePos)] == 1)
		{
			return true;
		}

	}
	else
	{
		if (CheckWhiteMinusY(board, choicePos) > 1 && board[choicePos.y - CheckWhiteMinusY(board, choicePos)][choicePos.x] == 2)
		{
			return true;
		}
		if (CheckWhitePlusY(board, choicePos) > 1 && board[choicePos.y + CheckWhitePlusY(board, choicePos)][choicePos.x] == 2)
		{
			return true;
		}
		if (CheckWhiteMinusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x - CheckWhiteMinusX(board, choicePos)] == 2)
		{
			return true;
		}
		if (CheckWhitePlusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x + CheckWhitePlusX(board, choicePos)] == 2)
		{
			return true;
		}

		if (CheckWhiteMinusYMinusX(board, choicePos) > 1 && board[choicePos.y - CheckWhiteMinusYMinusX(board, choicePos)][choicePos.x - CheckWhiteMinusYMinusX(board, choicePos)] == 2)
		{
			return true;
		}
		if (CheckWhiteMinusYPlusX(board, choicePos) > 1 && board[choicePos.y - CheckWhiteMinusYPlusX(board, choicePos)][choicePos.x + CheckWhiteMinusYPlusX(board, choicePos)] == 2)
		{
			return true;
		}
		if (CheckWhitePlusYMinusX(board, choicePos) > 1 && board[choicePos.y + CheckWhitePlusYMinusX(board, choicePos)][choicePos.x - CheckWhitePlusYMinusX(board, choicePos)] == 2)
		{
			return true;
		}
		if (CheckWhitePlusYPlusX(board, choicePos) > 1 && board[choicePos.y + CheckWhitePlusYPlusX(board, choicePos)][choicePos.x + CheckWhitePlusYPlusX(board, choicePos)] == 2)
		{
			return true;
		}
	}
	return false;
}

void FlipPiece(int board[BOARD_SIZE][BOARD_SIZE],Pos choicePos,bool isTurn)
{
	if (isTurn)
	{
		board[choicePos.y][choicePos.x] = 1;
		int temp;
		if (CheckBlackMinusY(board, choicePos) > 1 && board[choicePos.y - CheckBlackMinusY(board, choicePos)][choicePos.x] == 1)
		{
			temp = CheckBlackMinusY(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y - i][choicePos.x] = 1;
			}
		}
		if (CheckBlackPlusY(board, choicePos) > 1 && board[choicePos.y + CheckBlackPlusY(board, choicePos)][choicePos.x] == 1)
		{
			temp = CheckBlackPlusY(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y + i][choicePos.x] = 1;
			}
		}
		if (CheckBlackMinusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x - CheckBlackMinusX(board, choicePos)] == 1)
		{
			temp = CheckBlackMinusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y][choicePos.x - i] = 1;
			}
		}
		if (CheckBlackPlusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x + CheckBlackPlusX(board, choicePos)] == 1)
		{
			temp = CheckBlackPlusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y][choicePos.x + i] = 1;
			}
		}

		if (CheckBlackMinusYMinusX(board, choicePos) > 1 && board[choicePos.y - CheckBlackMinusYMinusX(board, choicePos)][choicePos.x - CheckBlackMinusYMinusX(board, choicePos)] == 1)
		{
			temp = CheckBlackMinusYMinusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y - i][choicePos.x - i] = 1;
			}
		}
		if (CheckBlackMinusYPlusX(board, choicePos) > 1 && board[choicePos.y - CheckBlackMinusYPlusX(board, choicePos)][choicePos.x + CheckBlackMinusYPlusX(board, choicePos)] == 1)
		{
			temp = CheckBlackMinusYPlusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y - i][choicePos.x + i] = 1;
			}
		}
		if (CheckBlackPlusYMinusX(board, choicePos) > 1 && board[choicePos.y + CheckBlackPlusYMinusX(board, choicePos)][choicePos.x - CheckBlackPlusYMinusX(board, choicePos)] == 1)
		{
			temp = CheckBlackPlusYMinusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y + i][choicePos.x - i] = 1;
			}
		}
		if (CheckBlackPlusYPlusX(board, choicePos) > 1 && board[choicePos.y + CheckBlackPlusYPlusX(board, choicePos)][choicePos.x + CheckBlackPlusYPlusX(board, choicePos)] == 1)
		{
			temp = CheckBlackPlusYPlusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y + i][choicePos.x + i] = 1;
			}
		}
	}
	else
	{
		board[choicePos.y][choicePos.x] = 2;
		int temp;
		if (CheckWhiteMinusY(board, choicePos) > 1 && board[choicePos.y - CheckWhiteMinusY(board, choicePos)][choicePos.x] == 2)
		{
			temp = CheckWhiteMinusY(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y - i][choicePos.x] = 2;
			}
		}
		if (CheckWhitePlusY(board, choicePos) > 1 && board[choicePos.y + CheckWhitePlusY(board, choicePos)][choicePos.x] == 2)
		{
			temp = CheckWhitePlusY(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y + i][choicePos.x] = 2;
			}
		}
		if (CheckWhiteMinusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x - CheckWhiteMinusX(board, choicePos)] == 2)
		{
			temp = CheckWhiteMinusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y][choicePos.x - i] = 2;
			}
		}
		if (CheckWhitePlusX(board, choicePos) > 1 && board[choicePos.y][choicePos.x + CheckWhitePlusX(board, choicePos)] == 2)
		{
			temp = CheckWhitePlusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y][choicePos.x + i] = 2;
			}
		}
		
		if (CheckWhiteMinusYMinusX(board, choicePos) > 1 && board[choicePos.y - CheckWhiteMinusYMinusX(board, choicePos)][choicePos.x - CheckWhiteMinusYMinusX(board, choicePos)] == 2)
		{
			temp = CheckWhiteMinusYMinusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y - i][choicePos.x - i] = 2;
			}
		}
		if (CheckWhiteMinusYPlusX(board, choicePos) > 1 && board[choicePos.y - CheckWhiteMinusYPlusX(board, choicePos)][choicePos.x + CheckWhiteMinusYPlusX(board, choicePos)] == 2)
		{
			temp = CheckWhiteMinusYPlusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y - i][choicePos.x + i] = 2;
			}
		}
		if (CheckWhitePlusYMinusX(board, choicePos) > 1 && board[choicePos.y + CheckWhitePlusYMinusX(board, choicePos)][choicePos.x - CheckWhitePlusYMinusX(board, choicePos)] == 2)
		{
			temp = CheckWhitePlusYMinusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y + i][choicePos.x - i] = 2;
			}
		}
		if (CheckWhitePlusYPlusX(board, choicePos) > 1 && board[choicePos.y + CheckWhitePlusYPlusX(board, choicePos)][choicePos.x + CheckWhitePlusYPlusX(board, choicePos)] == 2)
		{
			temp = CheckWhitePlusYPlusX(board, choicePos);
			for (int i = 1; i < temp; i++)
			{
				board[choicePos.y + i][choicePos.x + i] = 2;
			}
		}
	}
}

Pos MoveChoice(char input,Pos choicePos)
{
	Pos move;
	move.x = choicePos.x;
	move.y = choicePos.y;
	if (input == 'w')
	{
		if (move.y != 1)
		{
			move.y--;
		}
	}
	if (input == 's')
	{
		if (move.y != BOARD_SIZE - 2)
		{
			move.y++;
		}
	}
	if (input == 'a')
	{
		if (move.x != 1)
		{
			move.x--;
		}
	}
	if (input == 'd')
	{
		if (move.x != BOARD_SIZE - 2)
		{
			move.x++;
		}
	}
	return move;
}

bool CheckCanPlaceAll(const int board[BOARD_SIZE][BOARD_SIZE], bool isTurn)
{
	bool canPlaceAll = false;
	Pos checkSquare;
	for (int y = 1; y < BOARD_SIZE - 1; y++)
	{
		for (int x = 1; x < BOARD_SIZE - 1; x++)
		{
			checkSquare.y = y;
			checkSquare.x = x;
			if (CheckCanPlace(board, checkSquare, isTurn))
			{
				canPlaceAll = true;
			}
		}
	}
	return canPlaceAll;
}

void PieceCount(const int board[BOARD_SIZE][BOARD_SIZE], int* pBlackPieceCount,int* pWhitePieceCount)
{
	int blackPieceCount = 0;
	int whitePieceCount = 0;
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (board[y][x] == 1)
			{
				blackPieceCount++;
			}
			else if (board[y][x] == 2)
			{
				whitePieceCount++;
			}
		}
	}
	*pBlackPieceCount = blackPieceCount;
	*pWhitePieceCount = whitePieceCount;
}

int main(void)
{
	int sceneNumber = 0;	// 0:タイトル	// 1:ゲーム
	char input;		// 入力を保存
	while (1)
	{
		if (sceneNumber == 0)
		{
			// タイトル表示
			std::system("cls");
			std::cout << "+-------------+" << std::endl;
			std::cout << "|   \033[42m\033[30mOthello\033[0m   |" << std::endl;
			std::cout << "+-------------+" << std::endl;
			std::cout << "               " << std::endl;
			std::cout << "  Press Space  " << std::endl;

			// spaceを入力して開始
			while (1)
			{
				input = _getch();
				if (input == ' ')
				{
					sceneNumber = 1;
					break;
				}
			}
		}
		else if (sceneNumber == 1)
		{
			// 選択位置
			Pos choicePos;
			choicePos.x = 1;
			choicePos.y = 1;

			// 盤の初期化
			int board[BOARD_SIZE][BOARD_SIZE] = {
				{3,3,3,3,3,3,3,3,3,3},
				{3,0,0,0,0,0,0,0,0,3},
				{3,0,0,0,0,0,0,0,0,3},
				{3,0,0,0,0,0,0,0,0,3},
				{3,0,0,0,2,1,0,0,0,3},
				{3,0,0,0,1,2,0,0,0,3},
				{3,0,0,0,0,0,0,0,0,3},
				{3,0,0,0,0,0,0,0,0,3},
				{3,0,0,0,0,0,0,0,0,3},
				{3,3,3,3,3,3,3,3,3,3}
			};

			// 先手を黒にする
			bool isTurn = true;	// true:黒のターン　false:白のターン

			while (1)
			{
				// コンソールをクリア
				std::system("cls");

				// 勝敗判定
				int blackPieceCount = 0;
				int whitePieceCount = 0;
				PieceCount(board, &blackPieceCount, &whitePieceCount);
				if (blackPieceCount + whitePieceCount == (BOARD_SIZE - 2) * (BOARD_SIZE - 2) || blackPieceCount == 0 || whitePieceCount == 0)
				{
					choicePos.x = 0;
					choicePos.y = 0;
					DispBoard(board, choicePos);
					DispResult(blackPieceCount, whitePieceCount);
					std::cout << std::endl;
					DispPieceCount(board);

					std::cout << "もう一度？" << std::endl;
					std::cout << "1:再戦　2:終了" << std::endl;
					input = _getch();
					if (input == '2')
					{
						sceneNumber = 0;
					}
					break;
				}

				// 画面の表示
				DispBoard(board, choicePos);
				DispTurn(isTurn);
				std::cout << std::endl;
				DispPieceCount(board);
				std::cout << "WASD:選択　Space:コマを置く" << std::endl;

				// 入力
				input = _getch();

				// 入力に応じた操作
				choicePos = MoveChoice(input, choicePos);
				if (input == ' ' && CheckCanPlace(board, choicePos, isTurn))
				{
					FlipPiece(board, choicePos, isTurn);
					if (isTurn)
					{
						isTurn = false;
					}
					else
					{
						isTurn = true;
					}
				}

				// パス機能
				if (!CheckCanPlaceAll(board, isTurn))
				{
					if (isTurn)
					{
						isTurn = false;
					}
					else
					{
						isTurn = true;
					}
				}
			}
		}
		else
		{
			std::cout << "SceneError" << std::endl;
		}
	}
	
	

	return 0;
}