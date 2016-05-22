#pragma once
#include <vector>

class World
{
    using std::vector;

    int width, height;
    double population;
    vector<vector<bool>> isAlive;

    void updateCell(int x, int y);
public:
    World(int w, int h, double population) :
        width(w),
        height(h),
        population(population),
        isAlive(height, vector<bool>(width))
    {
    }

    World nextStep();
}
