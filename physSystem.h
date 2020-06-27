//

#include <vector>

//
class Quantity
{
// public:
//   Quantity();
//   ~Quantity;

// private:
//   int precision; // Significant figures, or is precision analysis needed?
//   double coefficient;
  // string units; // make a new class? Use a different data type?
  // Might need some generalizing in the future
  // For now, you can still define the product of two quantites as the product
  // of their coefficients and the concatenation of their units (unless there are fractional units)
  // whether the product is also of type Quantity is undecided
};


//
class PhysObject
{
// public:
  // PhysObject;
  // ~PhysObject;

// protected:
//   vector<Quantity> quantities;
};


// Abstraction that describes the objects/quantities/state that is being analyzed/simulated
class System
{
public:
  // System();
  // ~System();

  std::vector<double> state; // vector<double> might not work for all models, possibly create a State class?
  // void extractState();

  // addObject();

  // vector<vector<double>> quantityMatrix;
  // ^this might not need to be a permanent variable; might be better to form a matrix from quantities that are needed for analysis
  // ^how much can this be conceptually combined with state?

  // vector<PhysObject> objects; // May not end up needing a class for System, if there's no generalized data aside from this vector
  // ^ alternatively, objects might not be a necessary part of defining a physical system, and are instead derived from state
};


// Contains the physics theory that is applied to a physical system
class PhysModel
{
public:
  // Computes the change in a system's state over time (or some other parameter)
  virtual void evolve(System* pS, double delta) = 0;
};
