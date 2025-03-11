#pragma once
#include "DataSourceInterface.h"
#include<fstream>
#include <sstream>
#include"FilesHelper.h"
#include <windows.h>


class FileManger :
    public DataSourceInterface

{
    static void setConsoleColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

public:

    void delete_one_record(string filename, int id) {
        FilesHelper::delete_record(filename, id);
    }

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

