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
   
        return nullptr;
        
   
    
  

}

void Employee::edit_client(int id, string name, string password, double balance) {

 
    Client* client = searchClient(id);

    if (client == nullptr) {
        cout << "id not found";
        return;
    }
      
    //edit client attributes
    client->setID(id);
    client->setName(name); 
    client->setBalance(balance);
    client->setPW(password);
    ifstream Rfile("client.txt", ios::in);
    ofstream ofile("temp.txt");
    string line;
    while (getline(Rfile, line)) {

        Client old_client = ParserREad::parse_to_client(line);
        if (id == old_client.getId()) {
            ofile<<client->getName() << "|" << client->getId() << "|" << client->getBalance() << "|" << client->getPassword() << endl;

        }
        else {
            ofile << line << endl;
        }
       

    }
   


    Rfile.close();
    ofile.close();

    remove("client.txt");
    rename("temp.txt", "client.txt");


    delete client; 

   
}
void Employee::delete_client(int id)
{

    Client* client = searchClient(id);

    if (client == nullptr) {
        cout << "id not found";
        return;
    }

    //edit client attributes
    ifstream Rfile("client.txt", ios::in);
    ofstream ofile("temp.txt");
    string line;
    while (getline(Rfile, line)) {

        Client old_client = ParserREad::parse_to_client(line);
        if (id == old_client.getId()) {
            continue;
        }
        else {
            ofile << line << endl;
        }
    }



    Rfile.close();
    ofile.close();

    remove("client.txt");
    rename("temp.txt", "client.txt");

    

    delete client;



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
    out << "#################################\n";

    return out;
}



