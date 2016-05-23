#include "World.h"
#include <cmath>

using namespace std;


void World::updateCell(int y, int x)
{
    int neighbors = 0;

    for (int i = max(0, y - 1); i < min(height - 1, y + 1); ++i)
    for (int j = max(0, x - 1); j < min(width  - 1, x + 1); ++j)
        neighbors += (curr[i][j] && (i != y) && (j != x)) ? 1
                                                          : 0;
    const int survivalPoints = 2;
    const int birthPoints = 3;
    const int overpopulationPoints = 4;

    if (curr[y][x])
    {
        if (neighbors >= overpopulationPoints || survivalPoints > neighbors)
            next[y][x] = false;
    }
    else
    {
        if (neighbors == birthPoints)
            next[y][x] = true;
    }
}


void World::step()
{
    for (int i = 0; i < width; ++i)
    for (int j = 0; j < height; ++j)
        updateCell(i, j);
}
