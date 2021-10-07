#include <simulator.hpp>

class TestSystem : System
{
public:
    TestSystem(double t = 0);
    void printState();
    void advanceTime(double delta);
private:
    double time;
};

class TestModel : Model
{
public:
    static void evolve(TestSystem& system, double delta);
};