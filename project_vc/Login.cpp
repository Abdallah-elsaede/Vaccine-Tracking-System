#include "Login.h"

void Login::finally() {
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

void Login::manu() {
	int choice;
	do
	{
		//system("cls");
		cout << "***********************************************************************\n\n";
		cout << "                Welcome to Vaccine Tracking System                     \n\n";
		cout << "*******************        MENU        ********************************\n\n";
		cout << "1.Display\n";
		cout << "2.Edit\n";
		cout << "3.delete\n";
		cout << "4.Logout\n";
		cout << "\nEnter choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//system("cls");
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

