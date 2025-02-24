#pragma once
#include "ClientManager.h"
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "FileHelper.h"
#include "Validation.h"
#include "FileManager.h"
using namespace std;

class EmployeeManager
{
private:
    static void printEmployeeMenu() {
        system("cls");
        cout << "\n=== Employee Menu ===\n";
        cout << "(1) Display Info.\n" << "(2) Update Password\n" << "(3) Add New Client\n"
            "(4) Search For Client\n" << "(5) List All Clients\n" << "(6) Edit Client Info\n"
            "(7) LogOut!! \n";
    }

    //static void back(Employee* employee) {
    //    cout << "\n";
    //    system("pause");
    //    employeeOptions(employee);
    //}

public:

    static void addNewClient(Employee* employee) {
        Client client;
        client.setId(FileHelper::getLast("ClientLastId.txt" + 1));
        string pass, name;
        client.setName(name);
        client.setPassword(pass);
        employee->addClient(client);
        //FileManager::updateClients();
        cout << "\n Client Added Successfully :) \n";
    }

    static void searchForClient(Employee* employee) {
        int id;
        system("cls");
        cout << "Enter Client id: ";
        cin >> id;
        if (employee->searchClient(id) == NULL)
            cout << "Client Not Found" << endl;
        else
            employee->searchClient(id)->displayInfo();
    }

    static void ListAllClient(Employee* employee) {
        system("cls");
        cout << "The List Of All Clients :-" << endl;
        employee->listClients();
    }

    static void editClientInfo(Employee* employee) {
        int id;
        system("cls");
        cout << "enter Client Id : ";
        cin >> id;
        string name, pass;
        double balance;
        // the function editClient search inside it if the id is found or not.
//        if (employee->searchClient(id) == NULL)
//            cout << "Client Not Found" << endl;
//        else {
            /*employee->searchClient(id)->setName(name);
            employee->searchClient(id)->setPassword(pass);
            employee->searchClient(id)->setBalance(balance);*/

            employee->editClient();
    //    }
    }
   static Employee* EmployeeSearch(int id, string password){
        int start = 0, end = employeesInfo.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(id == employeesInfo[mid].getId()){
                if(password == employeesInfo[mid].getPassword()){
                    return &employeesInfo[mid];
                } else {
                    return nullptr;
                }
            }
            if(id > employeesInfo[mid].getId()){
                start = mid+1;
            }
            else if(id < employeesInfo[mid].getId()){
                end = mid-1;
            }
        }
        return nullptr;
    }
  static  Employee* login(int id, string password){
        Employee *e = EmployeeSearch(id, password);
        if(e!=nullptr){
            return e;
        } else {
            return nullptr;
        }
    }
    
    static void updatePassword(Employee* e) { // I added this from ClientManager
        string newPassword, confirmPassword;

        cout << "Enter new password: ";
        getline(cin, newPassword);

        cout << "Confirm new password: ";
        getline(cin, confirmPassword);

        if (newPassword != confirmPassword) {
            cout << "Passwords don't match!\n";
            return;
        }

        if (Validation::validatePassword(newPassword)) {
            e->setPassword(newPassword);
            cout << "Password updated successfully!\n";
        }
    }

   static void addToFile(){
        FileHelper::clearFile("Employees.txt", "LastEmployeeId.txt");
        for(Employee i: employeesInfo){
            cout << i.getId() << " , " << i.getName() << " , " << i.getPassword() << " , " << i.getSalary() << endl;
            FileHelper::saveEmployee(i);
        }
        FileHelper::clearFile("Clients.txt", "LastClientId.txt");
        for(Client i: clientsInfo){
            cout << i.getId() << " , " << i.getName() << " , " << i.getPassword() << " , " << i.getBalance() << endl;
            FileHelper::saveClient(i);
        }
    }
//    static Employee* logIn(int id, string password) {
//        for (eItr = employeesInfo.begin(); eItr != employeesInfo.end(); eItr++) {
//            if (eItr->getId() == id && eItr->getPassword() == password) {
//                cout << "\nLogin successful!\n";
//                return eItr._Ptr;
//            }
//            else {
//                cout << "\nInvalid ID or password.\n";
//                return NULL;
//            }
//        }
//    }

    static bool employeeOptions(Client* client) {
        printEmployeeMenu();
        cout << "Enter Your Choice: ";
        int choice;
        string pass;
        Employee employee;
        cin >> choice;
        switch (choice) {
        case1:
            system("cls");
            employee.displayInfo();
            break;
        case2:
            system("cls");
                updatePassword(&employee);
            break;
        case3:
            system("cls");
            EmployeeManager::addNewClient(&employee);
            break;
        case4:
            system("cls");
            EmployeeManager::searchForClient(&employee);
            break;
        case5:
            system("cls");
            EmployeeManager::ListAllClient(&employee);
            break;
        case6:
            system("cls");
            EmployeeManager::editClientInfo(&employee);
            break;
        case7:
            addToFile();
            system("cls");
            //Screen::loginOptions();
            break;
        default:
            cout << "You Enter Invalid Number, Try Again !!" << endl;
            break;
        }
        return true;
    }
};
