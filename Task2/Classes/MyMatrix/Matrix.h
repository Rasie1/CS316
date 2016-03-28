#pragma once
#include <stdexcept>
#include <iostream>
#include <iomanip>

template<typename T, class A = std::allocator<T>>
class Matrix
{
public:
    typedef A allocator_type;
    typedef typename A::value_type value_type;
    typedef typename A::reference reference;
    typedef typename A::const_reference const_reference;
    typedef typename A::difference_type difference_type;
    typedef typename A::size_type size_type;

    class iterator
    {
    public:
        typedef typename A::difference_type difference_type;
        typedef typename A::value_type value_type;
        typedef typename A::reference reference;
        typedef typename A::pointer pointer;

        class innerIterator
        {
        public:
            innerIterator() :
                p(nullptr),
                position(0),
                endPosition(0)
            {
            }

            innerIterator(T* p, int position, int endPosition) :
                p(p),
                position(position),
                endPosition(endPosition)
            {
            }

            innerIterator(const innerIterator& other) :
                p(other.p),
                position(other.position),
                endPosition(other.endPosition)
            {
            }


            innerIterator& operator=(const innerIterator& other)
            {
                this->p = other.p;
            }

            bool operator==(const innerIterator& other) const
            {
                if (p == other.p)
                    return true;
                if (endPosition == position || p == nullptr)
                    return other.p == nullptr || other.endPosition == other.position;
                return false;
            }

            bool operator!=(const innerIterator& other) const
            {
                return !(operator==(other));
            }

            innerIterator& operator++()
            {
                p++;
                position++;
                return *this;
            }

            T& operator*() const
            {
                return *p;
            }

            T* p;
            int position;
            int endPosition;
        };

        iterator() :
            p(nullptr),
            position(0),
            endPosition(0),
            rowSize(0)
        {
        }

        iterator(T* p, int position, int endPosition, int rowSize) :
            p(p),
            position(position),
            endPosition(endPosition),
            rowSize(rowSize)
        {
        }

        iterator(const iterator& other) :
            p(other.p),
            position(other.position),
            endPosition(other.endPosition),
            rowSize(other.rowSize)
        {
        }


        iterator& operator=(const iterator& other)
        {
            this->p = other.p;
        }

        bool operator==(const iterator& other) const
        {
            if (p == other.p)
                return true;
            if (endPosition == position || p == nullptr)
                return other.p == nullptr || other.endPosition == other.position;
            return false;
        }

        bool operator!=(const iterator& other) const
        {
            return !(operator==(other));
        }

        iterator& operator++()
        {
            p += rowSize;
            position++;
            return *this;
        }

        innerIterator operator*() const
        {
            return innerIterator(p, position, rowSize);
        }

//        vector<int> v;
//        for (vi::iterator it = bbegin))
//        for (int x: v)

        innerIterator begin()
        {
            return innerIterator(p, 0, rowSize);
        }

        innerIterator end()
        {
            return innerIterator();
        }

        T* p;
        int position;
        int endPosition;
        int rowSize;
    };






    Matrix(size_t rows, size_t cols);

    Matrix(const Matrix&) = default;
    Matrix(Matrix&&) = default;
    Matrix& operator=(const Matrix&) & = default;
    Matrix& operator=(Matrix&&) & = default;
    virtual ~Matrix() { }

    T  operator()(size_t x, size_t y) const throw(std::out_of_range());
    T& operator()(size_t x, size_t y)       throw(std::out_of_range());

//    bool operator==(const T&) const;
//    bool operator!=(const T&) const;

    iterator begin()
    {
        return iterator(data, 0, nRows, nCols);
    }

    iterator end()
    {
        return iterator();
    }

//    const_iterator cbegin()
//    {
//        return const_iterator(data, 0, nRows, nCols);
//    }

//    const_iterator cend()
//    {
//        return const_iterator();
//    }

    bool empty() { return nCols == 0 && nRows == 0; }

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
//    void detach()
//    {
//        T* tmp = *data;
//        if(!(tmp == 0 || m_sp.unique()))
//        {
//            p = new Matrix(*tmp);
//        }
//    }


    size_t nRows, nCols;

    T *data;
};

template<typename T, int width = 8>
std::ostream& operator<<(std::ostream& stream, Matrix<T>& m)
{
    for (Matrix<int>::iterator xs = m.begin(); xs != m.end(); ++xs)
    {
        for (Matrix<int>::iterator::innerIterator x = xs.begin();
             x != xs.end(); ++x)
            stream << std::setw(8) << std::to_string(*x);
        stream << std::endl;
    }

    return stream;
}

#include "Matrix_Impl.h"
