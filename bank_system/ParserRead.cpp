#include "ParserRead.h"

vector<string> ParserREad::split(string line)
{
    vector<string> splitResult;
    stringstream strs(line);
    string part;

    while (getline(strs, part, '|')) {
        splitResult.push_back(part);
    }

    return splitResult; 
}

Client ParserREad::parse_to_client(string line)
{
    vector<string>part = split(line);



    string name = part[0];
    int id = stoi(part[1]);
    double  balance = stod(part[2]);
    string  password = part[3];

    Client client(balance, id, name, password);
    return client;

}

Admin ParserREad::parse_to_admin(string line)
{


    vector<string>part = split(line);




    string name = part[0];
    int id = stoi(part[1]);
    double  salary = stod(part[2]);
    string  password = part[3];

     Admin admin(salary, id, name, password);
     return admin;

}

Employee ParserREad::parse_to_Employee(string line)
{

    vector<string>part = split(line);



    string name = part[0];
    int id = stoi(part[1]);
    double  balance = stod(part[2]);
    string  password = part[3];
    Employee employee(balance,id,name,password);
    return employee;
}

