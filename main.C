#include <iostream>
#include <vector>
#include <algebra.h>

using namespace std;

//enum equations of motion

int main()
{
  char command = 0;
  vector<vector<double>> system;

  do // while (command != 'Q' && command != 'q');
  {
    cout << "(A)dd an object, (P)rint matrix, (R)educe matrix, (T)rim matrix, (C)lear system, or (Q)uit: ";
    cin >> command;
    if (command == 'A' || command == 'a')
    {
      // Prompt for info
      // system.addObject(x, y);
      vector<double> newObject;
      double x, v, a = 0;
      cout << "Enter x v a: ";
      cin >> x >> v >> a;
      newObject.push_back(.5*a);
      newObject.push_back(v);
      newObject.push_back(x);
      cout << "Object trajectory: " << .5*a << "t^2 + " << v << "t + " << x << endl;
      system.push_back(newObject);
    }
    else if (command == 'P' || command == 'p')
      printMatrix(system);
    else if (command == 'R' || command == 'r')
      system = rowReduce(system);
    else if (command == 'T' || command == 't')
    {
      system = trimRows(system);
      system = trimCols(system);
    }
    else if (command == 'C' || command == 'c')
      system.clear();
      //system.?
  } while (command != 'Q' && command != 'q');
  return 0;
}
