#include <iostream>
#include <vector>
#include <string>
#include <algebra.h>
#include <menu.h>

using namespace std;

int main()
{
  string message = "Main Menu\ntest: Enter test menu\nexit: Exit menu";
  MainMenu mainMenu = MainMenu(message);
  mainMenu.open();

  return 0;
}
