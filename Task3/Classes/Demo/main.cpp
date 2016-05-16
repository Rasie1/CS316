#include <iostream>
#include "World.h"

using namespace std;

int main()
{
    auto width  = 64;
    auto height = 64;
    auto population = 0.3;

    auto world = World(width, height, population);

    auto iterations = 32;

    cout << "Starting simulation with" << endl
         << "Width: " << width << endl
         << "Height: " << height << endl
         << "Population percentage: " << population << endl;

    for (int i = 0; i < 32; ++i)
    {
        world.step();
        cout << world << endl;
    }

    cout << "Simulation finished" << endl;

    return 0;
}
