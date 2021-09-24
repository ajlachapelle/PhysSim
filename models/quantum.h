//
#include <vector>
#include <physSystem.h>

//
class QuantumSystem : public System
{
public:
  // QuantumSystem();
  // vector<Quantity> qState;
};

//
class IsingModel : PhysModel
{
public:
void evolve(QuantumSystem* pS, double dt);
};
