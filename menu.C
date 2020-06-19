//
#include <iostream>
#include <string>
#include <menu.h>

using namespace std;

Menu::Menu(string s)
{
  message = s;
}

//
MainMenu::MainMenu(string s): Menu(s){}

//
void MainMenu::open()
{
  string command = "";
  do // while (tolower(command) != 'x');
  {
    cout << message << endl;
    getline(cin, command);
    if (command == "test")
    {
      string newMessage = "Choose a test to run";
      TestMenu testMenu = TestMenu(newMessage);
      testMenu.open();
    }
  } while (command != "exit");
}


//
TestMenu::TestMenu(string s): Menu(s){}

//
void TestMenu::open()
{
  string command = "";
  do // while (tolower(command) != 'x');
  {
    cout << message << endl;
    getline(cin, command);
    if (command == "submenu")
    {
      string newMessage = "*" + message;
      TestMenu testMenu = TestMenu(newMessage);
      testMenu.open();
    }
  } while (command != "exit");
}
