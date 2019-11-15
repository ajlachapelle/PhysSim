//

//
class Quantity
{
// public:
  // Quantity();
  // ~Quantity;

// protected:

private:
  int precision; // Significant figures, or is precision analysis needed?
  double coefficient;
  string units; // make a new class? Use a different data type?
  // Might need some generalizing in the future
  // For now, you can still define the product of two quantites as the product
  // of their coefficients and the concatenation of their units (unless there are fractional units)
  // whether the product is also of type Quantity is undecided
};

// Template class for physical objects
class physObject
{
// public:
  // physObject;
  // ~physObject;

protected:
  vector<Quantity> quantities;
  // virtual void update();
  // it's possible that update may not be necessary,
  // if evolve is handled on a per-object basis rather than on the entire system

// private:
};

//
class System
{
public:
  // System();
  // ~System();

  // addObject();


  // virtual void evolve(double dt);
  // dt (strictly forward in time, assumes all objects are synced), or target time?, or start time and dt?
  // evolve might have to be defined on a per-theory basis, and take a system as an argument
  // or, treat theories as systems that are derived from the base class,
  // if mixed theories are needed, make a copy or subsystem?

// protected:

private:
  // bool closed;
  // vector<vector<double>> quantityMatrix;
  // ^this might not need to be a permanent variable; might be better to form a matrix from quantities that are needed for analysis
  vector<physObject> objects; // May not end up needing a class for System, if there's no generalized data aside from this vector
};
