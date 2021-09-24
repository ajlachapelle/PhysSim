// Functions and classes for finding unknowns algebraically

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//
void printMatrix(const vector<vector<double>> matrix) //>>*
{
  for (vector<double> rowVector : matrix)
  {
    cout << "[\t";
    for (double component : rowVector)
    {
      cout << component << "\t";
    }
    cout << "]" << endl;
  }
  //return ;
}

// Returns the sum of two vectors
vector<double> addVectors(vector<double> v1, vector<double> v2)
{
  //if (v1.size() != v2.size())
    //throw ;
  //int size = v1.size(); // Does size have overhead, or can it be placed in the for loop declaration?
  for (int i=0; i < v1.size(); ++i)
    v1[i] += v2[i];
  return v1;
}

// Adds vector 2 to vector 1
void addVectors(vector<double>* pV1, vector<double>* pV2)
{
  //if (pV1->size() != pV2->size())
    //throw ;
  //int size = pV1->size(); // Does size have overhead, or can it be placed in the for loop declaration?
  for (int i=0; i < pV1->size(); ++i)
    (*pV1)[i] += (*pV2)[i];
}

// Returns the scalar multiple of a vector
vector<double> scaleVector(vector<double> v, double scalar)
{
  //int size = v.size(); // Does size have overhead, or can it be placed in the for loop declaration?
  for (int i=0; i < v.size(); ++i)
    v[i] *= scalar;
  return v;
}

// Multiply a vector by a scalar
void scaleVector(vector<double>* pV, double scalar)
{
  //int size = v.size(); // Does size have overhead, or can it be placed in the for loop declaration?
  for (int i=0; i < pV->size(); ++i)
    (*pV)[i] *= scalar;
}

// Add a column to a matrix
vector<vector<double>> addCol(vector<vector<double>> matrix)
{
  for (vector<double> rowVector : matrix)
    rowVector.push_back(0);
  return matrix;
}

//
void addCol(vector<vector<double>>* pMatrix)
{
  for (vector<double> rowVector : *pMatrix)
    rowVector.push_back(0);
}

// Returns the input matrix with all zero rows removed
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

// Removes any zero rows from a matrix
void trimRows(vector<vector<double>>* pMatrix)
{
  for (int row=0; row<pMatrix->size(); ++row)
  {
    bool validEntry = false;
    for (int col=0; col<(*pMatrix)[row].size() && !validEntry; ++col)
      if ((*pMatrix)[row][col] != 0)
        validEntry = true;
    if (!validEntry)
    {
      (*pMatrix).erase((*pMatrix).begin()+row);
      // (*pMatrix).shrink...
      --row;
    }
  }
}

// Returns the input matrix with all zero columns removed (excluding the last column)
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

// Remove any zero columns from a matrix (excluding the last column)
void trimCols(vector<vector<double>>* pMatrix)
{
  for (int col=0; col<(*pMatrix)[0].size()-1; ++col)
  {
    bool validEntry = false;
    for (int row=0; row<pMatrix->size() && !validEntry; ++row)
      if ((*pMatrix)[row][col] != 0)
        validEntry = true;
    if (!validEntry)
    {
      for (int row=0; row<pMatrix->size(); ++row)
        (*pMatrix)[row].erase((*pMatrix)[row].begin()+col);
      // *pMatrix.shrink...
      --col;
    }
  }
}

// Returns the reduced echelon form matrix that is row-equivalent to the input matrix
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
      vector<double> temp(scaleVector(matrix[pivotRow], -1*matrix[row][pivotCol]/matrix[pivotRow][pivotCol]));
      matrix[row] = addVectors(matrix[row], temp);
    }

    // When there are no more operations to apply to the row, scale its pivot entry to 1
    // If a row is not a pivot row, then it is a zero vector, and doesn't need to be scaled
    matrix[pivotRow] = scaleVector(matrix[pivotRow], 1/matrix[pivotRow][pivotCol]);
  }
  return matrix;
}

// Row reduce a matrix to reduced echelon form
void rowReduce(vector<vector<double>>* pMatrix)//, bool fastPivot = true)
{
  int rowCount = pMatrix->size();
  int varCount = (*pMatrix)[0].size()-1; // The number of variables/unknowns in the linear system
  vector<int> pivots; // Tracks pivot positions in the format [pRow1, pCol1, pRow2 ...]

  // Initial elimination pass; puts matrix into augmented triangular form
  // If the pivot column reaches the augmented column, we can infer that all remaining rows have been eliminated
  for(int pivotRow=0, pivotCol=0; pivotCol<varCount && pivotRow<rowCount; ++pivotCol)
  {
    bool validPivot = ((*pMatrix)[pivotRow][pivotCol] != 0); // Tracks whether there are any valid pivot entries in the current column

    // Fast/greedy pivot: pivot as fast as possible, and only if necessary
    if (true)//(fastPivot)
      for (int row=pivotRow+1; row<rowCount && !validPivot; ++row)
        if ((*pMatrix)[row][pivotCol] > 0)
        {
          validPivot = true;
          (*pMatrix)[pivotRow].swap((*pMatrix)[row]);
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
        vector<double> temp((*pMatrix)[pivotRow]);
        scaleVector(&temp, -1*(*pMatrix)[row][pivotCol]/(*pMatrix)[pivotRow][pivotCol]);
        addVectors(&(*pMatrix)[row], &temp);
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
      vector<double> temp((*pMatrix)[pivotRow]);
      scaleVector(&temp, -1*(*pMatrix)[row][pivotCol]/(*pMatrix)[pivotRow][pivotCol]);
      addVectors(&(*pMatrix)[row], &temp);
    }

    // When there are no more operations to apply to the row, scale its pivot entry to 1
    // If a row is not a pivot row, then it is a zero vector, and doesn't need to be scaled
    scaleVector(&(*pMatrix)[pivotRow], 1/(*pMatrix)[pivotRow][pivotCol]);
  }
}
