#include<iostream>
#include "User_Admin.h"
#include<iostream>

using namespace std;

using namespace std;

User_Admin::User_Admin() {
	user.ag = 0;
	user.cou = " ";
	user.gen = ' ';
	user.id = 0.0;
	user.name = " ";
	user.pass = " ";
	male=0;
	female=0;
	cout1=0;
	cout2=0;
	cout3=0;
	coutwaiting=0;
	total=0;
}

bool User_Admin::check_gender(char g)
{
	if (g == 'm' || g == 'M')
	{
		male++;
		return true;
	}
	else if (g == 'f' || g == 'F')
	{
		female++;
		return true;
	}
	else {
		cout << "invaild gander\n";
		return false;
	}
}

User_Admin::User_Admin(int a,string c,char g,long long i,string n,string p) {
	user.ag = a;
	user.cou = c;
	user.gen = g;
	user.id = i;
	user.name = n;
	user.pass = p;
}

void User_Admin::manu() {
	int choice;
	do
	{
		system("cls");
		cout << "***********************************************************************\n\n";
		cout << "                Welcome to Vaccine Tracking System                     \n\n";
		cout << "********************        MENU        *******************************\n\n";
		cout << "1.Display\n";
		cout << "2.Edit\n";
		cout << "3.delete\n";
		cout << "4.Logout\n";
		cout << "\nEnter choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			displayuser();
			break;
		case 2:
			system("cls");
			edituser();
			break;
		case 3:
			system("cls");
			deleteuser();
			break;
		case 4:
			system("cls");
			finally();
			break;
		default:
			cout << "invaild choice\n";
			break;
		}
	} while (choice != 4);

}

void User_Admin::registeruser() {
	system("cls");
	cout << "***************************************************\n\n";
	cout << "                REGISTER SYSTEM                    \n\n";
	cout << "***************************************************\n\n";
	cout << "Enter the fullname: ";
	cin >> user.name;
	cout << "\nEnter the age: ";
	cin >> user.ag;
	cout << "\nEnter the Gender: ";
	cin >> user.gen;
	while (check_gender(user.gen) == false)
	{
		cout << "\the gender is wrong\n";
		cout << "\nEnter the gander: ";
		cin >> user.gen;
	}
	cout << "\nEnter the password: ";
	cin >> user.pass;
	cout << "\nEnter the id: ";
	cin >> user.id;
	while (check_Id(user.id) == true)
	{
		cout << "\the id is exit\n";
		cout << "\nEnter the id: ";
		cin >> user.id;
	}
	cout << "\nEnter the country: ";
	cin >> user.cou;
	while (check_country(user.cou) == false)
	{
		cout << "\the country should be Egypt\n";
		cout << "\nEnter the country: ";
		cin >> user.cou;
	}
	cout << "\nEnter the governorate: ";
	cin >> user.gov;
	V1.push_back(user);
	V2.push_back(user);
	coutwaiting++;
	total++;
}

bool User_Admin::check_country(string cou)
{
	if (cou == "egypt" || cou == "Egypt" || cou == "EGYPT")
	{
		return true;
	}
	else
	{
		cout << "please register in your country" << endl;
		return false;
	}
}

bool User_Admin::check_Id(long long Id) {
	for (int i = 0; i < V1.size(); i++)
	{
		if (V1[i].id == Id ) {
			return true;
		}
	}
	return false;
}

void User_Admin::display()
{
	for (int i=0; i <V1.size(); i++)
	{
		cout << V1[i].ag <<endl;
		cout << V1[i].cou << endl;
		cout << V1[i].gen << endl;
		cout << V1[i].gov << endl;
		cout << V1[i].name << endl;
		cout << V1[i].pass << endl;
	}
	cout << "\n" << endl;
}

void User_Admin::loginuser() {
	registeruser();
	long long na_id;
	string pass;
	system("cls");
	cout << "************************************************\n\n";
	cout << "                LOGIN SYSTEM                    \n\n";
	cout << "************************************************\n\n";
	cout << "\nEnter national id: ";
	cin >> na_id;
	cout << "\nEnter password: ";
	cin >> pass;
	if (search(na_id, pass) == true)
	{

		cout << "\nsuccessed login\n";
		manu();
	}
	else
	{
		cout << "\ninvaild (national id or password)\n";
		
	}
}

bool User_Admin::search(long long id, string pass) {
	for (int i = 0; i < V1.size(); i++)
	{
		if (V1[i].id == id&&V1[i].pass==pass) {
			return true;
		}
	}
	return false;
}

void User_Admin::displayuser() {
	long long id;
	string pass;
	system("cls");
	cout << "************************************************\n\n";
	cout << "                DISPLAY DATA                    \n\n";
	cout << "************************************************\n\n";
	cout << "\nEnter national id: ";
	cin >> id;
	cout << "\nEnter password: ";
	cin >> pass;
	cout << endl;
	for (int i = 0; i < V1.size(); i++)
	{
		if (V1[i].id == id && V1[i].pass == pass) {
			cout << "fullname : " << V1[i].name << endl;
			cout << "Gender : " << V1[i].gen << endl;
			cout << "Age : " << V1[i].ag << endl;
			cout << "Country : " << V1[i].cou << endl;
			cout << "Governorate : " << V1[i].gov << endl;
		}
	}
}

void User_Admin::deleteuser() {
	long long id;
	string pass;
	system("cls");
	cout << "************************************************\n\n";
	cout << "                DELETE DATA                    \n\n";
	cout << "************************************************\n\n";
	cout << "\nEnter national id: ";
	cin >> id;
	cout << "\nEnter password: ";
	cin >> pass;
	cout << endl;
	for (int i = 0; i < V1.size(); i++)
	{
		if (V1[i].id == id && V1[i].pass == pass) {
			if (V1[i].gen == 'm' || V1[i].gen == 'M') {
				V1.erase(V1.begin() + i);
				male--;
				cout << endl;
				cout << "do you want to delete 1 or 2 or 3 or not(0)" << endl;
				int c;
				cin >> c;
				if (c == 1) {
					cout1--;
				}
				else if (c == 2)
				{
					cout2--;
				}
				else if (c == 3)
				{
					cout3--;
				}
				else if (c == 0)
				{
					coutwaiting--;
				}
			}
			else if (V1[i].gen == 'F' || V1[i].gen == 'f')
			{
				V1.erase(V1.begin() + i);
				female--;
				cout << endl;
				cout << "do you want to delete 1 or 2 or 3 or not(0)" << endl;
				int c;
				cin >> c;
				if (c == 1) {
					cout1--;
				}
				else if (c == 2)
				{
					cout2--;
				}
				else if (c == 3)
				{
					cout3--;
				}
				else if (c == 0)
				{
					coutwaiting--;
				}
			}
		}
	

	}
	cout << "\n DATA IS DELETED \n";
	total--;
}

void User_Admin::edituser() {
	long long id;
	string pass;
	system("cls");
	cout << "***********************************************\n\n";
	cout << "                UPDATA DATA                    \n\n";
	cout << "***********************************************\n\n";
	cout << "\nEnter national id: ";
	cin >> id;
	cout << "\nEnter password: ";
	cin >> pass;

	for (int i = 0; i < V1.size(); i++)
	{
		if (V1[i].id == id && V1[i].pass == pass) 
		{
			long long id;
			string name, pass, cou, gov;
			int ag;
			char gen;
			system("cls");
			cout << "Enter new fullname: ";
			cin >> name;
			cout << "\nEnter new age: ";
			cin >> ag;
			cout << "\nEnter new password: ";
			cin >> pass;
			cout << "\nEnter new id: ";
			cin >> id;
			while (check_Id(user.id) == true)
			{
				cout << "\the id is exit\n";
				cout << "\nEnter the id: ";
				cin >> user.id;
			}
			cout << "\nEnter new gander: ";
			cin >> gen;
			while (check_gender(user.gen) == false)
			{
				cout << "\the gender is wrong\n";
				cout << "\nEnter new gander: ";
				cin >> user.gen;
			}
			cout << "\nEnter new country: ";
			cin >> cou;
			while (check_country(user.cou) == false)
			{
				cout << "\the country should be Egypt\n";
				cout << "\nEnter new country: ";
				cin >> user.cou;
			}
			cout << "\nEnter new governorate: ";
			cin >> gov;
			//system("cls");
			cout << "enter number of vaccine" << endl;
			int h;
			cin >> h;
			if (h == 0) {
				V1[i].name = name;
				V2[i].name = name;
				V1[i].ag = ag;
				V2[i].ag = ag;
				V1[i].pass = pass;
				V2[i].pass = pass;
				V1[i].id = id;
				V2[i].id = id;
				V1[i].gen = gen;
				V2[i].gen = gen;
				V1[i].cou = cou;
				V2[i].cou = cou;
				V1[i].gov = gov;
				V2[i].gov = gov;						
			}
			else if (h == 1||h==2||h==3)
			{
				V1[i].name = name;
				V1[i].ag = ag;
				V1[i].pass = pass;
				V1[i].id = id;
				V1[i].gen = gen;
				V1[i].cou = cou;
				V1[i].gov = gov;
			}
		}
	}
}

void User_Admin::mainmenu() {
	cout << "\n\t----------------------" << endl;
	cout << "\n\t MAIN MENU" << endl; // MAIN MENU
	cout << "\n\t1. Admin." << endl;
	cout << "\n\t2. user." << endl;
	cout << "\n\tEnter 0 to exit." << endl;
	cout << "\n\t----------------------" << endl;
	cout << "\n\t Enter choice :";
}

void User_Admin::menustart()
{
	cout << "*******************************************************************\n\n";
	cout << "                      Welcome to USER                              \n\n";
	cout << "*******************        MENU        ****************************\n\n";
	int start;
	cout << "1.Register....  "<<endl;
	cout << "2.Login  "<<endl;
	cout << "enter the choice :";
	cin >> start;
	switch (start)
	{
	case 1:
		system("cls");
		loginuser();
		break;
	case 2:
		system("cls");
		login();
		break;
		
	default:
		cout << "\n\t\tThe choice you entered was not valid," << endl;
		cout << "\n\t\tplease enter a valid option." << endl;
		system("cls");
		finally();
		break;
	}
		
}

void User_Admin::login()
{
	long long na_id;
	string pass;
	system("cls");
	cout << "************************************************\n\n";
	cout << "                LOGIN SYSTEM                    \n\n";
	cout << "************************************************\n\n";
	cout << "\nEnter national id: ";
	cin >> na_id;
	cout << "\nEnter password: ";
	cin >> pass;
	if (search(na_id, pass) == true)
	{
		cout << "\nsuccessed login\n";
		int co;
		cout << "\nwhat is a new dose you want?(1 or 2 or 3): ";
		cin >> co;
		if (co == 1)
		{
			cout1++;
			cout << "\nGo to your nearst hospital to take a new dose\n";
			coutwaiting--;
			manu();
		}
		else if (co == 2)
		{
			cout2++;
			cout << "\nYou completed your vaccined tracking\n";
			coutwaiting--;
			manu();
		}
		else if (co == 3)
		{
			cout3++;
			cout << "\nwating list\n";
			coutwaiting--;
			manu();
		}
		else
			cout << "Invaild choice\n";
		
	}
}

void User_Admin::admin_login()
{
}

void User_Admin::finally() {
	int choice;
	mainmenu();
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		admin_login();
		break;
	case 2:
		system("cls");
		menustart();
		break;
	case 0:
		system("cls");
		cout << "\n\t\tThank you for using App." << endl;
		break;
	default:
		cout << "\n\t\tThe choice you entered was not valid," << endl;
		cout << "\n\t\tplease enter a valid option." << endl;
		system("cls");
		break;
	}
}

