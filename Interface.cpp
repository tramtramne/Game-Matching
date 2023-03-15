#include"Interface.h"


void paintSelectMenu(mode* menu) {

	int X = menu->x;
	int Y = menu->y;

	for (int i = 0; i < 3; i++)
	{
		gotoXY(X, Y);
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
			{
				for (int k = 0; k < menu->frame[1][1].size(); k++)
				{
					if (menu->frame[1][1][k] != ' ')
					{
						setColor(8, 6);
						cout << menu->frame[1][1][k];
						setColor(BLACK, WHITE);
					}
					else
					{
						setColor(8, 3);
						cout << menu->frame[i][j][k];
						setColor(BLACK, WHITE);
					}
				}
			}
			else {
				setColor(8, 6);
				cout << menu->frame[i][j];
				setColor(BLACK, WHITE);
			}
		}
		gotoXY(X, ++Y);
	}
	setColor(BLACK, WHITE);
}

void paintSelectMode(mode* menu) {
	int X = menu->x;
	int Y = menu->y;

	for (int i = 0; i < 3; i++)
	{
		gotoXY(X, Y);
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
			{
				for (int k = 0; k < menu->frame[1][1].size(); k++)
				{
					if (menu->frame[1][1][k] != ' ')
					{
						setColor(2, BLACK);
						cout << menu->frame[1][1][k];
						setColor(BLACK, WHITE);
					}
					else
					{
						setColor(2, 3);
						cout << menu->frame[i][j][k];
						setColor(BLACK, WHITE);
					}
				}
			}
			else {
				setColor(2, 3);
				cout << menu->frame[i][j];
				setColor(BLACK, WHITE);
			}
		}
		gotoXY(X, ++Y);
	}
	setColor(BLACK, WHITE);
}
void Pokemon()
{
	char choose;
	cout << "\n";
	setColor(BLACK, RED);
	cout << "\t\t                                  ,'\\" << endl;
	cout << "\t\t    _.----.        ____         ,'  _\\   ___    ___     ____" << endl;
	cout << "\t\t_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
	setColor(BLACK, 6);
	cout << "\t\t\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
	cout << "\t\t \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
	cout << "\t\t   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
	cout << "\t\t    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl;
	setColor(BLACK, GREEN);
	cout << "\t\t     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;

	cout << "\t\t      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
	setColor(BLACK, AQUA);
	cout << "\t\t       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
	cout << "\t\t        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;
	cout << "\t\t                                `'                            '-._|" << endl;
	setColor(BLACK, WHITE);
}

void printCell(mode menu, int x, int y)
{
	gotoXY(x, y);
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
			{
				for (int k = 0; k < menu.frame[1][1].size(); k++)
				{
					if (menu.frame[1][1][k] != ' ')
					{
						setColor(6, BLACK);
						cout << menu.frame[1][1][k];
						setColor(BLACK, WHITE);
					}
					else
					{
						setColor(6, 3);
						cout << menu.frame[i][j][k];
						setColor(BLACK, WHITE);
					}
				}
			}
			else {
				setColor(6, 6);
				cout << menu.frame[i][j];
				setColor(BLACK, WHITE);
			}
		}
		gotoXY(x, ++y);
	}
}
boardMenu* createBoardMenu(mode*& mainMenu, string listMenu[], int n)
{
	int x = 42, y = 14;
	for (int i = 0; i < n; i++)
	{
		mainMenu[i].frame[1][1] = mainMenu[i].name = listMenu[i];
	}
	for (int i = 0; i < n; i++)
	{
		mainMenu[i].x = x;
		mainMenu[i].y = y;
		y += 4;
	}
	boardMenu* result = new boardMenu;
	result->cell = mainMenu;
	result->yAbove = mainMenu[0].y;
	result->yBelow = mainMenu[n - 1].y;
	return result;
}
void printBoardMenu(mode* menu, int n)
{
	for (int i = 0; i < n; i++)
	{
		gotoXY(menu[i].x, menu[i].y);
		printCell(menu[i], menu[i].x, menu[i].y);
	}
}
void MenuLevel()
{
	Pokemon();
	string listMenuLevel[4] = { "       4 x 4       ",
							"       6 x 6       " ,
							"       8 x 8       " ,
                            "       Return      "};
	mode* menu = new mode[4];
	boardMenu* menuLevel = createBoardMenu(menu, listMenuLevel, 4);
	printBoardMenu(menuLevel->cell, 4);
	char chooseLevel;
	int iCurrent = 0;
	paintSelectMenu(menuLevel->cell);
	while (1) {
		chooseLevel = _getch();
		if (chooseLevel == 's' && menuLevel->cell[iCurrent].y < menuLevel->yBelow)
		{
			printCell(menuLevel->cell[iCurrent], menuLevel->cell[iCurrent].x, menuLevel->cell[iCurrent].y);
			++iCurrent;
			gotoXY(menuLevel->cell[iCurrent].x, menuLevel->cell[iCurrent].y);
			paintSelectMenu(menuLevel->cell + iCurrent);
		}
		else if (chooseLevel == 'w' && menuLevel->cell[iCurrent].y > menuLevel->yAbove)
		{
			printCell(menuLevel->cell[iCurrent], menuLevel->cell[iCurrent].x, menuLevel->cell[iCurrent].y);
			--iCurrent;
			gotoXY(menuLevel->cell[iCurrent].x, menuLevel->cell[iCurrent].y);
			paintSelectMenu(menuLevel->cell + iCurrent);
		}
		else if (chooseLevel == ' ')
		{
			paintSelectMode(menuLevel->cell + iCurrent);
			system("cls");
			switch (iCurrent)
			{
			case 0:
			{
				startGame(4, 4,iCurrent);
				return;
			}
			case 1:
			{
				startGame(6, 6,iCurrent);
				return;
			case 2:
			{
				startGame(8, 8,iCurrent);
				return;
			}
            case 3: 
				return mainMenu();
			}
			}
		}
		else continue;
	}
	delete[] menu;
	delete[] menuLevel;
}
void printRule()
{ 
	char c = 34;
	Pokemon();
	cout << "\n\n\t\t\t\t\t\tRULES\n\n\n";
	cout << "\t\t    The task of the Pokemon game is to find 2 similar letters to connect them\n";
	cout << "\t\tto make those 2 characters disappear from the screen. The condition for successful\n";
	cout << "\t\tconcatenation of 2 similar characters is that they need to be separated by no more\n";
	cout << "\t\tthan 3 bends and there must be no obstacles between them. Depending on the level of\n";
	cout << "\t\tthe game, the same characters can be placed right next to each other or far apart.\n\n";

	cout << "\t\t    In each level, there will be different levels.With the easy level, there\n";
	cout << "\t\twill be less characters.In the medium to difficult level, there will be more\n";
	cout << "\t\tcharacters.Therefore, it requires players to quickly observeand quickly connect two\n";
	cout << "\t\tsimilar characters with the allowed distance together to remove them from the screen.\n\n";
	cout << "\t\t\t\t  + Press" << c << "w" << c << ": to move up\n";
	cout << "\t\t\t\t  + Press" << c << "s" << c << ": to move down\n";
	cout << "\t\t\t\t  + Press" << c << "a" << c << ": to move left\n";
	cout << "\t\t\t\t  + Press" << c << "d" << c << ": to move right\n";
    cout << "\t\t\t\t  + Press" << c << "h" << c << ": to be helped\n";

}
void mainMenu()
{
	tryagain:
	Pokemon();
	string listMainMenu[4] = { "     Play game     " ,"    Leaderboard    ",
							"       Rule        ","       Quit        " };
	mode* menu = new mode[4];
	boardMenu* mainMenu = createBoardMenu(menu, listMainMenu, 4);
	printBoardMenu(mainMenu->cell, 4);
	char choice;
	int indexCurrent = 0;
	paintSelectMenu(mainMenu->cell);
	while (1)
	{
		choice = _getch();
		if (choice == 's' && mainMenu->cell[indexCurrent].y < mainMenu->yBelow)
		{
			printCell(mainMenu->cell[indexCurrent], mainMenu->cell[indexCurrent].x, mainMenu->cell[indexCurrent].y);
			++indexCurrent;
			gotoXY(mainMenu->cell[indexCurrent].x, mainMenu->cell[indexCurrent].y);
			paintSelectMenu(mainMenu->cell + indexCurrent);
		}
		else if (choice == 'w' && mainMenu->cell[indexCurrent].y > mainMenu->yAbove)
		{
			printCell(mainMenu->cell[indexCurrent], mainMenu->cell[indexCurrent].x, mainMenu->cell[indexCurrent].y);
			--indexCurrent;
			gotoXY(mainMenu->cell[indexCurrent].x, mainMenu->cell[indexCurrent].y);
			paintSelectMenu(mainMenu->cell + indexCurrent);
		}
		else if (choice == ' ')
		{
			paintSelectMode(mainMenu->cell + indexCurrent);
			if (indexCurrent != 3)
			{
				if (indexCurrent == 0)
				{
					system("cls");
					MenuLevel();
				}
				else if (indexCurrent == 1) {
					system("cls");
					showLeaderBoard();
				}
				else if (indexCurrent == 2)
				{
					system("cls");
					printRule();
					returnPress(37, 40);
				}
			again:
				char ch = _getch();
				if (ch == ' ') {
					system("cls");
					goto tryagain;
				}
				else {
					goto again;
				}
			}
			else if (indexCurrent == 3)
			{
				break;
			}
		}
		else continue;
	}
	delete[] menu;
	delete[] mainMenu;
}

