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
#include <vector>
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/print.hpp>
#include <boost/mpl/reverse.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/type_traits.hpp>
#include <boost/mpl/placeholders.hpp>


using boost::mpl::vector_c;
using boost::mpl::vector;
using boost::mpl::push_back;
using boost::mpl::int_;
using boost::mpl::count_if;
using boost::mpl::modulus;
using boost::mpl::equal_to;
using boost::mpl::if_;
using boost::mpl::bool_;
using namespace std;
using namespace boost;
using namespace placeholders;

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


//template <typename What, typename From>
//struct IsClass : mpl::and_<
//        std::is_class<What>,
//        mpl::not_<std::is_same<From, What>>
//> {};

template <typename Base, typename Begin, typename End>
struct AllAreClasses
{
    typedef typename mpl::deref<Begin>::type
    Current;
    typedef typename mpl::next<Begin>::type
    Next;

    typedef typename mpl::if_<std::is_class<Current>,
                              typename AllAreClasses<Base, Next, End>::type,
                              mpl::false_
                             >::type
    type;
};

template <typename Base, typename End>
struct AllAreClasses<Base, End, End>
{
    typedef typename mpl::true_ type;
};

