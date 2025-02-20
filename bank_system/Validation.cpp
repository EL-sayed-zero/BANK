#include "validation.h"


bool Validation::isValidName(string name)
{

	if (name.size() < 5 || name.size() > 20) {
		return false;

	}
	for (char c : name) {

		if (!isalpha(c) || c == ' ') {
			return false;
		}
	}

	return true;
}

bool Validation::isValidPassword(string Password)
{
	if (Password.size() < 8 || Password.size() > 20) {
		return false;
	}

	for (char c : Password) {
		if (c == ' ') {
			return false;
		}
	}

	return true;

}

bool Validation::isMinBalance(double balance)
{
	return (balance >= 1500);
}
bool Validation::isValId(int id)
{
	return (id > 0);
}


bool Validation::isValidSalary(double salary)
{
	return (salary >= 500);
}

