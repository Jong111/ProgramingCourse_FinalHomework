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


#define AD_LOGIN 49
#define USER_SIGN_UP 50
#define USER_LOGIN 51
#define EXIT 52


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
		string info1 = "请输入管理员姓名：";
		printInfo(info1);
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
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
			string info5 = "请重新登录";
			printInfo(info5);
			administratorLogin();
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
			string info5 = "请重新登录";
			printInfo(info5);
			administratorLogin();
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
			string info3 = "请选择[y/n]";
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
			}
			if (ans == "n") {
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
				string info5 = "请选择[y/n]";
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
						string info3 = "该用户暂未发布商品，因此无法下架其商品";
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


int searchUserID(string userId, vector<user>users, vector<user>res) {
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
		f >> temp.sellerID;
		f >> temp.cmdNum;
		f >> temp.cmdState;
		cmds.push_back(temp);
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
	for (int i = 0; i < cmds.size(); i++) {
		of << cmds[i].cmdID << ' ' << cmds[i].cmdName << ' ' << cmds[i].cmdPrice << ' ' << cmds[i].cmdDay << ' ' << cmds[i].cmdNum << ' ' << cmds[i].sellerID << ' ' << cmds[i].cmdState << endl;
	}
	of.close();
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
		orders.push_back(temp);
	}
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
		f >> temp.userID;
		f >> temp.userName;
		f >> temp.userContact;
		f >> temp.userAdress;
		f >> temp.userBalance;
		f >> temp.userState;
		users.push_back(temp);
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
	for (int i = 0; i < users.size(); i++) {
		of << users[i].userID << ' ' << users[i].userName << ' ' << users[i].userContact << ' ' << users[i].userAdress << ' ' << users[i].userBalance << ' ' << users[i].userState << endl;
	}
	of.close();
}


void userSignUp() {
	vector<user>users;
	readDatasUser(users);
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
	vector<string> message;
	string u = "U";
	tmp.userID = u + getUserID(users.size());
	tmp.userName = userNamee;
	tmp.userContact = number;
	tmp.userAdress = adress;
	tmp.userBalance = "0.0";
	tmp.userState = "正常";
	tmp.userCode = code;
	tmp.userMessage = message;
	users.push_back(tmp);
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


string getUserID(int n) {
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
	case USER_LOGIN:
		//TODO
		cout << "Not Implemented";
		break;
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



