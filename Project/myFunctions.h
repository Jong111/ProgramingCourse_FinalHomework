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


typedef struct {
	string price;
	string day;
	string userID;
}record;


typedef struct {
	string sender;
	string receiver;
	string content;
} msg;

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
extern void userLogin(string& uid, int userLoginTimes);
extern void userOp(string uid);
extern int userHome();
extern void buyer(string uid);
extern void showAllCommodities4Buyer();
extern void printCommodities4Buyer(vector<cmd>& cmds);
extern void back2Buyer(string uid);
extern void showAllOrders4Buyer(string&uID);
extern void displayDiscriptionofCmd(vector<cmd>& res);
extern string controlDigits(string n);
extern void seller(string uid);
extern void back2Seller(string uid);
extern void showAllOrders4Seller(string& uID);
extern void showAllCommodities4Seller(string&uid);
extern void printCommodities4Seller(vector<cmd>& cmds, string& uid);
extern string handleInvalidInput_12();
extern void displayDiscriptionofCmd4Seller(vector<cmd>& res);
extern string displayHelper(string&str, int a);
extern int Min(int a, int b, int c);
extern void searchComplex(string& str, vector<cmd>cmds, vector<cmd>& res);
extern bool comp(pair<cmd, int> c1, pair<cmd, int> c2);
extern int minDistance(string s1, string s2);
extern void manageUserInformation(string uid);
extern void back2manageUser(string uid);
extern string handleInvalidInput_123();
extern void readDatasRecord(vector<record>& records);
extern void writeDatasRecord(vector<record>& records);
extern void showRefillRecord(string&uid);
extern void printRecords(vector<record>& records);
extern void searchRecordUid(string& uid, vector<record>& records, vector<record>& res);
extern void message(string uid);
extern void back2message(string uid);
extern void sendMessage(string& uid);
extern void printReceivedMessage(string uid, vector<msg>& msgs);

