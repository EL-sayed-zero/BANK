#pragma once
#include "Employee.h"



class Admin :
    public Employee
{




public:

    Admin();


    Admin(double salary, int id, string name, string password);


    Admin* search_admin(int id);

    void delete_employee(int id);
    void display();
    void delete_admin(int id);
    // Client methods

   
    void addEmployee(Employee& employee);

    void employee_list();

    Employee* searchemployee(int id);

    void edit_employee(int id, string name, string password, double balance);

    friend istream& operator >>(istream& in, Admin& admin);






    friend ostream& operator <<(ostream& out, Admin& admin);





};

