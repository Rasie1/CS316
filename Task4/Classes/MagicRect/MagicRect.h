#pragma once
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/modulus.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/bool.hpp>

using boost::mpl::vector_c;
using boost::mpl::vector;
using boost::mpl::push_back;
using boost::mpl::int_;
using boost::mpl::count_if;
using boost::mpl::modulus;
using boost::mpl::equal_to;
using boost::mpl::if_;
using boost::mpl::bool_;

#include <vector>
#include <iostream>
#include <iomanip>

using namespace boost;

namespace MagicRectHelpers
{
template <int i, int j, int n>
struct MatrixRow
{
    typedef typename MatrixRow<i, j - 1, n>::rowValue
    prev;

    static const int val = 1 + ((i - j + (n - 1) / 2) % n) * n + ((i + j + (n + 1) / 2) % n);

    typedef typename push_back<prev, int_<val>>::type
    rowValue;
};

template <int i, int n>
struct MatrixRow <i, 0, n>
{
    typedef vector<>::type rowValue;
};


template <int i, int n>
struct Matrix
{
    typedef typename Matrix<i-1, n>::matrixValue
    prev;

    typedef typename push_back<prev,
                               MatrixRow<i, n, n>
                              >::type
    matrixValue;
};

template<int n>
struct Matrix<0, n>
{
    typedef vector<> matrixValue;
};

//template <int i, int j, int n>
//struct MatrixRow
//{
//    typedef typename MatrixRow<i, j - 1, n>::rowValue
//    prev;

//    static const int val = n * i + j;

//    typedef typename push_back<prev, int_<val>>::type
//    rowValue;
//};

//template <int i, int n>
//struct MatrixRow <i, 0, n>
//{
//    typedef vector<>::type rowValue;
//};


//template <int i, int n>
//struct Matrix
//{
//    typedef typename Matrix<i-1, n>::matrixValue
//    prev;

//    typedef typename push_back<prev,
//                               MatrixRow<i, n, n>
//                              >::type
//    matrixValue;
//};

//template<int n>
//struct Matrix<0, n>
//{
//    typedef vector<> matrixValue;
//};


template<int n>
struct Ret : /*MakeMagical<n, n, */Matrix<n, n>//>
{

};

} // namespace MagicRectHelpers

template<int n>
struct MagicRect : MagicRectHelpers::Ret<n>
{

};

//std::vector<std::vector<int>> magicRectDynamic(int n)
//{
//    using std::cout;
//    using std::endl;
//    using std::setw;
//    std::vector<std::vector<int>> a(n * 2, std::vector<int>(n * 2));
//    std::vector<std::vector<int>> b(n, std::vector<int>(n));

//    int acc = 1;
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            a[i - j + n][j + i] = acc;
////            ret[(i + (n - j) + n/2) % n][(j + i + n/2 + 1) % n] = acc;
//            acc++;
//        }
//    }


//    cout << "Helper" << endl << endl;
//    for (auto xs : a)
//    {
//        for (auto x  : xs)
//        {
//            cout << setw(4);
//            if (x == 0)
//                cout << "    ";
//            else
//                cout << x;
//        }
//        cout << endl;
//    }

//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {

//            b[i][j] = a[n / 2 + 1 + i][n / 2 + j];
//            if (b[i][j] == 0)
//                b[i][j] = a[n /
//            if ((i + j) % 2)
//            {

//                //b[i][j] = a[(n + n / 2 - j) % n][(n + n / 2 + 1 + i) % n];
//            }
//            else
//            {
//                //b[i][j] = a[][(n + n / 2 + 1 + i) % n];
//            }
//        }
//    }

//    return b;
//}
