//
#include <iostream>
#include <TestTheory.h>

using namespace std;

TestSystem::TestSystem(double t, double a, double v, double x)
{
  state.push_back(t);
  state.push_back(a);
  state.push_back(v);
  state.push_back(x);
}

//
void TestModel::evolve(TestSystem* pS, double dt)
{
  pS->state[3] += pS->state[2]*dt + .5*dt*dt;
  pS->state[2] += pS->state[1]*dt;
  pS->state[0] += dt;
}
