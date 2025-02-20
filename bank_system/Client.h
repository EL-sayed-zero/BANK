#pragma once

#include "Person.h"



class Client :
    public Person
{
private:
    double balance;

public:

    Client();


    Client(double balance, int id, string name, string password);


    void setBalance(double balance);






    double getBalance();




    void deposite(double& amount);





    void withdrow(double amount);



    void transfare(double amount, Client& client);




    //check balance 
    void checkBalance() const;



    void display();




    //overloading cin>> methods

    friend istream& operator >>(istream& in, Client& client);


    //overloading cout<< methods

    friend ostream& operator <<(ostream& out, Client& client);





};

