#include "FileHelper.h"
void FileHelper::getMyAdmin() {
    string fileName ="Admin.txt", line;
    fstream input(fileName, ios::in);
    if(!input.is_open()){
        cout << "Error opening the file" << endl;
        return;
    }
    AdminGlobal = Admin::getMyAdmin();
    while(getline(input, line)){
        Admin a = Parser::parseToAdmin(line);
        AdminGlobal->setName(a.getName());
        AdminGlobal->setPassword(a.getPassword());
        AdminGlobal->setSalary(a.getSalary());
    }
}
