#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <windows.h>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<ctime>
#include<WinBase.h>
#include <iomanip>
#include<map>
#include<algorithm>
#include"myFunctions.h"
using namespace std;


#define AD_LOGIN 49
#define USER_SIGN_UP 50
#define USER_LOGIN 51
#define EXIT 52


int adLoginTimes = 0;
// int userLoginTimes = 0;


string END = "END";


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
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 120; i++) {
		cout << "=";
	}
}


// print a line of "*"
void printDisplay2() {
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
		string info1 = "请输入管理员姓名：";
		printInfo(info1);
		appGetXY(res1);
		string info2 = "请输入管理员密码：";
		printInfo(info2);
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		if (ans1 == "admin" && ans2 == "123456") {
			string info3 = "-----登录成功-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----登录失败-----";
			printInfo(info4);
			string info6 = "是否退出登录？[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "请重新登录";
				cout << endl;
				printInfo(info5);
				administratorLogin();
			}
			else if (ans == "y") {
				Sleep(100);
				system("cls");
				marketSystem();
			}
		}
	}
	else {
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		string info1 = "请再次输入管理员姓名：";
		printInfo(info1);
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		string info2 = "请再次输入管理员密码：";
		printInfo(info2);
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		if (ans1 == "admin" && ans2 == "123456") {
			string info3 = "-----登录成功-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----登录失败-----";
			printInfo(info4);
			string info6 = "是否退出登录？[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "请重新登录";
				cout << endl;
				printInfo(info5);
				administratorLogin();
			}
			else if (ans == "y") {
				Sleep(100);
				system("cls");
				marketSystem();
			}
		}
	}
}


string handleInvalidInput_y() {
	while (1) {
		string tmpAns;
		cin >> tmpAns;
		if (tmpAns == "y") {
			return tmpAns;
			break;
		}
		else {
			string info2 = "输入不合法，请重新输入：";
			printInfo(info2);
			int res3[2] = { 0 };
			appGetXY(res3);
			gotoxy(res3[0], res3[1]);
		}
	}
}


string handleInvalidInput_yn() {
	while (1) {
		string tmpAns;
		cin >> tmpAns;
		if (tmpAns == "y") {
			return tmpAns;
			break;
		}
		else if (tmpAns == "n") {
			return tmpAns;
			break;
		}
		else {
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "输入不合法，请重新输入：";
			int res4[2] = { 0 };
			appGetXY(res4);
			gotoxy(res4[0], res4[1]);
		}
	}
}


string handleInvalidInput_12() {
	while (1) {
		string tmpAns;
		cin >> tmpAns;
		if (tmpAns == "1") {
			return tmpAns;
			break;
		}
		else if (tmpAns == "2") {
			return tmpAns;
			break;
		}
		else {
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "输入不合法，请输入1或2来选择一个操作：";
			int res4[2] = { 0 };
			appGetXY(res4);
			gotoxy(res4[0], res4[1]);
		}
	}
}


string handleInvalidInput_123() {
	while (1) {
		string tmpAns;
		cin >> tmpAns;
		if (tmpAns == "1") {
			return tmpAns;
			break;
		}
		else if (tmpAns == "2") {
			return tmpAns;
			break;
		}
		else if (tmpAns == "3") {
			return tmpAns;
			break;
		}
		else {
			cout << endl;
			for (int i = 0; i < 10; i++) {
				cout << "   ";
			}
			cout << "输入不合法，请输入1或2或3来选择一个操作：";
			int res4[2] = { 0 };
			appGetXY(res4);
			gotoxy(res4[0], res4[1]);
		}
	}
}


void back2Ad() {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回管理员操作界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		administrator();
	}
}


void back2AdSearch() {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回管理员搜索界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		adSearch();
	}
}


void back2manageUser(string uid) {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回个人信息管理界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		manageUserInformation(uid);
	}
}


void back2AdSearchOrder() {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回订单查找界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		adSearchOrder();
	}
}


void back2message(string uid) {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回个人信息管理界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		message(uid);
	}
}


void adSearch() {
	printDisplay();
	cout << endl;
	string str = "1.按商品名称搜索     2.按商品价格区间搜索     3.按商品描述搜索     4.返回管理员操作界面";
	for (int i = 0; i < 20; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		string info = "请输入商品名称：";
		printInfo(info);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string cmdName;
		cin >> cmdName;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		searchComplex(cmdName, cmds, res);
		if (res.size() > 0) {
			printCommodities(res);
			back2AdSearch();
		}
		else {
			printSearchFailed();
			cout << endl;
			back2AdSearch();
		}
		break;
	}
	case 50: {
		string info1 = "请输入最低价格，商品价格不可以0开头（01之间的小数除外）：";
		string info2 = "请输入最高价格，商品价格不可以0开头（01之间的小数除外）：";
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		printInfo(info1);
		appGetXY(res1);
		printInfo(info2);
		appGetXY(res2);
		string price1, price2;
		gotoxy(res1[0], res1[1]);
		cin >> price1;
		gotoxy(res2[0], res2[1]);
		cin >> price2;
		// 检查输入价格是否合法
	l1:int flag1 = 1;
		int decNum1 = 0;
		if (price1.length() >= 2 && price1[0] == '0' && price1[1] != '.') flag1 = 0;
		for (int i = 0; i < price1.length(); i++) {
			if (price1[i] < '0' || price1[i] > '9') {
				if (price1[i] == '.' && decNum1 == 0 && i != price1.length() - 1) {
					decNum1++;
					continue;
				}
				else {
					flag1 = 0;
					break;
				}
			}
		}
		if (flag1 == 0) {
			string info3 = "您输入的最低价格格式有误，请重新输入：";
			printInfo(info3);
			cin >> price1;
			goto l1;
		}
	l2:int flag2 = 1;
		int decNum2 = 0;
		if (price2.length() >= 2 && price2[0] == '0' && price2[1] != '.') flag2 = 0;
		for (int i = 0; i < price2.length(); i++) {
			if (price2[i] < '0' || price2[i] > '9') {
				if (price2[i] == '.' && decNum2 == 0 && i != price2.length() - 1) {
					decNum2++;
					continue;
				}
				else {
					flag2 = 0;
					break;
				}
			}
		}
		if (flag2 == 0) {
			string info4 = "您输入的最高价格格式有误，请重新输入：";
			printInfo(info4);
			cin >> price2;
			goto l2;
		}
		// 判断最低价格是否小于等于最高价格
		if (atof(price1.c_str()) > atof(price2.c_str())) {
			string info7 = "最高价格必须大于等于最低价格，请重新输入最高价格：";
			printInfo(info7);
			cin >> price2;
			goto l2;
		}
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		for (int i = 0; i < cmds.size(); i++) {
			if (atof(cmds[i].cmdPrice.c_str()) >= atof(price1.c_str()) && atof(cmds[i].cmdPrice.c_str()) <= atof(price2.c_str())) {
				res.push_back(cmds[i]);
			}
		}
		if (res.size() > 0) {
			printCommodities(res);
			
		}
		else {
			printSearchFailed();
			cout << endl;
			back2AdSearch();
		}
		back2AdSearch();
		break;
	}
	case 51: {
		string info1 = "请输入商品描述：";
		int res1[2] = { 0 };
		printInfo(info1);
		appGetXY(res1);
		string dis;
		gotoxy(res1[0], res1[1]);
		cin >> dis;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		searchComplex2(dis, cmds, res);
		if (res.size() > 0) {
			printCommodities(res);
		}
		else {
			printSearchFailed();
			cout << endl;
			back2AdSearch();
		}
		back2AdSearch();
		break;
	}
	case 52: {
		//TODO
		Sleep(100);
		system("cls");
		administrator();
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(300);
		system("cls");
		adSearch();
	}
	}
}


void administrator() {
	printDisplay();
	cout << endl;
	string str = "1.查看所有商品     2.搜索商品     3.下架商品     4.查看所有订单     5.查看所有用户     6.封禁用户     7.注销";
	for (int i = 0; i < 12; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
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
		back2Ad();
		break;
	}
	case 50: {
		//TODO
		Sleep(100);
		system("cls");
		adSearch();
		break;
	}
	case 51: {
		//TODO
		string info1 = "请输入要下架的商品ID：";
		printInfo(info1);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string cmdId;
		cin >> cmdId;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		int idx = -1;
		idx = searchCmdID(cmdId, cmds, res);
		if (res.size() > 0) {
			string info2 = "确定要下架该商品吗？";
			printInfo(info2);
			cout << endl;
			printCommodities(res);
			string info3 = "请选择[y/n] ";
			printInfo(info3);
			int res3[2] = { 0 };
			appGetXY(res3);
			gotoxy(res3[0], res3[1]);
			string ans;
			ans = handleInvalidInput_yn();
			if (ans == "y") {
				string info4 = "商品下架成功";
				printInfo(info4);
				/*cmds.erase(cmds.begin() + idx);
				writeDatasCmd(cmds);*/
				cmds[idx].cmdState = "已下架";
				writeDatasCmd(cmds);
			}
			else if (ans == "n") {
				string info5 = "取消下架";
				printInfo(info5);
			}
			back2Ad();
		}
		else {
			printSearchFailed();
			Sleep(300);
			system("cls");
			administrator();
		}
		break;
	}
	case 52: {
		//TODO
		Sleep(100);
		system("cls");
		adSearchOrder();
		break;
	}
	case 53: {
		//TODO
		showAllUsers();
		back2Ad();
		break;
	}
	case 54: {
		//TODO
		string info1 = "请输入要封禁的用户ID：";
		printInfo(info1);
		int res1[2] = { 0 };
		appGetXY(res1);
		gotoxy(res1[0], res1[1]);
		string userId;
		cin >> userId;
		int idx = -1;
		vector<user>users, res;
		readDatasUser(users);
		idx = searchUserID(userId, users, res);
		if (idx != -1) {
			if (users[idx].userState == "封禁") {
				string info7 = "该用户已被封禁";
				printInfo(info7);
				back2Ad();
			}
			else {
				string info2 = "确定要封禁该用户吗？";
				printInfo(info2);
				cout << endl;
				vector<user> user_vec;
				user_vec.push_back(users[idx]);
				printUsers(user_vec, 1);
				string info5 = "请选择[y/n] ";
				printInfo(info5);
				int res3[2] = { 0 };
				appGetXY(res3);
				gotoxy(res3[0], res3[1]);
				string ans;
				ans = handleInvalidInput_yn();
				if (ans == "y") {
					cout << endl;
					users[idx].userState = "封禁";
					writeDatasUser(users);
					vector<cmd> cmds;
					readDatasCmd(cmds);
					vector<string> toBeTakeOff;
					for (int i = 0; i < cmds.size(); i++) {
						if (cmds[i].sellerID == userId) {
							toBeTakeOff.push_back(cmds[i].cmdID);
						}
					}
					vector<cmd>temp;
					// 该用户未发布过商品
					if (toBeTakeOff.size() == 0) {
						string info3 = "已将其封禁，但该用户暂未发布商品，因此无法下架其商品";
						printInfo(info3);
						back2Ad();
					}
					// 该用户发布过商品
					else {
						/*for (int i = 0; i < toBeTakeOff.size(); i++) {
							int tempp = searchCmdID(toBeTakeOff[i], cmds, temp);
							if (tempp != -1) {
								cmds.erase(cmds.begin() + tempp);
							}
						}
						writeDatasCmd(cmds);*/
						for (int i = 0; i < toBeTakeOff.size(); i++) {
							int tempp = searchCmdID(toBeTakeOff[i], cmds, temp);
							if (tempp != -1) {
								cmds[tempp].cmdState = "已下架";
							}
						}
						writeDatasCmd(cmds);
						string info8 = "封禁成功";
						printInfo(info8);
						back2Ad();
					}
				}
				else if (ans == "n") {
					string info4 = "取消封禁";
					printInfo(info4);
					back2Ad();
				}
			}
		}
		else {
			string info6 = "未找到该用户";
			printInfo(info6);
			back2Ad();
		}
		break;
	}
	case 55: {
		//TODO
		system("cls");
		marketSystem();
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(500);
		system("cls");
		administrator();
	}
	}
}


void adSearchOrder() {
	printDisplay();
	cout << endl;
	string str = "1.直接查看所有订单     2.查看某一用户的订单     3.返回管理员主界面";
	for (int i = 0; i < 20; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		showAllOrders();
		back2AdSearchOrder();
		break;
	}
	case 50: {
		//TODO
		string info = "请输入一个用户ID：";
		printInfo(info);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string userId;
		cin >> userId;
		vector<order> orders, res;
		readDatasOrder(orders);
		for (int i = 0; i < orders.size(); i++) {
			if (orders[i].sellerID == userId || orders[i].buyerID==userId) {
				res.push_back(orders[i]);
			}
		}
		if (res.size() > 0) {
			printOrders2(res);
			back2AdSearchOrder();
		}
		else {
			printSearchFailed2();
			Sleep(500);
			system("cls");
			adSearchOrder();
		}
		back2AdSearchOrder();
		break;
	}
	case 51: {
		//TODO
		Sleep(100);
		system("cls");
		administrator();
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(500);
		system("cls");
		adSearchOrder();
	}
	}
}


int searchUserID(string userId, vector<user>&users, vector<user>&res) {
	for (int i = 0; i < users.size(); i++) {
		if (users[i].userID == userId) {
			res.push_back(users[i]);
			return i;
			break;
		}
	}
	return -1;
}


void printInfo(string&str) {
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	cout << str;
}


void printSearchFailed() {
	cout << endl ;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 34; i++) {
		cout << "*";
	}
	string info2 = "没有找到您想要的商品！返回初始界面";
	printInfo(info2);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 34; i++) {
		cout << "*";
	}
	cout << endl;
}


void printSearchFailed2() {
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 50; i++) {
		cout << "*";
	}
	string info2 = "没有找到涉及到该用户的订单！返回初始界面";
	printInfo(info2);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 50; i++) {
		cout << "*";
	}
	cout << endl;
}


// Read datas from commodity.txt to cmds, 这里要解决一下输入中途文件就结束了的问题
void readDatasCmd(vector<cmd>&cmds) {
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
		f >> temp.cmdNum;
		f >> temp.sellerID;
		f >> temp.cmdState;
		f >> temp.cmdDiscription;
		if(temp.cmdID!="") cmds.push_back(temp);
	}
}


void readDatasRecord(vector<record>& records) {
	ifstream f;
	f.open("d:\\record.txt", ios::in);
	if (!f) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	while (!f.eof()) {
		record temp;
		f >> temp.price;
		f >> temp.day;
		f >> temp.userID;
		if (temp.price != "") records.push_back(temp);
	}
}


void readDatasMsg(vector<msg>& msgs) {
	ifstream f;
	f.open("d:\\message.txt", ios::in);
	if (!f) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	while (!f.eof()) {
		msg temp;
		f >> temp.sender;
		f >> temp.receiver;
		f >> temp.content;
		if (temp.sender != "") msgs.push_back(temp);
	}
}


// 这里要解决一下输入中途文件就结束了的问题
void writeDatasCmd(vector<cmd>& cmds) {
	ofstream of;
	of.open("d:\\commodity.txt", ios::out);
	if (!of) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	// int tt = 0;
	for (int i = 0; i < cmds.size(); i++) {
		of << cmds[i].cmdID << ' ' << cmds[i].cmdName << ' ' << controlDigits(cmds[i].cmdPrice) << ' ' << cmds[i].cmdDay << ' ' << cmds[i].cmdNum << ' ' << cmds[i].sellerID << ' ' << cmds[i].cmdState << ' ' << cmds[i].cmdDiscription << endl;
	}
	of.close();
}


void writeDatasRecord(vector<record>& records) {
	ofstream of;
	of.open("d:\\record.txt", ios::out);
	if (!of) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	// int tt = 0;
	for (int i = 0; i < records.size(); i++) {
		of << controlDigits(records[i].price) << ' ' << records[i].day << ' ' << records[i].userID << endl;
	}
	of.close();
}


void writeDatasMsg(vector<msg>& msgs) {
	ofstream of;
	of.open("d:\\message.txt", ios::out);
	if (!of) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	// int tt = 0;
	for (int i = 0; i < msgs.size(); i++) {
		of << msgs[i].sender << ' ' << msgs[i].receiver << ' ' << msgs[i].content << endl;
	}
	of.close();
}


void printCommodities(vector<cmd>& cmds) {
	printDisplay2();
	string str = "商品ID     名称                   价格       上架时间     数量       卖家ID     商品状态";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < cmds.size(); i++) {
		cout << "                                             ";
		string tmp = " ";
		string blank1 = displayHelper(tmp, 20 - cmds[i].cmdName.length());
		string blank2 = displayHelper(tmp, 5 - cmds[i].cmdPrice.length());
		string blank3 = displayHelper(tmp, 4 - cmds[i].cmdNum.length());
		cout << cmds[i].cmdID << "     " << cmds[i].cmdName << "     " + blank1 << cmds[i].cmdPrice << "     " + blank2 << cmds[i].cmdDay << "     " << cmds[i].cmdNum << "       " + blank3 << cmds[i].sellerID << "       " << cmds[i].cmdState << endl;
	}
	printDisplay2();
}


void printRecords(vector<record>& records) {
	printDisplay2();
	string str = "充值金额     充值时间";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < records.size(); i++) {
		cout << "                                             ";
		string tmp = " ";
		string blank1 = displayHelper(tmp, 7 - records[i].price.length());
		cout << records[i].price << "     " + blank1 << records[i].day << endl;
	}
	printDisplay2();
}


void showAllCommodities() {
	//cout << "Not implemented";
	vector<cmd> cmds;
	readDatasCmd(cmds);
	printCommodities(cmds);
}


void showRefillRecord(string&uid) {
	//cout << "Not implemented";
	vector<record> records, res;
	readDatasRecord(records);
	searchRecordUid(uid, records, res);
	if (res.size() > 0) {
		printRecords(res);
	}
	else {
		string info1 = "未查询到到充值记录";
		printInfo(info1);
	}
}


void searchRecordUid(string& uid, vector<record>& records, vector<record>& res) {
	for (int i = 0; i < records.size(); i++) {
		if (records[i].userID == uid) {
			res.push_back(records[i]);
		}
	}
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


void searchSimple2(string& str, vector<cmd>cmds, vector<cmd>& res) {
	for (int i = 0; i < cmds.size(); i++) {
		if (strIn(cmds[i].cmdDiscription, str) != 0) {
			res.push_back(cmds[i]);
		}
	}
}


bool comp(pair<cmd, int> c1, pair<cmd, int> c2) {
	return c1.second < c2.second;
}


void searchComplex(string& str, vector<cmd>cmds, vector<cmd>& res) {
	searchSimple(str, cmds, res);
	if (res.size()==0) {
		vector<pair<cmd, int>> v;
		for (int i = 0; i < cmds.size(); i++) {
			v.push_back(make_pair(cmds[i], minDistance(str, cmds[i].cmdName)));
		}
		sort(v.begin(), v.end(), comp);
		int tt = 0;
		double n = 0.0;
		int nn = 0;
		// 若商品数小于等于50，则返回编辑距离前1/5的商品
		if (cmds.size() <= 50) {
			n = cmds.size() / 5;
			if (n < 2) nn = 1;
			else nn = n;
			int i = 0;
			while (1) {
				res.push_back(v[i].first);
				i++;
				if (i >= nn) {
					if (v.size() >= 2 && v[i].second == v[i - 1].second) continue;
					else break;
				}
			}
		}
		// 若商品数大于50小于等于500，则返回前1/10的商品
		else if (cmds.size() > 50 && cmds.size() <= 500) {
			n = cmds.size() / 10;
			if (n < 2) nn = 1;
			else nn = n;
			int i = 0;
			while (1) {
				res.push_back(cmds[i]);
				i++;
				if (i >= nn) {
					if (cmds.size() >= 2 && cmds[i].cmdName == cmds[i - 1].cmdName) continue;
					else break;
				}
			}
		}
		// 若商品数大于500，则返回前1/100的商品
		else if (cmds.size() > 500) {
			n = cmds.size() / 100;
			if (n < 2) nn = 1;
			else nn = n;
			int i = 0;
			while (1) {
				res.push_back(cmds[i]);
				i++;
				if (i >= nn) {
					if (cmds.size() >= 2 && cmds[i].cmdName == cmds[i - 1].cmdName) continue;
					else break;
				}
			}
		}
	}
}


void searchComplex2(string& str, vector<cmd>cmds, vector<cmd>& res) {
	searchSimple2(str, cmds, res);
	if (res.size() == 0) {
		vector<pair<cmd, int>> v;
		for (int i = 0; i < cmds.size(); i++) {
			v.push_back(make_pair(cmds[i], minDistance(str, cmds[i].cmdDiscription)));
		}
		sort(v.begin(), v.end(), comp);
		int tt = 0;
		double n = 0.0;
		int nn = 0;
		// 若商品数小于等于50，则返回编辑距离前1/5的商品
		if (cmds.size() <= 50) {
			n = cmds.size() / 5;
			if (n < 2) nn = 1;
			else nn = n;
			int i = 0;
			while (1) {
				res.push_back(v[i].first);
				i++;
				if (i >= nn) {
					if (v.size() >= 2 && v[i].second == v[i - 1].second) continue;
					else break;
				}
			}
		}
		// 若商品数大于50小于等于500，则返回前1/10的商品
		else if (cmds.size() > 50 && cmds.size() <= 500) {
			n = cmds.size() / 10;
			if (n < 2) nn = 1;
			else nn = n;
			int i = 0;
			while (1) {
				res.push_back(cmds[i]);
				i++;
				if (i >= nn) {
					if (cmds.size() >= 2 && cmds[i].cmdDiscription == cmds[i - 1].cmdDiscription) continue;
					else break;
				}
			}
		}
		// 若商品数大于500，则返回前1/100的商品
		else if (cmds.size() > 500) {
			n = cmds.size() / 100;
			if (n < 2) nn = 1;
			else nn = n;
			int i = 0;
			while (1) {
				res.push_back(cmds[i]);
				i++;
				if (i >= nn) {
					if (cmds.size() >= 2 && cmds[i].cmdDiscription == cmds[i - 1].cmdDiscription) continue;
					else break;
				}
			}
		}
	}
}


int searchCmdID(string cmdId, vector<cmd>& cmds, vector<cmd>& res) {
	for (int i = 0; i < cmds.size(); i++) {
		if (cmds[i].cmdID == cmdId) {
			res.push_back(cmds[i]);
			return i;
			break;
		}
	}
	return -1;
}


void readDatasOrder(vector<order>& orders) {
	ifstream f;
	f.open("d:\\order.txt", ios::in);
	if (!f) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	while (!f.eof()) {
		order temp;
		f >> temp.orderID;
		f >> temp.cmdID;
		f >> temp.orderPrice;
		f >> temp.orderNum;
		f >> temp.orderDay;
		f >> temp.sellerID;
		f >> temp.buyerID;
		if(temp.orderID!="") orders.push_back(temp);
	}
}


void writeDatasOrder(vector<order>& orders) {
	ofstream of;
	of.open("d:\\order.txt", ios::out);
	if (!of) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	// int tt = 0;
	for (int i = 0; i < orders.size(); i++) {
		of << orders[i].orderID << ' ' << orders[i].cmdID << ' ' << controlDigits(orders[i].orderPrice) << ' ' << orders[i].orderNum << ' ' << orders[i].orderDay << ' ' << orders[i].sellerID << ' ' << orders[i].buyerID << endl;
	}
	of.close();
}


void showAllOrders() {
	vector<order> orders;
	readDatasOrder(orders);
	printOrders(orders);
}


void printOrders(vector<order>& orders) {
	printDisplay2();
	string str = "订单ID  商品ID   交易单价    数量      交易时间        卖家ID     买家ID";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < orders.size(); i++) {
		cout << "                                             ";
		string tmp = " ";
		string blank1 = displayHelper(tmp, 7 - orders[i].orderPrice.length());
		string blank2 = displayHelper(tmp, 4 - orders[i].orderNum.length());
		cout << orders[i].orderID << "     " << orders[i].cmdID << "     " << orders[i].orderPrice << "     " + blank1 << orders[i].orderNum << "     " + blank2 << orders[i].orderDay << "       " << orders[i].sellerID << "       " << orders[i].buyerID << endl;
	}
	printDisplay2();
}


void printOrders2(vector<order>& orders) {
	string info1 = "涉及到该用户的订单如下：";
	printInfo(info1);
	cout << endl;
	printDisplay2();
	string str = "订单ID  商品ID   交易单价    数量      交易时间        卖家ID     买家ID";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < orders.size(); i++) {
		cout << "                                             ";
		string tmp = " ";
		string blank1 = displayHelper(tmp, 7 - orders[i].orderPrice.length());
		string blank2 = displayHelper(tmp, 4 - orders[i].orderNum.length());
		cout << orders[i].orderID << "     " << orders[i].cmdID << "     " << orders[i].orderPrice << "     " + blank1 << orders[i].orderNum << "     " + blank2 << orders[i].orderDay << "       " << orders[i].sellerID << "       " << orders[i].buyerID << endl;
	}
	printDisplay2();
}


void readDatasUser(vector<user>&users) {
	ifstream f;
	f.open("d:\\user.txt", ios::in);
	if (!f) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	while (!f.eof()) {
		user temp;
		vector<string> messages;
		f >> temp.userID;
		f >> temp.userName;
		f >> temp.userContact;
		f >> temp.userAdress;
		f >> temp.userBalance;
		f >> temp.userState;
		f >> temp.userCode;
		if(temp.userID!="") users.push_back(temp);
	}
}


void printUsers(vector<user>&users, int type) {
	printDisplay2();
	if (type == 0) {
		string str = "用户ID  用户名    联系方式          地址                   钱包余额      用户状态";
		cout << endl;
		for (int i = 0; i < 15; i++) {
			cout << "   ";
		}
		cout << str << endl;
		for (int i = 0; i < users.size(); i++) {
			cout << "                                             ";
			string tmp = " ";
			string blank1 = displayHelper(tmp, 12 - users[i].userContact.length());
			string blank2 = displayHelper(tmp, 20 - users[i].userAdress.length());
			string blank3 = displayHelper(tmp, 7 - users[i].userBalance.length());
			cout << users[i].userID << "     " << users[i].userName << "     " << users[i].userContact << "     " + blank1 << users[i].userAdress << "     " + blank2 << users[i].userBalance << "       " + blank3 << users[i].userState << endl;
		}
	}
	else if (type == 1) {
		string str = "用户ID  用户名    联系方式          地址                   钱包余额";
		cout << endl;
		for (int i = 0; i < 15; i++) {
			cout << "   ";
		}
		cout << str << endl;
		for (int i = 0; i < users.size(); i++) {
			cout << "                                             ";
			string tmp = " ";
			string blank1 = displayHelper(tmp, 12 - users[i].userContact.length());
			string blank2 = displayHelper(tmp, 20 - users[i].userAdress.length());
			cout << users[i].userID << "     " << users[i].userName << "     " << users[i].userContact << "     " + blank1 << users[i].userAdress << "     " + blank2 << users[i].userBalance << endl;
		}
	}
	printDisplay2();
}


void showAllUsers() {
	vector<user> users;
	readDatasUser(users);
	printUsers(users, 0);
}


void writeDatasUser(vector<user>& users) {
	ofstream of;
	of.open("d:\\user.txt", ios::out);
	if (!of) {
		cout << "Error: Failed to open the file" << endl;
		exit(-1);
	}
	// int tt = 0;
	for (int i = 0; i < users.size(); i++) {
		of << users[i].userID << ' ' << users[i].userName << ' ' << users[i].userContact << ' ' << users[i].userAdress << ' ' << controlDigits(users[i].userBalance) << ' ' << users[i].userState << ' ' << users[i].userCode << endl;
	}
	of.close();
}


void userSignUp() {
	vector<user>users;
	readDatasUser(users);
	int nn = users.size();
	// int tt = 0;
	cout << endl;
	string info1 = "请输入用户名（用户名不超过10个字符）：";
	int res1[2] = { 0 };
	int res2[2] = { 0 };
	int res3[2] = { 0 };
	printInfo(info1);
	appGetXY(res1);
	string info2 = "请输入密码（密码不超过20个有效字符）：";
	printInfo(info2);
	appGetXY(res2);
	string info3 = "请再次输入密码：";
	printInfo(info3);
	appGetXY(res3);
	string userNamee, code, codeAgain;
	gotoxy(res1[0], res1[1]);
	cin >> userNamee;
	gotoxy(res2[0], res2[1]);
	cin >> code;
	gotoxy(res3[0], res3[1]);
	cin >> codeAgain;
	l5:int flag1 = 0;
	for (int i = 0; i < users.size(); i++) {
		if (userNamee == users[i].userName) {
			flag1 = 1;
			break;
		}
	}
	if (flag1 == 1) {
		string info4 = "用户名已存在，请重新输入：";
		printInfo(info4);
		int res4[2] = { 0 };
		appGetXY(res4);
		gotoxy(res4[0], res4[1]);
		cin >> userNamee;
		goto l5;
	}
	l6:if (code != codeAgain) {
		int res5[2] = { 0 };
		int res6[2] = { 0 };
		string info5 = "两次密码不一致，请重新输入：";
		printInfo(info5);
		appGetXY(res5);
		string info6 = "请再次确认：";
		printInfo(info6);
		appGetXY(res6);
		gotoxy(res5[0], res5[1]);
		cin >> code;
		gotoxy(res6[0], res6[1]);
		cin >> codeAgain;
		goto l6;
	}
	l7:if (userNamee.length() > 10) {
		string info7 = "用户名过长，请重新输入：";
		printInfo(info7);
		int res7[2] = { 0 };
		appGetXY(res7);
		gotoxy(res7[0], res7[1]);
		cin >> userNamee;
		goto l7;
	}
	if (code.length() > 20) {
		int res8[2] = { 0 };
		int res9[2] = { 0 };
		string info8 = "密码过长，请重新输入：";
		string info9 = "请再次确认：";
		printInfo(info8);
		appGetXY(res8);
		printInfo(info9);
		appGetXY(res9);
		gotoxy(res8[0], res8[1]);
		cin >> code;
		gotoxy(res9[0], res9[1]);
		cin >> codeAgain;
		goto l6;
	}
	string info10 = "请继续完善您的个人信息完成注册";
	printInfo(info10);
	int res10[2] = { 0 };
	int res11[2] = { 0 };
	string info11 = "请输入您的电话号码：";
	string info12 = "请输入您的地址：";
	printInfo(info11);
	appGetXY(res10);
	printInfo(info12);
	appGetXY(res11);
	gotoxy(res10[0], res10[1]);
	string number, adress;
	// 这里还没有对电话号码和地址的格式进行判断
	cin >> number;
	gotoxy(res11[0], res11[1]);
	cin >> adress;
	user tmp;
	string u = "U";
	tmp.userID = u + getID(nn);
	tmp.userName = userNamee;
	tmp.userContact = number;
	tmp.userAdress = adress;
	tmp.userBalance = "0.0";
	tmp.userState = "正常";
	tmp.userCode = code;
	users.push_back(tmp);
	// int ttt = 0;
	writeDatasUser(users);
	string info13 = "注册成功，按y返回主菜单：";
	int res13[2] = { 0 };
	printInfo(info13);
	appGetXY(res13);
	gotoxy(res13[0], res13[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		marketSystem();
	}
}


string getID(int n) {
	if (n < 9) {
		string tmp1 = "00";
		string num = to_string(n + 1);
		return tmp1 + num;
	}
	else if (n >= 9 && n < 99) {
		string tmp2 = "0";
		string num = to_string(n + 1);
		return tmp2 + num;
	}
	else if (n >= 99) {
		string num = to_string(n + 1);
		return num;
	}
}


void userLogin(string&uid, int userLoginTimes) {
	vector<user>users;
	readDatasUser(users);
	if (userLoginTimes == 0) {
		userLoginTimes++;
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		string info1 = "请输入用户名：";
		printInfo(info1);
		appGetXY(res1);
		string info2 = "请输入密码：";
		printInfo(info2);
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		vector<user> res;
		searchUserName(ans1, users, res);
		if (res.size()>0 && ans2 == res[0].userCode) {
			int tt = 0;
			uid = res[0].userID;
			int ttt = 0;
			string info3 = "-----登录成功-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----登录失败-----";
			printInfo(info4);
			string info6 = "是否退出登录？[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "请重新登录";
				cout << endl;
				printInfo(info5);
				userLogin(uid, userLoginTimes);
			}
			else if (ans == "y") {
				Sleep(100);
				system("cls");
				marketSystem();
			}
		}
	}
	else {
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		string info1 = "请再次输入用户名：";
		printInfo(info1);
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		string info2 = "请再次输入密码：";
		printInfo(info2);
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		vector<user> res;
		searchUserName(ans1, users, res);
		if (res.size() > 0 && ans2 == res[0].userCode) {
			uid = res[0].userID;
			string info3 = "-----登录成功-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----登录失败-----";
			printInfo(info4);
			string info6 = "是否退出登录？[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "请重新登录";
				cout << endl;
				printInfo(info5);
				userLogin(uid, userLoginTimes);
			}
			else if (ans == "y") {
				Sleep(100);
				system("cls");
				marketSystem();
			}
		}
	}
}


void searchUserName(string username, vector<user>&users, vector<user>&res) {
	for (int i = 0; i < users.size(); i++) {
		if (users[i].userName == username) {
			res.push_back(users[i]);
		}
	}
}


int userHome() {
	printDisplay();
	cout << endl;
	string str = "1. 我是买家     2.我是卖家     3.个人信息管理     4.留言     5.注销登录";
	for (int i = 0; i < 18; i++) {
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


void printCommodities4Buyer(vector<cmd>&cmds) {
	printDisplay2();
	string str = "商品ID     名称                   价格      上架时间        卖家ID";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < cmds.size(); i++) {
		if (cmds[i].cmdState == "销售中") {
			cout << "                                             ";
			string tmp = " ";
			string blank1 = displayHelper(tmp, 20 - cmds[i].cmdName.length());
			string blank2 = displayHelper(tmp, 5 - cmds[i].cmdPrice.length());
			string blank3 = displayHelper(tmp, 4 - cmds[i].cmdDay.length());
			cout << cmds[i].cmdID << "     " << cmds[i].cmdName << "     " + blank1 << cmds[i].cmdPrice << "     " + blank2 << cmds[i].cmdDay << "       " + blank3 << cmds[i].sellerID << endl;
		}
		else continue;
	}
	printDisplay2();
}


void showAllCommodities4Buyer() {
	vector<cmd> cmds;
	readDatasCmd(cmds);
	printCommodities4Buyer(cmds);
}


void showAllCommodities4Seller(string&uid) {
	vector<cmd> cmds;
	readDatasCmd(cmds);
	printCommodities4Seller(cmds, uid);
}


string displayHelper(string&str, int a) {
	string res = "";
	for (int i = 0; i < a; i++) {
		res += str;
	}
	return res;
}


void printCommodities4Seller(vector<cmd>& cmds, string&uid) {
	printDisplay2();
	string str = "商品ID       名称                 价格    数量       上架时间        商品状态";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < cmds.size(); i++) {
		if (cmds[i].sellerID == uid) {
			cout << "                                             ";
			string tmp = " ";
			string blank1 = displayHelper(tmp, 20 - cmds[i].cmdName.length());
			string blank2 = displayHelper(tmp, 5 - cmds[i].cmdPrice.length());
			// string blank3 = displayHelper(tmp, 4 - cmds[i].cmdDay.length());
			string blank4 = displayHelper(tmp, 4 - cmds[i].cmdNum.length());
			cout << cmds[i].cmdID << "     " << cmds[i].cmdName << "     " + blank1 << cmds[i].cmdPrice << "     " + blank2 << cmds[i].cmdNum << "     " + blank4 << cmds[i].cmdDay << "       " << cmds[i].cmdState << endl;
		}
		else continue;
	}
	printDisplay2();
}


void back2Buyer(string uid) {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回买家操作界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		buyer(uid);
	}
}


void back2userSearch(string uid) {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回买家搜索界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		buyerSearch(uid);
	}
}


void back2Seller(string uid) {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "按y返回卖家操作界面：";
	printInfo(info1);
	appGetXY(res2);
	gotoxy(res2[0], res2[1]);
	string ans;
	ans = handleInvalidInput_y();
	if (ans == "y") {
		Sleep(100);
		system("cls");
		seller(uid);
	}
}


void showAllOrders4Buyer(string&uID) {
	vector<order> orders;
	readDatasOrder(orders);
	vector<order> res;
	for (int i = 0; i < orders.size(); i++) {
		if (orders[i].buyerID == uID) {
			res.push_back(orders[i]);
		}
	}
	printOrders(res);
}


void showAllOrders4Seller(string& uID) {
	vector<order> orders;
	readDatasOrder(orders);
	vector<order> res;
	for (int i = 0; i < orders.size(); i++) {
		if (orders[i].sellerID == uID) {
			res.push_back(orders[i]);
		}
	}
	printOrders(res);
}


void buyer(string uid) {
	printDisplay();
	cout << endl;
	string str = "1.查看商品列表     2.购买商品     3.搜索商品     4.查看历史订单     5.查看商品详细信息     6.返回用户主界面";
	for (int i = 0; i < 12; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		showAllCommodities4Buyer();
		back2Buyer(uid);
		break;
	}
	case 50: {
		//TODO
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		string info1 = "请输入商品ID：";
		printInfo(info1);
		appGetXY(res1);
		string info2 = "请输入数量（购买数量不可为0且不可以0开头）：";
		printInfo(info2);
		appGetXY(res2);
		string id, num;
		gotoxy(res1[0], res1[1]);
		cin >> id;
		gotoxy(res2[0], res2[1]);
		cin >> num;
		// 检查num输入是否合法
		l1:for (int i = 0; i < num.length(); i++) {
			if (num[0] == '0' || num[i] > '9' || num[i] < '0') {
				string info3 = "输入数量不合法，请重新输入：";
				printInfo(info3);
				cin >> num;
				goto l1;
			}
		}
		vector<cmd> res, cmds;
		vector<user> users, thisUser;
		vector<order>orders;
		readDatasOrder(orders);
		readDatasUser(users);
		int idxx = -1;
		idxx = searchUserID(uid, users, thisUser);
		readDatasCmd(cmds);
		int idx = -1;
		idx = searchCmdID(id, cmds, res);
		// int ttt = 0;
		if (idx >= 0 && res[0].cmdState == "销售中") {
			if (atof(res[0].cmdNum.c_str()) < atof(num.c_str())) {
				string info7 = "抱歉，该商品仅剩"+res[0].cmdNum+"件，您想买的件数超出剩余量";
				printInfo(info7);
			}
			else if (atof(num.c_str()) * atof(res[0].cmdPrice.c_str()) > atof(thisUser[0].userBalance.c_str())) {
				string info4 = "您的余额不足";
				printInfo(info4);
			}
			else {
				// 购买成功，更新订单文件
				order tmp;
				tmp.buyerID = uid;
				tmp.cmdID = id;
				// 调用系统函数获取当前时间
				time_t curtime;
				time(&curtime);
				tm* nowtime = localtime(&curtime);
				tmp.orderDay = to_string(1900 + nowtime->tm_year) + "-" + to_string(nowtime->tm_mon + 1) + "-" + to_string(nowtime->tm_mday);
				string t = "T";
				tmp.orderID = t + getID(orders.size());
				tmp.orderNum = num;
				tmp.orderPrice = to_string(atof(num.c_str()) * atof(res[0].cmdPrice.c_str()));
				tmp.sellerID = res[0].sellerID;
				orders.push_back(tmp);
				writeDatasOrder(orders);
				// 更新用户文件-买家
				// int tt = 0;
				users[idxx].userBalance = to_string(atof(thisUser[0].userBalance.c_str()) - atof(num.c_str()) * atof(res[0].cmdPrice.c_str()));
				// 更新用户文件-卖家
				int idx2 = -1;
				vector<user>resus;
				idx2 = searchUserID(res[0].sellerID, users, resus);
				if (idx2 != -1) {
					// int tttt = 0;
					users[idx2].userBalance = to_string(atof(resus[0].userBalance.c_str()) + atof(num.c_str()) * atof(res[0].cmdPrice.c_str()));
				}
				writeDatasUser(users);
				// 更新商品文件
				cmds[idx].cmdNum = to_string(atoi(cmds[idx].cmdNum.c_str()) - atoi(num.c_str()));
				if (atof(cmds[idx].cmdNum.c_str()) == 0) {
					cmds[idx].cmdState = "补货中";
				}
				writeDatasCmd(cmds);
				string info8 = "购买成功，您可在订单中查看该订单";
				printInfo(info8);
			}
		}
		else {
			cout << endl;
			string info6 = "抱歉，未找到相应的商品";
			printInfo(info6);
		}
		back2Buyer(uid);
		break;
	}
	case 51: {
		//TODO
		Sleep(100);
		system("cls");
		buyerSearch(uid);
		break;
	}
	case 52: {
		//TODO
		showAllOrders4Buyer(uid);
		back2Buyer(uid);
		break;
	}
	case 53: {
		//TODO
		string info1 = "请输入您想要查看的商品ID：";
		printInfo(info1);
		int res1[2] = { 0 };
		appGetXY(res1);
		string cid;
		gotoxy(res1[0], res1[1]);
		cin >> cid;
		int idx = -1;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		idx=searchCmdID(cid, cmds, res);
		if(res.size()>0) {
			if (res[0].cmdState != "销售中") {
				string info3 = "抱歉，该商品暂不销售";
				printInfo(info3);
			}
			else displayDiscriptionofCmd(res);
			back2Buyer(uid);
		}
		else {
			string info2 = "抱歉，未查找到相关商品";
			printInfo(info2);
			back2Buyer(uid);
		}
		break;
	}
	case 54: {
		//TODO
		Sleep(100);
		system("cls");
		userOp(uid);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(500);
		system("cls");
		buyer(uid);
	}
	}
}


void buyerSearch(string& uid) {
	printDisplay();
	cout << endl;
	string str = "1.按商品名称搜索     2.按商品卖家搜索     3.按商品价格区间搜索     4.按商品描述搜索     5.返回买家主界面";
	for (int i = 0; i < 20; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		string info = "请输入商品名称：";
		printInfo(info);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string cmdName;
		cin >> cmdName;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		searchComplex(cmdName, cmds, res);
		if (res.size() > 0) {
			vector<cmd>res4User;
			for (int i = 0; i < res.size(); i++) {
				if (res[i].cmdState == "销售中") {
					res4User.push_back(res[i]);
				}
			}
			if (res4User.size() > 0) {
				printCommodities4Buyer(res4User);
				back2userSearch(uid);
			}
			else {
				printSearchFailed();
				cout << endl;
				back2userSearch(uid);
			}
		}
		else {
			printSearchFailed();
			cout << endl;
			back2userSearch(uid);
		}
		back2userSearch(uid);
		break;
	}
	case 50: {
		//TODO
		string info = "请输入商品卖家ID：";
		printInfo(info);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string sellerId;
		cin >> sellerId;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		for (int i = 0; i < cmds.size(); i++) {
			if (cmds[i].sellerID == sellerId) {
				res.push_back(cmds[i]);
			}
		}
		if (res.size() > 0) {
			vector<cmd>res4User;
			for (int i = 0; i < res.size(); i++) {
				if (res[i].cmdState == "销售中") {
					res4User.push_back(res[i]);
				}
			}
			if (res4User.size() > 0) {
				printCommodities4Buyer(res4User);
				back2userSearch(uid);
			}
			else {
				printSearchFailed();
				cout << endl;
				back2userSearch(uid);
			}
		}
		else {
			printSearchFailed();
			cout << endl;
			buyerSearch(uid);
		}
		back2userSearch(uid);
		break;
	}
	case 51: {
		string info1 = "请输入最低价格，商品价格不可以0开头（01之间的小数除外）：";
		string info2 = "请输入最高价格，商品价格不可以0开头（01之间的小数除外）：";
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		printInfo(info1);
		appGetXY(res1);
		printInfo(info2);
		appGetXY(res2);
		string price1, price2;
		gotoxy(res1[0], res1[1]);
		cin >> price1;
		gotoxy(res2[0], res2[1]);
		cin >> price2;
		// 检查输入价格是否合法
	l1:int flag1 = 1;
		int decNum1 = 0;
		if (price1.length() >= 2 && price1[0] == '0' && price1[1] != '.') flag1 = 0;
		for (int i = 0; i < price1.length(); i++) {
			if (price1[i] < '0' || price1[i] > '9') {
				if (price1[i] == '.' && decNum1 == 0 && i != price1.length() - 1) {
					decNum1++;
					continue;
				}
				else {
					flag1 = 0;
					break;
				}
			}
		}
		if (flag1 == 0) {
			string info3 = "您输入的最低价格格式有误，请重新输入：";
			printInfo(info3);
			cin >> price1;
			goto l1;
		}
	l2:int flag2 = 1;
		int decNum2 = 0;
		if (price2.length() >= 2 && price2[0] == '0' && price2[1] != '.') flag2 = 0;
		for (int i = 0; i < price2.length(); i++) {
			if (price2[i] < '0' || price2[i] > '9') {
				if (price2[i] == '.' && decNum2 == 0 && i != price2.length() - 1) {
					decNum2++;
					continue;
				}
				else {
					flag2 = 0;
					break;
				}
			}
		}
		if (flag2 == 0) {
			string info4 = "您输入的最高价格格式有误，请重新输入：";
			printInfo(info4);
			cin >> price2;
			goto l2;
		}
		// 判断最低价格是否小于等于最高价格
		if (atof(price1.c_str()) > atof(price2.c_str())) {
			string info7 = "最高价格必须大于等于最低价格，请重新输入最高价格：";
			printInfo(info7);
			cin >> price2;
			goto l2;
		}
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		for (int i = 0; i < cmds.size(); i++) {
			if (atof(cmds[i].cmdPrice.c_str()) >= atof(price1.c_str()) && atof(cmds[i].cmdPrice.c_str()) <= atof(price2.c_str()) && cmds[i].cmdState=="销售中") {
				res.push_back(cmds[i]);
			}
		}
		if (res.size() > 0) {
			printCommodities4Buyer(res);
			back2userSearch(uid);
		}
		else {
			printSearchFailed();
			cout << endl;
			back2userSearch(uid);
		}
		back2userSearch(uid);
		break;
	}
	case 52: {
		string info1 = "请输入商品描述：";
		int res1[2] = { 0 };
		printInfo(info1);
		appGetXY(res1);
		string dis;
		gotoxy(res1[0], res1[1]);
		cin >> dis;
		vector<cmd> cmds, res, res4User;
		readDatasCmd(cmds);
		searchComplex2(dis, cmds, res);
		for (int i = 0; i < res.size(); i++) {
			if (res[i].cmdState == "销售中") {
				res4User.push_back(res[i]);
			}
		}
		if (res4User.size() > 0) {
			printCommodities4Buyer(res4User);
		}
		else {
			printSearchFailed();
			cout << endl;
			back2userSearch(uid);
		}
		back2userSearch(uid);
		break;
	}
	case 53: {
		//TODO
		Sleep(100);
		system("cls");
		buyer(uid);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(500);
		system("cls");
		buyerSearch(uid);
	}
	}
}


string controlDigits(string n) {
	double val = atof(n.c_str());
	int a = val;
	double rest = val - a;
	int tt = 0;
	if (rest < 0.05) {
		string tmp = ".0";
		return to_string(a) + tmp;
	}
	else {
		string str = to_string(rest);
		if (str[2] < '9') {
			if (str[3] >= '5') {
				string tmp = ".";
				char c = str[2] + 1;
				return to_string(a) + tmp + c;
			}
			else {
				int ttt = 0;
				string tmp = ".";
				int tttt = 0;
				return to_string(a) + tmp + str[2];
			}
		}
		else {
			if (str[3] < '9') {
				string tmp = ".";
				return to_string(a) + tmp + str[2];
			}
			else {
				string aa = to_string(a + 1);
				string tmp = ".0";
				return aa + tmp;
			}
		}
	}
}


void displayDiscriptionofCmd(vector<cmd>&res) {
	cout << endl;
	printDisplay2();
	string info1 = "商品ID：" + res[0].cmdID;
	string info2 = "商品名称：" + res[0].cmdName;
	string info3 = "商品价格：" + res[0].cmdPrice;
	string info4 = "上架时间：" + res[0].cmdDay;
	string info5 = "商品描述：" + res[0].cmdDiscription;
	string info6 = "商品卖家：" + res[0].sellerID;
	printInfo(info1);
	printInfo(info2);
	printInfo(info3);
	printInfo(info4);
	printInfo(info5);
	printInfo(info6);
	cout << endl;
	printDisplay2();
}


void displayDiscriptionofCmd4Seller(vector<cmd>& res) {
	cout << endl;
	printDisplay2();
	string info1 = "商品ID：" + res[0].cmdID;
	string info2 = "商品名称：" + res[0].cmdName;
	string info3 = "商品价格：" + res[0].cmdPrice;
	string info5 = "商品描述：" + res[0].cmdDiscription;
	printInfo(info1);
	printInfo(info2);
	printInfo(info3);
	printInfo(info5);
	cout << endl;
	printDisplay2();
}


void seller(string uid) {
	printDisplay();
	cout << endl;
	string str = "1.发布商品     2.查看发布商品     3.修改商品信息     4.下架商品     5.查看历史订单    6.返回用户主界面";
	for (int i = 0; i < 12; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		int times = 0;
		string info1 = "请输入商品名称：";
		string info2 = "请输入商品价格，商品价格不可以0开头（01之间的小数除外）：";
		string info3 = "请输入商品数量，商品数量不可为0且不可以0开头：";
		string info4 = "请输入商品描述：";
		string name, price, num, discription;
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		int res3[2] = { 0 };
		int res4[2] = { 0 };
		printInfo(info1);
		appGetXY(res1);
		printInfo(info2);
		appGetXY(res2);
		gotoxy(res1[0], res1[1]);
		cin >> name;
		gotoxy(res2[0], res2[1]);
		cin >> price;
		// 判断价格是否合法
		l1:int flag = 1;
		int decNum = 0;
		if (price.length() >= 2 && price[0] == '0' && price[1] != '.') flag = 0;
		for (int i = 0; i < price.length(); i++) {
			if (price[i] < '0' || price[i] > '9') {
				if (price[i] == '.' && decNum == 0 && i != price.length() - 1) {
					decNum++;
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
		}
		if (flag == 0) {
			int res4[2] = { 0 };
			string info13 = "您输入的价钱格式有误，请重新输入：";
			printInfo(info13);
			cin >> price;
			goto l1;
		}
		printInfo(info3);
		appGetXY(res3);
		gotoxy(res3[0], res3[1]);
		cin >> num;
		// 判断数量是否合法
		l3:for (int i = 0; i < num.length(); i++) {
			if (num[0] == '0' || num[i] > '9' || num[i] < '0') {
				string info14 = "输入数量不合法，请重新输入：";
				printInfo(info14);
				cin >> num;
				goto l3;
			}
		}
		printInfo(info4);
		appGetXY(res4);
		gotoxy(res4[0], res4[1]);
		cin >> discription;
		cout << endl;
		string info5 = "请确认发布的商品信息无误！";
		cout << endl;
		printDisplay2();
		string info6 = "商品名称：" + name;
		string info7 = "商品价格：" + controlDigits(price);
		string info8 = "商品数量：" + num;
		string info9 = "商品描述：" + discription;
		printInfo(info6);
		printInfo(info7);
		printInfo(info8);
		printInfo(info9);
		cout << endl;
		printDisplay2();
		cout << endl;
		string info10 = "您确认要发布商品吗？[y/n] ";
		int res10[2] = { 0 };
		printInfo(info10);
		appGetXY(res10);
		string ans;
		gotoxy(res10[0], res10[1]);
		ans = handleInvalidInput_yn();
		if (ans == "y") {
			vector<cmd>cmds, res;
			readDatasCmd(cmds);
			cmd tmp;
			string tmpM = "M";
			time_t curtime;
			time(&curtime);
			tm* nowtime = localtime(&curtime);
			string tmpd = to_string(1900 + nowtime->tm_year) + "-" + to_string(nowtime->tm_mon + 1) + "-" + to_string(nowtime->tm_mday);
			tmp.cmdID = tmpM + getID(cmds.size());
			tmp.cmdName = name;
			tmp.cmdPrice = price;
			tmp.cmdDay = tmpd;
			tmp.sellerID = uid;
			tmp.cmdNum = num;
			tmp.cmdState = "销售中";
			tmp.cmdDiscription = discription;
			cmds.push_back(tmp);
			writeDatasCmd(cmds);
			string info11 = "商品发布成功！";
			printInfo(info11);
		}
		else if (ans == "n") {
			string info12 = "取消发布";
			printInfo(info12);
		}
		back2Seller(uid);
		break;
	}
	case 50: {
		//TODO
		showAllCommodities4Seller(uid);
		back2Seller(uid);
		break;
	}
	case 51: {
		//TODO
		string info1 = "请输入被修改商品的ID：";
		string info2 = "请输入被修改商品的属性（1.价格  2.描述）：";
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		printInfo(info1);
		appGetXY(res1);
		printInfo(info2);
		appGetXY(res2);
		string id, attribute;
		gotoxy(res1[0], res1[1]);
		cin >> id;
		vector<cmd>cmds, res;
		readDatasCmd(cmds);
		int idx = -1;
		idx = searchCmdID(id, cmds, res);
		gotoxy(res2[0], res2[1]);
		attribute = handleInvalidInput_12();
		if (res.size() > 0 && res[0].sellerID==uid) {
			if (attribute == "1") {
				int res3[2] = { 0 };
				string price;
				string info3 = "请输入被修改商品的价格，商品价格不可以0开头（01之间的小数除外）：";
				printInfo(info3);
				appGetXY(res3);
				gotoxy(res3[0], res3[1]);
				cin >> price;
				// 判断价格是否格式正确
				l2:int flag = 1;
				int decNum = 0;
				if (price.length() >= 2 && price[0] == '0' && price[1] != '.') flag = 0;
				for (int i = 0; i < price.length(); i++) {
					if (price[i] < '0' || price[i] > '9') {
						if (price[i] == '.' && decNum==0 && i != price.length() - 1) {
							decNum++;
							continue;
						}
						else {
							flag = 0;
							break;
						}
					}
				}
				if (flag == 0) {
					int res4[2] = { 0 };
					string info4 = "您输入的价钱格式有误，请重新输入：";
					printInfo(info4);
					cin >> price;
					goto l2;
				}
				string info5 = "请确认修改的商品信息无误！";
				printInfo(info5);
				cout << endl;
				vector<cmd>ress;
				cmd tmp = res[0];
				tmp.cmdPrice = controlDigits(price);
				ress.push_back(tmp);
				displayDiscriptionofCmd4Seller(ress);
				cout << endl;
				string info6 = "确认修改？[y/n] ";
				printInfo(info6);
				string ans;
				ans = handleInvalidInput_yn();
				if (ans == "y") {
					cmds[idx].cmdPrice = price;
					writeDatasCmd(cmds);
					string info7 = "修改成功！";
					printInfo(info7);
				}
				else if (ans == "n") {
					string info8 = "已取消修改";
					printInfo(info8);
				}
			}
			else if (attribute == "2") {
				int res9[2] = { 0 };
				string info9 = "请输入被修改商品的描述：";
				printInfo(info9);
				appGetXY(res9);
				string discription;
				gotoxy(res9[0], res9[1]);
				cin >> discription;
				string ans;
				string info15 = "确认修改？[y/n] ";
				printInfo(info15);
				ans = handleInvalidInput_yn();
				if (ans == "y") {
					cmds[idx].cmdDiscription = discription;
					writeDatasCmd(cmds);
					string info10 = "修改成功！";
					printInfo(info10);
				}
				else if (ans == "n") {
					string info11 = "已取消修改";
					printInfo(info11);
				}
			}
		}
		else if(res.size()==0) {
			string info12 = "未找到该商品，即将为您返回卖家操作界面";
			printInfo(info12);
		}
		else if (res[0].sellerID != uid) {
			string info13 = "您不具备修改该商品的权限，因为您不是该商品的发布者";
			printInfo(info13);
		}
		back2Seller(uid);
		break;
	}
	case 52: {
		//TODO
		string info1 = "请输入要下架的商品ID：";
		printInfo(info1);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string cmdId;
		cin >> cmdId;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		int idx = -1;
		idx = searchCmdID(cmdId, cmds, res);
		if (res.size() > 0 && res[0].sellerID==uid && res[0].cmdState!="已下架") {
			string info2 = "确定要下架该商品吗？";
			printInfo(info2);
			cout << endl;
			printCommodities(res);
			string info3 = "请选择[y/n] ";
			printInfo(info3);
			int res3[2] = { 0 };
			appGetXY(res3);
			gotoxy(res3[0], res3[1]);
			string ans;
			ans = handleInvalidInput_yn();
			if (ans == "y") {
				string info4 = "商品下架成功";
				printInfo(info4);
				/*cmds.erase(cmds.begin() + idx);
				writeDatasCmd(cmds);*/
				cmds[idx].cmdState = "已下架";
				writeDatasCmd(cmds);
			}
			else if (ans == "n") {
				string info5 = "取消下架";
				printInfo(info5);
			}
		}
		else if(res.size()==0) {
			string info12 = "未找到该商品，即将为您返回卖家操作界面";
			printInfo(info12);
		}
		else if (res[0].sellerID != uid) {
			string info13 = "您不具备下架该商品的权限，因为您不是该商品的发布者";
			printInfo(info13);
		}
		else if (res[0].cmdState == "已下架") {
			string info14 = "该商品在此之前已经被下架，不能重复下架";
			printInfo(info14);
		}
		back2Seller(uid);
		break;
	}
	case 53: {
		//TODO
		showAllOrders4Seller(uid);
		back2Seller(uid);
		break;
	}
	case 54: {
		//TODO
		Sleep(100);
		system("cls");
		userOp(uid);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(500);
		system("cls");
		seller(uid);
	}
	}
}


void manageUserInformation(string uid) {
	printDisplay();
	cout << endl;
	string str = "1.查看信息     2.修改信息     3.充值    4.查看充值记录     5.返回用户主界面";
	for (int i = 0; i < 20; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		vector<user> users, res;
		readDatasUser(users);
		int idx = -1;
		idx = searchUserID(uid, users, res);
		cout << endl;
		printDisplay2();
		string info1 = "用户名：" + res[0].userName;
		string info2 = "联系方式：" + res[0].userContact;
		string info3 = "地址：" + res[0].userAdress;
		string info4 = "钱包余额：" + res[0].userBalance;
		printInfo(info1);
		printInfo(info2);
		printInfo(info3);
		printInfo(info4);
		cout << endl;
		printDisplay2();
		back2manageUser(uid);
		break;
	}
	case 50: {
		//TODO
		string info1 = "请选择修改的属性（1.用户名  2.联系方式  3.地址）：";
		printInfo(info1);
		string ans = handleInvalidInput_123();
		if (ans == "1") {
			vector<user> users, res;
			readDatasUser(users);
			int idx = -1;
			idx = searchUserID(uid, users, res);
			int res2[2] = { 0 };
			string info2 = "请选择修改后的用户名";
			printInfo(info2);
			appGetXY(res2);
			string ans;
			gotoxy(res2[0], res2[1]);
			cin >> ans;
			// 检查是否与已有用户名重复
			l2:int flag = 1;
			for (int i = 0; i < users.size(); i++) {
				if (users[i].userName == ans && i != idx) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				int res4[2] = { 0 };
				string info13 = "该用户名已被占用，请重新输入：";
				printInfo(info13);
				cin >> ans;
				goto l2;
			}
			users[idx].userName = ans;
			writeDatasUser(users);
		}
		else if (ans == "2") {
			vector<user> users, res;
			readDatasUser(users);
			int idx = -1;
			idx = searchUserID(uid, users, res);
			int res2[2] = { 0 };
			string info2 = "请输入修改后的联系方式：";
			printInfo(info2);
			appGetXY(res2);
			string ans2;
			gotoxy(res2[0], res2[1]);
			cin >> ans2;
			// 判断电话号码格式是否正确
			l1:int flag = 1;
			for (int i = 0; i < ans2.length(); i++) {
				if (ans2[i] > '9' || ans2[i] < '0') {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				int res4[2] = { 0 };
				string info13 = "您输入的电话号码格式有误，请重新输入：";
				printInfo(info13);
				cin >> ans2;
				goto l1;
			}
			users[idx].userAdress = ans2;
			writeDatasUser(users);
		}
		else if (ans == "3") {
			vector<user> users, res;
			readDatasUser(users);
			int idx = -1;
			idx = searchUserID(uid, users, res);
			string info2 = "请输入修改后的地址";
			printInfo(info2);
			string ans2;
			cin >> ans2;
			users[idx].userAdress = ans2;
			writeDatasUser(users);
		}
		back2manageUser(uid);
		break;
	}
	case 51: {
		//TODO
		vector<user> users, res;
		readDatasUser(users);
		int idx = -1;
		idx = searchUserID(uid, users, res);
		string info1 = "请输入充值金额，金额不可以0开头（01之间的小数除外）：";
		printInfo(info1);
		string price;
		cin >> price;
		// 判断金额是否合法
		l5:int flag = 1;
		int decNum = 0;
		if (price.length() >= 2 && price[0] == '0' && price[1] != '.') flag = 0;
		for (int i = 0; i < price.length(); i++) {
			if (price[i] < '0' || price[i] > '9') {
				if (price[i] == '.' && decNum == 0 && i != price.length() - 1) {
					decNum++;
					continue;
				}
				else {
					flag = 0;
					break;
				}
			}
		}
		if (flag == 0) {
			int res4[2] = { 0 };
			string info4 = "您输入的价钱格式有误，请重新输入：";
			printInfo(info4);
			cin >> price;
			goto l5;
		}
		users[idx].userBalance = controlDigits(to_string(atof(users[idx].userBalance.c_str()) + atof(price.c_str())));
		writeDatasUser(users);
		vector<record> records;
		readDatasRecord(records);
		// 维护充值记录
		time_t curtime;
		time(&curtime);
		tm* nowtime = localtime(&curtime);
		string day = to_string(1900 + nowtime->tm_year) + "-" + to_string(nowtime->tm_mon + 1) + "-" + to_string(nowtime->tm_mday);
		record tmp;
		tmp.price = controlDigits(price);
		tmp.day = day;
		tmp.userID = uid;
		records.push_back(tmp);
		writeDatasRecord(records);
		string info5 = "充值成功，当前余额为：" + users[idx].userBalance;
		printInfo(info5);
		back2manageUser(uid);
		break;
	}
	case 52: {
		//TODO
		showRefillRecord(uid);
		back2manageUser(uid);
		break;
	}
	case 53: {
		Sleep(100);
		system("cls");
		userOp(uid);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(500);
		system("cls");
		manageUserInformation(uid);
	}
	}
}


void sendMessage(string& uid) {
	int res1[2] = { 0 };
	int res2[2] = { 0 };
	string info1 = "请输入接收人的用户ID：";
	string info2 = "请输入发送内容：";
	printInfo(info1);
	appGetXY(res1);
	printInfo(info2);
	appGetXY(res2);
	string ans1, ans2;
	gotoxy(res1[0], res1[1]);
	cin >> ans1;
	gotoxy(res2[0], res2[1]);
	cin >> ans2;
	vector<user> users, res;
	readDatasUser(users);
	int idx = -1;
	idx = searchUserID(ans1, users, res);
	if (res.size() > 0) {
		vector<msg> msgs;
		readDatasMsg(msgs);
		msg tmp;
		tmp.sender = uid;
		tmp.receiver = ans1;
		tmp.content = ans2;
		msgs.push_back(tmp);
		writeDatasMsg(msgs);
		string info3 = "发送成功";
		printInfo(info3);
		back2message(uid);
	}
	else {
		string info4 = "未找到该用户，是否重新发送？[y/n] ";
		printInfo(info4);
		string ans4 = handleInvalidInput_yn();
		if (ans4 == "y") {
			sendMessage(uid);
		}
		else if (ans4 == "n") {
			back2message(uid);
		}
	}
}


void printReceivedMessage(string uid, vector<msg>& msgs) {
	cout << endl;
	printDisplay2();
	string str = "发件人     内容";
	cout << endl;
	for (int i = 0; i < 77; i++) {
		cout << " ";
	}
	cout << str << endl;
	for (int i = 0; i < msgs.size(); i++) {
		if (msgs[i].receiver == uid) {
			cout << "                                                                             ";
			cout << msgs[i].sender << "       " << msgs[i].content << endl;
		}
	}
	printDisplay2();
}


void message(string uid) {
	printDisplay();
	cout << endl;
	string str = "1.发送留言     2.查看收到的留言     3.返回用户主界面";
	for (int i = 0; i < 20; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "请输入操作：";
	printInfo(info1);
	int res1[2] = { 0 };
	appGetXY(res1);
	string tmpOperation;
	gotoxy(res1[0], res1[1]);
	cin >> tmpOperation;
	int operation = string2ascii(tmpOperation);
	switch (operation) {
	case 49: {
		//TODO
		sendMessage(uid);
		break;
	}
	case 50: {
		//TODO
		vector<msg>msgs, res;
		readDatasMsg(msgs);
		printReceivedMessage(uid, msgs);
		back2message(uid);
		break;
	}
	case 51: {
		//TODO
		Sleep(100);
		system("cls");
		userOp(uid);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(500);
		system("cls");
		message(uid);
	}
	}
}


int minDistance(string s1, string s2) {
	int m = s1.length(), n = s2.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	// base case 
	for (int i = 1; i <= m; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= n; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min3(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1);
			}
		}
	}
	// 储存着整个 s1 和 s2 的最小编辑距离
	return dp[m][n];
}


int min3(int a, int b, int c) {
	if (a < b) {
		return a < c ? a : c;
	}
	else {
		return b < c ? b : c;
	}
}


void userOp(string uid) {
	l1: switch (userHome()) {
	case 49:
		//TODO
		Sleep(100);
		system("cls");
		buyer(uid);
		break;
	case 50:
		//TODO
		Sleep(100);
		system("cls");
		seller(uid);
		break;
	case 51:
		//TODO
		Sleep(100);
		system("cls");
		manageUserInformation(uid);
		break;
	case 52:
		Sleep(100);
		system("cls");
		message(uid);
	case 53:
		Sleep(300);
		system("cls");
		marketSystem();
		break;
	default:
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，即将为您返回主界面" << endl;
		Sleep(300);
		system("cls");
		goto l1;
	}
}


void marketSystem() {
	l1: switch (home()) {
	case AD_LOGIN: {
		//TODO
		administratorLogin();
		Sleep(200);
		system("cls");
		administrator();
		break;
	}
	case USER_SIGN_UP: {
		//TODO
		userSignUp();
		break;
	}
	case USER_LOGIN: {
		//TODO
		string uid = "";
		userLogin(uid, 0);
		Sleep(200);
		system("cls");
		// int ttt = 0;
		userOp(uid);
		break;
	}
	case EXIT: {
		//TODO
		string info1 = "您已退出程序";
		printInfo(info1);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，即将为您返回主界面" << endl;
		Sleep(300);
		system("cls");
		goto l1;
	}
	}
}

//int main() {
//	int n = home();
//	cout << n;
//	return 0;
//}



