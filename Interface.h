#pragma once
#include "game.h"

struct mode {
	int x, y;
	string name;
	string frame[3][3] = {
	{" ","                   "," "},
	{" ",name," "},
	{" ","                   "," "}
	};
};
struct boardMenu {
	mode* cell;
	int yAbove, yBelow;
};

void paintSelectMenu(mode* menu);
void paintSelectMode(mode* menu);
void Pokemon();
void printCell(mode menu, int x, int y);
boardMenu* createBoardMenu(mode*& mainMenu, string listMenu[], int n);
void printBoardMenu(mode* menu, int n);
void MenuLevel();
void mainMenu();
