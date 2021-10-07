//

#include <cmath>
#include <vector>

//
void MathVector::add(vector<double> &v) // vector<double> or mathVector?
{
  //int size = coefficients.size(); // Does size have overhead, or can it be placed in the for loop declaration?

  //if (v.size() != size)
    //throw ;

  for (int i=0; i < v.size(); ++i)
    this.coefficients[i] += v[i];
}

//
void MathVector::scale(double scalar)
{
  //int size = this.coefficients.size(); // Does size have overhead, or can it be placed in the for loop declaration?
  for (int i=0; i < this.coefficients.size(); ++i)
    this.coefficients[i] *= scalar;
}

//
double MathVector::dot(vector<double> &v) // vector<double> or mathVector?
{
  //int size = coefficients.size(); // Does size have overhead, or can it be placed in the for loop declaration?

  //if (v.size() != size)
    //throw ;

  double result = 0;
  for (int i=0; i < v.size(); ++i)
    result += this.coefficients[i]*v[i];
  return result;
}

//
double MathVector::norm()
{
    return std::sqrt(this.dot(&this)); // In places like these, you'll probably want to make a container function just in case you'll need to implement precision later on
}
