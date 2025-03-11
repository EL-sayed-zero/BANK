#include"Admin.h"
#include"FileManger.h"


Admin::Admin() {}

Admin::Admin(double salary, int id, string name, string password) :Employee(salary, id, name, password) {}

void Admin::display()
{
    cout << "admin info \n";
    Employee::display();
}


void Admin::delete_admin(int id)
{
    Admin* admin = search_admin(id);

    if (admin == nullptr) {
        cout << "id not found";
        return;
    }

    //edit client attributes
    ifstream Rfile("admin.txt", ios::in);
    ofstream ofile("temp.txt");
    string line;
    while (getline(Rfile, line)) {

        Admin old_admin = ParserREad::parse_to_admin(line);
        if (id == old_admin.getId()) {
            continue;
        }
        else {
            ofile << line << endl;
        }
    }



    Rfile.close();
    ofile.close();

    remove("admin.txt");
    rename("temp.txt", "admin.txt");

    cout << "admin deleted successfully \n";

    delete admin;
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


// parent  pointer 
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

   
    Employee* employee = searchemployee(id);

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
        if (id == old_employee.getId()) {
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
void Admin::delete_employee(int id)
{

    Employee* employee = searchemployee(id);

    if (employee == nullptr) {
        cout << "id not found";
        return;
    }

    //edit client attributes
    ifstream Rfile("Employee.txt", ios::in);
    ofstream ofile("temp.txt");
    string line;
    while (getline(Rfile, line)) {

        Employee old_employee = ParserREad::parse_to_Employee(line);
        if (id == old_employee.getId()) {
            continue;
        }
        else {
            ofile << line << endl;
        }
    }



    Rfile.close();
    ofile.close();

    remove("Employee.txt");
    rename("temp.txt", "Employee.txt");

    cout << "Employee deleted successfully \n";

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
    out << "#################################\n";
    return out;
}



    Admin* Admin::search_admin(int id) {


    ifstream file("admin.txt", ios::in);


    if (!file) {
        cout << "Error opening file!\n";
        return nullptr;
    }
    string line;


    while (getline(file, line)) {

        Admin admin = ParserREad::parse_to_admin(line);

        if (admin.getId() == id) {
            return new Admin(admin.getSalary(), admin.getId(), admin.getName(), admin.getPassword());
        }
    }
    file.close();
    return nullptr;



}