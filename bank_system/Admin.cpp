#include"Admin.h"
#include"FileManger.h"


Admin::Admin() {}

Admin::Admin(double salary, int id, string name, string password) :Employee(salary, id, name, password) {}

void Admin::display()
{
    cout << "admin info \n";
    Employee::display();
}
    //hi boss

void Admin::addEmployee(Employee& employee)
{
    FileManger f;
    f.add_Employee(employee);
    
}

void Admin::employee_list()
{
    FileManger f;
    f.get_all_employee();
}



Employee* Admin::searchemployee(int id) {
    ifstream file("Employee.txt", ios::in);


    if (!file) {
        cout << "Error opening file!\n";
        return nullptr;
    }
    string line;


    while (getline(file, line)) {
        
        Employee employee = ParserREad::parse_to_Employee(line);

        if (id == employee.getId()) {
            return new Employee(employee.getSalary(), employee.getId(), employee.getName(), employee.getPassword());

        }

    }
    file.close();

    return nullptr;





}

void Admin::edit_employee(int id, string name, string password, double salary) {

    int choice;
    cin >> choice;
    Employee* employee = searchemployee(choice);

    if (employee == nullptr) {
        cout << "id not found";
        return;
    }

    //edit client attributes
    employee->setID(id);
    employee->setName(name);
    employee->setSalary(salary);
    employee->setPW(password);
    ifstream Rfile("Employee.txt", ios::in);
    ofstream ofile("temp.txt");
    string line;
    while (getline(Rfile, line)) {

        Employee old_employee = ParserREad::parse_to_Employee(line);
        if (choice == old_employee.getId()) {
            ofile << employee->getName() << "|" << employee->getId() << "|" << employee->getSalary() << "|" << employee->getPassword() << endl;

        }
        else {
            ofile << line << endl;
        }


    }



    Rfile.close();
    ofile.close();

    remove("Employee.txt");
    rename("temp.txt", "Employee.txt");

    cout << "Employee updated successfully \n";

    delete employee;


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

