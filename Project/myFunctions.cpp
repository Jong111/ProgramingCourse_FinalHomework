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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
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
	string str = "1. ����Ա��¼     2.�û�ע��     3.�û���¼     4.�˳�����";
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
	cout << "�����������";
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
		string info1 = "���������Ա������";
		printInfo(info1);
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		string info2 = "���������Ա���룺";
		printInfo(info2);
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		if (ans1 == "admin" && ans2 == "123456") {
			string info3 = "-----��¼�ɹ�-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----��¼ʧ��-----";
			printInfo(info4);
			string info5 = "�����µ�¼";
			printInfo(info5);
			administratorLogin();
		}
	}
	else {
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		string info1 = "���ٴ��������Ա������";
		printInfo(info1);
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		string info2 = "���ٴ��������Ա���룺";
		printInfo(info2);
		appGetXY(res2);
		string ans1, ans2;
		gotoxy(res1[0], res1[1]);
		cin >> ans1;
		gotoxy(res2[0], res2[1]);
		cin >> ans2;
		if (ans1 == "admin" && ans2 == "123456") {
			string info3 = "-----��¼�ɹ�-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----��¼ʧ��-----";
			printInfo(info4);
			string info5 = "�����µ�¼";
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
			string info2 = "���벻�Ϸ������������룺";
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
			cout << "���벻�Ϸ������������룺";
			int res4[2] = { 0 };
			appGetXY(res4);
			gotoxy(res4[0], res4[1]);
		}
	}
}


void back2Ad() {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "��y���ع���Ա�������棺";
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
	string str = "1.�鿴������Ʒ     2.������Ʒ     3.�¼���Ʒ     4.�鿴���ж���     5.�鿴�����û�     6.����û�     7.ע��";
	for (int i = 0; i < 12; i++) {
		cout << "   ";
	}
	cout << str;
	cout << endl;
	printDisplay();
	cout << endl << endl;
	string info1 = "�����������";
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
		string info = "��������Ʒ���ƣ�";
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
		string info1 = "������Ҫ�¼ܵ���ƷID��";
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
			string info2 = "ȷ��Ҫ�¼ܸ���Ʒ��";
			printInfo(info2);
			cout << endl;
			printCommodities(res);
			string info3 = "��ѡ��[y/n]";
			printInfo(info3);
			int res3[2] = { 0 };
			appGetXY(res3);
			gotoxy(res3[0], res3[1]);
			string ans;
			ans = handleInvalidInput_yn();
			if (ans == "y") {
				string info4 = "��Ʒ�¼ܳɹ�";
				printInfo(info4);
				/*cmds.erase(cmds.begin() + idx);
				writeDatasCmd(cmds);*/
				cmds[idx].cmdState = "���¼�";
			}
			if (ans == "n") {
				string info5 = "ȡ���¼�";
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
		string info1 = "������Ҫ������û�ID��";
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
			if (users[idx].userState == "���") {
				string info7 = "���û��ѱ����";
				printInfo(info7);
				back2Ad();
			}
			else {
				string info2 = "ȷ��Ҫ������û���";
				printInfo(info2);
				cout << endl;
				vector<user> user_vec;
				user_vec.push_back(users[idx]);
				printUsers(user_vec, 1);
				string info5 = "��ѡ��[y/n]";
				printInfo(info5);
				int res3[2] = { 0 };
				appGetXY(res3);
				gotoxy(res3[0], res3[1]);
				string ans;
				ans = handleInvalidInput_yn();
				if (ans == "y") {
					cout << endl;
					users[idx].userState = "���";
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
					// ���û�δ��������Ʒ
					if (toBeTakeOff.size() == 0) {
						string info3 = "���û���δ������Ʒ������޷��¼�����Ʒ";
						printInfo(info3);
						back2Ad();
					}
					// ���û���������Ʒ
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
								cmds[tempp].cmdState = "���¼�";
							}
						}
						writeDatasCmd(cmds);
						string info8 = "����ɹ�";
						printInfo(info8);
						back2Ad();
					}
				}
				else if (ans == "n") {
					string info4 = "ȡ�����";
					printInfo(info4);
					back2Ad();
				}
			}
		}
		else {
			string info6 = "δ�ҵ����û�";
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
		cout << "û�иò������������������";
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
	string info2 = "û���ҵ�����Ҫ����Ʒ�����س�ʼ����";
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

// Read datas from commodity.txt to cmds, ����Ҫ���һ��������;�ļ��ͽ����˵�����
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


// ����Ҫ���һ��������;�ļ��ͽ����˵�����
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
	string str = "��ƷID     ����           �۸�      �ϼ�ʱ��     ����ID     ����     ��Ʒ״̬";
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
	string str = "����ID ��ƷID   ���׵���  ����   ����ʱ��       ����ID     ���ID";
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
		string str = "�û�ID �û���   ��ϵ��ʽ       ��ַ           Ǯ�����     �û�״̬";
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
		string str = "�û�ID �û���   ��ϵ��ʽ       ��ַ           Ǯ�����";
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
	string info1 = "�������û������û���������10���ַ�����";
	int res1[2] = { 0 };
	int res2[2] = { 0 };
	int res3[2] = { 0 };
	printInfo(info1);
	appGetXY(res1);
	string info2 = "���������루���벻����20����Ч�ַ�����";
	printInfo(info2);
	appGetXY(res2);
	string info3 = "���ٴ��������룺";
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
		string info4 = "�û����Ѵ��ڣ����������룺";
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
		string info5 = "�������벻һ�£����������룺";
		printInfo(info5);
		appGetXY(res5);
		string info6 = "���ٴ�ȷ�ϣ�";
		printInfo(info6);
		appGetXY(res6);
		gotoxy(res5[0], res5[1]);
		cin >> code;
		gotoxy(res6[0], res6[1]);
		cin >> codeAgain;
		goto l6;
	}
	l7:if (userNamee.length() > 10) {
		string info7 = "�û������������������룺";
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
		string info8 = "������������������룺";
		string info9 = "���ٴ�ȷ�ϣ�";
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
	string info10 = "������������ĸ�����Ϣ���ע��";
	printInfo(info10);
	int res10[2] = { 0 };
	int res11[2] = { 0 };
	string info11 = "���������ĵ绰���룺";
	string info12 = "���������ĵ�ַ��";
	printInfo(info11);
	appGetXY(res10);
	printInfo(info12);
	appGetXY(res11);
	gotoxy(res10[0], res10[1]);
	string number, adress;
	// ���ﻹû�жԵ绰����͵�ַ�ĸ�ʽ�����ж�
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
	tmp.userState = "����";
	tmp.userCode = code;
	tmp.userMessage = message;
	users.push_back(tmp);
	writeDatasUser(users);
	string info13 = "ע��ɹ�����y�������˵���";
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
		cout << "û�иò���������Ϊ������������" << endl;
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



