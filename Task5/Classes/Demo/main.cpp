#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "Types.h"

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
    inputTypesTrue;
    typedef mpl::reverse<inputTypesTrue>::type
    inputTypesTrueReversed;

    typedef mpl::vector<MyDerived1, MyDerived2, int, MyBase>
    inputTypesFalse;
    typedef mpl::reverse<inputTypesFalse>::type
    inputTypesFalseReversed;


    {
        typedef AllAreDerived<
                mpl::deref<mpl::begin<inputTypesTrueReversed>::type>::type,
                mpl::next <mpl::begin<inputTypesTrueReversed>::type>::type,
                mpl::end<inputTypesTrueReversed>::type>::type
        CheckIfAllDeriveFromFirst;

        typedef AllAreClasses<
                mpl::deref<mpl::begin<inputTypesTrueReversed>::type>::type,
                mpl::next <mpl::begin<inputTypesTrueReversed>::type>::type,
                mpl::end<inputTypesTrueReversed>::type>::type
        CheckIfAllAreClasses;

        std::cout << "Последовательность: "
                  << typeid(inputTypesTrue).name()
                  << "Все типы - классы: "
                  << CheckIfAllAreClasses::value << std::endl
                  << "Все классы - произвольные от последнего: "
                  << CheckIfAllDeriveFromFirst::value << std::endl;
    }
    {

        typedef AllAreDerived<
                mpl::deref<mpl::begin<inputTypesFalseReversed>::type>::type,
                mpl::next <mpl::begin<inputTypesFalseReversed>::type>::type,
                mpl::end<inputTypesFalseReversed>::type>::type
        CheckIfAllDeriveFromFirst;

        typedef AllAreClasses<
                mpl::deref<mpl::begin<inputTypesFalseReversed>::type>::type,
                mpl::next <mpl::begin<inputTypesFalseReversed>::type>::type,
                mpl::end<inputTypesFalseReversed>::type>::type
        CheckIfAllAreClasses;

        std::cout << "Последовательность: "
                  << typeid(inputTypesFalse).name()
                  << "Все типы - классы: "
                  << CheckIfAllAreClasses::value << std::endl
                  << "Все классы - произвольные от последнего: "
                  << CheckIfAllDeriveFromFirst::value << std::endl;
    }

    return 0;
}
