// Linear Algebra Solver

#include <iostream>
#include <vector>

using namespace std;

// Add vector 2 to vector 1
vector<double> addVectors(vector<double> v1, vector<double> v2)
{
  //if (v1.size() != v2.size())
    //throw ;
  //int size = v1.size(); // Does size have overhead, or can it be placed in the for loop declaration?
  for (int i=0; i < v1.size(); ++i)
    v1[i] += v2[i];
  return v1;
}

// Multiply a vector by a scalar
vector<double> scaleVector(vector<double> v, double scalar)
{
  //int size = v.size(); // Does size have overhead, or can it be placed in the for loop declaration?
  for (int i=0; i < v.size(); ++i)
    v[i] *= scalar;
  return v;
}

// Swap two rows of a vector matrix
vector<vector<double>> swapRows(vector<vector<double>> matrix, int rowIndex1, int rowIndex2)
{
  matrix[rowIndex1].swap(matrix[rowIndex2]);
  return matrix;
}

//
vector<vector<double>> swapPivotFast(vector<vector<double>> matrix, int pivotCol)
{
  //swap row w/ greatest entry w/ pivot
  return matrix;
}

//
vector<vector<double>> swapPivotPrecise(vector<vector<double>> matrix, int pivotCol)
{
  //if zero swap first nonzero w/ pivot
  return matrix;
}

// Row reduce a matrix to echelon form
vector<vector<double>> rowReduce(vector<vector<double>> matrix)
{
  int rowCount = matrix.size();
  //
  for(int i=0; i<rowCount; ++i)
  {
    //swapPivotPrecise();
    for (int k=i+1; k<rowCount; ++k)
    {
      vector<double> temp (scaleVector(matrix[i], -1*matrix[k][i]/matrix[i][i])); // Scale row_i so that row_i+row_k has a zero as the ith element
      matrix[k] = addVectors(matrix[k], temp);
    }
  }
  //
  for (int i=rowCount; i>0; --i)
  {
    for (int k=i-1; k>0; --k)
    {
      vector<double> temp (scaleVector(matrix[i-1], -1*matrix[k-1][i-1]/matrix[i-1][i-1])); // Scale row_i so that row_i+row_k has a zero as the ith element
      matrix[k-1] = addVectors(matrix[k-1], temp);
    }
  }
  // Scale all pivots to 1
  for(int i=0; i<rowCount; ++i)
    matrix[i] = scaleVector(matrix[i], 1/matrix[i][i]);
  return matrix;
}


void printMatrix(vector<vector<double>> matrix)
{
  for (vector<double> rowVector : matrix)
  {
    cout << "[";
    for (double component : rowVector)
    {
      cout << " " << component << " ";
    }
    cout << "]" << endl;
  }

}

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
    cout << "Initial Matrix:" << endl;
    printMatrix(coeffMatrix);
    cout << "Reduced Echelon Form Matrix:" << endl;
    coeffMatrix = rowReduce(coeffMatrix);
    printMatrix(coeffMatrix);
  }
  else
    cout << "Not solvable" << endl;
  return 0;
}
