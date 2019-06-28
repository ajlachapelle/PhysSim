//
//

#ifndef  EQUATION_H
#define  EQUATION_H

class Term
{
public:
  Term(void);
  Term(double coeff);
  bool isKnown(void);
  double getCoeff(void) {return coeff;}
  void setCoeff(double coeff) {this->coeff = coeff;}
  void adjustCoeff(double delta) {coeff += delta;}

private:
  double coeff;
  //int degree; //What's the heirarchy like here? Degree requires that this is a polynomial term...
};

class Vector
{
public:
  Vector(void);
  Vector(double xComp, double yComp, double zComp);

  double magnitude(void);

  Term* getComp(void) {return comp;}
  void setComp(int i, double val);

  void update(double di, double dj, double dk);
private:
  Term comp[3];
};

class Equation
{
public:
  virtual void solve(void) = 0;

private:

};

class Polynomial : public Equation
{
public:
  void solve(void);

private:
  int degree;
//  int coefficients[degree+1]; //declare/specify size in header file?
};

#endif
