#pragma once
#include"EmployeeManger.h"

class AdminManger
{
    static void setConsoleColor(int color) {
	   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	   SetConsoleTextAttribute(hConsole, color);
    }

public:
	static void PrintEmployeemenu() {
		cout << "1-add client\n";
		cout << "2-clients list\n";
		cout << "3-search client\n";
		cout << "4-edit client\n";
		cout << "5-Employee list\n";
		cout << "6-add employee\n";
		cout << "7-search employee\n";
		cout << "8- delete admin\n";
		cout << "9- delete employee\n";
		cout << "10- edit employee\n";
		cout << "11- logout\nenter your choise:";
		


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
		Employee newEmployee;

		while (true) {
			PrintEmployeemenu();
			cin >> choice;
			system("cls");
			switch (choice) {
			case 1:
				EmployeeManger::newclient(admin); 
				system("cls");
				break;
			case 2:
				EmployeeManger::listallclient(admin); 

				break;
			case 3:
				EmployeeManger::searchforclient(admin); 
				break;
			case 4:
				EmployeeManger::editClientInfo(admin);
				system("cls");
				break;
			case 5:
				employee_list();
				break;
			case 6:
				cout << "Enter new employee details:\n";
				cin >> newEmployee;
				add_employee(newEmployee);
				system("cls");
				break;
			case 7:
				search_employee(admin);
				break;
			case 8:
				delete_admin(admin);
				system("cls");
				break;
			case 9:
				delete_employee(admin);
				system("cls");
				break;
			case 10:
			    int id;
			    cout << "Enter the id of the employee you want to edit: ";
			    cin >> id;
			    edit_employee(id);
			    system("cls");
			    break;
			case 11:
				return false;
			default:
			    system("cls");
				cout << "+----------------------+\n|";
				setConsoleColor(4);
				cout << " Incorrect Entry !!   ";

				setConsoleColor(7);
				cout << "|\n+----------------------+\n";
				Sleep(3000);
				system("cls");
				break;
			}
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
			cout << * admin->searchemployee(id);
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
			cout << "1-change name\n";
			cout << "2-change password\n";
			cout << "3-change salary\n";
			cout << "enter your choice : ";
			cin >> choice;
			system("cls");
				string name;
				string password;
			switch(choice)
			{
			case 1:
				cout << "enter the new name : ";
				cin >> name;
				admin.searchemployee(id)->setName(name);
				system("cls");
				break;
			case 2:
				cout << "enter the new password : ";
				cin >> password;
				admin.searchemployee(id)->setPW(password);
				system("cls");
				break;
			case 3:
				cout << "enter the new salary : ";
				double salary;
				cin >> salary;
				admin.searchemployee(id)->setSalary(salary);
				system("cls");
					break;
			}
		}
		else {
		    setConsoleColor(4);
			cout << "not found";
			setConsoleColor(7);	 
			Sleep(3000); 
			system("cls");
			return;
		}
		admin.edit_employee(admin.searchemployee(id)->getId(), admin.searchemployee(id)->getName(), admin.searchemployee(id)->getPassword(), admin.searchemployee(id)->getSalary());
	}

	static void delete_employee(Admin* admin) {
		int id;
		cout << "insert the id:";
		cin >> id;
		admin->delete_employee(id);
	}
	static void delete_admin(Admin* admin) {
		int id;
		cout << "insert the id:";
		cin >> id;
		admin->delete_admin(id);
	}

};
