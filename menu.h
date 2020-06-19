//

#include <string>

using namespace std;

class Menu
{
public:
  Menu(string message);
  virtual void open() = 0;

protected:
  string message = "";
};

class MainMenu: Menu
{
public:
  MainMenu(string message);
  void open();
};

class TestMenu: Menu
{
public:
  TestMenu(string message);
  void open();
};
