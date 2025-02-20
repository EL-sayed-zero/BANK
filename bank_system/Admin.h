#pragma once
#include "Employee.h"



class Admin :
    public Employee
{




public:

    Admin();


    Admin(double salary, int id, string name, string password);





    void display();







    friend istream& operator >>(istream& in, Admin& admin);






    friend ostream& operator <<(ostream& out, Admin& admin);





};

