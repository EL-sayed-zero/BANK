#pragma once


#include<fstream>
#include "ParserRead.h"
#include"Admin.h"
class FilesHelper
{

    
	
	

private:

	static void deleteFile(string fileName);
	


public:


	static void saveLast(string fileName, int id);
public:

	static int getLast(string fileName);

	static void saveClient(Client client);


	static void saveEmployee(Employee employee, string fileName, string lastfile);


	static void getClients();
	
	

	static void getEmployees();

	static void getAdmins();


	static void clearFile(string fileName, string lastfileid);
		
	static void delete_record(string filename, int id);
};

