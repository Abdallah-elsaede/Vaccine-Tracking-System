#pragma once
#include "User_Admin.h"
#include<iostream>
using namespace std;
class Admin_User :
    public User_Admin
{
public:
    virtual void admin_login();
    void menuA();
    void displayall();
    void displayallwaitinglistno();
    void DeleteAllUsers();
    void DeleteUserId();
    void Females();
    void Males();
    void both_dose();
    void first_dose();
    void three_dose();
    void wating_list();
    void menu_statistics();
   // void displayallwaitinglistfirst();
    //void displayallwaitinglistsecond();
    //void displayallwaitinglistthird();
};

