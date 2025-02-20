#include "person.h"



Person::Person() {
	id = 0;
	name;
	password;

}

Person::Person(int id, string name, string password) {



	while (!Validation::isValId(id)) {
		cout << "invalid id \n";
		cout << "enter the valid id \n";
		cin >> id;
	}
	this->id = id;
	//name validation 

	while (!Validation::isValidName(name)) {

		cout << "invalid name , must has min 5 to 20 char   " << endl;
		cout << "###############################\n";
		cout << "enter the valid Name \n";
		cin >> name;
	}
	this->name = name;


	while (!Validation::isValidPassword(password)) {

		cout << "invalid password try again " << endl;
		cout << " enter valid password  " << endl;
		cin >> password;

	}
	this->password = password;

}

void Person::setID(int id)
{


	while (!Validation::isValId(id)) {
		cout << "invalid id \n";
		cout << "enter the valid id \n";
		cin >> id;
	}
	this->id = id;

}

void Person::setName(string name) {

	while (!Validation::isValidName(name)) {

		cout << "invalid name , must has min 5 to 20 char  " << endl;
		cout << "enter the valid Name \n";
		cin >> name;
	}
	this->name = name;


}

void Person::setPW(string password) {


	while (!Validation::isValidPassword(password)) {

		cout << "invalid password try again " << endl;
		cout << " enter valid password  " << endl;
		cin >> password;

	}
	this->password = password;



}

int Person::getId()
{
	return id;
}

string Person::getName()
{
	return name;
}

string Person::getPassword()
{
	return password;
}

void Person::display()
{
	cout << "name: " << name << " \n" << "id: " << id << "\n";
}


