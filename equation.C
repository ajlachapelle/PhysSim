#include <equation.h>

Term::Term(void)
{
  this->coeff = 0;
}

Term::Term(double coeff)
{
  this->coeff = coeff;
}

bool Term::isKnown(void)
{
  return true;
}

Vector::Vector(void)
{
  comp[0].setCoeff(1.0);
  comp[1].setCoeff(2.0);
  comp[2].setCoeff(.5);
}

Vector::Vector(double xComp, double yComp, double zComp) // how to generalize this constructor for any number of dimensions/arguments?
{
  comp[0].setCoeff(xComp);
  comp[1].setCoeff(yComp);
  comp[2].setCoeff(zComp);
}

//Term* getComp()
//{
//  return comp;
//}

void Vector::update(double di, double dj, double dk)
{

}

void Vector::setComp(int i, double val)
{
  comp[i].setCoeff(val);
}

void Polynomial::solve()
{

}
