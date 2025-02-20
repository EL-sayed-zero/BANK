#pragma once
#include <iostream>
#include< windows.h >
#include <fstream>
#include <string>
#include<sstream>
#include"Client.h"
#include"Admin.h"
#include"Employee.h"
//#include"ParserRead.h"
using namespace std;
class FileHelper
{

    static void setConsoleColor(int color) {
	   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	   SetConsoleTextAttribute(hConsole, color);
    }

    static void saveLast(string fileName, int id) {
	   ofstream file(fileName);
	   if (!file) {
		  cout << "+----------------+\n|";
		  setConsoleColor(4);
		  cout << " file not found ";
		  setConsoleColor(7);
		  cout << "|\n+----------------+\n";
		  return;
	   }
	   file << id;
	   file.close();
    }
public:

    static int getLast(string fileName) {
	   ifstream file(fileName);
	   if (!file) {
		  cout << "+----------------+\n|";
		  setConsoleColor(4);
		  cout << " file not found ";
		  setConsoleColor(7);
		  cout << "|\n+----------------+\n";
		  return 0;
	   }
	   string line;
	   while (getline(file, line)) {}
	   return stoi(line);

    }
    static void saveClient(Client client) {
	   ofstream file("clint.txt", ios::app);
	   if (!file) {
		  cout << "+----------------+\n|";
		  setConsoleColor(4);
		  cout << " file not found ";
		  setConsoleColor(7);
		  cout << "|\n+----------------+\n";
		  return;
	   }
	   saveLast("clientLastId.txt", client.getId());
	   file << client.getName() << "|" << client.getId() << "|" << client.getBalance() << "|" << client.getPassword() << endl;
	   file.close();
	   cout << "+---------------------------+\n|";
	   setConsoleColor(10);
	   cout << " client saved successfully ";
	   setConsoleColor(7);
	   cout << "|\n+---------------------------+\n";

    }
    static void saveEmployee(Employee employee) {
	   ofstream file("Employee.txt", ios::app);
	   if (!file ) {
		  cout << "+----------------+\n|";
		  setConsoleColor(4);
		  cout << " file not found ";
		  setConsoleColor(7);
		  cout << "|\n+----------------+\n";
	   }
	   saveLast("employeeLastId.txt", employee.getId()); // save last id 
	   file << employee.getId() << "|" << employee.getName() << "|" << employee.getSalary() << "|" << employee.getPassword() << endl;
	   file.close();
	   cout << "+-----------------------------+\n|";
	   setConsoleColor(10);
	   cout << " Employee saved successfully ";
	   setConsoleColor(7);
	   cout << "|\n+-----------------------------+\n";
    }
    static void getClients() {
	   ifstream file("client.txt", ios::in);
	   if (!file) {
		  cout << "+----------------+\n|";
		  setConsoleColor(4);
		  cout << " file not found ";
		  setConsoleColor(7);
		  cout << "|\n+----------------+\n";
		  return;
	   }
	   string line;
	   while (getline(file, line)) {
		  for (int i = 0; i < line.size(); i++)
		  {
			 if (line[i] == '|') {
				cout << " ";
			 }
			 else {
				cout << line[i];
			 }

		  }
		  cout << endl;
	   }
    }

    static void getEmployees() {

	   ifstream file("Employee.txt", ios::in);
	   if (!file) {
		  cout << "+----------------+\n|";
		  setConsoleColor(4);
		  cout << " file not found ";
		  setConsoleColor(7);
		  cout << "|\n+----------------+\n";
		  return;
	   }
	   string line;
	   while (getline(file, line)) {
		  for (int i = 0; i < line.size(); i++)
		  {
			 if (line[i] == '|') {
				cout << " ";
			 }
			 else {
				cout << line[i];
			 }

		  }
		  cout << endl;
	   }


    }

    static void getAmins() {
	   ifstream file("Admin.txt", ios::in);
	   if (!file) {
		  cout << "+----------------+\n|";
		  setConsoleColor(4);
		  cout << " file not found ";
		  setConsoleColor(7);
		  cout << "|\n+----------------+\n";
		  return;
	   }
	   string line;
	   while (getline(file, line)) {
		  for (int i = 0; i < line.size(); i++)
		  {
			 if (line[i] == '|') {
				cout << " ";
			 }
			 else {
				cout << line[i];
			 }

		  }
		  cout << endl;
	   }
    }


   


};

