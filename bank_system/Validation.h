#pragma once
#include <iostream>
using namespace std;
#include<string>

class Validation
{
public:

	static bool isValidName(string name);


	static bool isValidPassword(string Password);


	static bool isMinBalance(double balance);


	static bool isValId(int id);


	static bool isValidSalary(double salary);


};

