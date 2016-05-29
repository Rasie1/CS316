#include "World.h"
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>

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

    for (int i = max(0, y - 1); i <= min(height - 1, y + 1); ++i)
    for (int j = max(0, x - 1); j <= min(width  - 1, x + 1); ++j)
    {
        if (curr[i][j] && !((i == y) && (j == x)))
            neighbors++;
    }
    const int survivalPoints = 2;
    const int birthPoints = 3;
    const int overpopulationPoints = 4;

    if (curr[y][x])
    {
        next[y][x] = (neighbors < overpopulationPoints && neighbors >= survivalPoints) && curr[y][x];
    }
    else
    {
        next[y][x] = (neighbors == birthPoints);
    }
}

void World::step()
{
    step(0, 0, width, height);
}

void World::step(int x0, int y0, int x1, int y1)
{
    for (int i = y0; i < y1; ++i)
    for (int j = x0; j < x1; ++j)
        updateCell(i, j);

    for (int i = y0; i < y1; ++i)
    for (int j = x0; j < x1; ++j)
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

void World::runSingleThreaded(int iterations, int delay)
{
    for (int i = 0; i < iterations; ++i)
    {
        step();
        cout << *this << endl;
        this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

boost::mutex io_mutex;

void World::threadJob(int iterations, int partNumber, int parts, boost::barrier& cur_barier)
{
    int h = height / parts;
    int x0 = 0;
    int y0 = partNumber * h;
    int x1 = width;
    int y1 = partNumber * (h + 1);

    for (int iteration = 0; iteration < iterations; iteration++)
    {
        for (int i = y0; i < y1; ++i)
        for (int j = x0; j < x1; ++j)
            updateCell(i, j);

        {
            cur_barier.wait();
            boost::lock_guard<boost::mutex> locker(io_mutex);

            for (int i = y0; i < y1; ++i)
            for (int j = x0; j < x1; ++j)
                curr[i][j] = next[i][j];
        }
        {
            cur_barier.wait();
            boost::lock_guard<boost::mutex> locker(io_mutex);

            std::cout << "Iteration " << iteration << " on thread " << partNumber << endl
                      << *this << endl;
        }
        {
            cur_barier.wait();
            boost::lock_guard<boost::mutex> locker(io_mutex);
        }
    }

}

void World::runMultiThreaded(int iterations, int threadsNum)
{
    boost::barrier bar(threadsNum);

    auto threads = std::vector<boost::thread>();
    for (int i = 0; i < threadsNum; ++i)
    {
        threads.push_back(boost::thread(boost::bind(&World::threadJob,
                                                    this,
                                                    iterations,
                                                    i,
                                                    threadsNum,
                                                    boost::ref(bar)
                                                    )));
    }

    for (int i = 0; i < threadsNum; ++i)
        threads[i].join();
}
