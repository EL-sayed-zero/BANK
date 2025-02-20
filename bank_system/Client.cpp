#include "Client.h"




Client::Client() {
    balance = 0;
}

Client::Client(double balance, int id, string name, string password) :Person(id, name, password) {

    while (!Validation::isMinBalance(balance)) {
        cout << "min balance  must have greater than or equal 1500" << endl;
        cout << "enter the balance again \n";
        cin >> balance;

    }

    this->balance = balance;


}

void Client::setBalance(double balance)
{
    while (!Validation::isMinBalance(balance)) {
        cout << "min balance  must have greater than or equal 1500\n";
        cin >> balance;

    }

    this->balance = balance;


}

double Client::getBalance()
{
    return balance;
}

void Client::deposite(double& amount)
{
    balance += amount;
}

void Client::withdrow(double amount)
{

    if (balance < amount) {

        cout << "you do not have enough money  for withdraw \n";
    }
    else if (amount < 0) {
        cout << "you can not wuthdraw by negative " << endl;
    }
    else {
        balance -= amount;
    }


}

void Client::transfare(double amount, Client& client)
{

    if (balance < amount) {

        cout << "you do not have enough money  for transaction" << endl;
    }
    else if (amount < 0) {
        cout << "you can not negative transaction" << endl;
    }
    else {
        balance -= amount;
        client.deposite(amount);
    }

}

void Client::checkBalance() const
{
    cout << balance << endl;
}

void Client::display()
{
    Person::display();
    cout << "balane:" << balance << endl;
    cout << "######################### \n";

}

istream& operator>>(istream& in, Client& client)
{
    int temp_id;
    double temp_balnce;
    string temp_pw, temp_name;
    cout << "enter Client balance : " << endl;
    in >> temp_balnce;
    client.setBalance(temp_balnce);
    cout << "enter Client id :  " << endl;
    in >> temp_id;
    client.setID(temp_id);
    cout << "enter Client name : " << endl;
    in >> temp_name;
    client.setName(temp_name);
    cout << "enter Client password : " << endl;
    in >> temp_pw;
    client.setPW(temp_pw);



    return in;
}

ostream& operator<<(ostream& out, Client& client)
{
    cout << "Client id : " << client.getId() << endl;
    cout << "Client name :" << client.getName() << endl;
    cout << "Client balance : " << client.getBalance() << endl;
    cout << "Client password : " << client.getPassword() << endl;
    out << "#################################\n";

    return out;
}
