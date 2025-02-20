#include "FileManger.h"


void FileManger::add_Employee(Employee person)
{
    FilesHelper::saveEmployee(person, "Employee.txt", "lastEmployee.txt");
}


void FileManger::remove_all_employee()
{
    FilesHelper::clearFile("Employee.txt", "lastEmployee.txt");

}



void FileManger::get_all_employee()
{
    FilesHelper::getEmployees();



}





//clients 

void FileManger::add_Client(Client person)
{
    FilesHelper::saveClient(person);
}

void FileManger::remove_clients()
{
    FilesHelper::clearFile("client.txt", "lastClient.txt");

}

void FileManger::get_all_clients()
{
    FilesHelper::getClients();
   
}
//Admin 

void FileManger::add_admin(Admin admin)
{
    FilesHelper::saveEmployee(admin, "admin.txt", "lastAdmin,txt");
}

void FileManger::remove_admin()
{
    FilesHelper::clearFile("admin.txt", "lastAdmin,txt");

}

void FileManger::get_all_admin()
{
    FilesHelper::getAdmins();
}










