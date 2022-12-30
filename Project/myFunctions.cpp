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
			string info6 = "�Ƿ��˳���¼��[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "�����µ�¼";
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
			string info6 = "�Ƿ��˳���¼��[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "�����µ�¼";
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
			cout << "���벻�Ϸ���������1��2��ѡ��һ��������";
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
			cout << "���벻�Ϸ���������1��2��3��ѡ��һ��������";
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
		Sleep(100);
		system("cls");
		administrator();
	}
}


void back2AdSearch() {
	int res2[2] = { 0 };
	cout << endl;
	string info1 = "��y���ع���Ա�������棺";
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
	string info1 = "��y���ظ�����Ϣ������棺";
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
	string info1 = "��y���ض������ҽ��棺";
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
	string info1 = "��y���ظ�����Ϣ������棺";
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
	string str = "1.����Ʒ��������     2.����Ʒ�۸���������     3.����Ʒ��������     4.���ع���Ա��������";
	for (int i = 0; i < 20; i++) {
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
		string info = "��������Ʒ���ƣ�";
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
		string info1 = "��������ͼ۸���Ʒ�۸񲻿���0��ͷ��01֮���С�����⣩��";
		string info2 = "��������߼۸���Ʒ�۸񲻿���0��ͷ��01֮���С�����⣩��";
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
		// �������۸��Ƿ�Ϸ�
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
			string info3 = "���������ͼ۸��ʽ�������������룺";
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
			string info4 = "���������߼۸��ʽ�������������룺";
			printInfo(info4);
			cin >> price2;
			goto l2;
		}
		// �ж���ͼ۸��Ƿ�С�ڵ�����߼۸�
		if (atof(price1.c_str()) > atof(price2.c_str())) {
			string info7 = "��߼۸������ڵ�����ͼ۸�������������߼۸�";
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
		string info1 = "��������Ʒ������";
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
		cout << "û�иò������������������";
		Sleep(300);
		system("cls");
		adSearch();
	}
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
		Sleep(100);
		system("cls");
		adSearch();
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
			string info3 = "��ѡ��[y/n] ";
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
				writeDatasCmd(cmds);
			}
			else if (ans == "n") {
				string info5 = "ȡ���¼�";
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
				string info5 = "��ѡ��[y/n] ";
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
						string info3 = "�ѽ������������û���δ������Ʒ������޷��¼�����Ʒ";
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
		Sleep(500);
		system("cls");
		administrator();
	}
	}
}


void adSearchOrder() {
	printDisplay();
	cout << endl;
	string str = "1.ֱ�Ӳ鿴���ж���     2.�鿴ĳһ�û��Ķ���     3.���ع���Ա������";
	for (int i = 0; i < 20; i++) {
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
		showAllOrders();
		back2AdSearchOrder();
		break;
	}
	case 50: {
		//TODO
		string info = "������һ���û�ID��";
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
		cout << "û�иò������������������";
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


void printSearchFailed2() {
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << "   ";
	}
	for (int i = 0; i < 50; i++) {
		cout << "*";
	}
	string info2 = "û���ҵ��漰�����û��Ķ��������س�ʼ����";
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


// ����Ҫ���һ��������;�ļ��ͽ����˵�����
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
	string str = "��ƷID     ����                   �۸�       �ϼ�ʱ��     ����       ����ID     ��Ʒ״̬";
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
	string str = "��ֵ���     ��ֵʱ��";
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
		string info1 = "δ��ѯ������ֵ��¼";
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
		// ����Ʒ��С�ڵ���50���򷵻ر༭����ǰ1/5����Ʒ
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
		// ����Ʒ������50С�ڵ���500���򷵻�ǰ1/10����Ʒ
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
		// ����Ʒ������500���򷵻�ǰ1/100����Ʒ
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
		// ����Ʒ��С�ڵ���50���򷵻ر༭����ǰ1/5����Ʒ
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
		// ����Ʒ������50С�ڵ���500���򷵻�ǰ1/10����Ʒ
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
		// ����Ʒ������500���򷵻�ǰ1/100����Ʒ
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
	string str = "����ID  ��ƷID   ���׵���    ����      ����ʱ��        ����ID     ���ID";
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
	string info1 = "�漰�����û��Ķ������£�";
	printInfo(info1);
	cout << endl;
	printDisplay2();
	string str = "����ID  ��ƷID   ���׵���    ����      ����ʱ��        ����ID     ���ID";
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
		string str = "�û�ID  �û���    ��ϵ��ʽ          ��ַ                   Ǯ�����      �û�״̬";
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
		string str = "�û�ID  �û���    ��ϵ��ʽ          ��ַ                   Ǯ�����";
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
	string u = "U";
	tmp.userID = u + getID(nn);
	tmp.userName = userNamee;
	tmp.userContact = number;
	tmp.userAdress = adress;
	tmp.userBalance = "0.0";
	tmp.userState = "����";
	tmp.userCode = code;
	users.push_back(tmp);
	// int ttt = 0;
	writeDatasUser(users);
	string info13 = "ע��ɹ�����y�������˵���";
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
		string info1 = "�������û�����";
		printInfo(info1);
		appGetXY(res1);
		string info2 = "���������룺";
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
			string info3 = "-----��¼�ɹ�-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----��¼ʧ��-----";
			printInfo(info4);
			string info6 = "�Ƿ��˳���¼��[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "�����µ�¼";
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
		string info1 = "���ٴ������û�����";
		printInfo(info1);
		appGetXY(res1);
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		string info2 = "���ٴ��������룺";
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
			string info3 = "-----��¼�ɹ�-----";
			printInfo(info3);
		}
		else {
			string info4 = "-----��¼ʧ��-----";
			printInfo(info4);
			string info6 = "�Ƿ��˳���¼��[y/n] ";
			cout << endl;
			printInfo(info6);
			string ans = handleInvalidInput_yn();
			if (ans == "n") {
				string info5 = "�����µ�¼";
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
	string str = "1. �������     2.��������     3.������Ϣ����     4.����     5.ע����¼";
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
	cout << "�����������";
	string operation;
	cin >> operation;
	int res = string2ascii(operation);
	return res;
}


void printCommodities4Buyer(vector<cmd>&cmds) {
	printDisplay2();
	string str = "��ƷID     ����                   �۸�      �ϼ�ʱ��        ����ID";
	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << "   ";
	}
	cout << str << endl;
	for (int i = 0; i < cmds.size(); i++) {
		if (cmds[i].cmdState == "������") {
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
	string str = "��ƷID       ����                 �۸�    ����       �ϼ�ʱ��        ��Ʒ״̬";
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
	string info1 = "��y������Ҳ������棺";
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
	string info1 = "��y��������������棺";
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
	string info1 = "��y�������Ҳ������棺";
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
	string str = "1.�鿴��Ʒ�б�     2.������Ʒ     3.������Ʒ     4.�鿴��ʷ����     5.�鿴��Ʒ��ϸ��Ϣ     6.�����û�������";
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
		showAllCommodities4Buyer();
		back2Buyer(uid);
		break;
	}
	case 50: {
		//TODO
		int res1[2] = { 0 };
		int res2[2] = { 0 };
		string info1 = "��������ƷID��";
		printInfo(info1);
		appGetXY(res1);
		string info2 = "������������������������Ϊ0�Ҳ�����0��ͷ����";
		printInfo(info2);
		appGetXY(res2);
		string id, num;
		gotoxy(res1[0], res1[1]);
		cin >> id;
		gotoxy(res2[0], res2[1]);
		cin >> num;
		// ���num�����Ƿ�Ϸ�
		l1:for (int i = 0; i < num.length(); i++) {
			if (num[0] == '0' || num[i] > '9' || num[i] < '0') {
				string info3 = "�����������Ϸ������������룺";
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
		if (idx >= 0 && res[0].cmdState == "������") {
			if (atof(res[0].cmdNum.c_str()) < atof(num.c_str())) {
				string info7 = "��Ǹ������Ʒ��ʣ"+res[0].cmdNum+"����������ļ�������ʣ����";
				printInfo(info7);
			}
			else if (atof(num.c_str()) * atof(res[0].cmdPrice.c_str()) > atof(thisUser[0].userBalance.c_str())) {
				string info4 = "��������";
				printInfo(info4);
			}
			else {
				// ����ɹ������¶����ļ�
				order tmp;
				tmp.buyerID = uid;
				tmp.cmdID = id;
				// ����ϵͳ������ȡ��ǰʱ��
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
				// �����û��ļ�-���
				// int tt = 0;
				users[idxx].userBalance = to_string(atof(thisUser[0].userBalance.c_str()) - atof(num.c_str()) * atof(res[0].cmdPrice.c_str()));
				// �����û��ļ�-����
				int idx2 = -1;
				vector<user>resus;
				idx2 = searchUserID(res[0].sellerID, users, resus);
				if (idx2 != -1) {
					// int tttt = 0;
					users[idx2].userBalance = to_string(atof(resus[0].userBalance.c_str()) + atof(num.c_str()) * atof(res[0].cmdPrice.c_str()));
				}
				writeDatasUser(users);
				// ������Ʒ�ļ�
				cmds[idx].cmdNum = to_string(atoi(cmds[idx].cmdNum.c_str()) - atoi(num.c_str()));
				if (atof(cmds[idx].cmdNum.c_str()) == 0) {
					cmds[idx].cmdState = "������";
				}
				writeDatasCmd(cmds);
				string info8 = "����ɹ��������ڶ����в鿴�ö���";
				printInfo(info8);
			}
		}
		else {
			cout << endl;
			string info6 = "��Ǹ��δ�ҵ���Ӧ����Ʒ";
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
		string info1 = "����������Ҫ�鿴����ƷID��";
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
			if (res[0].cmdState != "������") {
				string info3 = "��Ǹ������Ʒ�ݲ�����";
				printInfo(info3);
			}
			else displayDiscriptionofCmd(res);
			back2Buyer(uid);
		}
		else {
			string info2 = "��Ǹ��δ���ҵ������Ʒ";
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
		cout << "û�иò������������������";
		Sleep(500);
		system("cls");
		buyer(uid);
	}
	}
}


void buyerSearch(string& uid) {
	printDisplay();
	cout << endl;
	string str = "1.����Ʒ��������     2.����Ʒ��������     3.����Ʒ�۸���������     4.����Ʒ��������     5.�������������";
	for (int i = 0; i < 20; i++) {
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
		string info = "��������Ʒ���ƣ�";
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
				if (res[i].cmdState == "������") {
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
		string info = "��������Ʒ����ID��";
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
				if (res[i].cmdState == "������") {
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
		string info1 = "��������ͼ۸���Ʒ�۸񲻿���0��ͷ��01֮���С�����⣩��";
		string info2 = "��������߼۸���Ʒ�۸񲻿���0��ͷ��01֮���С�����⣩��";
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
		// �������۸��Ƿ�Ϸ�
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
			string info3 = "���������ͼ۸��ʽ�������������룺";
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
			string info4 = "���������߼۸��ʽ�������������룺";
			printInfo(info4);
			cin >> price2;
			goto l2;
		}
		// �ж���ͼ۸��Ƿ�С�ڵ�����߼۸�
		if (atof(price1.c_str()) > atof(price2.c_str())) {
			string info7 = "��߼۸������ڵ�����ͼ۸�������������߼۸�";
			printInfo(info7);
			cin >> price2;
			goto l2;
		}
		vector<cmd> cmds, res;
		readDatasCmd(cmds);
		for (int i = 0; i < cmds.size(); i++) {
			if (atof(cmds[i].cmdPrice.c_str()) >= atof(price1.c_str()) && atof(cmds[i].cmdPrice.c_str()) <= atof(price2.c_str()) && cmds[i].cmdState=="������") {
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
		string info1 = "��������Ʒ������";
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
			if (res[i].cmdState == "������") {
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
		cout << "û�иò������������������";
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
	string info1 = "��ƷID��" + res[0].cmdID;
	string info2 = "��Ʒ���ƣ�" + res[0].cmdName;
	string info3 = "��Ʒ�۸�" + res[0].cmdPrice;
	string info4 = "�ϼ�ʱ�䣺" + res[0].cmdDay;
	string info5 = "��Ʒ������" + res[0].cmdDiscription;
	string info6 = "��Ʒ���ң�" + res[0].sellerID;
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
	string info1 = "��ƷID��" + res[0].cmdID;
	string info2 = "��Ʒ���ƣ�" + res[0].cmdName;
	string info3 = "��Ʒ�۸�" + res[0].cmdPrice;
	string info5 = "��Ʒ������" + res[0].cmdDiscription;
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
	string str = "1.������Ʒ     2.�鿴������Ʒ     3.�޸���Ʒ��Ϣ     4.�¼���Ʒ     5.�鿴��ʷ����    6.�����û�������";
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
		int times = 0;
		string info1 = "��������Ʒ���ƣ�";
		string info2 = "��������Ʒ�۸���Ʒ�۸񲻿���0��ͷ��01֮���С�����⣩��";
		string info3 = "��������Ʒ��������Ʒ��������Ϊ0�Ҳ�����0��ͷ��";
		string info4 = "��������Ʒ������";
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
		// �жϼ۸��Ƿ�Ϸ�
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
			string info13 = "������ļ�Ǯ��ʽ�������������룺";
			printInfo(info13);
			cin >> price;
			goto l1;
		}
		printInfo(info3);
		appGetXY(res3);
		gotoxy(res3[0], res3[1]);
		cin >> num;
		// �ж������Ƿ�Ϸ�
		l3:for (int i = 0; i < num.length(); i++) {
			if (num[0] == '0' || num[i] > '9' || num[i] < '0') {
				string info14 = "�����������Ϸ������������룺";
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
		string info5 = "��ȷ�Ϸ�������Ʒ��Ϣ����";
		cout << endl;
		printDisplay2();
		string info6 = "��Ʒ���ƣ�" + name;
		string info7 = "��Ʒ�۸�" + controlDigits(price);
		string info8 = "��Ʒ������" + num;
		string info9 = "��Ʒ������" + discription;
		printInfo(info6);
		printInfo(info7);
		printInfo(info8);
		printInfo(info9);
		cout << endl;
		printDisplay2();
		cout << endl;
		string info10 = "��ȷ��Ҫ������Ʒ��[y/n] ";
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
			tmp.cmdState = "������";
			tmp.cmdDiscription = discription;
			cmds.push_back(tmp);
			writeDatasCmd(cmds);
			string info11 = "��Ʒ�����ɹ���";
			printInfo(info11);
		}
		else if (ans == "n") {
			string info12 = "ȡ������";
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
		string info1 = "�����뱻�޸���Ʒ��ID��";
		string info2 = "�����뱻�޸���Ʒ�����ԣ�1.�۸�  2.��������";
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
				string info3 = "�����뱻�޸���Ʒ�ļ۸���Ʒ�۸񲻿���0��ͷ��01֮���С�����⣩��";
				printInfo(info3);
				appGetXY(res3);
				gotoxy(res3[0], res3[1]);
				cin >> price;
				// �жϼ۸��Ƿ��ʽ��ȷ
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
					string info4 = "������ļ�Ǯ��ʽ�������������룺";
					printInfo(info4);
					cin >> price;
					goto l2;
				}
				string info5 = "��ȷ���޸ĵ���Ʒ��Ϣ����";
				printInfo(info5);
				cout << endl;
				vector<cmd>ress;
				cmd tmp = res[0];
				tmp.cmdPrice = controlDigits(price);
				ress.push_back(tmp);
				displayDiscriptionofCmd4Seller(ress);
				cout << endl;
				string info6 = "ȷ���޸ģ�[y/n] ";
				printInfo(info6);
				string ans;
				ans = handleInvalidInput_yn();
				if (ans == "y") {
					cmds[idx].cmdPrice = price;
					writeDatasCmd(cmds);
					string info7 = "�޸ĳɹ���";
					printInfo(info7);
				}
				else if (ans == "n") {
					string info8 = "��ȡ���޸�";
					printInfo(info8);
				}
			}
			else if (attribute == "2") {
				int res9[2] = { 0 };
				string info9 = "�����뱻�޸���Ʒ��������";
				printInfo(info9);
				appGetXY(res9);
				string discription;
				gotoxy(res9[0], res9[1]);
				cin >> discription;
				string ans;
				string info15 = "ȷ���޸ģ�[y/n] ";
				printInfo(info15);
				ans = handleInvalidInput_yn();
				if (ans == "y") {
					cmds[idx].cmdDiscription = discription;
					writeDatasCmd(cmds);
					string info10 = "�޸ĳɹ���";
					printInfo(info10);
				}
				else if (ans == "n") {
					string info11 = "��ȡ���޸�";
					printInfo(info11);
				}
			}
		}
		else if(res.size()==0) {
			string info12 = "δ�ҵ�����Ʒ������Ϊ���������Ҳ�������";
			printInfo(info12);
		}
		else if (res[0].sellerID != uid) {
			string info13 = "�����߱��޸ĸ���Ʒ��Ȩ�ޣ���Ϊ�����Ǹ���Ʒ�ķ�����";
			printInfo(info13);
		}
		back2Seller(uid);
		break;
	}
	case 52: {
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
		if (res.size() > 0 && res[0].sellerID==uid && res[0].cmdState!="���¼�") {
			string info2 = "ȷ��Ҫ�¼ܸ���Ʒ��";
			printInfo(info2);
			cout << endl;
			printCommodities(res);
			string info3 = "��ѡ��[y/n] ";
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
				writeDatasCmd(cmds);
			}
			else if (ans == "n") {
				string info5 = "ȡ���¼�";
				printInfo(info5);
			}
		}
		else if(res.size()==0) {
			string info12 = "δ�ҵ�����Ʒ������Ϊ���������Ҳ�������";
			printInfo(info12);
		}
		else if (res[0].sellerID != uid) {
			string info13 = "�����߱��¼ܸ���Ʒ��Ȩ�ޣ���Ϊ�����Ǹ���Ʒ�ķ�����";
			printInfo(info13);
		}
		else if (res[0].cmdState == "���¼�") {
			string info14 = "����Ʒ�ڴ�֮ǰ�Ѿ����¼ܣ������ظ��¼�";
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
		cout << "û�иò������������������";
		Sleep(500);
		system("cls");
		seller(uid);
	}
	}
}


void manageUserInformation(string uid) {
	printDisplay();
	cout << endl;
	string str = "1.�鿴��Ϣ     2.�޸���Ϣ     3.��ֵ    4.�鿴��ֵ��¼     5.�����û�������";
	for (int i = 0; i < 20; i++) {
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
		vector<user> users, res;
		readDatasUser(users);
		int idx = -1;
		idx = searchUserID(uid, users, res);
		cout << endl;
		printDisplay2();
		string info1 = "�û�����" + res[0].userName;
		string info2 = "��ϵ��ʽ��" + res[0].userContact;
		string info3 = "��ַ��" + res[0].userAdress;
		string info4 = "Ǯ����" + res[0].userBalance;
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
		string info1 = "��ѡ���޸ĵ����ԣ�1.�û���  2.��ϵ��ʽ  3.��ַ����";
		printInfo(info1);
		string ans = handleInvalidInput_123();
		if (ans == "1") {
			vector<user> users, res;
			readDatasUser(users);
			int idx = -1;
			idx = searchUserID(uid, users, res);
			int res2[2] = { 0 };
			string info2 = "��ѡ���޸ĺ���û���";
			printInfo(info2);
			appGetXY(res2);
			string ans;
			gotoxy(res2[0], res2[1]);
			cin >> ans;
			// ����Ƿ��������û����ظ�
			l2:int flag = 1;
			for (int i = 0; i < users.size(); i++) {
				if (users[i].userName == ans && i != idx) {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				int res4[2] = { 0 };
				string info13 = "���û����ѱ�ռ�ã����������룺";
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
			string info2 = "�������޸ĺ����ϵ��ʽ��";
			printInfo(info2);
			appGetXY(res2);
			string ans2;
			gotoxy(res2[0], res2[1]);
			cin >> ans2;
			// �жϵ绰�����ʽ�Ƿ���ȷ
			l1:int flag = 1;
			for (int i = 0; i < ans2.length(); i++) {
				if (ans2[i] > '9' || ans2[i] < '0') {
					flag = 0;
					break;
				}
			}
			if (flag == 0) {
				int res4[2] = { 0 };
				string info13 = "������ĵ绰�����ʽ�������������룺";
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
			string info2 = "�������޸ĺ�ĵ�ַ";
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
		string info1 = "�������ֵ��������0��ͷ��01֮���С�����⣩��";
		printInfo(info1);
		string price;
		cin >> price;
		// �жϽ���Ƿ�Ϸ�
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
			string info4 = "������ļ�Ǯ��ʽ�������������룺";
			printInfo(info4);
			cin >> price;
			goto l5;
		}
		users[idx].userBalance = controlDigits(to_string(atof(users[idx].userBalance.c_str()) + atof(price.c_str())));
		writeDatasUser(users);
		vector<record> records;
		readDatasRecord(records);
		// ά����ֵ��¼
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
		string info5 = "��ֵ�ɹ�����ǰ���Ϊ��" + users[idx].userBalance;
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
		cout << "û�иò������������������";
		Sleep(500);
		system("cls");
		manageUserInformation(uid);
	}
	}
}


void sendMessage(string& uid) {
	int res1[2] = { 0 };
	int res2[2] = { 0 };
	string info1 = "����������˵��û�ID��";
	string info2 = "�����뷢�����ݣ�";
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
		string info3 = "���ͳɹ�";
		printInfo(info3);
		back2message(uid);
	}
	else {
		string info4 = "δ�ҵ����û����Ƿ����·��ͣ�[y/n] ";
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
	string str = "������     ����";
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
	string str = "1.��������     2.�鿴�յ�������     3.�����û�������";
	for (int i = 0; i < 20; i++) {
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
		cout << "û�иò������������������";
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
	// ���������� s1 �� s2 ����С�༭����
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
		cout << "û�иò���������Ϊ������������" << endl;
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
		string info1 = "�����˳�����";
		printInfo(info1);
		break;
	}
	default: {
		for (int i = 0; i < 10; i++) {
			cout << "   ";
		}
		cout << "û�иò���������Ϊ������������" << endl;
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



