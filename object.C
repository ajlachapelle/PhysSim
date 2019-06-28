//
//

#include <stdio.h>
#include <object.h>
#include <equation.h>

//Notes on eventual features: modularize the Evolve/update/resolve/etc function(s) to generally support different physical paradigms (even hypothetical ones)
//(cont.) also, generalize the simulator so that it is not reliant on a global clock, but is capable of working with one

//Object::Object(void)
//{
//  getPos().getComp()[0].setCoeff(0);
//}

Mass::Mass(void) //overloading (right term?) the constructor will probably be needed to set up different knowns/unknowns and such in the constructor
{
  mass = 1.0; //Write helper function: promptFor? handles whether the value is known or not, converts to the right data type, etc
  getPos().getComp()[0].setCoeff(1.0);
  getVel().getComp()[0].setCoeff(1.0);
  getAccel().getComp()[0].setCoeff(1.0);
}

void Mass::update(double dx, double dv)
{
  //Change name to updateDimension/updateDim?
  //Possible alt implementation: take care of appropriate physics in the update function for the physical object, whereas Evolve handles the specifics of updating a system
  pos.update(dx)
  vel.update(dv);
  //accel.update(dx'', dy'', dz'');
}

void Mass::Evolve(double t_0, double dt)
{
  //Might want to rewrite this as a switch statement, eventually
  int dimensions = 3; //Need to access the global(?) dimension value instead of hard coding
  double t = t_0 + dt;

  printf("Evolving system over the next %f seconds:\n", dt);
  //Note: think over how working backwards can/can't work, currently evolve is a one-way ticket; it permanently overwrites old t_0, x_0, v_0, a_0 values

  for (int i=0; i<dimensions; i++)
  {
    if (getAccel().getComp()[i].isKnown()) //To add: if accel is not known, try to solve for accel using F=ma
    {
      if (getVel().getComp()[i].isKnown())
      {
        if (getPos().getComp()[i].isKnown())
        {
          //might be more clear to do this via an update helper function
          //pos.comp[i].coeff += t*vel.comp[i].coeff + .5*t*t*accel.comp[i].coeff;
          //vel.comp[i].coeff += t*accel.comp[i].coeff;

          printf("Dimension-%i:\n", i+1);

          double dx = ;
          double dv' = ;

          printf("adjust position by: %f\n", t*getVel().getComp()[i].getCoeff() + .5*t*t*getAccel().getComp()[i].getCoeff());
          printf("adjust velocity by: %f\n", t*getAccel().getComp()[i].getCoeff());

          //Might need helper functions that get pointers/set values when you want to get the object and change the value,
          //not certain but it seems like the use of adjustCoeff adjusts a local copy instead of the actual coefficient
          //(this seems to be an issue with the Mass constructor when testObject is created; coefficients are not set properly)
          getPos().getComp()[i].adjustCoeff(t*getVel().getComp()[i].getCoeff() + .5*t*t*getAccel().getComp()[i].getCoeff());
          getVel().getComp()[i].adjustCoeff(t*getAccel().getComp()[i].getCoeff());
          //assume for now constant acceleration, but try to implement dynamic accel eventually (you'll probably need integral math, and a way to store an equation as the value of accel)
        }
      }
    }
  }
}
