#pragma once
#include <stdio.h>
#include "iostream"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "FileManager.h"
#include "stdio.h"
#include "Welcome.hpp"
using namespace std;

class Screen
{
private:
    static Client* screenClient;
    static Employee* screenEmployee;
    static Admin* screenAdmin;

public:
    
    static void loginOptions() {
        cout << "(1) Client." << endl;
        cout << "(2) Employee." << endl;
        cout << "(3) Admin." << endl;
    }

    static int loginAs() {
        loginOptions();
        int personCode;
        cout << "Login as: " << endl;
        cin >> personCode;
        return personCode;
    }

    static void invalid(int c) {

    }

    static void logout() {
        loginScreen(loginAs());
    }
    static void logInScreens(int c) {
        switch (c) {
        case1:
            ClientManager::clientOptions(screenClient);
            break;
        case2:
            EmployeeManager::employeeOptions(screenClient);
            break;
        case3:
            AdminManager::AdminOptions();
            break;
        default:
            cout << "Please enter a valid option" << endl;
            break;
        }
    }
    static void loginScreen(int c) {
        int trials = 3;
        int id;
        string password;
        switch (c) {
        case 1: {
            while (trials > 0) {
                cout << "Enter id: " << endl;
                cin >> id;
                cout << "Enter password: " << endl;
                cin >> password;
                screenClient = ClientManager::login(id, password);
                if (screenClient != nullptr) {
                    if (!ClientManager::clientOptions(screenClient)) {
                        logout();
                    }
                    else {
                        ClientManager::clientOptions(screenClient);
                    }
                    break;
                }
                else {
                    cout << "Invalide user data." << endl;
                }
                trials--;
            }
            cout << "You exceeded the number of trials, please contact the Bank"
                << endl;
            loginScreen(loginAs());
            break;
        }
        case 2: {
            trials = 3;
            while (trials > 0) {
                cout << "Enter id: " << endl;
                cin >> id;
                cout << "Enter password: " << endl;
                cin >> password;
                screenEmployee = EmployeeManager::login(id, password);
                if (screenEmployee != nullptr) {
                    if (!EmployeeManager::employeeOptions(screenClient)) {
                        logout();
                    }
                    else {
                        EmployeeManager::employeeOptions(screenClient);
                    }
                    break;
                }
                else {
                    cout << "Invalide user data." << endl;
                }
                trials--;
            }
            cout << "You exceeded the number of trials, please contact the Admin!"
                << endl;
            loginScreen(loginAs());
            break;
        }
        case 3: {
            trials = 3;
            while (trials > 0) {
                cout << "Enter id: " << endl;
                cin >> id;
                cout << "Enter password: " << endl;
                cin >> password;
                screenAdmin = AdminManager::login(id, password);
                if (screenAdmin != nullptr) {
                    if (!AdminManager::AdminOptions()) {
                        logout();
                    }
                    else {
                        AdminManager::AdminOptions();
                    }
                    break;
                }
                else {
                    cout << "Invalide user data." << endl;
                }
                trials--;
            }
            cout << "You exceeded the number of trials, please contact the Manager!"
                << endl;
            loginScreen(loginAs());
            break;
        }
        default:
            cout << "Please enter a valid option" << endl;
            break;
        }
    }

    static void runApp() {
        FileManager::getAllData();
        Welcome::hello();
        Welcome::welcome();
        Welcome::message();
        logInScreens(loginAs());
    }
};

