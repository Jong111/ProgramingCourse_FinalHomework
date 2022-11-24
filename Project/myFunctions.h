#pragma once
#include<vector>
#include<string>
using namespace std;

typedef struct {
	string cmdID;
	string cmdName;
	string cmdPrice;
	string cmdDay;
	string sellerID;
	string cmdNum;
	string cmdState;
} cmd;

extern int adLoginTimes;
extern void appGetXY(int* res);
extern void gotoxy(int x, int y);
extern int string2ascii(string& str);
extern int digit(int a);
extern void printDisplay();
extern int home();
extern void administratorLogin();
extern void administrator();
extern void showAllCommodities();
extern void printCommodities(vector<cmd>& cmds);
//extern cmd;
extern void readDatas(vector<cmd>& cmds);
extern void searchSimple(string& str, vector<cmd>cmds, vector<cmd>& res);
extern int strIn(string& str1, string& str2);
