//
#include <vector>
#include <physSystem.h>

//
class TestSystem : public System
{
public:
  TestSystem(double t, double a, double v, double x);
  // State vector; encodes time, acceleration, velocity, and position
  // vector<double> state(4);
};

//
class TestModel : PhysModel
{
public:
  void evolve(System* pS, double dt);
};
