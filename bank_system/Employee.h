#pragma once

#include"Person.h"
#include"Client.h"
#include"fstream"






class Employee :
    public Person
{
protected:
    double salary;

public:

    Employee();
    Employee(double salary, int id, string name, string password);




    void setSalary(double salary);



    double getSalary();



    virtual void display();

    void addClient(Client& client);

    void clients_list();

    Client* searchClient(int id);
    void delete_client(int id);

    void edit_client(int id, string name, string password, double balance);



    friend istream& operator >>(istream& in, Employee& employee);



    friend ostream& operator <<(ostream& out, Employee& employee);










};

