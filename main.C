#include <iostream>
#include <vector>

using namespace std;

vector <double> addVectors(vector <double> v1, vector <double> v2)
{
  //if (v1.size() < v2.size)
    // Throw exception?
  int len = v1.size;
  vector <double> vSum;
  for (int i=0; i < len; i++)
    vSum.push_back(v1[i] + v2[i]);
}

vector <double> scaleVector(vector <double> v, double scalar)
{
  int len = v.size();
  vector <double> vScaled;
  for (int i=0; i < len; i++)
    vScaled.push_back(v[i] *= scalar);
  return vScaled;
}

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
  while (command != 'E');
  return 0;
}
