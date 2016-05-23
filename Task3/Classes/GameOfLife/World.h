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
    World(int w, int h, double population) :
        width(w),
        height(h),
        population(population),
        curr(height, std::vector<bool>(width)),
        next(height, std::vector<bool>(width))
    {
    }

    void step();

    std::ostream& operator<<(std::ostream& stream)
    {
        for (auto xs : curr)
        {
            for (auto x : xs)
                stream << x << " ";
            stream << std::endl;
        }

        return stream;
    }
};
