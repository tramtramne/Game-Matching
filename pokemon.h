#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include<string>
#include<stdio.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#define _COL 4
#define _ROW 4
#define BLACK 0
#define AQUA 3
#define RED 4
#define WHITE 7
#define GRAY 8
#define GREEN 2
using namespace std;
struct pokemon
{
	int x;
	int y;
	char name = 0;
	char subMatrix[5][9];
};
void gotoXY(int& x, int& y);
void setColor(int backgound_color, int text_color);
void paintMove(pokemon** matrix, int x, int y);
void paintSelect(pokemon** matrix, int x, int y);
void paintUnMove(pokemon** matrix, int x, int y);
void paintCorect(pokemon** matrix, int x, int y);
void paintUnCorect(pokemon** matrix, int x, int y);
void paintSuggestion(pokemon** matrix, int x, int y);
void deletePokemon(pokemon**& matrix, pokemon& p1, pokemon& p2);
void printBackground(string nameOfFile, int row);
