#include "Employee.h"


Employee::Employee() {
    salary = 0;
}
Employee::Employee(double salary, int id, string name, string password) :Person(id, name, password) {

    while (!Validation::isValidSalary(salary)) {
        cout << "Salary must be 5000 or more. Please enter a valid salary: \n ";
        cin >> salary;
    }

    this->salary = salary;
}

void Employee::setSalary(double salary)
{
    while (!Validation::isValidSalary(salary)) {

        cout << "Salary must be 5000 or more. Please enter a valid salary: \n ";
        cin >> salary;
    }

    this->salary = salary;
}

double Employee::getSalary()
{
    return salary;
}

void Employee::display()
{
    Person::display();
    cout << salary << endl;
    cout << "############################\n";
}


istream& operator>>(istream& in, Employee& employee)
{
    int temp_id;
    double temp_salary;
    string temp_pw, temp_name;

    cout << "enter id " << endl;
    in >> temp_id;
    employee.setID(temp_id);
    cout << "enter name " << endl;
    in >> temp_name;
    employee.setName(temp_name);
    cout << "enter salary " << endl;
    in >> temp_salary;
    employee.setSalary(temp_salary);
    cout << "enter password " << endl;
    in >> temp_pw;
    employee.setPW(temp_pw);


    return in;
}

ostream& operator<<(ostream& out, Employee& employee)
{

    cout << "id : " << employee.getId() << endl;
    cout << "name :" << employee.getName() << endl;
    cout << "Salary : " << employee.getSalary() << endl;
    cout << "password : " << employee.getPassword() << endl;
    out << "#################################\n";

    return out;
}



