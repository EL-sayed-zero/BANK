#pragma once
#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include<sstream>
#include"Client.h"
#include"Admin.h" //Employee inside Admin 




class ParserREad {


    // main split 
public:
    //ahmed|20|6888|300idufuf
    static vector<string> split(string line);
    
    


    static Client parse_to_client(string line);//ahmed|20|6888|300idufuf




          
         

 
        
    


    static Admin parse_to_admin(string line) ;//ahmed|20|6888|300idufuf










    static Employee parse_to_Employee(string line);


    


};
