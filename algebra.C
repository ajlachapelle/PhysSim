// Functions and classes for finding unknowns algebraically

#include <iostream>
#include <vector>

using namespace std;

// Change to return a char buffer, and let the caller handle output? (then change name to matrixToString or something)
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

// Add a column to a matrix
vector<vector<double>> addCol(vector<vector<double>> matrix)
{
  for (vector<double> rowVector : matrix)
    rowVector.push_back(0);
  return matrix;
}
// Remove any zero rows from a matrix
vector<vector<double>> trimRows(vector<vector<double>> matrix)
{
  for (int row=0; row<matrix.size(); ++row)
  {
    bool validEntry = false;
    for (int col=0; col<matrix[row].size() && !validEntry; ++col)
      if (matrix[row][col] != 0)
        validEntry = true;
    if (!validEntry)
    {
      matrix.erase(matrix.begin()+row);
      // matrix.shrink...
      --row;
    }
  }
  return matrix;
}

// Remove any zero columns from a matrix (excluding the last column)
vector<vector<double>> trimCols(vector<vector<double>> matrix)
{
  for (int col=0; col<matrix[0].size()-1; ++col)
  {
    bool validEntry = false;
    for (int row=0; row<matrix.size() && !validEntry; ++row)
      if (matrix[row][col] != 0)
        validEntry = true;
    if (!validEntry)
    {
      for (int row=0; row<matrix.size(); ++row)
        matrix[row].erase(matrix[row].begin()+col);
      // matrix.shrink...
      --col;
    }
  }
  return matrix;
}

// Row reduce a matrix to echelon form
vector<vector<double>> rowReduce(vector<vector<double>> matrix)//, bool fastPivot = true)
{
  int rowCount = matrix.size();
  int varCount = matrix[0].size()-1; // The number of variables/unknowns in the linear system
  vector<int> pivots; // Tracks pivot positions in the format [pRow1, pCol1, pRow2 ...]

  // Initial elimination pass; puts matrix into augmented triangular form
  // If the pivot column reaches the augmented column, we can infer that all remaining rows have been eliminated
  for(int pivotRow=0, pivotCol=0; pivotCol<varCount && pivotRow<rowCount; ++pivotCol)
  {
    bool validPivot = (matrix[pivotRow][pivotCol] != 0); // Tracks whether there are any valid pivot entries in the current column

    // Fast/greedy pivot: pivot as fast as possible, and only if necessary
    if (true)//(fastPivot)
      for (int row=pivotRow+1; row<rowCount && !validPivot; ++row)
        if (matrix[row][pivotCol] > 0)
        {
          validPivot = true;
          matrix[pivotRow].swap(matrix[row]);
        }
    // Partial pivot:
    //else if (!fastPivot)
      //for (int row=pivotRow+1; row<rowCount; ++row)

    if (validPivot)
    {
      pivots.push_back(pivotRow);
      pivots.push_back(pivotCol);

      // Elimination step
      for (int row=pivotRow+1; row<rowCount; ++row)
      {
        vector<double> temp (scaleVector(matrix[pivotRow], -1*matrix[row][pivotCol]/matrix[pivotRow][pivotCol]));
        matrix[row] = addVectors(matrix[row], temp);
      }
      ++pivotRow;
    }
  }

  // Back-substitution
  for (int i=pivots.size()-1; i>0; i-=2)
  {
    int pivotRow = pivots[i-1];
    int pivotCol = pivots[i];
    for (int row=pivotRow-1; row>=0; --row)
    {
      vector<double> temp (scaleVector(matrix[pivotRow], -1*matrix[row][pivotCol]/matrix[pivotRow][pivotCol]));
      matrix[row] = addVectors(matrix[row], temp);
    }

    // When there are no more operations to apply to the row, scale its pivot entry to 1
    // If a row is not a pivot row, then it is a zero vector, and doesn't need to be scaled
    matrix[pivotRow] = scaleVector(matrix[pivotRow], 1/matrix[pivotRow][pivotCol]);
  }
  return matrix;
}
