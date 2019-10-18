#include <iostream>
#include <vector>

using namespace std;

int main()
{
  char command = 0;
  vector<vector<double>> System;

  do
  {
    cout << "(A)dd an object, (P)rint matrix, or (E)xit: ";
    cin >> command;
    if (command == 'A')
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
    }
  }
  while (command != 'E');
  return 0;
}
