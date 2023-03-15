#pragma once
#include"board.h"
struct dataUser {
	string user;
	string time;
};
string inputUser();
void sort(dataUser*& arr, string user, string time_use);
void printLeaderBoard();
dataUser* getdata(int iCurrent);
void sortLeaderBoard(string user, string time_use, int iCurrent);
void printdata();
void showLeaderBoard();
//void printframes();
void returnPress(int x, int y);