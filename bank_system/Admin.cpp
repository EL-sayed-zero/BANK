#include "Admin.h"


Admin::Admin() {}

Admin::Admin(double salary, int id, string name, string password) :Employee(salary, id, name, password) {}

void Admin::display()
{
    cout << "admin info \n";
    Employee::display();
}

istream& operator>>(istream& in, Admin& admin)
{


    int temp_id;
    double temp_salary;
    string temp_pw, temp_name;

    cout << "enter id " << endl;
    in >> temp_id;
    admin.setID(temp_id);
    cout << "enter name " << endl;
    in >> temp_name;
    admin.setName(temp_name);
    cout << "enter salary " << endl;
    in >> temp_salary;
    admin.setSalary(temp_salary);
    cout << "enter password " << endl;
    in >> temp_pw;
    admin.setPW(temp_pw);


    return in;
}

ostream& operator<<(ostream& out, Admin& admin)
{

    out << "Name : " << admin.getName() << endl;
    out << "id : " << admin.getId() << endl;
    out << "salary :" << admin.getSalary() << endl;
    out << "password :" << admin.getPassword() << endl;
    out << "#################################\n";
    return out;
}

