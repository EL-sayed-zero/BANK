#include "Admin.h"


Admin::Admin() {}

Admin::Admin(double salary, int id, string name, string password) :Employee(salary, id, name, password) {}

void Admin::display()
{
    cout << "admin info \n";
    Employee::display();
}

void Admin::addClient(Client& client)
{
    Employee::addClient(client);
}

void Admin::clients_list()
{
    Employee::clients_list();
}

Client* Admin::searchClient(int id)
{
    Employee::searchClient(id);
}

void Admin::edit_client(int id, string name, string password, double balance)
{
    Employee::edit_client(id, name, password, balance);
}

istream& operator>>(istream& in, Admin& admin)
{


    int temp_id;
    double temp_salary;
    string temp_pw, temp_name;

    cout << "enter Admin id " << endl;
    in >> temp_id;
    admin.setID(temp_id);
    cout << "enter Admin name " << endl;
    in >> temp_name;
    admin.setName(temp_name);
    cout << "enter Admin salary " << endl;
    in >> temp_salary;
    admin.setSalary(temp_salary);
    cout << "enter Admin password " << endl;
    in >> temp_pw;
    admin.setPW(temp_pw);


    return in;
}

ostream& operator<<(ostream& out, Admin& admin)
{

    out << "Admin Name : " << admin.getName() << endl;
    out << "Admin id : " << admin.getId() << endl;
    out << "Admin salary :" << admin.getSalary() << endl;
    out << "Admin password :" << admin.getPassword() << endl;
    out << "#################################\n";
    return out;
}

