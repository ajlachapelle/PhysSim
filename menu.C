//
#include <iostream>
#include <string>
#include <menu.h>
#include <TestTheory.h>

using namespace std;

//
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
  do // while (tolower(command) != 'exit');
  {
    cout << message << endl;
    getline(cin, command);
    // Bug: when returning from tests that require input, message prints twice, presumably because a blank input stream is being read without an input prompt
    if (command == "submenu")
    {
      string newMessage = "*" + message;
      TestMenu testMenu = TestMenu(newMessage);
      testMenu.open();
    }
    if (command == "physSystem")
    {
      double t, a, v, x, dt = 0;
      cout << "Enter system state (t, a, v, x):" << endl;
      cin >> t >> a >> v >> x;
      TestSystem system = TestSystem(t, a, v, x);
      TestModel model = TestModel();
      cout << "Enter change in time:" << endl;
      cin >> dt;
      model.evolve(&system, dt);
      cout << "t: " << system.state[0] << endl << "a, " << system.state[1] << endl << "v, " << system.state[2] << endl << "x, " << system.state[3] << endl;
    }
    // if (command == rowReduce)
    // {
    //
    // }
  } while (command != "exit");
}
