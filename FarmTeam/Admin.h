#pragma once
#include "Client.h"
#include "Employee.h"
#include "Person.h"
#include "global.h"
class Admin : public Employee {
private:

    // Constructors
    //1-Defaule Cons
    //==========================
    // Private constructor to prevent object creation from outside
    Admin() {
        this->id = 1;
    }

    //2-Parameterized Cons
    //============================
    Admin(const string& name, const string& password, double salary) : Employee(name, password, salary) {
        this->id = 1;
    }

    // The single instance of Admin (Singleton Pattern)
    static Admin* myAdmin;

public:
    // Delete copy constructor and assignment operator to prevent duplication
    /*Admin(const Admin&) = delete;
    Admin& operator=(const Admin&) = delete;*/

    // Static method to get the single instance of Admin
    static  Admin* getMyAdmin() {
        if (myAdmin == nullptr) {
            myAdmin = new Admin();
        }
        return myAdmin;
    }

    //Methods
    // Adding new Employee
    void addEmployee(Employee& employee) ;
    // To save employee data at file
    void saveEmployeeToFile() ;

    // search for Employee by id
    Employee* searchEmployee(int id) ;
    int searchEmployeeId(int id);


    // Editing Employee data
    void editEmployee() ;

    // All Employee list ready for print
    void listEmployee() ;
    // Display Info (overrid)
    void displayInfo() ;
};

