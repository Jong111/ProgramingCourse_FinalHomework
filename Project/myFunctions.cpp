#include <stdlib.h>
#include <windows.h>
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

void appGetXY(int* res) {
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &pBuffer);
	res[0] = pBuffer.dwCursorPosition.X;
	res[1] = pBuffer.dwCursorPosition.Y;
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}

int main() {
	string str = "���������ݵ�һ����";
	cout << str;
	//cout << str.length() << endl;
	int res[2] = { 0 };
	appGetXY(res);
	cout << endl;
	cout << *res << ' ' << *(res + 1) << endl;
	gotoxy(10, 10);
	/*cout << "���������ݵ�һ����:" << endl;
	cout << "���������ݵڶ�����";
	gotoxy(20, 0);
	string str1, str2;
	cin >> str1;
	gotoxy(20, 1);
	cin >> str2;
	gotoxy(30, 80);
	cout << "�������";*/
	return 0;
}

