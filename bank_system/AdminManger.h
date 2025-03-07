#pragma once
#include"EmployeeManger.h"

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
	static Admin* login(int id, string password) {
	

		ifstream file("admin.txt", ios::in);


		if (!file) {
			cout << "Error opening file!\n";
			return nullptr;
		}
		string line;


		while (getline(file, line)) {

			Admin admin= ParserREad::parse_to_admin(line);

			if (admin.getId() == id && admin.getPassword() == password) {
				cout << "Login successful!" << endl;
				return new Admin(admin.getSalary(), admin.getId(), admin.getName(), admin.getPassword());

			}

		}
		file.close();
		cout << "Invalid ID or Password!" << endl;
		return nullptr;



	}

	static bool AdminOptions(Admin* admin) {
		int choice;
		Employee newemployee,*employee;
		PrintEmployeemenu();
		cin >> choice;
			switch (choice) {

			case 1:
				EmployeeManger::newclient(&newemployee);
				return true;
			case 2:
				EmployeeManger::listallclient(&newemployee);
				return true;
			case 3:
				EmployeeManger::searchforclient(&newemployee);
				return true;
			case 4:
				EmployeeManger::editClientInfo(&newemployee);
				return true;
			case 5:
				employee_list();
				return true;
			case 6:
				cin >> newemployee;
				add_employee(newemployee);
				return true;
			case 7:
				search_employee(admin);
				return true;
			default:
				cout << "+----------------------+\n";
				cout << "| Incorrect Enter !! | \n";
				cout << "+----------------------+\n";

			}
	}



	static void employee_list() {
		Admin admin;
		admin.employee_list();
	}

	static void add_employee(Employee employee) {
		Admin admin;
		admin.addEmployee(employee);
	}

	static void search_employee(Admin *admin) {
		int id;
		cout << "enter the id fo search \n";
		cin >> id;
		if (admin->searchemployee(id) != nullptr) {
			cout << admin->searchemployee(id);
		}
		else {
			cout << "Employee not found" << endl;
		}
	}


	//
	static void edit_employee(int id) {
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
