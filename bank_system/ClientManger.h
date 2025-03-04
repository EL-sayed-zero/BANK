#pragma once
#include"FileManger.h"

class ClientManger
{

private:

    static void printClientMenu() {
        cout << "\n===== Client Menu =====" << endl;
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
        person->setPW(newPassword);
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
                cout << "Login successful!" << endl;
                return new Client(client.getBalance(), client.getId(), client.getName(), client.getPassword());

            }

        }
        file.close();
        cout << "Invalid ID or Password!" << endl;
        return nullptr;





    }
public:
    static bool clientOptions(Client* client) {
        int choice;
        double amount;
        int Id;

        while (true) {
            printClientMenu();
            cin >> choice;

            switch (choice) {
            case 1:
                client->checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                client->deposite(amount);
                cout << "Deposit successful!" << endl;
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                client->withdrow(amount);
                cout << "Withdrawal successful!" << endl;
                break;
            case 4:
                cout << "Enter recipient ID: ";
                cin >> Id;
                cout << "Enter amount to transfer: ";
                cin >> amount;

                {
                   Employee e;
                   Client* recipient = e.searchClient(Id);
                    if (recipient) {
                        client->transfare(amount, *recipient);
                        cout << "Transfer successful!" << endl;
                    }
                    else {
                        cout << "Client  not found!" << endl;
                    }
                }
                break;
            case 5:
                updatePassword(client);
                break;
            case 6:
                cout << "Logging out..." << endl;
                   return false;
            default:
                cout << "Invalid choice, please try again." << endl;
            }
        }
    }
    


 };

