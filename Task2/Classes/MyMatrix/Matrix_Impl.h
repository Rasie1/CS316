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

static inline size_t indexFromCoordinates(size_t x,
                                          size_t y,
                                          size_t rows,
                                          size_t cols) throw(std::out_of_range())
{

    if (x < cols && y < rows)
        return y * cols + x;
    else
        throw std::out_of_range("You're out of matrix size bounds");
}

template<typename T>
T Matrix<T>::operator()(size_t x, size_t y) const throw(std::out_of_range())
{
    return data[indexFromCoordinates(x,y, rows(), cols())];
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

    std::fill(newData, newData + rows * cols, value);

    // fill with default
    for (size_t y = 0; y < std::min(nRows, rows); ++y)
    for (size_t x = 0; x < std::min(nCols, cols); ++x)
        newData[indexFromCoordinates(x, y, rows, cols)] = operator()(x, y);

    delete[] data;

    this->data = newData;
    this->nRows = rows;
    this->nCols = cols;
}

template<typename T>
void Matrix<T>::insertCol(size_t pos, const T& value) throw(std::out_of_range())
{
    if (pos > cols())
        throw std::out_of_range("You're out of matrix size bounds");

    resize(rows(), cols() + 1);

    for (size_t y = 0;   y < rows(); ++y)
    for (size_t x = cols() - 1; x > pos; --x)
    {
        operator()(x, y) = operator()(x - 1, y);
    }
    for (size_t y = 0; y < rows(); ++y)
        operator()(pos, y) = value;
}

template<typename T>
void Matrix<T>::insertRow(size_t pos, const T& value) throw(std::out_of_range())
{
    if (pos > rows())
        throw std::out_of_range("You're out of matrix size bounds");

    resize(rows() + 1, cols());

    for (size_t y = rows() - 1; y > pos; --y)
    for (size_t x = 0;       x < cols(); ++x)
    {
        operator()(x, y) = operator()(x, y - 1);
    }
    for (size_t x = 0; x < cols(); ++x)
        operator()(x, pos) = value;
}

template<typename T>
template<typename ForwardIt>
void Matrix<T>::insertCol(size_t pos, ForwardIt begin, ForwardIt end) throw(std::out_of_range())
{

}

template<typename T>
template<typename ForwardIt>
void Matrix<T>::insertRow(size_t pos, ForwardIt begin, ForwardIt end) throw(std::out_of_range())
{

}

template<typename T>
void Matrix<T>::deleteRow(size_t pos) throw(std::out_of_range())
{

}

template<typename T>
void Matrix<T>::deleteCol(size_t pos) throw(std::out_of_range())
{

}
