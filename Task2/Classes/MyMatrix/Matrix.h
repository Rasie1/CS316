#pragma once

template<typename T>
class Matrix
{
public:
    Matrix() :
        rows(0),
        cols(0)
    {}

    T operator()(int x, int y)
    {
        return data[y * cols + x];
    }

private:
    int rows, cols;
    T *data;
};
