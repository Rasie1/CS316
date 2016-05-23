#include <iostream>
#include "Matrix.h"

using namespace std;

// Example Type for testing exception safety
struct MyType
{
    static bool shouldThrowInConstructor;
    static bool shouldThrowInAssignment;
    int value;

    void generateException()
    {
        throw std::logic_error("Example exception");
    }

    MyType()
    {
        value = rand() % 10;
        if (shouldThrowInConstructor)
            generateException();
    }

    MyType& operator=(const MyType& other)
    {
        if (shouldThrowInAssignment)
            generateException();
        return *this;
    }
};

bool MyType::shouldThrowInConstructor = false;
bool MyType::shouldThrowInAssignment  = false;

std::ostream& operator<<(std::ostream& stream, const MyType& x)
{
    return stream << x.value;
}

int main()
{
    cout << "Welcome" << endl;
    cout << "A:" << endl;
    Matrix<int> a(4, 4);
    a(1, 1) = 17;
    cout << a << endl;

    cout << "Resizing with default value:" << endl;
    a.resize(10, 10, 1000);
    cout << "A:" << endl;
    cout << a << endl;

    cout << "Resizing into smaller matrix:" << endl;
    a.resize(8, 5);
    cout << "A:" << endl;
    cout << a << endl;

    cout << "Copying to B" << endl;
    auto b = a;
    cout << b << endl;
//    Matrix<int> b(4, 4)
    b(1, 1) = -100;
    cout << "B (changed (1,1) to -100):" << endl;
    cout << b << endl;

    cout << "Inserting a row and a column" << endl;
    a.insertRow(3, 2);
    a.insertCol(2, 1);
    cout << "A:" << endl;
    cout << a << endl;

    cout << "Deleting a row and a column" << endl;
    a.deleteRow(3);
    a.deleteCol(2);
    cout << "A:" << endl;
    cout << a << endl;

    cout << "Displaying B:" << endl;
    cout << b << endl;

    cout << "Swapping B and A" << endl;
    swap(a, b);


    cout << "Displaying A" << endl;
    cout << a << endl;
    cout << "Displaying B" << endl;
    cout << b << endl;

    cout << "Copying A to C (laziness test)" << endl;
    auto c = a;
    cout << "Changing A(1,1) to -3" << endl;
    a(1,1) = -3;
    cout << "A:" << endl;
    cout << a << endl;
    cout << "C:" << endl;
    cout << c << endl;





    cout << "Exception safety tests" << endl;

    MyType::shouldThrowInConstructor = false;
    MyType::shouldThrowInAssignment  = true;

    auto m1 = Matrix<MyType>(4, 4);
    auto m2 = m1;

    cout << "M1:" << endl << m1
         << "M2:" << endl << m2 << endl;

    try
    {
        m1(1,1) = MyType();
    }
    catch (const std::logic_error& e)
    {
        cout << "Caught exception" << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught  ..." << endl;
    }


    cout << "M1:" << endl << m1
         << "M2:" << endl << m2 << endl;


    MyType::shouldThrowInConstructor = true;
    MyType::shouldThrowInAssignment  = false;
    try
    {
        m1.resize(5, 5);
        cout << "Printed?" << endl;
    }
    catch (const std::logic_error& e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught  ..." << endl;
    }

    cout << "M1:" << endl << m1 << endl;



    cout << endl << "All tests done" << endl;

    return 0;
}
