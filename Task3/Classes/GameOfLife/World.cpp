#include "World.h"
#include <cmath>

using namespace std;


void World::updateCell(int y, int x)
{
    int neighbors = 0;

    for (int i = max(0, y - 1); i < min(height - 1, y + 1); ++i)
    for (int j = max(0, x - 1); j < min(width  - 1, x + 1); ++j)
        neighbors += (isAlive[i][j] && (i != y) && (j != x)) ? 1
                                                             : 0;
    const int survivalPoints = 2;
    const int birthPoints = 3;
    const int overpopulationPoints = 4;

    if (isAlive[y][x])
    {
        if (neighbors >= overpopulationPoints || survivalPoints > neighbors)
            isAlive[y][x] = false;
    }
    else
    {
        if (neighbors == birthPoints)
            isAlive[y][x] = true;
    }
}


void World::update()
{
    for (int i = 0; i < height; ++i)
    for (int j = 0; j < height; ++j)
        updateCell(i, j);
}
