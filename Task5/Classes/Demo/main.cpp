#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/print.hpp>
#include <boost/mpl/reverse.hpp>
#include "Types.h"

using namespace std;

template <typename What, typename From>
struct IsDerived : mpl::and_<
        std::is_base_of<From, What>,
        mpl::not_<std::is_same<From, What>>
> {};

template <typename Base, typename Begin, typename End>
struct AllAreDerived
{
    typedef typename mpl::deref<Begin>::type
    Current;
    typedef typename mpl::next<Begin>::type
    Next;

    typedef typename mpl::if_<IsDerived<Current, Base>,
                              typename AllAreDerived<Base, Next, End>::type,
                              mpl::false_
                             >::type
    type;
};

template <typename Base, typename End>
struct AllAreDerived<Base, End, End>
{
    typedef typename mpl::true_ type;
};


int main()
{
    struct MyBase
    {
    };

    struct MyDerived1 : MyBase
    {
    };

    struct MyDerived2 : MyBase
    {
    };

    typedef mpl::vector<MyDerived1, MyDerived2, MyDerived1, MyBase>
    inputTypes;

    typedef mpl::reverse<inputTypes>::type
    inputTypesReversed;

    typedef AllAreDerived<
            mpl::deref<mpl::begin<inputTypesReversed>::type>::type,
            mpl::next <mpl::begin<inputTypesReversed>::type>::type,
            mpl::end<inputTypesReversed>::type>::type
    CheckIfAllDeriveFromFirst;


    std::cout << "Все классы - произвольные от последнего: "
              << CheckIfAllDeriveFromFirst::value << std::endl;

    return 0;
}
