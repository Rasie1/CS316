#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) :
        nRows(rows),
        nCols(cols)
{
    data = new T[rows * cols];
}

template<typename T>
std::pair<size_t, size_t> Matrix<T>::size() const
{
    return std::make_pair(rows(), cols());
}

template<typename T>
size_t Matrix<T>::rows() const
{
    return nRows;
}

template<typename T>
size_t Matrix<T>::cols() const
{
    return nCols;
}

template<typename T>
T Matrix<T>::operator()(size_t x, size_t y) const throw(std::out_of_range())
{
    return operator()(x, y);
}

template<typename T>
T& Matrix<T>::operator()(size_t x, size_t y) throw(std::out_of_range())
{
    if (x < rows() && y < cols())
        return data[y * cols() + x];
    else
        throw std::out_of_range("You're out of matrix size bounds");
}

template<typename T>
void Matrix<T>::resize(size_t rows, size_t cols)
{
    this->nRows = rows;
    this->nCols = cols;
    data = new T[rows * cols];
}

