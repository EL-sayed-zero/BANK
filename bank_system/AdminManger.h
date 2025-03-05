#pragma once
#include"FileManger.h"

class AdminManger
{

public:
	static void PrintEmployeemenu() {
		cout << "1-add client\n";
		cout << "2-clients list\n";
		cout << "3-search client\n";
		cout << "4-edit client\n";
		cout << "5-Employee list\n";
		cout << "6-add employee\n";
		cout << "7-search employee\n";
		cout << "8-logout\nenter your choise:";


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

	



	void employee_list() {
		Admin admin;
		admin.employee_list();
	}

	void add_employee(Employee employee) {
		Admin admin;
		admin.addEmployee(employee);
	}

	Employee* search_employee(int id) {
		Admin admin;
		return admin.searchemployee(id);
	}


	//
	void edit_employee(int id) {
		Admin admin;
		if (admin.searchemployee(id)) {
			int choice;
			cout<<"1-change name\n";
			cout << "2-change password\n";
			cout << "3-change salary\n";
			cout << "enter your choice:";
			cin >> choice;
				string name;
				string password;
			switch(choice)
			{
			case 1:
				cout << "enter the new name:";
				cin >> name;
				admin.searchemployee(id)->setName(name);
				break;
			case 2:
				cout << "enter the new password:";
				cin >> password;
				admin.searchemployee(id)->setPW(password);
				break;
			case 3:
				cout << "enter the new salary:";
				double salary;
				cin >> salary;
				admin.searchemployee(id)->setSalary(salary);
					break;
			}
		}
		else {
			cout << "not found";
			return;
		}
		admin.edit_employee(admin.searchemployee(id)->getId(), admin.searchemployee(id)->getName(), admin.searchemployee(id)->getPassword(), admin.searchemployee(id)->getSalary());
	}



};
