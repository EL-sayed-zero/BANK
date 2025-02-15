#pragma once
#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include<sstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include <fstream>



class Parser_read {



public:
    static vector<string> split(string line) {
        vector<string> splitResult;   
        stringstream strs(line);     
        string part;

        while (getline(strs, part, '|')) {
            splitResult.push_back(part);    
        }

        return splitResult;  
    }


    static Client parse_to_client(string line) {


        ifstream file("client.txtt", ios::in);
        if (!file) {
            cout << " can not find file";
            return;
        }
        string line;
        Client client;
       
        while ( getline (file, line) ) {


           
            vector<string>part = split(line);
            int id;
            double balance;
            string name, password;

            name = part[0];
            id = stoi(part[1]);
            balance = stod(part[2]);
            password = part[3];



        }

        file.close();
        return  Client(balance, id, name, password);
    }               

};
