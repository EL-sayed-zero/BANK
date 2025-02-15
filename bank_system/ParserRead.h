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



class ParserREad {


    // main split 
public:
    //ahmed|20|6888|300idufuf
    static vector<string> split(string line) {
        vector<string> splitResult;
        stringstream strs(line);
        string part;

        while (getline(strs, part, '|')) {
            splitResult.push_back(part);
        }

        return splitResult; //[sahhdd,id.jddkd.iddijd]
    }


    static Client parse_to_client(string line) {//ahmed|20|6888|300idufuf




            vector<string>part = split(line); 

       
          
            string name = part[0];
           int id = stoi(part[1]);
          double  balance = stod(part[2]);
          string  password = part[3];

        return Client (balance, id, name, password);

         

 
        
    }


    static Admin parse_to_admin(string line) {//ahmed|20|6888|300idufuf




        vector<string>part = split(line);

            
      

        string name = part[0];
        int id = stoi(part[1]);
        double  salary= stod(part[2]);
        string  password = part[3];

        return Admin (salary, id, name, password);





    }



    static Employee parse_to_Employee(string line) {

        vector<string>part = split(line);



        string name = part[0];
        int id = stoi(part[1]);
        double  balance = stod(part[2]);
        string  password = part[3];

        return Employee(balance, id, name, password);

    }


};
