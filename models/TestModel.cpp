#include <TestModel.hpp>
#include <iostream>

TestSystem::TestSystem(double t)
{
    time = t;
}

void TestSystem::printState()
{
    std::cout << "Time: " << time << std::endl;
}

void TestSystem::advanceTime(double delta)
{
    time += delta;
}

void TestModel::evolve(TestSystem& system, double dt)
{
    system.advanceTime(dt);
    // system.bit = static_cast<int>(system.time % 2);
}