#pragma once
#include"FileManger.h"



class EmployeeManger
{
    static void setConsoleColor(int color) {
	   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	   SetConsoleTextAttribute(hConsole, color);
    }
    
private:
    static void OptionsEditClient() {
	   cout << "1- Name Edit\n";
	   cout << "2- Password Edit \n";
	   cout << "3- Balance Edit \n";
	   cout << "4- Exit \n";
	   cout << "Enter Choice Number : ";
    }


	static void Employeemenu(){
	    setConsoleColor(1);
	    cout << "==> Empoyee Menu <==\n" << endl;
	    setConsoleColor(7);
		cout << "1-add client\n";
		cout << "2-clients list\n";
		cout << "3-search client\n";
		cout << "4-edit client\n";
		cout << "5- Delete client\n";
		cout << "6-Exit\n";
		cout << "Enter Choice Number : ";
	}
public:
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
		cout << "Please insert your id : ";
		cin >> id;
		system("cls");
		if (employee->searchClient(id) != nullptr) {
		    cout << *employee->searchClient(id);

		}
		else {

		    cout << "+-----------------------+\n|";
		    setConsoleColor(4);
		    cout << " Not found This Client ";
		    setConsoleColor(7);
		    cout << "|\n+-----------------------+\n";
		    Sleep(2000);
		    system("cls");

		}


	}
	static void delete_client(Employee* employee) {
		int id;
		cout << "please insert the id:";
		cin >> id;
		employee->delete_client(id);
		cout << "+------------------------+\n|";
		setConsoleColor(10);
		cout << "Client deleted successfully ";
		setConsoleColor(7);
		cout << "|\n+------------------------+\n";
		Sleep(2000);
		system("cls");
	}


	static void editClientInfo(Employee* employee) {
	    int id; 
	    cout << "Enter Client ID : ";
	    cin >> id;
	    Client* client = employee->searchClient(id); 
	    if (client == nullptr) {
		   cout << "+------------------------+\n|";
		   setConsoleColor(4);
		   cout << " No't Found This Client ";
		   setConsoleColor(7);
		   cout << "| \n+------------------------+\n";
		   Sleep(2000);
		   system("cls");
	    }
	    int choice;
	    string newName, newPassword;
	    double newBalance;
	    OptionsEditClient(); 
	    cin >> choice;
	    system("cls");
	    switch (choice) {
	    case 1:
		   cout << "Enter The New Name : ";
		   cin >> newName;
		   client->setName(newName);
		   cout << "+-----------------------------+\n|";
		   setConsoleColor(10);
		   cout << " Name changed successfully    ";
		   setConsoleColor(7);
		   cout << "|\n+-----------------------------+\n";
		   Sleep(2000);   
		   system("cls");

		   break;
	    case 2:
		   cout << "Enter The New Password : ";
		   cin >> newPassword;
		   client->setPW(newPassword);
		   cout << "+---------------------------------+\n|";
		   setConsoleColor(10);
		   cout << " Password changed successfully   ";
		   setConsoleColor(7);
		   cout << "|\n+---------------------------------+\n";
		   Sleep(2000);
		   system("cls");
		   break;
	    case 3:
		   cout << "Enter The New Balance : ";
		   cin >> newBalance;
		   client->setBalance(newBalance);
		   cout << "+--------------------------------+\n|";
		   setConsoleColor(10);
		   cout << " Balance changed successfully   |\n";
		   setConsoleColor(7);
		   cout << "+--------------------------------+\n";
		   Sleep(2000);
		   system("cls");
		   break;
	    case 4:
		   return;
	    default:
		   cout << "+----------------------+\n|";
		   setConsoleColor(4);
		   cout << " Incorrect Enter !!   ";
		   setConsoleColor(7);
		   cout << "|\n+----------------------+\n";
		   Sleep(3000);
		   system("cls");

	    }
	    employee->edit_client(client->getId(), client->getName(), client->getPassword(), client->getBalance());

	    delete client;
	}
	static Employee* login(int id, string password) {

		ifstream file("Employee.txt", ios::in);


		if (!file) {
		    setConsoleColor(4);
			cout << "Error opening file!\n";
			setConsoleColor(7);
			Sleep(2000);
			system("cls");
			return nullptr;
		}
		string line;


		while (getline(file, line)) {
       Employee employee= ParserREad::parse_to_Employee(line);

			if (id == employee.getId() && password == employee.getPassword()) {
			    setConsoleColor(10);
				cout << "\t\t\tLogin successful!" << endl;
				setConsoleColor(7);
				Sleep(2000);
				system("cls");
				return new Employee(employee.getSalary(), employee.getId(), employee.getName(), employee.getPassword());

			}

		}
		file.close();
		setConsoleColor(4);
		cout << "Invalid ID or Password!" << endl;
		setConsoleColor(7);
		Sleep(2000);
		system("cls");
		return nullptr;





	}

	
		
	static bool employeeOpttions(Employee* employee ) {
	
	    int choice;				    	   
	    while (true) {
			Employeemenu();
			cin >> choice;
			system("cls");
			
		   switch (choice) {

		   case 1:
			  newclient(employee);
			  system("cls");
			  break;
		   case 2:
			  listallclient(employee);
			  system("cls");
			  break;
		   case 3:
			  searchforclient(employee);
			  system("cls");
			  break;
		   case 4:
			   editClientInfo(employee);
			   system("cls");
			   break;
		   case 5:
			   delete_client(employee);
			   system("cls");
			   break;
		   case 6:
			   return false;

		   default:
			  system("cls");
			  cout << "+----------------------+\n|";
			  setConsoleColor(4);
			  cout << " Incorrect Enter !!   ";
			  setConsoleColor(7);
			  cout << "| \n+----------------------+\n";
			  Sleep(2000);
			  system("cls");

			  break;
			  
		   }



	    }


	}



};

