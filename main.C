#include <iostream>
#include <vector>

using namespace std;

//enum equations of motion

int main()
{
  char command = 0;
  vector<vector<double>> System;

  do
  {
    cout << "(A)dd an object, (P)rint matrix, or (Q)uit: ";
    cin >> command;
    switch (command)
    case
    {
      vector<double> newObject;
      double x, v, a = 0;
      cout << "Enter x v a: ";
      cin >> x >> v >> a;
      newObject.push_back(.5*a);
      newObject.push_back(v);
      newObject.push_back(x);
      cout << "Object trajectory: " << .5*a << "t^2 + " << v << "t + " << x << endl;
      System.push_back(newObject);
    }; break;
  }
  while (command != 'Q');
  return 0;
}
