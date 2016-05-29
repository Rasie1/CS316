#include <iostream>
#include <chrono>
#include <thread>
#include "World.h"

using namespace std;

int main()
{
    auto width  = 20;
    auto height = 20;
    auto population = 0.3;

    auto world = World(width, height, population);

    auto iterations = 10000;
    auto delay = 60;

    cout << "Starting simulation with" << endl
         << "Width: " << width << endl
         << "Height: " << height << endl
         << "Population percentage: " << population << endl;

    cout << world << endl;

    for (int i = 0; i < iterations; ++i)
    {
        world.step();
        cout << world << endl;
        this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    cout << "Simulation finished" << endl;

    return 0;
}
