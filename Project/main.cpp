#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include"myFunctions.h"

using namespace std;

#define AD_LOGIN 49
#define USER_SIGN_UP 50
#define USER_LOGIN 51
#define EXIT 52


int main() {
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
		cout << "Not Implemented";
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