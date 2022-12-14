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
				Sleep(500);
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
				Sleep(500);
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
		Sleep(500);
		system("cls");
		administrator();
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
		string info = "请输入商品名称：";
		printInfo(info);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string cmdName;
		cin >> cmdName;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		searchSimple(cmdName, cmds, res);
		if (res.size() > 0) {
			printCommodities(res);
			back2Ad();
		}
		else {
			printSearchFailed();
			Sleep(700);
			system("cls");
			administrator();
		}
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
			Sleep(700);
			system("cls");
			administrator();
		}
		break;
	}
	case 52: {
		//TODO
		showAllOrders();
		back2Ad();
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
		Sleep(1000);
		system("cls");
		administrator();
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


void showAllCommodities() {
	//cout << "Not implemented";
	vector<cmd> cmds;
	readDatasCmd(cmds);
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
	string str = "订单ID 商品ID   交易单价  数量   交易时间       卖家ID     买家ID";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < orders.size(); i++) {
		cout << "                                             ";
		cout << orders[i].orderID << "     " << orders[i].cmdID << "     " << orders[i].orderPrice << "     " << orders[i].orderNum << "     " << orders[i].orderDay << "       " << orders[i].sellerID << "       " << orders[i].buyerID << endl;
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
		string str = "用户ID 用户名   联系方式       地址           钱包余额     用户状态";
		cout << endl;
		for (int i = 0; i < 15; i++) {
			cout << "   ";
		}
		cout << str << endl;
		for (int i = 0; i < users.size(); i++) {
			cout << "                                             ";
			cout << users[i].userID << "     " << users[i].userName << "     " << users[i].userContact << "     " << users[i].userAdress << "     " << users[i].userBalance << "       " << users[i].userState << endl;
		}
	}
	else if (type == 1) {
		string str = "用户ID 用户名   联系方式       地址           钱包余额";
		cout << endl;
		for (int i = 0; i < 15; i++) {
			cout << "   ";
		}
		cout << str << endl;
		for (int i = 0; i < users.size(); i++) {
			cout << "                                             ";
			cout << users[i].userID << "     " << users[i].userName << "     " << users[i].userContact << "     " << users[i].userAdress << "     " << users[i].userBalance << "       " << endl;
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
		Sleep(500);
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
				Sleep(500);
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
				Sleep(500);
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
	string str = "1. 我是买家     2.我是卖家     3.个人信息管理     4.注销登录";
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


void printCommodities4Buyer(vector<cmd>&cmds) {
	printDisplay2();
	string str = "商品ID     名称                   价格      上架时间          卖家ID";
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
			string blank3 = displayHelper(tmp, 4 - cmds[i].cmdNum.length());
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
	string str = "商品ID       名称                 价格    数量    上架时间           商品状态";
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
			string blank3 = displayHelper(tmp, 4 - cmds[i].cmdNum.length());
			cout << cmds[i].cmdID << "     " << cmds[i].cmdName << "     " + blank1 << cmds[i].cmdPrice << "     " + blank2 << cmds[i].cmdNum << "     " << cmds[i].cmdDay << "       " + blank3 << cmds[i].cmdState << endl;
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
		Sleep(500);
		system("cls");
		buyer(uid);
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
		Sleep(500);
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
				/*CTime t = CTime::GetCurrentTime();
				string year = to_string(p->tm_year);
				string month = to_string(p->tm_mon);
				string day = to_string(p->tm_mday);*/
				/*tmp.orderDay = year + "-" + month + "-" + day;*/
				tmp.orderDay = "2022-02-12";
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
					int tttt = 0;
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
		string info = "请输入商品名称：";
		printInfo(info);
		int res2[2] = { 0 };
		appGetXY(res2);
		gotoxy(res2[0], res2[1]);
		string cmdName;
		cin >> cmdName;
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		searchSimple(cmdName, cmds, res);
		if (res.size() > 0) {
			vector<cmd>res4User;
			for (int i = 0; i < res.size(); i++) {
				if (res[i].cmdState == "销售中") {
					res4User.push_back(res[i]);
				}
			}
			if (res4User.size() > 0) {
				printCommodities4Buyer(res4User);
				back2Buyer(uid);
			}
			else {
				printSearchFailed();
				Sleep(700);
				system("cls");
				buyer(uid);
			}
		}
		else {
			printSearchFailed();
			Sleep(700);
			system("cls");
			buyer(uid);
		}
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
		Sleep(500);
		system("cls");
		userOp(uid);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(1000);
		system("cls");
		buyer(uid);
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
			string tmpd = "2022-02-16";
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
		Sleep(500);
		system("cls");
		userOp(uid);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，请重新输入操作";
		Sleep(1000);
		system("cls");
		seller(uid);
	}
	}
}


void userOp(string uid) {
	l1: switch (userHome()) {
	case 49:
		//TODO
		Sleep(300);
		system("cls");
		buyer(uid);
		break;
	case 50:
		//TODO
		Sleep(300);
		system("cls");
		seller(uid);
		break;
	case 51:
		//TODO
		break;
	case 52:
		Sleep(600);
		system("cls");
		marketSystem();
		break;
	default:
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，即将为您返回主界面" << endl;
		Sleep(1000);
		system("cls");
		goto l1;
	}
}


void marketSystem() {
	l1: switch (home()) {
	case AD_LOGIN:
		//TODO
		administratorLogin();
		Sleep(1000);
		system("cls");
		administrator();
		break;
	case USER_SIGN_UP:
		//TODO
		userSignUp();
		break;
	case USER_LOGIN: {
		//TODO
		string uid = "";
		userLogin(uid, 0);
		Sleep(1000);
		system("cls");
		// int ttt = 0;
		userOp(uid);
		break;
	}
	case EXIT:
		//TODO
		cout << "Not Implemented";
		break;
	default:
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "没有该操作，即将为您返回主界面" << endl;
		Sleep(1000);
		system("cls");
		goto l1;
	}
}

//int main() {
//	int n = home();
//	cout << n;
//	return 0;
//}



