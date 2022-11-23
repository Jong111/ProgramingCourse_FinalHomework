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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

int main() {
	string str = "请输入内容第一部分";
	cout << str;
	//cout << str.length() << endl;
	int res[2] = { 0 };
	appGetXY(res);
	cout << endl;
	cout << *res << ' ' << *(res + 1) << endl;
	gotoxy(10, 10);
	/*cout << "请输入内容第一部分:" << endl;
	cout << "请输入内容第二部分";
	gotoxy(20, 0);
	string str1, str2;
	cin >> str1;
	gotoxy(20, 1);
	cin >> str2;
	gotoxy(30, 80);
	cout << "输入完毕";*/
	return 0;
}

