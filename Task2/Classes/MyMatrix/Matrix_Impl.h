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
void Matrix<T>::deleteRow(size_t n)
{

}

template<typename T>
void Matrix<T>::deleteCol(size_t n)
{

}

template<typename T>
template<typename ForwardIt>
void Matrix<T>::insertCol(ForwardIt begin, ForwardIt end)
{

}

template<typename T>
template<typename ForwardIt>
void Matrix<T>::insertRow(ForwardIt begin, ForwardIt end)
{

}

static inline size_t indexFromCoordinates(size_t x,
                                          size_t y,
                                          size_t rows,
                                          size_t cols) throw(std::out_of_range())
{

    if (x < rows && y < cols)
        return y * cols + x;
    else
        throw std::out_of_range("You're out of matrix size bounds");
}

template<typename T>
T Matrix<T>::operator()(size_t x, size_t y) const throw(std::out_of_range())
{
    return operator()(x, y);
}

template<typename T>
T& Matrix<T>::operator()(size_t x, size_t y) throw(std::out_of_range())
{
    return data[indexFromCoordinates(x,y, rows(), cols())];
}

template<typename T>
void Matrix<T>::resize(size_t rows, size_t cols, const T& value)
{
    auto newData = new T[rows * cols];

    // fill with default
    for (int y = 0; y < nRows; ++y)
    for (int x = 0; x < nCols; ++x)
    {
        operator () (x, y) = value;
    }

    delete[] data;

    this->data = newData;
    this->nRows = rows;
    this->nCols = cols;
}

