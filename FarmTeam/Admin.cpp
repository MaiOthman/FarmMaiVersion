#include "Admin.h"

Admin* AdminGlobal;

//Methods
// Adding new Employee
void Admin::addEmployee(Employee& employee) {
    employeesInfo.push_back(employee);
    saveEmployeeToFile();
}

// To save employee data at file
void Admin::saveEmployeeToFile() {
    ofstream file("Employee.txt", ios::trunc);
    for (const auto& employee : employeesInfo) {
        // file << employee.getId() << " " << employee.getName() << " " << employee.getPassword() << " " << employee.getSalary() << endl;
        file << employee.getId() << " " << employee.getName() << " " << employee.getPassword() << endl;
    }
    file.close();
    cout << "Employee data saved to file." << endl;
}

// search for Employee by id
Employee* Admin::searchEmployee(int id) {
    for (auto& employee : employeesInfo) {
        if (employee.getId() == id)
            return &employee;
    }
    return nullptr;
}
int Admin::searchEmployeeId(int id){
    int index;
    int start = 0, end = employeesInfo.size()-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(id == employeesInfo[mid].getId()){
            return mid;
        }
        if(id > employeesInfo[mid].getId()){
            start = mid+1;
        }
        else if (id < employeesInfo[mid].getId()){
            end = mid-1;
        }
    }
    cout << "Employee is not found in this list" << endl;
    return -1;
}
// Editing Employee data
void Admin::editEmployee() {
    int id;
    string name, password;
    double salary;
    cout << "Please enter your Id: " << endl;
    cin >> id;
    int index =searchEmployeeId(id);
    if(index!=-1){
        cout << "Please enter an employee name: " << endl;
        cin >> name;
        cout << "Please enter an employee password: " << endl;
        cin >> password;
        cout << "Please enter an employee salary: " << endl;
        cin >> salary;
        employeesInfo[id].setName(name);
        employeesInfo[id].setPassword(password);
        employeesInfo[id].setSalary(salary);
    }
//    Employee* employee = searchEmployee(id);
//    if (employee) {
//        employee->setName(name);
//        employee->setPassword(password);
//        employee->setSalary(salary);
//        cout << "Employee updated successfully.\n";
//    }
//    else {
//        cout << "Insert valid employee data.\n";
//    }
}

// All Employee list ready for print
void Admin::listEmployee() {
    for (const auto& employee : employeesInfo) {
        //cout << "Employee ID: " << employee.getId() << ", Name: " << employee.getName()
         //   << ", Salary: " << employee.getSalary() << endl;

        cout << "Employee ID: " << employee.getId() << ", Name: " << employee.getName() << endl;
    }
}
// Display Info (overrid)
void Admin::displayInfo() {
    cout << "     ** Admin Info **" << endl;
    cout << "Admin ID     : " << id << endl;
    cout << "Admin Name   : " << name << endl;
    cout << "Admin Salary : " << salary << endl;
    cout << "\n==============================\n";
}
