#pragma once

#include<iostream>
using namespace std;
#include<string>
#include "Person.h"
#include"Validation.h"
#include<utility>
#include"Client.h"
#include"FileManger.h"



class Employee :
    public Person
{
protected:
    double salary;

public:

    Employee() {
        salary = 0;
    }
    Employee(double salary, int id, string name, string password) :Person(id, name, password) {

           while (!Validation::isValidSalary(salary)) {  
            cout << "Salary must be 5000 or more. Please enter a valid salary: \n ";
            cin >> salary;
        }

        this->salary = salary;  
    }


    //setter 

    void setSalary(double salary) {
        while (!Validation::isValidSalary(salary)) {

            cout << "Salary must be 5000 or more. Please enter a valid salary: \n ";
            cin >> salary;
        }

        this->salary = salary;
    }

    double getSalary() {
        return salary;
    }
    

   virtual void display() {
        Person::display();
        cout << salary << endl;
        cout << "##################\n";
    }






   friend istream& operator >>(istream& in, Employee& employee) {
       int temp_id;
       double temp_salary;
       string temp_pw, temp_name;

       cout << "enter id " << endl;
       in >> temp_id;
       employee.setID(temp_id);
       cout << "enter name " << endl;
       in >> temp_name;
       employee.setName(temp_name);
       cout << "enter salary " << endl;
       in >> temp_salary;
       employee.setSalary(temp_salary);
       cout << "enter password " << endl;
       in >> temp_pw;
       employee.setPW(temp_pw);

       
       return in;
   }

   friend ostream& operator <<(ostream& out, Employee& employee) {

       cout << "id : " << employee.getId() << endl;
       cout << "name :" << employee.getName() << endl;
       cout << "Salary : " << employee.getSalary() << endl;
       cout << "password : " << employee.getPassword() << endl;
       out << "#################################\n";

       return out;
   }


   





































































   void add_client(Client& client)
   {
       FileManger f;
       f.add_Client(client);
   }


};

