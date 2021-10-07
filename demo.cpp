#include <iostream>
#include <TestModel.hpp>

using namespace std;

int main()
{
    TestSystem testSystem;
    testSystem.printState();
    TestModel::evolve(testSystem, 1.0);
    testSystem.printState();
    return 0;
}
