#pragma once

#include< windows.h >
#include <fstream>
#include "ParserRead.h"

class FilesHelper
{

	static void saveLast(string fileName, int id) {
		ofstream file(fileName);
		if (!file) {
			cout << "+----------------+\n|";
		
			cout << " file not found ";
		
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
		
			cout << " file not found ";
	
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
	
			cout << " file not found ";
		
			cout << "|\n+----------------+\n";
			return;
		}
		saveLast("clientLastId.txt", client.getId());
		file << client.getName() << "|" << client.getId() << "|" << client.getBalance() << "|" << client.getPassword() << endl;
		file.close();
		cout << "+---------------------------+\n|";
		cout << " client saved successfully ";
		cout << "|\n+---------------------------+\n";

	}
	static void saveEmployee(Employee employee) {
		ofstream file("Employee.txt", ios::app);
		if (!file) {
			cout << "+----------------+\n|";
			cout << " file not found ";
			cout << "|\n+----------------+\n";
		}
		saveLast("employeeLastId.txt", employee.getId()); // save last id 
		file << employee.getId() << "|" << employee.getName() << "|" << employee.getSalary() << "|" << employee.getPassword() << endl;
		file.close();
		cout << "+-----------------------------+\n|";
	
		cout << " Employee saved successfully ";
	
		cout << "|\n+-----------------------------+\n";
	}
	static void getClients() {
		ifstream file("client.txt", ios::in);
		if (!file) {
			cout << "+----------------+\n|";
	
			cout << " file not found ";

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
	
			cout << " file not found ";
	
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
	
			cout << " file not found ";

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

