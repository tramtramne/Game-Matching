#include"pokemon.h"

void gotoXY(int& x, int& y) {
    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void paintMove(pokemon** matrix, int x, int y) {


    int X = matrix[y][x].x + 2;
    int Y = matrix[y][x].y + 1;
    gotoXY(X, Y);
    setColor(WHITE, BLACK);

    for (int i = 1; i < 4; i++) {
        for (int j = 2; j < 7; j++) {
            if (i == 2 && j == 4) {

                cout << matrix[y][x].name;
            }
            else {
                cout << matrix[y][x].subMatrix[i][j];
            }
        }
        Y = Y + 1;
        gotoXY(X, Y);
    }
    X = X +2;
    Y=Y-2 ;
    gotoXY(X, Y);
    setColor(BLACK, WHITE);

}
void paintSelect(pokemon** matrix, int x, int y) {

    int X = matrix[y][x].x + 2;
    int Y = matrix[y][x].y + 1;
    gotoXY(X, Y);
    setColor(AQUA, BLACK);

    for (int i = 1; i < 4; i++) {
        for (int j = 2; j < 7; j++) {
            if (i == 2 && j == 4) {

                cout << matrix[y][x].name;
            }
            else {
                cout << matrix[y][x].subMatrix[i][j];
            }
        }
        Y = Y + 1;
        gotoXY(X, Y);
    }
    X = X + 2;
    Y = Y - 2;
    gotoXY(X, Y);
    setColor(BLACK, WHITE);
}
void paintUnMove(pokemon** matrix, int x, int y) {

    int X = matrix[y][x].x + 2;
    int Y = matrix[y][x].y + 1;
    gotoXY(X, Y);
    setColor(BLACK, WHITE);

    for (int i = 1; i < 4; i++) {
        for (int j = 2; j < 7; j++) {
            if (i == 2 && j == 4) {

                cout << matrix[y][x].name;
            }
            else {
                cout << matrix[y][x].subMatrix[i][j];
            }
        }
        Y = Y + 1;
        gotoXY(X, Y);
    }

}
void paintCorect(pokemon** matrix, int x, int y) {
    int X = matrix[y][x].x + 2;
    int Y = matrix[y][x].y + 1;
    gotoXY(X, Y);
    setColor(GREEN, BLACK);

    for (int i = 1; i < 4; i++) {
        for (int j = 2; j < 7; j++) {
            if (i == 2 && j == 4) {

                cout << matrix[y][x].name;
            }
            else {
                cout << matrix[y][x].subMatrix[i][j];
            }
        }
        Y = Y + 1;
        gotoXY(X, Y);
    }
    X = X + 2;
    Y = Y - 2;
    gotoXY(X, Y);
    setColor(BLACK, WHITE);

}
void paintUnCorect(pokemon** matrix, int x, int y) {
    int X = matrix[y][x].x + 2;
    int Y = matrix[y][x].y + 1;
    gotoXY(X, Y);
    setColor(RED, BLACK);

    for (int i = 1; i < 4; i++) {
        for (int j = 2; j < 7; j++) {
            if (i == 2 && j == 4) {

                cout << matrix[y][x].name;
            }
            else {
                cout << matrix[y][x].subMatrix[i][j];
            }
        }
        Y = Y + 1;
        gotoXY(X, Y);
    }
    X = X + 2;
    Y = Y - 2;
    gotoXY(X, Y);
    setColor(BLACK, WHITE);

}
void paintSuggestion(pokemon** matrix, int x, int y) {
    int X = matrix[y][x].x + 2;
    int Y = matrix[y][x].y + 1;
    gotoXY(X, Y);
    setColor(GRAY, BLACK);

    for (int i = 1; i < 4; i++) {
        for (int j = 2; j < 7; j++) {
            if (i == 2 && j == 4) {

                cout << matrix[y][x].name;
            }
            else {
                cout << matrix[y][x].subMatrix[i][j];
            }
        }
        Y = Y + 1;
        gotoXY(X, Y);
    }
    X = X + 2;
    Y = Y - 2;
    gotoXY(X, Y);
    setColor(BLACK, WHITE);

}
void deletePokemon(pokemon**& matrix, pokemon& p1, pokemon& p2) {
    matrix[p1.y][p1.x].name = NULL;
    matrix[p2.y][p2.x].name = NULL;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            matrix[p1.y][p1.x].subMatrix[i][j] = NULL;
            matrix[p2.y][p2.x].subMatrix[i][j] = NULL;
        }
    }

}
void printBackground(string nameOfFile, int row)
{
    int color[3];
    if (row == 4)
    {
        color[0] = 11; color[1] = 3, color[2] = 3;
    }
    else if (row == 6)
    {
        color[0] = 12; color[1] = 4, color[2] = 4;
    }
    else {
        color[0] = 10; color[1] = 2, color[2] = 2;
    }
    fstream f;
    int X = 35, Y = 10;
    row *= 5;
    char ch;
    f.open(nameOfFile, ios::in);
    int count = 0;
    if (f)
    {
        while (!(f.eof()))
        {
            cout << endl;
            gotoXY(X, Y);
            string s;
            getline(f, s);
            if (count <= row / 3)  setColor(BLACK, color[0]);
            else if (count <= 2 * row / 3) setColor(BLACK, color[1]);
            else if (count <= row) setColor(BLACK, color[2]);
            cout << s;
            count++;
            ++Y;
        }
        setColor(BLACK, WHITE);
    }
    f.close();
}
