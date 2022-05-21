#pragma once
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<queue>
using namespace std;
const int HUNDRED = 100;

class User_Admin
{
public:
	struct datauser
	{
		long long id;
		string name, pass, cou, gov;
		int ag;
		char gen;

	};
	vector<datauser>V1;
	vector<datauser>V2;
	datauser user;
	int male, female, cout1, cout2, cout3, coutwaiting, total;
	User_Admin();
	User_Admin(int a, string c, char g, long long i, string n, string p);
	void registeruser();
	void display();
	void loginuser();
	bool search(long long id, string pass);
	virtual void manu();
	void displayuser();
	void deleteuser();
	void edituser();
	void mainmenu();
	bool check_gender(char g);
	bool check_Id(long long Id);
	bool check_country(string cou);
	void menustart();
	void login();
	virtual void  finally();
	void admin_login();
};

