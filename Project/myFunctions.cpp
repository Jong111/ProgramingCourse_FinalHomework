#include <stdlib.h>
#include <windows.h>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include"myFunctions.h"
using namespace std;

int adLoginTimes = 0;


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


int digit(int a) {
	int res = 0;
	while (a) {
		res++;
		a /= 10;
	}
	return res;
}


int string2ascii(string& str) {
	int res = 0;
	for (int i = 0; i < str.length(); i++) {
		int k = digit(int(str[i]));
		res = pow(10, k) * res + int(str[i]);
	}
	return res;
}


// print a line of "="
void printDisplay() {
	int res[2] = { 0 };
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 120; i++) {
		cout << "=";
	}
}


// print a line of "*"
void printDisplay2() {
	int res[2] = { 0 };
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 120; i++) {
		cout << "*";
	}
}

int home() {
	printDisplay();
	cout << endl;
	string str = "1. 管理员登录     2.用户注册     3.用户登录     4.退出程序";
	for (int i = 0; i < 20; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	cout << "请输入操作：";
	string operation;
	cin >> operation;
	int res = string2ascii(operation);
	return res;
}


void administratorLogin() {
	if (adLoginTimes == 0) {
		adLoginTimes++;
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "请输入管理员姓名：";
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "请输入管理员密码：";
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		if (ans1 == "admin" && ans2 == "123456") {
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "-----登录成功-----";
		}
		else {
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "-----登录失败-----" << endl;
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "请重新登录";
			administratorLogin();
		}
	}
	else {
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "请再次输入管理员姓名：";
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "请再次输入管理员密码：";
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		if (ans1 == "admin" && ans2 == "123456") {
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "-----登录成功-----";
		}
		else {
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "-----登录失败-----" << endl;
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "请重新登录";
			administratorLogin();
		}
	}
}


void administrator() {
	printDisplay();
	cout << endl;
	string str = "1. 查看所有商品     2.搜索商品     3.下架商品     4.查看所有订单     5.查看所有用户     6.封禁用户     7.注销";
	for (int i = 0; i < 12; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	cout << "请输入操作：";
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		showAllCommodities();
		int res2[2] = { 0 };
		cout << endl << endl;
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "按y返回管理员操作界面：";
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string ans;
		while (1) {
			string tmpAns;
			cin >> tmpAns;
			if (tmpAns == "y") {
				ans = tmpAns;
				break;
			}
			else {
				cout << endl;
				for (int i = 0; i < 10; i++) {
					cout << "   ";
				}
				cout << "输入不合法，请重新输入：";
				int res3[2] = { 0 };
				appGetXY(res3);
				gotoxy(res3[0], res3[1]);
			}
		}
		if (ans == "y") {
			Sleep(500);
			system("cls");
			administrator();
		}
		break;
	}
	case 50: {
		//TODO
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "请输入商品名称：";
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string cmdName;
		cin >> cmdName;
		vector<cmd> cmds, res;
		readDatas(cmds);
		searchSimple(cmdName, cmds, res);
		printCommodities(res);
		break;
	}
	case 51: {
		//TODO
		break;
	}
	case 52: {
		//TODO
		break;
	}
	case 53: {
		//TODO
		break;
	}
	case 54: {
		//TODO
		break;
	}
	case 55: {
		//TODO
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(1000);
		system("cls");
		administrator();
	}
	}
}


// Read datas from commodity.txt to cmds, 这里要解决一下输入中途文件就结束了的问题
void readDatas(vector<cmd>&cmds) {
	ifstream f;
	f.open("d:\\commodity.txt", ios::in);
	if (!f) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	while (!f.eof()) {
		cmd temp;
		f >> temp.cmdID;
		f >> temp.cmdName;
		f >> temp.cmdPrice;
		f >> temp.cmdDay;
		f >> temp.sellerID;
		f >> temp.cmdNum;
		f >> temp.cmdState;
		cmds.push_back(temp);
	}
}


void printCommodities(vector<cmd>& cmds) {
	printDisplay2();
	string str = "商品ID     名称           价格      上架时间     卖家ID     数量     商品状态";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < cmds.size(); i++) {
		cout << "                                             ";
		cout << cmds[i].cmdID << "     " << cmds[i].cmdName << "     " << cmds[i].cmdPrice << "     " << cmds[i].cmdDay << "     " << cmds[i].sellerID << "       " << cmds[i].cmdNum << "       " << cmds[i].cmdState << endl;
	}
	printDisplay2();
}


void showAllCommodities() {
	//cout << "Not implemented";
	vector<cmd> cmds;
	readDatas(cmds);
	printCommodities(cmds);
}


// Check if str2 is a substring of str1
int strIn(string& str1, string& str2) {
	int res = 1;
	if (str1.find(str2) == string::npos) res = 0;
	return res;
}


void searchSimple(string& str, vector<cmd>cmds, vector<cmd>&res) {
	for (int i = 0; i < cmds.size(); i++) {
		if (strIn(cmds[i].cmdName, str)!=0) {
			res.push_back(cmds[i]);
		}
	}
}


//int main() {
//	int n = home();
//	cout << n;
//	return 0;
//}



