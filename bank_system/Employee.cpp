#include "Employee.h"
#include"FileManger.h"


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

void Employee::addClient(Client& client)
{
    FileManger f;
    f.add_Client(client);
}

void Employee::clients_list()
{
    FileManger f;
    f.get_all_clients();
}





Client *Employee::searchClient(int id) {
    ifstream file("client.txt", ios::in);


    if (!file) {
        cout << "Error opening file!\n";
        return nullptr;
    }
    string line;
   

    while (getline(file, line)) {
       
       Client client = ParserREad::parse_to_client(line);

        if (id == client.getId()) {
            return new Client(client.getBalance(), client.getId(), client.getName(),client.getPassword());
         
        }
       
        }
    file.close();
   
        cout << "id not found";
        return nullptr;
        
   
    
  

}

void edit_client(int id, string name, string password, double balance) {
    fstream file("client.txt", ios::in);
    if (!file) {
        cout << "may br something wrong in client file !\n";
        return;
    }
    string line;
    vector<Client>clients;
    while (getline(file, line)) {
        clients.push_back(ParserREad::parse_to_client(line));
    }
    file.close();
    FileManger f;
    f.remove_clients();
    for (int i = clients.size() - 1; i > -1; i--) {
        if (clients[i].getId() == id) {
            clients[i].setName(name);
            clients[i].setBalance(balance);
            clients[i].setPW(password);
            f.add_Client(clients[i]);
        }
        f.add_Client(clients[i]);

    }
}




istream& operator>>(istream& in, Employee& employee)
{
    int temp_id;
    double temp_salary;
    string temp_pw, temp_name;

    cout << "enter Employee id " << endl;
    in >> temp_id;
    employee.setID(temp_id);
    cout << "enter Employee name " << endl;
    in >> temp_name;
    employee.setName(temp_name);
    cout << "enter Employee salary " << endl;
    in >> temp_salary;
    employee.setSalary(temp_salary);
    cout << "enter Employee password " << endl;
    in >> temp_pw;
    employee.setPW(temp_pw);


    return in;
}

ostream& operator<<(ostream& out, Employee& employee)
{

    cout << "Employee id : " << employee.getId() << endl;
    cout << "Employee name :" << employee.getName() << endl;
    cout << "Employee Salary : " << employee.getSalary() << endl;
    cout << "Employee password : " << employee.getPassword() << endl;
    out << "#################################\n";

    return out;
}



