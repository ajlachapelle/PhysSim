// Linear Algebra Solver

#include <iostream>
#include <vector>

using namespace std;

vector<double> addVectors(vector<double> v1, vector<double> v2)
{
  //if (v1.size() < v2.size)
    // Throw exception?
  int size = () ? v1.size() : ; // Does size have overhead, or can it be placed in the for loop declaration?
  vector<double> vSum (size);
  for (int i=0; i < len; ++i)
    vSum.push_back(v1[i] + v2[i]);
}

vector<double> scaleVector(vector<double> v, double scalar)
{
  int len = v.size(); // Does size have overhead, or can it be placed in the for loop declaration?
  vector<double> vScaled;
  for (int i=0; i < len; ++i)
    vScaled.push_back(v[i] *= scalar);
  return vScaled;
}

void swapVectors()
{

}

vector<vector<double>> reduceMatrix(vector<vector<double>> inMatrix)
{
  int rowCount = inMatrix.size();
  //int colCount = inMatrix[0].size(); - if we assume that all equations have the same number of unknowns, we could just check the size from an arbitrary column now
  vector<vector<double>> outMatrix (rowCount, ###);
  //
  for(int i=0; i<rowCount; ++i)
  {
    outMatrix[i].resize(inMatrix[i].size()) // If line 30 is implemented we can replace the size check with a variable; does the size check have more overhead?
    //tmp = scale(vi, -1*vi+1[i-1]/vi[i-1])
    //vi+1 = add(vi+1, tmp)
  }
  //
  return outMatrix;
}

//for()
//tmp = scale(vn-i, -1*vn-i[m-i-1]/vn[m-i-1])
//vn-i-1 = add(vn-i, tmp)
//for()
//tmp = scale (vi, 1/vi[i-1])
//vi = tmp

int main()
{
  int numEquations = 0;
  int numUnknowns = 0;
  cout << "How many equations?" << endl;
  cin >> numEquations;
  vector<vector<double>> matrix;
  cout << "How many unknowns?" << endl;
  cin >> numUnknowns;
  if (numEquations >= numUnknowns)
  {
    vector<vector<double>> coeffMatrix (numEquations, vector<double> (numUnknowns+1));
    for (int i=0; i<numEquations; ++i)
    {
      cout << "Enter coefficients of equation " << i+1 << ":";
      for (int j=0; j<numUnknowns+1; j++)
        cin >> coeffMatrix[i][j];
    }
    //coeffMatrix = reduceMatrix(coeffMatrix);
  }
  else
    cout << "Not solvable" << endl;
  return 0;
}
