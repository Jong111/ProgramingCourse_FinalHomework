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
	string cmdDiscription;
} cmd;


typedef struct {
	string orderID;
	string cmdID;
	string orderPrice;
	string orderNum;
	string orderDay;
	string sellerID;
	string buyerID;
} order;


typedef struct {
	string userID;
	string userName;
	string userContact;
	string userAdress;
	string userBalance;
	string userState;
	string userCode;
	/*int messageNum;
	vector<string> userMessage;*/
}user;

extern int adLoginTimes;
extern int userLoginTimes;
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
extern void readDatasCmd(vector<cmd>& cmds);
extern void writeDatasCmd(vector<cmd>& cmds);
extern void searchSimple(string& str, vector<cmd>cmds, vector<cmd>& res);
extern int searchCmdID(string cmdId, vector<cmd>& cmds, vector<cmd>& res);
extern int strIn(string& str1, string& str2);
extern void back2Ad();
extern void printInfo(string& str);
extern void printSearchFailed();
extern string handleInvalidInput_y();
extern string handleInvalidInput_yn();
extern void readDatasOrder(vector<order>& orders);
extern void showAllOrders();
extern void printOrders(vector<order>& orders);
extern void printUsers(vector<user>& users, int type);
extern void showAllUsers();
extern void readDatasUser(vector<user>& users);
extern int searchUserID(string userId, vector<user>&users, vector<user>&res);
extern void writeDatasUser(vector<user>& users);
extern void marketSystem();
extern void userSignUp();
extern string getID(int n);
extern void searchUserName(string userName, vector<user>&users, vector<user> &res);
extern void userLogin(string&uid);
extern void userOp(string uid);
extern int userHome();
extern void buyer(string uid);
extern void showAllCommodities4User();
extern void printCommodities4User(vector<cmd>& cmds);
extern void back2Buyer(string uid);
extern void showAllOrders4User(string&uID);
extern void displayDiscriptionofCmd(vector<cmd>& res);
extern string controlDigits(string n);

