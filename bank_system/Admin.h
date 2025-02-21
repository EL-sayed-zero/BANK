#pragma once
#include "Employee.h"



class Admin :
    public Employee
{




public:

    Admin();


    Admin(double salary, int id, string name, string password);





    void display();

    // Client methods

    void addClient(Client& client);

    void clients_list();

    Client* searchClient(int id);

    void edit_client(int id, string name, string password, double balance);







    friend istream& operator >>(istream& in, Admin& admin);






    friend ostream& operator <<(ostream& out, Admin& admin);





};

