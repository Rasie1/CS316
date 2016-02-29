#pragma once
#include <stdexcept>
#include <iostream>
#include <iomanip>

template<typename T>
class Matrix
{
public:
    Matrix(size_t rows, size_t cols);

    Matrix(const Matrix&) = default;
    Matrix(Matrix&&) = default;
    Matrix& operator=(const Matrix&) & = default;
    Matrix& operator=(Matrix&&) & = default;
    virtual ~Matrix() { }

    T  operator()(size_t x, size_t y) const throw(std::out_of_range());
    T& operator()(size_t x, size_t y)       throw(std::out_of_range());

    size_t rows() const;
    size_t cols() const;
    std::pair<size_t, size_t> size() const;

    void resize(size_t rows, size_t cols, const T& value = T());

    template<typename ForwardIt>
    void insertCol(size_t pos, ForwardIt begin, ForwardIt end) throw(std::out_of_range());
    template<typename ForwardIt>
    void insertRow(size_t pos, ForwardIt begin, ForwardIt end) throw(std::out_of_range());

    void insertCol(size_t pos, const T& value = T()) throw(std::out_of_range());
    void insertRow(size_t pos, const T& value = T()) throw(std::out_of_range());

    void deleteRow(size_t pos) throw(std::out_of_range());
    void deleteCol(size_t pos) throw(std::out_of_range());

private:
    size_t nRows, nCols;

    T *data;
};

template<typename T, int width = 8>
std::ostream& operator<<(std::ostream& stream, const Matrix<T>& m)
{
    for (size_t y = 0; y < m.rows(); ++y)
    {
        for (size_t x = 0; x < m.cols(); ++x)
            stream << std::setw(width) << std::to_string(m(x, y));

        stream << std::endl;
    }

    return stream;
}

#include "Matrix_Impl.h"
