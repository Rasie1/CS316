#include "Matrix.h"

template<typename T, class A>
Matrix<T, A>::Matrix(size_t rows, size_t cols) :
        nRows(rows),
        nCols(cols)
{
    data = new T[rows * cols];
}

template<typename T, class A>
std::pair<size_t, size_t> Matrix<T, A>::size() const
{
    return std::make_pair(rows(), cols());
}

template<typename T, class A>
size_t Matrix<T, A>::rows() const
{
    return nRows;
}

template<typename T, class A>
size_t Matrix<T, A>::cols() const
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

template<typename T, class A>
T Matrix<T, A>::operator()(size_t x, size_t y) const throw(std::out_of_range())
{
    return data[indexFromCoordinates(x,y, rows(), cols())];
}

template<typename T, class A>
T& Matrix<T, A>::operator()(size_t x, size_t y) throw(std::out_of_range())
{
    detach();
    return data[indexFromCoordinates(x,y, rows(), cols())];
}

template<typename T, class A>
void Matrix<T, A>::resize(size_t rows, size_t cols, const T& value)
{
    detach();
    auto newData = new T[rows * cols];

    std::fill(newData, newData + rows * cols, value);

    // fill with default
    for (size_t y = 0; y < std::min(nRows, rows); ++y)
    for (size_t x = 0; x < std::min(nCols, cols); ++x)
        newData[indexFromCoordinates(x, y, rows, cols)] = operator()(x, y);

//    delete[] data;

    data.reset(newData);

//    this->data = newData;
    this->nRows = rows;
    this->nCols = cols;
}

template<typename T, class A>
void Matrix<T, A>::insertCol(size_t pos, const T& value) throw(std::out_of_range())
{
    detach();
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

template<typename T, class A>
void Matrix<T, A>::insertRow(size_t pos, const T& value) throw(std::out_of_range())
{
    detach();
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

template<typename T, class A>
template<typename ForwardIt>
void Matrix<T, A>::insertCol(size_t pos, ForwardIt begin, ForwardIt end) throw(std::out_of_range())
{
    detach();

}

template<typename T, class A>
template<typename ForwardIt>
void Matrix<T, A>::insertRow(size_t pos, ForwardIt begin, ForwardIt end) throw(std::out_of_range())
{
    detach();
}


template<typename T, class A>
void Matrix<T, A>::deleteRow(size_t pos) throw(std::out_of_range())
{
    detach();
    if (pos >= rows())
        throw std::out_of_range("You're out of matrix size bounds");

    for (size_t y = pos; y < rows() - 1; ++y)
    for (size_t x = 0;   x < cols(); ++x)
    {
        operator()(x, y) = operator()(x, y + 1);
    }

    resize(rows() - 1, cols());
}


template<typename T, class A>
void Matrix<T, A>::deleteCol(size_t pos) throw(std::out_of_range())
{
    detach();
    if (pos >= cols())
        throw std::out_of_range("You're out of matrix size bounds");

    for (size_t y = 0;   y < rows(); ++y)
    for (size_t x = pos; x < cols() - 1; ++x)
    {
        operator()(x, y) = operator()(x + 1, y);
    }

    resize(rows(), cols() - 1);
}

template<typename T, class A>
Matrix<T, A>::~Matrix()
{
}


template<typename T, class A>
Matrix<T, A>::Matrix(const Matrix& other) :
    nRows(other.nRows),
    nCols(other.nCols),
    data(other.data)
{

}

template<typename T, class A>
Matrix<T, A>::Matrix(Matrix&& other) :
    nRows(other.nRows),
    nCols(other.nCols),
    data(other.data)
{

}

template<typename T, class A>
Matrix<T, A>& Matrix<T, A>::operator=(Matrix&& other) &
{
    swap(*this, other);

    return *this;
}

template<typename T, class A>
void Matrix<T, A>::detach()
{
    auto tmp = this->data.rawPtr();
    if (!(tmp == nullptr || data.unique()))
    {
        auto newdata = new T[nRows * nCols];
        std::copy(tmp, tmp + nRows * nCols, newdata);
        data.reset(newdata);
    }
}
