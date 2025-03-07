#pragma once
#include"AdminManger.h"
#include"ClientManger.h"
#include"EmployeeManger.h"
#include <windows.h>
class Screen
{

    static void setConsoleColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
public:
    static void printThankYou() {


        cout <<" /$$$$$$$$ /$$                           /$$             /$$     /$$                   \n";
        cout <<"|__  $$__/| $$                          | $$            |  $$   /$$/                   \n";
        cout <<"   | $$   | $$$$$$$   /$$$$$$  /$$$$$$$ | $$   /$$       \  $$ /$$//$$$$$$  /$$   /$$  \n";
        cout <<"   | $$   | $$__  $$ |____  $$| $$__  $$| $$  /$$/        \  $$$$//$$__  $$| $$  | $$  \n";
        cout <<"   | $$   | $$  \ $$  /$$$$$$$| $$  \ $$| $$$$$$/          \  $$/| $$  \ $$| $$  | $$  \n";
        cout <<"   | $$   | $$  | $$ /$$__  $$| $$  | $$| $$_  $$           | $$ | $$  | $$| $$  | $$  \n";
        cout <<"   | $$   | $$  | $$|  $$$$$$$| $$  | $$| $$ \  $$          | $$ |  $$$$$$/|  $$$$$$/  \n";
        cout <<"   |__/   |__/  |__/ \_______/|__/  |__/|__/  \__/          |__/  \______/  \______/   \n";
                                                                                     
                                                                                     
                                                                                     

        
                                                                                     
                                                                                     
                                                                                     



    }

 static void bankName() {

             setConsoleColor(11);
             cout << "\t\t//$$$$$$\\   $$\\     $$\\    $$$$$$\\               $$\\    $$$$$$$\\                      $$\\       \n";
             cout << "\t\t$$  __$$\\  \\$$\\   $$  |  $$  __$$\\              \\$$\\   $$  __$$\\                     $$ |      \n";
             cout << "\t\t$$ /  \\__|  \\$$\\ $$  /   $$ /  $$ |              \\$$\\  $$ |  $$ | $$$$$$\\  $$$$$$$\\  $$ |  $$\\ \n";
             cout << "\t\t\\$$$$$$\\     \\$$$$  /    $$$$$$$$ |               \\$$\\ $$$$$$$\\ | \\____$$\\ $$  __$$\\ $$ | $$  |\n";
             cout << "\t\t \\____$$\\     \\$$  /     $$  __$$ |               $$  |$$  __$$\\  $$$$$$$ |$$ |  $$ |$$$$$$  / \n";
             cout << "\t\t$$\\   $$ |     $$ |      $$ |  $$ |              $$  / $$ |  $$ |$$  __$$ |$$ |  $$ |$$  _$$<  \n";
             cout << "\t\t\\$$$$$$  |     $$ |      $$ |  $$ |             $$  /  $$$$$$$  |\\$$$$$$$ |$$ |  $$ |$$ | \\$$\\ \n";
             cout << "\t\t \\______/$$$$$$\\__|$$$$$$\\__|  \\__|$$$$$$\\$$$$$$\\__/   \\_______/  \\_______|\\__|  \\__|\\__|  \\__|\n";
             cout << "\t\t         \\______|  \\______|        \\______\\______|                                             \n";
             cout << "\t\t                                                                                               \n";
             setConsoleColor(7);
             Sleep(5000);
             system("cls");

         }
 



 static void welcome() {
     setConsoleColor(11);
     cout << "\t\t                         /$$                                                  \n";
     cout << "\t\t                        | $$                                                  \n";
     cout << "\t\t /$$  /$$  /$$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$        \n";
     cout << "\t\t| $$ | $$ | $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$      \n";
     cout << "\t\t| $$ | $$ | $$| $$$$$$$$| $$| $$      | $$  \\ $$| $$ \\ $$ \\ $$| $$$$$$$$    \n";
     cout << "\t\t| $$ | $$ | $$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/      \n";
     cout << "\t\t|  $$$$$/$$$$/|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$      \n";
     cout << "\t\t \\_____/\___/  \\_______/|__/ \\_______/ \\______/ |__/ |__/ |__/ \\_______/ \n";
     cout << "\t\t                                                                              \n";
     cout << "\t\t                                                                               \n";
     setConsoleColor(7);
     Sleep(3000);
     system("cls");

 }


      static void loginOptions() {

          cout << "\nLogin as:" << endl;
          cout << "1. Client" << endl;
          cout << "2. Employee" << endl;
          cout << "3. Admin" << endl;
          cout << "4. Exit" << endl;
          cout << "Enter your choice: ";

     }



      static void invalid(int c) {
          cout << "\nInvalid choice (" << c << ")! Please try again.\n" << endl;
      }


      static int loginAs() {
          int choice;
          loginOptions();
          cin >> choice;

          while (choice < 1 || choice > 4) {
              invalid(choice);
              loginOptions();
              cin >> choice;
          }

          return choice;
      }


      static void logout() {
          exit(0);
      }


      static void loginscreen() {
          int choise,id;
          string password;
          loginOptions();
          cin >> choise;
         
          while (true) {
              switch (choise)
              {
              case 1:
                  cout << "insert your id : ";
                  cin >> id;
                  cout << "insert your password:";
                  cin >> password;
                  ClientManger::login(id, password);
                  ClientManger::clientOptions(ClientManger::login(id, password));

                  break;
              case 2:
                  cout << "insert your id:";
                  cin >> id;
                  cout << "insert your password:";
                  cin >> password;
                  EmployeeManger::login(id, password);
                  EmployeeManger::employeeOpttions(EmployeeManger::login(id, password));

                  break;
              case 3:
                  cout << "insert your id:";
                  cin >> id;
                  cout << "insert your password:";
                  cin >> password;
                  AdminManger::login(id, password);
                  AdminManger::AdminOptions(AdminManger::login(id, password));
                  break;
              case 4:
                  printThankYou();
                  logout();

                  break;
              default:
                  break;
              }
          }
      }

      static void runApp() {
          welcome();
          bankName();
          loginscreen();


      }


};


   











