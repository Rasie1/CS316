#pragma once

#include <stdexcept>

template<typename T>
class Matrix
{
public:
    Matrix(size_t rows, size_t cols);

    virtual ~Matrix() {}

    T  operator()(size_t x, size_t y) const throw(std::out_of_range());
    T& operator()(size_t x, size_t y)       throw(std::out_of_range());

    size_t rows() const;
    size_t cols() const;
    std::pair<size_t, size_t> size() const;

    void resize(size_t rows, size_t cols);

private:
    size_t nRows, nCols;
    T *data;
};

#include "Matrix_Impl.h"