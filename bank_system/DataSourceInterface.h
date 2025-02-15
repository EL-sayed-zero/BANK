#pragma once
#include"Employee.h"
#include"Client.h"
#include"Admin.h"
#include<vector>
class DataSourceInterface
{
public:

	virtual void add_Employee(Employee person) = 0;
	virtual void get_all_employee() = 0;
	virtual void remove_all_employee() = 0;
	//client method 
	virtual void add_Client(Client person) = 0;
	virtual void get_add_clients() = 0;
	virtual void remove_clients() = 0;

	//admin method 
	virtual void add_admin(Admin admin)  = 0;
	virtual void get_add_admin() = 0;
	virtual void remove_admin() = 0;
};