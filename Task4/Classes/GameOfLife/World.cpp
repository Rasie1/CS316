#include "World.h"
#include <cmath>
#include <ostream>

using namespace std;

World::World(int w, int h, double population) :
    width(w),
    height(h),
    population(population),
    curr(height, std::vector<bool>(width)),
    next(height, std::vector<bool>(width))
{
    for (int i = 0; i < height; ++i)
    for (int j = 0; j < width ; ++j)
        next[i][j] = curr[i][j] = static_cast<bool>(random() % 2);
}

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
        else
            next[y][x] = true;
    }
    else
    {
        if (neighbors == birthPoints)
            next[y][x] = true;
    }
}

void World::step()
{
    for (int i = 0; i < height; ++i)
    for (int j = 0; j < width; ++j)
        updateCell(i, j);

    for (int i = 0; i < height; ++i)
    for (int j = 0; j < width; ++j)
        curr[i][j] = next[i][j];

}

static char visualizeCell(bool x)
{
    return x ? '@' : '.';
}

std::ostream& operator<<(std::ostream& stream, const World& world)
{
    for (auto xs : world.curr)
    {
        for (auto x : xs)
            stream << visualizeCell(x) << " ";
        stream << std::endl;
    }

    return stream;
}
