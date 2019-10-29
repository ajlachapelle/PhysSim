#include <iostream>
#include <vector>
#include <algebra.h>

using namespace std;

//enum equations of motion

int main()
{
  char command = 0;
  vector<vector<double>> system;

  do
  {
    cout << "(A)dd an object, (P)rint matrix, or (Q)uit: ";
    cin >> command;
    if (command == 'A' || command == 'a')
    {
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
    if (command == 'P' || command == 'p')
    {
      printMatrix(system);
    }
    }
    while (command != 'Q' && command != 'q');
  return 0;
}
