#pragma once
#include"FileManger.h"



class EmployeeManger
{
	static void Employeemenu(){
		cout << "1-add client\n";
		cout << "2-clients list\n";
		cout << "3-search client\n";
		cout << "4-edit client\n";
	}
	static void newclient(Employee* employee) {
		Client client;
		cin >> client;
		employee->addClient(client);
	}

	static void listallclient(Employee* employee) {
		employee->clients_list();
	}

	static void searchforclient(Employee* employee) {
		int id;
		cout << "Please insert your id:";
		cin >> id;
		employee->searchClient(id);
	}

};

