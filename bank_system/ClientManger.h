#pragma once
#include"FileManger.h"


class ClientManger
{
    static void setConsoleColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
public:

    static void printClientMenu() {
        setConsoleColor(1);
        cout << "===== Client Menu =====\n" << endl;
	   setConsoleColor(7);
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Update Password" << endl;
        cout << "6. Logout" << endl;
        cout << "Enter your choice: ";
    }

    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password (8-20 characters): ";
        cin >> newPassword;
        Employee employee;
        Client* client = employee.searchClient(person->getId());
        client->setPW(newPassword);
        employee.edit_client(client->getId(), client->getName(), client->getPassword(), client->getBalance());
        delete client;
    }

    static Client* login(int id, string password) {


        ifstream file("client.txt", ios::in);


        if (!file) {
            cout << "Error opening file!\n";
            return nullptr;
        }
        string line;


        while (getline(file, line)) {

            Client client = ParserREad::parse_to_client(line);

            if (id == client.getId() && password==client.getPassword()) {
                setConsoleColor(10);
                cout << "\t\t\t Login successful! " << endl;
			 setConsoleColor(7);

			 Sleep(1000);
			 system("cls");

                return new Client(client.getBalance(), client.getId(), client.getName(), client.getPassword());

            }

        }
        file.close();
        cout << "Invalid ID or Password!" << endl;
        return nullptr;





    }

    static bool clientOptions(Client* client) {
        int choice;
        double amount;
        int Id;
        Employee employee;

        while (true) {
            printClientMenu();
            cin >> choice;
            system("cls");
            switch (choice) {
            case 1:
                client->checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                client->deposite(amount);
                employee.edit_client(client->getId(), client->getName(), client->getPassword(), client->getBalance());
                cout << "Deposit successful!" << endl;
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                client->withdrow(amount);
                employee.edit_client(client->getId(), client->getName(), client->getPassword(), client->getBalance());
                cout << "Withdrawal successful!" << endl;
                break;
            case 4:
                cout << "Enter recipient ID: ";
                cin >> Id;
                cout << "Enter amount to transfer: ";
                cin >> amount;
                if (Id == client->getId()) {
				cout << "+---------------------------------+\n|";
				setConsoleColor(4);
				cout << " You can't transfer to yourself! " ;
				setConsoleColor(7);
				cout << "|\n+---------------------------------+\n";
                    Sleep(2000);
                    system("cls");

				break;
                }

                {
                   Employee e;
                   Client* recipient = e.searchClient(Id);
                    if (recipient) {
                        client->transfare(amount, *recipient);
                        e.edit_client(client->getId(), client->getName(), client->getPassword(), client->getBalance());
                        e.edit_client(recipient->getId(), recipient->getName(), recipient->getPassword(), recipient->getBalance());
                        cout << "Transfer successful!" << endl;
                    }
                    else {

                        cout << "Client  not found!" << endl;
                    }
                    delete recipient;
                }
                break;
            case 5:
                updatePassword(client);
                break;
            case 6:
                cout << "Logging out..." << endl;
                Sleep(3000);
                system("cls");
                   return false;
            default:
                system("cls");
			 setConsoleColor(4);
                cout << "Invalid choice, please try again." << endl;
			 setConsoleColor(7);
                Sleep(3000);
			 system("cls");
                break;
            }
        }
    }
    


 };

