#include "board.h"

board* createBoard(pokemon**& matrix, int row, int col) {
    int c, d, count = 0, temp;
    char i;
    while (true)
    {
        temp = rand() % 26;
        i = 'A' + temp;
        while (true)
        {
            c = rand() % col;
            d = rand() % row;
            if (matrix[d][c].name == 0)
            {
                matrix[d][c].name = i;
                count++;
                break;
            }
        }
        while (true)
        {
            c = rand() % col;
            d = rand() % row;
            if (matrix[d][c].name == 0)
            {
                matrix[d][c].name = i;
                count++;
                break;
            }
        }
        if (count == col * row) {
            break;
        }
    }
    int x = 35, y = 10;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j].x = x + j * 9;
            matrix[i][j].y = y + i * 5;
            for (int h = 0; h < 5; h++)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (h == 2 && k == 4)
                    {
                        matrix[i][j].subMatrix[h][k] = matrix[i][j].name;
                    }
                    if (h == 0 || h == 4)
                    {
                        if (k == 0 || k == 8)
                        {
                            matrix[i][j].subMatrix[h][k] = ' ';
                            continue;
                        }
                        matrix[i][j].subMatrix[h][k] = '-';
                        continue;
                    }
                    if (k == 0 || k == 8)
                    {
                        if (h == 0 || h == 4)
                        {
                            matrix[i][j].subMatrix[h][k] = ' ';
                            continue;
                        }
                        matrix[i][j].subMatrix[h][k] = '|';
                        continue;
                    }
                    matrix[i][j].subMatrix[h][k] = ' ';
                }
            }
        }
    }
    board* result = new board;
    result->column = col;
    result->row = row;
    result->matrix = matrix;
    result->x = 0;
    result->y = 0;
    result->p1 = nullptr;
    result->p2 = nullptr;
    return result;
}
void showFrameOfBoard(int row, int col)
{
    int x = 34, y = 9;
    gotoXY(x, y);
    for (int i = 0; i < row * 5 + 2; i++)
    {
        for (int j = 0; j < col * 9 + 2; j++)
        {
            if (i == 0 || i == row * 5 + 1)
            {
                if (j == 0 || j == col * 9 + 2) cout << " ";
                else cout << "-";
            }
            else if (j == 0 || j == col * 9 + 1)
            {

                cout << "|";
            }
            else cout << " ";
        }
        gotoXY(x, ++y);
    }
}
void showBoard(board*& board, int row, int col) {

    if (!(isContinue(board, board->matrix, col, row)))
    {
        if (!(checkEndgame(board, row, col)))
            randomAgain(board, board->matrix, col, row);
    }
    showFrameOfBoard(row, col);
    string nameOfFile;
    if (row == 4) nameOfFile = "4x4.txt";
    else if (row == 6) nameOfFile = "6x6.txt";
    else if (row == 8) nameOfFile = "background8x8.txt";
    printBackground(nameOfFile, row);
    int X, Y;
    //pokemon** matrix = board->matrix;
    for (int i = 0; i < board->row; i++) {
        for (int j = 0; j < board->column; j++) {
            X = board->matrix[i][j].x;
            Y = board->matrix[i][j].y;
            gotoXY(X, Y);
            if (board->matrix[i][j].name != ' ') {
                for (int h = 0; h < 5; h++) {
                    for (int k = 0; k < 9; k++) {
                        if (h == 2 && k == 4) {
                            cout << board->matrix[i][j].name;
                            continue;
                        }
                        cout << board->matrix[i][j].subMatrix[h][k];

                    }
                    Y++;
                    gotoXY(X, Y);
                }
            }
        }
    }
}

void playGame(board*& board, int row, int col) {
    char move;
    pokemon p1 = {}, p2 = {}, temp = {};
    paintMove(board->matrix, board->x, board->y);
    int count = 0;
    bool check = false;
    while (true) {
        move = _getch();
        if (move == 's' && board->y < board->row - 1) {
            paintUnMove(board->matrix, board->x, board->y);
            if (check == true) {
                paintSelect(board->matrix, temp.x, temp.y);
            }
            board->y++;
            paintMove(board->matrix, board->x, board->y);
        }
        else if (move == 'd' && board->x < board->column - 1) {
            paintUnMove(board->matrix, board->x, board->y);
            if (check == true) {
                paintSelect(board->matrix, temp.x, temp.y);
            }
            board->x++;
            paintMove(board->matrix, board->x, board->y);
        }
        else if (move == 'a' && board->x > 0) {
            paintUnMove(board->matrix, board->x, board->y);
            if (check == true) {
                paintSelect(board->matrix, temp.x, temp.y);
            }
            board->x--;
            paintMove(board->matrix, board->x, board->y);
        }
        else if (move == 'w' && board->y > 0) {
            paintUnMove(board->matrix, board->x, board->y);
            if (check == true) {
                paintSelect(board->matrix, temp.x, temp.y);
            }
            board->y--;
            paintMove(board->matrix, board->x, board->y);
        }
        else if (move == 'h') {
            moveSuggest(board, row, col);
            paintMove(board->matrix, board->x, board->y);
        }
        else if (move == ' ') {
            count++;

            if (count == 1) {
                p1.x = board->x;
                p1.y = board->y;
                temp.x = board->x;
                temp.y = board->y;
                check = true;
                paintSelect(board->matrix, p1.x, p1.y);
            }
            else if (count == 2) {
                p2.x = board->x;
                p2.y = board->y;
                paintSelect(board->matrix, p2.x, p2.y);
                if (checkSame(board, p1, p2)) {
                    if (check_general(board, p1, p2)) {
                        if (checkTotal(board, p1, p2, col, row)) {
                            //Beep(440, 300);
                            paintCorect(board->matrix, p1.x, p1.y);
                            paintCorect(board->matrix, p2.x, p2.y);
                            Sleep(300);
                            deletePokemon(board->matrix, p1, p2);
                            system("cls");
                            showBoard(board, row, col);
                            paintMove(board->matrix, p2.x, p2.y);
                        }
                        else {
                            paintUnCorect(board->matrix, p1.x, p1.y);
                            paintUnCorect(board->matrix, p2.x, p2.y);
                            Sleep(300);
                        }
                    }
                    else {
                        paintUnCorect(board->matrix, p1.x, p1.y);
                        paintUnCorect(board->matrix, p2.x, p2.y);
                        Sleep(300);
                    }
                    paintMove(board->matrix, p2.x, p2.y);
                    paintUnMove(board->matrix, temp.x, temp.y);
                }
                else {
                    paintMove(board->matrix, p2.x, p2.y);
                }

                count = 0;
                check = false;
                temp = {};
            }
        }
        else {
            continue;
        }
        if (checkEndgame(board, row, col)) {
            break;
        }
    }
}
//check total
bool checkTotal(board* board, pokemon p1, pokemon p2, int col, int row)
{
    int col1 = p1.x;
    int col2 = p2.x;
    int row1 = p1.y;
    int row2 = p2.y;
    return (check_I_Matching(board, p1, p2, row1, row2, col1, col2) ||
        check_L_Matching(board, p1, p2) ||
        check_Z_Matching(board, p1, p2) ||
        check_U_Matching(board, p1, p2, row, col));
}
//Check I matching
bool check_I_Matching_Row(board* board, pokemon p1, pokemon p2, int row1, int row2, int col1, int col2) {

    pokemon** matrix = board->matrix;
    if (row1 != row2) return 0;
    int maxcol = max(col1, col2);
    int mincol = min(col1, col2);
    for (int i = mincol + 1; i <= maxcol - 1; i++)
    {
        if (matrix[row1][i].name != NULL)
        {
            return false;
        }
    }
    return true;
}
bool check_I_Matching_Col(board* board, pokemon p1, pokemon p2, int row1, int row2, int col1, int col2) {
    if (col1 != col2) return 0;
    pokemon** matrix = board->matrix;
    int maxrow = max(row1, row2);
    int minrow = min(row1, row2);
    for (int i = minrow + 1; i <= maxrow - 1; i++)
    {
        if (matrix[i][col1].name != NULL)
        {
            return false;
        }
    }
    return true;
}
bool check_I_Matching(board* board, pokemon p1, pokemon p2, int row1, int row2, int col1, int col2) {

    pokemon** matrix = board->matrix;
    if (row1 == row2)
    {
        if (abs(col1 - col2) == 1)
            return 1;
        else
            return check_I_Matching_Row(board, p1, p2, row1, row2, col1, col2);
    }
    if (col1 == col2)
    {
        if (abs(row1 - row2) == 1)
            return 1;
        else return check_I_Matching_Col(board, p1, p2, row1, row2, col1, col2);
    }
    return 0;
}
//Check L matching
bool check_L_Matching(board* board, pokemon p1, pokemon p2) {
    int col1 = p1.x;
    int col2 = p2.x;
    int row1 = p1.y;
    int row2 = p2.y;
    pokemon** matrix = board->matrix;
    if (matrix[row2][col1].name == NULL)
    {
        return check_I_Matching(board, p1, p2, row2, row2, col1, col2) &&
            check_I_Matching(board, p1, p2, row1, row2, col1, col1);
    }
    if (matrix[row1][col2].name == NULL)
        return check_I_Matching(board, p1, p2, row1, row1, col1, col2) &&
        check_I_Matching(board, p1, p2, row1, row2, col2, col2);
    return 0;
}
//Check Z matching
bool check_Z_Matching(board* board, pokemon p1, pokemon p2) {
    int col1 = p1.x;
    int col2 = p2.x;
    int row1 = p1.y;
    int row2 = p2.y;
    pokemon** matrix = board->matrix;

    int max_dong = max(row1, row2);
    int min_dong = min(row1, row2);
    int max_cot = max(col1, col2);
    int min_cot = min(col1, col2);
    for (int i = min_dong + 1; i < max_dong; i++)
    {
        if (check_I_Matching(board, p1, p2, i, i, col1, col2) &&
            matrix[i][col1].name == NULL &&
            matrix[i][col2].name == NULL &&
            check_I_Matching(board, p1, p2, row1, i, col1, col1) &&
            check_I_Matching(board, p1, p2, i, row2, col2, col2))
            return 1;
    }
    for (int i = min_cot + 1; i < max_cot; i++)
    {
        if (check_I_Matching(board, p1, p2, row1, row2, i, i) &&
            matrix[row1][i].name == NULL &&
            matrix[row2][i].name == NULL &&
            check_I_Matching(board, p1, p2, row1, row2, col1, i) &&
            check_I_Matching(board, p1, p2, row2, row2, i, col2))
            return 1;
    }
    return 0;
}
//Check U matching
bool check_U_Matching(board* board, pokemon p1, pokemon p2, int col, int row) {
    int col1 = p1.x;
    int col2 = p2.x;
    int row1 = p1.y;
    int row2 = p2.y;
    for (int i = 0; i < row; i++)
    {
        if (i == row1 || i == row2) {
            continue;
        }
        if (check_I_Matching(board, p1, p2, i, i, col1, col2))
        {
            if (board->matrix[i][col1].name == NULL &&
                board->matrix[i][col2].name == NULL &&
                check_I_Matching(board, p1, p2, row1, i, col1, col1) &&
                check_I_Matching(board, p1, p2, i, row2, col2, col2))
                return 1;
        }
    }
    for (int i = 0; i < col; i++)
    {
        if (i == col1 || i == col2) continue;
        if (check_I_Matching(board, p1, p2, row1, row2, i, i))
        {
            if (board->matrix[row1][i].name == NULL &&
                board->matrix[row2][i].name == NULL &&
                check_I_Matching(board, p1, p2, row1, row1, col1, i) &&
                check_I_Matching(board, p1, p2, row2, row2, i, col2))
                return 1;
        }
    }
    // ngang
    if ((check_I_Matching(board, p1, p2, 0, row1, col1, col1) && board->matrix[0][col1].name == NULL) || row1 == 0)
    {
        if (row2 == 0 || (check_I_Matching(board, p1, p2, 0, row2, col2, col2) && board->matrix[0][col2].name == NULL))
            return 1;
    }
    if ((check_I_Matching(board, p1, p2, row - 1, row1, col1, col1) && board->matrix[row - 1][col1].name == NULL) || row1 == row - 1)
    {
        if (row2 == row - 1 || (check_I_Matching(board, p1, p2, row - 1, row2, col2, col2) && board->matrix[row - 1][col2].name == NULL))
            return 1;
    }

    // doc
    if ((check_I_Matching(board, p1, p2, row1, row1, col1, 0) && board->matrix[row1][0].name == NULL) || col1 == 0)
    {
        if (col2 == 0 || (check_I_Matching(board, p1, p2, row2, row2, col2, 0) && board->matrix[row2][0].name == NULL))
            return 1;
    }
    if ((check_I_Matching(board, p1, p2, row1, row1, col1, col - 1) && board->matrix[row1][col - 1].name == NULL) || col1 == col - 1)
    {
        if (col2 == col - 1 || (check_I_Matching(board, p1, p2, row2, row2, col - 1, col2) && board->matrix[row2][col - 1].name == NULL))
            return 1;
    }
    return 0;
}
bool checkEndgame(board* board, int row, int col)
{
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board->matrix[i][j].name == NULL) count++;
        }
    }
    if (count == row * col) return true;
    return false;
}
bool check_general(board* board, pokemon p1, pokemon p2) {
    int cot1 = p1.x;
    int cot2 = p2.x;
    int dong1 = p1.y;
    int row2 = p2.y;
    if (p1.x == p2.x && p2.y == p1.y) return 0;
    if (board->matrix[dong1][cot1].name != board->matrix[row2][cot2].name) {
        return false;
    }
    return true;
}
bool checkSame(board* board, pokemon p1, pokemon p2) {
    if (p1.x == p2.x && p1.y == p2.y) {
        return false;
    }
    return true;
}
bool isContinue(board* board, pokemon** matrix, int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board->matrix[i][j].name != NULL)
            {
                for (int h = 0; h < row; h++)
                {
                    for (int k = 0; k < col; k++)
                    {
                        if (h != i || k != j)
                        {
                            if (board->matrix[i][j].name == board->matrix[h][k].name)
                            {
                                pokemon p1, p2;
                                p1.x = j;
                                p1.y = i;
                                p2.x = k;
                                p2.y = h;
                                if (checkTotal(board, p1, p2, col, row))
                                    return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
void randomAgain(board* board, pokemon** matrix, int col, int row)
{
    char** name = new char* [col * row];
    int index = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j].name != NULL)
            {
                name[index] = &matrix[i][j].name;
                index++;
            }
        }
    }
    while (1)
    {
        int a = rand() % index;
        int b;
        while (1)
        {
            b = rand() % index;
            if (a != b) break;
        }
        swap(*name[a], *name[b]);
        if (isContinue(board, matrix, col, row)) {
            break;
        }
    }
    delete[] name;
}
void moveSuggest(board* board, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board->matrix[i][j].name != NULL) {
                for (int h = 0; h < row; h++) {
                    for (int k = 0; k < col; k++) {
                        if (i == h && j == k) {
                            continue;
                        }
                        else {
                            pokemon p1, p2;
                            p1.x = j;
                            p1.y = i;
                            p2.x = k;
                            p2.y = h;
                            if (check_general(board, p1, p2)) {
                                if (checkTotal(board, p1, p2, col, row)) {
                                    paintSuggestion(board->matrix, p1.x, p1.y);
                                    paintSuggestion(board->matrix, p2.x, p2.y);
                                    Sleep(1000);
                                    paintUnMove(board->matrix, p1.x, p1.y);
                                    paintUnMove(board->matrix, p2.x, p2.y);
                                    return;
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}

void PrintEndgame(string& user,string& time_use, string& lv)
{
    int x = 65, y = 10;
    setColor(BLACK, RED);
    gotoXY(x, y);
    cout << "                _                            ";
    gotoXY(x, ++y);
    cout << "               | |                           ";
    gotoXY(x, ++y);
    cout << "  ___ _ __   __| | __ _  __ _ _ __ ___   ___ ";
    gotoXY(x, ++y);
    cout << " / _ \\ '_ \\ / _` |/ _` |/ _` | '_ ` _ \\ / _ \\";
    gotoXY(x, ++y);
    cout << " | __/ | | | (_| | (_| | (_| | | | | | |  __/";
    gotoXY(x, ++y);
    cout << "                   __/ |                     ";
    gotoXY(x, ++y);
    cout << "                  |___/                      ";
    y += 2;
    setColor(BLACK, WHITE);
    gotoXY(x, y);
    cout << "USERNAME:";
    x += 25;
    gotoXY(x, y);
    cout << user;
    x -= 25;
    gotoXY(x, ++y);
    cout << "TIME:";
    x += 25;
    gotoXY(x, y);
    cout << stoi(time_use) / 1000;
    x -= 25;
    gotoXY(x, ++y);
    cout << "LEVEL:";
    x += 25;
    gotoXY(x, y);
    cout << lv;
}