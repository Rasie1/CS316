#include <iostream>

#include "World.h"

using namespace std;

int main()
{
    auto width  = 20;
    auto height = 20;
    auto population = 0.3;

    auto world = World(width, height, population);

    auto iterations = 10;

    cout << "Starting simulation with" << endl
         << "Width: " << width << endl
         << "Height: " << height << endl
         << "Population percentage: " << population << endl;

    cout << world << endl;

//    auto delay = 60;
//    world.runSingleThreaded(iterations, delay);

    cout << "Running threads: " << endl;
    int threads = 5;
    world.runMultiThreaded(iterations, threads);

    cout << "Simulation finished" << endl;

    return 0;
}
