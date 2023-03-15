#include"leaderBoard.h"
#include"Interface.h"

void sort(dataUser*& arr,string user, string time_use) {
	int x = stoi(time_use)/1000;
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 5; j++) {
			if (stoi(arr[i].time) > stoi(arr[j].time)) {
				dataUser  temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (x < stoi(arr[i].time)) {
			arr[i].time = to_string(x);
			arr[i].user = user;
			break;
		}
	}
}
void printLeaderBoard() {
	int x, y;
	y = 1;
	x = 1;
	gotoXY(x, y);
	ifstream fin;
	fin.open("leaderBoardText.txt", ios::in);
	string s;
	if (!fin) {
		cout << "khong mo duoc file ";
	}
	else {
		while (!fin.eof()) {
			getline(fin, s);
			gotoXY(x, y);
			cout << s;
			y++;
		}
		fin.close();
	}
}
string inputUser() {
	string user;
	string frame[3] = {
		"----------------------------------------------",
		"|                                            |",
		"----------------------------------------------"
	};
	int x = 30, y = 15;
	
	for (int i = 0; i < 3; i++)
	{
		gotoXY(x, y);
		cout << frame[i] << endl;
		y++;
	}
	do {
		x = 32, y = 16;
		gotoXY(x, y);
		cout << "USERNAME: ";
		getline(cin, user);
		if (user.size() > 20)
		{
			y += 2;
			gotoXY(x, y);
			cout << "Username is less than 20 characters.\n";
		}
	} while (user.size() > 20);
	return user;
}


dataUser* getdata(int iCurrent) {
	ifstream fin;
	dataUser *s;
	int index=0;
	s = new dataUser[5];
	if (iCurrent == 0) {
		fin.open("LBeazy.txt", ios::in);
	}
	else if (iCurrent == 1) {
		fin.open("LBnomal.txt", ios::in);
	}
	else {
		fin.open("LBhard.txt", ios::in);
	}
	if (!fin) {
		cout << "khong mo duoc file!" << endl;
	}
	else {
		while (!fin.eof()) {
			getline(fin, s[index].user);
			getline(fin, s[index].time);
			index++;
		}
	}
	fin.close();
	return s;
}
void printdata() {
	dataUser* temp = getdata(2);
	cout << temp[0].user<<" "<<temp[0].time;
	cout << temp[1].user << " " << temp[1].time;
	cout << temp[2].user << " " << temp[2].time;
}
void sortLeaderBoard(string user, string time_use, int iCurrent) {
	dataUser* arr = getdata(iCurrent);
	ofstream fout;
	int index = 0;
	if (iCurrent == 0) {
		fout.open("LBeazy.txt", ios::out);
	}
	else if (iCurrent == 1) {
		fout.open("LBnomal.txt", ios::out);
	}
	else {
		fout.open("LBhard.txt", ios::out);
	}
	sort(arr,user,time_use);
	for (int i = 0; i < 4; i++) {
		fout << arr[i].user << endl;
		fout << arr[i].time<<endl;
	}
	fout << arr[4].user << endl;
	fout << arr[4].time;
	delete[] arr;
	fout.close();
}
void printframes(int x, int y) {
	gotoXY(x, y);
	cout << " ------------------------------------"<<endl;
	y++;
	gotoXY(x, y);
	cout << "|                                    |"<<endl;
	y++;
	gotoXY(x, y);
	cout << "|                                    |"<<endl;
	y++;
	gotoXY(x, y);
	cout << "|                                    |"<<endl;
	y++;
	gotoXY(x, y);
	cout << "|                                    |"<< endl;
	y++;
	gotoXY(x, y);
	cout << "|                                    |"<<endl;
	y++;
	gotoXY(x, y);
	cout << " ------------------------------------";
}
void showLeaderBoard() {
	int x, y;
	
	setColor(BLACK, 2);
	printLeaderBoard();
	setColor(BLACK, WHITE);
	dataUser* arr = getdata(0);
	x = 10, y = 8;
	gotoXY(x, y);
	cout << setw(15) << left << "Username" << setw(10) << right << "Time" << setw(10) << right << "Level";
	cout << endl;
	y++;
	x -= 2;
	printframes(x,y);
	x += 2;
	for (int i = 0; i < 5; ++i)
	{
		y++;
		gotoXY(x, y);
		cout << setw(15) << left << arr[i].user << setw(10) << right << arr[i].time << setw(10) << right << 1 << endl;
	}
	delete[] arr;
	y++;
	arr = getdata(1);
	x -= 2;
	printframes(x, y);
	x += 2;
	for (int i = 0; i < 5; ++i)
	{
		y++;
		gotoXY(x, y);
		cout << setw(15) << left << arr[i].user << setw(10) << right << arr[i].time << setw(10) << right << 2 << endl;
	}
	delete[] arr;
	y++;
	arr = getdata(2);
	x -= 2;
	printframes(x, y);
	x += 2;
	for (int i = 0; i < 5; ++i)
	{
		y++;
		gotoXY(x, y);
		cout << setw(15) << left << arr[i].user << setw(10) << right << arr[i].time << setw(10) << right << 3 << endl;
	}
	delete[] arr;
	returnPress(10, 32);
}
void returnPress(int x, int y)
{
	string frame[3]= { "                               ",
		"             RETURN            ",
		"                               "
	};
	gotoXY(x, y);
	for (int j = 0; j < 3; j++)
	{
		if (j == 1)
		{
			for (int k = 0; k < frame[1].size(); k++)
			{
				if (frame[1][k] != ' ')
				{
					setColor(8, BLACK);
					cout << frame[1][k];
					setColor(BLACK, WHITE);
				}
				else
				{
					setColor(8, 3);
					cout << frame[1][k];
					setColor(BLACK, WHITE);
				}
			}
		}
		else {
			setColor(8, 6);
			cout << frame[j];
			setColor(BLACK, WHITE);
		}
		gotoXY(x, ++y);
	}
	x += 15; y -= 2;
	gotoXY(x, y);
}