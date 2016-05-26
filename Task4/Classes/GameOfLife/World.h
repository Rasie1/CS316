#pragma once
#include <vector>
#include <iosfwd>
#include <iomanip>

class World
{
    int width, height;
    double population;
    std::vector<std::vector<bool>> curr;
    std::vector<std::vector<bool>> next;

    void updateCell(int x, int y);
public:
    World(int w, int h, double population);

    void step();

    friend std::ostream& operator<<(std::ostream& stream, const World& world);
};

std::ostream& operator<<(std::ostream& stream, const World& world);
