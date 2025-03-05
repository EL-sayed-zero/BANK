#pragma once
#include"FileManger.h"



class EmployeeManger
{
private:
    static void OptionsEditClient() {
	   cout << "1- Name Edit\n";
	   cout << "2- Password Edit \n";
	   cout << "3- Balance Edit \n";
	   cout << "4- Exit \n";
	   cout << "Enter Choice Number : ";
    }


	static void Employeemenu(){
	    cout << "==> Empoyee Menu <==\n";
		cout << "1-add client\n";
		cout << "2-clients list\n";
		cout << "3-search client\n";
		cout << "4-edit client\n";
		cout << "5-Exit\n";
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
		cout << "Please insert your id:";
		cin >> id;
		if (employee->searchClient(id) != nullptr) {
		    cout << employee->searchClient(id);
		}
		else {

		    cout << "+-----------------------+\n";
		    cout << "| Not found This Client |\n";
		    cout << "+-----------------------+\n";

		}


	}


	static void editClientInfo(Employee* employee) {
	    int id;
	    cout << "Enter Client ID : ";
	    cin >> id;
	    Client* client = employee->searchClient(id);
	    int choice;
	    string newName, newPassword;
	    double newBalance;
	    OptionsEditClient(); 
	    cin >> choice;
	    switch (id) {
	    case 1:
		   cout << "Enter The New Name : ";
		   cin >> newName;
		   client->setName(newName);
		   cout << "+-----------------------------+\n";
		   cout << "| Name changed successfully |\n";
		   cout << "+-----------------------------+\n";
		   break;
	    case 2:
		   cout << "Enter The New Password : ";
		   cin >> newPassword;
		   client->setPW(newPassword);
		   cout << "+---------------------------------+\n";
		   cout << "| Password changed successfully |\n";
		   cout << "+---------------------------------+\n";
		   break;
	    case 3:
		   cout << "Enter The New Balance : ";
		   cin >> newBalance;
		   client->setBalance(newBalance);
		   cout << "+--------------------------------+\n";
		   cout << "| Balance changed successfully |\n";
		   cout << "+--------------------------------+\n";
		   break;
	    case 4:
		   return;
	    default:
		   cout << "+----------------------+\n";
		   cout << "| Incorrect Enter !! |\n";
		   cout << "+----------------------+\n";

	    }
	    employee->edit_client(client->getId(), client->getName(), client->getPassword(), client->getBalance());

	    
	}
	static Employee* login(int id, string password) {
	  
	    Admin admin;
	    if (admin.searchemployee(id)->getId() == id && admin.searchemployee(id)->getPassword() == password) {
		   cout << "+---------------------+\n";
		   cout << "| You are logged in |\n";
		   cout << "+---------------------+\n";


		   return admin.searchemployee(id);
	    }
	    cout << "+-------------------------------+\n";
	    cout << "| This Employee No't Found !! |\n";
	    cout << "+-------------------------------+\n";

	    return nullptr;
	}
	static bool employeeOpttions(Employee* employee ) {
	
	    int choice;				    
	    Employeemenu();
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
		   case 4:
			  return false;
		   default:
			  cout << "+----------------------+\n";
			  cout << "| Incorrect Enter !! | \n";
			  cout << "+----------------------+\n";
			  
		   }



	    }


	}



};

