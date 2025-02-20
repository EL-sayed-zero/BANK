#pragma once
#include "DataSourceInterface.h"
#include<fstream>
#include <sstream>


class FileManger :
    public DataSourceInterface

{

public:



    void add_Employee(Employee person);



    void remove_all_employee();





    void get_all_employee();



    void  add_Client(Client person);





    void  remove_clients();



    void get_all_clients();






    void add_admin(Admin admin);





    void remove_admin();





    void get_all_admin();





};

