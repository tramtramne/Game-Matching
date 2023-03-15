#pragma once
#include "pokemon.h"

using namespace std;
struct board
{
	int row;
	int column;
	pokemon** matrix;
	pokemon* p1;
	pokemon* p2;
	int x, y;
};

board* createBoard(pokemon**& matrix, int row, int col);
void showBoard(board*& board, int row, int col);
bool checkTotal(board* board, pokemon p1, pokemon p2, int col, int row);
void playGame(board*& board, int row, int col);
bool checkTotal(board* board, pokemon p1, pokemon p2, int row, int  col);
//Check I matching
bool check_I_Matching_Row(board* board, pokemon p1, pokemon p2, int row1, int row2, int col1, int col2);
bool check_I_Matching_Col(board* board, pokemon p1, pokemon p2, int row1, int row2, int col1, int col2);
bool check_I_Matching(board* board, pokemon p1, pokemon p2, int row1, int row2, int col1, int col2);
//Check L matching
bool check_L_Matching(board* board, pokemon p1, pokemon p2);
//Check Z matching
bool check_Z_Matching(board* board, pokemon p1, pokemon p2);
//Check U matching
bool check_U_Matching(board* board, pokemon p1, pokemon p2, int col, int row);
bool check_general(board* board, pokemon p1, pokemon p2);

bool checkEndgame(board* board, int row, int col);
bool checkSame(board* board, pokemon p1, pokemon p2);
bool isContinue(board* board, pokemon** matrix, int col, int row);
void randomAgain(board* board, pokemon** matrix, int col, int row);
void moveSuggest(board* board, int row, int col);
void PrintEndgame(string& user, string& time_use, string& lv);