#pragma once
#include <vector>
#include <iosfwd>
#include <iomanip>
#include <boost/thread.hpp>
#include <boost/thread/barrier.hpp>
#include <boost/bind.hpp>

class World
{
    int width, height;
    double population;
    std::vector<std::vector<bool>> curr;
    std::vector<std::vector<bool>> next;

    void updateCell(int x, int y);
    void threadJob(int iterations, int partNumber, int parts, boost::barrier& cur_barier);
    void step();
    void step(int x0, int y0, int x1, int y1);
public:
    World(int w, int h, double population);

    void runSingleThreaded(int iterations, int delay);
    void runMultiThreaded(int iterations, int threadsNum);

    friend std::ostream& operator<<(std::ostream& stream, const World& world);
};

std::ostream& operator<<(std::ostream& stream, const World& world);
