//
//

#include <vector>

using namespace std;

vector<double> addVectors(vector<double> v1, vector<double> v2);
vector<double> scaleVector(vector<double> v, double scalar);
vector<vector<double>> swapRows(vector<vector<double>> matrix, int rowIndex1, int rowIndex2);

vector<vector<double>> swapPivotFast(vector<vector<double>> matrix, int pivotCol);
vector<vector<double>> swapPivotPrecise(vector<vector<double>> matrix, int pivotCol);

vector<vector<double>> rowReduce(vector<vector<double>> matrix);

void printMatrix(vector<vector<double>> matrix);

void matrixTest();
