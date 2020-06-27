// Definitions for menu objects

#include <string>

using namespace std;

// Base menu class, no defined behavior when opened
class Menu
{
public:
  Menu(string message);
  virtual void open() = 0;

protected:
  string message = "";
};

//
class MainMenu: Menu
{
public:
  MainMenu(string message);
  void open();
};

// Menu for accessing various test routines
class TestMenu: Menu
{
public:
  TestMenu(string message);
  void open();
};
