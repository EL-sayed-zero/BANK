#pragma once

#include"Validation.h"

class Person

{

protected:
	int id;
	string name;
	string password;

public:

	Person();

	Person(int id, string name, string password);







	//setters
	void setID(int id);




	void setName(string name);

	void setPW(string password);

	//getter 

	int getId();
	string getName();
	string getPassword();



	virtual void display();









};

