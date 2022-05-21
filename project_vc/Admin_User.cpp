#include "Admin_User.h"

void Admin_User::admin_login()
{
	string user, pass;
	bool is_login=false;
	int count=1;
	cout << "*****************************************************************\n\n";
	cout << "                      LOGIN Admin                               \n\n";
	cout << "****************************************************************\n\n";
	do
	{
		cout << "\nEnter username: ";
		cin >> user;
		cout << "\nEnter password: ";
		cin >> pass;
		if (user == "admin" && pass == "admin")
		{
			is_login=true;
			break;
		}
		else
			cout << "\ninvaild (national id or password)\n";
		count++;
	} while (count<=3);
	if(is_login)
	{
		menuA();
	}
	else
		cout << "\nyou have enter wrong data 3 time , please try agin later\n";

}

void Admin_User::menuA() {
	int choice;
	system("cls");
	do {
		cout << "*************************\n\n";
		cout << "                      Welcome to Admin                               \n\n";
		cout << "*******        MENU        ************\n\n";
		cout << "1.View All Record\n";
		cout << "2.Delete Record By Id\n";
		cout << "3.Delete ALL Records \n";
		cout << "4.View statistics\n";
		cout << "5.View All Record In Waiting List\n";
		cout << "6.Exit\n";
		cout << "\nEnter your choice : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			system("cls");
			displayall();
			break;
		case 2:
			system("cls");
			DeleteUserId();
			break;
		case 3:
			system("cls");
			DeleteAllUsers();
			break;
		case 4:
			system("cls");
			menu_statistics();
			break;
		case 5:
			system("cls");
			displayallwaitinglistno();
			break;
		case 6:
			system("cls");
			finally();
			break;
		default:
			system("cls");
			cout << "Wrong Choice Intered\n" << endl;
			menuA();
		}
	} while (choice != 6);
}

void Admin_User::displayall() {
	system("cls");
	cout << "************************************************\n\n";
	cout << "                DISPLAY ALL DATA                    \n\n";
	cout << "************************************************\n\n";
	for (int i = 0; i < V1.size(); i++)
	{
		cout << "Name " << i + 1 << " : " << V1[i].name << endl;
		cout << "Age " << i + 1 << " : " << V1[i].ag << endl;
		cout << "Country " << i + 1 << " : " << V1[i].cou << endl;
		cout << "Gender " << i + 1 << " : " << V1[i].gen << endl;
		cout << "Governorate " << i + 1 << " : " << V1[i].gov << endl;
		cout << "National ID " << i + 1 << " : " << V1[i].id << endl;
		cout << "Password " << i + 1 << " : " << V1[i].pass << endl;
		cout << endl;
		cout << "============================================";
		cout << endl;
	}
}

void Admin_User::displayallwaitinglistno() {
	system("cls");
	cout << "************************************************\n\n";
	cout << "         DISPLAY ALL DATA IN WAITING LIST       \n\n";
	cout << "************************************************\n\n";
	for (int i = 0; i < V2.size(); i++)
	{
		cout << "Name " << i + 1 << " : " << V2[i].name << endl;
		cout << "Age " << i + 1 << " : " << V2[i].ag << endl;
		cout << "Country " << i + 1 << " : " << V2[i].cou << endl;
		cout << "Gender " << i + 1 << " : " << V2[i].gen << endl;
		cout << "Governorate " << i + 1 << " : " << V2[i].gov << endl;
		cout << "National ID " << i + 1 << " : " << V2[i].id << endl;
		cout << "Password " << i + 1 << " : " << V2[i].pass << endl;
		cout << endl;
		cout << "============================================";
		cout << endl;
	}
}

void Admin_User::DeleteAllUsers() {
	system("cls");
	cout << "**************************************************\n\n";
	cout << "                DELETE All DATA                   \n\n";
	cout << "**************************************************\n\n";
	for (int i = 0; i < V1.size(); i++)
	{
		V1.erase(V1.begin());
	}
	cout << "successfully Delete" << endl;
	total = 0;
	male = 0;
	female = 0;
	cout1 = 0;
	cout2 = 0;
	cout3 = 0;
	coutwaiting = 0;
}

void Admin_User::DeleteUserId() {
	long long id;
	system("cls");
	cout << "************************************************\n\n";
	cout << "                DELETE DATA                    \n\n";
	cout << "************************************************\n\n";
	cout << "\nEnter national id: ";
	cin >> id;
	cout << endl;
	for (int i = 0; i < V1.size(); i++)
	{
		if (V1[i].id == id) {
			V1.erase(V1.begin() + i);
			if (V1[i].gen == 'm' || V1[i].gen == 'M') {
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

void Admin_User::Females()
{
	float per_females = (female / static_cast<float>(total)) * HUNDRED;
	cout << "percentage of females: " << per_females << "%" << endl;

}

void Admin_User::Males()
{
	float per_males = (male / static_cast<float>(total)) * HUNDRED;
	cout << "percentage of males: " << per_males << "%" << endl;

}

void Admin_User::three_dose()
{
	float per_count3 = (cout3 / static_cast<float>(total)) * HUNDRED;
	cout << "percentage of three dose: " << per_count3 << "%" << endl;
}

void Admin_User::both_dose()
{
	float per_count2 = (cout2 / static_cast<float>(total)) * HUNDRED;
	cout << "percentage of both dose: " << per_count2 << "%" << endl;
}

void Admin_User::first_dose()
{
	float per_count1 = (cout1 / static_cast<float>(total)) * HUNDRED;
	cout << "percentage of both dose: " << per_count1 << "%" << endl;
}

void Admin_User::wating_list()
{
	cout << "wating list: " << coutwaiting << endl;
	float per_count4 = (coutwaiting / static_cast<float>(total)) * HUNDRED;
	cout << "percentage of both dose: " << per_count4 << "%" << endl;
}

void Admin_User::menu_statistics()
{
	system("cls");
	cout << "***********************************************************************\n\n";
	cout << "                      Welcome to page statistics                       \n\n";
	cout << "*******************        MENU        ********************************\n\n";
	cout << "1.Percentage of people registered in the system that has received the first dose\n";
	cout << "2.Percentage of people registered in the system that has received both doses\n";
	cout << "3.Percentage of people registered in the system that has received three doses\n";
	cout << "4.Percentage of Females registered in the system\n";
	cout << "5.Percentage of Males registered in the system\n";
	cout << "6.Percentage of wating list registered in the system and his number\n";
	cout << "7.Back\n";
	cout << "\nEnter your choice : ";
	int choice;
	cin >> choice;
	cout << endl;

	switch (choice)
	{

	case 1:
		system("cls");
		first_dose();
		break;
	case 2:
		system("cls");
		both_dose();
		break;
	case 3:
		system("cls");
		three_dose();
		break;
	case 4:
		system("cls");
		Females();
		break;
	case 5:
		system("cls");
		Males();
		break;
	case 6:
		system("cls");
		wating_list();
		break;
	case 7:
		system("cls");
		menuA();
		break;
	default:
		system("cls");
		cout << "Wrong Choice Intered\n" << endl;

	}
}