#include "AdminManager.h"
 void AdminManager::updatePassword(Admin* admin){
    string password;
    cout << "Please enter neue Password" << endl;
    cin >> password;
    admin->setPassword(password);
}

 Admin* AdminManager::login(int id, string password){
    if(id == 1){
        if(password == AdminGlobal->getPassword()){
            return AdminGlobal;
        }else {
            cout << "Invalid password" << endl;
            return nullptr;
        }
    } else {
        cout << "Invalid userId!" << endl;
        return nullptr;
    }
    return nullptr;
}
 void AdminManager::newEmployee(Admin* admin){
    Employee e = Employee();
    string name, password;
    double salary;
    cout << "Please enter a name of the Employee: " << endl;
    cin >> name;
    cout << "Please enter a password of the Employee: " << endl;
    cin >> password;
    cout << "Please enter a salary of the Employee: " << endl;
    cin >> salary;
    e.setName(name);
    e.setPassword(password);
    e.setSalary(salary);
    admin->addEmployee(e);
}
 void AdminManager::AddToFile(){
    FileHelper::clearFile("Admin.txt", "LastAdminId.txt");
    FileHelper::saveMyAdmin(AdminGlobal);
}
  void AdminManager::printAdminMenu(){
    cout <<"(1) Display my info. " << endl;
    cout << "(2) Update Password." << endl;
    cout <<"(3) Add new client. " << endl;
    cout << "(4) Search for client." << endl;
    cout <<"(5) List all clients. " << endl;
    cout << "(6) Edit client info." << endl;
    cout <<"(7) Add new Employee. " << endl;
    cout << "(8) Search for Employee." << endl;
    cout <<"(9) List all Employees. " << endl;
    cout << "(10) Edit Employee info." << endl;
    cout <<"(11) Logout. " << endl;
}
  bool AdminManager::AdminOptions(){
    while(true){
        printAdminMenu();
        int option;
        cout <<"Your choice is: " << endl;
        cin >> option;
        if(option > 0 && option < 12){
            switch (option) {
                case 1:
                {
                    AdminGlobal->displayInfo();
                    break;
                }
                case 2:
                {
                    updatePassword(AdminGlobal);
                    break;
                }
                case 3:
                {
                    EmployeeManager::addNewClient(AdminGlobal);
                    break;
                }
                case 4:{
                    int id;
                    cout << "Please enter a client id" << endl;
                    cin >> id;
                    Client* c = AdminGlobal->searchClient(id);
                    if(c!=nullptr){
                        c->displayInfo();
                    }
                    break;
                }
                case 5:
                    EmployeeManager::ListAllClient(AdminGlobal);
                    break;
                case 6:
                    AdminGlobal->editClient();
                    break;
                case 7:
                {
                    newEmployee(AdminGlobal);
                    break;
                }
                case 8:
                {
                    int id;
                    cout << "Please enter an Employee id" << endl;
                    cin >> id;
                    Employee* e = AdminGlobal->searchEmployee(id);
                    if(e!=nullptr){
                        e->displayInfo();
                    }
                    break;
                }
                case 9:
                {
                    AdminGlobal->listEmployee();
                    break;
                }
                case 10:{
                    AdminGlobal->editEmployee();
                    break;
                }
                case 11:
                    EmployeeManager::addToFile();
                    AddToFile();
                    return false;
                    
                default:
                    break;
            }
        } else {
            cout << "Please enter a valid option" << endl;
            continue;
        }
    }
    return true;
}
