#include "FileManger.h"


void FileManger::add_Employee(Employee person)
{

    fstream file("Employee.txt");
    if (!file) {
        ofstream employeefile("Employee.txt");
        file << person.getName() << "|";
        file << person.getId() << "|";
        file << person.getSalary() << "|";
        file << person.getPassword() << "\n";
        file.close();
        employeefile.close();
        return;
    }
    file << person.getName() << "|";
    file << person.getId() << "|";
    file << person.getSalary() << "|";
    file << person.getPassword() << "\n";
    file.close();
}
//
//void FileManger::remove_all_employee()
//{
//
//}



void FileManger::get_all_employee()
{
    ifstream file("Employee.txt", ios::in);
    string line;


    while (getline(file, line)) {

        stringstream strs(line);  //cut 
        string id, salary, name, password;

        getline(strs, name, '|');
        getline(strs, id, '|');
        getline(strs, salary, '|');
        getline(strs, password, '\n');


        int temp_id = stoi(id);
        int temp_salary = stod(salary);

        Employee temp(temp_salary, temp_id, name, password);
        temp.display();

    }

    file.close();


}
//clients 

void FileManger::add_Client(Client person)
{

    ofstream file("client.txt", ios::app);
    if (!file.good()) {
        cout << "There was an error with the file." << endl;
        return;
    }
    file << person.getName() << "|";
    file << person.getId() << "|";
    file << person.getBalance() << "|";
    file << person.getPassword() << "\n";
    file.close();
}

void FileManger::remove_clients()
{
    ofstream file("client.txt", ios::trunc);
    if (!file) {
        cout << "There was an error with the file.";
        return;
    }

    file.close();

}

void FileManger::get_all_clients()
{

    ifstream file("client.txt", ios::in);
    if (!file) {
        cout << "there was an erroe with file ";
        return;
    }

    string line;


    while (getline(file, line)) {

        cout << line << endl;


    }
}
//Admin 

void FileManger::add_admin(Admin admin)
{
    ofstream file("admin.txt", ios::app);

    if (!file) {
        cout << "file not exist ";
        return;
    }
    file << admin.getName() << "|";
    file << admin.getId() << "|";
    file << admin.getSalary() << "|";
    file << admin.getPassword() << "\n";
    file.close();
}

void FileManger::remove_admin()
{

    ofstream file("admin.txt", ios::trunc);
    if (!file) {
        cout << "there was an erroe with file ";
        return;

    }
    file.close();
}

void FileManger::get_all_admin()
{
    ifstream file("admin.txt", ios::in);
    if (!file) {
        cout << " can not find file";
        return;
    }

    string line;
    while (getline(file, line)) {

        cout << line << endl;

    }

    file.close();

}










