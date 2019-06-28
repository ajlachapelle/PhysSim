//
//

#ifndef  OBJECT_H
#define  OBJECT_H

#include <equation.h>

class Object
{
public:
  //Object(void);
  //void Evolve(double t_0, double dt);

  Vector getPos() {return pos;} //how to group pos/vel/accel? should they be separated based on heirarchy?

private:
  Vector pos;
};

class Mass : public Object
{
public:
  Mass(void);

  double getMass();
  Vector getVel() {return vel;}
  Vector getAccel() {return accel;}

  void update(double dx, double dv);

  void Evolve(double t_0, double dt);
private:
  double mass; //units? equation data type instead of double? (then add method that evaluates as double - isn't there a special way to do this?)
  Vector vel;
  Vector accel;
};

class Force : public Object
{};

#endif
