// Routine for testing matrix operations
//

// #include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<algebra.h>
#include<chrono>

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

      auto pbvStart = chrono::high_resolution_clock::now();
      vector<vector<double>> pbvMatrix = rowReduce(matrix);
      auto pbvStop = chrono::high_resolution_clock::now();
      auto pbvDuration = chrono::duration_cast<chrono::microseconds>(pbvStop - pbvStart);

      auto pbrStart = chrono::high_resolution_clock::now();
      rowReduce(&matrix);
      auto pbrStop = chrono::high_resolution_clock::now();
      auto pbrDuration = chrono::duration_cast<chrono::microseconds>(pbrStop - pbrStart);

      // TODO: once printMatrix has been rewritten, direct output to file
      // testResult << printMatrix(matrix);
      printMatrix(pbvMatrix);
      cout << pbvDuration.count() << " \u03BCs" << endl;
      pbvMatrix.clear();
      cout << "Pass by reference result:" << endl;
      printMatrix(matrix);
      cout << pbrDuration.count() << " \u03BCs" << endl;
      matrix.clear();
      cout << endl;
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
