#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/print.hpp>
#include "MagicRect.h"

using namespace std;

struct printElement {
    template <typename T>
    void operator()(T t) const
    {
       std::cout << T::value << " ";
    }
};

struct printRow {
    template <typename T>
    void operator()(T t) const
    {
        boost::mpl::for_each<typename T::rowValue>(printElement());
        std::cout << std::endl;
    }
};

int main()
{
    const int n = 5;
    cout << "Magic rect of " << n << endl;


    boost::mpl::for_each<MagicRect<n>::matrixValue>(printRow());
    auto rect = magicRectDynamic(n);

    cout << "Dynamic" << endl << endl;
    for (auto xs : rect)
    {
        for (auto x  : xs)
        {
            cout << setw(4);
            if (x == 0)
                cout << "    ";
            else
                cout << x;
        }
        cout << endl;
    }



    return 0;
}
