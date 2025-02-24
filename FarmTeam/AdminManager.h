#pragma once
#include <iostream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
#include "global.h"
#include "FileHelper.h"
#include "EmployeeManager.h"
#include "globalAdmin.hpp"

using namespace std;

class AdminManager
{
public:
    static void updatePassword(Admin* admin);

    static Admin* login(int id, string password);
    static void newEmployee(Admin* admin);
    static void AddToFile();
    static  void printAdminMenu();
    static  bool AdminOptions();

};
