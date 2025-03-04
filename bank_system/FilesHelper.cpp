#include "FilesHelper.h"

void FilesHelper::deleteFile(string fileName)
{
	ofstream file(fileName, ios::trunc);

	if (!file) {
		cout << "file not found to delete \n";
		return;
	}
	file.close();

}

void FilesHelper::saveLast(string fileName, int id)
{
	ofstream file(fileName);
	if (!file) {
		cout << "+----------------+\n|";

		cout << " file not found ";

		cout << "|\n+----------------+\n";
		return;
	}
	file << id;
	file.close();
}

int FilesHelper::getLast(string fileName)
{
	ifstream file(fileName);
	if (!file) {
		cout << "+----------------+\n|";

		cout << " file not found ";

		cout << "|\n+----------------+\n";
		return 0;
	}
	string line;
	while (getline(file, line))  
	return stoi(line);

}

void FilesHelper::saveClient(Client client)
{
	ofstream file("client.txt", ios::app);
	if (!file) {
		cout << "+----------------+\n|";

		cout << " file not found ";

		cout << "|\n+----------------+\n";
		return;
	}
	saveLast("lastClient.txt", client.getId());
	file << client.getName() << "|" << client.getId() << "|" << client.getBalance() << "|" << client.getPassword() << endl;
	file.close();
	cout << "+---------------------------+\n|";
	cout << " client saved successfully ";
	cout << "|\n+---------------------------+\n";

}

void FilesHelper::saveEmployee(Employee employee, string fileName, string lastfile)
{
	ofstream file(fileName, ios::app);
	if (!file) {
		cout << "+----------------+\n|";
		cout << " file not found ";
		cout << "|\n+----------------+\n";
		return;
	}
	saveLast(lastfile, employee.getId());
	file << employee.getName() << "|" << employee.getId() << "|" << employee.getSalary() << "|" << employee.getPassword() << endl;
	file.close();
	cout << "+-----------------------------+\n|";

	cout << " Employee saved successfully ";

	cout << "|\n+-----------------------------+\n";
}

void FilesHelper::getClients()
{
	ifstream file("client.txt", ios::in);
	if (!file) {
		cout << "+----------------+\n|";

		cout << " file not found ";

		cout << "|\n+----------------+\n";
		return;
	}
	string line;

	while (getline(file, line)) {
		Client client;
		client = ParserREad::parse_to_client(line);
		cout << client;

	}

}

void FilesHelper::getEmployees()
{
	ifstream file("Employee.txt", ios::in);
	if (!file) {
		cout << "+----------------+\n|";

		cout << " file not found ";

		cout << "|\n+----------------+\n";
		return;
	}
	string line;
	while (getline(file, line)) {

		Employee emp;
		emp = ParserREad::parse_to_Employee(line);
		cout << emp;
	}
}

void FilesHelper::getAdmins()
{
	ifstream file("Admin.txt", ios::in);
	if (!file) {
		cout << "+----------------+\n|";

		cout << " file not found ";

		cout << "|\n+----------------+\n";
		return;
	}
	string line;
	Admin admin;
	while (getline(file, line)) {


		admin = ParserREad::parse_to_admin(line);
		cout << admin;

	}
}

void FilesHelper::clearFile(string fileName, string lastfileid)
{
	deleteFile(fileName);

	deleteFile(lastfileid);
	cout << "+-------------------------------------------------------+\n|";

	cout << fileName << " and " << lastfileid << "  successfully deleted  ";

	cout << "|\n+-----------------------------------------------------+\n";
}



