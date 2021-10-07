//
#include <string>
#include <vector>

class MathVector
{
public:

protected:

private:
std::vector<double> coefficients; // Abbreviate name? Does this data type remove the need for separate quantity objects?
//Might want to switch from vector<double> to vector<Quantity> or something, to keep track of precision
// Or, add a second vector with precision info:
  // vector<int> precision;
  // vector<string/char[]/?> units;

  // string(?) getString, or overload extraction operator?
  void add(MathVector &v); // Is a return type that isn't always used inefficent?
  void scale(double s);
  double dot(MathVector &v); // static w/ both v1 and v2 as arguments, change name to dotProduct?
  // mathVector? crossProduct(mathVector &v);
  double norm();
};
