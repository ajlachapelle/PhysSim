#include <stdio.h>
#include <object.h>

int main(int argc, char* argv[])
{

  int dimensions = 3;
  printf("%d-dimensional problem:\n", dimensions);

  Mass testObject = Mass();


  printf("x_0 = %f\n", testObject.getPos().getComp()[0].getCoeff());
  printf("vx_0 = %f\n", testObject.getVel().getComp()[0].getCoeff());
  printf("ax_0 = %f\n", testObject.getAccel().getComp()[0].getCoeff());

  printf("y_0 = %f\n", testObject.getPos().getComp()[1].getCoeff());
  printf("vy_0 = %f\n", testObject.getVel().getComp()[1].getCoeff());
  printf("ay_0 = %f\n", testObject.getAccel().getComp()[1].getCoeff());

  printf("z_0 = %f\n", testObject.getPos().getComp()[2].getCoeff());
  printf("vz_0 = %f\n", testObject.getVel().getComp()[2].getCoeff());
  printf("az_0 = %f\n", testObject.getAccel().getComp()[2].getCoeff());

  testObject.Evolve(0.0, 10.0);

  //printf("x = %f\n", testObject.getPos().getComp()[0].getCoeff());
  //printf("y = %f\n", testObject.getVel().getComp()[0].getCoeff());
  //printf("z = %f\n", testObject.getAccel().getComp()[0].getCoeff());
}
