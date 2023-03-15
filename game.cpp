#include "game.h"
#include"leaderBoard.h"
#include"Interface.h"
void startGame(int row,int col,int iCurent) {
	Pokemon();
	string lv;
	if (iCurent == 0) lv = "4x4";
	else if (iCurent == 1) lv = "6x6";
	else lv = "8x8";
	string user;
	user =inputUser();
	system("cls");
	pokemon** matrix;
	matrix = new pokemon * [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new pokemon[col];
	}
	board* board = createBoard(matrix, row, col);
	showBoard(board, row, col);
	clock_t start, end;
	string time_use;
	start = clock();
	playGame(board, row, col);
	end = clock();
	time_use = (int)end-start;
	time_use=to_string((int)end-start);
	system("cls");
	sortLeaderBoard(user, time_use, iCurent);
	PrintEndgame(user, time_use,lv);

	showLeaderBoard();
	for (int i = 0; i < 4; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
