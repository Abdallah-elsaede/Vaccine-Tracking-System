#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<iostream>
#include<string>
#include "User_Admin.h"
#include"Admin_User.h"
#include"Login.h"
using namespace std;

int main() {
	Login U;
	U.finally();
	return 0;
}