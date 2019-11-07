// Routine for testing matrix operations
//

// #include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algebra.h>

using namespace std;

// TODO: Review stdio implementation of printMatrix and file input/output
int main()
{
  ifstream testSet("matrixTestSet");
  // ofstream testResult("matrixTestResult");
  vector<vector<double>> matrix;

  string line;
  while (getline(testSet, line))
  {
    if (line == "")
    {
      // printMatrix(matrix);
      // cout << endl;
      matrix = rowReduce(matrix);
      // TODO: once printMatrix has been rewritten, direct output to file
      // testResult << printMatrix(matrix);
      printMatrix(matrix);
      matrix.clear();
      cout << endl << endl;
    }
    else
    {
      vector<double> rowVector;
      double entry;
      istringstream ls(line);
      while (ls >> entry)
      {
        rowVector.push_back(entry);
      }
      matrix.push_back(rowVector);
    }
  }
}
