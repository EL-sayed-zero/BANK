#include <iostream>
using namespace std;
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include"Admin.h"

#include"FileManger.h"




int main() {

	FileManger f;
	//Client c,b,a;
	//cin >> c>>b>>a;

	//f.add_Client(c);

	//f.add_Client(b);
	//f.add_Client(a);

	Employee e;
	///*Client *m=e.searchClient(2);
	//cout << *m;
	//delete m;*/

	e.edit_client(9, "hesham", "a", 900000);
   
   



}

