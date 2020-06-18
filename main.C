#include <iostream>
#include <vector>
#include <string>
#include <algebra.h>
#include <menu.h>

using namespace std;

int main()
{
  string message = "Menu\n(N)ew menu or E(x)it menu";
  Menu mainMenu = Menu(message);
  mainMenu.open();

  return 0;
}
