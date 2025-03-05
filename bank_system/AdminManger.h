#pragma once
#include"FileManger.h"

class AdminManger
{
	static void PrintEmployeemenu() {
		cout << "1-add client\n";
		cout << "2-clients list\n";
		cout << "3-search client\n";
		cout << "4-edit client\n";
		cout << "5-logout\nenter your choise:";
	}
	Admin* login(int id, string password) {
		Admin admin;
		if (admin.searchemployee(id)->getId() == id && admin.searchemployee(id)->getPassword() == password) {
			cout << "welcome back\n";
		}
		else {
			cout << "not found\n";
		}
	}

	static bool AdminOptions(Employee* employee) {
		int choice;
		PrintEmployeemenu();
		cin >> choice;
		while (true) {
			switch (choice) {

			case 1:
				newclient(employee);

				return true;
			case 2:
				listallclient(employee);
				
				return true;
			case 3:
				searchforclient(employee);
				
				return true;
			case 5:
				return false;
			default:
				cout << "+----------------------+\n";
				cout << "| Incorrect Enter !! | \n";
				cout << "+----------------------+\n";

			}



		}
	}


};
