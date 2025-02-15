#pragma once
#include "DataSourceInterface.h"
#include<fstream>
#include <string>
#include <sstream>
using namespace std;
class FileManger :
    public DataSourceInterface

{
    // i make static func to use the class without obj 
public:



   static void add_Employee(Employee person) {
        fstream file("Employee.txt");
        if (!file.good()) {
            ofstream employeefile("Employee.txt");
            employeefile  << person.getName() << "|" << person.getId() << "|" << person.getSalary() << "|" << person.getPassword() << endl;
            employeefile.close();
            return; 
        }
        ofstream employeefile("Employee.txt", ios::app);
        employeefile << person.getName() << "|" << person.getId() << "|" << person.getSalary() << "|" << person.getPassword() << endl;
        employeefile.close();

    }

    void  remove_all_employee() {

        fstream check_file("Employee.txt");
        if (!check_file.good()) {
            return;
        }
        check_file.close();
        ofstream file("Employee.txt", ios::trunc);
        file.close();
    }



     void get_all_employee() {

        ifstream file("Employee.txt", ios::in);
        string line;
        if (!file) {
            cout << "file not found ";
            return;
        }

        while (getline(file, line)) {

            cout << line << endl;  
        }

        file.close();

    }

         void  add_Client(Client person) {

            ofstream file("client.txt", ios::app);
            if (!file.good()) {
                cout << "There was an error with the file." << endl;
                exit(1);
            }
            file << person.getName() << "|";
            file << person.getId() << "|";
            file << person.getBalance() << "|";
            file << person.getPassword() << "\n";
            file.close();

        }


         void  remove_all_Clients() {
            ofstream file("client.txt", ios::trunc);
            if (!file) {
                cout << "There was an error with the file.";
                exit(1);
            }

            file.close();


        }

         void get_all_clients() {

            ifstream file("client.txt", ios::in);
            if (!file) {
                cout << "there was an erroe with file ";
                exit(0);
            }
          
            string line;


            while (getline(file, line)) {

                cout << line << endl;


            }

        }



         void add_admin(Admin admin) {

            ofstream file("admin.txt", ios::app);

            if (!file) {
                cout << "file not exist ";
                exit(0);
            }
            file << admin.getName() << "|";
            file << admin.getId() << "|";
            file << admin.getSalary() << "|";
            file << admin.getPassword() << "\n";
            file.close();
        }


         void delete_Admin() {

            ofstream file("admin.txt", ios::trunc);
            if (!file) {
                cout << "there was an erroe with file ";
                return;

            }
            file.close();
        }



         void get_all_admin() {

            ifstream file("admin.txt", ios::in);
            if (!file) {
                cout << " can not find file";
                exit(0);
            }

            string line;
            while (getline(file, line)) {

                cout << line << endl;

            }

            file.close();

        }


    };

