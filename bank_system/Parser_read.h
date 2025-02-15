//#pragma once
//#include <iostream>
//using namespace std;
//#include<string>
//#include<vector>
//#include<sstream>
//
//class Parser_read
//{
//public:
//    stream file("admin.txt", ios::in);
//    if (!file) {
//        cout << " can not find file";
//        exit(0);
//    }
//    vector<Admin>admins;
//    string line;
//    while (getline(file, line)) {
//
//        stringstream strs(line);
//        string id, salary, name, password;
//
//        getline(strs, name, '|');
//        getline(strs, id, '|');
//        getline(strs, salary, '|');
//        getline(strs, password, '\n');
//
//
//        int temp_id = stoi(id);
//        int temp_salary = stod(salary);
//
//        Admin admin(temp_salary, temp_id, name, password);
//        admins.push_back(admin);
//
//    }
//
//    file.close();
//    return admins;
//
//}
//
//};
//
