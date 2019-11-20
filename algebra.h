//
//

#include <vector>

using namespace std;

vector<double> addVectors(vector<double> v1, vector<double> v2);
void addVectors(vector<double>* v1, vector<double>* v2);

vector<double> scaleVector(vector<double> v, double scalar);
void scaleVector(vector<double>* v, double scalar);

vector<vector<double>> addCol(vector<vector<double>> matrix);
void addCol(vector<vector<double>>* matrix);

vector<vector<double>> trimRows(vector<vector<double>> matrix);
vector<vector<double>> trimCols(vector<vector<double>> matrix);
void trimRows(vector<vector<double>>* matrix);
void trimCols(vector<vector<double>>* matrix);

vector<vector<double>> rowReduce(vector<vector<double>> matrix);
void rowReduce(vector<vector<double>>* matrix);

void printMatrix(vector<vector<double>> matrix);
