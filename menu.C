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
void Menu::open()
{
  char command = 0;
  do // while (command != 'Q' && command != 'q');
  {
    cout << message << endl;
    cin >> command;
    if (tolower(command) == 'n')
    {
      string newMessage = "Sub-" + message;
      Menu newTestMenu = Menu(newMessage);
      newTestMenu.open();
    }
  } while (tolower(command) != 'x');
}
